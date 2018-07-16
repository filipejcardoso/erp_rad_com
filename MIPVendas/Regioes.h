//---------------------------------------------------------------------------

#ifndef RegioesH
#define RegioesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) Regioes : public TPersistent
{
private:

public:
	int id;
	int codigo_uf;
	UnicodeString uf;
	UnicodeString uf_nome;
	int codigo_municipio;
	UnicodeString municipio;

    UnicodeString getMunicipioUf();
};
//---------------------------------------------------------------------------
#endif

