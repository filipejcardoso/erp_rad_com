//---------------------------------------------------------------------------

#ifndef FornecedoresViewH
#define FornecedoresViewH
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
#include "FornecedoresController.h"
#include "Associados.h"
#include "GridHelper.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFFornecedoresView : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabDados;
	TTabSheet *TabEnderecos;
	TTabSheet *TabContatos;
	TTabSheet *TabBancarias;
	TPanel *Panel2;
	TStringGrid *StringGridContatos;
	TLabel *Label41;
	TEdit *EditContatosNome;
	TLabel *Label42;
	TEdit *EditContatosContato;
	TLabel *Label43;
	TEdit *EditContatosCargo;
	TStringGrid *StringGridBancarias;
	TPanel *Panel3;
	TPanel *Panel5;
	TGroupBox *GroupDadosFornecedore;
	TGroupBox *GroupJuridica;
	TLabel *Label9;
	TLabel *Label4;
	TLabel *Label10;
	TEdit *EditCnpj;
	TEdit *EditRazaoSocial;
	TEdit *EditInscricaoMunicipal;
	TGroupBox *GroupFisica;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TEdit *EditCpf;
	TEdit *EditRg;
	TDateTimePicker *DateNascimento;
	TGroupBox *GroupGenericas;
	TLabel *Label5;
	TLabel *Label18;
	TLabel *Label6;
	TEdit *EditSite;
	TEdit *EditEmail;
	TEdit *EditNome;
	TEdit *EditContatosObservacao;
	TLabel *Label14;
	TButton *ButtonAdicionarContato;
	TButton *ButtonRemoverContato;
	TComboBox *ComboContatosTipo;
	TLabel *Label15;
	TEdit *EditBancariasDescricao;
	TLabel *Label16;
	TEdit *EditBancariasBanco;
	TLabel *Label17;
	TLabel *Label19;
	TEdit *EditBancariasAgencia;
	TLabel *Agencia;
	TEdit *EditBancariasConta;
	TEdit *EditBancariasCpfCnpj;
	TLabel *Label26;
	TLabel *Label27;
	TEdit *EditBancariasNome;
	TPanel *Panel6;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label25;
	TEdit *EditEnderecosLogradouro;
	TEdit *EditEnderecosCep;
	TEdit *EditEnderecosNumero;
	TComboBox *ComboEnderecosRegiao;
	TStringGrid *StringGridEnderecos;
	TPanel *Panel7;
	TButton *ButtonAdicionarEndereco;
	TButton *ButtonRemoverEndereco;
	TComboBox *ComboEnderecosTipo;
	TLabel *Label24;
	TEdit *EditEnderecosComplemento;
	TLabel *Label28;
	TPanel *Panel4;
	TButton *ButtonAdicionarBancarias;
	TButton *ButtonRemoverBancarias;
	TPanel *PanelOptions;
	TSpeedButton *Modificar;
	TSpeedButton *Adicionar;
	TSpeedButton *Deletar;
	TSpeedButton *Sair;
	TTimer *RecursosThread;
	TGroupBox *GroupDados;
	TComboBox *ComboSituacao;
	TComboBox *ComboTipo;
	TEdit *EditFax;
	TEdit *EditInscricaoEstadual;
	TEdit *EditTelefoneCelular;
	TEdit *EditTelefoneComercial;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label63;
	TLabel *Label66;
	TLabel *Label8;
	TGroupBox *GroupTipo;
	TCheckBox *CheckCliente;
	TCheckBox *CheckFornecedor;
	TEdit *EditEnderecosBairro;
	TLabel *Label20;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall StringGridContatosDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall StringGridBancariasDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall StringGridEnderecosDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall RecursosThreadTimer(TObject *Sender);
	void __fastcall SairClick(TObject *Sender);
	void __fastcall ComboTipoChange(TObject *Sender);
	void __fastcall ButtonAdicionarBancariasClick(TObject *Sender);
	void __fastcall ButtonAdicionarContatoClick(TObject *Sender);
	void __fastcall AdicionarClick(TObject *Sender);
	void __fastcall DeletarClick(TObject *Sender);
	void __fastcall ModificarClick(TObject *Sender);
	void __fastcall ButtonAdicionarEnderecoClick(TObject *Sender);
	void __fastcall StringGridEnderecosMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall StringGridContatosMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y);
	void __fastcall StringGridBancariasMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall StringGridContatosSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall StringGridBancariasSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall StringGridEnderecosSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall ButtonRemoverEnderecoClick(TObject *Sender);
	void __fastcall ButtonRemoverContatoClick(TObject *Sender);
	void __fastcall ButtonRemoverBancariasClick(TObject *Sender);
	void __fastcall PageControl1Change(TObject *Sender);
private:
	int rowselectEnderecos;
	int colselectEnderecos;
	int rowselectBancarias;
	int colselectBancarias;
	int rowselectContatos;
	int colselectContatos;

	GridHelper *helperEnderecos;
	GridHelper *helperContatos;
	GridHelper *helperBancarias;

	void DesignerBotoes();
	void loadFornecedor();
	void loadFornecedorModel();
    void loadClearFields();
	void loadView();

	void gridEnderecos();
	void gridContatos();
	void gridReferenciasBancarias();

	void loadComboIndicacao();
	void loadComboTipo();
	void loadComboSituacao();
	void loadComboEnderecosRegiao();
	void loadComboEnderecosTipo();
	void loadComboContatosTipo();

	void setTipo(bool);
	void setTipoAssociado(bool, int);

public:
	Associados *fornecedor;
    FornecedoresController *controller;
	int editar;// 0 - adicionar 1 - editar 2 - visualizar
	__fastcall TFFornecedoresView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFFornecedoresView *FFornecedoresView;
//---------------------------------------------------------------------------
#endif
