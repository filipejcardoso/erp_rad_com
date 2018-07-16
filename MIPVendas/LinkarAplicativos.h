//---------------------------------------------------------------------------

#ifndef LinkarAplicativosH
#define LinkarAplicativosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
//---------------------------------------------------------------------------
class TFLinkarAplicativos : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditHost;
	TLabel *Label1;
	TEdit *EditNome;
	TLabel *Label2;
	TEdit *EditUsuarioBd;
	TLabel *Label3;
	TEdit *EditSenhaBd;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TComboBox *ComboFornecedor;
	TComboBox *ComboUsuario;
	TComboBox *ComboCentro;
	TComboBox *ComboProjeto;
	TComboBox *ComboContabil;
	TButton *Button1;
	TPanel *PanelTopo;
	TLabel *LabelCabecalhoTitulo;
	TLabel *LabelCabecalhoSubTitulo;
	TSQLQuery *SQLQuery1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery2;
	TButton *Button2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:
	void CarregarCampos();
	int TestarConexao();
	void CarregarCombos();
	int CONTA[10000],PROJETO[10000],CENTRO[10000];
	UnicodeString CNPJ[10000];

    void loadCabecalho();

public:		// User declarations
	__fastcall TFLinkarAplicativos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFLinkarAplicativos *FLinkarAplicativos;
//---------------------------------------------------------------------------
#endif
