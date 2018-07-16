//---------------------------------------------------------------------------

#pragma hdrstop

#include "Categorias.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Categorias::Categorias()
{
    subcategoria = new TList();
}
//---------------------------------------------------------------------------
Subcategorias* Categorias::instance_subcategoria()
{
    return new Subcategorias();
}
//---------------------------------------------------------------------------
TRttiInstanceType* Categorias::cls_subcategoria()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(Subcategorias)));

    return cls;
}

