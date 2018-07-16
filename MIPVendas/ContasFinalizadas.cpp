//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ContasFinalizadas.h"
#include "Principal.h"
#include "PedidosView.h"
#include "autoload.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFContasFinalizadas *FContasFinalizadas;
//---------------------------------------------------------------------------
__fastcall TFContasFinalizadas::TFContasFinalizadas(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFContasFinalizadas::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);

	SQLQuery1->SQLConnection = SQLCONNECT;
}
//---------------------------------------------------------------------------
void TFContasFinalizadas::GerarGridPendentes()
{
	UnicodeString QUERY,CONSUMIDOR;
	int numerodalinha,i,j,cc,rc;

	rc = GridPendentes->RowCount;
	cc = GridPendentes->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
			GridPendentes->Cells[j][i] = "";

	numerodalinha = 1;
	// ESTRUTURA
	GridPendentes->Options << goRowSelect;
	GridPendentes->ScrollBars = ssVertical;
	GridPendentes->Rows[1]->Clear();
	GridPendentes->RowCount = 0;
	GridPendentes->ColCount = 4;
	GridPendentes->FixedCols = 0;
	GridPendentes->ColWidths[0] = 0;
	GridPendentes->ColWidths[1] = ((GridPendentes->Width)/3)+200;
	GridPendentes->ColWidths[2] = ((GridPendentes->Width)/3)-100;
	GridPendentes->ColWidths[3] = ((GridPendentes->Width)/3)-100;
	GridPendentes->Cols[0]->Add("CLIENTE ID");
	GridPendentes->Cols[1]->Add("CLIENTE");
	GridPendentes->Cols[2]->Add("DATA ANTIGA");
	GridPendentes->Cols[3]->Add("VALOR");
	// ESTRUTURA

	if(CheckConsumidorPendentes->Checked == TRUE)
		CONSUMIDOR = " AND C.consumidor";
	else
		CONSUMIDOR = "";

	if(RadioSimplesPendentes->Checked)
		QUERY = "SELECT V.id AS id,V.cliente AS cliente_id,sum(V.valor) AS valor,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,MIN(V.data) AS data,C.id AS id_c,C.nome_fantasia AS cliente,CF.consumidor AS consumidor,F.id AS id_f,F.situacao AS situacao FROM vendas AS V INNER JOIN clientes AS C ON(V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (CF.cliente = C.id) INNER JOIN fechamentos AS F ON (V.fechamento = F.id) WHERE (V.modo_pagar='3' AND C.nome_fantasia LIKE '%"+EditBuscaPendentes->Text+"%' AND CF.consumidor='1' AND F.situacao='1') GROUP BY V.cliente ORDER BY C.nome_fantasia ASC";
	else
		QUERY = "SELECT V.id AS id,V.cliente AS cliente_id,sum(V.valor) AS valor,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,MIN(V.data) AS data,C.id AS id_c,C.nome_fantasia AS cliente,CF.consumidor AS consumidor,F.id AS id_f,F.situacao AS situacao FROM vendas AS V INNER JOIN clientes AS C ON(V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (CF.cliente = C.id) INNER JOIN fechamentos AS F ON (V.fechamento = F.id) WHERE (V.modo_pagar='3' AND C.nome_fantasia LIKE '%"+EditBuscaPendentes->Text+"%' AND CF.consumidor='1' AND F.situacao='1') GROUP BY V.cliente ORDER BY C.nome_fantasia ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		GridPendentes->Cells[0][numerodalinha] = SQLQuery1->Fields->FieldByName("cliente_id")->AsString;
		GridPendentes->Cells[1][numerodalinha] = SQLQuery1->Fields->FieldByName("cliente")->AsString;
		GridPendentes->Cells[2][numerodalinha] = SQLQuery1->Fields->FieldByName("data")->AsString;
		GridPendentes->Cells[3][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("valor")->AsFloat);

		GridPendentes->RowCount++;
		SQLQuery1->Next();
		numerodalinha++;
		if (numerodalinha == 2)
			GridPendentes->FixedRows = 1;
	}
}
void TFContasFinalizadas::DesignerPendentes()
{
	int borda = 20;

	PanelPendentesFixo->Top = borda;
	PanelPendentesFixo->Left = borda;
	PanelPendentesFixo->Height =  PanelPendentes->Height - 2*borda;

	PanelPendentesVariavel->Top = borda;
	PanelPendentesVariavel->Left = PanelPendentesFixo->Width + 2*borda;
	PanelPendentesVariavel->Height = PanelPendentes->Height - 2*borda;
	PanelPendentesVariavel->Width = PanelPendentes->Width - PanelPendentesFixo->Width - 4*borda;
}

void __fastcall TFContasFinalizadas::FormShow(TObject *Sender)
{
	loadCabecalho();

	data_inicial->Date = Now();
	data_final->Date = Now();
	data_inicial->Date = data_inicial->Date - 30;

	RadioSimplesPendentes->Checked = TRUE;
	DesignerPendentes();
	GerarGridPendentes();
}
//---------------------------------------------------------------------------


