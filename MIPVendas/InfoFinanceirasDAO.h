//---------------------------------------------------------------------------

#ifndef InfoFinanceirasDAOH
#define InfoFinanceirasDAOH
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
#include "InfoFinanceiras.h"
#include "Associados.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFInfoFinanceirasDAO : public TDataModule
{
__published:
	TRESTClient *RESTClient;
	TRESTRequest *RESTRequest;
	TRESTResponse *RESTResponse;
private:
    UnicodeString resource;
public:

	Paginator *paginate;
    Result *result;
	TList* index(UnicodeString);
    TList *show(UnicodeString, int);
	TList *store(UnicodeString tipo_associado, Associados *associado);
    TList *update(UnicodeString tipo_associado, Associados *associado);
	void destroy(InfoFinanceiras*);
	__fastcall TFInfoFinanceirasDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFInfoFinanceirasDAO *FInfoFinanceirasDAO;
//---------------------------------------------------------------------------

#endif
