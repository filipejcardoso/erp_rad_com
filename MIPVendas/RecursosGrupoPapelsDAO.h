//---------------------------------------------------------------------------

#ifndef RecursosGrupoPapelsDAOH
#define RecursosGrupoPapelsDAOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include "RecursosGrupoPapels.h"
#include "Result.h"
#include "Paginator.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFRecursosGrupoPapelsDAO : public TDataModule
{
__published:	// IDE-managed Components
	TRESTClient *RESTClient;
	TRESTRequest *RESTRequest;
	TRESTResponse *RESTResponse;
private:	// User declarations
    UnicodeString resource;
public:		// User declarations
	Result* result;
    Paginator *paginate;

	TList* store();
	__fastcall TFRecursosGrupoPapelsDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFRecursosGrupoPapelsDAO *FRecursosGrupoPapelsDAO;
//---------------------------------------------------------------------------
#endif
