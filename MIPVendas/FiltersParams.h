//---------------------------------------------------------------------------

#ifndef FiltersParamsH
#define FiltersParamsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Rtti.hpp>
#include "Fields.h"
//---------------------------------------------------------------------------
class FiltersParams
{
	private:

	public:
		class Filter;
		TList *filters;
		void addFilter(Field *field, UnicodeString logic, UnicodeString op, UnicodeString value);
		void deleteChecked();
		FiltersParams::FiltersParams();
};
class FiltersParams::Filter
{
    public:
		int id;
		Field *field;
		UnicodeString Logic;
		UnicodeString Operator;
		UnicodeString Value;
		bool checked;

        Filter();
};
#endif

