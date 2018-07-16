//---------------------------------------------------------------------------

#pragma hdrstop

#include "PedidosController.h"
#include "ProdutosDAO.h"
#include "ListaPedidosView.h"
#include "PedidosView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
PedidosController::PedidosController()
{
    this->instaceFields();
}
//---------------------------------------------------------------------------
void PedidosController::instaceFields()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(Pedidos)));

	fields = new Fields(cls, NULL);

	fields->GetField("id")->primaryKey = true;
	fields->GetField("id")->visible = true;
//	fields->GetField("atendente_nome")->visible = true;
//	fields->GetField("cliente_nome")->visible = true;
	fields->GetField("created_at")->visible = true;
	fields->GetField("valor")->visible = true;

	fields->GetField("id")->text = "Número do Pedido";
//	fields->GetField("atendente_nome")->text = "Atendente";
//	fields->GetField("cliente_nome")->text = "Cliente";
	fields->GetField("created_at")->text = "Data";
	fields->GetField("valor")->text = "Valor";
}
//---------------------------------------------------------------------------
TList* PedidosController::index(UnicodeString queryParams)
{
	TList* records;

	Result *result = new Result();

	FProdutosDAO->result = result;

	records = FPedidosDAO->index(queryParams);

	return records;
}
//---------------------------------------------------------------------------
Pedidos* PedidosController::createPedido()
{
	Pedidos *pedido;

	Result *result = new Result();

	FPedidosDAO->result = result;

	TList *listPedidos = FPedidosDAO->store();

	pedido = (Pedidos*) listPedidos->Items[0];

	return pedido;
}
//---------------------------------------------------------------------------
Pedidos* PedidosController::addProduto(Pedidos *pedido, TList *listProdutos)
{
	FPedidosProdutosDAO->store(pedido, listProdutos);
}
//---------------------------------------------------------------------------
Pedidos* PedidosController::deleteEmpty(Pedidos *pedido)
{
	FPedidosDAO->destroy("empty", pedido);
}
//---------------------------------------------------------------------------
Pedidos* PedidosController::setProdutoQuantidade(Pedidos *pedido, PedidosProdutos *produto, UnicodeString value)
{
	FPedidosProdutosDAO->update(IntToStr(pedido->id), IntToStr(produto->id), "quantidade",value);
}
//---------------------------------------------------------------------------
Pedidos* PedidosController::setProdutoDesconto(Pedidos *pedido, PedidosProdutos *produto, UnicodeString value)
{
	FPedidosProdutosDAO->update(IntToStr(pedido->id), IntToStr(produto->id), "desconto", value);
}
//---------------------------------------------------------------------------
Pedidos* PedidosController::setDescontoD(Pedidos *pedido, UnicodeString value)
{
	FPedidosDAO->desconto(IntToStr(pedido->id), value, 1);
}
//---------------------------------------------------------------------------
Pedidos* PedidosController::setDescontoP(Pedidos *pedido, UnicodeString value)
{
	FPedidosDAO->desconto(IntToStr(pedido->id), value, 0);
}
//---------------------------------------------------------------------------
Pedidos* PedidosController::setObservacao(Pedidos *pedido, UnicodeString value)
{
	FPedidosDAO->observacao(IntToStr(pedido->id), value);
}
//---------------------------------------------------------------------------
Pedidos* PedidosController::setCliente(Pedidos *pedido, UnicodeString value)
{
	FPedidosDAO->cliente(IntToStr(pedido->id), value);
}
void PedidosController::showPedido(int editar)
{
	FPedidosView->editar = editar;
	FPedidosView->ShowModal();
}
//---------------------------------------------------------------------------
void PedidosController::showListPedidos()
{
	TRttiContext context;

	FListaPedidosView->controller->queryParams->fields = fields;

	FListaPedidosView->controller->cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(PedidosController)));

    FListaPedidosView->controller->instance = (TObject*)this;

	FPedidosDAO->paginate = FListaPedidosView->controller->queryParams->paginate;//remover

	FListaPedidosView->editar = 0;
	FListaPedidosView->ShowModal();
}

