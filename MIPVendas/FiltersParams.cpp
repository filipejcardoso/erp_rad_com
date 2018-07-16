//---------------------------------------------------------------------------

#pragma hdrstop

#include "FiltersParams.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void FiltersParams::addFilter(Field *field, UnicodeString logic, UnicodeString op, UnicodeString value)
{
	Filter *filter = new Filter();

	filter->field = field;
	filter->Logic = logic;
	filter->Operator = op;
	filter->Value = value;

	filters->Add(filter);

	filter->id = filters->Count;
}
//---------------------------------------------------------------------------
void FiltersParams::deleteChecked()
{
	for(int i=0;i<filters->Count;i++)
	{
		Filter *filter = (Filter*) filters->Items[i];

		if(filter->checked)
			filters->Delete(i--);
	}
}
//---------------------------------------------------------------------------
FiltersParams::FiltersParams()
{
	filters = new TList();
}
//---------------------------------------------------------------------------
FiltersParams::Filter::Filter()
{
	this->checked = false;
}

