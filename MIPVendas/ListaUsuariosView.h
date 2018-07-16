//---------------------------------------------------------------------------

#ifndef ListaUsuariosViewH
#define ListaUsuariosViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Rtti.hpp>
//---------------------------------------------------------------------------
#include "CrudController.h"
#include "GridHelper.h"
#include "Fields.h"
#include "JSONRtti.h"
//---------------------------------------------------------------------------
class TFListaUsuariosView : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TEdit *EditBusca;
	TLabel *Label3;
	TSpeedButton *BtSearch;
	TSpeedButton *BtInsert;
	TStringGrid *StringGridRecords;
	TPanel *PanelTitle;
	TLabel *LabelCabecalhoModulo;
	TLabel *LabelCabecalhoSubTitulo;
	TLabel *LabelCabecalhoTitulo;
	void __fastcall FormCreate(TObject *Sender);
    void __fastcall StringGridRecordsDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State);
	void __fastcall StringGridRecordsDblClick(TObject *Sender);
	void __fastcall StringGridRecordsSelectCell(TObject *Sender, int ACol,
		  int ARow, bool &CanSelect);
	void __fastcall StringGridRecordsMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y);
	void __fastcall BtSearchClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtInsertClick(TObject *Sender);
	void __fastcall EditBuscaKeyPress(TObject *Sender, System::WideChar &Key);
private:
    int rowselectRecords;
	int colselectRecords;
	Fields *field;
    TRttiContext context;

	void gridRecords();
	void loadView();
public:
	GridHelper *helperGridRecords;
	UsuariosController *controller;
	__fastcall TFListaUsuariosView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFListaUsuariosView *FListaUsuariosView;
//---------------------------------------------------------------------------
#endif
