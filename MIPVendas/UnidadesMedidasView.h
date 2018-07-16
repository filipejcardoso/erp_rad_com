//---------------------------------------------------------------------------

#ifndef UnidadesMedidasViewH
#define UnidadesMedidasViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "UnidadesMedidas.h"
#include "UnidadesMedidasController.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFUnidadesMedidasView : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelOptions;
	TSpeedButton *Modificar;
	TSpeedButton *Adicionar;
	TSpeedButton *Deletar;
	TSpeedButton *Sair;
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TEdit *EditNome;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SairClick(TObject *Sender);
	void __fastcall AdicionarClick(TObject *Sender);
	void __fastcall DeletarClick(TObject *Sender);
	void __fastcall ModificarClick(TObject *Sender);
private:
	void DesignerBotoes();
	void loadUnidadesMedida();
	void loadUnidadesMedidaModel();
    void loadClearFields();
	void loadView();

public:
	UnidadesMedidas *unidades_medida;
	UnidadesMedidasController *controller;
	int editar;// 0 - adicionar 1 - editar 2 - visualizar
	__fastcall TFUnidadesMedidasView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFUnidadesMedidasView *FUnidadesMedidasView;
//---------------------------------------------------------------------------
#endif
