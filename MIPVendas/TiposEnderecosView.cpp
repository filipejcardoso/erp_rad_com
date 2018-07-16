//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TiposEnderecosView.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFTiposEnderecosView *FTiposEnderecosView;
//---------------------------------------------------------------------------
__fastcall TFTiposEnderecosView::TFTiposEnderecosView(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TFTiposEnderecosView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
	ConfigurarForm(this);
	tipos_endereco = new TiposEnderecos();
	controller = new TiposEnderecosController();
}
//---------------------------------------------------------------------------
void TFTiposEnderecosView::DesignerBotoes()
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
void TFTiposEnderecosView::loadTiposEndereco()
{
	EditNome->Text = tipos_endereco->nome;
	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFTiposEnderecosView::loadTiposEnderecoModel()
{
	tipos_endereco->nome = EditNome->Text;
}
//---------------------------------------------------------------------------
void TFTiposEnderecosView::loadClearFields()
{
	EditNome->Clear();

	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFTiposEnderecosView::loadView()
{
	DesignerBotoes();

	if(editar)
		loadTiposEndereco();
	else
	{
		tipos_endereco = new TiposEnderecos();
		loadClearFields();
    }
}
void __fastcall TFTiposEnderecosView::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------

void __fastcall TFTiposEnderecosView::SairClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFTiposEnderecosView::AdicionarClick(TObject *Sender)
{
	this->loadTiposEnderecoModel();
	Result *result = controller->store(tipos_endereco);

	if(result->code == 201)
		Close();
}
//---------------------------------------------------------------------------

void __fastcall TFTiposEnderecosView::DeletarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja remover?",L"Remover Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		Result *result = controller->destroy(tipos_endereco);

		if(result->code == 200)
			Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFTiposEnderecosView::ModificarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		this->loadTiposEnderecoModel();
		Result *result = controller->update(tipos_endereco);

		if(result->code == 202)
			Close();
	}
}
//---------------------------------------------------------------------------

