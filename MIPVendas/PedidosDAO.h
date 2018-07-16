//---------------------------------------------------------------------------

#ifndef PedidosDAOH
#define PedidosDAOH
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
#include "Pedidos.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFPedidosDAO : public TDataModule
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
	TList* show(UnicodeString, int);
	TList* store();
	TList* update(Pedidos*);
	TList* desconto(UnicodeString pedido, UnicodeString value, int tipo);
	TList* observacao(UnicodeString pedido, UnicodeString value);
	TList* cliente(UnicodeString pedido, UnicodeString value);
	void destroy(UnicodeString queryParams, Pedidos *pedido);
	__fastcall TFPedidosDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPedidosDAO *FPedidosDAO;
//---------------------------------------------------------------------------

#endif
