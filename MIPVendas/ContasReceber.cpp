//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ContasReceber.h"
#include "Principal.h"
#include "PedidosView.h"
#include "ContasReceberFechamento.h"
#include "ConfigContasReceberEspelho.h"
#include "ConfigContasReceberModel.h"
#include "autoload.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFContasReceber *FContasReceber;
//---------------------------------------------------------------------------
__fastcall TFContasReceber::TFContasReceber(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFContasReceber::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);

	SQLQuery1->SQLConnection = SQLCONNECT;
}
//---------------------------------------------------------------------------
void __fastcall TFContasReceber::GridPendentesDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	UnicodeString Texto;
	TDate data;
	int atrasado = 0;

	if(ARow>0)
	{
		Texto = GridPendentes->Cells[ACol][ARow];
		data = GridPendentes->Cells[2][ARow];

		//VERIFICA SE O PRAZO NAO ESTOROU
		if(data + dias_notificao < Now())
			atrasado = 1;

		GridPendentes->Canvas->Font->Color=clBlack;

		if(atrasado)
			GridPendentes->Canvas->Font->Color = clRed;

		if(ARow%2!=0)
			GridPendentes->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridPendentes->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridPendentes->Canvas->Brush->Color=TColor(0xc9a78b);

			if(atrasado)
				GridPendentes->Canvas->Brush->Color=TColor(0x9696EF);

			GridPendentes->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridPendentes->Canvas->FillRect(Rect);
		GridPendentes->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridPendentes->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);
	}
}
//---------------------------------------------------------------------------
void TFContasReceber::GerarGridPendentes()
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
		QUERY = "SELECT V.id AS id,V.cliente AS cliente_id,sum(V.valor) AS valor,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,MIN(V.data) AS data,C.id AS id_c,C.nome_fantasia AS cliente,CF.consumidor AS consumidor FROM vendas AS V INNER JOIN clientes AS C ON(V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (CF.cliente = C.id) WHERE (V.modo_pagar='3' AND V.fechamento = '0' AND C.nome_fantasia LIKE '%"+EditBuscaPendentes->Text+"%' AND CF.consumidor='1') GROUP BY V.cliente ORDER BY C.nome_fantasia ASC";
	else
		QUERY = "SELECT V.id AS id,V.cliente AS cliente_id,sum(V.valor) AS valor,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,MIN(V.data) AS data,C.id AS id_c,C.nome_fantasia AS cliente,CF.consumidor AS consumidor FROM vendas AS V INNER JOIN clientes AS C ON(V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (CF.cliente = C.id) WHERE (V.modo_pagar='3' AND V.fechamento = '0' AND C.nome_fantasia LIKE '%"+EditBuscaPendentes->Text+"%' AND CF.consumidor='1') GROUP BY V.cliente ORDER BY C.nome_fantasia ASC";

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
	LimparCheck();
}
void __fastcall TFContasReceber::FormShow(TObject *Sender)
{
	loadCabecalho();

	RadioSimplesPendentes->Checked = TRUE;
	RadioSimplesFechamentos->Checked = TRUE;
	RadioSimplesArquivados->Checked = TRUE;
    CheckConsumidorPendentes->Checked = FALSE;
    CheckConsumidorFechamentos->Checked = FALSE;
    CheckConsumidorArquivados->Checked = FALSE;

	PageControlPrincipal->TabIndex = 0;
	dias_notificao = GetDiasNotificacao();

	DesignerPendentes();
	GerarGridPendentes();
	GerarGridPendentesDetalhada();
}
//---------------------------------------------------------------------------
void __fastcall TFContasReceber::GridPendentesDetalhadaDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	UnicodeString Texto;
	tagRECT *rc;
    int i,c,all_select;

	rc = (tagRECT *) malloc(sizeof(tagRECT));
	rc->left = Rect.Left;
	rc->top = Rect.top;
	rc->right = Rect.Right;
	rc->bottom = Rect.Bottom;
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

	if(ACol == 0)
	{
		 all_select = 1;
		 c = GridPendentesDetalhada->RowCount;
		 for(i=1;i<c;i++)
			if(!ProucurarLinha(i))
			{
				all_select = 0;
				break;
			}

		if (ProucurarLinha(ARow) || all_select)
			DrawFrameControl(GridPendentesDetalhada->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
		else
			DrawFrameControl(GridPendentesDetalhada->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK);
	}
}
//---------------------------------------------------------------------------
void TFContasReceber::GerarGridPendentesDetalhada()
{
	UnicodeString QUERY,MODO;
	int numerodalinha,i,j,cc,rc;

	rc = GridPendentesDetalhada->RowCount;
	cc = GridPendentesDetalhada->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
			GridPendentesDetalhada->Cells[j][i] = "";

	LimparCheck();
	numerodalinha = 1;
	// ESTRUTURA
	GridPendentesDetalhada->Options << goRowSelect;
	GridPendentesDetalhada->ScrollBars = ssVertical;
	GridPendentesDetalhada->Rows[1]->Clear();
	GridPendentesDetalhada->RowCount = 0;
	GridPendentesDetalhada->ColCount = 6;
	GridPendentesDetalhada->FixedCols = 0;
	GridPendentesDetalhada->ColWidths[0] = 50;
	GridPendentesDetalhada->ColWidths[1] = ((GridPendentesDetalhada->Width)/4) - 50;
	GridPendentesDetalhada->ColWidths[2] = ((GridPendentesDetalhada->Width)/4);
	GridPendentesDetalhada->ColWidths[3] = ((GridPendentesDetalhada->Width)/4);
	GridPendentesDetalhada->ColWidths[4] = ((GridPendentesDetalhada->Width)/4);
	GridPendentesDetalhada->Cols[0]->Add("");
	GridPendentesDetalhada->Cols[1]->Add("CÓDIGO");
	GridPendentesDetalhada->Cols[2]->Add("DATA");
	GridPendentesDetalhada->Cols[3]->Add("ATENDENTE");
	GridPendentesDetalhada->Cols[4]->Add("VALOR");
	// ESTRUTURA

	id_cliente = FStrToInt(GridPendentes->Cells[0][rowselect_pendentes]);

	if(RadioSimplesPendentes->Checked)
		QUERY = "SELECT V.id AS id,V.codigo_caixa AS codigo_caixa,V.codigo AS codigo,V.vendedor AS id_vendedor,V.atendente AS id_atendente,V.cliente AS id_cliente,V.modo_pagar AS modo_pagar,V.data AS data,V.valor AS valor,V.fechamento AS fechamento,C.id AS id_c,C.nome_fantasia AS cliente,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE (V.cliente = '"+GridPendentes->Cells[0][rowselect_pendentes]+"' AND V.fechamento='0' AND V.modo_pagar='3') ORDER BY V.codigo ASC";
	else
		QUERY = "SELECT V.id AS id,V.codigo_caixa AS codigo_caixa,V.codigo AS codigo,V.vendedor AS id_vendedor,V.atendente AS id_atendente,V.cliente AS id_cliente,V.modo_pagar AS modo_pagar,V.data AS data,V.valor AS valor,V.fechamento AS fechamento,C.id AS id_c,C.nome_fantasia AS cliente,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE (V.cliente = '"+GridPendentes->Cells[0][rowselect_pendentes]+"' AND V.fechamento='0' AND V.modo_pagar='3') ORDER BY V.codigo ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		GridPendentesDetalhada->Cells[1][numerodalinha] = SQLQuery1->Fields->FieldByName("codigo")->AsString;
		GridPendentesDetalhada->Cells[2][numerodalinha] = SQLQuery1->Fields->FieldByName("data")->AsString;
		GridPendentesDetalhada->Cells[3][numerodalinha] = SQLQuery1->Fields->FieldByName("atendente")->AsString;
		GridPendentesDetalhada->Cells[4][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("valor")->AsFloat);
		GridPendentesDetalhada->RowCount++;
		SQLQuery1->Next();
		numerodalinha++;
	}

	TotalPendentes();
}
//---------------------------------------------------------------------------
void __fastcall TFContasReceber::GridPendentesSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselect_pendentes = ARow;
	CLIENTE_SELECIONADO = GridPendentes->Cells[1][rowselect_pendentes];
	CLIENTE_ID_SELECIONADO = GridPendentes->Cells[0][rowselect_pendentes];

	GerarGridPendentesDetalhada();
}
//---------------------------------------------------------------------------
void TFContasReceber::DesignerPendentes()
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
void TFContasReceber::DesignerFechamentos()
{
	int borda = 20;

	PanelFechamentosFixo->Top = borda;
	PanelFechamentosFixo->Left = borda;
	PanelFechamentosFixo->Height =  PanelFechamentos->Height - 2*borda;

	PanelFechamentosVariavel->Top = borda;
	PanelFechamentosVariavel->Left = PanelFechamentosFixo->Width + 2*borda;
	PanelFechamentosVariavel->Height = PanelFechamentos->Height - 2*borda;
	PanelFechamentosVariavel->Width = PanelFechamentos->Width - PanelFechamentosFixo->Width - 4*borda;
}
void TFContasReceber::DesignerArquivados()
{
	int borda = 20;

	PanelArquivadosFixo->Top = borda;
	PanelArquivadosFixo->Left = borda;
	PanelArquivadosFixo->Height =  PanelArquivados->Height - 2*borda;

	PanelArquivadosVariavel->Top = borda;
	PanelArquivadosVariavel->Left = PanelArquivadosFixo->Width + 2*borda;
	PanelArquivadosVariavel->Height = PanelArquivados->Height - 2*borda;
	PanelArquivadosVariavel->Width = PanelArquivados->Width - PanelArquivadosFixo->Width - 4*borda;
}
void TFContasReceber::MarcarCheck(Check *Proximo)
{
	Check *movel;

	if(!LinhasSelecionadasNo)
	{
		LinhasSelecionadasNo = (Check*) malloc(sizeof(Check));
		LinhasSelecionadasNo->linha = Proximo->linha;
		LinhasSelecionadasNo->codigo = Proximo->codigo;
		LinhasSelecionadasNo->data = Proximo->data;
		LinhasSelecionadasNo->cliente = Proximo->cliente;
		LinhasSelecionadasNo->vendedor = Proximo->vendedor;
		LinhasSelecionadasNo->atendente = Proximo->atendente;
		LinhasSelecionadasNo->valor = Proximo->valor;
		LinhasSelecionadasNo->proximo = NULL;
	}
	else
	{
		movel = LinhasSelecionadasNo;
		while(movel->proximo)
			movel = movel->proximo;

		movel->proximo = (Check*) malloc(sizeof(Check));
		movel->proximo->linha = Proximo->linha;
		movel->proximo->codigo = Proximo->codigo;
		movel->proximo->data = Proximo->data;
		movel->proximo->cliente = Proximo->cliente;
		movel->proximo->vendedor = Proximo->vendedor;
		movel->proximo->atendente = Proximo->atendente;
		movel->proximo->valor = Proximo->valor;
		movel->proximo->proximo = NULL;
	}
}
//---------------------------------------------------------------------------
void TFContasReceber::DesmarcarCheck(int linha)
{
	Check *atual,*anterior;

	if(LinhasSelecionadasNo)
	{
		atual = LinhasSelecionadasNo;

		//CASO INICIAL
		if(atual->linha == linha)
		{
			LinhasSelecionadasNo = LinhasSelecionadasNo->proximo;
			free(atual);
			atual = NULL;
		}


		while(atual)
		{
			anterior = atual;
			atual = atual->proximo;

			if(atual)
			{
				if(atual->linha == linha)
				{
					//CASO DO MEIO
					if(atual->proximo)
					{
						anterior->proximo = atual->proximo;
						free(atual);
						atual = NULL;
					}
					else //CASO FINAL
					{
						anterior->proximo = NULL;
						free(atual);
						atual = NULL;
					}

					break;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
int TFContasReceber::ProucurarLinha(int linha)
{
	Check *movel;
	int iR = 0;

	if(LinhasSelecionadasNo)
	{
		movel = LinhasSelecionadasNo;

		while(movel)
		{
			if(movel->linha == linha)
			{
				iR = 1;
				break;
			}
			movel = movel->proximo;
		}
	}

	return iR;
}

void __fastcall TFContasReceber::FormClose(TObject *Sender, TCloseAction &Action)
{
	Check *movel;

	//LIBERAR MEMORIA
	if(LinhasSelecionadasNo)
	{
		LinhasSelecionadasMovel = LinhasSelecionadasNo;
		while(LinhasSelecionadasMovel->proximo)
		{
			movel = LinhasSelecionadasMovel;
			LinhasSelecionadasMovel = LinhasSelecionadasMovel->proximo;
			free(movel);
			movel = NULL;
		}

		if(LinhasSelecionadasNo)
		{
			free(LinhasSelecionadasNo);
			LinhasSelecionadasNo = NULL;
		}
	}

	LiberarMemoriaFechamentos();
	LiberarMemoriaMIPGestaoValores();
}
//---------------------------------------------------------------------------
void TFContasReceber::LiberarMemoriaMIPGestaoValores()
{
	if(MIPGestao.host)
		free(MIPGestao.host);

	if(MIPGestao.bd)
		free(MIPGestao.bd);

	if(MIPGestao.usuario_bd)
		free(MIPGestao.usuario_bd);

	if(MIPGestao.senha)
		free(MIPGestao.senha);

	if(MIPGestao.fornecedor)
		free(MIPGestao.fornecedor);

	if(MIPGestao.fornecedor_cnpj)
		free(MIPGestao.fornecedor_cnpj);

	if(MIPGestao.usuario)
		free(MIPGestao.usuario);
}
//---------------------------------------------------------------------------
void __fastcall TFContasReceber::GridPendentesDetalhadaSelectCell(TObject *Sender,
          int ACol, int ARow, bool &CanSelect)
{
	rowselect_pendentes_detalhada = ARow;
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::GridPendentesDetalhadaMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int i,c,all_select;

	if(rowselect_pendentes_detalhada>0)
	{
		LinhasSelecionadasMovel = (Check *) malloc(sizeof(Check));

		LinhasSelecionadasMovel->linha = rowselect_pendentes_detalhada;
		LinhasSelecionadasMovel->codigo = FStrToInt(GridPendentesDetalhada->Cells[1][rowselect_pendentes_detalhada]);
		LinhasSelecionadasMovel->data = GridPendentesDetalhada->Cells[2][rowselect_pendentes_detalhada];
		LinhasSelecionadasMovel->cliente = FStrToInt(GridPendentesDetalhada->Cells[1][rowselect_pendentes_detalhada]);
		LinhasSelecionadasMovel->vendedor = FStrToInt(GridPendentesDetalhada->Cells[1][rowselect_pendentes_detalhada]);;
		LinhasSelecionadasMovel->atendente = FStrToInt(GridPendentesDetalhada->Cells[1][rowselect_pendentes_detalhada]);
		LinhasSelecionadasMovel->valor = FStrToFloat(GridPendentesDetalhada->Cells[4][rowselect_pendentes_detalhada]);

		if(!ProucurarLinha(rowselect_pendentes_detalhada))
			MarcarCheck(LinhasSelecionadasMovel);
		else
			DesmarcarCheck(LinhasSelecionadasMovel->linha);

		free(LinhasSelecionadasMovel);
	}
	else
	{
		 all_select = 1;
		 c = GridPendentesDetalhada->RowCount;
		 for(i=1;i<c;i++)
			if(!ProucurarLinha(i))
			{
				all_select = 0;
				break;
			}

		if(!all_select)
		{
			for(i=1;i<c;i++)
            {
				LinhasSelecionadasMovel = (Check *) malloc(sizeof(Check));

				LinhasSelecionadasMovel->linha = i;
				LinhasSelecionadasMovel->codigo = FStrToInt(GridPendentesDetalhada->Cells[1][i]);
				LinhasSelecionadasMovel->data = GridPendentesDetalhada->Cells[2][i];
				LinhasSelecionadasMovel->cliente = FStrToInt(GridPendentesDetalhada->Cells[1][i]);
				LinhasSelecionadasMovel->vendedor = FStrToInt(GridPendentesDetalhada->Cells[1][i]);;
				LinhasSelecionadasMovel->atendente = FStrToInt(GridPendentesDetalhada->Cells[1][i]);
				LinhasSelecionadasMovel->valor = FStrToFloat(GridPendentesDetalhada->Cells[4][i]);

				if(!ProucurarLinha(i))
					MarcarCheck(LinhasSelecionadasMovel);

				free(LinhasSelecionadasMovel);
			}
		}
		else
		{
			for(i=1;i<c;i++)
            {
				if(ProucurarLinha(i))
					DesmarcarCheck(i);
			}
		}
	}
	GridPendentesDetalhada->Repaint();
	TotalPendentes();
}
//---------------------------------------------------------------------------
void TFContasReceber::TotalPendentes()
{
	float total = 0;

	if(LinhasSelecionadasNo)
	{
		LinhasSelecionadasMovel = LinhasSelecionadasNo;
		while(LinhasSelecionadasMovel)
		{
			total = total + LinhasSelecionadasMovel->valor;
			LinhasSelecionadasMovel = LinhasSelecionadasMovel->proximo;
		}
	}

	EditPendentesSelecionado->Text = FormatFloat("#,###,###,##0.00",total);
}
void TFContasReceber::TotalArquivados()
{
	float total = 0;

	if(LinhasSelecionadasNo)
	{
		LinhasSelecionadasMovel = LinhasSelecionadasNo;
		while(LinhasSelecionadasMovel)
		{
			total = total + LinhasSelecionadasMovel->valor;
			LinhasSelecionadasMovel = LinhasSelecionadasMovel->proximo;
		}
	}

	EditArquivadosSelecionado->Text = FormatFloat("#,###,###,##0.00",total);
}
void __fastcall TFContasReceber::Button5Click(TObject *Sender)
{
	if(MessageBox(NULL,L"Deseja arquivar os pedidos selecionados?",L"Arquivar Pedidos",MB_YESNO | MB_ICONWARNING) == 6)
	{
		Arquivar();
		GerarGridPendentesDetalhada();
		LimparCheck();
	}
}
//---------------------------------------------------------------------------
int TFContasReceber::Arquivar()
{
	UnicodeString QUERY;
	int iR = 0;

	if(LinhasSelecionadasNo)
	{
		LinhasSelecionadasMovel = LinhasSelecionadasNo;

		while(LinhasSelecionadasMovel)
		{
			QUERY = "UPDATE vendas SET ";
			QUERY += "fechamento='1'";
			QUERY += " WHERE codigo='"+IntToStr(LinhasSelecionadasMovel->codigo)+"'";

			SQLQuery1->SQL->Clear();
			SQLQuery1->SQL->Add(QUERY);
			SQLQuery1->ExecSQL();
			LinhasSelecionadasMovel = LinhasSelecionadasMovel->proximo;
		}
		iR = 1;
		MessageBox(NULL,L"Pedidos arquivados com sucesso!",L"Arquivar Pedido",MB_OK | MB_ICONINFORMATION);
	}
	else
		MessageBox(NULL,L"Descuple, nenhum pedido selecionado!",L"Arquivar Pedido",MB_OK | MB_ICONERROR);
	return iR;
}
//---------------------------------------------------------------------------
void TFContasReceber::LimparCheck()
{
	Check *proximo;
	if(LinhasSelecionadasNo)
	{
		LinhasSelecionadasMovel = LinhasSelecionadasNo;
		while(LinhasSelecionadasMovel)
		{
			proximo = LinhasSelecionadasMovel->proximo;
			DesmarcarCheck(LinhasSelecionadasMovel->linha);
			LinhasSelecionadasMovel = proximo;
		}
	}
}
//---------------------------------------------------------------------------
void TFContasReceber::ExportarNFe()
{
}
//---------------------------------------------------------------------------
void __fastcall TFContasReceber::Button3Click(TObject *Sender)
{
	ExportarNFe();
}
//---------------------------------------------------------------------------
void TFContasReceber::AdicionarTabelaProdutos(TabelaProdutos *Proximo)
{
	TabelaProdutos *movel;

	if(!TabelaProdutosNo)
	{
		TabelaProdutosNo = (TabelaProdutos*) malloc(sizeof(TabelaProdutos));
		Orcamento.produtos = TabelaProdutosNo;

		TabelaProdutosNo->funcao = Proximo->funcao;
		TabelaProdutosNo->id = Proximo->id;
		TabelaProdutosNo->id_produto = Proximo->id_produto;
		TabelaProdutosNo->codbarras = Proximo->codbarras;
		TabelaProdutosNo->descricao = Proximo->descricao;
		TabelaProdutosNo->preco = Proximo->preco;
		TabelaProdutosNo->quantidade = Proximo->quantidade;
		TabelaProdutosNo->unidade = Proximo->unidade;
		TabelaProdutosNo->marca = Proximo->marca;
		TabelaProdutosNo->ncm = Proximo->ncm;
		TabelaProdutosNo->cfop = Proximo->cfop;
		TabelaProdutosNo->desconto = Proximo->desconto;
		TabelaProdutosNo->promocao = Proximo->promocao;
		TabelaProdutosNo->devolucao = Proximo->devolucao;
		TabelaProdutosNo->proximo = NULL;
	}
	else
	{
		movel = TabelaProdutosNo;
		while(movel->proximo)
		movel = movel->proximo;

		movel->proximo = (TabelaProdutos*) malloc(sizeof(TabelaProdutos));

		movel->proximo->funcao = Proximo->funcao;
		movel->proximo->id = Proximo->id;
		movel->proximo->id_produto = Proximo->id_produto;
		movel->proximo->codbarras = Proximo->codbarras;
		movel->proximo->descricao = Proximo->descricao;
		movel->proximo->preco = Proximo->preco;
		movel->proximo->quantidade = Proximo->quantidade;
		movel->proximo->unidade = Proximo->unidade;
		movel->proximo->marca = Proximo->marca;
		movel->proximo->ncm = Proximo->ncm;
		movel->proximo->cfop = Proximo->cfop;
		movel->proximo->desconto = Proximo->desconto;
		movel->proximo->promocao = Proximo->promocao;
		movel->proximo->devolucao = Proximo->devolucao;
		movel->proximo->proximo = NULL;
	}
}
//------------------------------------------------------------------------
float TFContasReceber::CalculoNcm(UnicodeString ncm,float valor)
{
	TSQLQuery *SQLQuery;
	float aliquota;
	int r;

	SQLQuery = new TSQLQuery(NULL);
	SQLQuery->SQLConnection = SQLCONNECT;

	SQLQuery->SQL->Clear();
	SQLQuery->SQL->Add("SELECT id,ncm,aliquota_nacional FROM nfe_ncm WHERE ncm='"+ncm+"' ORDER BY id ASC");
	SQLQuery->Open();
	SQLQuery->First();

	aliquota = SQLQuery->Fields->FieldByName("aliquota_nacional")->AsFloat;

	r = valor*aliquota/100;

	delete(SQLQuery);

	return r;

}
//------------------------------------------------------------------------
void TFContasReceber::LiberarMemoriaProdutos()
{
	TabelaProdutos *movel;

	//LIBERAR MEMORIA
	if(TabelaProdutosNo)
	{
		TabelaProdutosMovel = TabelaProdutosNo;
		while(TabelaProdutosMovel->proximo)
		{
			movel = TabelaProdutosMovel;
			TabelaProdutosMovel = TabelaProdutosMovel->proximo;
			free(movel);
			movel = NULL;
		}

		if(TabelaProdutosNo)
		{
			free(TabelaProdutosNo);
			TabelaProdutosNo = NULL;
		}
	}
}
//-----------------------------------------------------------------------
void TFContasReceber::ProucurarCodbarras(char *codbarras,TabelaProdutos **ponteiro)
{
	TabelaProdutos *movel;

	*ponteiro = NULL;
	if(TabelaProdutosNo)
	{
		movel = TabelaProdutosNo;
		while(movel)
		{
			if(strcmp(movel->codbarras,codbarras) == 0)
			{
				*ponteiro = movel;
				break;
			}
			movel = movel->proximo;
		}
	}
}
//-----------------------------------------------------------------------
int TFContasReceber::GetDiasNotificacao()
{
	ConfigContasReceberEspelho *config_contas_receber = ConfigContasReceberModel::selectAll();

	return config_contas_receber->getNotificacao();
}


void __fastcall TFContasReceber::ButtonFiltrarPendentesClick(TObject *Sender)
{
	GerarGridPendentes();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::RadioSimplesPendentesClick(TObject *Sender)
{
	GerarGridPendentes();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::RadioIndicacaoPendentesClick(TObject *Sender)
{
	GerarGridPendentes();
}
//---------------------------------------------------------------------------

void TFContasReceber::RealizarFechamento()
{
	UnicodeString QUERY;
	UnicodeString CLIENTE;
	int CODIGO;
	int i;
	TDate data;

	/*------------------------------SETAR DATA----------------------------*/
	data = Now();

	/*--------------------------PEGAR ULTIMO CÓDIGO--------------------------*/
	QUERY = "SELECT id,codigo FROM fechamentos ORDER BY codigo DESC LIMIT 1";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	CODIGO = SQLQuery1->Fields->FieldByName("codigo")->AsInteger + 1;

	/*------------------------------GET CLIENTE-----------------------------*/
	CLIENTE = CLIENTE_ID_SELECIONADO;

	if(FechamentosNo)
	{
		FechamentosMovel = FechamentosNo;
		i = 1;
		while(FechamentosMovel)
		{
			QUERY = "INSERT INTO fechamentos (codigo,prestacao,data_fechamento,data_pagamento,modo_pagar,desconto,valor,usuario_fechamento,cliente,usuario_pagamento,situacao,valor_pago)";
			QUERY += " VALUES ('";
			QUERY += IntToStr(CODIGO)+"','";
			QUERY += IntToStr(i)+"','";
			QUERY += RevertOrd(data.DateString())+"','";
			QUERY += RevertOrd(FechamentosMovel->data_vencimento.DateString())+"','";
			QUERY += IntToStr(FechamentosMovel->modpagar)+"','";
			QUERY += FormatFloat("###########0.00",FechamentosMovel->desconto)+"','";
			QUERY += FormatFloat("###########0.00",FechamentosMovel->valor)+"','";
			QUERY += IntToStr(USUARIO)+"','";
			QUERY += CLIENTE+"','";
			QUERY += "0','";
			QUERY += "0','";
			QUERY += "0')";

			SQLQuery1->SQL->Clear();
			SQLQuery1->SQL->Add(QUERY);
			SQLQuery1->ExecSQL();

			FechamentosMovel = FechamentosMovel->proximo;
			i++;
		}
	}

	FecharPedidos(CODIGO);
	InserirMIPGestao(CODIGO,(i-1));
	LiberarMemoriaFechamentos();
	LimparCheck();
	GerarGridPendentesDetalhada();

	MessageBox(NULL,L"Fechamento realizado com sucesso!",L"Fechamento",MB_OK | MB_ICONINFORMATION);
}
void __fastcall TFContasReceber::Button4Click(TObject *Sender)
{
	if(LinhasSelecionadasNo)
	{
		LiberarMemoriaFechamentos();
		FContasReceberFechamento->ShowModal();
	}
	else
		MessageBox(NULL,L"Desculpe, nenhum pedido selecionado!",L"Realizar fechamento",MB_OK | MB_ICONERROR);

}
//---------------------------------------------------------------------------
void TFContasReceber::FecharPedidos(int codigo_fechamento)
{
	UnicodeString QUERY;

	if(LinhasSelecionadasNo)
	{
		LinhasSelecionadasMovel = LinhasSelecionadasNo;

		while(LinhasSelecionadasMovel)
		{
			QUERY = "UPDATE vendas SET ";
			QUERY += "fechamento='"+IntToStr(codigo_fechamento)+"'";
			QUERY += " WHERE codigo='"+IntToStr(LinhasSelecionadasMovel->codigo)+"'";

			SQLQuery1->SQL->Clear();
			SQLQuery1->SQL->Add(QUERY);
			SQLQuery1->ExecSQL();
			LinhasSelecionadasMovel = LinhasSelecionadasMovel->proximo;
		}
	}
}
//---------------------------------------------------------------------------
void TFContasReceber::InserirMIPGestao(int codigo_fechamento,int NParcelas)
{
   	UnicodeString QUERY,MEDICAO,DESCRICAO,MODO;
	int id_nota;
	TDate data;
	int i;

	if(ConectarMIPGestao())
	{
		SQLQuery2->SQLConnection = SQLConnection1;

		data = Now();

		if(FechamentosNo)
		{
			FechamentosMovel = FechamentosNo;
			i = 1;
			while(FechamentosMovel)
			{
				MEDICAO = i;

				switch(FechamentosMovel->modpagar)
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
						MODO = "BOLETO";
					break;
				}

				DESCRICAO = "FECHAMENTO DE CONTA - "+data.DateString()+"\r\n";
				DESCRICAO += "-------------------------------------------------\r\n";
				DESCRICAO += "CODIGO DO FECHAMENTO - "+IntToStr(codigo_fechamento)+"\r\n";
				DESCRICAO += "-------------------------------------------------\r\n";
				DESCRICAO += "CLIENTE - "+CLIENTE_SELECIONADO+"\r\n";
				DESCRICAO += "-------------------------------------------------\r\n";
				DESCRICAO += "PARCELA - "+MEDICAO+"/"+IntToStr(NParcelas)+"\r\n";
				DESCRICAO += "-------------------------------------------------\r\n";
				DESCRICAO += "VALOR DA PARCELA - "+FormatFloat("###########0.00",FechamentosMovel->valor)+"\r\n";
				DESCRICAO += "-------------------------------------------------\r\n";
				DESCRICAO += "MODO DE PAGAR - "+MODO+"\r\n";

				QUERY = "INSERT INTO notas_saida (fornecedor,cnpj,data_pagamento,data_emissao,data_lancamento,nnf,valor,vnf,icms,ipi,confins,pis,iss,descricao,conta_contabil,projeto,centro_custo,medicao,tipo_nf,usuario_lancamento,consolidado)";

				QUERY += " VALUES ('";
				QUERY += CharToStr(MIPGestao.fornecedor)+"','";
				QUERY += CharToStr(MIPGestao.fornecedor_cnpj)+"','";
				QUERY += RevertOrd(FechamentosMovel->data_vencimento.DateString())+"','";
				QUERY += RevertOrd(data.DateString())+"','";
				QUERY += RevertOrd(data.DateString())+"','";
				QUERY += IntToStr(codigo_fechamento)+"','";
				QUERY += FormatFloat("###########0.00",FechamentosMovel->valor)+"','";
				QUERY += FormatFloat("###########0.00",FechamentosMovel->valor)+"','";
				QUERY += "','";
				QUERY += "','";
				QUERY += "','";
				QUERY += "','";
				QUERY += "','";
				QUERY += DESCRICAO+"','";
				QUERY += IntToStr(MIPGestao.conta)+"','";
				QUERY += IntToStr(MIPGestao.projeto)+"','";
				QUERY += IntToStr(MIPGestao.centro)+"','";
				QUERY += MEDICAO+"','";
				QUERY += "0','";
				QUERY += CharToStr(MIPGestao.usuario)+"','";
				QUERY += "0')";

				SQLQuery2->SQL->Clear();
				SQLQuery2->SQL->Add(QUERY);
				SQLQuery2->ExecSQL();

				FechamentosMovel = FechamentosMovel->proximo;
				i++;
			}
		}
	}

	if(SQLConnection1->Connected == TRUE)
	{
		SQLConnection1->Close();
		SQLConnection1->Connected = FALSE;
	}
}
//------------------------------------------------------------------------
void TFContasReceber::CarregarMIPGestao()
{
	UnicodeString QUERY;

	QUERY = "SELECT id,host,nome_bd,usuario_bd,senha_bd,fornecedor_gestao,cnpj_gestao,usuario_gestao,centro_gestao,projeto_gestao,conta_gestao FROM link ORDER BY id ASC";

	LiberarMemoriaMIPGestaoValores();
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		MIPGestao.host = StrToChar(SQLQuery1->Fields->FieldByName("host")->AsString);
		MIPGestao.bd = StrToChar(SQLQuery1->Fields->FieldByName("nome_bd")->AsString);
		MIPGestao.usuario_bd = StrToChar(SQLQuery1->Fields->FieldByName("usuario_bd")->AsString);
		MIPGestao.senha = StrToChar(SQLQuery1->Fields->FieldByName("senha_bd")->AsString);
		MIPGestao.fornecedor = StrToChar(SQLQuery1->Fields->FieldByName("fornecedor_gestao")->AsString);
		MIPGestao.fornecedor_cnpj = StrToChar(SQLQuery1->Fields->FieldByName("cnpj_gestao")->AsString);
		MIPGestao.usuario = StrToChar(SQLQuery1->Fields->FieldByName("usuario_gestao")->AsString);
		MIPGestao.centro = SQLQuery1->Fields->FieldByName("centro_gestao")->AsInteger;
		MIPGestao.projeto = SQLQuery1->Fields->FieldByName("projeto_gestao")->AsInteger;
		MIPGestao.conta = SQLQuery1->Fields->FieldByName("conta_gestao")->AsInteger;
	}
}
//------------------------------------------------------------------------
int TFContasReceber::ConectarMIPGestao()
{
	int iR = 1;

	CarregarMIPGestao();

	//CONFIGURA SQL
	SQLConnection1->DriverName = "MySQL";

	//SETA PARÂMETROS SQL
	SQLConnection1->Params->Values["HostName"] = MIPGestao.host;
	SQLConnection1->Params->Values["Database"] = MIPGestao.bd;
	SQLConnection1->Params->Values["User_Name"] = MIPGestao.usuario_bd;
	SQLConnection1->Params->Values["Password"] = MIPGestao.senha;


	if(SQLConnection1->Connected==TRUE)
	{
		SQLConnection1->Close();
		SQLConnection1->Connected = FALSE;
	}

	//CONECTA NO BANCO DE DADOS
	try
	{
		SQLConnection1->Open();
	}
	catch (const Exception &)
	{
		iR = 0;
	}

	return iR;
}
void TFContasReceber::AdicionarFechamento(int linha,float valor,float desconto,int modpagar,TDate data_vencimento)
{
	TFechamentos *movel;

	if(!FechamentosNo)
	{
		FechamentosNo = (TFechamentos*) malloc(sizeof(Check));
		FechamentosNo->linha = linha;
		FechamentosNo->valor = valor;
		FechamentosNo->desconto = desconto;
		FechamentosNo->modpagar = modpagar;
		FechamentosNo->data_vencimento = data_vencimento;
		FechamentosNo->proximo = NULL;
	}
	else
	{
		movel = FechamentosNo;
		while(movel->proximo)
			movel = movel->proximo;

		movel->proximo = (TFechamentos*) malloc(sizeof(Check));
		movel->proximo->linha = linha;
		movel->proximo->valor = valor;
		movel->proximo->desconto = desconto;
		movel->proximo->modpagar = modpagar;
		movel->proximo->data_vencimento = data_vencimento;
		movel->proximo->proximo = NULL;
	}
}
void TFContasReceber::RemoverFechamento(int linha)
{
	TFechamentos *atual,*anterior;

	if(FechamentosNo)
	{
		atual = FechamentosNo;

		//CASO INICIAL
		if(atual->linha == linha)
		{
			FechamentosNo = FechamentosNo->proximo;
			free(atual);
			atual = NULL;
		}


		while(atual)
		{
			anterior = atual;
			atual = atual->proximo;

			if(atual)
			{
				if(atual->linha == linha)
				{
					//CASO DO MEIO
					if(atual->proximo)
					{
						anterior->proximo = atual->proximo;
						free(atual);
						atual = NULL;
					}
					else //CASO FINAL
					{
						anterior->proximo = NULL;
						free(atual);
						atual = NULL;
					}

					break;
				}
			}
		}
	}
}
void TFContasReceber::LiberarMemoriaFechamentos()
{
	TFechamentos *proximo;

	if(FechamentosNo)
	{
		FechamentosMovel = FechamentosNo;
		while(FechamentosMovel)
		{
			proximo = FechamentosMovel->proximo;
			RemoverFechamento(FechamentosMovel->linha);
			FechamentosMovel = proximo;
		}
	}
}



void __fastcall TFContasReceber::GridFechamentosDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	UnicodeString Texto;
	TDate data;
	int atrasado = 0;

	if(ARow>0)
	{
		Texto = GridFechamentos->Cells[ACol][ARow];
		data = GridFechamentos->Cells[2][ARow];

		//VERIFICA SE O PRAZO NAO ESTOROU
		if(data + dias_notificao < Now())
			atrasado = 1;

		GridFechamentos->Canvas->Font->Color=clBlack;

		if(atrasado)
			GridFechamentos->Canvas->Font->Color = clRed;

		if(ARow%2!=0)
			GridFechamentos->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridFechamentos->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridFechamentos->Canvas->Brush->Color=TColor(0xc9a78b);

			if(atrasado)
				GridFechamentos->Canvas->Brush->Color=TColor(0x9696EF);

			GridFechamentos->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridFechamentos->Canvas->FillRect(Rect);
		GridFechamentos->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridFechamentos->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::GridFechamentosDetalhadaDrawCell(TObject *Sender,
          int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
UnicodeString Texto;
	if(ARow>0)
	{
		Texto = GridFechamentosDetalhada->Cells[ACol][ARow];

		GridFechamentosDetalhada->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			GridFechamentosDetalhada->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridFechamentosDetalhada->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridFechamentosDetalhada->Canvas->Brush->Color=TColor(0xc9a78b);
			GridFechamentosDetalhada->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridFechamentosDetalhada->Canvas->FillRect(Rect);
		GridFechamentosDetalhada->Canvas->Rectangle(Rect.Left-5,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridFechamentosDetalhada->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

	}
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::GridFechamentosParcelasDrawCell(TObject *Sender,
		  int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
UnicodeString Texto;
	if(ARow>0)
	{
		Texto = GridFechamentosParcelas->Cells[ACol][ARow];

		GridFechamentosParcelas->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			GridFechamentosParcelas->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridFechamentosParcelas->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridFechamentosParcelas->Canvas->Brush->Color=TColor(0xc9a78b);
			GridFechamentosParcelas->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridFechamentosParcelas->Canvas->FillRect(Rect);
		GridFechamentosParcelas->Canvas->Rectangle(Rect.Left-5,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridFechamentosParcelas->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

	}

}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::GridFechamentosPedidosDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	UnicodeString Texto;
	tagRECT *rc;
    int i,c,all_select;

	rc = (tagRECT *) malloc(sizeof(tagRECT));
	rc->left = Rect.Left;
	rc->top = Rect.top;
	rc->right = Rect.Right;
	rc->bottom = Rect.Bottom;
	/*--------------------COLOCAR CHECKBOX----------------------------*/
	if (ARow>0)
	{
		Texto = GridFechamentosPedidos->Cells[ACol][ARow];

		GridFechamentosPedidos->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			GridFechamentosPedidos->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridFechamentosPedidos->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridFechamentosPedidos->Canvas->Brush->Color=TColor(0xc9a78b);
			GridFechamentosPedidos->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridFechamentosPedidos->Canvas->FillRect(Rect);
		GridFechamentosPedidos->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridFechamentosPedidos->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);
	}

	if(ACol == 0)
	{
		 all_select = 1;
		 c = GridFechamentosPedidos->RowCount;
		 for(i=1;i<c;i++)
			if(!ProucurarLinha(i))
			{
				all_select = 0;
				break;
			}

		if (ProucurarLinha(ARow) || all_select)
			DrawFrameControl(GridFechamentosPedidos->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
		else
			DrawFrameControl(GridFechamentosPedidos->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::ButtonFiltrarFechamentosClick(TObject *Sender)
{
	GerarGridFechamentos();
}
//---------------------------------------------------------------------------
void TFContasReceber::GerarGridFechamentos()
{
	UnicodeString QUERY;
	int numerodalinha,i,j,cc,rc;

	rc = GridFechamentos->RowCount;
	cc = GridFechamentos->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
			GridFechamentos->Cells[j][i] = "";

	numerodalinha = 1;
	// ESTRUTURA
	GridFechamentos->Options << goRowSelect;
	GridFechamentos->ScrollBars = ssVertical;
	GridFechamentos->Rows[1]->Clear();
	GridFechamentos->RowCount = 0;
	GridFechamentos->ColCount = 4;
	GridFechamentos->FixedCols = 0;
	GridFechamentos->ColWidths[0] = 0;
	GridFechamentos->ColWidths[1] = ((GridFechamentos->Width)/3)+200;
	GridFechamentos->ColWidths[2] = ((GridFechamentos->Width)/3)-100;
	GridFechamentos->ColWidths[3] = ((GridFechamentos->Width)/3)-100;
	GridFechamentos->Cols[0]->Add("CLIENTE ID");
	GridFechamentos->Cols[1]->Add("CLIENTE");
	GridFechamentos->Cols[2]->Add("DATA ANTIGA");
	GridFechamentos->Cols[3]->Add("VALOR");
	// ESTRUTURA
	if(RadioSimplesPendentes->Checked)
		QUERY = "SELECT F.id AS id,MIN(F.data_pagamento) AS data,SUM(F.valor) AS valor,F.cliente AS cliente_id,C.id AS id_c,C.nome_fantasia AS cliente,CF.cliente AS cliente_cc,CF.consumidor AS consumidor FROM fechamentos AS F INNER JOIN clientes AS C ON (C.id = F.cliente) INNER JOIN clientes_financeiro AS CF ON (CF.cliente = F.cliente) WHERE (F.situacao='0' AND CF.consumidor='1' AND C.nome_fantasia LIKE '%"+EditBuscaFechamentos->Text+"%') GROUP BY F.cliente ORDER BY C.nome_fantasia ASC";
	else
		QUERY = "SELECT F.id AS id,MIN(F.data_pagamento) AS data,SUM(F.valor) AS valor,F.cliente AS cliente_id,C.id AS id_c,C.nome_fantasia AS cliente,CF.cliente AS cliente_cc,CF.consumidor AS consumidor FROM fechamentos AS F INNER JOIN clientes AS C ON (C.id = F.cliente) INNER JOIN clientes_financeiro AS CF ON (CF.cliente = F.cliente) WHERE (F.situacao='0' AND CF.consumidor='1' AND C.nome_fantasia LIKE '%"+EditBuscaFechamentos->Text+"%') GROUP BY F.cliente ORDER BY C.nome_fantasia ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		GridFechamentos->Cells[0][numerodalinha] = SQLQuery1->Fields->FieldByName("cliente_id")->AsString;
		GridFechamentos->Cells[1][numerodalinha] = SQLQuery1->Fields->FieldByName("cliente")->AsString;
		GridFechamentos->Cells[2][numerodalinha] = SQLQuery1->Fields->FieldByName("data")->AsString;
		GridFechamentos->Cells[3][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("valor")->AsFloat);

		GridFechamentos->RowCount++;
		SQLQuery1->Next();
		numerodalinha++;
		if (numerodalinha == 2)
			GridFechamentos->FixedRows = 1;
	}
}
//---------------------------------------------------------------------------
void TFContasReceber::GerarGridFechamentosDetalhada()
{
	UnicodeString QUERY;
	int numerodalinha,i,j,cc,rc;

	rc = GridFechamentosDetalhada->RowCount;
	cc = GridFechamentosDetalhada->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
			GridFechamentosDetalhada->Cells[j][i] = "";

	numerodalinha = 1;
	// ESTRUTURA
	GridFechamentosDetalhada->Options << goRowSelect;
	GridFechamentosDetalhada->ScrollBars = ssVertical;
	GridFechamentosDetalhada->Rows[1]->Clear();
	GridFechamentosDetalhada->RowCount = 0;
	GridFechamentosDetalhada->ColCount = 6;
	GridFechamentosDetalhada->FixedCols = 0;
	GridFechamentosDetalhada->ColWidths[0] = 60;
	GridFechamentosDetalhada->ColWidths[1] = 60;
	GridFechamentosDetalhada->ColWidths[2] = ((GridFechamentosDetalhada->Width)/4)-25;
	GridFechamentosDetalhada->ColWidths[3] = ((GridFechamentosDetalhada->Width)/4)-25;
	GridFechamentosDetalhada->ColWidths[4] = ((GridFechamentosDetalhada->Width)/4)-35;
	GridFechamentosDetalhada->ColWidths[5] = ((GridFechamentosDetalhada->Width)/4)-35;
	GridFechamentosDetalhada->Cols[0]->Add("CODIGO");
	GridFechamentosDetalhada->Cols[1]->Add("PREST.");
	GridFechamentosDetalhada->Cols[2]->Add("FECHAMENTO");
	GridFechamentosDetalhada->Cols[3]->Add("VENCIMENTO");
	GridFechamentosDetalhada->Cols[4]->Add("PAGO");
	GridFechamentosDetalhada->Cols[5]->Add("VALOR");
	// ESTRUTURA
	if(RadioSimplesPendentes->Checked)
		QUERY = "SELECT F.id AS id,COUNT(F.prestacao) AS prestacoes,F.codigo AS codigo,MIN(F.data_pagamento) AS data_pagamento,MIN(F.data_fechamento) AS data_fechamento,SUM(F.valor) AS valor,SUM(F.valor_pago) AS pago,F.cliente AS cliente_id,C.id AS id_c,C.nome_fantasia AS cliente,CF.cliente AS cliente_cc,CF.consumidor AS consumidor,F.situacao AS situacao FROM fechamentos AS F INNER JOIN clientes AS C ON (C.id = F.cliente) INNER JOIN clientes_financeiro AS CF ON (CF.cliente = F.cliente) WHERE (F.situacao='0' AND CF.consumidor='1' AND C.nome_fantasia LIKE '%"+EditBuscaFechamentos->Text+"%' AND F.cliente='"+GridFechamentos->Cells[0][rowselect_fechamentos]+"') GROUP BY F.codigo ORDER BY C.nome_fantasia ASC";
	else
		QUERY = "SELECT F.id AS id,COUNT(F.prestacao) AS prestacoes,F.codigo AS codigo,MIN(F.data_pagamento) AS data_pagamento,MIN(F.data_fechamento) AS data_fechamento,SUM(F.valor) AS valor,SUM(F.valor_pago) AS pago,F.cliente AS cliente_id,C.id AS id_c,C.nome_fantasia AS cliente,CF.cliente AS cliente_cc,CF.consumidor AS consumidor,F.situacao AS situacao FROM fechamentos AS F INNER JOIN clientes AS C ON (C.id = F.cliente) INNER JOIN clientes_financeiro AS CF ON (CF.cliente = F.cliente) WHERE (F.situacao='0' AND CF.consumidor='1' AND C.nome_fantasia LIKE '%"+EditBuscaFechamentos->Text+"%' AND F.cliente='"+GridFechamentos->Cells[0][rowselect_fechamentos]+"') GROUP BY F.codigo ORDER BY C.nome_fantasia ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		GridFechamentosDetalhada->Cells[0][numerodalinha] = SQLQuery1->Fields->FieldByName("codigo")->AsString;
		GridFechamentosDetalhada->Cells[1][numerodalinha] = SQLQuery1->Fields->FieldByName("prestacoes")->AsString;
		GridFechamentosDetalhada->Cells[2][numerodalinha] = SQLQuery1->Fields->FieldByName("data_fechamento")->AsString;
		GridFechamentosDetalhada->Cells[3][numerodalinha] = SQLQuery1->Fields->FieldByName("data_pagamento")->AsString;
		GridFechamentosDetalhada->Cells[4][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("pago")->AsFloat);
		GridFechamentosDetalhada->Cells[5][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("valor")->AsFloat);

		GridFechamentosDetalhada->RowCount++;
		SQLQuery1->Next();
		numerodalinha++;
		if (numerodalinha == 2)
			GridFechamentosDetalhada->FixedRows = 1;
	}
}

void __fastcall TFContasReceber::GridFechamentosSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselect_fechamentos = ARow;
	rowselect_fechamentos_detalhada = 1;

	CLIENTE_SELECIONADO = GridFechamentos->Cells[1][rowselect_fechamentos];
	CLIENTE_ID_SELECIONADO = GridFechamentos->Cells[0][rowselect_fechamentos];

	GerarGridFechamentosDetalhada();
	GerarGridFechamentosParcelas();
	GerarGridFechamentosPedidos();
}
//---------------------------------------------------------------------------
void TFContasReceber::GerarGridFechamentosParcelas()
{
	UnicodeString QUERY,MODO;
	int numerodalinha,i,j,cc,rc;

	rc = GridFechamentosParcelas->RowCount;
	cc = GridFechamentosParcelas->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
			GridFechamentosParcelas->Cells[j][i] = "";

	numerodalinha = 1;
	// ESTRUTURA
	GridFechamentosParcelas->Options << goRowSelect;
	GridFechamentosParcelas->ScrollBars = ssVertical;
	GridFechamentosParcelas->Rows[1]->Clear();
	GridFechamentosParcelas->RowCount = 0;
	GridFechamentosParcelas->ColCount = 4;
	GridFechamentosParcelas->FixedCols = 0;
	GridFechamentosParcelas->ColWidths[0] = ((GridFechamentosParcelas->Width)/4);
	GridFechamentosParcelas->ColWidths[1] = ((GridFechamentosParcelas->Width)/4);
	GridFechamentosParcelas->ColWidths[2] = ((GridFechamentosParcelas->Width)/4);
	GridFechamentosParcelas->ColWidths[3] = ((GridFechamentosParcelas->Width)/4);
	GridFechamentosParcelas->Cols[0]->Add("PRESTACÃO");
	GridFechamentosParcelas->Cols[1]->Add("MODO DE PAGAR");
	GridFechamentosParcelas->Cols[2]->Add("VENCIMENTO");
	GridFechamentosParcelas->Cols[3]->Add("VALOR");
	// ESTRUTURA
	if(RadioSimplesPendentes->Checked)
		QUERY = "SELECT F.id AS id,F.prestacao AS prestacao,F.codigo AS codigo,F.data_pagamento AS data_pagamento,F.data_fechamento AS data_fechamento,F.valor AS valor,F.modo_pagar AS modo_pagar,F.situacao AS situacao FROM fechamentos AS F WHERE (F.situacao='0' AND F.codigo='"+GridFechamentosDetalhada->Cells[0][rowselect_fechamentos_detalhada]+"') ORDER BY F.prestacao ASC";
	else
		QUERY = "SELECT F.id AS id,F.prestacao AS prestacao,F.codigo AS codigo,F.data_pagamento AS data_pagamento,F.data_fechamento AS data_fechamento,F.valor AS valor,F.modo_pagar AS modo_pagar,F.situacao AS situacao FROM fechamentos AS F WHERE (F.situacao='0' AND F.codigo='"+GridFechamentosDetalhada->Cells[0][rowselect_fechamentos_detalhada]+"') ORDER BY F.prestacao ASC";

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
				MODO = "BOLETO";
			break;
		}
		GridFechamentosParcelas->Cells[0][numerodalinha] = SQLQuery1->Fields->FieldByName("prestacao")->AsString;
		GridFechamentosParcelas->Cells[1][numerodalinha] = MODO;
		GridFechamentosParcelas->Cells[2][numerodalinha] = SQLQuery1->Fields->FieldByName("data_pagamento")->AsString;
		GridFechamentosParcelas->Cells[3][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("valor")->AsFloat);

		GridFechamentosParcelas->RowCount++;
		SQLQuery1->Next();
		numerodalinha++;
		if (numerodalinha == 2)
			GridFechamentosParcelas->FixedRows = 1;
	}
}

void __fastcall TFContasReceber::GridFechamentosDetalhadaSelectCell(TObject *Sender,
          int ACol, int ARow, bool &CanSelect)
{
	rowselect_fechamentos_detalhada = ARow;
	GerarGridFechamentosParcelas();
	GerarGridFechamentosPedidos();
}
//---------------------------------------------------------------------------
void TFContasReceber::GerarGridFechamentosPedidos()
{
	UnicodeString QUERY,MODO;
	int numerodalinha,i,j,cc,rc;

	rc = GridFechamentosPedidos->RowCount;
	cc = GridFechamentosPedidos->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
			GridFechamentosPedidos->Cells[j][i] = "";

	LimparCheck();
	numerodalinha = 1;
	// ESTRUTURA
	GridFechamentosPedidos->Options << goRowSelect;
	GridFechamentosPedidos->ScrollBars = ssVertical;
	GridFechamentosPedidos->Rows[1]->Clear();
	GridFechamentosPedidos->RowCount = 0;
	GridFechamentosPedidos->ColCount = 6;
	GridFechamentosPedidos->FixedCols = 0;
	GridFechamentosPedidos->ColWidths[0] = 50;
	GridFechamentosPedidos->ColWidths[1] = ((GridFechamentosPedidos->Width)/4) - 50;
	GridFechamentosPedidos->ColWidths[2] = ((GridFechamentosPedidos->Width)/4);
	GridFechamentosPedidos->ColWidths[3] = ((GridFechamentosPedidos->Width)/4);
	GridFechamentosPedidos->ColWidths[4] = ((GridFechamentosPedidos->Width)/4);
	GridFechamentosPedidos->Cols[0]->Add("");
	GridFechamentosPedidos->Cols[1]->Add("CÓDIGO");
	GridFechamentosPedidos->Cols[2]->Add("DATA");
	GridFechamentosPedidos->Cols[3]->Add("ATENDENTE");
	GridFechamentosPedidos->Cols[4]->Add("VALOR");
	// ESTRUTURA


	id_cliente = FStrToInt(GridPendentes->Cells[0][rowselect_pendentes]);

	if(RadioSimplesPendentes->Checked)
		QUERY = "SELECT V.id AS id,V.codigo_caixa AS codigo_caixa,V.codigo AS codigo,V.vendedor AS id_vendedor,V.atendente AS id_atendente,V.cliente AS id_cliente,V.modo_pagar AS modo_pagar,V.data AS data,V.valor AS valor,V.fechamento AS fechamento,C.id AS id_c,C.nome_fantasia AS cliente,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE (V.fechamento='"+GridFechamentosDetalhada->Cells[0][rowselect_fechamentos_detalhada]+"') ORDER BY V.codigo ASC";
	else
		QUERY = "SELECT V.id AS id,V.codigo_caixa AS codigo_caixa,V.codigo AS codigo,V.vendedor AS id_vendedor,V.atendente AS id_atendente,V.cliente AS id_cliente,V.modo_pagar AS modo_pagar,V.data AS data,V.valor AS valor,V.fechamento AS fechamento,C.id AS id_c,C.nome_fantasia AS cliente,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE (V.fechamento='"+GridFechamentosDetalhada->Cells[0][rowselect_fechamentos_detalhada]+"') ORDER BY V.codigo ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		GridFechamentosPedidos->Cells[1][numerodalinha] = SQLQuery1->Fields->FieldByName("codigo")->AsString;
		GridFechamentosPedidos->Cells[2][numerodalinha] = SQLQuery1->Fields->FieldByName("data")->AsString;
		GridFechamentosPedidos->Cells[3][numerodalinha] = SQLQuery1->Fields->FieldByName("atendente")->AsString;
		GridFechamentosPedidos->Cells[4][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("valor")->AsFloat);
		GridFechamentosPedidos->RowCount++;
		SQLQuery1->Next();
		numerodalinha++;
	}
}

void __fastcall TFContasReceber::GridFechamentosPedidosMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int i,c,all_select;

	if(rowselect_fechamentos_pedidos>0)
	{
		LinhasSelecionadasMovel = (Check *) malloc(sizeof(Check));

		LinhasSelecionadasMovel->linha = rowselect_fechamentos_pedidos;
		LinhasSelecionadasMovel->codigo = FStrToInt(GridFechamentosPedidos->Cells[1][rowselect_fechamentos_pedidos]);
		LinhasSelecionadasMovel->data = GridFechamentosPedidos->Cells[2][rowselect_fechamentos_pedidos];
		LinhasSelecionadasMovel->cliente = FStrToInt(GridFechamentosPedidos->Cells[1][rowselect_fechamentos_pedidos]);
		LinhasSelecionadasMovel->vendedor = FStrToInt(GridFechamentosPedidos->Cells[1][rowselect_fechamentos_pedidos]);;
		LinhasSelecionadasMovel->atendente = FStrToInt(GridFechamentosPedidos->Cells[1][rowselect_fechamentos_pedidos]);
		LinhasSelecionadasMovel->valor = FStrToFloat(GridFechamentosPedidos->Cells[4][rowselect_fechamentos_pedidos]);

		if(!ProucurarLinha(rowselect_fechamentos_pedidos))
			MarcarCheck(LinhasSelecionadasMovel);
		else
			DesmarcarCheck(LinhasSelecionadasMovel->linha);

		free(LinhasSelecionadasMovel);
	}
	else
	{
		 all_select = 1;
		 c = GridFechamentosPedidos->RowCount;
		 for(i=1;i<c;i++)
			if(!ProucurarLinha(i))
			{
				all_select = 0;
				break;
			}

		if(!all_select)
		{
			for(i=1;i<c;i++)
            {
				LinhasSelecionadasMovel = (Check *) malloc(sizeof(Check));

				LinhasSelecionadasMovel->linha = i;
				LinhasSelecionadasMovel->codigo = FStrToInt(GridFechamentosPedidos->Cells[1][i]);
				LinhasSelecionadasMovel->data = GridFechamentosPedidos->Cells[2][i];
				LinhasSelecionadasMovel->cliente = FStrToInt(GridFechamentosPedidos->Cells[1][i]);
				LinhasSelecionadasMovel->vendedor = FStrToInt(GridFechamentosPedidos->Cells[1][i]);;
				LinhasSelecionadasMovel->atendente = FStrToInt(GridFechamentosPedidos->Cells[1][i]);
				LinhasSelecionadasMovel->valor = FStrToFloat(GridFechamentosPedidos->Cells[4][i]);

				if(!ProucurarLinha(i))
					MarcarCheck(LinhasSelecionadasMovel);

				free(LinhasSelecionadasMovel);
			}
		}
		else
		{
			for(i=1;i<c;i++)
            {
				if(ProucurarLinha(i))
					DesmarcarCheck(i);
			}
		}
	}
	GridFechamentosPedidos->Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TFContasReceber::GridFechamentosPedidosSelectCell(TObject *Sender,
          int ACol, int ARow, bool &CanSelect)
{
	rowselect_fechamentos_pedidos = ARow;
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::PageControlPrincipalChange(TObject *Sender)
{
	if(PageControlPrincipal->ActivePage == TabPendentes)
	{
		rowselect_pendentes = 1;

		LimparCheck();
		DesignerPendentes();
		GerarGridPendentes();
		GerarGridPendentesDetalhada();
	}
	else if(PageControlPrincipal->ActivePage == TabFechamentos)
	{
		rowselect_fechamentos = 1;
		rowselect_fechamentos_detalhada = 1;
		PageControlFechamentos->TabIndex = 0;

		LimparCheck();
		DesignerFechamentos();
		GerarGridFechamentos();
		GerarGridFechamentosDetalhada();
		GerarGridFechamentosParcelas();
		GerarGridFechamentosPedidos();
	}
	else if(PageControlPrincipal->ActivePage == TabArquivados)
	{
		rowselect_arquivados = 1;

		LimparCheck();
		DesignerArquivados();
		GerarGridArquivados();
		GerarGridArquivadosDetalhada();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::Button10Click(TObject *Sender)
{
	ExportarNFe();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::Button9Click(TObject *Sender)
{
	int codigo;

	if(MessageBox(NULL,L"Deseja arquivar os pedidos selecionados?",L"Arquivar Pedidos",MB_YESNO | MB_ICONWARNING) == 6)
	{
		codigo = FStrToInt(GridFechamentosDetalhada->Cells[0][rowselect_fechamentos_detalhada]);

		if(Arquivar())
		{
			DeletarFechamento(codigo);
			RemoverMIPGestao(codigo);
			LimparCheck();

			GerarGridFechamentosDetalhada();
			GerarGridFechamentosParcelas();
			GerarGridFechamentosPedidos();
		}
	}
}
//---------------------------------------------------------------------------
void TFContasReceber::DeletarFechamento(int codigo_fechamento)
{
	CarregarMIPGestao();
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add("DELETE FROM fechamentos WHERE codigo = '" + IntToStr(codigo_fechamento) + "'");
	SQLQuery1->ExecSQL();
}
//---------------------------------------------------------------------------
void TFContasReceber::RemoverMIPGestao(int codigo_fechamento)
{
	if(ConectarMIPGestao())
	{
		SQLQuery2->SQLConnection = SQLConnection1;
		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add("DELETE FROM notas_saida WHERE (nnf = '" + IntToStr(codigo_fechamento) + "' AND fornecedor='"+CharToStr(MIPGestao.fornecedor)+"' AND centro_custo='"+IntToStr(MIPGestao.centro)+"' AND conta_contabil='"+IntToStr(MIPGestao.conta)+"' AND projeto='"+IntToStr(MIPGestao.projeto)+"')");
		SQLQuery2->ExecSQL();

		if(SQLConnection1->Connected == TRUE)
		{
			SQLConnection1->Close();
			SQLConnection1->Connected = FALSE;
		}
	}
}
void TFContasReceber::AtualizarMIPGestao(int codigo_fechamento,int prestacao)
{
	UnicodeString QUERY,MODO,DESCRICAO;
	TDate data;

	data = Now();
	if(ConectarMIPGestao())
	{
		SQLQuery2->SQLConnection = SQLConnection1;

		//VERIFICA SE EXISTE
		QUERY = "SELECT * FROM notas_saida WHERE (nnf = '" + IntToStr(codigo_fechamento) + "' AND fornecedor='"+CharToStr(MIPGestao.fornecedor)+"' AND centro_custo='"+IntToStr(MIPGestao.centro)+"' AND conta_contabil='"+IntToStr(MIPGestao.conta)+"' AND projeto='"+IntToStr(MIPGestao.projeto)+"' AND medicao='"+IntToStr(prestacao)+"') ORDER BY id DESC LIMIT 1";
		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->Open();
		SQLQuery2->First();
		if(SQLQuery2->Fields->FieldByName("id")->AsInteger)
		{
			SQLQuery2->SQL->Clear();
			SQLQuery2->SQL->Add("UPDATE notas_saida SET consolidado='1',usuario_consolida='"+CharToStr(MIPGestao.usuario)+"' WHERE (nnf = '" + IntToStr(codigo_fechamento) + "' AND fornecedor='"+CharToStr(MIPGestao.fornecedor)+"' AND centro_custo='"+IntToStr(MIPGestao.centro)+"' AND conta_contabil='"+IntToStr(MIPGestao.conta)+"' AND projeto='"+IntToStr(MIPGestao.projeto)+"' AND medicao='"+IntToStr(prestacao)+"')");
			SQLQuery2->ExecSQL();
		}
		else
		{
			MODO = GridFechamentosParcelas->Cells[1][rowselect_fechamentos_parcelas];

			DESCRICAO = "FECHAMENTO DE CONTA - "+data.DateString()+"\r\n";
			DESCRICAO += "-------------------------------------------------\r\n";
			DESCRICAO += "CODIGO DO FECHAMENTO - "+IntToStr(codigo_fechamento)+"\r\n";
			DESCRICAO += "-------------------------------------------------\r\n";
			DESCRICAO += "CLIENTE - "+CLIENTE_SELECIONADO+"\r\n";
			DESCRICAO += "-------------------------------------------------\r\n";
			DESCRICAO += "PARCELA - 1/1\r\n";
			DESCRICAO += "-------------------------------------------------\r\n";
			DESCRICAO += "VALOR DA PARCELA - "+GridFechamentosParcelas->Cells[3][rowselect_fechamentos_parcelas]+"\r\n";
			DESCRICAO += "-------------------------------------------------\r\n";
			DESCRICAO += "MODO DE PAGAR - "+MODO+"\r\n";

			QUERY = "INSERT INTO notas_saida (fornecedor,cnpj,data_pagamento,data_emissao,data_lancamento,nnf,valor,vnf,icms,ipi,confins,pis,iss,descricao,conta_contabil,projeto,centro_custo,medicao,tipo_nf,usuario_lancamento,usuario_consolida,consolidado)";

			QUERY += " VALUES ('";
			QUERY += CharToStr(MIPGestao.fornecedor)+"','";
			QUERY += CharToStr(MIPGestao.fornecedor_cnpj)+"','";
			QUERY += RevertOrd(GridFechamentosDetalhada->Cells[2][rowselect_fechamentos_detalhada])+"','";
			QUERY += RevertOrd(GridFechamentosDetalhada->Cells[3][rowselect_fechamentos_detalhada])+"','";
			QUERY += RevertOrd(data.DateString())+"','";
			QUERY += IntToStr(codigo_fechamento)+"','";
			QUERY += FormatFloat("#########0.00",FStrToFloat(GridFechamentosParcelas->Cells[3][rowselect_fechamentos_parcelas]))+"','";
			QUERY += FormatFloat("#########0.00",FStrToFloat(GridFechamentosParcelas->Cells[3][rowselect_fechamentos_parcelas]))+"','";
			QUERY += "','";
			QUERY += "','";
			QUERY += "','";
			QUERY += "','";
			QUERY += "','";
			QUERY += DESCRICAO+"','";
			QUERY += IntToStr(MIPGestao.conta)+"','";
			QUERY += IntToStr(MIPGestao.projeto)+"','";
			QUERY += IntToStr(MIPGestao.centro)+"','";
			QUERY += "1','";
			QUERY += "0','";
			QUERY += CharToStr(MIPGestao.usuario)+"','";
			QUERY += CharToStr(MIPGestao.usuario)+"','";
			QUERY += "1')";

			SQLQuery2->SQL->Clear();
			SQLQuery2->SQL->Add(QUERY);
			SQLQuery2->ExecSQL();
		}

		if(SQLConnection1->Connected == TRUE)
		{
			SQLConnection1->Close();
			SQLConnection1->Connected = FALSE;
		}
	}
}

void __fastcall TFContasReceber::Button6Click(TObject *Sender)
{
	int codigo,prestacao;
	UnicodeString TEXTO;

	TEXTO = "Tem certeza que deseja finalizar a prestação "+GridFechamentosParcelas->Cells[0][rowselect_fechamentos_parcelas]+" - "+GridFechamentosParcelas->Cells[1][rowselect_fechamentos_parcelas];
	if(MessageBox(NULL,TEXTO.c_str(),L"Finalizar fechamento",MB_YESNO | MB_ICONWARNING) == 6)
	{
		if(rowselect_fechamentos_detalhada>0 && GridFechamentosDetalhada->Cells[0][rowselect_fechamentos_detalhada].Trim()!="")
		{
			codigo = FStrToInt(GridFechamentosDetalhada->Cells[0][rowselect_fechamentos_detalhada]);
			prestacao = FStrToInt(GridFechamentosParcelas->Cells[0][rowselect_fechamentos_parcelas]);

			FinalizarFechamento(codigo,prestacao);
			AtualizarMIPGestao(codigo,prestacao);

			rowselect_fechamentos_detalhada = 1;
			GerarGridFechamentosDetalhada();
			GerarGridFechamentosParcelas();
			GerarGridFechamentosPedidos();

			MessageBox(NULL,L"Fechamento finalizado com sucesso!",L"Finalizar fechamento",MB_OK | MB_ICONINFORMATION);
		}
		else
			MessageBox(NULL,L"Selecione um fechamento válido!",L"Finalizar fechamento",MB_OK | MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::GridFechamentosParcelasSelectCell(TObject *Sender,
          int ACol, int ARow, bool &CanSelect)
{
	rowselect_fechamentos_parcelas = ARow;
}
//---------------------------------------------------------------------------
void TFContasReceber::FinalizarFechamento(int codigo_fechamento,int prestacao)
{
	UnicodeString QUERY;

	QUERY = "UPDATE fechamentos SET ";
	QUERY += "situacao = '1',usuario_pagamento='"+IntToStr(USUARIO)+"',valor_pago = valor";
	QUERY += " WHERE (codigo='"+IntToStr(codigo_fechamento)+"' AND prestacao='"+IntToStr(prestacao)+"')";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->ExecSQL();

	AtualizarGastoCliente();

}
//------------------------------------------------------------------------------------------------
void TFContasReceber::AtualizarGastoCliente()
{
	UnicodeString QUERY;
	float limite,gasto,valor_carteira;
	int situacao = 0;

	valor_carteira = FStrToFloat(GridFechamentosParcelas->Cells[3][rowselect_fechamentos_parcelas]);
	//VERIFICA SE O CLIENTE ESTÁ LIBERADO
	QUERY = "SELECT id,cliente,limite,gasto,situacao FROM clientes_financeiro WHERE cliente='"+CLIENTE_ID_SELECIONADO+"' ORDER BY id ASC LIMIT 1";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger != 0)
	{
		limite = SQLQuery1->Fields->FieldByName("limite")->AsFloat;
		gasto = SQLQuery1->Fields->FieldByName("gasto")->AsFloat;
		gasto = gasto - valor_carteira;

		if(gasto < limite)
			situacao = 1;
	}

	//ATUALIZA O GASTO NO CASA DE CARTEIRA
	QUERY = "UPDATE clientes_financeiro SET gasto = gasto - '"+FloatToStr(valor_carteira)+"',situacao='"+IntToStr(situacao)+"' WHERE cliente='"+CLIENTE_ID_SELECIONADO+"'";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->ExecSQL();
}
void __fastcall TFContasReceber::GridArquivadosSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselect_arquivados = ARow;
	CLIENTE_SELECIONADO = GridPendentes->Cells[1][rowselect_pendentes];
	CLIENTE_ID_SELECIONADO = GridPendentes->Cells[0][rowselect_pendentes];

	GerarGridArquivadosDetalhada();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::GridArquivadosDetalhadaSelectCell(TObject *Sender,
          int ACol, int ARow, bool &CanSelect)
{
	rowselect_arquivados_detalhada = ARow;
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::Button1Click(TObject *Sender)
{
	GerarGridArquivados();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::GridArquivadosDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	UnicodeString Texto;
	TDate data;
	int atrasado = 0;

	if(ARow>0)
	{
		Texto = GridArquivados->Cells[ACol][ARow];
		data = GridArquivados->Cells[2][ARow];

		//VERIFICA SE O PRAZO NAO ESTOROU
		if(data + dias_notificao < Now())
			atrasado = 1;

		GridArquivados->Canvas->Font->Color=clBlack;

		if(atrasado)
			GridArquivados->Canvas->Font->Color = clRed;

		if(ARow%2!=0)
			GridArquivados->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridArquivados->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridArquivados->Canvas->Brush->Color=TColor(0xc9a78b);

			if(atrasado)
				GridArquivados->Canvas->Brush->Color=TColor(0x9696EF);

			GridArquivados->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridArquivados->Canvas->FillRect(Rect);
		GridArquivados->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridArquivados->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);
	}
}
//---------------------------------------------------------------------------
void TFContasReceber::GerarGridArquivados()
{
	UnicodeString QUERY;
	int numerodalinha,i,j,cc,rc;

	rc = GridArquivados->RowCount;
	cc = GridArquivados->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
			GridArquivados->Cells[j][i] = "";

	numerodalinha = 1;
	// ESTRUTURA
	GridArquivados->Options << goRowSelect;
	GridArquivados->ScrollBars = ssVertical;
	GridArquivados->Rows[1]->Clear();
	GridArquivados->RowCount = 0;
	GridArquivados->ColCount = 4;
	GridArquivados->FixedCols = 0;
	GridArquivados->ColWidths[0] = 0;
	GridArquivados->ColWidths[1] = ((GridArquivados->Width)/3)+200;
	GridArquivados->ColWidths[2] = ((GridArquivados->Width)/3)-100;
	GridArquivados->ColWidths[3] = ((GridArquivados->Width)/3)-100;
	GridArquivados->Cols[0]->Add("CLIENTE ID");
	GridArquivados->Cols[1]->Add("CLIENTE");
	GridArquivados->Cols[2]->Add("DATA ANTIGA");
	GridArquivados->Cols[3]->Add("VALOR");
	// ESTRUTURA

	if(RadioSimplesPendentes->Checked)
		QUERY = "SELECT V.id AS id,V.cliente AS cliente_id,sum(V.valor) AS valor,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,MIN(V.data) AS data,C.id AS id_c,C.nome_fantasia AS cliente,CF.consumidor AS consumidor FROM vendas AS V INNER JOIN clientes AS C ON(V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (CF.cliente = C.id) WHERE (V.modo_pagar='3' AND V.fechamento = '1' AND C.nome_fantasia LIKE '%"+EditBuscaArquivados->Text+"%' AND CF.consumidor='1') GROUP BY V.cliente ORDER BY C.nome_fantasia ASC";
	else
		QUERY = "SELECT V.id AS id,V.cliente AS cliente_id,sum(V.valor) AS valor,V.modo_pagar AS modo_pagar,V.fechamento AS fechamento,MIN(V.data) AS data,C.id AS id_c,C.nome_fantasia AS cliente,CF.consumidor AS consumidor FROM vendas AS V INNER JOIN clientes AS C ON(V.cliente = C.id) INNER JOIN clientes_financeiro AS CF ON (CF.cliente = C.id) WHERE (V.modo_pagar='3' AND V.fechamento = '1' AND C.nome_fantasia LIKE '%"+EditBuscaArquivados->Text+"%' AND CF.consumidor='1') GROUP BY V.cliente ORDER BY C.nome_fantasia ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		GridArquivados->Cells[0][numerodalinha] = SQLQuery1->Fields->FieldByName("cliente_id")->AsString;
		GridArquivados->Cells[1][numerodalinha] = SQLQuery1->Fields->FieldByName("cliente")->AsString;
		GridArquivados->Cells[2][numerodalinha] = SQLQuery1->Fields->FieldByName("data")->AsString;
		GridArquivados->Cells[3][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("valor")->AsFloat);

		GridArquivados->RowCount++;
		SQLQuery1->Next();
		numerodalinha++;
		if (numerodalinha == 2)
			GridArquivados->FixedRows = 1;
	}
	LimparCheck();
}
//---------------------------------------------------------------------------
void TFContasReceber::GerarGridArquivadosDetalhada()
{
	UnicodeString QUERY,MODO;
	int numerodalinha,i,j,cc,rc;

	rc = GridArquivadosDetalhada->RowCount;
	cc = GridArquivadosDetalhada->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
			GridArquivadosDetalhada->Cells[j][i] = "";

	LimparCheck();
	numerodalinha = 1;
	// ESTRUTURA
	GridArquivadosDetalhada->Options << goRowSelect;
	GridArquivadosDetalhada->ScrollBars = ssVertical;
	GridArquivadosDetalhada->Rows[1]->Clear();
	GridArquivadosDetalhada->RowCount = 0;
	GridArquivadosDetalhada->ColCount = 6;
	GridArquivadosDetalhada->FixedCols = 0;
	GridArquivadosDetalhada->ColWidths[0] = 50;
	GridArquivadosDetalhada->ColWidths[1] = ((GridArquivadosDetalhada->Width)/4) - 50;
	GridArquivadosDetalhada->ColWidths[2] = ((GridArquivadosDetalhada->Width)/4);
	GridArquivadosDetalhada->ColWidths[3] = ((GridArquivadosDetalhada->Width)/4);
	GridArquivadosDetalhada->ColWidths[4] = ((GridArquivadosDetalhada->Width)/4);
	GridArquivadosDetalhada->Cols[0]->Add("");
	GridArquivadosDetalhada->Cols[1]->Add("CÓDIGO");
	GridArquivadosDetalhada->Cols[2]->Add("DATA");
	GridArquivadosDetalhada->Cols[3]->Add("ATENDENTE");
	GridArquivadosDetalhada->Cols[4]->Add("VALOR");
	// ESTRUTURA


	id_cliente = FStrToInt(GridArquivados->Cells[0][rowselect_arquivados]);

	if(RadioSimplesPendentes->Checked)
		QUERY = "SELECT V.id AS id,V.codigo_caixa AS codigo_caixa,V.codigo AS codigo,V.vendedor AS id_vendedor,V.atendente AS id_atendente,V.cliente AS id_cliente,V.modo_pagar AS modo_pagar,V.data AS data,V.valor AS valor,V.fechamento AS fechamento,C.id AS id_c,C.nome_fantasia AS cliente,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE (V.cliente = '"+GridArquivados->Cells[0][rowselect_arquivados]+"' AND V.fechamento='1' AND V.modo_pagar='3') ORDER BY V.codigo ASC";
	else
		QUERY = "SELECT V.id AS id,V.codigo_caixa AS codigo_caixa,V.codigo AS codigo,V.vendedor AS id_vendedor,V.atendente AS id_atendente,V.cliente AS id_cliente,V.modo_pagar AS modo_pagar,V.data AS data,V.valor AS valor,V.fechamento AS fechamento,C.id AS id_c,C.nome_fantasia AS cliente,U.id AS id_u,U.nome AS atendente FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN usuarios AS U ON (V.atendente = U.id) WHERE (V.cliente = '"+GridArquivados->Cells[0][rowselect_arquivados]+"' AND V.fechamento='1' AND V.modo_pagar='3') ORDER BY V.codigo ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		GridArquivadosDetalhada->Cells[1][numerodalinha] = SQLQuery1->Fields->FieldByName("codigo")->AsString;
		GridArquivadosDetalhada->Cells[2][numerodalinha] = SQLQuery1->Fields->FieldByName("data")->AsString;
		GridArquivadosDetalhada->Cells[3][numerodalinha] = SQLQuery1->Fields->FieldByName("atendente")->AsString;
		GridArquivadosDetalhada->Cells[4][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("valor")->AsFloat);
		GridArquivadosDetalhada->RowCount++;
		SQLQuery1->Next();
		numerodalinha++;
	}

	TotalArquivados();
}

void __fastcall TFContasReceber::Button13Click(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja desarquivar os pedidos?",L"Desarquivar pedidos",MB_YESNO | MB_ICONWARNING) == 6)
	{
		Desarquivar();
		GerarGridArquivadosDetalhada();
		LimparCheck();
	}
}
//---------------------------------------------------------------------------

int TFContasReceber::Desarquivar()
{
	UnicodeString QUERY;
	int iR = 0;

	if(LinhasSelecionadasNo)
	{
		LinhasSelecionadasMovel = LinhasSelecionadasNo;

		while(LinhasSelecionadasMovel)
		{
			QUERY = "UPDATE vendas SET ";
			QUERY += "fechamento='0'";
			QUERY += " WHERE codigo='"+IntToStr(LinhasSelecionadasMovel->codigo)+"'";

			SQLQuery1->SQL->Clear();
			SQLQuery1->SQL->Add(QUERY);
			SQLQuery1->ExecSQL();
			LinhasSelecionadasMovel = LinhasSelecionadasMovel->proximo;
		}
		iR = 1;
		MessageBox(NULL,L"Pedidos desarquivados com sucesso!",L"Desarquivar Pedido",MB_OK | MB_ICONINFORMATION);
	}
	else
		MessageBox(NULL,L"Descuple, nenhum pedido selecionado!",L"Desarquivar Pedido",MB_OK | MB_ICONERROR);
	return iR;
}


void __fastcall TFContasReceber::GridArquivadosDetalhadaMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int i,c,all_select;

	if(rowselect_arquivados_detalhada>0)
	{
		LinhasSelecionadasMovel = (Check *) malloc(sizeof(Check));

		LinhasSelecionadasMovel->linha = rowselect_arquivados_detalhada;
		LinhasSelecionadasMovel->codigo = FStrToInt(GridArquivadosDetalhada->Cells[1][rowselect_arquivados_detalhada]);
		LinhasSelecionadasMovel->data = GridArquivadosDetalhada->Cells[2][rowselect_arquivados_detalhada];
		LinhasSelecionadasMovel->cliente = FStrToInt(GridArquivadosDetalhada->Cells[1][rowselect_arquivados_detalhada]);
		LinhasSelecionadasMovel->vendedor = FStrToInt(GridArquivadosDetalhada->Cells[1][rowselect_arquivados_detalhada]);;
		LinhasSelecionadasMovel->atendente = FStrToInt(GridArquivadosDetalhada->Cells[1][rowselect_arquivados_detalhada]);
		LinhasSelecionadasMovel->valor = FStrToFloat(GridArquivadosDetalhada->Cells[4][rowselect_arquivados_detalhada]);

		if(!ProucurarLinha(rowselect_arquivados_detalhada))
			MarcarCheck(LinhasSelecionadasMovel);
		else
			DesmarcarCheck(LinhasSelecionadasMovel->linha);

		free(LinhasSelecionadasMovel);
	}
	else
	{
		 all_select = 1;
		 c = GridArquivadosDetalhada->RowCount;
		 for(i=1;i<c;i++)
			if(!ProucurarLinha(i))
			{
				all_select = 0;
				break;
			}

		if(!all_select)
		{
			for(i=1;i<c;i++)
            {
				LinhasSelecionadasMovel = (Check *) malloc(sizeof(Check));

				LinhasSelecionadasMovel->linha = i;
				LinhasSelecionadasMovel->codigo = FStrToInt(GridArquivadosDetalhada->Cells[1][i]);
				LinhasSelecionadasMovel->data = GridArquivadosDetalhada->Cells[2][i];
				LinhasSelecionadasMovel->cliente = FStrToInt(GridArquivadosDetalhada->Cells[1][i]);
				LinhasSelecionadasMovel->vendedor = FStrToInt(GridArquivadosDetalhada->Cells[1][i]);;
				LinhasSelecionadasMovel->atendente = FStrToInt(GridArquivadosDetalhada->Cells[1][i]);
				LinhasSelecionadasMovel->valor = FStrToFloat(GridArquivadosDetalhada->Cells[4][i]);

				if(!ProucurarLinha(i))
					MarcarCheck(LinhasSelecionadasMovel);

				free(LinhasSelecionadasMovel);
			}
		}
		else
		{
			for(i=1;i<c;i++)
            {
				if(ProucurarLinha(i))
					DesmarcarCheck(i);
			}
		}
	}
	GridArquivadosDetalhada->Repaint();
	TotalArquivados();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::GridArquivadosDetalhadaDrawCell(TObject *Sender,
          int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
	UnicodeString Texto;
	tagRECT *rc;
    int i,c,all_select;

	rc = (tagRECT *) malloc(sizeof(tagRECT));
	rc->left = Rect.Left;
	rc->top = Rect.top;
	rc->right = Rect.Right;
	rc->bottom = Rect.Bottom;
	/*--------------------COLOCAR CHECKBOX----------------------------*/
	if (ARow>0)
	{
		Texto = GridArquivadosDetalhada->Cells[ACol][ARow];

		GridArquivadosDetalhada->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			GridArquivadosDetalhada->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridArquivadosDetalhada->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridArquivadosDetalhada->Canvas->Brush->Color=TColor(0xc9a78b);
			GridArquivadosDetalhada->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridArquivadosDetalhada->Canvas->FillRect(Rect);
		GridArquivadosDetalhada->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridArquivadosDetalhada->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);
	}

	if(ACol == 0)
	{
		 all_select = 1;
		 c = GridArquivadosDetalhada->RowCount;
		 for(i=1;i<c;i++)
			if(!ProucurarLinha(i))
			{
				all_select = 0;
				break;
			}

		if (ProucurarLinha(ARow) || all_select)
			DrawFrameControl(GridArquivadosDetalhada->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
		else
			DrawFrameControl(GridArquivadosDetalhada->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK);
	}
}
//---------------------------------------------------------------------------

void TFContasReceber::ImprimirOrcamento()
{
}


void __fastcall TFContasReceber::Button2Click(TObject *Sender)
{
	ImprimirOrcamento();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::Button8Click(TObject *Sender)
{
	ImprimirOrcamento();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceber::Button7Click(TObject *Sender)
{
	ImprimirOrcamento();
}
//---------------------------------------------------------------------------
void TFContasReceber::loadCabecalho()
{
//    EmpresaModel *empresa_model = new EmpresaModel();
//	EmpresaEspelho *empresa = empresa_model->selectAll();
//
//	InfoGeraisModel *info_gerais_model = new InfoGeraisModel();
//	InfoGeraisEspelho *info_gerais = info_gerais_model->selectAll();
//
//	LabelCabecalhoEmpresaPendentes->Caption =  "[CONTAS À RECEBER - PENDENTES] " + empresa->getNomeFantasia();
//	LabelCabecalhoEmpresaFechamentos->Caption =  "[CONTAS À RECEBER - FECHAMENTOS] " + empresa->getNomeFantasia();
//	LabelCabecalhoEmpresaArquivados->Caption =  "[CONTAS À RECEBER - ARQUIVADOS] " + empresa->getNomeFantasia();
//
//	LabelCabecalhoAppPendentes->Caption =  ToUpper(info_gerais->getSoftwareName());
//	LabelCabecalhoAppFechamentos->Caption = ToUpper(info_gerais->getSoftwareName());
//	LabelCabecalhoAppArquivados->Caption =  ToUpper(info_gerais->getSoftwareName());
}

