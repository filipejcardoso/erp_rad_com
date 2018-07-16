//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UsuariosView.h"
#include "Principal.h"
#include "UsuariosDAO.h"
#include "PapelsDAO.h"
#include "Papels.h"
#include "PapelsController.h"
#include "Style.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFUsuariosView *FUsuariosView;
//---------------------------------------------------------------------------
__fastcall TFUsuariosView::TFUsuariosView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFUsuariosView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);

	controller = new UsuariosController();
	usuario = new User();
}
//---------------------------------------------------------------------------
void __fastcall TFUsuariosView::FormShow(TObject *Sender)
{
	//STYLE DO FORM
	Style::setTop(LabelCabecalhoTitulo, LabelCabecalhoSubTitulo, LabelCabecalhoModulo, "Usuário Detalhado");

	loadView();
}
//---------------------------------------------------------------------------
void TFUsuariosView::loadView()
{
	DesignerBotoes();
	loadClearFields();

	if(editar)
		loadUsuario();
}
//---------------------------------------------------------------------------
void TFUsuariosView::loadClearFields()
{
	loadComboPapels();

	this->EditPassword->Clear();
	this->NameEdit->Clear();
	this->EditUserName->Clear();
	this->EditEmail->Clear();
}
//---------------------------------------------------------------------------
void TFUsuariosView::loadUsuario()
{
	usuario = (User*) controller->show(usuario->id)->Items[0];

	setComboPapels();

	this->NameEdit->Text = usuario->nome;
	this->EditUserName->Text = usuario->username;
	this->EditEmail->Text = usuario->email;
    this->EditPassword->Text = usuario->password;
}
//---------------------------------------------------------------------------
void TFUsuariosView::setComboPapels()
{
	int index = 0;

	for (int i=0;i<PapelCombo->Items->Count; i++)
	{
		Papels *papel = ((Papels*)PapelCombo->Items[0].Objects[i]);

		if(usuario->papel_id == papel->id)
		{
			index = i;
            break;
        }
	}

    PapelCombo->ItemIndex = index;
}
//---------------------------------------------------------------------------
void TFUsuariosView::loadComboPapels()
{
	TList *papels = new TList();

	this->PapelCombo->Clear();

	papels = FPapelsDAO->index("");

	for (int i = 0; i<papels->Count; i++)
	{
		Papels *papel = (Papels*) papels->Items[i];

		this->PapelCombo->AddItem(papel->nome, papel);
	}

    this->PapelCombo->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFUsuariosView::SairClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFUsuariosView::DeletarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja remover?",L"Remover Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		result = new Result();

		result = controller->destroy(usuario);
		if (result->code == 200)
			Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFUsuariosView::AdicionarClick(TObject *Sender)
{
	int index;
	
	result = new Result();

	this->loadUsuarioModel();

	result = controller->store(usuario);

	if(result->code == 201)
	{
		Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFUsuariosView::ModificarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		result = new Result();

		this->loadUsuarioModel();

		result = controller->update(usuario);

		if(result->code == 202)
			Close();
	}
}
//---------------------------------------------------------------------------
void TFUsuariosView::loadUsuarioModel()
{
	usuario->nome = this->NameEdit->Text;
	usuario->username = this->EditUserName->Text;
	usuario->email = this->EditEmail->Text;

	usuario->papel_id = ((Papels*)PapelCombo->Items[0].Objects[PapelCombo->ItemIndex])->id;

	if(EditPassword->Text.Trim() != "")
		usuario->password = this->EditPassword->Text;
}
//---------------------------------------------------------------------------
void TFUsuariosView::DesignerBotoes()
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


void __fastcall TFUsuariosView::EditPasswordClick(TObject *Sender)
{
    if(EditPassword->Text.Length()>20)
	    EditPassword->Clear();
}
//---------------------------------------------------------------------------

