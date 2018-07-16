//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GraficoVendas.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFGraficoVendas *FGraficoVendas;
//---------------------------------------------------------------------------
__fastcall TFGraficoVendas::TFGraficoVendas(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFGraficoVendas::MontarGrafico()
{
	UnicodeString QUERY,TextLegenda;
	UnicodeString CONSUMIDOR,FECHAMENTO,ATENDENTE;
	UnicodeString NOME_MESES[12] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
	float X,Y;
	int i;

	i = 0;

	if(CheckConsumidor->Checked)
		CONSUMIDOR = "1";
	else
		CONSUMIDOR = "0";

	if(CheckFinalizado->Checked)
		FECHAMENTO = "2";
	else
		FECHAMENTO = "0";

	if(ComboAtendentes->ItemIndex>0)
		ATENDENTE  = "AND U.nome = '"+CharToStr(atendentes[ComboAtendentes->ItemIndex - 1].desc)+"' ";
	else
		ATENDENTE = "";

	switch(ComboPeriodo->ItemIndex)
	{
		case 0:
			QUERY = "SELECT V.id AS id,V.codigo AS codigo_venda,SUM(V.valor) AS valor,V.vendedor AS vendedor_id,V.cliente AS cliente_id,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,V.data AS data,V.mes AS mes,V.ano AS ano,C.id AS id_c,C.nome_fantasia AS cliente,CF.id AS id_cf,CF.cliente AS cliente_cf,CF.consumidor AS consumidor,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (V.cliente = CF.cliente) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE ((CF.consumidor='1' OR CF.consumidor='"+CONSUMIDOR+"') "+ATENDENTE+"AND V.fechamento>='"+FECHAMENTO+"' AND (V.data>='"+RevertOrd(data_inicial->DateTime.DateString())+"' AND V.data<='"+RevertOrd(data_final->DateTime.DateString())+"')) GROUP BY data ORDER BY V.data ASC";
//			QUERY = "SELECT V.id AS id,SUM(V.valor) AS valor,V.cliente AS cliente_id,V.vendedor AS vendedor_id,V.cliente AS cliente_id,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,V.data AS data,V.mes AS mes,V.ano AS ano,C.id AS id_c,C.nome_fantasia AS cliente,CF.id AS id_cf,CF.cliente AS cliente_cf,CF.consumidor AS consumidor,U.id AS id_u,U.nome AS vendedor FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (V.cliente = CF.cliente) INNER JOIN usuarios AS U ON (V.vendedor = U.id) WHERE ((CF.consumidor='1' OR CF.consumidor='"+CONSUMIDOR+"') "+ATENDENTE+"AND V.fechamento>='"+FECHAMENTO+"' AND (V.data>='"+RevertOrd(data_inicial->DateTime.DateString())+"' AND V.data<='"+RevertOrd(data_final->DateTime.DateString())+"')) GROUP BY V.data ORDER BY V.data ASC";
		break;
		case 1:
			QUERY = "SELECT V.id AS id,V.codigo AS codigo_venda,SUM(V.valor) AS valor,V.vendedor AS vendedor_id,V.cliente AS cliente_id,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,V.data AS data,V.mes AS mes,V.ano AS ano,C.id AS id_c,C.nome_fantasia AS cliente,CF.id AS id_cf,CF.cliente AS cliente_cf,CF.consumidor AS consumidor,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (V.cliente = CF.cliente) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE ((CF.consumidor='1' OR CF.consumidor='"+CONSUMIDOR+"') "+ATENDENTE+"AND V.fechamento>='"+FECHAMENTO+"' AND (V.data>='"+RevertOrd(data_inicial->DateTime.DateString())+"' AND V.data<='"+RevertOrd(data_final->DateTime.DateString())+"')) GROUP BY mes,ano ORDER BY V.data ASC";
//			QUERY = "SELECT V.id AS id,SUM(V.valor) AS valor,V.cliente AS cliente_id,V.vendedor AS vendedor_id,V.cliente AS cliente_id,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,V.data AS data,V.mes AS mes,V.ano AS ano,C.id AS id_c,C.nome_fantasia AS cliente,CF.id AS id_cf,CF.cliente AS cliente_cf,CF.consumidor AS consumidor,U.id AS id_u,U.nome AS vendedor FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (V.cliente = CF.cliente) INNER JOIN usuarios AS U ON (V.vendedor = U.id) WHERE ((CF.consumidor='1' OR CF.consumidor='"+CONSUMIDOR+"') "+ATENDENTE+"AND V.fechamento>='"+FECHAMENTO+"' AND (V.data>='"+RevertOrd(data_inicial->DateTime.DateString())+"' AND V.data<='"+RevertOrd(data_final->DateTime.DateString())+"')) GROUP BY V.mes,V.ano ORDER BY V.data ASC";
		break;
		case 2:
			QUERY = "SELECT V.id AS id,V.codigo AS codigo_venda,SUM(V.valor) AS valor,V.vendedor AS vendedor_id,V.cliente AS cliente_id,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,V.data AS data,V.mes AS mes,V.ano AS ano,C.id AS id_c,C.nome_fantasia AS cliente,CF.id AS id_cf,CF.cliente AS cliente_cf,CF.consumidor AS consumidor,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (V.cliente = CF.cliente) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE ((CF.consumidor='1' OR CF.consumidor='"+CONSUMIDOR+"') "+ATENDENTE+"AND V.fechamento>='"+FECHAMENTO+"' AND (V.data>='"+RevertOrd(data_inicial->DateTime.DateString())+"' AND V.data<='"+RevertOrd(data_final->DateTime.DateString())+"')) GROUP BY ano ORDER BY V.data ASC";
//			QUERY = "SELECT V.id AS id,SUM(V.valor) AS valor,V.cliente AS cliente_id,V.vendedor AS vendedor_id,V.cliente AS cliente_id,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,V.data AS data,V.mes AS mes,V.ano AS ano,C.id AS id_c,C.nome_fantasia AS cliente,CF.id AS id_cf,CF.cliente AS cliente_cf,CF.consumidor AS consumidor,U.id AS id_u,U.nome AS vendedor FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (V.cliente = CF.cliente) INNER JOIN usuarios AS U ON (V.vendedor = U.id) WHERE ((CF.consumidor='1' OR CF.consumidor='"+CONSUMIDOR+"') "+ATENDENTE+"AND V.fechamento>='"+FECHAMENTO+"' AND (V.data>='"+RevertOrd(data_inicial->DateTime.DateString())+"' AND V.data<='"+RevertOrd(data_final->DateTime.DateString())+"')) GROUP BY V.ano ORDER BY V.data ASC";
		break;
	}

	Chart1->Series[0]->Clear();
	Chart1->Title->Clear();

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		if(i == 0)
		{
			Chart1->Title->Text->Add("GRÁFICO DE VENDAS");
			i++;
		}

		switch(ComboPeriodo->ItemIndex)
		{
			case 0:
				TextLegenda = SQLQuery1->Fields->FieldByName("data")->AsString;
			break;
			case 1:
				TextLegenda = NOME_MESES[SQLQuery1->Fields->FieldByName("mes")->AsInteger-1]+" de "+SQLQuery1->Fields->FieldByName("ano")->AsString;
			break;
			case 2:
				TextLegenda = SQLQuery1->Fields->FieldByName("ano")->AsString;
			break;
		}

		X = i;

		Y = SQLQuery1->Fields->FieldByName("valor")->AsFloat;

		Chart1->Series[0]->AddXY(X,Y,TextLegenda,clTeeColor);

		SQLQuery1->Next();
		i++;
	}
	GerarGrid();
}
//---------------------------------------------------------------------------
void __fastcall TFGraficoVendas::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);

	SQLQuery1->SQLConnection = SQLCONNECT;
}
//---------------------------------------------------------------------------
void TFGraficoVendas::Designer()
{
	//TABELA
	if(CheckTabela->Checked)
	{
		StringGrid1->Visible = TRUE;

		if(CheckGrafico->Checked)
			StringGrid1->Height = (ClientHeight-PanelOpcao->Height)/2;
		else
			StringGrid1->Height = (ClientHeight-PanelOpcao->Height);
	}
	else
	{
		StringGrid1->Visible = FALSE;
		StringGrid1->Height = 0;
	}

    //GRAFICO
	if(CheckGrafico->Checked)
		Chart1->Visible = TRUE;
	else
		Chart1->Visible = FALSE;
}
void __fastcall TFGraficoVendas::CheckGraficoClick(TObject *Sender)
{
	Designer();
}
//---------------------------------------------------------------------------
void __fastcall TFGraficoVendas::CheckTabelaClick(TObject *Sender)
{
	Designer();
}
//---------------------------------------------------------------------------

