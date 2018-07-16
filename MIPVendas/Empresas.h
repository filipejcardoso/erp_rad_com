//---------------------------------------------------------------------------
#ifndef EmpresasH
#define EmpresasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Generics.Collections.hpp>
#include "Enderecos.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) Empresas : public TPersistent
{
	private:
        void instance();

	public:
		int id;
		UnicodeString nome;
		UnicodeString razao_social;
		UnicodeString cpf_cnpj;
		UnicodeString rg;
		UnicodeString ie;
		UnicodeString im;
		UnicodeString telefone;
		UnicodeString email;
		UnicodeString site;

		Enderecos *endereco;

		Empresas();
		Empresas(bool);
};
#endif

