//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GrupoRecursosView.h"
#include "PapeisView.h"
#include "Recursos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFGrupoRecursos *FGrupoRecursos;
//---------------------------------------------------------------------------
__fastcall TFGrupoRecursos::TFGrupoRecursos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFGrupoRecursos::SairClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFGrupoRecursos::FormClose(TObject *Sender, TCloseAction &Action)
{
	this->ReadCheckBox->Checked = false;
	this->CreateCheckBox->Checked = false;
	this->UpdateCheckBox->Checked = false;
	this->DeleteCheckBox->Checked = false;
}
//---------------------------------------------------------------------------
void __fastcall TFGrupoRecursos::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------
void TFGrupoRecursos::loadView()
{
	int a;
}
//---------------------------------------------------------------------------
