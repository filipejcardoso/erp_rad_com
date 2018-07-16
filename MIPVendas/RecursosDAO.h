//---------------------------------------------------------------------------

#ifndef RecursosDAOH
#define RecursosDAOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include <Rtti.hpp>
#include "JSONRtti.h"
#include "Recursos.h"
#include "Result.h"
#include "Paginator.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFResourceDAO : public TDataModule
{
__published:	// IDE-managed Components
	TRESTClient *RESTClient;
	TRESTRequest *RESTRequest;
	TRESTResponse *RESTResponse;
private:	// User declarations
public:		// User declarations
	Paginator *paginate;
    UnicodeString resource;
	Result *result;
	TList* index(UnicodeString);
	TList* show(UnicodeString, int);
	__fastcall TFResourceDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFResourceDAO *FResourceDAO;
//---------------------------------------------------------------------------
#endif
