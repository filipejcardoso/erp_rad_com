//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaUnidadesMedidasView.h"
#include "UnidadesMedidasController.h"
#include "UnidadesMedidasDAO.h"
#include "InfoFinanceirasDAO.h"
#include "ReferenciasBancariasDAO.h"
#include "ContatosDAO.h"
#include "EnderecosDAO.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
UnidadesMedidasController::UnidadesMedidasController()
{
	instaceFields();
}
//---------------------------------------------------------------------------
void UnidadesMedidasController::instaceFields()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(UnidadesMedidas)));

	fields = new Fields(cls, NULL);

	fields->GetField("id")->primaryKey = true;
	fields->GetField("id")->visible = true;
	fields->GetField("descricao")->visible = true;
	fields->GetField("descricao")->required = true;

	fields->GetField("id")->text = "ID";
	fields->GetField("descricao")->text = "Nome";
}
//---------------------------------------------------------------------------
void UnidadesMedidasController::showCrudView(int editar)
{
	TRttiContext context;

	FListaUnidadesMedidasView->editar = editar;
	FListaUnidadesMedidasView->controller->queryParams->fields = fields;

	FListaUnidadesMedidasView->controller->cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(UnidadesMedidasController)));

	FListaUnidadesMedidasView->controller->instance = (TObject*)this;

	FUnidadesMedidasDAO->paginate = FListaUnidadesMedidasView->controller->queryParams->paginate; //remove

	FListaUnidadesMedidasView->ShowModal();
}
//---------------------------------------------------------------------------
TList* UnidadesMedidasController::index(UnicodeString queryParams)
{
	return FUnidadesMedidasDAO->index(queryParams);
}
//---------------------------------------------------------------------------
TList* UnidadesMedidasController::show(int id)
{
	QueryParams *queryParams = new QueryParams();

	TList* records;

	records = FUnidadesMedidasDAO->show(queryParams->getQuery(), id);

	return records;
}
//---------------------------------------------------------------------------
Result* UnidadesMedidasController::store(UnidadesMedidas *unidades_medida)
{
	Result *result = new Result();

	FUnidadesMedidasDAO->result = result;

	TList *records = FUnidadesMedidasDAO->store(unidades_medida);

	return result;
}
//---------------------------------------------------------------------------
Result* UnidadesMedidasController::update(UnidadesMedidas *unidades_medida)
{
	Result *result = new Result();

	FUnidadesMedidasDAO->result = result;

	TList *records = FUnidadesMedidasDAO->update(unidades_medida);

	return result;
}
//---------------------------------------------------------------------------
Result* UnidadesMedidasController::destroy(UnidadesMedidas *unidades_medida)
{
	Result *result = new Result();

	FUnidadesMedidasDAO->result = result;

	FUnidadesMedidasDAO->destroy(unidades_medida);

	return result;
}

