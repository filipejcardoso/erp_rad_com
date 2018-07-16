//---------------------------------------------------------------------------

#pragma hdrstop

#include "Configuracoes.h"
#include "ConfiguracoesController.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Configuracoes::Configuracoes()
{
    this->instance();
}
//---------------------------------------------------------------------------
Configuracoes::Configuracoes(bool load)
{
	this->instance();

	if(load)
	{
        ConfiguracoesController *controller = new ConfiguracoesController();
		Configuracoes *configuracao = (Configuracoes*) controller->show()->Items[0];

		id = configuracao->id;

		//CONFIG PEDIDOS
		config_pedido->id = configuracao->config_pedido->id;
		config_pedido->validade = configuracao->config_pedido->validade;
		config_pedido->associado->id = configuracao->config_pedido->associado->id;
	}
}
//---------------------------------------------------------------------------
void Configuracoes::instance()
{
	config_pedido = new ConfigPedidos();
}

