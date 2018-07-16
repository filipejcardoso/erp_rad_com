//---------------------------------------------------------------------------

#pragma hdrstop

#include "Field.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Field::Field()
{
	this->visible = false;
	this->checked = true;
	this->primaryKey = false;
	this->required = false;
}
void Field::check(bool value)
{
    if(value)
		Fchecked = value;
	else if(!required)
		Fchecked = value;
}
