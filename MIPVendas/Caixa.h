//---------------------------------------------------------------------------

#ifndef CaixaH
#define CaixaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <jpeg.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TFCaixa : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelTopo;
	TLabel *LabelCabecalhoTitulo;
	TLabel *LabelCabecalhoSubTitulo;
	TPanel *PanelVariavel;
	TPanel *PanelPagamento;
	TStringGrid *StringGrid1;
	TPanel *PanelDesconto;
	TPanel *PanelFixo;
	TPanel *PanelProdutos;
	TPanel *PanelFinalizar;
	TButton *ButtonAbrirFechar;
	TButton *ButtonLeituraX;
	TButton *ButtonReducaoZ;
	TButton *ButtonExtornar;
	TSQLQuery *SQLQuery1;
	TActionList *ActionList1;
	TAction *F1;
	TAction *F2;
	TAction *F3;
	TAction *F4;
	TAction *F5;
	TAction *F6;
	TAction *F7;
	TAction *F8;
	TAction *F12;
	TLabel *Label3;
	TEdit *EditSaldoDinheiro;
	TLabel *Label4;
	TEdit *EditSaldoCartao;
	TLabel *Label5;
	TEdit *EditSaldoCarteira;
	TLabel *Label9;
	TEdit *EditSaldoCheque;
	TLabel *Label10;
	TEdit *EditSaldoTotal;
	TLabel *LabelState;
	TLabel *LabelCodigo;
	TLabel *LabelOperador;
	TLabel *LabelData;
	TLabel *LabelHorario;
	TPrintDialog *PrintDialog1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonAbrirFecharClick(TObject *Sender);
	void __fastcall ButtonLeituraXClick(TObject *Sender);
	void __fastcall ButtonReducaoZClick(TObject *Sender);
	void __fastcall ButtonExtornarClick(TObject *Sender);
	void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:
	typedef struct
	{
		char *host;
		char *bd;
		char *usuario_bd;
		char *senha;
		char *fornecedor;
		char *fornecedor_cnpj;
		char *usuario;
		int centro;
		int projeto;
		int conta;
	}FMIPGestao;
	FMIPGestao MIPGestao;

	typedef struct _TabelaProdutos
	{
		int funcao;
		int id;
		int id_produto;
		char *codbarras;
		char *descricao;
		float preco;
		float quantidade;
		char *unidade;
		char *marca;
		char *ncm;
		char *cfop;
		float desconto;
		int promocao;
		int devolucao;
		_TabelaProdutos *proximo;

	}TabelaProdutos;
	TabelaProdutos *TabelaProdutosMovel;
	TabelaProdutos *TabelaProdutosNo;

	UnicodeString OPERADOR;
	int STATE;
	int rowselect;

	void InicializarCampos();
	void Designer();
	void GerarGrid();
	void AbrirCaixa();
	void FecharCaixa();
	void ReducaoZ();
	void LeituraX();
	void ExtornarVenda();
	void ImprimirRelatorio();
	void AnalisaRetorno(int Retorno, const wchar_t * TituloJanela, char * Mensagem, char * Informacao);
	void CalcularSaldo(int state);
	void CarregarProdutos();
	void AdicionarTabelaProdutos(TabelaProdutos *Proximo);
	void InserirMIPGestao();
	void CarregarMIPGestao();
	int ConectarMIPGestao();
    void loadCabecalho();
public:		// User declarations
	__fastcall TFCaixa(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFCaixa *FCaixa;
//---------------------------------------------------------------------------
#endif
