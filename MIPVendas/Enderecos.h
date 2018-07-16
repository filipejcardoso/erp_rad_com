//---------------------------------------------------------------------------

#ifndef EnderecosH
#define EnderecosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "TiposEnderecos.h"
#include "Regioes.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) Enderecos : public TPersistent
{
private:

public:
	int id;
	UnicodeString cep;
	UnicodeString logradouro;
	UnicodeString numero;
	UnicodeString bairro;
	UnicodeString complemento;

	Regioes *regioes;
	TiposEnderecos *tipos_endereco;

    Enderecos();
};
//---------------------------------------------------------------------------
#endif


