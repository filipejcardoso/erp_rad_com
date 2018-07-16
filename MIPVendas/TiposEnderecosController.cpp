//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaTiposEnderecosView.h"
#include "TiposEnderecosController.h"
#include "TiposEnderecosDAO.h"
#include "InfoFinanceirasDAO.h"
#include "ReferenciasBancariasDAO.h"
#include "ContatosDAO.h"
#include "EnderecosDAO.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TiposEnderecosController::TiposEnderecosController()
{
	instaceFields();
}
//---------------------------------------------------------------------------
void TiposEnderecosController::instaceFields()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(TiposEnderecos)));

	fields = new Fields(cls, NULL);

	fields->GetField("id")->primaryKey = true;
	fields->GetField("id")->visible = true;
	fields->GetField("nome")->visible = true;
	fields->GetField("nome")->required = true;

	fields->GetField("id")->text = "ID";
	fields->GetField("nome")->text = "Nome";
}
//---------------------------------------------------------------------------
void TiposEnderecosController::showCrudView(int editar)
{
	TRttiContext context;

	FListaTiposEnderecosView->editar = editar;
	FListaTiposEnderecosView->controller->queryParams->fields = fields;

	FListaTiposEnderecosView->controller->cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(TiposEnderecosController)));

	FListaTiposEnderecosView->controller->instance = (TObject*)this;

	FTiposEnderecosDAO->paginate = FListaTiposEnderecosView->controller->queryParams->paginate; //remove

	FListaTiposEnderecosView->ShowModal();
}
//---------------------------------------------------------------------------
TList* TiposEnderecosController::index(UnicodeString queryParams)
{
	return FTiposEnderecosDAO->index(queryParams);
}
//---------------------------------------------------------------------------
TList* TiposEnderecosController::show(int id)
{
	QueryParams *queryParams = new QueryParams();

	TList* records;

	records = FTiposEnderecosDAO->show(queryParams->getQuery(), id);

	return records;
}
//---------------------------------------------------------------------------
Result* TiposEnderecosController::store(TiposEnderecos *tipos_endereco)
{
	Result *result = new Result();

	FTiposEnderecosDAO->result = result;

	TList *records = FTiposEnderecosDAO->store(tipos_endereco);

	return result;
}
//---------------------------------------------------------------------------
Result* TiposEnderecosController::update(TiposEnderecos *tipos_endereco)
{
	Result *result = new Result();

	FTiposEnderecosDAO->result = result;

	TList *records = FTiposEnderecosDAO->update(tipos_endereco);

	return result;
}
//---------------------------------------------------------------------------
Result* TiposEnderecosController::destroy(TiposEnderecos *tipos_endereco)
{
	Result *result = new Result();

	FTiposEnderecosDAO->result = result;

	FTiposEnderecosDAO->destroy(tipos_endereco);

	return result;
}

