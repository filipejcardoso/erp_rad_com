//---------------------------------------------------------------------------

#ifndef ConfiguracoesViewH
#define ConfiguracoesViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
#include "ConfiguracoesController.h"
#include "Configuracoes.h"
#include "GridHelper.h"
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFConfiguracoesView : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelOptions;
	TSpeedButton *Modificar;
	TSpeedButton *Sair;
	TPageControl *PageControl1;
	TTabSheet *TabDados;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TEdit *EditValidade;
	TLabel *Label2;
	TComboBox *ComboClientePadrao;
	TImage *ImageLogo;
	TOpenDialog *OpenDialog1;
	TSpeedButton *BtSearch;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SairClick(TObject *Sender);
	void __fastcall ModificarClick(TObject *Sender);
	void __fastcall BtSearchClick(TObject *Sender);
private:
    UnicodeString printLogo;
	void loadConfiguracoes();
	void loadConfiguracoesModel();
	void loadView();

	void loadComboClientePadrao();

public:
	Configuracoes *configuracao;
    ConfiguracoesController *controller;
	__fastcall TFConfiguracoesView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFConfiguracoesView *FConfiguracoesView;
//---------------------------------------------------------------------------
#endif
