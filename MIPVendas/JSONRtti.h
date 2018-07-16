//---------------------------------------------------------------------------

#ifndef JSONRttiH
#define JSONRttiH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <REST.Json.hpp>
#include <System.JSON.hpp>
#include <Rtti.hpp>
//---------------------------------------------------------------------------
class JSONRtti
{
	private:

	public:
		static void serialize(void* instance, TRttiInstanceType *cls, TJSONObject *json);
		static TJSONObject* deserialize(TObject*);
};
#endif

