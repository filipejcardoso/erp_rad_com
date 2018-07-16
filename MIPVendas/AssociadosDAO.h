//---------------------------------------------------------------------------

#ifndef AssociadosDAOH
#define AssociadosDAOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include <REST.Json.hpp>
#include <Rtti.hpp>
#include "Model.h"
#include "JSONRtti.h"
#include "Paginator.h"
#include "Result.h"
#include "Associados.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFAssociadosDAO : public TDataModule
{
__published:
	TRESTClient *RESTClient;
	TRESTRequest *RESTRequest;
	TRESTResponse *RESTResponse;
private:

public:

    UnicodeString resource;
	Paginator *paginate;
    Result *result;
	TList* index(UnicodeString);
    TList *show(UnicodeString, int);
	TList *store(Associados*);
    TList *update(Associados*);
	void destroy(Associados*);
	__fastcall TFAssociadosDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAssociadosDAO *FAssociadosDAO;
//---------------------------------------------------------------------------

#endif