void __fastcall TFContasFinalizadas::GridPendentesDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	UnicodeString Texto;

	if(ARow>0)
	{
		Texto = GridPendentes->Cells[ACol][ARow];

		GridPendentes->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			GridPendentes->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridPendentes->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridPendentes->Canvas->Brush->Color=TColor(0xc9a78b);

			GridPendentes->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridPendentes->Canvas->FillRect(Rect);
		GridPendentes->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridPendentes->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);
	}
}
//---------------------------------------------------------------------------
void TFContasFinalizadas::GerarGridPendentesDetalhada()
{
	UnicodeString QUERY,MODO;
	int numerodalinha,i,j,cc,rc;

	rc = GridPendentesDetalhada->RowCount;
	cc = GridPendentesDetalhada->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
			GridPendentesDetalhada->Cells[j][i] = "";

	numerodalinha = 1;
	// ESTRUTURA
	GridPendentesDetalhada->Options << goRowSelect;
	GridPendentesDetalhada->ScrollBars = ssVertical;
	GridPendentesDetalhada->Rows[1]->Clear();
	GridPendentesDetalhada->RowCount = 0;
	GridPendentesDetalhada->ColCount = 6;
	GridPendentesDetalhada->FixedCols = 0;
	GridPendentesDetalhada->ColWidths[0] = ((GridPendentesDetalhada->Width)/4);
	GridPendentesDetalhada->ColWidths[1] = ((GridPendentesDetalhada->Width)/4);
	GridPendentesDetalhada->ColWidths[2] = ((GridPendentesDetalhada->Width)/4);
	GridPendentesDetalhada->ColWidths[3] = ((GridPendentesDetalhada->Width)/4);
	GridPendentesDetalhada->Cols[0]->Add("CÓDIGO");
	GridPendentesDetalhada->Cols[1]->Add("DATA");
	GridPendentesDetalhada->Cols[2]->Add("USUARIO FECHAMENT.");
	GridPendentesDetalhada->Cols[3]->Add("VALOR");
	// ESTRUTURA

	id_cliente = FStrToInt(GridPendentes->Cells[0][rowselect]);

	if(RadioSimplesPendentes->Checked)
		QUERY = "SELECT C.id AS id_c,C.nome_fantasia AS cliente,U.id AS id_u,U.nome AS atendente,F.id AS id,F.codigo AS codigo,F.situacao AS situacao,F.data_pagamento AS data,F.cliente AS cliente,F.valor AS valor,F.usuario_fechamento AS ufechamento FROM fechamentos AS F INNER JOIN clientes AS C ON (F.cliente = C.id) INNER JOIN usuarios AS U ON (F.usuario_fechamento = U.id) WHERE (F.cliente = '"+GridPendentes->Cells[0][rowselect]+"' AND F.situacao='1' AND (F.data_pagamento>='"+RevertOrd(data_inicial->DateTime.DateString())+"' AND F.data_pagamento<='"+RevertOrd(data_final->DateTime.DateString())+"')) ORDER BY F.codigo ASC";
	else
		QUERY = "SELECT C.id AS id_c,C.nome_fantasia AS cliente,U.id AS id_u,U.nome AS atendente,F.id AS id,F.codigo AS codigo,F.situacao AS situacao,F.data_pagamento AS data,F.cliente AS cliente,F.valor AS valor,F.usuario_fechamento AS ufechamento FROM fechamentos AS F INNER JOIN clientes AS C ON (F.cliente = C.id) INNER JOIN usuarios AS U ON (F.usuario_fechamento = U.id) WHERE (F.cliente = '"+GridPendentes->Cells[0][rowselect]+"' AND F.situacao='1' AND (F.data_pagamento>='"+RevertOrd(data_inicial->DateTime.DateString())+"' AND F.data_pagamento<='"+RevertOrd(data_final->DateTime.DateString())+"')) ORDER BY F.codigo ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		GridPendentesDetalhada->Cells[0][numerodalinha] = SQLQuery1->Fields->FieldByName("codigo")->AsString;
		GridPendentesDetalhada->Cells[1][numerodalinha] = SQLQuery1->Fields->FieldByName("data")->AsString;
		GridPendentesDetalhada->Cells[2][numerodalinha] = SQLQuery1->Fields->FieldByName("atendente")->AsString;
		GridPendentesDetalhada->Cells[3][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("valor")->AsFloat);
		GridPendentesDetalhada->RowCount++;
		SQLQuery1->Next();
		numerodalinha++;
	}
}

void __fastcall TFContasFinalizadas::GridPendentesSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselect = ARow;
	GerarGridPendentesDetalhada();
}
//---------------------------------------------------------------------------

void __fastcall TFContasFinalizadas::GridPendentesDetalhadaDrawCell(TObject *Sender,
          int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
	UnicodeString Texto;

	/*--------------------COLOCAR CHECKBOX----------------------------*/
	if (ARow>0)
	{
		Texto = GridPendentesDetalhada->Cells[ACol][ARow];

		GridPendentesDetalhada->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			GridPendentesDetalhada->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridPendentesDetalhada->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridPendentesDetalhada->Canvas->Brush->Color=TColor(0xc9a78b);
			GridPendentesDetalhada->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridPendentesDetalhada->Canvas->FillRect(Rect);
		GridPendentesDetalhada->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridPendentesDetalhada->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);
	}

}
//---------------------------------------------------------------------------


void __fastcall TFContasFinalizadas::GridPendentesDetalhadaSelectCell(TObject *Sender,
          int ACol, int ARow, bool &CanSelect)
{
	rowselect_pendentes_detalhada = ARow;
}
//---------------------------------------------------------------------------


void __fastcall TFContasFinalizadas::ButtonFiltrarPendentesClick(TObject *Sender)

{
	GerarGridPendentes();
}
//---------------------------------------------------------------------------

void TFContasFinalizadas::loadCabecalho()
{
//    EmpresaModel *empresa_model = new EmpresaModel();
//	EmpresaEspelho *empresa = empresa_model->selectAll();
//
//	InfoGeraisModel *info_gerais_model = new InfoGeraisModel();
//	InfoGeraisEspelho *info_gerais = info_gerais_model->selectAll();
//
//	LabelCabecalhoTitulo->Caption =  "[CONTAS FINALIZADAS] " + empresa->getNomeFantasia();
//
//	LabelCabecalhoSubTitulo->Caption =  ToUpper(info_gerais->getSoftwareName());
}

