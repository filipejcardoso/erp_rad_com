//---------------------------------------------------------------------------

#ifndef TiposEnderecosH
#define TiposEnderecosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) TiposEnderecos : public TPersistent
{
private:

public:
	int id;
	UnicodeString nome;
};
//---------------------------------------------------------------------------
#endif


