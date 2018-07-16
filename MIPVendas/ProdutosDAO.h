//---------------------------------------------------------------------------

#ifndef ProdutosDAOH
#define ProdutosDAOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include <REST.Json.hpp>
#include <System.JSON.hpp>
#include <Rtti.hpp>
#include "JSONRtti.h"
#include "Paginator.h"
#include "Result.h"
#include "Produtos.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFProdutosDAO : public TDataModule
{
__published:	// IDE-managed Components
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
    TList *store(Produtos*);
    TList *update(Produtos*);
    void destroy(Produtos*);
	__fastcall TFProdutosDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFProdutosDAO *FProdutosDAO;
//---------------------------------------------------------------------------
#endif
