//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LiberarAcesso.h"
#include "PedidosView.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFLiberarAcesso *FLiberarAcesso;
//---------------------------------------------------------------------------
__fastcall TFLiberarAcesso::TFLiberarAcesso(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFLiberarAcesso::FormShow(TObject *Sender)
{
	acesso = 0;
	EditUsuario->Clear();
	EditSenha->Clear();
	EditUsuario->SetFocus();
}
//---------------------------------------------------------------------------

int TFLiberarAcesso::GetAcesso()
{
	return acesso;
}
void __fastcall TFLiberarAcesso::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);

	SQLQuery1->SQLConnection = SQLCONNECT;
}
//---------------------------------------------------------------------------

void __fastcall TFLiberarAcesso::ButtonCancelarClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

