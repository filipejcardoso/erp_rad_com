//---------------------------------------------------------------------------

#ifndef GerenciarUsuariosH
#define GerenciarUsuariosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFGerenciarUsuarios : public TForm
{
__published:	// IDE-managed Components
	TSQLQuery *SQLQuery1;
	TPanel *Panel1;
	TPanel *Panel2;
	TStringGrid *StringGrid1;
	TPanel *Panel3;
	TButton *ButtonAtualizar;
	TButton *ButtonNovoUsuario;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditUsuario;
	TEdit *EditSenha;
	TLabel *Label3;
	TEdit *EditRepitirSenha;
	TGroupBox *GroupBox1;
	TCheckBox *Check0;
	TCheckBox *Check1;
	TCheckBox *Check3;
	TCheckBox *Check2;
	TCheckBox *Check4;
	TCheckBox *Check5;
	TCheckBox *Check6;
	TCheckBox *Check7;
	TPanel *Panel4;
	TButton *ButtonInserirModificar;
	TButton *ButtonDeletar;
	TLabel *Label4;
	TEdit *EditDesconto;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State);
	void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall StringGrid1Click(TObject *Sender);
	void __fastcall ButtonAtualizarClick(TObject *Sender);
	void __fastcall ButtonNovoUsuarioClick(TObject *Sender);
	void __fastcall ButtonDeletarClick(TObject *Sender);
	void __fastcall ButtonInserirModificarClick(TObject *Sender);

private:
	typedef struct
	{
		int id;
		char *nome;
		char *senha;
		char desconto;
		unsigned int permissao;
	}Usuarios;
	Usuarios *users;
	int rowselect;
	int n;
	int editar;

	void ConfigurarLayout();
	void GerarGrid();
	void CarregarCampos();
	void InicializarCampos();
	void DesignerBotoes();
	void InserirUsuario();
	void ModificarUsuario();
public:		// User declarations
	__fastcall TFGerenciarUsuarios(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFGerenciarUsuarios *FGerenciarUsuarios;
//---------------------------------------------------------------------------
#endif
