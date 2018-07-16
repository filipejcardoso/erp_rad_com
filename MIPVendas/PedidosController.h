//---------------------------------------------------------------------------

#ifndef PedidosControllerH
#define PedidosControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "Fields.h"
#include "QueryParams.h"
#include "Pedidos.h"
#include "PedidosDAO.h"
#include "PedidosProdutos.h"
#include "PedidosProdutosDAO.h"
#include "Result.h"
#include "Produtos.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) PedidosController : public TPersistent
{
private:
	Fields *fields;
	void instaceFields();

public:
	PedidosController();

    TList* index(UnicodeString);

	Pedidos* createPedido();
	Pedidos* addProduto(Pedidos*, TList*);
	Pedidos* deleteEmpty(Pedidos*);
	Pedidos* setProdutoQuantidade(Pedidos*, PedidosProdutos*, UnicodeString value);
	Pedidos* setProdutoDesconto(Pedidos*, PedidosProdutos*, UnicodeString value);
	Pedidos* setDescontoD(Pedidos *pedido, UnicodeString value);
	Pedidos* setDescontoP(Pedidos *pedido, UnicodeString value);
	Pedidos* setObservacao(Pedidos *pedido, UnicodeString value);
	Pedidos* setCliente(Pedidos *pedido, UnicodeString value);

    void showPedido(int);
    void showListPedidos();
};

#endif