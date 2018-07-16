//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TiposContatosView.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFTiposContatosView *FTiposContatosView;
//---------------------------------------------------------------------------
__fastcall TFTiposContatosView::TFTiposContatosView(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TFTiposContatosView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
	ConfigurarForm(this);
	tipos_contato = new TiposContatos();
	controller = new TiposContatosController();
}
//---------------------------------------------------------------------------
void TFTiposContatosView::DesignerBotoes()
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
void TFTiposContatosView::loadTiposContato()
{
	EditNome->Text = tipos_contato->nome;
	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFTiposContatosView::loadTiposContatoModel()
{
	tipos_contato->nome = EditNome->Text;
}
//---------------------------------------------------------------------------
void TFTiposContatosView::loadClearFields()
{
	EditNome->Clear();

	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFTiposContatosView::loadView()
{
	DesignerBotoes();

	if(editar)
		loadTiposContato();
	else
	{
		tipos_contato = new TiposContatos();
		loadClearFields();
    }
}
void __fastcall TFTiposContatosView::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------

void __fastcall TFTiposContatosView::SairClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFTiposContatosView::AdicionarClick(TObject *Sender)
{
	this->loadTiposContatoModel();
	Result *result = controller->store(tipos_contato);

	if(result->code == 201)
		Close();
}
//---------------------------------------------------------------------------

void __fastcall TFTiposContatosView::DeletarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja remover?",L"Remover Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		Result *result = controller->destroy(tipos_contato);

		if(result->code == 200)
			Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFTiposContatosView::ModificarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		this->loadTiposContatoModel();
		Result *result = controller->update(tipos_contato);

		if(result->code == 202)
			Close();
	}
}
//---------------------------------------------------------------------------

