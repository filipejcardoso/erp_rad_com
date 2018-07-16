//---------------------------------------------------------------------------

#pragma hdrstop

#include "CrudController.h"
#include "ListaProdutosView.h"
#include "Helper.h"
#include "ProdutosDAO.h"
#include "AssociadosDAO.h"
#include "GridHelper.h"
#include "Paginator.h"
#include "ValueHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void CrudController::addFilter()
{
	int index = this->ComboFilterField->ItemIndex;

	Field *field = (Field*) this->ComboFilterField->Items[0].Objects[index];

	queryParams->filters->addFilter(field, this->ComboFilterLogic->Text, this->ComboFilterOperator->Text, this->EditFilterValue->Text);

	gridFilters();
}
//---------------------------------------------------------------------------
void CrudController::deleteFilter()
{
	queryParams->filters->deleteChecked();

	gridFilters();
}
//---------------------------------------------------------------------------
void CrudController::addSort()
{
	int index = this->ComboSortField->ItemIndex;

	Field *field = (Field*) this->ComboSortField->Items[0].Objects[index];

	queryParams->sorts->addSort(field, this->ComboSortOrder->Text);

	gridSorts();
}
//---------------------------------------------------------------------------
void CrudController::deleteSort()
{
	queryParams->sorts->deleteChecked();

	gridSorts();
}
//---------------------------------------------------------------------------
CrudController::CrudController()
{
	queryParams = new QueryParams();
}
//---------------------------------------------------------------------------
void CrudController::gridFilters()
{
	int numerodalinha,i,c;

	c = StringGridFilters->RowCount;

	for(i=1;i<c;i++)
		StringGridFilters->Rows[i]->Clear();

	numerodalinha = 1;
	//ESTRUTURA
	StringGridFilters->Options << goRowSelect;
	StringGridFilters->ScrollBars = ssVertical;
	StringGridFilters->Rows[1]->Clear();
	StringGridFilters->RowCount = 0;
	StringGridFilters->ColCount = 5;
	StringGridFilters->FixedCols = 0;
	StringGridFilters->ColWidths[0] = 50;
	StringGridFilters->ColWidths[1] = (StringGridFilters->Width/4 - 50);
	StringGridFilters->ColWidths[2] = (StringGridFilters->Width/4);
	StringGridFilters->ColWidths[3] = (StringGridFilters->Width/4);
	StringGridFilters->ColWidths[4] = (StringGridFilters->Width/4);
	StringGridFilters->Cells[1][0] = "&|";
	StringGridFilters->Cells[2][0] = "Field";
	StringGridFilters->Cells[3][0] = "Operator";
	StringGridFilters->Cells[4][0] = "Value";
	//ESTRUTURA

	TList *filters = queryParams->filters->filters;

	for(i=0; i<filters->Count; i++)
	{
		StringGridFilters->Cells[1][numerodalinha] = ((FiltersParams::Filter*)filters->Items[i])->Logic;
		StringGridFilters->Cells[2][numerodalinha] = ((FiltersParams::Filter*)filters->Items[i])->field->text;
		StringGridFilters->Cells[3][numerodalinha] = ((FiltersParams::Filter*)filters->Items[i])->Operator;
		StringGridFilters->Cells[4][numerodalinha] = ((FiltersParams::Filter*)filters->Items[i])->Value;

		StringGridFilters->RowCount++;

		numerodalinha++;

		if (numerodalinha == 2)
			StringGridFilters->FixedRows = 1;
	}
	if (numerodalinha <= 1)
	{
		StringGridFilters->RowCount++;
		StringGridFilters->FixedRows = 1;
	}
}
//---------------------------------------------------------------------------
void CrudController::gridSorts()
{
	int numerodalinha,i,c;

	c = StringGridSort->RowCount;

	for(i=1;i<c;i++)
		StringGridSort->Rows[i]->Clear();

	numerodalinha = 1;
	//ESTRUTURA
	StringGridSort->Options << goRowSelect;
	StringGridSort->ScrollBars = ssVertical;
	StringGridSort->Rows[1]->Clear();
	StringGridSort->RowCount = 0;
	StringGridSort->ColCount = 3;
	StringGridSort->FixedCols = 0;
	StringGridSort->ColWidths[0] = 50;
	StringGridSort->ColWidths[1] = (StringGridSort->Width/2 - 50);
	StringGridSort->ColWidths[2] = (StringGridSort->Width/2);
	StringGridSort->Cells[1][0] = "Field";
	StringGridSort->Cells[2][0] = "Order";
	//ESTRUTURA

	TList *sorts = queryParams->sorts->sorts;

	for(i=0; i<sorts->Count; i++)
	{
		StringGridSort->Cells[1][numerodalinha] = ((SortParams::Sort*)sorts->Items[i])->field->text;
		StringGridSort->Cells[2][numerodalinha] = ((SortParams::Sort*)sorts->Items[i])->Order;

		StringGridSort->RowCount++;

		numerodalinha++;

		if (numerodalinha == 2)
			StringGridSort->FixedRows = 1;
	}
	if (numerodalinha <= 1)
	{
		StringGridSort->RowCount++;
		StringGridSort->FixedRows = 1;
	}
}
//---------------------------------------------------------------------------
TList* CrudController::getRecords()
{
    TList* records;

    queryParams->ignoreFilterValue = EditSearch->Text;
	queryParams->ignoreFilters = !this->CheckFilterAdvanced->Checked;

	TRttiMethod *method = cls->GetMethod("index");

	TValue valor = ValueHelper::StrToValue(queryParams->getQuery(), "UnicodeString");

	TValue recordsValue = method->Invoke(instance, &valor , 0);

	records = (TList*) recordsValue.AsObject();

	recordsList = records;

	return recordsList;
}
//---------------------------------------------------------------------------
Fields* CrudController::getFields()
{
	return queryParams->fields;
}
//---------------------------------------------------------------------------
void CrudController::loadComboPerPage()
{
	ComboPerPage->Clear();

	for(int i=1;i<=500;i++)
		ComboPerPage->Items->Add(i);

    ComboPerPage->ItemIndex = 14;
}
//---------------------------------------------------------------------------
void CrudController::loadComboFilterField()
{
	this->ComboFilterField->Clear();

	TList *fields = this->getFields()->getVisible();

	Field *field;
	for(int i=0; i<fields->Count; i++)
	{
		field = (Field*) fields->Items[i];

		this->ComboFilterField->AddItem(field->text,(TObject*) field);
    }

    this->ComboFilterField->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void CrudController::loadComboPage()
{
	ComboPage->Clear();

    if(queryParams->paginate!=NULL)
	{
		for(int i=1;i<=queryParams->paginate->last_page;i++)
			ComboPage->Items->Add(i);

		ComboPage->ItemIndex = queryParams->paginate->current_page - 1;
	}
	else
	{
		ComboPage->Items->Add(1);
        ComboPage->ItemIndex = 0;
	}

}
//---------------------------------------------------------------------------
void CrudController::loadComboSortField()
{
	this->ComboSortField->Clear();

	TList *fields = this->getFields()->getVisible();

	Field *field;
	for(int i=0; i<fields->Count; i++)
	{
		field = (Field*) fields->Items[i];

		this->ComboSortField->AddItem(field->text,(TObject*) field);
    }

    this->ComboSortField->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void CrudController::loadComboSortOrder()
{
	this->ComboSortOrder->Clear();

	this->ComboSortOrder->Items->Add("ASC");
	this->ComboSortOrder->Items->Add("DESC");

	this->ComboSortOrder->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void CrudController::loadComboFilterOperator()
{
	this->ComboFilterOperator->Clear();

    this->ComboFilterOperator->Items->Add("like");
    this->ComboFilterOperator->Items->Add("=");
    this->ComboFilterOperator->Items->Add(">");
    this->ComboFilterOperator->Items->Add("<");
	this->ComboFilterOperator->Items->Add("<>");

    this->ComboFilterOperator->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void CrudController::loadComboFilterLogic()
{
	this->ComboFilterLogic->Clear();

	this->ComboFilterLogic->Items->Add("AND");
	this->ComboFilterLogic->Items->Add("OR");

	this->ComboFilterLogic->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void CrudController::gridFields()
{
	int numerodalinha,i,c;

	c = StringGridFields->RowCount;

	for(i=0;i<c;i++)
		StringGridFields->Rows[i]->Clear();

	numerodalinha = 1;
	//ESTRUTURA
	StringGridFields->Options << goRowSelect;
	StringGridFields->ScrollBars = ssVertical;
	StringGridFields->Rows[1]->Clear();
	StringGridFields->RowCount = 0;
	StringGridFields->ColCount = 2;
	StringGridFields->FixedCols = 0;
	StringGridFields->Cells[1][0] = "Fields";
	StringGridFields->ColWidths[0] = 50;
	StringGridFields->ColWidths[1] = StringGridFields->Width-50;
	//ESTRUTURA

	TList *fields = this->getFields()->getVisible();

	Field *field;
	for(i=0; i<fields->Count; i++)
	{
		field = (Field*) fields->Items[i];

		StringGridFields->Cells[1][numerodalinha] = field->text;

		StringGridFields->RowCount++;

		numerodalinha++;

		if (numerodalinha == 2)
			StringGridFields->FixedRows = 1;
	}
	if (numerodalinha <= 1)
		StringGridFields->RowCount++;
}
//---------------------------------------------------------------------------
void CrudController::gridRecords()
{
	this->setPaginate();

	GridHelper *grid = new GridHelper();

	grid->StringGrid = StringGridRecords;
    grid->primaryKey = true;
	grid->list = this->getRecords();
	grid->fields = this->getFields();

	grid->gerarGrid();

	this->loadComboPage();
}
//---------------------------------------------------------------------------
void CrudController::setPaginate()
{
	int pageMax;
    int restPage;

	queryParams->paginate->per_page = ComboPerPage->ItemIndex + 1;
	queryParams->paginate->current_page = ComboPage->ItemIndex + 1;

	pageMax = queryParams->paginate->count/queryParams->paginate->per_page;
	restPage = queryParams->paginate->count % queryParams->paginate->per_page;

    if(restPage)
        pageMax++;

	if(queryParams->paginate->current_page > (pageMax))
        queryParams->paginate->current_page = pageMax;
}

