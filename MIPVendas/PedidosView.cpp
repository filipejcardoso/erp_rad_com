//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PedidosView.h"
#include "PedidosDAO.h"
#include "ProdutosDAO.h"
#include "PedidosProdutosDAO.h"
#include "Produtos.h"
#include "Principal.h"
#include "PedidosProdutos.h"
#include "ProdutosController.h"
#include "ClientesController.h"
#include "GridHelper.h"
#include "ProdutosView.h"
#include "ListaProdutosView.h"
#include "Sistema.h"
#include "Enderecos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma resource "*.dfm"
TFPedidosView *FPedidosView;
//---------------------------------------------------------------------------
__fastcall TFPedidosView::TFPedidosView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFPedidosView::FormCreate(TObject *Sender)
{
	controller = new PedidosController();
    pedido = new Pedidos();

	//CONFIGURAR O FORM
	ConfigurarForm(this);
}
//---------------------------------------------------------------------------
void __fastcall TFPedidosView::EditCodigoKeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key == 13)
	{
		EditQuantidade->Text = "1";
		EditQuantidade->SetFocus();
	}
}
//---------------------------------------------------------------------------
void TFPedidosView::loadView()
{
	loadClearFields();

	if(!editar)
		pedido = controller->createPedido();

	loadPedido();
}
//---------------------------------------------------------------------------
void TFPedidosView::loadPedido()
{
	TList *list = FPedidosDAO->show("", pedido->id);

	pedido = (Pedidos*) list->Items[0];

    //PRODUTOS
	gridProdutos();

    //NUMERO
	LabelNumeroPedido->Caption = FormatFloat("00000", pedido->id);

    //OBSERVACAO
	MemoObs->Lines->Clear();
	MemoObs->Lines->Add(pedido->observacao);

    //DATA
	LabelData->Caption = pedido->created_at;

	//DESCONTO
	EditValor->Text = FormatFloat("#,###,###,##0.00",pedido->valor);
	EditDescontoP->Text = FormatFloat("#,###,###,##0.00",pedido->desconto);

	if(pedido->valor == 0 && pedido->desconto == 100)
		EditDescontoD->Clear();
	else
		EditDescontoD->Text = FormatFloat("#,###,###,##0.00",pedido->desconto*pedido->valor/(100 - pedido->desconto));

	//ATENDENTE
	LabelAtendente->Caption = pedido->atendente->nome.UpperCase();

	//CLIENTE
	LabelCliente->Caption = "CLIENTE: " + pedido->cliente->nome.UpperCase();

	//MARGEM DE CONTRIBUICAO
    LabelContribuicao->Caption = "Margem de Contribuição: " + FormatFloat("#,###,###,##0.00", pedido->margem_contribuicao) + "%";

	//MARGEM DE NFE
	LabelNfe->Caption = "Margem NF-e: " + FormatFloat("#,###,###,##0.00", pedido->margem_nfe) + "%";

    EditCodigo->SetFocus();
}
//---------------------------------------------------------------------------
void TFPedidosView::loadClearFields()
{
	setEditarQuantidade(false);

	EditValor->Clear();
	EditCodigo->Clear();
    LabelContribuicao->Visible = FALSE;
    LabelNfe->Visible = FALSE;

	EditCodigo->SetFocus();
}
//---------------------------------------------------------------------------
void TFPedidosView::gridProdutos()
{
	PedidosProdutos *produto;
	int numerodalinha,i;

	for(i=1;i<StringGridProdutos->RowCount;i++)
		StringGridProdutos->Rows[i]->Clear();

	numerodalinha = 1;
	//ESTRUTURA
	StringGridProdutos->Options << goRowSelect;
	StringGridProdutos->ScrollBars = ssVertical;
	StringGridProdutos->Rows[1]->Clear();
	StringGridProdutos->RowCount = 0;
	StringGridProdutos->ColCount = 9;
	StringGridProdutos->FixedCols = 0;
	StringGridProdutos->Cells[0][0] = "Item  ";
	StringGridProdutos->Cells[1][0] = "CodBarras";
	StringGridProdutos->Cells[2][0] = "Nome";
	StringGridProdutos->Cells[3][0] = "UN";
	StringGridProdutos->Cells[4][0] = "Marca";
	StringGridProdutos->Cells[5][0] = "QTD   ";
	StringGridProdutos->Cells[6][0] = "Desconto";
	StringGridProdutos->Cells[7][0] = "Unitário";
	StringGridProdutos->Cells[8][0] = "Total";
	//ESTRUTURA

	TList *produtos = this->pedido->pedidos_produto;

	for(i=0; i<produtos->Count; i++)
	{
		produto = (PedidosProdutos*) produtos->Items[i];

		StringGridProdutos->Cells[0][numerodalinha] = i+1;
		StringGridProdutos->Cells[1][numerodalinha] = produto->codbarras;
		StringGridProdutos->Cells[2][numerodalinha] = produto->nome;
		StringGridProdutos->Cells[3][numerodalinha] = produto->unidade_medida;
		StringGridProdutos->Cells[4][numerodalinha] = produto->marca;
		StringGridProdutos->Cells[5][numerodalinha] = produto->quantidade;
		StringGridProdutos->Cells[6][numerodalinha] = FormatFloat("#,###,###,##0.00",produto->desconto);
		StringGridProdutos->Cells[7][numerodalinha] = FormatFloat("#,###,###,##0.00",produto->preco/produto->quantidade);
		StringGridProdutos->Cells[8][numerodalinha] = FormatFloat("#,###,###,##0.00",produto->preco);

		StringGridProdutos->RowCount++;

		numerodalinha++;

		if (numerodalinha == 2)
			StringGridProdutos->FixedRows = 1;
	}
	if (numerodalinha <= 1)
		StringGridProdutos->RowCount++;

	GridHelper *grid = new GridHelper();
	grid->StringGrid = StringGridProdutos;
	grid->sizeGrid();
}
//---------------------------------------------------------------------------
void __fastcall TFPedidosView::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------

