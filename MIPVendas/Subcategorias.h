//---------------------------------------------------------------------------

#ifndef SubcategoriasH
#define SubcategoriasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) Subcategorias : public TPersistent
{
private:

public:
	int id;
	UnicodeString nome;
    int categoria_id;

	Subcategorias();
};
//---------------------------------------------------------------------------

#endif
