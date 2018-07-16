//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaMarcasView.h"
#include "MarcasController.h"
#include "MarcasDAO.h"
#include "InfoFinanceirasDAO.h"
#include "ReferenciasBancariasDAO.h"
#include "ContatosDAO.h"
#include "EnderecosDAO.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
MarcasController::MarcasController()
{
	instaceFields();
}
//---------------------------------------------------------------------------
void MarcasController::instaceFields()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(Marcas)));

	fields = new Fields(cls, NULL);

	fields->GetField("id")->primaryKey = true;
	fields->GetField("id")->visible = true;
	fields->GetField("descricao")->visible = true;
	fields->GetField("descricao")->required = true;

	fields->GetField("id")->text = "ID";
	fields->GetField("descricao")->text = "Nome";
}
//---------------------------------------------------------------------------
void MarcasController::showCrudView(int editar)
{
	TRttiContext context;

	FListaMarcasView->editar = editar;
	FListaMarcasView->controller->queryParams->fields = fields;

	FListaMarcasView->controller->cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(MarcasController)));

	FListaMarcasView->controller->instance = (TObject*)this;

	FMarcasDAO->paginate = FListaMarcasView->controller->queryParams->paginate; //remove

	FListaMarcasView->ShowModal();
}
//---------------------------------------------------------------------------
TList* MarcasController::index(UnicodeString queryParams)
{
	return FMarcasDAO->index(queryParams);
}
//---------------------------------------------------------------------------
TList* MarcasController::show(int id)
{
	QueryParams *queryParams = new QueryParams();

	TList* records;

	records = FMarcasDAO->show(queryParams->getQuery(), id);

	return records;
}
//---------------------------------------------------------------------------
Result* MarcasController::store(Marcas *marca)
{
	Result *result = new Result();

	FMarcasDAO->result = result;

	TList *records = FMarcasDAO->store(marca);

	return result;
}
//---------------------------------------------------------------------------
Result* MarcasController::update(Marcas *marca)
{
	Result *result = new Result();

	FMarcasDAO->result = result;

	TList *records = FMarcasDAO->update(marca);

	return result;
}
//---------------------------------------------------------------------------
Result* MarcasController::destroy(Marcas *marca)
{
	Result *result = new Result();

	FMarcasDAO->result = result;

	FMarcasDAO->destroy(marca);

	return result;
}

