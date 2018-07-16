//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaTiposContatosView.h"
#include "TiposContatosController.h"
#include "TiposContatosDAO.h"
#include "InfoFinanceirasDAO.h"
#include "ReferenciasBancariasDAO.h"
#include "ContatosDAO.h"
#include "EnderecosDAO.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TiposContatosController::TiposContatosController()
{
	instaceFields();
}
//---------------------------------------------------------------------------
void TiposContatosController::instaceFields()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(TiposContatos)));

	fields = new Fields(cls, NULL);

	fields->GetField("id")->primaryKey = true;
	fields->GetField("id")->visible = true;
	fields->GetField("nome")->visible = true;
	fields->GetField("nome")->required = true;

	fields->GetField("id")->text = "ID";
	fields->GetField("nome")->text = "Nome";
}
//---------------------------------------------------------------------------
void TiposContatosController::showCrudView(int editar)
{
	TRttiContext context;

	FListaTiposContatosView->editar = editar;
	FListaTiposContatosView->controller->queryParams->fields = fields;

	FListaTiposContatosView->controller->cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(TiposContatosController)));

	FListaTiposContatosView->controller->instance = (TObject*)this;

	FTiposContatosDAO->paginate = FListaTiposContatosView->controller->queryParams->paginate; //remove

	FListaTiposContatosView->ShowModal();
}
//---------------------------------------------------------------------------
TList* TiposContatosController::index(UnicodeString queryParams)
{
	return FTiposContatosDAO->index(queryParams);
}
//---------------------------------------------------------------------------
TList* TiposContatosController::show(int id)
{
	QueryParams *queryParams = new QueryParams();

	TList* records;

	records = FTiposContatosDAO->show(queryParams->getQuery(), id);

	return records;
}
//---------------------------------------------------------------------------
Result* TiposContatosController::store(TiposContatos *tipos_contato)
{
	Result *result = new Result();

	FTiposContatosDAO->result = result;

	TList *records = FTiposContatosDAO->store(tipos_contato);

	return result;
}
//---------------------------------------------------------------------------
Result* TiposContatosController::update(TiposContatos *tipos_contato)
{
	Result *result = new Result();

	FTiposContatosDAO->result = result;

	TList *records = FTiposContatosDAO->update(tipos_contato);

	return result;
}
//---------------------------------------------------------------------------
Result* TiposContatosController::destroy(TiposContatos *tipos_contato)
{
	Result *result = new Result();

	FTiposContatosDAO->result = result;

	FTiposContatosDAO->destroy(tipos_contato);

	return result;
}

