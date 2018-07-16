//---------------------------------------------------------------------------

#ifndef ContasFinalizadasH
#define ContasFinalizadasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFContasFinalizadas : public TForm
{
__published:	// IDE-managed Components
	TSQLQuery *SQLQuery1;
	TPanel *PanelPendentes;
	TPanel *PanelPendentesFixo;
	TStringGrid *GridPendentes;
	TPanel *PanelPendentesFiltro;
	TEdit *EditBuscaPendentes;
	TButton *ButtonFiltrarPendentes;
	TGroupBox *GroupBox1;
	TRadioButton *RadioSimplesPendentes;
	TRadioButton *RadioIndicacaoPendentes;
	TCheckBox *CheckConsumidorPendentes;
	TPanel *PanelPendentesVariavel;
	TStringGrid *GridPendentesDetalhada;
	TPanel *PanelTopoPendentes;
	TLabel *LabelCabecalhoTitulo;
	TLabel *LabelCabecalhoSubTitulo;
	TPanel *Panel1;
	TLabel *Label2;
	TDateTimePicker *data_final;
	TDateTimePicker *data_inicial;
	TLabel *Label3;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall GridPendentesDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall GridPendentesSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall GridPendentesDetalhadaDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall GridPendentesDetalhadaSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall ButtonFiltrarPendentesClick(TObject *Sender);

private:
	int rowselect;
	int rowselect_pendentes_detalhada;
	int dias_notificao;
	int id_cliente;

	void GerarGridPendentes();
	void DesignerPendentes();
	void GerarGridPendentesDetalhada();
    void loadCabecalho();
public:
	__fastcall TFContasFinalizadas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFContasFinalizadas *FContasFinalizadas;
//---------------------------------------------------------------------------
#endif
