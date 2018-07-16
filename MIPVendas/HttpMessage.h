//---------------------------------------------------------------------------

#ifndef HttpMessageH
#define HttpMessageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <REST.Json.hpp>
#include <System.JSON.hpp>
#include <Rtti.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include "Result.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) HttpMessage : public TPersistent
{
	private:

	public:
		static int check(TJSONObject*, int);
		static int check(TJSONObject*, TRESTRequest*, TRESTResponse*, int);
		static int storeMessage(Result*);
		static int updateMessage(Result*);
		static int destroyMessage(Result*);

		static int internalMessage(Result*);
		static int invalidParams(Result*);
		static int notFound(Result*);
		static int roleDenied(Result*);
		static int checkExpired(Result*);
};
#endif
