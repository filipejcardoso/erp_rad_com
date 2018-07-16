//---------------------------------------------------------------------------

#ifndef ValueHelperH
#define ValueHelperH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <REST.Json.hpp>
#include <System.JSON.hpp>
#include <Rtti.hpp>
//---------------------------------------------------------------------------
class ValueHelper
{
	private:

	public:
		static TValue StrToValue(UnicodeString value, UnicodeString type);
		static UnicodeString ValueToStr(TValue value);
};
#endif

