#pragma hdrstop

#include "Empresas.h"
#include "EmpresasController.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Empresas::Empresas()
{
	this->instance();
}
//---------------------------------------------------------------------------
Empresas::Empresas(bool load)
{
	this->instance();

	if(load)
	{
        EmpresasController *controller = new EmpresasController();
		Empresas *empresa = (Empresas*) controller->show()->Items[0];

		//DADOS PRINCIPAIS DA EMPRESA
		this->nome = empresa->nome;
		this->razao_social = empresa->razao_social;
		this->cpf_cnpj = empresa->cpf_cnpj;
		this->im = empresa->im;
		this->ie = empresa->ie;
		this->telefone = empresa->telefone;
		this->email = empresa->email;
		this->site = empresa->site;

		this->endereco->cep = empresa->endereco->cep;
		this->endereco->complemento = empresa->endereco->complemento;
		this->endereco->logradouro = empresa->endereco->logradouro;
		this->endereco->numero = empresa->endereco->numero;
		this->endereco->bairro = empresa->endereco->bairro;

		this->endereco->regioes->id = empresa->endereco->regioes->id;
		this->endereco->regioes->codigo_uf = empresa->endereco->regioes->codigo_uf;
		this->endereco->regioes->uf = empresa->endereco->regioes->uf;
		this->endereco->regioes->uf_nome = empresa->endereco->regioes->uf_nome;
		this->endereco->regioes->codigo_municipio = empresa->endereco->regioes->codigo_municipio;
		this->endereco->regioes->municipio = empresa->endereco->regioes->municipio;

		this->endereco->tipos_endereco->id = empresa->endereco->tipos_endereco->id;
		this->endereco->tipos_endereco->nome = empresa->endereco->tipos_endereco->nome;

		if(empresa)
            delete empresa;
	}
}
//---------------------------------------------------------------------------
void Empresas::instance()
{
	endereco = new Enderecos();
}
