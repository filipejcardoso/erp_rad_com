//---------------------------------------------------------------------------

#ifndef VendasCpfH
#define VendasCpfH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFVendasCpf : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelTopo;
	TLabel *LabelTitulo;
	TLabel *Label7;
	TEdit *EditCpf;
	TButton *ButtonCancelar;
	TButton *ButtonSalvar;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonCancelarClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonSalvarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFVendasCpf(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFVendasCpf *FVendasCpf;
//---------------------------------------------------------------------------
#endif
