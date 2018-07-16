//---------------------------------------------------------------------------

#ifndef HelperH
#define HelperH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <REST.Json.hpp>
#include <System.JSON.hpp>
#include <Rtti.hpp>
#include <typeinfo.h>
//---------------------------------------------------------------------------
class Helper
{
	private:

	public:
		static bool searchStrList(TList*, UnicodeString);
		static UnicodeString DateConvert(UnicodeString);
		static UnicodeString DateQuery(UnicodeString);
};
#endif

