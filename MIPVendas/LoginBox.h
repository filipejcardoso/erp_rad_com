//---------------------------------------------------------------------------

#ifndef LoginBoxH
#define LoginBoxH
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
#include "User.h"
#include "AuthController.h"
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFLoginBox : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *PanelTopo;
	TLabel *LabelCabecalhoTitulo;
	TLabel *LabelCabecalhoSubTitulo;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TEdit *EditUsuario;
	TLabel *Label2;
	TEdit *EditSenha;
	TComboBox *ComboHost;
	TLabel *Label4;
	TButton *ButtonIniciar;
	TButton *ButtonCancelar;
	TImage *Image1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonCancelarClick(TObject *Sender);
	void __fastcall ButtonIniciarClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ComboHostChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:
	int login;

	TList* loadAPI();
	void loadComboHost();
	void loadView();
	User* loadUser();
public:
    AuthController *controller;
	__fastcall TFLoginBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFLoginBox *FLoginBox;
//---------------------------------------------------------------------------
#endif
