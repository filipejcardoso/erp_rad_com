//---------------------------------------------------------------------------

#ifndef ContasReceberH
#define ContasReceberH
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
#include <Vcl.Grids.hpp>
#include <stdio.h>
#include <Vcl.Dialogs.hpp>
#include <System.Character.hpp>
//---------------------------------------------------------------------------
class TFContasReceber : public TForm
{
__published:	// IDE-managed Components
	TSQLQuery *SQLQuery1;
	TPageControl *PageControlPrincipal;
	TTabSheet *TabPendentes;
	TTabSheet *TabFechamentos;
	TTabSheet *TabArquivados;
	TPanel *PanelPendentes;
	TPanel *PanelPendentesFixo;
	TStringGrid *GridPendentes;
	TPanel *PanelPendentesFiltro;
	TPanel *PanelPendentesVariavel;
	TEdit *EditBuscaPendentes;
	TButton *ButtonFiltrarPendentes;
	TStringGrid *GridPendentesDetalhada;
	TPanel *PanelTopoPendentes;
	TLabel *LabelCabecalhoEmpresaPendentes;
	TLabel *LabelCabecalhoAppPendentes;
	TPanel *PanelPendentesOpcoes;
	TButton *Button2;
	TLabel *Label5;
	TEdit *EditPendentesSelecionado;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TSaveDialog *SaveDialog1;
	TGroupBox *GroupBox1;
	TRadioButton *RadioSimplesPendentes;
	TRadioButton *RadioIndicacaoPendentes;
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery2;
	TPanel *PanelTopoFechamentos;
	TLabel *LabelCabecalhoEmpresaFechamentos;
	TLabel *LabelCabecalhoAppFechamentos;
	TPanel *PanelFechamentos;
	TPanel *PanelFechamentosFixo;
	TStringGrid *GridFechamentos;
	TPanel *Panel4;
	TEdit *EditBuscaFechamentos;
	TButton *ButtonFiltrarFechamentos;
	TGroupBox *GroupBox2;
	TRadioButton *RadioSimplesFechamentos;
	TRadioButton *RadioIndicacaoFechamentos;
	TPanel *PanelFechamentosVariavel;
	TPanel *Panel6;
	TStringGrid *GridFechamentosDetalhada;
	TPanel *Panel1;
	TPageControl *PageControlFechamentos;
	TTabSheet *Parcelas;
	TStringGrid *GridFechamentosParcelas;
	TTabSheet *Pedidos;
	TStringGrid *GridFechamentosPedidos;
	TPanel *Panel7;
	TLabel *Label4;
	TButton *Button6;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TPanel *Panel2;
	TPanel *PanelArquivadosTopo;
	TLabel *LabelCabecalhoEmpresaArquivados;
	TLabel *LabelCabecalhoAppArquivados;
	TPanel *PanelArquivados;
	TPanel *PanelArquivadosFixo;
	TStringGrid *GridArquivados;
	TPanel *Panel9;
	TEdit *EditBuscaArquivados;
	TButton *Button1;
	TGroupBox *GroupBox3;
	TRadioButton *RadioSimplesArquivados;
	TRadioButton *RadioIndicacaoArquivados;
	TPanel *PanelArquivadosVariavel;
	TStringGrid *GridArquivadosDetalhada;
	TPanel *Panel11;
	TLabel *Label9;
	TButton *Button7;
	TEdit *EditArquivadosSelecionado;
	TButton *Button13;
	TPrintDialog *PrintDialog1;
	TCheckBox *CheckConsumidorPendentes;
	TCheckBox *CheckConsumidorArquivados;
	TCheckBox *CheckConsumidorFechamentos;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall GridPendentesDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall GridPendentesDetalhadaDrawCell(TObject *Sender, int ACol, int ARow,
		  TRect &Rect, TGridDrawState State);
	void __fastcall GridPendentesSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall GridPendentesDetalhadaSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall GridPendentesDetalhadaMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ButtonFiltrarPendentesClick(TObject *Sender);
	void __fastcall RadioSimplesPendentesClick(TObject *Sender);
	void __fastcall RadioIndicacaoPendentesClick(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall GridFechamentosDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall GridFechamentosDetalhadaDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall GridFechamentosParcelasDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall GridFechamentosPedidosDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall ButtonFiltrarFechamentosClick(TObject *Sender);
	void __fastcall GridFechamentosSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall GridFechamentosDetalhadaSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall GridFechamentosPedidosMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall GridFechamentosPedidosSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall PageControlPrincipalChange(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall GridFechamentosParcelasSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall GridArquivadosSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall GridArquivadosDetalhadaSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall GridArquivadosDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall GridArquivadosDetalhadaMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall GridArquivadosDetalhadaDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);




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
	TabelaProdutos *TabelaProdutosNo;
	TabelaProdutos *TabelaProdutosMovel;

	void AdicionarTabelaProdutos(TabelaProdutos *Proximo);
	void LiberarMemoriaProdutos();
	void ProucurarCodbarras(char *codbarras,TabelaProdutos **ponteiro);

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
	TabelaOrcamento Orcamento;

	typedef struct _TFechamentos
	{
		int linha;
		float valor;
		float desconto;
		int modpagar;
		TDate data_vencimento;
		_TFechamentos *proximo;
	}TFechamentos;

	typedef struct _Check
	{
		int linha;
		int codigo;
		TDate data;
		int cliente;
		int vendedor;
		int atendente;
		float valor;
		_Check *proximo;
	}Check;
	Check *LinhasSelecionadasNo;
	Check *LinhasSelecionadasMovel;

	void MarcarCheck(Check *Proximo);
	void DesmarcarCheck(int linha);
	void LimparCheck();
	int ProucurarLinha(int linha);


	int id_cliente;
	int dias_notificao;

	int rowselect_pendentes;
	int rowselect_pendentes_detalhada;
	int rowselect_fechamentos;
	int rowselect_fechamentos_detalhada;
	int rowselect_fechamentos_parcelas;
	int rowselect_fechamentos_pedidos;
	int rowselect_arquivados;
	int rowselect_arquivados_detalhada;

	void GerarGridPendentes();
	void GerarGridPendentesDetalhada();

	void GerarGridFechamentos();
	void GerarGridFechamentosDetalhada();
	void GerarGridFechamentosParcelas();
	void GerarGridFechamentosPedidos();

	void GerarGridArquivados();
	void GerarGridArquivadosDetalhada();

	void DesignerPendentes();
	void DesignerFechamentos();
	void DesignerArquivados();
	void TotalPendentes();
	void TotalArquivados();
	int Arquivar();
	int Desarquivar();
	void FecharPedidos(int codigo_fechamento);
	void DeletarFechamento(int codigo_fechamento);
	void ExportarNFe();
	float CalculoNcm(UnicodeString ncm,float valor);
	int GetDiasNotificacao();
	void LiberarMemoriaMIPGestaoValores();
	void FinalizarFechamento(int codigo_fechamento,int prestacao);
	void AtualizarGastoCliente();
	void ImprimirOrcamento();

	void InserirMIPGestao(int codigo_fechamento,int NParcelas);
	void RemoverMIPGestao(int codigo_fechamento);
	void AtualizarMIPGestao(int codigo_fechamento,int prestacao);
	void CarregarMIPGestao();
	int ConectarMIPGestao();

    void loadCabecalho();

public:
	UnicodeString CLIENTE_SELECIONADO;
	UnicodeString CLIENTE_ID_SELECIONADO;
	TFechamentos *FechamentosNo;
	TFechamentos *FechamentosMovel;

	void AdicionarFechamento(int linha,float valor,float desconto,int modpagar,TDate data_vencimento);
	void RemoverFechamento(int linha);
	void LiberarMemoriaFechamentos();
	void RealizarFechamento();

	__fastcall TFContasReceber(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFContasReceber *FContasReceber;
//---------------------------------------------------------------------------
#endif
