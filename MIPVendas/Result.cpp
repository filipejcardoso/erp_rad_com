//---------------------------------------------------------------------------

#pragma hdrstop

#include "Result.h"
#include "JSONRtti.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void Result::setJSON(TJSONArray *json)
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(Result)));

	JSONRtti::serialize(this, cls, (TJSONObject*) json);
}
