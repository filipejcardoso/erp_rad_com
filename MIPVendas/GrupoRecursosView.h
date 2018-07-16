//---------------------------------------------------------------------------

#ifndef GrupoRecursosViewH
#define GrupoRecursosViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFGrupoRecursos : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelOptions;
	TSpeedButton *Adicionar;
	TSpeedButton *Sair;
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TCheckBox *ReadCheckBox;
	TCheckBox *CreateCheckBox;
	TCheckBox *UpdateCheckBox;
	TCheckBox *DeleteCheckBox;
	TPanel *PanelTitle;
	TLabel *LabelCabecalhoModulo;
	TLabel *LabelCabecalhoSubTitulo;
	TLabel *LabelCabecalhoTitulo;
	TComboBox *GrupoRecursosBox;
	void __fastcall SairClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	void loadView();
public:		// User declarations
	__fastcall TFGrupoRecursos(TComponent* Owner);
	int crud;
};
//---------------------------------------------------------------------------
extern PACKAGE TFGrupoRecursos *FGrupoRecursos;
//---------------------------------------------------------------------------
#endif
