//---------------------------------------------------------------------------

#ifndef AuthDaoH
#define AuthDaoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include <REST.Json.hpp>
#include <Rtti.hpp>
#include "User.h"
#include "Result.h"
#include "JSONRtti.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFAuthDAO : public TDataModule
{
__published:	// IDE-managed Components
	TRESTClient *RESTClient;
	TRESTRequest *RESTRequest;
	TRESTResponse *RESTResponse;
private:
    UnicodeString resource;
public:
    Result *result;
	User* login(User*);
	void logout();

	__fastcall TFAuthDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAuthDAO *FAuthDAO;
//---------------------------------------------------------------------------
#endif
