//---------------------------------------------------------------------------

#ifndef TiposContatosH
#define TiposContatosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) TiposContatos : public TPersistent
{
private:

public:
	int id;
	UnicodeString nome;
};
//---------------------------------------------------------------------------
#endif


