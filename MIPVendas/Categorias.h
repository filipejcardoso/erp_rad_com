//---------------------------------------------------------------------------

#ifndef CategoriasH
#define CategoriasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#include "Subcategorias.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) Categorias : public TPersistent
{
private:

public:
	int id;
	UnicodeString nome;
	TList *subcategoria;

    Categorias();

	Subcategorias* instance_subcategoria();

	TRttiInstanceType* cls_subcategoria();
};
//---------------------------------------------------------------------------
#endif
