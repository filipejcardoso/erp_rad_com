//---------------------------------------------------------------------------

#ifndef LiberarAcessoH
#define LiberarAcessoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFLiberarAcesso : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TImage *Image1;
	TEdit *EditUsuario;
	TEdit *EditSenha;
	TButton *ButtonLiberar;
	TButton *ButtonCancelar;
	TSQLQuery *SQLQuery1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonCancelarClick(TObject *Sender);
private:
	int acesso;
public:
	int GetAcesso();
	__fastcall TFLiberarAcesso(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFLiberarAcesso *FLiberarAcesso;
//---------------------------------------------------------------------------
#endif
