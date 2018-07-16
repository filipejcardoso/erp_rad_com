//---------------------------------------------------------------------------

#pragma hdrstop

#include "ConfiguracoesController.h"
#include "ConfiguracoesDAO.h"
#include "EnderecosDAO.h"
#include "ConfiguracoesView.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
ConfiguracoesController::ConfiguracoesController()
{
}
//---------------------------------------------------------------------------
void ConfiguracoesController::showForm()
{
	FConfiguracoesView->ShowModal();
}
//---------------------------------------------------------------------------
TList* ConfiguracoesController::show()
{
	Result *result = new Result();

	FConfiguracoesDAO->result = result;

	TList* records = FConfiguracoesDAO->show();

	return records;
}
//---------------------------------------------------------------------------
Result* ConfiguracoesController::update(Configuracoes *configuracao)
{
	Result *result = new Result();

	FConfiguracoesDAO->result = result;

	TList *referencias_bancaria = configuracao->config_pedido->associado->referencias_bancaria;
	TList *contato = configuracao->config_pedido->associado->contato;
	TList *endereco = configuracao->config_pedido->associado->endereco;

	configuracao->config_pedido->associado->referencias_bancaria = NULL;
	configuracao->config_pedido->associado->contato = NULL;
	configuracao->config_pedido->associado->endereco = NULL;

	TList *records = FConfiguracoesDAO->update(configuracao);

	configuracao->config_pedido->associado->referencias_bancaria = referencias_bancaria;
	configuracao->config_pedido->associado->contato = contato;
	configuracao->config_pedido->associado->endereco = endereco;

	return result;
}

