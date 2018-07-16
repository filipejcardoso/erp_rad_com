//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaClientesView.h"
#include "ClientesController.h"
#include "AssociadosDAO.h"
#include "InfoFinanceirasDAO.h"
#include "ReferenciasBancariasDAO.h"
#include "ContatosDAO.h"
#include "EnderecosDAO.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
ClientesController::ClientesController()
{
	instaceFields();
}
//---------------------------------------------------------------------------
void ClientesController::instaceFields()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(Associados)));

	fields = new Fields(cls, NULL);

	fields->GetField("id")->primaryKey = true;
	fields->GetField("id")->visible = true;
	fields->GetField("nome")->visible = true;
	fields->GetField("email")->visible = true;
	fields->GetField("cpf_cnpj")->visible = true;
	fields->GetField("telefone_comercial")->visible = true;
	fields->GetField("telefone_celular")->visible = true;

	fields->GetField("id")->text = "ID";
	fields->GetField("nome")->text = "Nome";
	fields->GetField("email")->text = "E-Mail";
	fields->GetField("cpf_cnpj")->text = "CPF/CNPJ";
	fields->GetField("telefone_comercial")->text = "Telefone";
	fields->GetField("telefone_celular")->text = "Celular";
}
//---------------------------------------------------------------------------
void ClientesController::showCrudView(int editar)
{
	TRttiContext context;

	if(editar)
	{
		FListaClientesView->helperGridRecords->clearCheck();
		FListaClientesView->helperGridRecords->checkBox = TRUE;
		FListaClientesView->PanelAddPedido->Visible = TRUE;
	}
	else
	{
		FListaClientesView->helperGridRecords->checkBox = FALSE;
		FListaClientesView->PanelAddPedido->Visible = FALSE;
	}

	FListaClientesView->editar = editar;
	FListaClientesView->controller->queryParams->fields = fields;

	FListaClientesView->controller->cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(ClientesController)));

	FListaClientesView->controller->instance = (TObject*)this;

	FAssociadosDAO->paginate = FListaClientesView->controller->queryParams->paginate; //remove

	FListaClientesView->ShowModal();
}
//---------------------------------------------------------------------------
TList* ClientesController::index(UnicodeString queryParams)
{
    FAssociadosDAO->resource = "clientes";
	return FAssociadosDAO->index(queryParams);
}
//---------------------------------------------------------------------------
TList* ClientesController::show(int id)
{
    FAssociadosDAO->resource = "clientes";

	QueryParams *queryParams = new QueryParams();

	TList* records;

	records = FAssociadosDAO->show(queryParams->getQuery(), id);

	return records;
}
//---------------------------------------------------------------------------
Result* ClientesController::store(Associados *associado)
{
    FAssociadosDAO->resource = "clientes";

	Result *result = new Result();

	FAssociadosDAO->result = result;

	TList *referencias_bancaria = associado->referencias_bancaria;
	TList *contato = associado->contato;
	TList *endereco = associado->endereco;

	associado->referencias_bancaria = NULL;
	associado->contato = NULL;
    associado->endereco = NULL;

	TList *records = FAssociadosDAO->store(associado);

	if(result->code == 201)
	{
		Associados *newcliente = (Associados*) records->Items[0];

		associado->id = newcliente->id;

		FInfoFinanceirasDAO->store("clientes", associado);

		associado->referencias_bancaria = referencias_bancaria;
		associado->contato = contato;
		associado->endereco = endereco;

		insertRelation(associado);
	}

	return result;
}
//---------------------------------------------------------------------------
Result* ClientesController::update(Associados *associado)
{
    FAssociadosDAO->resource = "clientes";

	Result *result = new Result();

	FAssociadosDAO->result = result;

	TList *referencias_bancaria = associado->referencias_bancaria;
	TList *contato = associado->contato;
	TList *endereco = associado->endereco;

	associado->referencias_bancaria = NULL;
	associado->contato = NULL;
    associado->endereco = NULL;

	TList *records = FAssociadosDAO->update(associado);

	if(result->code == 202)
	{
		FInfoFinanceirasDAO->update("clientes", associado);

		associado->referencias_bancaria = referencias_bancaria;
		associado->contato = contato;
		associado->endereco = endereco;
	}

	return result;
}
//---------------------------------------------------------------------------
Result* ClientesController::destroy(Associados *associado)
{
    FAssociadosDAO->resource = "clientes";

	Result *result = new Result();

	FAssociadosDAO->result = result;

	FAssociadosDAO->destroy(associado);

	return result;
}
//---------------------------------------------------------------------------
void ClientesController::insertRelation(Associados *associado)
{
	TList *listRecords;

	FReferenciasBancariasDAO->resource = "clientes";
	FContatosDAO->resource = "clientes";
	FEnderecosDAO->resource = "clientes";

	for(int i=0;i<associado->referencias_bancaria->Count;i++)
	{
		ReferenciasBancarias *referencias_bancaria = (ReferenciasBancarias*)associado->referencias_bancaria->Items[i];
		listRecords = FReferenciasBancariasDAO->store(associado, referencias_bancaria);
		referencias_bancaria->id = ((ReferenciasBancarias*) listRecords->Items[i])->id;
	}

	for(int i=0;i<associado->contato->Count;i++)
	{
		Contatos *contato = (Contatos*)associado->contato->Items[i];
		listRecords = FContatosDAO->store(associado, contato);
		contato->id = ((Contatos*) listRecords->Items[i])->id;
	}

	for(int i=0;i<associado->endereco->Count;i++)
	{
		Enderecos *endereco = (Enderecos*)associado->endereco->Items[i];
		listRecords = FEnderecosDAO->store(associado, endereco);
		endereco->id = ((Enderecos*) listRecords->Items[i])->id;
	}

}
//---------------------------------------------------------------------------
Result* ClientesController::destroyRelation(Associados *associado)
{
	Result *result = new Result();

	FReferenciasBancariasDAO->result = result;
	FContatosDAO->result = result;
	FEnderecosDAO->result = result;

	FReferenciasBancariasDAO->resource = "clientes";
	FContatosDAO->resource = "clientes";
	FEnderecosDAO->resource = "clientes";

	for(int i=0;i<associado->referencias_bancaria->Count;i++)
	{
		ReferenciasBancarias *referencias_bancaria = (ReferenciasBancarias*)associado->referencias_bancaria->Items[i];
		FReferenciasBancariasDAO->destroy(associado, referencias_bancaria);
	}

	for(int i=0;i<associado->contato->Count;i++)
	{
		Contatos *contato = (Contatos*)associado->contato->Items[i];
		FContatosDAO->destroy(associado, contato);
	}

	for(int i=0;i<associado->endereco->Count;i++)
	{
		Enderecos *endereco = (Enderecos*)associado->endereco->Items[i];
		FEnderecosDAO->destroy(associado, endereco);
	}

    return result;
}
//---------------------------------------------------------------------------
Result* ClientesController::storeRelation(Associados *associado)
{
	TList *listRecords;
	Result *result = new Result();

	FReferenciasBancariasDAO->result = result;
	FContatosDAO->result = result;
	FEnderecosDAO->result = result;

	FReferenciasBancariasDAO->resource = "clientes";
	FContatosDAO->resource = "clientes";
	FEnderecosDAO->resource = "clientes";

	for(int i=0;i<associado->referencias_bancaria->Count;i++)
	{
		ReferenciasBancarias *referencias_bancaria = (ReferenciasBancarias*)associado->referencias_bancaria->Items[i];
		listRecords = FReferenciasBancariasDAO->store(associado, referencias_bancaria);
		referencias_bancaria->id = ((ReferenciasBancarias*) listRecords->Items[i])->id;
	}

	for(int i=0;i<associado->contato->Count;i++)
	{
		Contatos *contato = (Contatos*)associado->contato->Items[i];
		listRecords = FContatosDAO->store(associado, contato);
		contato->id = ((Contatos*) listRecords->Items[i])->id;
	}

	for(int i=0;i<associado->endereco->Count;i++)
	{
		Enderecos *endereco = (Enderecos*)associado->endereco->Items[i];
		listRecords = FEnderecosDAO->store(associado, endereco);
		endereco->id = ((Enderecos*) listRecords->Items[i])->id;
	}

	return result;
}
//---------------------------------------------------------------------------