void __fastcall TFPedidosView::StringGridProdutosDrawCell(TObject *Sender, int ACol,
		  int ARow, TRect &Rect, TGridDrawState State)
{
UnicodeString Texto;
	if(ARow>0)
	{
		Texto = StringGridProdutos->Cells[ACol][ARow];

		StringGridProdutos->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGridProdutos->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGridProdutos->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGridProdutos->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGridProdutos->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGridProdutos->Canvas->FillRect(Rect);
		StringGridProdutos->Canvas->Rectangle(Rect.Left-5,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGridProdutos->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

	}}
//---------------------------------------------------------------------------
void TFPedidosView::insertProduto()
{
	TList *listProdutos = new TList();
	PedidosProdutos *pedido_produto = new PedidosProdutos();

	UnicodeString codbarras = EditCodigo->Text.Trim();
	EditCodigo->Clear();

	float quantidade = FStrToFloat(EditQuantidade->Text.Trim());

	pedido_produto->codbarras = codbarras;
	pedido_produto->quantidade = quantidade;

	listProdutos->Add((PedidosProdutos*) pedido_produto);

	controller->addProduto(pedido, listProdutos);
}
void __fastcall TFPedidosView::FormClose(TObject *Sender, TCloseAction &Action)
{
    controller->deleteEmpty(pedido);
}
//---------------------------------------------------------------------------


void __fastcall TFPedidosView::EditQuantidadeKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key == 13)
	{
		if(editar_produto)
		{
			PedidosProdutos *produto = (PedidosProdutos*)pedido->pedidos_produto->Items[rowselect - 1];

			controller->setProdutoQuantidade(pedido, produto, EditQuantidade->Text.Trim());
		}
		else
			insertProduto();

		this->loadPedido();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFPedidosView::EditCodigoClick(TObject *Sender)
{
	setEditarQuantidade(false);
}
//---------------------------------------------------------------------------


void __fastcall TFPedidosView::StringGridProdutosSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselect = ARow;

	if(ARow>0 && StringGridProdutos->Cells[ACol][ARow].Trim()!="")
		setEditarQuantidade(true);
}
//---------------------------------------------------------------------------
void TFPedidosView::setEditarQuantidade(bool editar)
{
	editar_produto = editar;

	if(editar)
	{
		EditQuantidade->Color = clMoneyGreen;
		EditQuantidade->Text = ((PedidosProdutos*)pedido->pedidos_produto->Items[rowselect - 1])->quantidade;

		EditDesconto->Color = clMoneyGreen;
		EditDesconto->Text = FormatFloat("#,###,###,##0.00",((PedidosProdutos*)pedido->pedidos_produto->Items[rowselect - 1])->desconto);
	}
	else
	{
		EditQuantidade->Color = TColor(0x00F0F2F3);
		EditQuantidade->Clear();

		EditDesconto->Color = TColor(0x00F0F2F3);
		EditDesconto->Clear();
	}
}

