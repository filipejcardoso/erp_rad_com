//---------------------------------------------------------------------------

#ifndef CategoriasViewH
#define CategoriasViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
#include "Categorias.h"
#include "CategoriasController.h"
#include "GridHelper.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFCategoriasView : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelOptions;
	TSpeedButton *Modificar;
	TSpeedButton *Adicionar;
	TSpeedButton *Deletar;
	TSpeedButton *Sair;
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TEdit *EditNome;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TEdit *EditSubcategoria;
	TStringGrid *StringGridSubcategorias;
	TSpeedButton *BtInsert;
	TSpeedButton *ButtonDeletarSubcategoria;
	TSpeedButton *ButtonEditarSubcategoria;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SairClick(TObject *Sender);
	void __fastcall AdicionarClick(TObject *Sender);
	void __fastcall DeletarClick(TObject *Sender);
	void __fastcall ModificarClick(TObject *Sender);
	void __fastcall StringGridSubcategoriasDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall StringGridSubcategoriasMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall StringGridSubcategoriasSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall BtInsertClick(TObject *Sender);
	void __fastcall ButtonDeletarSubcategoriaClick(TObject *Sender);
	void __fastcall ButtonEditarSubcategoriaClick(TObject *Sender);
private:
	void DesignerBotoes();
	void loadCategoria();
	void loadCategoriaModel();
    void loadClearFields();
	void loadView();

	int colselectSubcategorias;
	int rowselectSubcategorias;
    int editar_subcategoria;

	GridHelper *helperSubcategorias;

	void gridSubcategorias();

	void setEditarSubcategoria(bool);

public:
	Categorias *categoria;
	CategoriasController *controller;
	int editar;// 0 - adicionar 1 - editar 2 - visualizar
	__fastcall TFCategoriasView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFCategoriasView *FCategoriasView;
//---------------------------------------------------------------------------
#endif
