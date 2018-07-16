//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ListaTiposContatosView.h"
#include "Principal.h"
#include "TiposContatosView.h"
#include "Produtos.h"
#include "Field.h"
#include "GridHelper.h"
#include "Style.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFListaTiposContatosView *FListaTiposContatosView;
//---------------------------------------------------------------------------
__fastcall TFListaTiposContatosView::TFListaTiposContatosView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFListaTiposContatosView::EditFilterValueKeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key == 13)
		BtSearch->Click();
}
//---------------------------------------------------------------------------
void __fastcall TFListaTiposContatosView::FormCreate(TObject *Sender)
{
    //CONFIGURAR O FORM
	ConfigurarForm(this);

	helperGridRecords = new GridHelper(this->StringGrid1);
	helperGridRecords->primaryKey = true;
	helperGridRecords->checkOnlyOne = true;

	controller = new CrudController();

	controller->CheckFilterAdvanced = this->CheckFilterAdvanced;

	controller->ComboFilterField = this->ComboField;
	controller->ComboFilterOperator = this->ComboOperator;
	controller->ComboFilterLogic = this->ComboLogic;
	controller->ComboPerPage = this->ComboPerPage;
	controller->ComboPage = this->ComboPage;
	controller->ComboSortField = this->ComboSortField;
	controller->ComboSortOrder = this->ComboSortOrder;

	controller->EditSearch = this->EditBusca;
	controller->EditFilterValue = this->EditFilterValue;

    controller->StringGridRecords = this->StringGrid1;
    controller->StringGridFields = this->StringGridFields;
    controller->StringGridFilters = this->StringGridFilters;
    controller->StringGridSort = this->StringGridSort;
}
//---------------------------------------------------------------------------
void __fastcall TFListaTiposContatosView::StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
    UnicodeString Texto;
	tagRECT *rc;

	rc = new tagRECT();
	rc->left = Rect.Left;
	rc->top = Rect.top;
	rc->right = Rect.Right;
	rc->bottom = Rect.Bottom;

	TList *fields = controller->getFields()->getVisible();

	if (ARow>0)
	{
		Texto = StringGrid1->Cells[ACol][ARow];

		StringGrid1->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGrid1->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGrid1->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGrid1->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGrid1->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGrid1->Canvas->FillRect(Rect);
		StringGrid1->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGrid1->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

		/*--------------------COLOCAR CHECKBOX----------------------------*/
		if(helperGridRecords)
			if(helperGridRecords->checkBox)
			{
				if(ACol == 1)
				{
					if(helperGridRecords->isChecked(ARow))
						DrawFrameControl(StringGrid1->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
					else
						DrawFrameControl(StringGrid1->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK);
				}
			}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFListaTiposContatosView::StringGrid1DblClick(TObject *Sender)
{
	TiposContatos *tipos_contato = (TiposContatos*)controller->recordsList->Items[rowselectRecords - 1];

	FTiposContatosView->editar = 1;
	FTiposContatosView->tipos_contato->id = tipos_contato->id;
	FTiposContatosView->tipos_contato->nome = tipos_contato->nome;
	FTiposContatosView->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFListaTiposContatosView::StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselectRecords = ARow;
	colselectRecords = ACol;
}
//---------------------------------------------------------------------------
void __fastcall TFListaTiposContatosView::BtSearchClick(TObject *Sender)
{
	gridRecords();
}
//---------------------------------------------------------------------------
void __fastcall TFListaTiposContatosView::BtInsertClick(TObject *Sender)
{
	FTiposContatosView->editar = 0;
	FTiposContatosView->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFListaTiposContatosView::FormDestroy(TObject *Sender)
{
    delete controller;
}
//---------------------------------------------------------------------------
void TFListaTiposContatosView::gridRecords()
{
	controller->gridRecords();
	if(helperGridRecords->checkBox)
        helperGridRecords->insertCol(1);
}
//---------------------------------------------------------------------------
void TFListaTiposContatosView::loadView()
{
	this->CheckFilterAdvanced->Checked = FALSE;
	PanelOptions->Visible = FALSE;

	controller->loadComboFilterField();
	controller->loadComboFilterOperator();
	controller->loadComboFilterLogic();
	controller->loadComboPage();
	controller->loadComboPerPage();
	controller->loadComboSortField();
	controller->loadComboSortOrder();

	controller->gridFields();
	controller->gridFilters();
	gridRecords();
	controller->gridSorts();

    EditBusca->SetFocus();
}
//---------------------------------------------------------------------------//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::StringGridFieldsDrawCell(TObject *Sender,
          int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    UnicodeString Texto;
	tagRECT *rc;

	rc = new tagRECT();
	rc->left = Rect.Left;
	rc->top = Rect.top;
	rc->right = Rect.Right;
	rc->bottom = Rect.Bottom;

	TList *fields = controller->getFields()->getVisible();

	if (ARow>0)
	{
		Texto = StringGridFields->Cells[ACol][ARow];

		StringGridFields->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGridFields->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGridFields->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGridFields->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGridFields->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGridFields->Canvas->FillRect(Rect);
		StringGridFields->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGridFields->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

		/*--------------------COLOCAR CHECKBOX----------------------------*/
		if(ACol == 0)
		{
			Field *field = (Field*) fields->Items[ARow - 1];

			if(field->checked == true)
				DrawFrameControl(StringGridFields->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
			else
				DrawFrameControl(StringGridFields->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK);
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TFListaTiposContatosView::StringGridFieldsSelectCell(TObject *Sender,
		  int ACol, int ARow, bool &CanSelect)
{
	rowselectFields = ARow;
	colselectFields = ACol;
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::ButtonFiltroClick(TObject *Sender)
{
    controller->addFilter();
}
//---------------------------------------------------------------------------


void __fastcall TFListaTiposContatosView::CheckFilterAdvancedClick(TObject *Sender)
{
	PanelOptions->Visible = CheckFilterAdvanced->Checked;

	GridHelper *grid = new GridHelper();
	grid->primaryKey = true;
	grid->StringGrid = StringGrid1;
    grid->sizeGrid();
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::StringGridFiltersDrawCell(TObject *Sender,
          int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    UnicodeString Texto;
	tagRECT *rc;

	rc = new tagRECT();
	rc->left = Rect.Left;
	rc->top = Rect.top;
	rc->right = Rect.Right;
	rc->bottom = Rect.Bottom;

	if (ARow>0)
	{
		Texto = StringGridFilters->Cells[ACol][ARow];

		StringGridFilters->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGridFilters->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGridFilters->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGridFilters->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGridFilters->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGridFilters->Canvas->FillRect(Rect);
		StringGridFilters->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGridFilters->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

		/*--------------------COLOCAR CHECKBOX----------------------------*/
		if(ACol == 0)
		{
	        TList *filterList = controller->queryParams->filters->filters;
			if(filterList->Count>0)
			{
				FiltersParams::Filter *filter = (FiltersParams::Filter*) filterList->Items[ARow - 1];

				if(filter->checked == true)
					DrawFrameControl(StringGridFilters->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
				else
					DrawFrameControl(StringGridFilters->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK);
            }
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::StringGridSortDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
    UnicodeString Texto;
	tagRECT *rc;

	rc = new tagRECT();
	rc->left = Rect.Left;
	rc->top = Rect.top;
	rc->right = Rect.Right;
	rc->bottom = Rect.Bottom;

	if (ARow>0)
	{
		Texto = StringGridSort->Cells[ACol][ARow];

		StringGridSort->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGridSort->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGridSort->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGridSort->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGridSort->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGridSort->Canvas->FillRect(Rect);
		StringGridSort->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGridSort->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

		/*--------------------COLOCAR CHECKBOX----------------------------*/
		if(ACol == 0)
		{
	        TList *sortsList = controller->queryParams->sorts->sorts;
			if(sortsList->Count>0)
			{
				SortParams::Sort *sort = (SortParams::Sort*) sortsList->Items[ARow - 1];

				if(sort->checked == true)
					DrawFrameControl(StringGridSort->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
				else
					DrawFrameControl(StringGridSort->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK);
            }
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TFListaTiposContatosView::StringGridFiltersSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselectFilters = ARow;
	colselectFilters = ACol;
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::StringGridFiltersMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	TList *filtersList = controller->queryParams->filters->filters;

	if(colselectFilters == 0 && rowselectFilters>0)
	{
		if(filtersList->Count > 0)
		{
			FiltersParams::Filter *filter = (FiltersParams::Filter*) filtersList->Items[rowselectFilters - 1];

			if(filter->checked)
				filter->checked = false;
			else
				filter->checked = true;
		}
	}

    StringGridFilters->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::StringGridFieldsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	TList *fields = controller->getFields()->getVisible();

	if(colselectFields == 0 && rowselectFields>0)
	{
		Field *field = (Field*) fields->Items[rowselectFields - 1];

		if(field->checked)
			field->checked = false;
		else
        	field->checked = true;
	}

    StringGridFields->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::Button1Click(TObject *Sender)
{
    controller->deleteFilter();
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::Button2Click(TObject *Sender)
{
    controller->addSort();
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::Button3Click(TObject *Sender)
{
    controller->deleteSort();
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::StringGridSortMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	TList *sortsList = controller->queryParams->sorts->sorts;

	if(colselectSorts == 0 && rowselectSorts>0)
	{
		if(sortsList->Count > 0)
		{
			SortParams::Sort *sort = (SortParams::Sort*) sortsList->Items[rowselectSorts - 1];

			if(sort->checked)
				sort->checked = false;
			else
				sort->checked = true;
		}
	}

    StringGridSort->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::StringGridSortSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{
	rowselectSorts = ARow;
	colselectSorts = ACol;
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::FormShow(TObject *Sender)
{
	//STYLE DO FORM
	Style::setTop(LabelCabecalhoTitulo, LabelCabecalhoSubTitulo, "Tipos de Contato");

	loadView();
}
//---------------------------------------------------------------------------

void __fastcall TFListaTiposContatosView::StringGrid1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(helperGridRecords)
		if(helperGridRecords->checkBox)
		{
			if(colselectRecords == 1)
				helperGridRecords->selectRow(rowselectRecords);

			StringGrid1->Repaint();
		}
}
//---------------------------------------------------------------------------

