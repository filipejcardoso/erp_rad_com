//---------------------------------------------------------------------------

#ifndef ProdutosViewH
#define ProdutosViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <jpeg.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdFTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include "ProdutosController.h"
#include "Produtos.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFProdutosView : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TSpeedButton *Modificar;
	TSpeedButton *Adicionar;
	TSpeedButton *Deletar;
	TSpeedButton *Sair;
	TGroupBox *GroupBox1;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EditNcm;
	TEdit *EditCfop;
	TGroupBox *GroupBox2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label16;
	TLabel *Label12;
	TEdit *EditNome;
	TEdit *EditCodbarras;
	TGroupBox *GroupBox3;
	TLabel *Label6;
	TLabel *Label8;
	TLabel *Label7;
	TEdit *EditPrecoCompra;
	TEdit *EditLucro;
	TEdit *EditPrecoVenda;
	TComboBox *ComboMarcas;
	TComboBox *ComboUnidadesMedidas;
	TGroupBox *GroupBox4;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label17;
	TComboBox *ComboCategorias;
	TComboBox *ComboSubcategorias;
	TComboBox *ComboLojas;
	TGroupBox *GroupBox7;
	TLabel *Label9;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label10;
	TEdit *EditProdutosEstoqueArea;
	TEdit *EditProdutosEstoqueRua;
	TEdit *EditProdutosEstoqueModulo;
	TEdit *EditProdutosEstoqueNivel;
	TEdit *EditProdutosEstoqueVao;
	TEdit *EditQuantidade;
	TGroupBox *GroupBox9;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TEdit *EditProdutosDimensoesPeso;
	TEdit *EditProdutosDimensoesAltura;
	TEdit *EditProdutosDimensoesLargura;
	TEdit *EditProdutosDimensoesComprimento;
	TPanel *PanelTitle;
	TLabel *LabelCabecalhoModulo;
	TLabel *LabelCabecalhoSubTitulo;
	TLabel *LabelCabecalhoTitulo;
	TEdit *EditProdutosDimensoesDiametro;
	TLabel *Label27;
	TTimer *RecursosThread;
	TSpeedButton *BtInsert;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboCategoriasChange(TObject *Sender);
	void __fastcall SairClick(TObject *Sender);
	void __fastcall EditLucroKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall EditLucroKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditLucroKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditPrecoCompraKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditPrecoCompraKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall EditPrecoCompraKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditPrecoVendaKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditPrecoVendaKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall EditPrecoVendaKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall AdicionarClick(TObject *Sender);
	void __fastcall DeletarClick(TObject *Sender);
	void __fastcall ModificarClick(TObject *Sender);
	void __fastcall RecursosThreadTimer(TObject *Sender);
	void __fastcall BtInsertClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
private:
	void DesignerBotoes();
	void loadComboMarcas();
	void loadComboLojas();
	void loadComboCategorias();
	void loadComboSubcategorias();
	void loadComboUnidadesMedidas();
	void loadProduto();
    void loadClearFields();
	void loadView();

	void setComboMarcas();
	void setComboLojas();
	void setComboCategorias();
	void setComboSubcategorias();
	void setComboUnidadesMedidas();

	void maxComboMarcas();
	void maxComboLojas();
	void maxComboCategorias();
	void maxComboSubcategorias();
	void maxComboUnidadesMedidas();

	void setPrecoVenda();
	void setLucro();

	void loadProdutosModel();
public:
	Produtos *produto;
    ProdutosController *controller;
	int editar;// 0 - adicionar 1 - editar 2 - visualizar

	__fastcall TFProdutosView(TComponent* Owner);
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
extern PACKAGE TFProdutosView *FProdutosView;
//---------------------------------------------------------------------------
#endif
