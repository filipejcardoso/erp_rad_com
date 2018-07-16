//---------------------------------------------------------------------------

#pragma hdrstop

#include "QueryParams.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
QueryParams::QueryParams()
{
    fields = NULL;
	filters = new FiltersParams();
	sorts = new SortParams();
	paginate = new Paginator();

	this->ignoreFilters = false;
}
//---------------------------------------------------------------------------
UnicodeString QueryParams::getQuery()
{
	UnicodeString query;

	TList *fieldsQuery;
	TList *filtersQuery;
	TList *sortsQuery;

	Field *field;
	FiltersParams::Filter *filter;
	SortParams::Sort *sort;

	TList *fieldsParams = new TList();
	bool mark = false;

    query = "";

	if(fields)
	{
		//FIELDS
		fieldsQuery = this->fields->getChecked();
		query += "fields=";

		if(fieldsQuery->Count>0)
			mark = true;

		for(int i=0;i<fieldsQuery->Count;i++)
		{
			field = (Field*) fieldsQuery->Items[i];

			if(field->relation == NULL)
			{
				if(!Helper::searchStrList(fieldsParams, field->column))
				{
					if(i)
						query += ",";

					query += field->column;
					fieldsParams->Add(&field->column);
				}
			}
			else
			{
				if(!Helper::searchStrList(fieldsParams, field->relation))
				{
					if(i)
						query += ",";

					query += field->relation;
					fieldsParams->Add(&field->relation);
				}
			}
		}
	}

	//FILTER
	if(this->ignoreFilters)
		filtersQuery = this->getFiltersIgnore();
	else
		filtersQuery = filters->filters;

	for(int i = 0;i<filtersQuery->Count;i++)
	{
		if(mark)
			query += "&";
		else
			mark = true;

		filter = (FiltersParams::Filter*)filtersQuery->Items[i];
		field = filter->field;

		if(field->relation == NULL)
			query += filter->Logic + field->column + "[]=" + filter->Operator +"," + filter->Value;
		else
			query += filter->Logic + field->relation + "[]=" + field->column + "," + filter->Operator + "," + filter->Value;
	}

	//SORT
	sortsQuery = sorts->sorts;

	if(sortsQuery->Count > 0)
	{
		if(mark)
			query += "&sort=";
		else
		{
			mark = true;
			query += "sort=";
		}
		for(int i = 0;i<sortsQuery->Count;i++)
		{

			sort = (SortParams::Sort*)sortsQuery->Items[i];
			field = sort->field;

			if(field->relation == NULL)
			{
				if(i)
					query += "," + sort->OrderTag + field->column;
				else
					query += sort->OrderTag + field->column;
			}
		}
	}

	//PAGINATE
	if(paginate->per_page != 0)
	{
		if(mark)
			query += "&";

		query += "limit=" + IntToStr(paginate->per_page);
		if(paginate->current_page!=0)
			query += "&page=" + IntToStr(paginate->current_page);
	}

	return query;
}
//---------------------------------------------------------------------------
TList* QueryParams::getFiltersIgnore()
{
	UnicodeString logic = "AND";

	FiltersParams *filtersIgnore = new FiltersParams();

	TList *fieldsChecked = this->fields->getChecked();

	for(int i=0;i<fieldsChecked->Count;i++)
	{
		Field *field = (Field*) fieldsChecked->Items[i];

		filtersIgnore->addFilter(field, logic, "like", ignoreFilterValue);

		if(!i)
            logic = "OR";
    }

    return filtersIgnore->filters;
}
