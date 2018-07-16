//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Vendas.h"
#include "Principal.h"
#include "PedidosView.h"
#include "VendasRecebimento.h"
#include "VendasCpf.h"
#include "Bemafi32.h"
#include "LiberarAcesso.h"
#include "ConfigPdvEspelho.h"
#include "ConfigPdvModel.h"
#include "autoload.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFVendas *FVendas;
//---------------------------------------------------------------------------
__fastcall TFVendas::TFVendas(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFVendas::Designer()
{
	PanelFinalizar->Left = 25;
	PanelFinalizar->Width = PanelFixo->Width - 50;
	PanelFinalizar->Top = PanelFixo->Height - PanelFinalizar->Height - 25;

	PanelProdutos->Left = 25;
	PanelProdutos->Width = PanelFixo->Width - 50;
	PanelProdutos->Top = 25;
	PanelProdutos->Height = PanelFixo->Height - PanelFinalizar->Height - 75;

	PanelDesconto->Left = 25;
	PanelDesconto->Width = PanelVariavel->Width - 50;
	PanelDesconto->Top = PanelVariavel->Height - PanelDesconto->Height - 25;

	PanelPagamento->Left = 25;
	PanelPagamento->Width = PanelVariavel->Width - 50;
	PanelPagamento->Top = 25;
	PanelPagamento->Height = PanelVariavel->Height - PanelDesconto->Height - 75;
}
void __fastcall TFVendas::FormShow(TObject *Sender)
{
	loadCabecalho();
	Designer();
	InicializarCampos();
	AbrirCOM();
}
//---------------------------------------------------------------------------
void TFVendas::FecharCOM()
{
	int r;

	//FECHA PORTA IMPRESSORA FISCAL
	if(VerificarFiscal() == 1)
	{
		r = Bematech_FI_FechaPortaSerial();
		if(r!=1)
			MessageBox(NULL,L"Erro ao Fechar COM Impressora Fiscal",L"COM Impressora", MB_OK | MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------
void TFVendas::AbrirCOM()
{
	int r;

	//ABRE PORTA IMPRESSORA FISCAL
	if(VerificarFiscal() == 1)
	{
		r=Bematech_FI_AbrePortaSerial();
		if(r!=1)
			MessageBox(NULL,L"Erro ao abrir COM Impressora Fiscal",L"COM Impressora",MB_OK | MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFVendas::ButtonDinheiroClick(TObject *Sender)
{
	if(Orcamento.produtos)
	{
		FVendasRecebimento->modpagar = 0;
		FVendasRecebimento->ShowModal();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFVendas::FormResize(TObject *Sender)
{
	Designer();
}
//---------------------------------------------------------------------------
void __fastcall TFVendas::GridPagamentoDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
{
	UnicodeString Texto;
	if(ARow>0)
	{
		Texto = GridPagamento->Cells[ACol][ARow];

		GridPagamento->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			GridPagamento->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridPagamento->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridPagamento->Canvas->Brush->Color=TColor(0xc9a78b);
			GridPagamento->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridPagamento->Canvas->FillRect(Rect);
		GridPagamento->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridPagamento->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

	}
}
//---------------------------------------------------------------------------
void __fastcall TFVendas::GridProdutosDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
{
	UnicodeString Texto;

	Texto = GridProdutos->Cells[ACol][ARow];
	GridProdutos->Canvas->Font->Color=clBlack;

	GridProdutos->Canvas->Brush->Color = TColor(0xffffff);
	GridProdutos->Canvas->Pen->Color = TColor(0xffffff);

	//COLOCA O TEXTO
	GridProdutos->Canvas->FillRect(Rect);
	GridProdutos->Canvas->Rectangle(Rect.Left - 5, Rect.Top-5, Rect.Left+Rect.Width() , Rect.Top+Rect.Height() + 5);
	GridProdutos->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);
}
//---------------------------------------------------------------------------
void TFVendas::CarregarOrcamento()
{
	UnicodeString QUERY;
	int i;

	/*----------------------------CARREGAR ORÇAMENTO----------------------------------------------------*/
	QUERY = "SELECT id,codigo,data,hora,usuario,atendente,cliente,observacao,vendido FROM orcamentos WHERE ( codigo='"+IntToStr(Orcamento.codigo)+"' AND vendido='0') ORDER BY id DESC";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		Orcamento.id = SQLQuery1->Fields->FieldByName("id")->AsInteger;
		Orcamento.codigo = SQLQuery1->Fields->FieldByName("codigo")->AsInteger;
		Orcamento.data = SQLQuery1->Fields->FieldByName("data")->AsDateTime;
		Orcamento.hora = SQLQuery1->Fields->FieldByName("hora")->AsDateTime;
		Orcamento.usuario = SQLQuery1->Fields->FieldByName("usuario")->AsInteger;
		Orcamento.atendente = SQLQuery1->Fields->FieldByName("atendente")->AsInteger;
		Orcamento.cliente = SQLQuery1->Fields->FieldByName("cliente")->AsInteger;
		Orcamento.observacao = StrToChar(SQLQuery1->Fields->FieldByName("observacao")->AsString);
		Orcamento.vendido = SQLQuery1->Fields->FieldByName("vendido")->AsInteger;

		/*----------------------------CARREGAR CLIENTE----------------------------------------------------*/
		QUERY = "SELECT id,nome_fantasia FROM clientes WHERE id='"+IntToStr(Orcamento.cliente)+"' ORDER BY id ASC";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->Open();
		SQLQuery1->First();
		if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
			NOME_CLIENTE = SQLQuery1->Fields->FieldByName("nome_fantasia")->AsString;

		LabelCliente->Caption = "CLIENTE: " + NOME_CLIENTE.UpperCase();

		/*----------------------------CARREGAR PRODUTOS----------------------------------------------------*/
		TabelaProdutosMovel = (TabelaProdutos *) malloc(sizeof(TabelaProdutos));

		QUERY = "SELECT id,orcamento,id_produto,codbarras,descricao,preco,quantidade,unidade_medida,marca,ncm,cfop,desconto,promocao,devolucao FROM orcamentos_produtos WHERE orcamento='"+IntToStr(Orcamento.codigo)+"' ORDER BY id DESC";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->Open();
		SQLQuery1->First();
		while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
		{
			TabelaProdutosMovel->funcao = 0;
			TabelaProdutosMovel->id = SQLQuery1->Fields->FieldByName("id")->AsInteger;
			TabelaProdutosMovel->id_produto = SQLQuery1->Fields->FieldByName("id_produto")->AsInteger;
			TabelaProdutosMovel->codbarras = StrToChar(SQLQuery1->Fields->FieldByName("codbarras")->AsString);
			TabelaProdutosMovel->descricao = StrToChar(SQLQuery1->Fields->FieldByName("descricao")->AsString);
			TabelaProdutosMovel->preco = SQLQuery1->Fields->FieldByName("preco")->AsFloat;
			TabelaProdutosMovel->quantidade = SQLQuery1->Fields->FieldByName("quantidade")->AsFloat;
			TabelaProdutosMovel->unidade = StrToChar(SQLQuery1->Fields->FieldByName("unidade_medida")->AsString);
			TabelaProdutosMovel->marca = StrToChar(SQLQuery1->Fields->FieldByName("marca")->AsString);
			TabelaProdutosMovel->ncm = StrToChar(SQLQuery1->Fields->FieldByName("ncm")->AsString);
			TabelaProdutosMovel->cfop = StrToChar(SQLQuery1->Fields->FieldByName("cfop")->AsString);
			TabelaProdutosMovel->desconto = SQLQuery1->Fields->FieldByName("desconto")->AsFloat;
			TabelaProdutosMovel->promocao = SQLQuery1->Fields->FieldByName("promocao")->AsInteger;
			TabelaProdutosMovel->devolucao = SQLQuery1->Fields->FieldByName("devolucao")->AsInteger;

			AdicionarTabelaProdutos(TabelaProdutosMovel);
			SQLQuery1->Next();
		}

		if(TabelaProdutosMovel)
			free(TabelaProdutosMovel);
	}
	else
		MessageBox(NULL,L"Pedido inexistente ou código inválido!",L"Codigo inválido",MB_OK | MB_ICONERROR);
}
void __fastcall TFVendas::EditCodigoKeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key == 13)
	{
		LiberarMemoria();
		Orcamento.codigo = FStrToInt(EditCodigo->Text);
		CarregarOrcamento();
		GerarGridProdutos();
		if(Orcamento.produtos)
			FVendasCpf->ShowModal();
	}
}
//---------------------------------------------------------------------------
void TFVendas::AdicionarTabelaProdutos(TabelaProdutos *Proximo)
{
	TabelaProdutos *movel;

	ProucurarCodbarras(Proximo->codbarras,&movel);

	if(movel) //codigo de barras ja existe
	{
		movel->quantidade++;
		if(movel->funcao == 2)
		{
			movel->funcao = Proximo->funcao;
			movel->quantidade = Proximo->quantidade;
		}
	}
	else if(movel == NULL) //codbarras ainda nao existe
	{

		if(!Orcamento.produtos)
		{
			Orcamento.produtos = (TabelaProdutos*) malloc(sizeof(TabelaProdutos));

			Orcamento.produtos->funcao = Proximo->funcao;
			Orcamento.produtos->id = Proximo->id;
			Orcamento.produtos->id_produto = Proximo->id_produto;
			Orcamento.produtos->codbarras = Proximo->codbarras;
			Orcamento.produtos->descricao = Proximo->descricao;
			Orcamento.produtos->preco = Proximo->preco;
			Orcamento.produtos->quantidade = Proximo->quantidade;
			Orcamento.produtos->unidade = Proximo->unidade;
			Orcamento.produtos->marca = Proximo->marca;
			Orcamento.produtos->ncm = Proximo->ncm;
			Orcamento.produtos->cfop = Proximo->cfop;
			Orcamento.produtos->desconto = Proximo->desconto;
			Orcamento.produtos->promocao = Proximo->promocao;
			Orcamento.produtos->devolucao = Proximo->devolucao;
			Orcamento.produtos->proximo = NULL;
		}
		else
		{
			movel = Orcamento.produtos;
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
}
void __fastcall TFVendas::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);

	SQLQuery1->SQLConnection = SQLCONNECT;
}
//---------------------------------------------------------------------------
void TFVendas::ProucurarCodbarras(char *codbarras,TabelaProdutos **ponteiro)
{
	TabelaProdutos *movel;

	*ponteiro = NULL;
	if(Orcamento.produtos)
	{
		movel = Orcamento.produtos;
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
//---------------------------------------------------------------------------
void TFVendas::EstruturarGridProdutos()
{
	UnicodeString QUERY;
	int i,j,rc,cc;

	rc = GridProdutos->RowCount;
	cc = GridProdutos->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
		GridProdutos->Cells[j][i] = "";

	// ESTRUTURA GRID
	GridProdutos->Options << goRowSelect;
	GridProdutos->ScrollBars = ssVertical;
	GridProdutos->Rows[1]->Clear();
	GridProdutos->RowCount = 0;
	GridProdutos->ColCount = 1;
	GridProdutos->FixedCols = 0;
	GridProdutos->ColWidths[0] = GridProdutos->Width;
	// ESTRUTURA GRID
}
//---------------------------------------------------------------------------
void TFVendas::GerarGridProdutos()
{
	UnicodeString QUERY;
	int numerodalinha;
	float preco_total,preco_unitario;
	char LinhaProduto[200];
	char LinhaPreco[200];

	EstruturarGridProdutos();
	numerodalinha = 0;

	if(Orcamento.produtos)
	{
		TabelaProdutosMovel = Orcamento.produtos;
		while(TabelaProdutosMovel)
		{
			if(TabelaProdutosMovel->funcao!=2)
			{
				preco_unitario = TabelaProdutosMovel->preco*(1-TabelaProdutosMovel->desconto/100);
				preco_total = preco_unitario*TabelaProdutosMovel->quantidade;

				sprintf(LinhaProduto,"%s %20s",TabelaProdutosMovel->codbarras,TabelaProdutosMovel->descricao);
				sprintf(LinhaPreco,"%10.2f %5s x %10.2f  = %10.2f",TabelaProdutosMovel->quantidade,TabelaProdutosMovel->unidade,preco_unitario,preco_total);

				GridProdutos->Cells[0][numerodalinha++] = LinhaProduto;
				GridProdutos->RowCount++;

				GridProdutos->Cells[0][numerodalinha++] = LinhaPreco;
				GridProdutos->RowCount++;

			}
			TabelaProdutosMovel = TabelaProdutosMovel->proximo;
		}
	}
	Total();
}
//--------------------------------------------
void TFVendas::Total()
{
	TabelaProdutos *movel;
	float total,preco;

	total = 0;
	if(Orcamento.produtos)
	{
		movel = Orcamento.produtos;
		while(movel)
		{
			preco = movel->preco*(1-movel->desconto/100)*movel->quantidade;
			if(movel->devolucao)
			{
				preco = preco*-1;
				devolucao = 1;
			}
			if(movel->funcao != 2)
				total = total + preco;
			movel = movel->proximo;
		}
	}
	EditValorTotal->Text = FormatFloat("#,###,###,##0.00",total);
	EditValorRestante->Text = FormatFloat("#,###,###,##0.00",total);
	Desconto();
}
//--------------------------------------------
void TFVendas::Desconto()
{
	TabelaProdutos *movel;
	float total,total_desconto,preco,descontoP,descontoD;

	total = 0;
	total_desconto = 0;
	if(Orcamento.produtos)
	{
		movel = Orcamento.produtos;
		while(movel)
		{
			preco = movel->preco*movel->quantidade;
			if(movel->funcao != 2)
				total = total + preco;
			movel = movel->proximo;
		}

		movel = Orcamento.produtos;
		while(movel)
		{
			preco = movel->preco*(1-movel->desconto/100)*movel->quantidade;
			if(movel->funcao != 2)
				total_desconto = total_desconto + preco;
			movel = movel->proximo;
		}
		if(total!=0)
			descontoP = (1-total_desconto/total)*100;
		else
			descontoP = 0;

		descontoD = total-total_desconto;
	}
	EditDescontoP->Text = FormatFloat("#,###,###,##0.00",descontoP);
	EditDescontoD->Text = FormatFloat("#,###,###,##0.00",descontoD);
}

void __fastcall TFVendas::GridProdutosSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{
	int row;
	int i;
	int n;
	float preco;

	rowselect = ARow;
	row = rowselect;

	if(!(row%2))
		row++;

	n = (row-1)/2;

	preco = 1;
	if(Orcamento.produtos)
	{
		TabelaProdutosMovel = Orcamento.produtos;
		for(i=0;i<n;i++)
			if(TabelaProdutosMovel->proximo)
				TabelaProdutosMovel = TabelaProdutosMovel->proximo;
			else
			{
				preco = 0;
				break;
			}

		if(preco)
			preco = TabelaProdutosMovel->preco*(1-TabelaProdutosMovel->desconto/100);

	}
	LabelPrecoProduto->Caption = FormatFloat("#,###,###,##0.00",preco);
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::ButtonCartaoClick(TObject *Sender)
{
	if(Orcamento.produtos)
	{
		FVendasRecebimento->modpagar = 1;
		FVendasRecebimento->ShowModal();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::ButtonChequeClick(TObject *Sender)
{
	if(Orcamento.produtos)
	{
		FVendasRecebimento->modpagar = 2;
		FVendasRecebimento->ShowModal();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::ButtonCarteiraClick(TObject *Sender)
{
	if(Orcamento.produtos)
	{
		FVendasRecebimento->modpagar = 3;
		FVendasRecebimento->ShowModal();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::ButtonValeClick(TObject *Sender)
{
	if(Orcamento.produtos)
	{
		FVendasRecebimento->modpagar = 4;
		FVendasRecebimento->ShowModal();
	}
}
//---------------------------------------------------------------------------
void TFVendas::AdicionarPagamento(int modpagar,float valor)
{
	Pagamento *movel;
	if(!PagamentoNo)
	{
		PagamentoNo = (Pagamento*) malloc(sizeof(Pagamento));
		PagamentoNo->modpagar = modpagar;
		PagamentoNo->valor = valor;
		PagamentoNo->proximo = NULL;
	}
	else
	{
		movel = PagamentoNo;
		while(movel->proximo)
			movel = movel->proximo;

		movel->proximo = (Pagamento*) malloc(sizeof(Pagamento));

		movel->proximo->modpagar = modpagar;
		movel->proximo->valor = valor;
		movel->proximo->proximo = NULL;
	}
}
//---------------------------------------------------------------------------
void TFVendas::DeletarPagamento(int n)
{
  /*	Pagamento *atual,*anterior;

	if(PagamentoNo)
	{
		atual = PagamentoNo;

		//CASO INICIAL
		if(strcmp(atual->codbarras,codbarras) == 0)
		{
			PagamentoNo = PagamentoNo->proximo;
			free(atual);
			atual = NULL;
		}


		while(atual)
		{
			anterior = atual;
			atual = atual->proximo;

			if(strcmp(atual->codbarras,codbarras) == 0)
			{
				//CASO DO MEIO
				if(atual->proximo)
				{
					anterior->proximo = atual->proximo;
					free(atual);
					atual = NULL;
				}
				else
				{
					anterior->proximo = NULL;
					free(atual);
					atual = NULL;
				}

				break;
			}
		}
	}   */
}
//-------------------------------------------------------------------------
void TFVendas::GerarGridPagamentos()
{
	UnicodeString QUERY,MODO;
	int i,j,rc,cc;
	int numerodalinha;

	rc = GridPagamento->RowCount;
	cc = GridPagamento->ColCount;

	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
			GridPagamento->Cells[j][i] = "";

	// ESTRUTURA GRID
	GridPagamento->Options << goRowSelect;
	GridPagamento->ScrollBars = ssVertical;
	GridPagamento->Rows[1]->Clear();
	GridPagamento->RowCount = 0;
	GridPagamento->ColCount = 2;
	GridPagamento->FixedCols = 0;
	GridPagamento->ColWidths[0] = 100;
	GridPagamento->ColWidths[1] = GridPagamento->Width-100;
	GridPagamento->Cols[0]->Add("VALOR(R$)");
	GridPagamento->Cols[1]->Add("MODO DE PAGAR");
	// ESTRUTURA GRID

	numerodalinha = 1;

	if(PagamentoNo)
	{
		PagamentoMovel = PagamentoNo;
		while(PagamentoMovel)
		{
			switch(PagamentoMovel->modpagar)
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
			GridPagamento->Cells[0][numerodalinha] = FormatFloat("#,###,###,##0.00",PagamentoMovel->valor);
			GridPagamento->Cells[1][numerodalinha] = MODO;

			GridPagamento->RowCount++;
			numerodalinha++;
			if (numerodalinha == 2)
				GridPagamento->FixedRows = 1;
			PagamentoMovel = PagamentoMovel->proximo;
		}
	}
	GridPagamento->RowCount++;
	CalcularRestante();
}
//---------------------------------
void TFVendas::CalcularRestante()
{
	float total,total_pago,final;

	total = FStrToFloat(EditValorTotal->Text);

	total_pago = 0;
	if(PagamentoNo)
	{
		PagamentoMovel = PagamentoNo;
		while(PagamentoMovel)
		{
			total_pago = total_pago + PagamentoMovel->valor;
			PagamentoMovel = PagamentoMovel->proximo;
		}
	}

	final = total - total_pago;

	EditValorRestante->Text = FormatFloat("#,###,###,##0.00",final);

}
void __fastcall TFVendas::F1Execute(TObject *Sender)
{
	ButtonDinheiro->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::F2Execute(TObject *Sender)
{
	ButtonCartao->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::F3Execute(TObject *Sender)
{
	ButtonCheque->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::F4Execute(TObject *Sender)
{
	ButtonCarteira->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::F5Execute(TObject *Sender)
{
	ButtonVale->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::F6Execute(TObject *Sender)
{
	ButtonGaveta->Click();
}
//---------------------------------------------------------------------------
void TFVendas::LiberarMemoria()
{
	Pagamento *movel_pagamento;
	TabelaProdutos *movel_produtos;

	//LIBERAR MEMORIA PRODUTOS
	if(Orcamento.produtos)
	{
		TabelaProdutosMovel = Orcamento.produtos;
		while(TabelaProdutosMovel->proximo)
		{
			movel_produtos = TabelaProdutosMovel;
			TabelaProdutosMovel = TabelaProdutosMovel->proximo;
			free(movel_produtos);
			movel_produtos = NULL;
		}

		if(Orcamento.produtos)
		{
			free(Orcamento.produtos);
			Orcamento.produtos = NULL;
		}
	}
	//LIBERAR MEMORIA PAGAMENTOS
	if(PagamentoNo)
	{
		PagamentoMovel = PagamentoNo;
		while(PagamentoMovel->proximo)
		{
			movel_pagamento = PagamentoMovel;
			PagamentoMovel = PagamentoMovel->proximo;
			free(movel_pagamento);
			movel_pagamento = NULL;
		}

		if(PagamentoNo)
		{
			free(PagamentoNo);
			PagamentoNo = NULL;
		}
	}
}
//--------------------------------------------------------------------
void TFVendas::InicializarCampos()
{
	LiberarMemoria();

	devolucao = 0;
	impressora = VerificarFiscal();
	LabelCabecalhoTitulo->Font->Color = TColor(0x30CE95);
	EditCodigo->Clear();
	EditDescontoD->Clear();
	EditDescontoP->Clear();
	EditValorTotal->Clear();
	EditValorRestante->Clear();
	LabelPrecoProduto->Caption = FormatFloat("#,###,###,##0.00",0);
	LabelCliente->Caption = "CLIENTE:";
	CPF_CLIENTE = "";

	GerarGridProdutos();
	GerarGridPagamentos();

	EditCodigo->SetFocus();
}
//--------------------------------------------------------------------
void __fastcall TFVendas::FormClose(TObject *Sender, TCloseAction &Action)
{
	LiberarMemoria();
	FecharCOM();
}
//---------------------------------------------------------------------------
void TFVendas::ConcluirVenda()
{
	TDate data;
	UnicodeString QUERY;
	int carteira = 0;
	int liberado = 1;
	int vale = 0;
	int situacao;
    float limite,gasto;
	float valor_carteira = 0;
	unsigned short year,month,day;

	data = Now();
	data.DecodeDate(&year,&month,&day);

	//PROUCURAR CARTEIRA
	if(PagamentoNo)
	{
		PagamentoMovel = PagamentoNo;
		while(PagamentoMovel)
		{
			if(PagamentoMovel->modpagar == 3)
			{
				carteira = 1;
				valor_carteira = valor_carteira + PagamentoMovel->valor;
			}

			PagamentoMovel = PagamentoMovel->proximo;
		}

	}

	//PROUCURAR VALE
	if(PagamentoNo)
	{
		PagamentoMovel = PagamentoNo;
		while(PagamentoMovel)
		{
			if(PagamentoMovel->modpagar == 4)
			{
				vale = 1;
				break;
			}
			PagamentoMovel = PagamentoMovel->proximo;
		}
	}

	//VERIFICA SE O CLIENTE ESTÁ LIBERADO NO CASO DE CARTERA
	if(carteira)
	{
		QUERY = "SELECT id,cliente,limite,gasto,situacao FROM clientes_financeiro WHERE cliente='"+IntToStr(Orcamento.cliente)+"' ORDER BY id ASC LIMIT 1";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->Open();
		SQLQuery1->First();
		if(SQLQuery1->Fields->FieldByName("id")->AsInteger != 0)
		{
			situacao = SQLQuery1->Fields->FieldByName("situacao")->AsInteger;
			limite = SQLQuery1->Fields->FieldByName("limite")->AsFloat;
			gasto = SQLQuery1->Fields->FieldByName("gasto")->AsFloat;

			gasto = gasto + valor_carteira;

			if(gasto>limite || !situacao)
				liberado = 0;

		}
		else
			liberado = 0;
	}

	//REALIZA A VENDA CASO ESTEJA LIBERADO
	if(liberado)
	{
		//ATUALIZA O GASTO NO CASA DE CARTEIRA
		if(carteira)
		{
			if(gasto>=limite)
				situacao = 0;

			QUERY = "UPDATE clientes_financeiro SET gasto='"+FloatToStr(gasto)+"',situacao='"+IntToStr(situacao)+"' WHERE cliente='"+IntToStr(Orcamento.cliente)+"'";
			SQLQuery1->SQL->Clear();
			SQLQuery1->SQL->Add(QUERY);
			SQLQuery1->ExecSQL();
		}

		//ATUALIZA O ORÇAMENTO PARA VENDIDO
		QUERY = "UPDATE orcamentos SET vendido='1' WHERE codigo='"+IntToStr(Orcamento.codigo)+"'";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->ExecSQL();

		//ATUALIZA DESCONTO PRODUTOS ORÇAMENTO
		AtualizarOrcamento();

		//RETIRA DO ESTOQUE OS PRODUTOS
		if(Orcamento.produtos)
		{
			TabelaProdutosMovel = Orcamento.produtos;
			while(TabelaProdutosMovel)
			{
				QUERY = "UPDATE produtos SET quantidade = quantidade-"+FloatToStr(TabelaProdutosMovel->quantidade)+" WHERE codbarras='"+CharToStr(TabelaProdutosMovel->codbarras)+"'";
				SQLQuery1->SQL->Clear();
				SQLQuery1->SQL->Add(QUERY);
				SQLQuery1->ExecSQL();

				TabelaProdutosMovel = TabelaProdutosMovel->proximo;
			}
		}

		//INSERE A VENDA
		if(PagamentoNo)
		{
			PagamentoMovel = PagamentoNo;
			while(PagamentoMovel)
			{
				QUERY = "INSERT INTO vendas (codigo_caixa,codigo,fechamento,vendedor,atendente,cliente,modo_pagar,valor,data,mes,ano)";
				QUERY += " VALUES ('";
				QUERY += IntToStr(CODIGO_CAIXA)+"','";
				QUERY += IntToStr(Orcamento.codigo)+"','";
				QUERY += "0','";
				QUERY += IntToStr(USUARIO)+"','";
				QUERY += IntToStr(Orcamento.atendente)+"','";
				QUERY += IntToStr(Orcamento.cliente)+"','";
				QUERY += IntToStr(PagamentoMovel->modpagar)+"','";
				QUERY += FloatToStr(PagamentoMovel->valor)+"','";
				QUERY += RevertOrd(data.DateString())+"','";
				QUERY += IntToStr((int)month)+"','";
				QUERY += IntToStr((int)year)+"')";

				SQLQuery1->SQL->Clear();
				SQLQuery1->SQL->Add(QUERY);
				SQLQuery1->ExecSQL();

				PagamentoMovel = PagamentoMovel->proximo;
			}
		}
		ImprimirCupom(carteira,vale);
	}
	else
		MessageBox(NULL,L"A Venda não pode ser concluida, pois o cliente está bloqueado!",L"Cliente Bloqueado",MB_OK | MB_ICONERROR);


	//INICIALIZA CAMPOS
	InicializarCampos();
}
//-----------------------------------------------------------------------
void TFVendas::ImprimirCupom(int carteira,int vale)
{
	UnicodeString QUERY;
	int i;
	int x;
	int STATE = 0;

	STATE = impressora;

	if(!STATE || devolucao || carteira || vale)
	{
		if(devolucao || carteira || vale)
			x = 2;
		else
			x = 1;

        for(i=0;i<x;i++)
			ImprimirNaoFiscal();
	}
	else if(STATE == 1)
		ImprimirFiscal();
	else if(STATE == 2)
        ImprimirSAT();
}
//-----------------------------------------------------------------------
void TFVendas::ImprimirNaoFiscal()
{
//	TDate data;
//	UnicodeString TOTAL,MODO;
//	float preco_total,preco_unitario;
//	float dinheiro,cartao,cheque,carteira,vale;
//	char LinhaProduto[500];
//	char LinhaPreco[500];
//	int y,h;
//	int i;
//
//	y = 10;//altura inicial
//	h = 20;//altura linha
//	data = Now();
//
//	dinheiro = cartao = cheque = carteira = vale = 0;
//	if(PagamentoNo)
//	{
//		PagamentoMovel = PagamentoNo;
//		while(PagamentoMovel)
//		{
//			switch(PagamentoMovel->modpagar)
//			{
//				case 0:
//					dinheiro = dinheiro + PagamentoMovel->valor;
//				break;
//				case 1:
//					cartao = cartao + PagamentoMovel->valor;
//				break;
//				case 2:
//					cheque = cheque + PagamentoMovel->valor;
//				break;
//				case 3:
//					carteira = carteira + PagamentoMovel->valor;
//				break;
//				case 4:
//					vale = vale + PagamentoMovel->valor;
//				break;
//			}
//
//			PagamentoMovel = PagamentoMovel->proximo;
//		}
//
//	}
//
//	Printer()->BeginDoc();
//
//	Printer()->Canvas->Pen->Color = clBlack;
//	Printer()->Canvas->Font->Size = 7;
//	Printer()->Canvas->Font->Name = "Courier New";

	// CABEÇALHO
//	Printer()->Canvas->TextOutW(60, y, empresa->getRazaoSocial());
//	Printer()->Canvas->TextOutW(130, y + h, empresa->getRua()+","+empresa->getBairro());
//	Printer()->Canvas->TextOutW(110, y + 2*h, empresa->getBairro()+" - "+regiao->getMunicipio()+" - "+regiao->getUf());
//	Printer()->Canvas->TextOutW(0, y + 3*h, L"CNPJ: "+empresa->getCpfCnpj());
//	Printer()->Canvas->TextOutW(0, y + 4*h, L"I.E: "+empresa->getIeRg());
//	Printer()->Canvas->TextOutW(0, y + 5*h, L"SITE: "+empresa->getSite());
//	Printer()->Canvas->TextOutW(0, y + 6*h,L"--------------------------------------------------------------------------------");
//	y = y + 7*h;
//
//	Printer()->Canvas->TextOutW(0, y,data.DateString());
//	Printer()->Canvas->TextOutW(150, y,data.TimeString());
//	Printer()->Canvas->TextOutW(300, y, L"COD:" + IntToStr(Orcamento.codigo));
//	Printer()->Canvas->TextOutW(0, y + h,NOME_CLIENTE);
//	Printer()->Canvas->TextOutW(0, y + 2*h,L"--------------------------------------------------------------------------------");
//	y = y + 3*h;
//
//	Printer()->Canvas->Font->Size = 11;
//	Printer()->Canvas->TextOutW(160,y, L"CONTROLE INTERNO");
//	Printer()->Canvas->Font->Size = 7;
//	y = y +3*h;
//
//	Printer()->Canvas->TextOutW(0, y, "ITEM CÓDIGO DESCRIÇÃO QTD.UN.VL_UNIT( R$) VL_ITEM( R$)");
//	Printer()->Canvas->Font->Size = 7;
//	Printer()->Canvas->TextOutW(0, y + h,L"--------------------------------------------------------------------------------");
//	y = y + 2*h;
//
//	 PRODUTOS
//	preco_total = preco_unitario = 0;
//	if(Orcamento.produtos)
//	{
//		TabelaProdutosMovel = Orcamento.produtos;
//		while(TabelaProdutosMovel)
//		{
//			preco_unitario = TabelaProdutosMovel->preco*(1-TabelaProdutosMovel->desconto/100);
//			preco_total = preco_unitario*TabelaProdutosMovel->quantidade;
//
//			if(!TabelaProdutosMovel->devolucao)
//			{
//				sprintf(LinhaProduto,"%s %20s",TabelaProdutosMovel->codbarras,TabelaProdutosMovel->descricao);
//				sprintf(LinhaPreco,"%10.2f %5s x %10.2f  = %10.2f",TabelaProdutosMovel->quantidade,TabelaProdutosMovel->unidade,preco_unitario,preco_total);
//			}
//			else
//			{
//				sprintf(LinhaProduto,"%s DEVOLUCAO %10s",TabelaProdutosMovel->codbarras,TabelaProdutosMovel->descricao);
//				sprintf(LinhaPreco,"%10.2f %5s x -%10.2f  = -%10.2f",TabelaProdutosMovel->quantidade,TabelaProdutosMovel->unidade,preco_unitario,preco_total);
//			}
//
//			Printer()->Canvas->TextOutW(0, y,LinhaProduto);
//			Printer()->Canvas->TextOutW(0, y + h,LinhaPreco);
//			y = y + 2*h;
//
//			TabelaProdutosMovel = TabelaProdutosMovel->proximo;
//		}
//	}
//
//	 TOTAIS
//	TOTAL = EditValorTotal->Text;
//
//	Printer()->Canvas->Font->Style = TFontStyles() << fsBold;
//	Printer()->Canvas->TextOutW(0, y, "TOTAL R$");
//	Printer()->Canvas->TextOutW(500, y, TOTAL);
//
//	Printer()->Canvas->Font->Style = TFontStyles() >> fsBold;
//	y = y + h;
//
//	for(i=0;i<5;i++)
//		switch(i)
//		{
//			case 0:
//				if(dinheiro)
//				{
//					MODO = "DINHEIRO";
//					Printer()->Canvas->TextOutW(0, y , MODO);//MODO DE PAGAR
//					Printer()->Canvas->TextOutW(500,y,FormatFloat("#,###,###,##0.00",dinheiro));
//					y = y + h;
//				}
//			break;
//			case 1:
//				if(cartao)
//				{
//					MODO = "CARTÃO";
//					Printer()->Canvas->TextOutW(0, y, MODO);//MODO DE PAGAR
//					Printer()->Canvas->TextOutW(500, y,FormatFloat("#,###,###,##0.00",cartao));
//					y = y + h;
//				}
//			break;
//			case 2:
//				if(cheque)
//				{
//					MODO = "CHEQUE";
//					Printer()->Canvas->TextOutW(0, y, MODO);//MODO DE PAGAR
//					Printer()->Canvas->TextOutW(500, y,FormatFloat("#,###,###,##0.00",cheque));
//					y = y + h;
//				}
//			break;
//			case 3:
//				if(cheque)
//				{
//					MODO = "CARTEIRA";
//					Printer()->Canvas->TextOutW(0, y, MODO);//MODO DE PAGAR
//					Printer()->Canvas->TextOutW(500, y,FormatFloat("#,###,###,##0.00",carteira));
//					y = y + h;
//				}
//			break;
//			case 4:
//				if(vale)
//				{
//					MODO = "VALE";
//					Printer()->Canvas->TextOutW(0, y, MODO);//MODO DE PAGAR
//					Printer()->Canvas->TextOutW(500, y,FormatFloat("#,###,###,##0.00",vale));
//					y = y + h;
//				}
//			break;
//		}
//
//	Printer()->Canvas->TextOutW(0, y,"CUPOM SEM VALOR FISCAL");
//	Printer()->EndDoc();
}
//-----------------------------------------------------------------------
void TFVendas::ImprimirFiscal()
{
	char *VALOR_TOTAL;
	char *QUANTIDADE;
	char *VALOR_UNITARIO;
	char *CPF;
	char *CODBARRAS;
	char *DESCRICAO;
	float preco_unitario = 0;
	float preco_total = 0;
	float valor_total = 0;
	float dinheiro,cartao,cheque;
	int r;
	int i;

	dinheiro = cartao = cheque = 0;
	if(PagamentoNo)
	{
		PagamentoMovel = PagamentoNo;
		while(PagamentoMovel)
		{
			switch(PagamentoMovel->modpagar)
			{
				case 0:
					dinheiro = dinheiro + PagamentoMovel->valor;
				break;
				case 1:
					cartao = cartao + PagamentoMovel->valor;
				break;
				case 2:
					cheque = cheque + PagamentoMovel->valor;
				break;
			}

			PagamentoMovel = PagamentoMovel->proximo;
		}

	}

	CPF = StrToChar(CPF_CLIENTE);
	r = Bematech_FI_AbreCupom(CPF);
	free(CPF);

	if(r!=1)
	{
		MessageBox(NULL,L"CPF inválido",L"CPF inválido",MB_OK | MB_ICONWARNING);
		Bematech_FI_AbreCupom("");
	}

	// PRODUTOS
	if(Orcamento.produtos)
	{
		TabelaProdutosMovel = Orcamento.produtos;
		while(TabelaProdutosMovel)
		{
			preco_unitario = TabelaProdutosMovel->preco*(1-TabelaProdutosMovel->desconto/100);
			preco_total = preco_unitario*TabelaProdutosMovel->quantidade;
			valor_total = valor_total + preco_total;

			VALOR_UNITARIO = StrToChar(FormatFloat("#######0.00",preco_unitario));
			QUANTIDADE = StrToChar(FormatFloat("######0.000",TabelaProdutosMovel->quantidade));
			CODBARRAS = StrToChar(CharToStr(TabelaProdutosMovel->codbarras));
			DESCRICAO = StrToChar(CharToStr(TabelaProdutosMovel->descricao));

			CharLimite(CODBARRAS,13);
			CharLimite(DESCRICAO,29);

			r = Bematech_FI_VendeItem(CODBARRAS,DESCRICAO,"FF","F",QUANTIDADE,2,VALOR_UNITARIO,"%","0000");

			if(r!=1)
				AnalisaRetorno( r, L"CUPOM FISCAL", "", "" );

			free(VALOR_UNITARIO);
			free(QUANTIDADE);
			free(CODBARRAS);
			free(DESCRICAO);

			TabelaProdutosMovel = TabelaProdutosMovel->proximo;
		}
	}

	r = Bematech_FI_IniciaFechamentoCupom("A","$","0000");
	if(r!=1)
		AnalisaRetorno( r, L"CUPOM FISCAL", "", "" );

	for(i=0;i<5;i++)
		switch(i)
		{
			case 0:
				if(dinheiro)
				{
					VALOR_TOTAL = StrToChar(FormatFloat("#,###,###,##0.00",dinheiro));
					Bematech_FI_EfetuaFormaPagamento("Dinheiro",VALOR_TOTAL);
					free(VALOR_TOTAL);
				}
			break;
			case 1:
				if(cartao)
				{
					VALOR_TOTAL = StrToChar(FormatFloat("#,###,###,##0.00",cartao));
					Bematech_FI_EfetuaFormaPagamento("Cartao",VALOR_TOTAL);
					free(VALOR_TOTAL);
				}
			break;
			case 2:
				if(cheque)
				{
					VALOR_TOTAL = StrToChar(FormatFloat("#,###,###,##0.00",cheque));
					Bematech_FI_EfetuaFormaPagamento("Cheque",VALOR_TOTAL);
					free(VALOR_TOTAL);
				}
			break;
		}

	Bematech_FI_TerminaFechamentoCupom("Agradecemos a preferência, volte sempre");

}
//---------------------------------------------------------------------------
void TFVendas::ImprimirSAT()
{
	UnicodeString sessao = AberturaCupomSAT();
	if(VenderItemSAT(sessao));
		if(EfetuarPagamentoSAT(sessao));
			FecharCupomSAT(sessao);
}
UnicodeString TFVendas::AberturaCupomSAT()
{
		UnicodeString sessao;

		TJSONObject *jsonAbertura = new TJSONObject();

		//Monta JSon identificação
		TJSONObject *identificacao = new TJSONObject();
		identificacao->AddPair("cnpj", new TJSONString("19125250000186"));
		identificacao->AddPair("numeroCaixa", new TJSONString("01"));
		identificacao->AddPair("signAC", new TJSONString("sJS5BHvzfiV3Lmxd8rgdFF+7x+JBSqvfxSTk5yXPHUeaZXnDKt4/OFauIKFYl2czyYJh7yYbzqYr1Dc4n3LfNQrXGk+1MTqOVxY5n7T/HWMaKQuDFWqXQDWZEQTGCov8izILReN+HTZCv8bxc4NVEoQVwqZGAsS27amv0FtsGeGpwfrAiyXQlpsdGmZOFs1+5NFV4e4uPHW4XrRtN342NxfWbVKUd4dZ7mxDujLD1jZ4exT8KorLEqYP4Oe6//ZnUgtyO1J2qUNcjxDcNb1JjkPOPl4FXlTPX6p2PRKpus/gKmFM+Fczvi2HUC9mgT8ZKtfQqaIAym1V+z/Awjv1Hg=="));

		//Adiciona identificação no json principal
		jsonAbertura->AddPair("identificacao", identificacao);

		//-------------------------------------
		//Cria Json emitente
		TJSONObject *emitente = new TJSONObject();
		emitente->AddPair("cnpj", new TJSONString("19125250000186"));
		emitente->AddPair("ie", new TJSONString("454390742115"));
		emitente->AddPair("indRatISSQN", new TJSONString("S"));

		//Adiciona Json emitente no Json principal
		jsonAbertura->AddPair("emitente", emitente);

		//-------------------------------------
		//Criar JSon destinatario
		TJSONObject *destinatario = new TJSONObject();
		destinatario->AddPair("cpf", new TJSONString("41063729831"));
		destinatario->AddPair("xNome", new TJSONString("Filipe Julio Cardoso"));

		//Adiciona destinatario em jSon principal
		jsonAbertura->AddPair("destinatario", destinatario);

		UnicodeString JsonString = jsonAbertura->ToString();
		JsonString = StringReplace(JsonString,0xA,"",TReplaceFlags() << rfReplaceAll);
		JsonString = StringReplace(JsonString,0xD,"",TReplaceFlags() << rfReplaceAll);

		TStringStream *JsonToSend = new TStringStream();

		JsonToSend->WriteString(JsonString);
		JsonToSend->Position = 0;

		UnicodeString URL = "http://localhost:9999/api/v1/documento/cupom";

		try {

			HTTP->Request->ContentType = "application/json";
			HTTP->Request->CharSet = "utf-8";
			HTTP->Response->ContentType ="plain/text";
          	HTTP->Response->CharSet = "UTF-8";

			String JsonStreamRetorno = HTTP->Post(URL, JsonToSend);
            String Sessao = JsonStreamRetorno;

//			memoLog->Lines->Add(JsonStreamRetorno);

			JsonStreamRetorno = StringReplace(JsonStreamRetorno,0xA,"",TReplaceFlags() << rfReplaceAll);
            JsonStreamRetorno = StringReplace(JsonStreamRetorno,0xD,"",TReplaceFlags() << rfReplaceAll);

			TJSONObject *jsonObj = (TJSONObject*) TJSONObject::ParseJSONValue(TEncoding::ASCII->GetBytes(JsonStreamRetorno), 0);

			TJSONPair *par1 = jsonObj->Get(1);

			sessao = StringReplace(par1->JsonValue->ToString(),"\"","",TReplaceFlags() << rfReplaceAll);

            return sessao;
		}
		catch (Exception& e){
			ShowMessage("Erro ao abrir o CFE-e-SAT");
            return "Erro ao abrir o CFE-e-SAT";
		}
}
//---------------------------------------------------------------------------
int TFVendas::VenderItemSAT(UnicodeString sessao)
{
		//JSon principal
		TJSONObject *jsonVenda =  new TJSONObject();

		TJSONObject *produto = new TJSONObject();
		produto->AddPair("cean", new TJSONString("7897381600621"));//OK
		produto->AddPair("ncm", new TJSONString("85444900"));//OK
		produto->AddPair("cfop", new TJSONString("5405"));//OK
		produto->AddPair("indTot", new TJSONNumber(1));
		produto->AddPair("vUnCom", new TJSONNumber(1.000));
		produto->AddPair("uTrib", new TJSONString("UN"));
		produto->AddPair("vUnTrib", new TJSONString("1.000"));
		produto->AddPair("cProd", new TJSONString("7897381600621"));
		produto->AddPair("xProd", new TJSONString("Cabo flex 2.50mm"));
		produto->AddPair("uCom", new TJSONString("UN"));
		produto->AddPair("qTrib", new TJSONNumber(1.000));
		produto->AddPair("qCom", new TJSONString("1.00"));
		produto->AddPair("vProd", new TJSONNumber(1.00));
		produto->AddPair("indRegra", new TJSONString("A"));
		produto->AddPair("vDesc", new TJSONNumber(0.00));
		produto->AddPair("vOutro", new TJSONNumber(0.00));
		produto->AddPair("qCom", new TJSONString("1.0000"));

		//Adiciona jSonProduto no json principal
		jsonVenda->AddPair("produto", produto);

		//-------------------------------------
		//Cria Json icms00
		TJSONObject *icms00 = new TJSONObject();
		icms00->AddPair("orig", new TJSONNumber(0));
		icms00->AddPair("cst", new TJSONString("0.00"));
		icms00->AddPair("picms", new TJSONNumber(0));

		//Adiciona icms00 em icms
		TJSONObject *icms = new TJSONObject();
		icms->AddPair("icms00", icms00);

		//-------------------------------------
		//Criar JSon cofinsnt
		TJSONObject *cofinsnt = new TJSONObject();
		cofinsnt->AddPair("cst", new TJSONString("08"));

		//Adiciona cofinsnt em cofins
		TJSONObject *cofins = new TJSONObject();
		cofins->AddPair("cofinsnt", cofinsnt);

		//-------------------------------------
		//Criar JSon pisnt
		TJSONObject *pisnt = new TJSONObject();
		pisnt->AddPair("cst", new TJSONString("08"));

		//Adiciona pisnt em pis
		TJSONObject *pis = new TJSONObject();
		pis->AddPair("pisnt", pisnt);


		//-------------------------------------
		//Criar JSon Imposto
		TJSONObject *imposto =  new TJSONObject();

		//Adiciona icms em imposto
		imposto->AddPair("icms", icms);

		//Adiciona cofins em imposto
		imposto->AddPair("cofins", cofins);

		//Adiciona pis em imposto
		imposto->AddPair("pis", pis);

		//Adiciona imposto no json de venda
		jsonVenda->AddPair("imposto", imposto);

		//Adiciona os pares na raiz do JSon principal
		jsonVenda->AddPair("vItem12741", new TJSONString("1"));
		jsonVenda->AddPair("nItem", new TJSONNumber(1));

		UnicodeString JsonString = jsonVenda->ToString();
		JsonString = StringReplace(JsonString,0xA,"",TReplaceFlags() << rfReplaceAll);
		JsonString = StringReplace(JsonString,0xD,"",TReplaceFlags() << rfReplaceAll);

		TStringStream *JsonToSend = new TStringStream();

		JsonToSend->WriteString(JsonString);
		JsonToSend->Position = 0;

		UnicodeString URL = "http://localhost:9999/api/v1/documento/cupom/"+sessao+"/item";

		try {

		    HTTP->Request->ContentType = "application/json";
			HTTP->Request->CharSet = "utf-8";
			HTTP->Response->ContentType ="plain/text";
			HTTP->Response->CharSet = "UTF-8";

			String JsonStreamRetorno = HTTP->Post(URL, JsonToSend);
			String Sessao = JsonStreamRetorno;

//			memoLog->Lines->Add(JsonStreamRetorno);
			return 1;
		}
		catch (Exception& e){
			ShowMessage("Erro ao vender item CFE-e-SAT");
			return 0;
		}
}
//---------------------------------------------------------------------------
int TFVendas::EfetuarPagamentoSAT(UnicodeString sessao)
{
		//JSon principal
		TJSONObject *jsonPagamento = new TJSONObject();

		jsonPagamento->AddPair("tPag", new TJSONString(""));
		jsonPagamento->AddPair("vPag", new TJSONString(""));

		UnicodeString JsonString = jsonPagamento->ToString();
		JsonString = StringReplace(JsonString,0xA,"",TReplaceFlags() << rfReplaceAll);
		JsonString = StringReplace(JsonString,0xD,"",TReplaceFlags() << rfReplaceAll);

		TStringStream *JsonToSend = new TStringStream();

		WriteStringToStream(JsonToSend, JsonString, enUTF8);
		JsonToSend->Position = 0;

		UnicodeString URL = "http://localhost:9999/api/v1/documento/cupom/"+sessao+"/pagamento";

		try {

			HTTP->Request->ContentType = "application/json";
			HTTP->Request->CharSet = "utf-8";
			HTTP->Response->ContentType ="plain/text";
			HTTP->Response->CharSet = "UTF-8";

			String JsonStreamRetorno = HTTP->Post(URL, JsonToSend);

//			memoLog->Lines->Add(JsonStreamRetorno);

			return 1;
		}
		catch (Exception& e){
			ShowMessage("Erro ao efetuar pagamento CFE-e-SAT");
			return 0;
		}
}
//---------------------------------------------------------------------------
int TFVendas::FecharCupomSAT(UnicodeString sessao)
{
		//JSon principal
		TJSONObject *jsonFechamento = new TJSONObject();

		//Monta JSon do total
		TJSONObject *total = new TJSONObject();
		total->AddPair("vCFeLei12741", new TJSONString("0.00"));

		//Adiciona JSon do total no JSon principal
		jsonFechamento->AddPair("total",total);

		//Monta JSon Informação Adicional
		TJSONObject *informacaoAdicional = new TJSONObject();
		informacaoAdicional->AddPair("infCpl", new TJSONString("Informacoes Complementares"));

		//Adiciona JSon do total no JSon principal
		jsonFechamento->AddPair("informacaoAdicional",informacaoAdicional);

		UnicodeString JsonString = jsonFechamento->ToString();
		JsonString = StringReplace(JsonString,0xA,"",TReplaceFlags() << rfReplaceAll);
		JsonString = StringReplace(JsonString,0xD,"",TReplaceFlags() << rfReplaceAll);

		TStringStream *JsonToSend = new TStringStream();

		WriteStringToStream(JsonToSend, JsonString, enUTF8);
		JsonToSend->Position = 0;

		UnicodeString URL = "http://localhost:9999/api/v1/documento/cupom/"+sessao;

		try {

			HTTP->Request->ContentType = "application/json";
			HTTP->Request->CharSet = "utf-8";
			HTTP->Response->ContentType ="plain/text";
			HTTP->Response->CharSet = "UTF-8";

			String JsonStreamRetorno = HTTP->Post(URL, JsonToSend);

//			memoLog->Lines->Add(JsonStreamRetorno);

			return 1;
		}
		catch (Exception& e){
			ShowMessage("Erro ao fechar o cupom CFE-e-SAT");
			return 0;
		}
}
//---------------------------------------------------------------------------
int TFVendas::CancelarCupomSAT()
{
    return 0;
}

//---------------------------------------------------------------------------
void TFVendas::AbrirGaveta()
{
	UnicodeString QUERY;
	int STATE = 0;

	STATE = VerificarFiscal();

	if(STATE)
		Bematech_FI_AcionaGaveta();
	else
	{
		Printer()->BeginDoc();
		Printer()->Canvas->TextOutW(5,5,0x27+"\'VN\'");
		Printer()->EndDoc();
	}

}
//-----------------------------------------------------------------------
void TFVendas::AnalisaRetorno(int Retorno, const wchar_t * TituloJanela, char * Mensagem, char * Informacao)
{
    //int  RetornoStatus = 0;   // retorno da função que le o status da impressora
    int  ACK, ST1, ST2 = 0;   // variáveis de status da impressora
    char StringStatus[12];    // status da impressora em string (ACK, ST1, ST2)
    //char StringRetorno[450];  // descrição por extenso dos status da impressora + StatusString (450 posicoes)
    char *StringRetorno;      // descrição por extenso dos status da impressora + StatusString (450 posicoes)
    int Tamanho = 0;          // qtde de bytes que devem ser alocados para a variável StringRetorno

    ACK = 0; ST1 = 0; ST2 = 0;
    //memset( StringRetorno, 0, 450 );
    memset( StringStatus,  0,  12 );

    Tamanho = strlen( Mensagem ) + strlen( Informacao ) + 450 + 5; // tamanho da var. Mensagem + tam. da var. Informacao + 450 (descrição por extenso dos status da impressora + StatusString) + 5 ( LF + nulo )

    // tenta alocar memória pra variável StringRetorno, se der erro retorna
    if ( ( StringRetorno = new char[ Tamanho ] ) == NULL )
        return;

    memset( StringRetorno, '\0', Tamanho );

    switch( Retorno)
    {
        case 0:      // erro de comunicação
			Application->MessageBox(L"Erro de comunicação com a impressora", TituloJanela, MB_OK);
			break;

		case -1:      // erro de execução
			Application->MessageBox(L"Erro de execução da função", TituloJanela, MB_OK);
			break;

		case -2:      // parâmetro inválido
			Application->MessageBox(L"Parâmetro inválido na função", TituloJanela, MB_OK);
			break;

		case -3:      // alíquota não programada
			Application->MessageBox(L"Alíquota não programada", TituloJanela, MB_OK);
			break;

		case -4:      // Arquivo de inicialização BemaFI32.ini não foi encontrado
			Application->MessageBox(L"O arquivo de inicialização BemaFI32.ini não foi encontrado", TituloJanela, MB_OK);
			break;

		case -5:      // erro na abertura da porta serial
			Application->MessageBox(L"Erro ao tentar abrir a porta de comunicação", TituloJanela, MB_OK);
			break;

		case -6:      // impressora desligada ou cabo desconectado
			Application->MessageBox(L"impressora desligada ou cabo de comunicação desconectado", TituloJanela, MB_OK);
			break;

		case -7:      // banco não encontrado no arquivo 'BemaFI32.ini'
			Application->MessageBox(L"banco não encontrado no arquivo 'BemaFI32.ini'", TituloJanela, MB_OK);
			break;

		case -8:      // erro ao criar ou gravar no arquivo 'Status.txt'ou 'Retorno.txt'
			Application->MessageBox(L"Erro ao criar ou gravar no arquivo 'Status.txt'ou 'Retorno.txt'", TituloJanela, MB_OK);
			break;

		case 1:
			// le o status da impressora
			Retorno = Bematech_FI_RetornoImpressora( &ACK, &ST1, &ST2);

			if ( ACK == 21 )
			{
				Application->MessageBox(L"Status da impressora: 21 \n Comando não executado", TituloJanela, MB_OK);
				return;
			}

			if ( ST1 != 0 || ST2 != 0 )
			{
				sprintf( StringRetorno, "%s%d,%d,%d\n", "Status da Impressora: ", ACK, ST1, ST2 );

				if ( ST1 >= 128 )
				{
					strcat( StringRetorno, "Fim de Papel\n" );
					ST1 -= 128;
                }

                if ( ST1 >= 64 )
                {
                    strcat( StringRetorno, "Pouco Papel\n" );
                    ST1 -= 64;
                }

                if ( ST1 >= 32 )
                {
                    strcat( StringRetorno, "Erro no relógio\n" );
                    ST1 -= 32;
                }

                if ( ST1 >= 16 )
                {
                    strcat( StringRetorno, "Impressora em erro\n" );
                    ST1 -= 16;
                }

                if ( ST1 >= 8 )
                {
                    strcat( StringRetorno, "Primeiro dado do comando não foi Esc\n" );
                    ST1 -= 8;
                }

                if ( ST1 >= 4 )
                {
                    strcat( StringRetorno, "Comando inexistente\n" );
                    ST1 -= 4;
                }

                if ( ST1 >= 2 )
                {
                    strcat( StringRetorno, "Cupom fiscal aberto\n" );
                    ST1 -= - 2;
                }

                if ( ST1 >= 1 )
                {
                    strcat( StringRetorno, "Número de parâmetros inválido no comando\n" );
                    ST1 -= - 1;
                }

                if ( ST2 >= 128 )
                {
                    strcat( StringRetorno, "Tipo de Parâmetro de comando inválido\n" );
                    ST2 -= 128;
                }

                if ( ST2 >= 64 )
                {
                    strcat( StringRetorno, "Memória fiscal lotada\n" );
                    ST2 -= 64;
                }

                if ( ST2 >= 32 )
                {
                    strcat( StringRetorno, "Erro na CMOS\n" );
                    ST2 -= 32;
                }

                if ( ST2 >= 16 )
                {
                    strcat( StringRetorno, "Alíquota não programada\n" );
                    ST2 -= 16;
                }

                if ( ST2 >= 8 )
                {
                    strcat( StringRetorno, "Capacidade de alíquota programáveis lotada\n" );
                    ST2 -= 8;
                }

                if ( ST2 >= 4 )
                {
                    strcat( StringRetorno, "Cancelamento não permitido\n" );
                    ST2 -= 4;
                }

                if ( ST2 >= 2 )
                {
                    strcat( StringRetorno, "CGC/IE do proprietário não programados\n" );
                    ST2 -= 2;
                }

                if ( ST2 >= 1 )
                {
                    strcat( StringRetorno, "Comando não executado\n" );
                    ST2 -= 1;
                }

            } //fim do ST1 <> 0 and ST2 <> 0

            // se houver informação pra ser mostrada, concatena com o status
            if ( strlen( Mensagem ) > 0 || strlen( Informacao ) > 0 )
                sprintf( StringRetorno + strlen( StringRetorno ), "\n%s%s", Mensagem, Informacao );

            // se houver alguma informação mostra em tela
			UnicodeString sr;
			if ( strlen( StringRetorno ) > 0 )
			{
				sr=StringRetorno;
				Application->MessageBox(sr.c_str(), TituloJanela, MB_OK);
			}
            break;

    } // end switch
}
//-----------------------------------
int TFVendas::VerificarFiscal()
{
	UnicodeString QUERY;
	int STATE;

	ConfigPdvModel *config_pdv_model = new ConfigPdvModel();
	ConfigPdvEspelho *config_pdv = config_pdv_model->selectAll();

    STATE = config_pdv->getCupom();

	return STATE;
}



void __fastcall TFVendas::ButtonGavetaClick(TObject *Sender)
{
	AbrirGaveta();
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::F7Execute(TObject *Sender)
{
	if(Orcamento.produtos)
		FVendasCpf->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::F12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void TFVendas::DescontoDinheiro()
{
	float total,preco,porcentagem,dinheiro,desconto;
	int promocao = 0;
	int devolucao = 0;

	dinheiro = FStrToFloat(EditDescontoD->Text);

	if(Orcamento.produtos)
	{
		TabelaProdutosMovel = Orcamento.produtos;

		total = 0;
		while(TabelaProdutosMovel)
		{
			preco = TabelaProdutosMovel->preco*TabelaProdutosMovel->quantidade;
			if(TabelaProdutosMovel->funcao != 2)
			{
				total = total + preco;
				if(TabelaProdutosMovel->promocao)
					promocao = 1;
				if(TabelaProdutosMovel->devolucao)
					devolucao = 1;
			}
			TabelaProdutosMovel = TabelaProdutosMovel->proximo;
		}

		desconto = total - dinheiro;

		if(total && !promocao && !devolucao)
			porcentagem = (1 - desconto/total)*100;
		else
		{
			porcentagem = 0;
			if(promocao)
				MessageBox(NULL,L"Modo de desconto indisponível, existem produtos em promoção",L"Desconto Indisponível",MB_OK | MB_ICONWARNING);
			else if(devolucao)
				MessageBox(NULL,L"Modo de desconto indisponível, existem produtos em devolução",L"Desconto Indisponível",MB_OK | MB_ICONWARNING);
		}

		TabelaProdutosMovel = Orcamento.produtos;
		while(TabelaProdutosMovel)
		{
			TabelaProdutosMovel->desconto = porcentagem;
			TabelaProdutosMovel = TabelaProdutosMovel->proximo;
		}
	}
}
//---------------------------------------------------------------------------
void TFVendas::DescontoPorcentagem()
{
	float porcentagem;
	int promocao = 0;
	int devolucao = 0;

	porcentagem = FStrToFloat(EditDescontoP->Text);

	if(Orcamento.produtos)
	{
		TabelaProdutosMovel = Orcamento.produtos;
		while(TabelaProdutosMovel)
		{
			if(TabelaProdutosMovel->funcao != 2)
			{
				if(TabelaProdutosMovel->promocao)
						promocao = 1;
				if(TabelaProdutosMovel->devolucao)
					devolucao = 1;
			}
			TabelaProdutosMovel = TabelaProdutosMovel->proximo;
		}

		if(promocao || devolucao)
		{
			porcentagem = 0;
			if(promocao)
				MessageBox(NULL,L"Modo de desconto indisponível, existem produtos em promoção",L"Desconto Indisponível",MB_OK | MB_ICONWARNING);
			else
				MessageBox(NULL,L"Modo de desconto indisponível, existem produtos em devolução",L"Desconto Indisponível",MB_OK | MB_ICONWARNING);
		}

		TabelaProdutosMovel = Orcamento.produtos;
		while(TabelaProdutosMovel)
		{
			TabelaProdutosMovel->desconto = porcentagem;
			TabelaProdutosMovel = TabelaProdutosMovel->proximo;
		}
	}
}

void __fastcall TFVendas::EditDescontoDKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key == 13)
	{
		DescontoDinheiro();
		PermissaoDesconto();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::EditDescontoDExit(TObject *Sender)
{
	DescontoDinheiro();
	GerarGridProdutos();
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::EditDescontoPExit(TObject *Sender)
{
	DescontoPorcentagem();
	GerarGridProdutos();
}
//---------------------------------------------------------------------------

void __fastcall TFVendas::EditDescontoPKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key == 13)
	{
		DescontoPorcentagem();
		PermissaoDesconto();
	}
}
//---------------------------------------------------------------------------
void TFVendas::PermissaoDesconto()
{
	float desconto,permitido;

	Total();

	desconto = FStrToFloat(EditDescontoP->Text);
	permitido = GetDescontoPermitido();

	if(Orcamento.produtos)
	{
		TabelaProdutosMovel = Orcamento.produtos;
		if(desconto > permitido)
		{
			FLiberarAcesso->ShowModal();
			if(!FLiberarAcesso->GetAcesso())
			{
				while(TabelaProdutosMovel)
				{
					TabelaProdutosMovel->desconto = 0;
					TabelaProdutosMovel = TabelaProdutosMovel->proximo;
				}
			}
		}
	}
	GerarGridProdutos();
}
//--------------------------------------------------------------------------
float TFVendas::GetDescontoPermitido()
{
	UnicodeString QUERY;

	//PEGA O VALOR MAXIMO DE DESCONTO
	QUERY = "SELECT id,desconto FROM usuarios WHERE id ='"+IntToStr(USUARIO)+"' ORDER BY id DESC";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();

	return SQLQuery1->Fields->FieldByName("desconto")->AsFloat;
}
//-------------------------------------------------------------------------
void TFVendas::AtualizarOrcamento()
{
	UnicodeString QUERY;
	if(Orcamento.produtos)
	{
		TabelaProdutosMovel = Orcamento.produtos;

		while(TabelaProdutosMovel)
		{
			/*--------------------------MODIFICA PRODUTOS--------------------------------*/
			QUERY = "UPDATE orcamentos_produtos SET ";

			QUERY += "id_produto='"+IntToStr(TabelaProdutosMovel->id_produto)+"',";
			QUERY += "codbarras='"+CharToStr(TabelaProdutosMovel->codbarras)+"',";
			QUERY += "descricao='"+CharToStr(TabelaProdutosMovel->descricao)+"',";
			QUERY += "preco='"+FloatToStr(TabelaProdutosMovel->preco)+"',";
			QUERY += "quantidade='"+FloatToStr(TabelaProdutosMovel->quantidade)+"',";
			QUERY += "unidade_medida='"+CharToStr(TabelaProdutosMovel->unidade)+"',";
			QUERY += "marca='"+CharToStr(TabelaProdutosMovel->marca)+"',";
			QUERY += "ncm='"+CharToStr(TabelaProdutosMovel->ncm)+"',";
			QUERY += "cfop='"+CharToStr(TabelaProdutosMovel->cfop)+"',";
			QUERY += "desconto='"+FloatToStr(TabelaProdutosMovel->desconto)+"',";
			QUERY += "promocao='"+IntToStr(TabelaProdutosMovel->promocao)+"',";
			QUERY += "devolucao='"+IntToStr(TabelaProdutosMovel->devolucao)+"'";

			QUERY += " WHERE id='"+IntToStr(TabelaProdutosMovel->id)+"'";

			SQLQuery1->SQL->Clear();
			SQLQuery1->SQL->Add(QUERY);
			SQLQuery1->ExecSQL();

			TabelaProdutosMovel = TabelaProdutosMovel->proximo;
		}
	}
}
void TFVendas::SetarImpressora()
{
	if(impressora)
	{
		LabelCabecalhoTitulo->Font->Color = TColor(0x0000ff);
		impressora = 0;
	}
	else
	{
		LabelCabecalhoTitulo->Font->Color = TColor(0x30CE95);
		impressora = VerificarFiscal();
	}

}

void __fastcall TFVendas::F9Execute(TObject *Sender)
{
	SetarImpressora();
}
//---------------------------------------------------------------------------
void TFVendas::loadCabecalho()
{
//    EmpresaModel *empresa_model = new EmpresaModel();
//	EmpresaEspelho *empresa = empresa_model->selectAll();
//
//	InfoGeraisModel *info_gerais_model = new InfoGeraisModel();
//	InfoGeraisEspelho *info_gerais = info_gerais_model->selectAll();
//
//	LabelCabecalhoTitulo->Caption =  "[PDV] " + empresa->getNomeFantasia();
//
//	LabelCabecalhoSubTitulo->Caption =  ToUpper(info_gerais->getSoftwareName());
}

