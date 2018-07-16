//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LojasView.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFLojasView *FLojasView;
//---------------------------------------------------------------------------
__fastcall TFLojasView::TFLojasView(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TFLojasView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
	ConfigurarForm(this);
	loja = new Lojas();
	controller = new LojasController();
}
//---------------------------------------------------------------------------
void TFLojasView::DesignerBotoes()
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
void TFLojasView::loadLoja()
{
	EditNome->Text = loja->nome;
	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFLojasView::loadLojaModel()
{
	loja->nome = EditNome->Text;
}
//---------------------------------------------------------------------------
void TFLojasView::loadClearFields()
{
	EditNome->Clear();

	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFLojasView::loadView()
{
	DesignerBotoes();

	if(editar)
		loadLoja();
	else
	{
		loja = new Lojas();
		loadClearFields();
    }
}
void __fastcall TFLojasView::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------

void __fastcall TFLojasView::SairClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFLojasView::AdicionarClick(TObject *Sender)
{
	this->loadLojaModel();
	Result *result = controller->store(loja);

	if(result->code == 201)
		Close();
}
//---------------------------------------------------------------------------

void __fastcall TFLojasView::DeletarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja remover?",L"Remover Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		Result *result = controller->destroy(loja);

		if(result->code == 200)
			Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFLojasView::ModificarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		this->loadLojaModel();
		Result *result = controller->update(loja);

		if(result->code == 202)
			Close();
	}
}
//---------------------------------------------------------------------------

