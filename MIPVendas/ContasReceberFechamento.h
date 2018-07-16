//---------------------------------------------------------------------------

#ifndef ContasReceberFechamentoH
#define ContasReceberFechamentoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.Grids.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFContasReceberFechamento : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelTopo;
	TLabel *LabelTitulo;
	TLabel *Label7;
	TSQLQuery *SQLQuery1;
	TStringGrid *StringGrid1;
	TPanel *Panel1;
	TLabel *Label2;
	TEdit *EditValorFechamento;
	TButton *ButtonCancelar;
	TButton *ButtonDinheiro;
	TButton *ButtonCartao;
	TButton *ButtonCheque;
	TButton *ButtonBoleto;
	TLabel *Label1;
	TEdit *EditValorRestante;
	TLabel *Label6;
	TLabel *Label3;
	TEdit *EditDescontoP;
	TEdit *EditDescontoD;
	TLabel *Label4;
	TEdit *EditValorTotal;
	TLabel *Label5;
	TLabel *LabelCliente;
	TActionList *ActionList1;
	TAction *Del;
	TDateTimePicker *data_vencimento;
	TLabel *Label8;
	TAction *F1;
	TAction *F2;
	TAction *F3;
	TAction *F4;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonCancelarClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonDinheiroClick(TObject *Sender);
	void __fastcall ButtonCartaoClick(TObject *Sender);
	void __fastcall ButtonChequeClick(TObject *Sender);
	void __fastcall ButtonBoletoClick(TObject *Sender);
	void __fastcall DelExecute(TObject *Sender);
	void __fastcall EditDescontoPKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall EditDescontoDExit(TObject *Sender);
	void __fastcall EditDescontoDKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall EditDescontoPExit(TObject *Sender);
	void __fastcall F4Execute(TObject *Sender);
	void __fastcall F3Execute(TObject *Sender);
	void __fastcall F2Execute(TObject *Sender);
	void __fastcall F1Execute(TObject *Sender);

private:
	int rowselect;

	void InicializarCampos();
	void GerarGrid();
	void Total();
	void DescontoP();
	void DescontoD();
	void AdicionarFechamento(int modpagar);
public:
	__fastcall TFContasReceberFechamento(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFContasReceberFechamento *FContasReceberFechamento;
//---------------------------------------------------------------------------
#endif
