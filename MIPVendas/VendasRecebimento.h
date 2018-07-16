//---------------------------------------------------------------------------

#ifndef VendasRecebimentoH
#define VendasRecebimentoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFVendasRecebimento : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelTopo;
	TLabel *LabelTitulo;
	TLabel *Label7;
	TEdit *EditValorRestante;
	TButton *ButtonCancelar;
	TButton *ButtonReceber;
	TEdit *EditTroco;
	TEdit *EditValorCliente;
	TLabel *LabelValorCliente;
	TLabel *Label2;
	TLabel *LabelTroco;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonCancelarClick(TObject *Sender);
	void __fastcall ButtonReceberClick(TObject *Sender);
	void __fastcall EditValorClienteKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall EditValorClienteKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditValorClienteKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);



private:
	void Designer();
	void CalcularTroco();
public:
	int modpagar;//0-dinheiro 1-cartao 2-cheque 3-carteira 4-vale
	__fastcall TFVendasRecebimento(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFVendasRecebimento *FVendasRecebimento;
//---------------------------------------------------------------------------
#endif
