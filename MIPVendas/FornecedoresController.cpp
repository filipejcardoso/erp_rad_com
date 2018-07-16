//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaFornecedoresView.h"
#include "FornecedoresController.h"
#include "AssociadosDAO.h"
#include "InfoFinanceirasDAO.h"
#include "ReferenciasBancariasDAO.h"
#include "ContatosDAO.h"
#include "EnderecosDAO.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
FornecedoresController::FornecedoresController()
{
	instaceFields();
}
//---------------------------------------------------------------------------
void FornecedoresController::instaceFields()
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
void FornecedoresController::showCrudView(int editar)
{
	TRttiContext context;

	if(editar)
	{
		FListaFornecedoresView->helperGridRecords->clearCheck();
		FListaFornecedoresView->helperGridRecords->checkBox = TRUE;
		FListaFornecedoresView->PanelAddPedido->Visible = TRUE;
	}
	else
	{
		FListaFornecedoresView->helperGridRecords->checkBox = FALSE;
		FListaFornecedoresView->PanelAddPedido->Visible = FALSE;
	}

	FListaFornecedoresView->editar = editar;
	FListaFornecedoresView->controller->queryParams->fields = fields;

	FListaFornecedoresView->controller->cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(FornecedoresController)));

	FListaFornecedoresView->controller->instance = (TObject*)this;

	FAssociadosDAO->paginate = FListaFornecedoresView->controller->queryParams->paginate; //remove

	FListaFornecedoresView->ShowModal();
}
//---------------------------------------------------------------------------
TList* FornecedoresController::index(UnicodeString queryParams)
{
    FAssociadosDAO->resource = "fornecedores";
	return FAssociadosDAO->index(queryParams);
}
//---------------------------------------------------------------------------
TList* FornecedoresController::show(int id)
{
    FAssociadosDAO->resource = "fornecedores";

	QueryParams *queryParams = new QueryParams();

	TList* records;

	records = FAssociadosDAO->show(queryParams->getQuery(), id);

	return records;
}
//---------------------------------------------------------------------------
Result* FornecedoresController::store(Associados *associado)
{
    FAssociadosDAO->resource = "fornecedores";

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
		Associados *newfornecedore = (Associados*) records->Items[0];

		associado->id = newfornecedore->id;

		FInfoFinanceirasDAO->store("fornecedores", associado);

		associado->referencias_bancaria = referencias_bancaria;
		associado->contato = contato;
		associado->endereco = endereco;

		insertRelation(associado);
	}

	return result;
}
//---------------------------------------------------------------------------
Result* FornecedoresController::update(Associados *associado)
{
    FAssociadosDAO->resource = "fornecedores";

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
		FInfoFinanceirasDAO->update("fornecedores", associado);

		associado->referencias_bancaria = referencias_bancaria;
		associado->contato = contato;
		associado->endereco = endereco;
	}

	return result;
}
//---------------------------------------------------------------------------
Result* FornecedoresController::destroy(Associados *associado)
{
    FAssociadosDAO->resource = "fornecedores";

	Result *result = new Result();

	FAssociadosDAO->result = result;

	FAssociadosDAO->destroy(associado);

	return result;
}
//---------------------------------------------------------------------------
void FornecedoresController::insertRelation(Associados *associado)
{
	FReferenciasBancariasDAO->resource = "fornecedores";
	FContatosDAO->resource = "fornecedores";
	FEnderecosDAO->resource = "fornecedores";

	for(int i=0;i<associado->referencias_bancaria->Count;i++)
	{
		ReferenciasBancarias *referencias_bancaria = (ReferenciasBancarias*)associado->referencias_bancaria->Items[i];
		FReferenciasBancariasDAO->store(associado, referencias_bancaria);
	}

	for(int i=0;i<associado->contato->Count;i++)
	{
		Contatos *contato = (Contatos*)associado->contato->Items[i];
		FContatosDAO->store(associado, contato);
	}

	for(int i=0;i<associado->endereco->Count;i++)
	{
		Enderecos *endereco = (Enderecos*)associado->endereco->Items[i];
		FEnderecosDAO->store(associado, endereco);
	}
}
//---------------------------------------------------------------------------
Result* FornecedoresController::destroyRelation(Associados *associado)
{
	Result *result = new Result();

	FReferenciasBancariasDAO->result = result;
	FContatosDAO->result = result;
	FEnderecosDAO->result = result;

	FReferenciasBancariasDAO->resource = "fornecedores";
	FContatosDAO->resource = "fornecedores";
	FEnderecosDAO->resource = "fornecedores";

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
Result* FornecedoresController::storeRelation(Associados *associado)
{
	TList *listRecords;
	Result *result = new Result();

	FReferenciasBancariasDAO->result = result;
	FContatosDAO->result = result;
	FEnderecosDAO->result = result;

	FReferenciasBancariasDAO->resource = "fornecedores";
	FContatosDAO->resource = "fornecedores";
	FEnderecosDAO->resource = "fornecedores";

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

