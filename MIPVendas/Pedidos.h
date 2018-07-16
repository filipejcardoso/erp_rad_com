//---------------------------------------------------------------------------

#ifndef PedidosH
#define PedidosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "PedidosProdutos.h"
#include "User.h"
#include "Associados.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, private, public) properties (__published, private, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class Pedidos : public TPersistent
{
	private:

	public:
		int id;
		int status;
		User *atendente;
		Associados *cliente;
        UnicodeString observacao;
		float desconto;
		float valor;
        float margem_contribuicao;
        float margem_nfe;
		UnicodeString created_at;
		TList *pedidos_produto;

		PedidosProdutos* instance_pedidos_produto();
		TRttiInstanceType* cls_pedidos_produto();

		Pedidos();
};
#endif