void __fastcall TFGraficoVendas::Button1Click(TObject *Sender)
{
	MontarGrafico();
}
//---------------------------------------------------------------------------
void TFGraficoVendas::InicializarCampos()
{
	data_inicial->Date = Now();
	data_final->Date = Now();
	data_inicial->Date = data_inicial->Date - 30;

	CheckConsumidor->Checked = TRUE;
	CheckFinalizado->Checked = FALSE;
	CheckGrafico->Checked = TRUE;
	CheckTabela->Checked = TRUE;
}
void __fastcall TFGraficoVendas::FormShow(TObject *Sender)
{
	InicializarCampos();
	CarregarBoxAtendentes();
	Designer();
	SetarModo();
	MontarGrafico();
}
//---------------------------------------------------------------------------
void TFGraficoVendas::CarregarBoxAtendentes()
{
	UnicodeString QUERY;
	int i;

	ComboAtendentes->Clear();
	ComboAtendentes->Items->Add("TODOS");
	/*---------------------Get Numero de Registros------------------------*/
	QUERY = "SELECT COUNT(id) AS numero_registros FROM usuarios ORDER BY id ASC";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	NAtendentes = SQLQuery1->Fields->FieldByName("numero_registros")->AsInteger;

	if(NAtendentes)
	{
		atendentes = (IdDesc *) malloc(NAtendentes*sizeof(IdDesc));

		QUERY = "SELECT id,nome FROM usuarios ORDER BY nome ASC";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->Open();
		SQLQuery1->First();

		i = 0;
		while(SQLQuery1->Fields->FieldByName("id")->AsInteger && i<NAtendentes)
		{
			atendentes[i].id = SQLQuery1->Fields->FieldByName("id")->AsInteger;
			atendentes[i].desc = StrToChar(SQLQuery1->Fields->FieldByName("nome")->AsString);
			ComboAtendentes->Items->Add(atendentes[i].desc);
			i++;
			SQLQuery1->Next();
		}
	}

	//SETANDO O COMBO
	ComboAtendentes->ItemIndex = 0;
}
void TFGraficoVendas::SetarModo()
{
	int i;
	if(modo)
	{
		//SETANDO O COMBO
		for(i=0;i<NAtendentes;i++)
			if((atendentes+i)->id == USUARIO)
				break;

		ComboAtendentes->ItemIndex = i + 1;
		ComboAtendentes->Enabled = FALSE;
	}
	else
	{
		ComboAtendentes->ItemIndex = 0;
		ComboAtendentes->Enabled = TRUE;
	}
}
void TFGraficoVendas::GerarGrid()
{
	UnicodeString QUERY,MODO;
	UnicodeString CONSUMIDOR,FECHAMENTO,ATENDENTE;
	int numerodalinha,i,j,cc,rc;

	rc = StringGrid1->RowCount;
	cc = StringGrid1->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
		StringGrid1->Cells[j][i] = "";

	if(CheckConsumidor->Checked)
		CONSUMIDOR = "1";
	else
		CONSUMIDOR = "0";

	if(CheckFinalizado->Checked)
		FECHAMENTO = "2";
	else
		FECHAMENTO = "0";

	if(ComboAtendentes->ItemIndex>0)
		ATENDENTE  = "AND U.nome = '"+CharToStr(atendentes[ComboAtendentes->ItemIndex - 1].desc)+"' ";
	else
		ATENDENTE = "";

	numerodalinha = 1;
	// ESTRUTURA StringGrid1
	StringGrid1->Options << goRowSelect;
	StringGrid1->ScrollBars = ssVertical;
	StringGrid1->Rows[1]->Clear();
	StringGrid1->RowCount = 0;
	StringGrid1->ColCount = 6;
	StringGrid1->FixedCols = 0;
	StringGrid1->ColWidths[0] = ((StringGrid1->Width)/6);
	StringGrid1->ColWidths[1] = ((StringGrid1->Width)/6);
	StringGrid1->ColWidths[2] = ((StringGrid1->Width)/6);
	StringGrid1->ColWidths[3] = ((StringGrid1->Width)/6);
	StringGrid1->ColWidths[4] = ((StringGrid1->Width)/6);
	StringGrid1->ColWidths[5] = ((StringGrid1->Width)/6);
	StringGrid1->Cols[0]->Add("CÓDIGO");
	StringGrid1->Cols[1]->Add("DATA");
	StringGrid1->Cols[2]->Add("CLIENTE");
	StringGrid1->Cols[3]->Add("ATENDENTE");
	StringGrid1->Cols[4]->Add("MODO DE PAGAR");
	StringGrid1->Cols[5]->Add("VALOR");
	// ESTRUTURA StringGrid1

	switch(ComboPeriodo->ItemIndex)
	{
		case 0:
			QUERY = "SELECT V.id AS id,V.codigo_caixa AS codigo_caixa,V.codigo AS codigo,V.vendedor AS id_vendedor,V.atendente AS id_atendente,V.cliente AS id_cliente,V.modo_pagar AS modo_pagar,V.data AS data,V.valor AS valor,V.fechamento AS fechamento,V.data AS data,V.mes AS mes,V.ano AS ano,C.id AS id_c,C.nome_fantasia AS cliente,CF.id AS id_cf,CF.cliente AS cliente_cf,CF.consumidor AS consumidor,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (V.cliente = CF.cliente) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE ((CF.consumidor='1' OR CF.consumidor='"+CONSUMIDOR+"') "+ATENDENTE+"AND V.fechamento>='"+FECHAMENTO+"' AND (V.data>='"+RevertOrd(data_inicial->DateTime.DateString())+"' AND V.data<='"+RevertOrd(data_final->DateTime.DateString())+"')) ORDER BY V.data ASC";
		break;
		case 1:
			QUERY = "SELECT V.id AS id,V.codigo_caixa AS codigo_caixa,V.codigo AS codigo,V.vendedor AS id_vendedor,V.atendente AS id_atendente,V.cliente AS id_cliente,V.modo_pagar AS modo_pagar,V.data AS data,V.valor AS valor,V.fechamento AS fechamento,V.data AS data,V.mes AS mes,V.ano AS ano,C.id AS id_c,C.nome_fantasia AS cliente,CF.id AS id_cf,CF.cliente AS cliente_cf,CF.consumidor AS consumidor,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (V.cliente = CF.cliente) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE ((CF.consumidor='1' OR CF.consumidor='"+CONSUMIDOR+"') "+ATENDENTE+"AND V.fechamento>='"+FECHAMENTO+"' AND (V.data>='"+RevertOrd(data_inicial->DateTime.DateString())+"' AND V.data<='"+RevertOrd(data_final->DateTime.DateString())+"')) ORDER BY V.data ASC";
		break;
		case 2:
			QUERY = "SELECT V.id AS id,V.codigo_caixa AS codigo_caixa,V.codigo AS codigo,V.vendedor AS id_vendedor,V.atendente AS id_atendente,V.cliente AS id_cliente,V.modo_pagar AS modo_pagar,V.data AS data,V.valor AS valor,V.fechamento AS fechamento,V.data AS data,V.mes AS mes,V.ano AS ano,C.id AS id_c,C.nome_fantasia AS cliente,CF.id AS id_cf,CF.cliente AS cliente_cf,CF.consumidor AS consumidor,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (V.cliente = CF.cliente) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE ((CF.consumidor='1' OR CF.consumidor='"+CONSUMIDOR+"') "+ATENDENTE+"AND V.fechamento>='"+FECHAMENTO+"' AND (V.data>='"+RevertOrd(data_inicial->DateTime.DateString())+"' AND V.data<='"+RevertOrd(data_final->DateTime.DateString())+"')) ORDER BY V.data ASC";
		break;
	}

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		switch(SQLQuery1->Fields->FieldByName("modo_pagar")->AsInteger)
		{
			case 0:
				MODO = "DINHEIRO";
			break;
			case 1:
				MODO = "CARTÃO";
			break;
			case 2:
				MODO = "CHEQUE";
			break;
			case 3:
				MODO = "CARTEIRA";
			break;
			case 4:
				MODO = "VALE";
			break;
		}
		StringGrid1->Cells[0][numerodalinha] = SQLQuery1->Fields->FieldByName("codigo")->AsString;
		StringGrid1->Cells[1][numerodalinha] = SQLQuery1->Fields->FieldByName("data")->AsString;
		StringGrid1->Cells[2][numerodalinha] = SQLQuery1->Fields->FieldByName("cliente")->AsString;
		StringGrid1->Cells[3][numerodalinha] = SQLQuery1->Fields->FieldByName("atendente")->AsString;
		StringGrid1->Cells[4][numerodalinha] = MODO;
		StringGrid1->Cells[5][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("valor")->AsFloat);
		StringGrid1->RowCount++;
		SQLQuery1->Next();
		numerodalinha++;
		if (numerodalinha == 2)
			StringGrid1->FixedRows = 1;
	}
	if (numerodalinha <= 1)
		StringGrid1->RowCount++;
}
void __fastcall TFGraficoVendas::FormClose(TObject *Sender, TCloseAction &Action)
{
	if(atendentes)
		free(atendentes);
}
//---------------------------------------------------------------------------

void __fastcall TFGraficoVendas::StringGrid1DrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
{
UnicodeString Texto;
	if(ARow>0)
	{
		Texto = StringGrid1->Cells[ACol][ARow];

		StringGrid1->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGrid1->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGrid1->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGrid1->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGrid1->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGrid1->Canvas->FillRect(Rect);
		StringGrid1->Canvas->Rectangle(Rect.Left-5,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGrid1->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

	}
}
//---------------------------------------------------------------------------

