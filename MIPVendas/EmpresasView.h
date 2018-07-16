//---------------------------------------------------------------------------

#ifndef EmpresasViewH
#define EmpresasViewH
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
#include "EmpresasController.h"
#include "Empresas.h"
#include "GridHelper.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFEmpresasView : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelOptions;
	TSpeedButton *Modificar;
	TSpeedButton *Sair;
	TPageControl *PageControl1;
	TTabSheet *TabDados;
	TGroupBox *GroupDadosEmpresa;
	TGroupBox *GroupGenericas;
	TLabel *Label5;
	TEdit *EditNome;
	TGroupBox *GroupEnderecos;
	TLabel *Label4;
	TEdit *EditRazaoSocial;
	TEdit *EditCnpj;
	TLabel *Label9;
	TEdit *EditInscricaoEstadual;
	TLabel *Label1;
	TEdit *EditInscricaoMunicipal;
	TLabel *Label10;
	TEdit *EditTelefone;
	TLabel *Label2;
	TLabel *Label18;
	TEdit *EditEmail;
	TEdit *EditSite;
	TLabel *Label6;
	TEdit *EditEnderecosCep;
	TLabel *Label15;
	TComboBox *ComboEnderecosRegiao;
	TLabel *Label17;
	TEdit *EditEnderecosLogradouro;
	TLabel *Label14;
	TEdit *EditEnderecosNumero;
	TLabel *Label16;
	TEdit *EditEnderecosBairro;
	TLabel *Label27;
	TComboBox *ComboEnderecosTipo;
	TLabel *Label19;
	TEdit *EditEnderecosComplemento;
	TLabel *Label26;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SairClick(TObject *Sender);
	void __fastcall ModificarClick(TObject *Sender);
private:
	void loadEmpresa();
	void loadEmpresaModel();
    void loadClearFields();
	void loadView();

	void loadComboEnderecosRegiao();
	void loadComboEnderecosTipo();

public:
	Empresas *empresa;
    EmpresasController *controller;
	__fastcall TFEmpresasView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFEmpresasView *FEmpresasView;
//---------------------------------------------------------------------------
#endif
