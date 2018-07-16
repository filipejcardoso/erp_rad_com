//---------------------------------------------------------------------------

#ifndef VendasH
#define VendasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <VCLTee.TeCanvas.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <stdio.h>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//---------------------------------------------------------------------------
class TFVendas : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelTopo;
	TLabel *LabelCabecalhoTitulo;
	TPanel *PanelVariavel;
	TPanel *PanelFixo;
	TPanel *PanelPagamento;
	TPanel *PanelDesconto;
	TStringGrid *GridPagamento;
	TEdit *EditCodigo;
	TLabel *Label2;
	TEdit *EditDescontoP;
	TLabel *Label3;
	TEdit *EditDescontoD;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EditValorTotal;
	TPanel *PanelProdutos;
	TStringGrid *GridProdutos;
	TPanel *PanelFinalizar;
	TLabel *Label6;
	TEdit *EditValorRestante;
	TButton *ButtonDinheiro;
	TButton *ButtonCarteira;
	TButton *ButtonCartao;
	TButton *ButtonCheque;
	TButton *ButtonVale;
	TGroupBox *GroupBox1;
	TLabel *LabelPrecoProduto;
	TSQLQuery *SQLQuery1;
	TLabel *LabelCabecalhoSubTitulo;
	TButton *ButtonGaveta;
	TActionList *ActionList1;
	TAction *F1;
	TAction *F2;
	TAction *F3;
	TAction *F4;
	TAction *F5;
	TAction *F6;
	TLabel *Label8;
	TAction *F7;
	TAction *F8;
	TAction *F12;
	TLabel *LabelCliente;
	TAction *F9;
	TIdHTTP *HTTP;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonDinheiroClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall GridPagamentoDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State);
	void __fastcall GridProdutosDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State);
	void __fastcall EditCodigoKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall GridProdutosSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall ButtonCartaoClick(TObject *Sender);
	void __fastcall ButtonChequeClick(TObject *Sender);
	void __fastcall ButtonCarteiraClick(TObject *Sender);
	void __fastcall ButtonValeClick(TObject *Sender);
	void __fastcall F1Execute(TObject *Sender);
	void __fastcall F2Execute(TObject *Sender);
	void __fastcall F3Execute(TObject *Sender);
	void __fastcall F4Execute(TObject *Sender);
	void __fastcall F5Execute(TObject *Sender);
	void __fastcall F6Execute(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ButtonGavetaClick(TObject *Sender);
	void __fastcall F7Execute(TObject *Sender);
	void __fastcall F12Execute(TObject *Sender);
	void __fastcall EditDescontoDKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall EditDescontoDExit(TObject *Sender);
	void __fastcall EditDescontoPExit(TObject *Sender);
	void __fastcall EditDescontoPKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall F9Execute(TObject *Sender);

private:
	typedef struct
	{
		int id;
		char *desc;
	}IdDesc;
	IdDesc *atendentes;

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

	typedef struct
	{
		int id;
		int codigo;
		TDate data;
		TTime hora;
		int usuario;
		int atendente;
		int cliente;
		char *observacao;
		int vendido;
		TabelaProdutos *produtos;
	}TabelaOrcamento;

	typedef struct _Pagamento
	{
		int modpagar;
		float valor;
		_Pagamento *proximo;
	}Pagamento;
	Pagamento *PagamentoMovel;
	Pagamento *PagamentoNo;

	int rowselect;
	int impressora;
	UnicodeString NOME_CLIENTE;

	void AdicionarTabelaProdutos(TabelaProdutos *Proximo);
	void ProucurarCodbarras(char *codbarras,TabelaProdutos **ponteiro);

	void Designer();
	void EstruturarGridProdutos();
	void GerarGridProdutos();
	void Desconto();
	void Total();
	void CarregarOrcamento();
	void CalcularRestante();
	void LiberarMemoria();
	void InicializarCampos();
	void ImprimirCupom(int carteira,int vale);
	void ImprimirNaoFiscal();
	void ImprimirFiscal();
	void AnalisaRetorno(int Retorno, const wchar_t * TituloJanela, char * Mensagem, char * Informacao);
	int VerificarFiscal();
	void AbrirCOM();
	void FecharCOM();
	void SetarImpressora();

	void ImprimirSAT();
	UnicodeString AberturaCupomSAT();
	int VenderItemSAT(UnicodeString sessao);
	int EfetuarPagamentoSAT(UnicodeString sessao);
	int FecharCupomSAT(UnicodeString sessao);
	int CancelarCupomSAT();
	void loadCabecalho();

public:
	TabelaOrcamento Orcamento;
	UnicodeString CPF_CLIENTE;
	int devolucao;

	void AbrirGaveta();
	void AdicionarPagamento(int modpagar,float valor);
	void DeletarPagamento(int n);
	void GerarGridPagamentos();
	void ConcluirVenda();
	void DescontoPorcentagem();
	void DescontoDinheiro();
	void PermissaoDesconto();
	float GetDescontoPermitido();
	void AtualizarOrcamento();

	__fastcall TFVendas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFVendas *FVendas;
//---------------------------------------------------------------------------
#endif
