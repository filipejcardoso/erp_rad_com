//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MarcasView.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFMarcasView *FMarcasView;
//---------------------------------------------------------------------------
__fastcall TFMarcasView::TFMarcasView(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TFMarcasView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
	ConfigurarForm(this);
	marca = new Marcas();
	controller = new MarcasController();
}
//---------------------------------------------------------------------------
void TFMarcasView::DesignerBotoes()
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
//---------------------------------------------------------------------------
void TFMarcasView::loadMarca()
{
	EditNome->Text = marca->descricao;
	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFMarcasView::loadMarcaModel()
{
	marca->descricao = EditNome->Text;
}
//---------------------------------------------------------------------------
void TFMarcasView::loadClearFields()
{
	EditNome->Clear();

	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFMarcasView::loadView()
{
	DesignerBotoes();

	if(editar)
		loadMarca();
	else
	{
		marca = new Marcas();
		loadClearFields();
    }
}
void __fastcall TFMarcasView::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------

void __fastcall TFMarcasView::SairClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFMarcasView::AdicionarClick(TObject *Sender)
{
	this->loadMarcaModel();
	Result *result = controller->store(marca);

	if(result->code == 201)
		Close();
}
//---------------------------------------------------------------------------

void __fastcall TFMarcasView::DeletarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja remover?",L"Remover Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		Result *result = controller->destroy(marca);

		if(result->code == 200)
			Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFMarcasView::ModificarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		this->loadMarcaModel();
		Result *result = controller->update(marca);

		if(result->code == 202)
			Close();
	}
}
//---------------------------------------------------------------------------

