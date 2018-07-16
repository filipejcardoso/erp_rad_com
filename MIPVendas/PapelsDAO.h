//---------------------------------------------------------------------------

#ifndef PapelsDAOH
#define PapelsDAOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include "Result.h"
#include "Paginator.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFPapelsDAO : public TDataModule
{
__published:	// IDE-managed Components
	TRESTClient *RESTClient;
	TRESTRequest *RESTRequest;
	TRESTResponse *RESTResponse;
private:
    UnicodeString resource;
public:
    Result *result;
	Paginator *paginate;
	TList* index(UnicodeString);
	TList* show(UnicodeString, int);
    TList* store();
	__fastcall TFPapelsDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPapelsDAO *FPapelsDAO;
//---------------------------------------------------------------------------
#endif
