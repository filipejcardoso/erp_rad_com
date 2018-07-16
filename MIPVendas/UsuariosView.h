//---------------------------------------------------------------------------

#ifndef UsuariosViewH
#define UsuariosViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include "User.h"
#include "UsuariosController.h"
#include "Papels.h"
#include "Result.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFUsuariosView : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelTitle;
	TLabel *LabelCabecalhoModulo;
	TLabel *LabelCabecalhoSubTitulo;
	TLabel *LabelCabecalhoTitulo;
	TGroupBox *GroupBox1;
	TLabel *Nome;
	TEdit *NameEdit;
	TLabel *UserName;
	TEdit *EditUserName;
	TLabel *Email;
	TEdit *EditEmail;
	TLabel *Password;
	TEdit *EditPassword;
	TLabel *Papel;
	TComboBox *PapelCombo;
	TPanel *ActionsPanel;
	TSpeedButton *Deletar;
	TSpeedButton *Adicionar;
	TSpeedButton *Modificar;
	TSpeedButton *Sair;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SairClick(TObject *Sender);
	void __fastcall DeletarClick(TObject *Sender);
	void __fastcall AdicionarClick(TObject *Sender);
	void __fastcall ModificarClick(TObject *Sender);
	void __fastcall EditPasswordClick(TObject *Sender);
private:
	void DesignerBotoes();
	void loadView();
	void loadUsuario();
	void loadComboPapels();
    void setComboPapels();
	void loadClearFields();
    void loadUsuarioModel();

public:
	User *usuario;
	UsuariosController *controller;
	Papels *papel;
	Result *result;
	int editar; //0 - Inserir usuario / 1 - Update usuario

	__fastcall TFUsuariosView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFUsuariosView *FUsuariosView;
//---------------------------------------------------------------------------
#endif
