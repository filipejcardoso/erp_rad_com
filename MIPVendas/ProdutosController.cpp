//---------------------------------------------------------------------------

#pragma hdrstop

#include "ProdutosController.h"
#include "ListaProdutosView.h"
#include "ProdutosDAO.h"
#include "Produtos.h"
#include "Helper.h"
#include "Result.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
ProdutosController::ProdutosController()
{
	instaceFields();
}
//---------------------------------------------------------------------------
void ProdutosController::instaceFields()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(Produtos)));

	fields = new Fields(cls, NULL);

	fields->GetField("id")->primaryKey = true;
	fields->GetField("id")->visible = true;
	fields->GetField("nome")->visible = true;
	fields->GetField("codbarras")->visible = true;
	fields->GetField("codbarras")->required = true;
	fields->GetField("unidades_medida_descricao")->visible = true;
	fields->GetField("preco_venda")->visible = true;
	fields->GetField("marca_descricao")->visible = true;

	fields->GetField("id")->text = "ID";
	fields->GetField("nome")->text = "Nome";
	fields->GetField("codbarras")->text = "Código de barras";
	fields->GetField("unidades_medida_descricao")->text = "Unidade de Medida";
	fields->GetField("preco_venda")->text = "Preço";
	fields->GetField("marca_descricao")->text = "Marca";
}
//---------------------------------------------------------------------------
void ProdutosController::showCrudView(int editar)
{
	TRttiContext context;

	if(editar)
	{
		FListaProdutosView->helperGridRecords->clearCheck();
		FListaProdutosView->helperGridRecords->checkBox = TRUE;
		FListaProdutosView->PanelAddPedido->Visible = TRUE;
	}
	else
	{
		FListaProdutosView->helperGridRecords->checkBox = FALSE;
		FListaProdutosView->PanelAddPedido->Visible = FALSE;
	}

	FListaProdutosView->editar = editar;
	FListaProdutosView->controller->queryParams->fields = fields;

	FListaProdutosView->controller->cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(ProdutosController)));

    FListaProdutosView->controller->instance = (TObject*)this;

    FProdutosDAO->paginate = FListaProdutosView->controller->queryParams->paginate;//remover

	FListaProdutosView->ShowModal();
}
//---------------------------------------------------------------------------
TList* ProdutosController::index(UnicodeString queryParams)
{
	TList* records;

	Result *result = new Result();

	FProdutosDAO->result = result;

	records = FProdutosDAO->index(queryParams);

	return records;
}
//---------------------------------------------------------------------------
TList* ProdutosController::show(int id)
{
   	QueryParams *queryParams = new QueryParams();

	TList* records;

	records = FProdutosDAO->show(queryParams->getQuery(), id);

    return records;
}
//---------------------------------------------------------------------------
Result* ProdutosController::store(Produtos *produto)
{
    Result *result = new Result();

	FProdutosDAO->result = result;

	FProdutosDAO->store(produto);

	return result;
}
//---------------------------------------------------------------------------
Result* ProdutosController::update(Produtos *produto)
{
    Result *result = new Result();

	FProdutosDAO->result = result;

	FProdutosDAO->update(produto);

	return result;
}
//---------------------------------------------------------------------------
Result* ProdutosController::destroy(Produtos *produto)
{
    Result *result = new Result();

	FProdutosDAO->result = result;

	FProdutosDAO->destroy(produto);

	return result;
}

