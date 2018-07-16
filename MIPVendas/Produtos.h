//---------------------------------------------------------------------------

#ifndef ProdutosH
#define ProdutosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "Marcas.h"
#include "Estoques.h"
#include "Lojas.h"
#include "UnidadesMedidas.h"
#include "Dimensaos.h"
#include "Subcategorias.h"
#include "DadosFiscals.h"
#include "Fields.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) Produtos : public TPersistent
{
	private:

	public:
		int id;
		UnicodeString nome;
		UnicodeString codbarras;
		float preco_compra;
		float preco_venda;
		Marcas *marca;
		Estoques *estoque;
		Lojas *loja;
		UnidadesMedidas *unidades_medida;
		Dimensaos *dimensao;
		Subcategorias *subcategoria;
		DadosFiscals *dados_fiscal;

		Produtos::Produtos();
};
#endif
//---------------------------------------------------------------------------
