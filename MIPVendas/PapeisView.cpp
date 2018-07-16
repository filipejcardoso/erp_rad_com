//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PapeisView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFPapeisView *FPapeisView;
//---------------------------------------------------------------------------
__fastcall TFPapeisView::TFPapeisView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFPapeisView::FormCreate(TObject *Sender)
{
	//recursoController = new RecursosController();
	papelController = new PapelsController();
	aux = new RecursosGrupoPapelsController();
	papel = new Papels();
}
//---------------------------------------------------------------------------
void __fastcall TFPapeisView::BtAddClick(TObject *Sender)
{
	auxiliar = aux->createAuxTable();
	auxiliar->papels_id = papel->id;

	loadGruposRecursos();
}
//---------------------------------------------------------------------------
void __fastcall TFPapeisView::SairClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFPapeisView::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------
void TFPapeisView::loadView()
{
	papel = papelController->createPapel();

	loadGruposRecursos();
}
//---------------------------------------------------------------------------
void TFPapeisView::loadGruposRecursos()
{
	int a;
}
//---------------------------------------------------------------------------
