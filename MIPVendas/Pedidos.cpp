//---------------------------------------------------------------------------

#pragma hdrstop

#include "Pedidos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Pedidos::Pedidos()
{
	atendente = new User();
	cliente = new Associados();

	pedidos_produto = new TList();
}
//---------------------------------------------------------------------------
PedidosProdutos *Pedidos::instance_pedidos_produto()
{
	return new PedidosProdutos();
}
//---------------------------------------------------------------------------
TRttiInstanceType *Pedidos::cls_pedidos_produto()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(PedidosProdutos)));

    return cls;
}
