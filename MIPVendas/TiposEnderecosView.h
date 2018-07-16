//---------------------------------------------------------------------------

#ifndef TiposEnderecosViewH
#define TiposEnderecosViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "TiposEnderecos.h"
#include "TiposEnderecosController.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFTiposEnderecosView : public TForm
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
	void loadTiposEndereco();
	void loadTiposEnderecoModel();
    void loadClearFields();
	void loadView();

public:
	TiposEnderecos *tipos_endereco;
	TiposEnderecosController *controller;
	int editar;// 0 - adicionar 1 - editar 2 - visualizar
	__fastcall TFTiposEnderecosView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFTiposEnderecosView *FTiposEnderecosView;
//---------------------------------------------------------------------------
#endif
