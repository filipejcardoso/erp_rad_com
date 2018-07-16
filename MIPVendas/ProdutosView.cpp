//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProdutosView.h"
#include "Principal.h"
#include "InformacoesProduto.h"
#include "Marcas.h"
#include "MarcasDAO.h"
#include "UnidadesMedidas.h"
#include "UnidadesMedidasDAO.h"
#include "Categorias.h"
#include "CategoriasDAO.h"
#include "Lojas.h"
#include "LojasDAO.h"
#include "Subcategorias.h"
#include "SubcategoriasDAO.h"
#include "Result.h"
#include "HttpMessage.h"
#include "Style.h"
#include "MarcasView.h"
#include "UnidadesMedidasView.h"
#include "CategoriasView.h"
#include "LojasView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)                                     8
#pragma resource "*.dfm"
TFProdutosView *FProdutosView;
//---------------------------------------------------------------------------
__fastcall TFProdutosView::TFProdutosView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFProdutosView::loadComboMarcas()
{
	int key = 0;
	TList *marcas;

	this->ComboMarcas->Clear();

	marcas = FMarcasDAO->index("");

	for(int i=0;i<marcas->Count;i++)
	{
		Marcas *marca = (Marcas*) marcas->Items[i];

		this->ComboMarcas->AddItem(marca->descricao, marca);
	}

	this->ComboMarcas->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::loadComboLojas()
{
	int key = 0;
	TList *lojas;

	this->ComboLojas->Clear();

	lojas = FLojasDAO->index("");

	for(int i=0;i<lojas->Count;i++)
	{
		Lojas *loja = (Lojas*) lojas->Items[i];

		this->ComboLojas->AddItem(loja->nome, loja);
	}

	this->ComboLojas->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::loadComboCategorias()
{
	int key = 0;
	TList *categorias;

	this->ComboCategorias->Clear();

	categorias = FCategoriasDAO->index("");

	for(int i=0;i<categorias->Count;i++)
	{
		Categorias *categoria = (Categorias*) categorias->Items[i];

		this->ComboCategorias->AddItem(categoria->nome, categoria);
    }

	this->ComboCategorias->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::loadComboSubcategorias()
{
	int key = 0;
	int categoria;
    int index;
	TList *subcategorias;

    index = ComboCategorias->ItemIndex;
	categoria = ((Categorias*)ComboCategorias->Items[0].Objects[index])->id;

	this->ComboSubcategorias->Clear();

	subcategorias = FSubcategoriasDAO->index("", categoria);

	for(int i=0;i<subcategorias->Count;i++)
	{
		Subcategorias *subcategoria = (Subcategorias*) subcategorias->Items[i];

		this->ComboSubcategorias->AddItem(subcategoria->nome, subcategoria);
	}

	this->ComboSubcategorias->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::loadComboUnidadesMedidas()
{
	int key = 0;
	TList *unidades_medidas;

	this->ComboUnidadesMedidas->Clear();

	unidades_medidas = FUnidadesMedidasDAO->index("");

	for(int i=0;i<unidades_medidas->Count;i++)
	{
		UnidadesMedidas *unidades_medida = (UnidadesMedidas*) unidades_medidas->Items[i];

		this->ComboUnidadesMedidas->AddItem(unidades_medida->descricao, unidades_medida);
    }

	this->ComboUnidadesMedidas->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::setComboMarcas()
{
	int key = 0;

	for(int i=0;ComboMarcas->Items->Count;i++)
	{
		Marcas *marca = (Marcas*) ComboMarcas->Items[0].Objects[i];

		if(marca->id == produto->marca->id)
		{
			key = i;
			break;
		}
	}

	this->ComboMarcas->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::setComboLojas()
{
	int key = 0;

	for(int i=0;ComboLojas->Items->Count;i++)
	{
		Lojas *loja = (Lojas*) ComboLojas->Items[0].Objects[i];

		if(loja->id == produto->loja->id)
		{
			key = i;
			break;
		}
	}

	this->ComboLojas->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::setComboCategorias()
{
	int key = 0;

	for(int i=0;ComboCategorias->Items->Count;i++)
	{
		Categorias *categoria = (Categorias*) ComboCategorias->Items[0].Objects[i];

		if(categoria->id == produto->subcategoria->categoria_id)
		{
			key = i;
			break;
		}
	}

	this->ComboCategorias->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::setComboSubcategorias()
{
	int key = 0;

	for(int i=0;ComboSubcategorias->Items->Count;i++)
	{
		Subcategorias *subcategoria = (Subcategorias*) ComboSubcategorias->Items[0].Objects[i];

		if(subcategoria->id == produto->subcategoria->id)
		{
			key = i;
			break;
		}

	}

	this->ComboSubcategorias->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::setComboUnidadesMedidas()
{
	int key = 0;

	for(int i=0;ComboUnidadesMedidas->Items->Count;i++)
	{
		UnidadesMedidas *unidades_medida = (UnidadesMedidas*) ComboUnidadesMedidas->Items[0].Objects[i];

		if(unidades_medida->id == produto->unidades_medida->id)
		{
			key = i;
			break;
		}
	}

	this->ComboUnidadesMedidas->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::maxComboMarcas()
{
	int key = 0;
    int max = 0;

	for(int i=0;ComboMarcas->Items->Count>i;i++)
	{
		Marcas *marca = (Marcas*) ComboMarcas->Items[0].Objects[i];

		if(marca->id > max)
        {
			max = marca->id;
			key = i;
		}
	}

	this->ComboMarcas->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::maxComboLojas()
{
	int key = 0;
    int max = 0;

	for(int i=0;ComboLojas->Items->Count>i;i++)
	{
		Lojas *loja = (Lojas*) ComboLojas->Items[0].Objects[i];

		if(loja->id > max)
        {
			max = loja->id;
			key = i;
		}
	}

	this->ComboLojas->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::maxComboCategorias()
{
	int key = 0;
    int max = 0;

	for(int i=0;ComboCategorias->Items->Count>i;i++)
	{
		Categorias *categoria = (Categorias*) ComboCategorias->Items[0].Objects[i];

		if(categoria->id > max)
        {
			max = categoria->id;
			key = i;
		}
	}

	this->ComboCategorias->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::maxComboSubcategorias()
{
	int key = 0;
    int max = 0;

	for(int i=0;ComboSubcategorias->Items->Count>i;i++)
	{
		Subcategorias *subcategoria = (Subcategorias*) ComboSubcategorias->Items[0].Objects[i];

		if(subcategoria->id > max)
        {
			max = subcategoria->id;
			key = i;
		}
	}

	this->ComboSubcategorias->ItemIndex = key;
}
//---------------------------------------------------------------------------
void TFProdutosView::maxComboUnidadesMedidas()
{
	int key = 0;
    int max = 0;

	for(int i=0;ComboUnidadesMedidas->Items->Count>i;i++)
	{
		UnidadesMedidas *unidades_medida = (UnidadesMedidas*) ComboUnidadesMedidas->Items[0].Objects[i];

		if(unidades_medida->id > max)
		{
            max = unidades_medida->id;
			key = i;
		}
	}

	this->ComboUnidadesMedidas->ItemIndex = key;
}
//---------------------------------------------------------------------------
void __fastcall TFProdutosView::FormShow(TObject *Sender)
{
	//STYLE DO FORM
	Style::setTop(LabelCabecalhoTitulo, LabelCabecalhoSubTitulo, LabelCabecalhoModulo, "Produto Detalhado");

	loadView();
}
//---------------------------------------------------------------------------
void TFProdutosView::loadView()
{
	DesignerBotoes();

	if(editar)
	{
		loadProduto();
	    setLucro();
	}
	else
		loadClearFields();

}
//---------------------------------------------------------------------------
void TFProdutosView::loadProduto()
{
	produto = (Produtos*) controller->show(produto->id)->Items[0];

	loadClearFields();

	setComboMarcas();
	setComboLojas();
	setComboCategorias();
	loadComboSubcategorias();
	setComboSubcategorias();
	setComboUnidadesMedidas();

	this->EditNome->Text = produto->nome;
	this->EditCodbarras->Text = produto->codbarras;
	this->EditPrecoCompra->Text = FormatFloat("#,###,###,##0.00", produto->preco_compra);
	this->EditPrecoVenda->Text = FormatFloat("#,###,###,##0.00", produto->preco_venda);

	this->EditQuantidade->Text = produto->estoque->quantidade;
	this->EditProdutosEstoqueArea->Text = produto->estoque->area;
	this->EditProdutosEstoqueRua->Text = produto->estoque->rua;
	this->EditProdutosEstoqueModulo->Text = produto->estoque->modulo;
	this->EditProdutosEstoqueNivel->Text = produto->estoque->nivel;
	this->EditProdutosEstoqueVao->Text = produto->estoque->vao;

	this->EditProdutosDimensoesPeso->Text = produto->dimensao->peso;
	this->EditProdutosDimensoesLargura->Text = produto->dimensao->largura;
	this->EditProdutosDimensoesComprimento->Text = produto->dimensao->comprimento;
	this->EditProdutosDimensoesAltura->Text = produto->dimensao->altura;
	this->EditProdutosDimensoesDiametro->Text = produto->dimensao->diametro;

	this->EditNcm->Text = produto->dados_fiscal->ncm;
	this->EditCfop->Text = produto->dados_fiscal->cfop;
}
//---------------------------------------------------------------------------
void TFProdutosView::loadClearFields()
{
	this->EditNome->Clear();
	this->EditCodbarras->Clear();
	this->EditPrecoCompra->Clear();
	this->EditPrecoVenda->Clear();

	this->EditQuantidade->Clear();
	this->EditProdutosEstoqueArea->Clear();
	this->EditProdutosEstoqueRua->Clear();
	this->EditProdutosEstoqueModulo->Clear();
	this->EditProdutosEstoqueNivel->Clear();
	this->EditProdutosEstoqueVao->Clear();

	this->EditProdutosDimensoesPeso->Clear();
	this->EditProdutosDimensoesLargura->Clear();
	this->EditProdutosDimensoesComprimento->Clear();
	this->EditProdutosDimensoesAltura->Clear();
	this->EditProdutosDimensoesDiametro->Clear();

	this->EditNcm->Clear();
	this->EditCfop->Clear();

	this->EditLucro->Clear();

    this->EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFProdutosView::loadProdutosModel()
{
    int index;
	produto->nome = this->EditNome->Text;
	produto->codbarras = this->EditCodbarras->Text;
	produto->preco_compra = FStrToFloat(this->EditPrecoCompra->Text);
	produto->preco_venda = FStrToFloat(this->EditPrecoVenda->Text);

	index = ComboMarcas->ItemIndex;
	produto->marca->id = ((Marcas*)ComboMarcas->Items[0].Objects[index])->id;

	index = ComboLojas->ItemIndex;
	produto->loja->id = ((Lojas*)ComboLojas->Items[0].Objects[index])->id;

	index = ComboCategorias->ItemIndex;
	produto->subcategoria->categoria_id = ((Categorias*)ComboCategorias->Items[0].Objects[index])->id;

	index = ComboSubcategorias->ItemIndex;
	produto->subcategoria->id = ((Subcategorias*)ComboSubcategorias->Items[0].Objects[index])->id;

	index = ComboUnidadesMedidas->ItemIndex;
	produto->unidades_medida->id = ((UnidadesMedidas*)ComboUnidadesMedidas->Items[0].Objects[index])->id;

	produto->estoque->quantidade = FStrToFloat(this->EditQuantidade->Text);
	produto->estoque->area = this->EditProdutosEstoqueArea->Text;
	produto->estoque->rua = this->EditProdutosEstoqueRua->Text;
	produto->estoque->modulo = this->EditProdutosEstoqueModulo->Text;
	produto->estoque->nivel = this->EditProdutosEstoqueNivel->Text;
	produto->estoque->vao = this->EditProdutosEstoqueVao->Text;

	produto->dimensao->peso = FStrToFloat(this->EditProdutosDimensoesPeso->Text);
	produto->dimensao->largura = FStrToFloat(this->EditProdutosDimensoesLargura->Text);
	produto->dimensao->comprimento = FStrToFloat(this->EditProdutosDimensoesComprimento->Text);
	produto->dimensao->altura = FStrToFloat(this->EditProdutosDimensoesAltura->Text);
	produto->dimensao->diametro = FStrToFloat(this->EditProdutosDimensoesDiametro->Text);

	produto->dados_fiscal->ncm = this->EditNcm->Text;
	produto->dados_fiscal->cfop = this->EditCfop->Text;
}
//---------------------------------------------------------------------------
void TFProdutosView::DesignerBotoes()
{
	Adicionar->Top = 10;
	Adicionar->Left = 25;

	Modificar->Top = 10;
	Modificar->Left = 25;

	Deletar->Top = 10;
	Deletar->Left = 160;

	if(editar == 0)
	{
		Adicionar->Visible = TRUE;

		Modificar->Visible = FALSE;

		Deletar->Visible = FALSE;
	}
	else if(editar == 1)
	{
		Adicionar->Visible = FALSE;

		Modificar->Visible = TRUE;

		Deletar->Visible = TRUE;
	}
	else if(editar == 2)
	{
		Adicionar->Visible = FALSE;

		Modificar->Visible = FALSE;

		Deletar->Visible = FALSE;
	}
}

void __fastcall TFProdutosView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);

	controller = new ProdutosController();
    produto = new Produtos();
}


void __fastcall TFProdutosView::ComboCategoriasChange(TObject *Sender)
{
	this->loadComboSubcategorias();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::SairClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void TFProdutosView::setPrecoVenda()
{
	float pc,pv,lucro;

	pc = FStrToFloat(EditPrecoCompra->Text);
	lucro = FStrToFloat(EditLucro->Text);

	pv = pc*(1 + lucro/100);

	EditPrecoVenda->Text = FormatFloat("#,###,###,##0.00", pv);
}
//---------------------------------------------------------------------------
void TFProdutosView::setLucro()
{
	float pc,pv,lucro;

	pc = FStrToFloat(EditPrecoCompra->Text);
	pv = FStrToFloat(EditPrecoVenda->Text);

	if(pc != 0)
		lucro = (pv/pc - 1)*100;
	else
		lucro = 0;

	EditLucro->Text = FormatFloat("#,###,###,##0.00", lucro);
}

void __fastcall TFProdutosView::EditLucroKeyPress(TObject *Sender, System::WideChar &Key)

{
	setPrecoVenda();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::EditLucroKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	setPrecoVenda();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::EditLucroKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	setPrecoVenda();
}
//---------------------------------------------------------------------------
void __fastcall TFProdutosView::EditPrecoCompraKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	setPrecoVenda();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::EditPrecoCompraKeyPress(TObject *Sender, System::WideChar &Key)

{
	setPrecoVenda();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::EditPrecoCompraKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	setPrecoVenda();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::EditPrecoVendaKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	setLucro();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::EditPrecoVendaKeyPress(TObject *Sender, System::WideChar &Key)

{
	setLucro();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::EditPrecoVendaKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	setLucro();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::AdicionarClick(TObject *Sender)
{
    this->loadProdutosModel();
	Result *result = controller->store(produto);

	if(result->code == 201)
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::DeletarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja remover?",L"Remover Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		Result *result = controller->destroy(produto);

		if(result->code == 200)
			Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::ModificarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		this->loadProdutosModel();
		Result *result = controller->update(produto);

		if(result->code == 202)
			Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TFProdutosView::RecursosThreadTimer(TObject *Sender)
{
	RecursosThread->Enabled = FALSE;
	loadComboMarcas();
	loadComboLojas();
	loadComboCategorias();
	loadComboSubcategorias();
	loadComboUnidadesMedidas();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::BtInsertClick(TObject *Sender)
{
	FMarcasView->editar = 0;
	FMarcasView->ShowModal();
	loadComboMarcas();
	maxComboMarcas();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::SpeedButton1Click(TObject *Sender)
{
	FUnidadesMedidasView->editar = 0;
	FUnidadesMedidasView->ShowModal();
	loadComboUnidadesMedidas();
	maxComboUnidadesMedidas();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::SpeedButton2Click(TObject *Sender)
{
	FLojasView->editar = 0;
	FLojasView->ShowModal();
	loadComboLojas();
	maxComboLojas();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::SpeedButton3Click(TObject *Sender)
{
	FCategoriasView->editar = 0;
	FCategoriasView->ShowModal();
	loadComboCategorias();
	maxComboCategorias();
}
//---------------------------------------------------------------------------

void __fastcall TFProdutosView::SpeedButton4Click(TObject *Sender)
{
	Categorias *categoria = (Categorias*)ComboCategorias->Items[0].Objects[ComboCategorias->ItemIndex];

	FCategoriasView->editar = 1;
	FCategoriasView->categoria->id = categoria->id;
	FCategoriasView->ShowModal();
	loadComboSubcategorias();
	maxComboSubcategorias();
}
//---------------------------------------------------------------------------

