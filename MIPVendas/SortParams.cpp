//---------------------------------------------------------------------------

#pragma hdrstop

#include "SortParams.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void SortParams::addSort(Field *field, UnicodeString order)
{
	Sort *sort = new Sort();

	sort->field = field;
	sort->Order = order;

	if(sort->Order.UpperCase() == "ASC")
		sort->OrderTag = "A";
	else if(sort->Order.UpperCase() == "DESC")
		sort->OrderTag = "D";

	sorts->Add(sort);

	sort->id = sorts->Count;
}
//---------------------------------------------------------------------------
void SortParams::deleteChecked()
{
	for(int i=0;i<sorts->Count;i++)
	{
		Sort *sort = (Sort*) sorts->Items[i];

		if(sort->checked)
			sorts->Delete(i--);
	}
}
//---------------------------------------------------------------------------
SortParams::SortParams()
{
	sorts = new TList();
}
//---------------------------------------------------------------------------
SortParams::Sort::Sort()
{
	this->checked = false;
}
