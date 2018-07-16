//---------------------------------------------------------------------------

#pragma hdrstop

#include "Produtos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Produtos::Produtos()
{
	marca = new Marcas();
	estoque = new Estoques();
	loja = new Lojas();
	unidades_medida = new UnidadesMedidas();
	dimensao = new Dimensaos();
	subcategoria = new Subcategorias();
	dados_fiscal = new DadosFiscals();
}
//---------------------------------------------------------------------------

