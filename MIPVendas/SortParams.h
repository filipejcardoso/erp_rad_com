//---------------------------------------------------------------------------

#ifndef SortParamsH
#define SortParamsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Rtti.hpp>
#include "Fields.h"
//---------------------------------------------------------------------------
class SortParams
{
	private:

	public:
		class Sort;
		TList *sorts;
		void addSort(Field *field, UnicodeString order);
		void deleteChecked();
		SortParams::SortParams();
};
class SortParams::Sort
{
    public:
		int id;
		Field *field;
		UnicodeString Order;
		UnicodeString OrderTag;
		bool checked;

        Sort();
};
#endif

