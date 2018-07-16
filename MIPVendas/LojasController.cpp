//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaLojasView.h"
#include "LojasController.h"
#include "LojasDAO.h"
#include "InfoFinanceirasDAO.h"
#include "ReferenciasBancariasDAO.h"
#include "ContatosDAO.h"
#include "EnderecosDAO.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
LojasController::LojasController()
{
	instaceFields();
}
//---------------------------------------------------------------------------
void LojasController::instaceFields()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(Lojas)));

	fields = new Fields(cls, NULL);

	fields->GetField("id")->primaryKey = true;
	fields->GetField("id")->visible = true;
	fields->GetField("nome")->visible = true;
	fields->GetField("nome")->required = true;

	fields->GetField("id")->text = "ID";
	fields->GetField("nome")->text = "Nome";
}
//---------------------------------------------------------------------------
void LojasController::showCrudView(int editar)
{
	TRttiContext context;

	FListaLojasView->editar = editar;
	FListaLojasView->controller->queryParams->fields = fields;

	FListaLojasView->controller->cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(LojasController)));

	FListaLojasView->controller->instance = (TObject*)this;

	FLojasDAO->paginate = FListaLojasView->controller->queryParams->paginate; //remove

	FListaLojasView->ShowModal();
}
//---------------------------------------------------------------------------
TList* LojasController::index(UnicodeString queryParams)
{
	return FLojasDAO->index(queryParams);
}
//---------------------------------------------------------------------------
TList* LojasController::show(int id)
{
	QueryParams *queryParams = new QueryParams();

	TList* records;

	records = FLojasDAO->show(queryParams->getQuery(), id);

	return records;
}
//---------------------------------------------------------------------------
Result* LojasController::store(Lojas *loja)
{
	Result *result = new Result();

	FLojasDAO->result = result;

	TList *records = FLojasDAO->store(loja);

	return result;
}
//---------------------------------------------------------------------------
Result* LojasController::update(Lojas *loja)
{
	Result *result = new Result();

	FLojasDAO->result = result;

	TList *records = FLojasDAO->update(loja);

	return result;
}
//---------------------------------------------------------------------------
Result* LojasController::destroy(Lojas *loja)
{
	Result *result = new Result();

	FLojasDAO->result = result;

	FLojasDAO->destroy(loja);

	return result;
}

