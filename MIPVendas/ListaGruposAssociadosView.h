//---------------------------------------------------------------------------
#ifndef ListaGruposAssociadosViewH
#define ListaGruposAssociadosViewH
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
#include <Vcl.Buttons.hpp>
#include <jpeg.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Rtti.hpp>
//---------------------------------------------------------------------------
#include "GridHelper.h"
#include "CrudController.h"
//---------------------------------------------------------------------------
class TFListaGruposAssociadosView : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelSearch;
	TSQLQuery *SQLQuery1;
	TSpeedButton *BtSearch;
	TSpeedButton *BtInsert;
	TLabel *Label3;
	TComboBox *ComboPage;
	TPanel *PanelOptions;
	TEdit *EditBusca;
	TLabel *Label5;
	TComboBox *ComboPerPage;
	TLabel *Label4;
	TCheckBox *CheckFilterAdvanced;
	TPanel *PanelTitle;
	TLabel *LabelCabecalhoTitulo;
	TLabel *LabelCabecalhoSubTitulo;
	TScrollBox *ScrollBox1;
	TPanel *PanelFiltersOptions;
	TStringGrid *StringGridFilters;
	TPanel *PanelFiltersComponents;
	TLabel *Label1;
	TLabel *Label6;
	TLabel *Label2;
	TLabel *Label9;
	TEdit *EditFilterValue;
	TComboBox *ComboOperator;
	TComboBox *ComboField;
	TButton *ButtonFiltro;
	TButton *Button1;
	TComboBox *ComboLogic;
	TPanel *PanelSortOptions;
	TStringGrid *StringGridSort;
	TPanel *PanelSortComponents;
	TLabel *Label7;
	TLabel *Label8;
	TComboBox *ComboSortField;
	TComboBox *ComboSortOrder;
	TButton *Button2;
	TButton *Button3;
	TStringGrid *StringGridFields;
	TStringGrid *StringGrid1;
	void __fastcall EditFilterValueKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall StringGrid1DblClick(TObject *Sender);
	void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall BtSearchClick(TObject *Sender);
	void __fastcall BtInsertClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall StringGridFieldsDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall StringGridFieldsSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall ButtonFiltroClick(TObject *Sender);
	void __fastcall CheckFilterAdvancedClick(TObject *Sender);
	void __fastcall StringGridFiltersDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall StringGridSortDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall StringGridFiltersSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall StringGridFiltersMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall StringGridFieldsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall StringGridSortMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall StringGridSortSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall StringGrid1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);


private:
	int rowselectRecords;
	int colselectRecords;
	int rowselectFields;
	int colselectFields;
	int rowselectFilters;
	int colselectFilters;
	int rowselectSorts;
	int colselectSorts;

	void gridRecords();
	void loadView();
public:
	GridHelper *helperGridRecords;
	CrudController *controller;
	int editar;//0 - visualizar produto  ;  1 - adicionar ao orcamento
	__fastcall TFListaGruposAssociadosView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFListaGruposAssociadosView *FListaGruposAssociadosView;
//---------------------------------------------------------------------------
#endif
