//---------------------------------------------------------------------------

#ifndef ProdutosControllerH
#define ProdutosControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "Fields.h"
#include "QueryParams.h"
#include "Produtos.h"
#include "PedidosProdutos.h"
#include "Result.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) ProdutosController : public TPersistent
{
private:
	Fields *fields;
	void instaceFields();

public:
	ProdutosController::ProdutosController();
	void showCrudView(int);
    TList* index(UnicodeString);
	TList* show(int);
	Result* store(Produtos*);
	Result* update(Produtos*);
    Result* destroy(Produtos*);
};

#endif
