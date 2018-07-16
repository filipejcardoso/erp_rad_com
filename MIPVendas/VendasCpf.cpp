//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VendasCpf.h"
#include "Principal.h"
#include "Vendas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFVendasCpf *FVendasCpf;
//---------------------------------------------------------------------------
__fastcall TFVendasCpf::TFVendasCpf(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFVendasCpf::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);
}
//---------------------------------------------------------------------------
void __fastcall TFVendasCpf::ButtonCancelarClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFVendasCpf::FormShow(TObject *Sender)
{
	EditCpf->Clear();
	EditCpf->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFVendasCpf::ButtonSalvarClick(TObject *Sender)
{
	FVendas->CPF_CLIENTE = EditCpf->Text;
	Close();
}
//---------------------------------------------------------------------------
