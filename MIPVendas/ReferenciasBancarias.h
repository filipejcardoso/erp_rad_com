//---------------------------------------------------------------------------

#ifndef ReferenciasBancariasH
#define ReferenciasBancariasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) ReferenciasBancarias : public TPersistent
{
private:

public:
	int id;
	UnicodeString banco;
	UnicodeString agencia;
	UnicodeString conta;
	UnicodeString nome;
	UnicodeString cpf_cnpj;
	UnicodeString descricao;
};
//---------------------------------------------------------------------------
#endif


