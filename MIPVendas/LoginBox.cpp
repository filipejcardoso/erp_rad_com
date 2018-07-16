//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoginBox.h"
#include "Principal.h"
#include "APIRest.h"
#include "Sistema.h"
#include "AuthDAO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFLoginBox *FLoginBox;
//---------------------------------------------------------------------------
__fastcall TFLoginBox::TFLoginBox(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFLoginBox::loadComboHost()
{
	TList *listAPI = loadAPI();

	ComboHost->Clear();

	for(int i=0;i<listAPI->Count;i++)
	{
		APIRest *api = (APIRest*) listAPI->Items[i];
		ComboHost->AddItem(api->nome, api);

		if(!i)
			SISTEMA->api = api;
	}

	ComboHost->ItemIndex = 0;
}
//---------------------------------------------------------------------------
TList* TFLoginBox::loadAPI()
{
	TIniFile *config = NULL;
	int count_api;
	TList *listAPI = new TList();

	//CARREGA COMBOBOX
	config = new TIniFile(GetCurrentDir()+"\\api.ini");
	count_api = StrToInt(config->ReadString("GERAL","API",""));

	for(int i=1;i<=count_api;i++)
	{
		APIRest *api = new APIRest();

		api->nome = config->ReadString("API"+IntToStr(i),"NOME","");
		api->host = config->ReadString("API"+IntToStr(i),"HOST","");
		api->version = config->ReadString("API"+IntToStr(i),"VERSION","");
		api->background = config->ReadString("API"+IntToStr(i),"BACKGROUND","");

		listAPI->Add((APIRest*) api);
	}

    return listAPI;
}
//-------------------------------------
void TFLoginBox::loadView()
{
	login = 0;

	EditUsuario->Clear();
	EditSenha->Clear();
	loadComboHost();
	FPrincipal->AtualizarPlanoFundo();

	EditUsuario->SetFocus();
}
void __fastcall TFLoginBox::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------

void __fastcall TFLoginBox::ButtonCancelarClick(TObject *Sender)
{
	exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TFLoginBox::ButtonIniciarClick(TObject *Sender)
{
	Application->ProcessMessages();
	if(controller->login(this->loadUser()))
	{
		login = 1;

		FPrincipal->BarraStatus->Panels->Items[0]->Text = "Usuário: " + SISTEMA->usuario->nome;
		FPrincipal->BarraStatus->Panels->Items[1]->Text = ComboHost->Text;

		Close();
	}
    else
		MessageBox(NULL,L"Login ou senha incorreto",L"Falha no Login",MB_OK | MB_ICONERROR);

	ButtonIniciar->Enabled = TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TFLoginBox::FormClose(TObject *Sender, TCloseAction &Action)
{
	if(!login)
		exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TFLoginBox::ComboHostChange(TObject *Sender)
{
	int index = this->ComboHost->ItemIndex;

	SISTEMA->api = (APIRest*) this->ComboHost->Items[0].Objects[index];

	FPrincipal->AtualizarPlanoFundo();
}
//---------------------------------------------------------------------------

User* TFLoginBox::loadUser()
{
	User *usuario = new User();

//	usuario->username = this->EditUsuario->Text;
//	usuario->password = this->EditSenha->Text;

	usuario->username = "admin";
	usuario->password = "admin";

	return usuario;
}
void __fastcall TFLoginBox::FormCreate(TObject *Sender)
{
    controller = new AuthController();
}
//---------------------------------------------------------------------------

