//---------------------------------------------------------------------------

#ifndef QueryParamsH
#define QueryParamsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Rtti.hpp>
#include "Fields.h"
#include "FiltersParams.h"
#include "SortParams.h"
#include "Paginator.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class QueryParams
{
	private:
        TList* getFiltersIgnore();

	public:
		Fields *fields;
		FiltersParams *filters;
		SortParams *sorts;
		Paginator *paginate;

		bool ignoreFilters;
        UnicodeString ignoreFilterValue;

		QueryParams::QueryParams();
        UnicodeString getQuery();
};
#endif

