//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaGruposAssociadosView.h"
#include "GruposAssociadosController.h"
#include "GruposAssociadosDAO.h"
#include "InfoFinanceirasDAO.h"
#include "ReferenciasBancariasDAO.h"
#include "ContatosDAO.h"
#include "EnderecosDAO.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
GruposAssociadosController::GruposAssociadosController()
{
	instaceFields();
}
//---------------------------------------------------------------------------
void GruposAssociadosController::instaceFields()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(GruposAssociados)));

	fields = new Fields(cls, NULL);

	fields->GetField("id")->primaryKey = true;
	fields->GetField("id")->visible = true;
	fields->GetField("nome")->visible = true;
	fields->GetField("nome")->required = true;

	fields->GetField("id")->text = "ID";
	fields->GetField("nome")->text = "Nome";
}
//---------------------------------------------------------------------------
void GruposAssociadosController::showCrudView(int editar)
{
	TRttiContext context;

	FListaGruposAssociadosView->editar = editar;
	FListaGruposAssociadosView->controller->queryParams->fields = fields;

	FListaGruposAssociadosView->controller->cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(GruposAssociadosController)));

	FListaGruposAssociadosView->controller->instance = (TObject*)this;

	FGruposAssociadosDAO->paginate = FListaGruposAssociadosView->controller->queryParams->paginate; //remove

	FListaGruposAssociadosView->ShowModal();
}
//---------------------------------------------------------------------------
TList* GruposAssociadosController::index(UnicodeString queryParams)
{
	return FGruposAssociadosDAO->index(queryParams);
}
//---------------------------------------------------------------------------
TList* GruposAssociadosController::show(int id)
{
	QueryParams *queryParams = new QueryParams();

	TList* records;

	records = FGruposAssociadosDAO->show(queryParams->getQuery(), id);

	return records;
}
//---------------------------------------------------------------------------
Result* GruposAssociadosController::store(GruposAssociados *grupos_associado)
{
	Result *result = new Result();

	FGruposAssociadosDAO->result = result;

	TList *records = FGruposAssociadosDAO->store(grupos_associado);

	return result;
}
//---------------------------------------------------------------------------
Result* GruposAssociadosController::update(GruposAssociados *grupos_associado)
{
	Result *result = new Result();

	FGruposAssociadosDAO->result = result;

	TList *records = FGruposAssociadosDAO->update(grupos_associado);

	return result;
}
//---------------------------------------------------------------------------
Result* GruposAssociadosController::destroy(GruposAssociados *grupos_associado)
{
	Result *result = new Result();

	FGruposAssociadosDAO->result = result;

	FGruposAssociadosDAO->destroy(grupos_associado);

	return result;
}

