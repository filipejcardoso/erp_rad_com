//---------------------------------------------------------------------------

#ifndef GraficoVendasH
#define GraficoVendasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Grids.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
//---------------------------------------------------------------------------
class TFGraficoVendas : public TForm
{
__published:	// IDE-managed Components
	TChart *Chart1;
	TBarSeries *Series1;
	TPanel *PanelOpcao;
	TLabel *Label1;
	TLabel *Label2;
	TDateTimePicker *data_inicial;
	TDateTimePicker *data_final;
	TButton *Button1;
	TGroupBox *GroupBox1;
	TComboBox *ComboPeriodo;
	TCheckBox *CheckGrafico;
	TCheckBox *CheckTabela;
	TCheckBox *CheckConsumidor;
	TCheckBox *CheckFinalizado;
	TStringGrid *StringGrid1;
	TSQLQuery *SQLQuery1;
	TComboBox *ComboAtendentes;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CheckGraficoClick(TObject *Sender);
	void __fastcall CheckTabelaClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
private:
	typedef struct
	{
		int id;
		char *desc;
	}IdDesc;
	IdDesc *atendentes;
	int NAtendentes;

	void Designer();
	void MontarGrafico();
	void InicializarCampos();
	void CarregarBoxAtendentes();
	void GerarGrid();
	void SetarModo();
public:
	int modo; // 0 - grafico completo 1 - vendas atendentes
	__fastcall TFGraficoVendas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFGraficoVendas *FGraficoVendas;
//---------------------------------------------------------------------------
#endif
