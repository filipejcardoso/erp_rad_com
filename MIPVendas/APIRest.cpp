//---------------------------------------------------------------------------

#pragma hdrstop

#include "APIRest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
UnicodeString APIRest::getBaseURL()
{
    UnicodeString url = "http://" + host + "/api/" + version;

	return url;
}
