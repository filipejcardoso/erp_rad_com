//---------------------------------------------------------------------------

#ifndef ImportarH
#define ImportarH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.SqlExpr.hpp>
#include <Data.FMTBcd.hpp>
//---------------------------------------------------------------------------
class TFImportar : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery1;
	TSQLQuery *SQLQuery2;
	TButton *Button7;
	TSQLQuery *SQLQuery3;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TSQLQuery *SQLQuery4;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
private:
	int VerificarDevolucao(char *codbarras,char **codfinal);
public:		// User declarations
	__fastcall TFImportar(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFImportar *FImportar;
//---------------------------------------------------------------------------
#endif
