//---------------------------------------------------------------------------

#ifndef CrudControllerH
#define CrudControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Rtti.hpp>
#include "Fields.h"
#include "QueryParams.h"
//---------------------------------------------------------------------------
class CrudController
{
private:

public:
    TList *recordsList;
	TRttiInstanceType *cls;
    TObject *instance;
	QueryParams *queryParams;
	void *RecursoController;

	TCheckBox *CheckFilterAdvanced;

	TComboBox *ComboFilterField;
	TComboBox *ComboFilterOperator;
	TComboBox *ComboFilterLogic;
	TComboBox *ComboPerPage;
	TComboBox *ComboPage;
	TComboBox *ComboSortField;
	TComboBox *ComboSortOrder;

	TEdit *EditSearch;
	TEdit *EditFilterValue;

	TStringGrid *StringGridRecords;
	TStringGrid *StringGridFields;
	TStringGrid *StringGridFilters;
	TStringGrid *StringGridSort;

	CrudController();

	Fields* getFields();

	TList* getRecords();

	void addFilter();
	void deleteFilter();

	void addSort();
	void deleteSort();

    void setPaginate();

	void gridFilters();
	void gridFields();
	void gridRecords();
	void gridSorts();

	void loadComboFilterField();
	void loadComboFilterOperator();
	void loadComboFilterLogic();
	void loadComboPerPage();
	void loadComboPage();
	void loadComboSortField();
	void loadComboSortOrder();
};

#endif