void __fastcall TFPedidosView::SearchProductClick(TObject *Sender)
{
    this->searchProduto();
}

void __fastcall TFPedidosView::ExitClick(TObject *Sender)
{
	Close();
}
void __fastcall TFPedidosView::EditDescontoKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key == 13)
	{
		if(editar_produto)
		{
			PedidosProdutos *produto = (PedidosProdutos*)pedido->pedidos_produto->Items[rowselect - 1];

			controller->setProdutoDesconto(pedido, produto, EditDesconto->Text.Trim());

			this->loadPedido();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFPedidosView::EditDescontoDKeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key == 13)
	{
		controller->setDescontoD(pedido, EditDescontoD->Text.Trim());

		this->loadPedido();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFPedidosView::EditDescontoPKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key == 13)
	{
		controller->setDescontoP(pedido, EditDescontoP->Text.Trim());

		this->loadPedido();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFPedidosView::TimerObsTimer(TObject *Sender)
{
	TimerObs->Enabled = FALSE;
	pedido->observacao = MemoObs->Text.Trim();
	controller->setObservacao(pedido, pedido->observacao);
}
//---------------------------------------------------------------------------

void __fastcall TFPedidosView::MemoObsKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(!TimerObs->Enabled)
        TimerObs->Enabled = TRUE;
}
//---------------------------------------------------------------------------
void TFPedidosView::imprimir()
{
	frxUserDataSet1->RangeEnd = reCount;
	frxUserDataSet1->RangeEndCount = StringGridProdutos->RowCount - 1;
	frxReport1->ShowReport();
}
void __fastcall TFPedidosView::ImprimirClick(TObject *Sender)
{
    this->imprimir();
}
//---------------------------------------------------------------------------
void TFPedidosView::searchProduto()
{
	ProdutosController *produtosController = new ProdutosController();
	produtosController->showCrudView(1);
}
//---------------------------------------------------------------------------
void TFPedidosView::searchCliente()
{
	ClientesController *clientesController = new ClientesController();
	clientesController->showCrudView(1);
}
//---------------------------------------------------------------------------
void __fastcall TFPedidosView::RemoveProductClick(TObject *Sender)
{
    this->searchCliente();
}
//---------------------------------------------------------------------------
void __fastcall TFPedidosView::BuscarProduto1Click(TObject *Sender)
{
    this->searchProduto();
}
//---------------------------------------------------------------------------

void __fastcall TFPedidosView::BuscarCliente1Click(TObject *Sender)
{
    this->searchCliente();
}
//---------------------------------------------------------------------------

void __fastcall TFPedidosView::Imprimir1Click(TObject *Sender)
{
	this->imprimir();
}
//---------------------------------------------------------------------------


void __fastcall TFPedidosView::Sair1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFPedidosView::frxReport1GetValue(const UnicodeString VarName, Variant &Value)

{
	 if(VarName == "item")
		Value = StringGridProdutos->Cells[0][frxUserDataSet1->RecNo + 1];
	 else if(VarName == "codbarras")
		Value = StringGridProdutos->Cells[1][frxUserDataSet1->RecNo + 1];
	 else if(VarName == "nome")
		Value = StringGridProdutos->Cells[2][frxUserDataSet1->RecNo + 1];
	 else if(VarName == "unidade")
		Value = StringGridProdutos->Cells[3][frxUserDataSet1->RecNo + 1];
	 else if(VarName == "marca")
		Value = StringGridProdutos->Cells[4][frxUserDataSet1->RecNo + 1];
	 else if(VarName == "quantidade")
		Value = StringGridProdutos->Cells[5][frxUserDataSet1->RecNo + 1];
	 else if(VarName == "desconto")
		Value = StringGridProdutos->Cells[6][frxUserDataSet1->RecNo + 1];
	 else if(VarName == "unitario")
		Value = StringGridProdutos->Cells[7][frxUserDataSet1->RecNo + 1];
	 else if(VarName == "total")
		Value = StringGridProdutos->Cells[8][frxUserDataSet1->RecNo + 1];
	 else if(VarName == "valor_total")
		Value = FormatFloat("#,###,###,##0.00", pedido->valor);
	 else if(VarName == "data")
		Value = pedido->created_at;
	 else if(VarName == "numero")
		Value = pedido->id;
	 else if(VarName == "validade")
		Value = IntToStr(SISTEMA->configuracao->config_pedido->validade) + " dias";
	 else if(VarName == "cliente")
		Value = pedido->cliente->nome;
	 else if(VarName == "cpf_cnpj")
	 {
		if(pedido->cliente->tipo == 0)
			Value = "CPF: " + pedido->cliente->cpf_cnpj;
		else if(pedido->cliente->tipo == 1)
			Value = "CNPJ: " + pedido->cliente->cpf_cnpj;
	 }
	 else if(VarName == "telefone")
		Value = pedido->cliente->telefone_comercial;
	 else if(VarName == "celular")
		Value = pedido->cliente->telefone_celular;
	 else if(VarName == "email")
		Value = pedido->cliente->email;
	 else if(VarName == "ie")
		Value = pedido->cliente->ie;
	 else if(VarName == "cep")
	 {
		if(pedido->cliente->endereco->Count>0)
		{
            Enderecos *endereco = (Enderecos*)pedido->cliente->endereco->Items[0];
			Value = endereco->cep;
        }
		else
            Value = "";
     }
	 else if(VarName == "logradouro")
	 {
		if(pedido->cliente->endereco->Count>0)
		{
			Enderecos *endereco = (Enderecos*)pedido->cliente->endereco->Items[0];
			Value = endereco->logradouro + ",  " + endereco->numero;
        }
		else
            Value = "";
     }
	 else if(VarName == "regiao")
	 {
		if(pedido->cliente->endereco->Count>0)
		{
			ClientesController *clientesController = new ClientesController();
			Associados *cliente = (Associados*)(clientesController->show(pedido->cliente->id))->Items[0];
			Value = ((Enderecos*)cliente->endereco->Items[0])->regioes->getMunicipioUf();
        }
		else
            Value = "";
	 }
	 else if(VarName == "observacao")
		Value = pedido->observacao;
	 else if(VarName == "empresa")
		Value = SISTEMA->empresa->nome;
	 else if(VarName == "empresa_cnpj")
		Value = "CNPJ: " + SISTEMA->empresa->cpf_cnpj;
	 else if(VarName == "empresa_logradouro")
		Value = SISTEMA->empresa->endereco->logradouro + ",   " + SISTEMA->empresa->endereco->numero;
	 else if(VarName == "empresa_cep")
		Value = SISTEMA->empresa->endereco->cep;
	 else if(VarName == "empresa_ie")
		Value = SISTEMA->empresa->ie;
	 else if(VarName == "empresa_regiao")
		Value = SISTEMA->empresa->endereco->regioes->getMunicipioUf();
	 else if(VarName == "empresa_telefone")
		Value = SISTEMA->empresa->telefone;
	 else if(VarName == "empresa_site")
		Value = SISTEMA->empresa->site;
}
//---------------------------------------------------------------------------

void __fastcall TFPedidosView::frxReport1BeforePrint(TfrxReportComponent *Sender)

{
	if(Sender->Name == "PictureLogo")
	{
		TfrxPictureView *picture = (TfrxPictureView*) Sender;
        picture->Picture->LoadFromFile(GetCurrentDir() + "/images/pedido/print_logo.jpg");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFPedidosView::margem_contribuicaoExecute(TObject *Sender)
{
	if(!LabelContribuicao->Visible)
	{
		LabelContribuicao->Visible = TRUE;
		LabelNfe->Visible = TRUE;
	}
	else
	{
		LabelContribuicao->Visible = FALSE;
		LabelNfe->Visible = FALSE;
    }
}
//---------------------------------------------------------------------------

