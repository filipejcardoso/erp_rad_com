//---------------------------------------------------------------------------

#pragma hdrstop

#include "ValueHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TValue ValueHelper::StrToValue(UnicodeString value, UnicodeString type)
{
	TValue valor;

	if(value.LowerCase().Trim() != "null")
	{
		if(type == "int")
			valor = TValue::From<int>(StrToInt(value));
		else if(type == "float")
			valor = TValue::From<float>(StrToFloat(value));
		else if(type == "UnicodeString")
			valor = TValue::From<UnicodeString>(value);
	}
	else
	{
		if(type == "int")
			valor = TValue::From<int>(0);
		else if(type == "float")
			valor = TValue::From<float>(0);
		else if(type == "UnicodeString")
			valor = TValue::From<UnicodeString>(" ");
	}

	return valor;
}
//---------------------------------------------------------------------------
UnicodeString ValueHelper::ValueToStr(TValue value)
{
	UnicodeString str;

	if(value.IsType<int>())
		str = StrToInt(value.AsInteger());
	else if(value.IsType<float>())
		str = FormatFloat("#,###,###,##0.00", value.AsExtended());
	else if(value.IsType<UnicodeString>())
		str = value.AsString();

    return str;
}
