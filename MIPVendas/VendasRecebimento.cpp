//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VendasRecebimento.h"
#include "Principal.h"
#include "Vendas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFVendasRecebimento *FVendasRecebimento;
//---------------------------------------------------------------------------
__fastcall TFVendasRecebimento::TFVendasRecebimento(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFVendasRecebimento::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);
}
//---------------------------------------------------------------------------
void __fastcall TFVendasRecebimento::FormShow(TObject *Sender)
{
	UnicodeString MODO;

	Designer();
	switch(modpagar)
	{
		case 0:
			MODO = "DINHEIRO";
		break;
		case 1:
			MODO = "CARTÃO";
		break;
		case 2:
			MODO = "CHEQUE";
		break;
		case 3:
			MODO = "CARTEIRA";
		break;
		case 4:
			MODO = "VALE";
		break;
	}

	EditValorRestante->Text = FVendas->EditValorRestante->Text;
	EditValorCliente->Text = "";
	EditTroco->Text = "";

	LabelTitulo->Caption = "CAIXA RECEBER ("+MODO+")";

	if(modpagar)
		ButtonReceber->SetFocus();
	else
		EditValorCliente->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFVendasRecebimento::ButtonCancelarClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFVendasRecebimento::ButtonReceberClick(TObject *Sender)
{
	float recebendo,restante;

	restante = FStrToFloat(FVendas->EditValorRestante->Text);
	recebendo = FStrToFloat(EditValorRestante->Text);

	if((recebendo>0 || modpagar==3) && recebendo<=restante)
	{
		FVendas->AdicionarPagamento(modpagar,FStrToFloat(EditValorRestante->Text));

		if(!modpagar)
			FVendas->AbrirGaveta();

		if(recebendo < restante)
			FVendas->GerarGridPagamentos();
		else
			FVendas->ConcluirVenda();

		Close();
	}
	else
		MessageBox(NULL,L"Valor incorreto a ser recebido!",L"Caixa Receber",MB_OK | MB_ICONERROR);
}
//---------------------------------------------------------------------------
void TFVendasRecebimento::Designer()
{
	switch(modpagar)
	{
		case 0:
			LabelValorCliente->Visible = TRUE;
			EditValorCliente->Visible = TRUE;

			LabelTroco->Visible = TRUE;
			EditTroco->Visible = TRUE;

			ButtonCancelar->Top = 455;
			ButtonReceber->Top = 455;

			Height = 555;

		break;
		default:
			LabelValorCliente->Visible = FALSE;
			EditValorCliente->Visible = FALSE;

			LabelTroco->Visible = FALSE;
			EditTroco->Visible = FALSE;

			ButtonCancelar->Top = 250;
			ButtonReceber->Top = 250;

			Height = 355;
		break;
	}
}
//---------------------------------
void TFVendasRecebimento::CalcularTroco()
{
	float valor_receber;
	float valor_cliente;
	float troco;

	valor_receber = FStrToFloat(EditValorRestante->Text);
	valor_cliente = FStrToFloat(EditValorCliente->Text);

	troco = valor_cliente - valor_receber;

	EditTroco->Text = FormatFloat("#,###,###,##0.00",troco);
}
void __fastcall TFVendasRecebimento::EditValorClienteKeyPress(TObject *Sender, System::WideChar &Key)

{
	CalcularTroco();
}
//---------------------------------------------------------------------------

void __fastcall TFVendasRecebimento::EditValorClienteKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	CalcularTroco();
}
//---------------------------------------------------------------------------

void __fastcall TFVendasRecebimento::EditValorClienteKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	CalcularTroco();
}
//---------------------------------------------------------------------------

