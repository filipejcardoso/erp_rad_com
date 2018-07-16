//---------------------------------------------------------------------------

#ifndef PapeisViewH
#define PapeisViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
#include "PapelsController.h"
#include "RecursosController.h"
#include "RecursosGrupoPapelsController.h"
#include "PapelsDAO.h"
#include "RecursosGrupoPapels.h"
#include "Papels.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFPapeisView : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelTitle;
	TLabel *LabelCabecalhoModulo;
	TLabel *LabelCabecalhoSubTitulo;
	TLabel *LabelCabecalhoTitulo;
	TGroupBox *GroupBox1;
	TLabel *Nome;
	TEdit *NameEdit;
	TPanel *ActionsPanel;
	TSpeedButton *Deletar;
	TSpeedButton *Adicionar;
	TSpeedButton *Modificar;
	TSpeedButton *Sair;
	TComboBox *ComboBox1;
	TGroupBox *GroupBox2;
	TStringGrid *StringGrid1;
	TLabel *Label1;
	TSpeedButton *BtAdd;
	TEdit *DescontEdit;
	TLabel *Label2;
	void __fastcall BtAddClick(TObject *Sender);
	void __fastcall SairClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
	//RecursosController *recursoController;
	RecursosGrupoPapelsController *aux;
	PapelsController *papelController;
	RecursosGrupoPapels *auxiliar;
	Papels *papel;

	void loadView();
    void loadGruposRecursos();
public:		// User declarations
	__fastcall TFPapeisView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPapeisView *FPapeisView;
//---------------------------------------------------------------------------
#endif
