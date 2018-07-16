//---------------------------------------------------------------------------

#pragma hdrstop

#include "Helper.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
bool Helper::searchStrList(TList *list, UnicodeString str)
{
	bool result = false;

	for(int i=0;i<list->Count;i++)
	{
		UnicodeString *str_list = (UnicodeString*) list->Items[i];

		if(!str_list->Compare(str))
		{
			result = true;
			break;
		}
	}

	return result;
}
//---------------------------------------------------------------------------
UnicodeString Helper::DateConvert(UnicodeString data)
{
	int step;
	wchar_t *newdate;
	UnicodeString dia,mes,ano,dataStr;

	newdate = data.c_str();

	step = 0;
	dia = mes = ano = "";
	for(int i=0;newdate[i]!=0;i++)
	{
		if(newdate[i] == '-')
		{
			i++;
			step++;
		}

		switch(step)
		{
			case 0:
				ano = ano + newdate[i];
			break;
			case 1:
				mes = mes + newdate[i];
			break;
			case 2:
				dia = dia + newdate[i];
			break;
		}
	}

	dataStr = dia + "/" + mes + "/" + ano;

	return dataStr;
}
//---------------------------------------------------------------------------
UnicodeString Helper::DateQuery(UnicodeString data)
{
	int step;
	wchar_t *newdate;
	UnicodeString dia,mes,ano,dataStr;

	newdate = data.c_str();

	step = 0;
	dia = mes = ano = "";
	for(int i=0;newdate[i]!=0;i++)
	{
		if(newdate[i] == '/')
		{
			i++;
			step++;
		}

		switch(step)
		{
			case 0:
				dia = dia + newdate[i];
			break;
			case 1:
				mes = mes + newdate[i];
			break;
			case 2:
				ano = ano + newdate[i];
			break;
		}
	}

	dataStr = ano + "-" + mes + "-" + dia;

	return dataStr;
}


