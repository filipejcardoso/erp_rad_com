//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GruposAssociadosView.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFGruposAssociadosView *FGruposAssociadosView;
//---------------------------------------------------------------------------
__fastcall TFGruposAssociadosView::TFGruposAssociadosView(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TFGruposAssociadosView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
	ConfigurarForm(this);
	grupos_associado = new GruposAssociados();
	controller = new GruposAssociadosController();
}
//---------------------------------------------------------------------------
void TFGruposAssociadosView::DesignerBotoes()
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
void TFGruposAssociadosView::loadGruposAssociado()
{
	EditNome->Text = grupos_associado->nome;
	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFGruposAssociadosView::loadGruposAssociadoModel()
{
	grupos_associado->nome = EditNome->Text;
}
//---------------------------------------------------------------------------
void TFGruposAssociadosView::loadClearFields()
{
	EditNome->Clear();

	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFGruposAssociadosView::loadView()
{
	DesignerBotoes();

	if(editar)
		loadGruposAssociado();
	else
	{
		grupos_associado = new GruposAssociados();
		loadClearFields();
    }
}
void __fastcall TFGruposAssociadosView::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------

void __fastcall TFGruposAssociadosView::SairClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFGruposAssociadosView::AdicionarClick(TObject *Sender)
{
	this->loadGruposAssociadoModel();
	Result *result = controller->store(grupos_associado);

	if(result->code == 201)
		Close();
}
//---------------------------------------------------------------------------

void __fastcall TFGruposAssociadosView::DeletarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja remover?",L"Remover Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		Result *result = controller->destroy(grupos_associado);

		if(result->code == 200)
			Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFGruposAssociadosView::ModificarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		this->loadGruposAssociadoModel();
		Result *result = controller->update(grupos_associado);

		if(result->code == 202)
			Close();
	}
}
//---------------------------------------------------------------------------

