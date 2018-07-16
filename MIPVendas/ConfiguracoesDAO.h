//---------------------------------------------------------------------------

#ifndef ConfiguracoesDAOH
#define ConfiguracoesDAOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include <REST.Json.hpp>
#include <Rtti.hpp>
#include "JSONRtti.h"
#include "Paginator.h"
#include "Result.h"
#include "Configuracoes.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFConfiguracoesDAO : public TDataModule
{
__published:
	TRESTClient *RESTClient;
	TRESTRequest *RESTRequest;
	TRESTResponse *RESTResponse;
private:
    UnicodeString resource;
public:

	Result *result;
	TList *show();
    TList *update(Configuracoes*);
	__fastcall TFConfiguracoesDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFConfiguracoesDAO *FConfiguracoesDAO;
//---------------------------------------------------------------------------

#endif
