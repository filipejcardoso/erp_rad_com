//---------------------------------------------------------------------------

#pragma hdrstop

#include "Sistema.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Sistema *SISTEMA;
//---------------------------------------------------------------------------
Sistema::Sistema()
{
    Fusuario = new User();
	Fapi = new APIRest();
	Fempresa = new Empresas();
	Fconfiguracao = new Configuracoes();
}
//---------------------------------------------------------------------------
void Sistema::setUsuario(User* value)
{
	usuario->id = value->id;
	usuario->nome = value->nome;
	usuario->email = value->email;
	usuario->token = value->token;
}
//---------------------------------------------------------------------------
void Sistema::setAPIRest(APIRest* value)
{
	api->nome = value->nome;
	api->host = value->host;
	api->version = value->version;
	api->background = value->background;
}
//---------------------------------------------------------------------------
void Sistema::setEmpresa(Empresas* value)
{
	//DADOS DA EMPRESA
	empresa->nome = value->nome;
	empresa->razao_social = value->razao_social;
	empresa->cpf_cnpj = value->cpf_cnpj;
	empresa->im = value->im;
	empresa->ie = value->ie;
	empresa->telefone = value->telefone;
	empresa->email = value->email;
	empresa->site = value->site;

	empresa->endereco->cep = value->endereco->cep;
	empresa->endereco->complemento = value->endereco->complemento;
	empresa->endereco->logradouro = value->endereco->logradouro;
	empresa->endereco->numero = value->endereco->numero;
	empresa->endereco->bairro = value->endereco->bairro;

	empresa->endereco->regioes->id = value->endereco->regioes->id;
	empresa->endereco->regioes->codigo_uf = value->endereco->regioes->codigo_uf;
	empresa->endereco->regioes->uf = value->endereco->regioes->uf;
	empresa->endereco->regioes->uf_nome = value->endereco->regioes->uf_nome;
	empresa->endereco->regioes->codigo_municipio = value->endereco->regioes->codigo_municipio;
	empresa->endereco->regioes->municipio = value->endereco->regioes->municipio;

	empresa->endereco->tipos_endereco->id = value->endereco->tipos_endereco->id;
	empresa->endereco->tipos_endereco->nome = value->endereco->tipos_endereco->nome;
}
//---------------------------------------------------------------------------
void Sistema::setConfiguracao(Configuracoes* value)
{
	configuracao->id = value->id;

	//CONFIG PEDIDOS
    configuracao->config_pedido->id = value->config_pedido->id;
    configuracao->config_pedido->validade = value->config_pedido->validade;
	configuracao->config_pedido->associado->id = value->config_pedido->associado->id;

}

