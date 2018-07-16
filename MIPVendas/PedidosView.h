//---------------------------------------------------------------------------

#ifndef PedidosViewH
#define PedidosViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <jpeg.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
#include "Pedidos.h"
#include "PedidosController.h"
#include "frxClass.hpp"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFPedidosView : public TForm
{
__published:	// IDE-managed Components
	TPrintDialog *PrintDialog1;
	TSaveDialog *SaveDialog1;
	TActionList *ActionList1;
	TPanel *PanelTopo;
	TLabel *LabelCabecalhoTitulo;
	TLabel *LabelCabecalhoSubTitulo;
	TPanel *Panel4;
	TStringGrid *StringGridProdutos;
	TPanel *Panel3;
	TPanel *Panel2;
	TPanel *Panel5;
	TEdit *EditValor;
	TLabel *Label1;
	TLabel *Label12;
	TImage *Imprimir;
	TLabel *Label10;
	TImage *Exit;
	TImage *RemoveProduct;
	TLabel *Label2;
	TImage *SearchProduct;
	TLabel *Label9;
	TPanel *Panel6;
	TImage *Image1;
	TEdit *EditDescontoD;
	TLabel *Label4;
	TLabel *Label3;
	TEdit *EditDescontoP;
	TGroupBox *GroupBox1;
	TLabel *LabelNumeroPedido;
	TLabel *Label14;
	TPanel *Panel1;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label11;
	TLabel *LabelCliente;
	TEdit *EditCodigo;
	TEdit *EditQuantidade;
	TEdit *EditDesconto;
	TGroupBox *GroupBox2;
	TLabel *LabelAtendente;
	TGroupBox *GroupBox3;
	TLabel *LabelData;
	TMemo *MemoObs;
	TLabel *Label18;
	TTimer *TimerObs;
	TMainMenu *MainMenu1;
	TMenuItem *OPES1;
	TMenuItem *BuscarProduto1;
	TMenuItem *BuscarCliente1;
	TMenuItem *Imprimir1;
	TMenuItem *Sair1;
	TfrxReport *frxReport1;
	TfrxUserDataSet *frxUserDataSet1;
	TLabel *LabelContribuicao;
	TLabel *Label13;
	TAction *margem_contribuicao;
	TLabel *LabelNfe;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall EditCodigoKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall StringGridProdutosDrawCell(TObject *Sender, int ACol, int ARow,
		  TRect &Rect, TGridDrawState State);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall EditQuantidadeKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall EditCodigoClick(TObject *Sender);
	void __fastcall StringGridProdutosSelectCell(TObject *Sender, int ACol, int ARow,
		  bool &CanSelect);
	void __fastcall SearchProductClick(TObject *Sender);
    void __fastcall ExitClick(TObject *Sender);
	void __fastcall EditDescontoKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall EditDescontoDKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall EditDescontoPKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall TimerObsTimer(TObject *Sender);
	void __fastcall MemoObsKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ImprimirClick(TObject *Sender);
	void __fastcall RemoveProductClick(TObject *Sender);
	void __fastcall BuscarProduto1Click(TObject *Sender);
	void __fastcall BuscarCliente1Click(TObject *Sender);
	void __fastcall Imprimir1Click(TObject *Sender);
	void __fastcall Sair1Click(TObject *Sender);
	void __fastcall frxReport1GetValue(const UnicodeString VarName, Variant &Value);
	void __fastcall frxReport1BeforePrint(TfrxReportComponent *Sender);
	void __fastcall margem_contribuicaoExecute(TObject *Sender);




private:
	int rowselect;
	bool editar_produto;

	void loadClearFields();
	void loadView();
	void setEditarQuantidade(bool);

	void insertProduto();

	void gridProdutos();

	void searchProduto();
	void searchCliente();
	void imprimir();

public:
	PedidosController *controller;
	Pedidos *pedido;
	int editar;// 0 - adicionar 1 - editar 2 - visualizar
    void loadPedido();
	__fastcall TFPedidosView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPedidosView *FPedidosView;
//---------------------------------------------------------------------------
#endif
