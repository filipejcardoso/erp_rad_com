//---------------------------------------------------------------------------

#pragma hdrstop

#include "Fields.h"
#include "ValueHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Fields::Fields(TRttiInstanceType *cls, UnicodeString relation)
{
	this->RttiInstance = cls;
    fieldsList = new TList();


	initList(this->RttiInstance, relation);
}
//--------------------------------------------------------------------------
void Fields::initList(TRttiInstanceType *cls, UnicodeString relation)
{
	TRttiField *field;
    UnicodeString typeStr;

	// Get fields RTTI
	DynamicArray<TRttiField*> fields = cls->GetFields();

	for(int k=0;k<fields.Length;k++)
	{
		field = fields[k];
		typeStr = field->FieldType->ToString();

		if(typeStr == "int" || typeStr == "float" || typeStr == "UnicodeString")
		{
			Field *fieldObj = new Field();

			fieldObj->column = field->Name;
			fieldObj->relation = relation;

			if(relation != NULL)
				fieldObj->name = relation + "_" + field->Name;
			else
				fieldObj->name = field->Name;

            fieldObj->text = fieldObj->name;

			fieldsList->Add(fieldObj);
		}
		else if(typeStr != "TList")
		{
			TRttiInstanceType *c = field->FieldType->AsInstance;

			initList(c, field->Name);
		}
	}
}
//--------------------------------------------------------------------------
int Fields::CountChecked()
{
	return getChecked()->Count;
}
//--------------------------------------------------------------------------
TList* Fields::getChecked()
{
	TList *listChecked = new TList();

    TList *listVisible = this->getVisible();
	for(int i=0;i<listVisible->Count;i++)
	{
        Field *field = (Field*) listVisible->Items[i];
		if(field->checked)
            listChecked->Add(field);
	}

	return listChecked;
}
//--------------------------------------------------------------------------
int Fields::CountVisible()
{
	return getVisible()->Count;
}
//--------------------------------------------------------------------------
TList* Fields::getVisible()
{
	TList *listVisible = new TList();

	for(int i=0;i<fieldsList->Count;i++)
	{
        Field *field = (Field*) fieldsList->Items[i];
		if(field->visible)
            listVisible->Add(field);
	}

	return listVisible;
}
//--------------------------------------------------------------------------
Field* Fields::GetField(UnicodeString value)
{
	Field *fieldGet = NULL;

	for(int i=0;i<fieldsList->Count;i++)
	{
        Field *field = (Field*) fieldsList->Items[i];
		if(field->name == value)
		{
			fieldGet = field;
            break;
        }
	}

	return fieldGet;
}
//---------------------------------------------------------------------------
Field* Fields::getPrimaryKey()
{
	Field *fieldGet = NULL;

	for(int i=0;i<fieldsList->Count;i++)
	{
        Field *field = (Field*) fieldsList->Items[i];
		if(field->primaryKey == true)
		{
			fieldGet = field;
            break;
        }
	}

	return fieldGet;
}

