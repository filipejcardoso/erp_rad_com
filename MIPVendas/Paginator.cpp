//---------------------------------------------------------------------------

#pragma hdrstop

#include "Paginator.h"
#include "JSONRtti.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Paginator::Paginator()
{
	per_page = 0;
	current_page = 0;
	last_page = 0;
	count = 0;
}
Paginator::Paginator(TJSONArray *json)
{
	this->setJSON(json);
}
//---------------------------------------------------------------------------
void Paginator::setJSON(TJSONArray *json)
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(Paginator)));

	JSONRtti::serialize(this, cls, (TJSONObject*) json);
}

