//---------------------------------------------------------------------------

#ifndef PedidosProdutosH
#define PedidosProdutosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, private, public) properties (__published, private, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class PedidosProdutos : public TPersistent
{
	private:

	public:
		int id;
		UnicodeString codbarras;
		UnicodeString nome;
		UnicodeString marca;
        UnicodeString unidade_medida;
		float quantidade;
		float preco_compra;
		float preco_venda;
		float desconto;
		float preco;
		UnicodeString ncm;
		UnicodeString cfop;
};
#endif