//---------------------------------------------------------------------------

#ifndef GruposAssociadosH
#define GruposAssociadosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) GruposAssociados : public TPersistent
{
private:

public:
	int id;
	UnicodeString nome;
};
//---------------------------------------------------------------------------
#endif


