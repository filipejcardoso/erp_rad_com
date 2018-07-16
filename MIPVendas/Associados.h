//---------------------------------------------------------------------------
#ifndef AssociadosH
#define AssociadosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Generics.Collections.hpp>
#include "Contatos.h"
#include "GruposAssociados.h"
#include "InfoFinanceiras.h"
#include "ReferenciasBancarias.h"
#include "Enderecos.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) Associados : public TPersistent
{
	private:

	public:
		int id;
        int indicacao_id;
		int tipo_associado;
		int tipo;
		int situacao;
		int tipo_contribuinte;
		UnicodeString nome;
		UnicodeString razao_social;
		UnicodeString nascimento;
		UnicodeString email;
		UnicodeString cpf_cnpj;
		UnicodeString rg;
		UnicodeString ie;
		UnicodeString im;
		UnicodeString telefone_comercial;
		UnicodeString telefone_celular;
		UnicodeString fax;
		UnicodeString site;

		GruposAssociados *grupos_associado;
		InfoFinanceiras *info_financeira;

		TList *contato;
		TList *referencias_bancaria;
		TList *endereco;

		Contatos* instance_contato();
		ReferenciasBancarias* instance_referencias_bancaria();
		Enderecos* instance_endereco();

		TRttiInstanceType* cls_contato();
		TRttiInstanceType* cls_referencias_bancaria();
		TRttiInstanceType* cls_endereco();

		Associados();
};
#endif

