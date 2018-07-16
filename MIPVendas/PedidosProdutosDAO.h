//---------------------------------------------------------------------------

#ifndef PedidosProdutosDAOH
#define PedidosProdutosDAOH
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
#include "PedidosProdutos.h"
#include "Pedidos.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFPedidosProdutosDAO : public TDataModule
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
    Pedidos *pedidos;
	TList* index(UnicodeString);
    TList *show(UnicodeString, int);
	TList *store(Pedidos *pedido, TList*);
    TList *update(UnicodeString idPedido, UnicodeString idProduto, UnicodeString key, UnicodeString value);
	void destroy(PedidosProdutos*);
	__fastcall TFPedidosProdutosDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPedidosProdutosDAO *FPedidosProdutosDAO;
//---------------------------------------------------------------------------

#endif
