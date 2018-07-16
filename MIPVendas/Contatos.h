//---------------------------------------------------------------------------

#ifndef ContatosH
#define ContatosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "TiposContatos.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) Contatos : public TPersistent
{
private:

public:
	int id;
	UnicodeString nome;
	UnicodeString contato;
	UnicodeString cargo;
	UnicodeString observacao;

	TiposContatos *tipos_contato;

	Contatos();
};
//---------------------------------------------------------------------------
#endif
