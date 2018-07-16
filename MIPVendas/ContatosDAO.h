//---------------------------------------------------------------------------

#ifndef ContatosDAOH
#define ContatosDAOH
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
#include "Contatos.h"
#include "Associados.h"
#include "Associados.h"

//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFContatosDAO : public TDataModule
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
	TList *store(Associados*, Contatos*);
    TList *update(Contatos*);
	void destroy(Associados*, Contatos*);
	__fastcall TFContatosDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFContatosDAO *FContatosDAO;
//---------------------------------------------------------------------------

#endif
