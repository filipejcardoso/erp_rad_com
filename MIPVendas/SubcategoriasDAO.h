//---------------------------------------------------------------------------

#ifndef SubcategoriasDAOH
#define SubcategoriasDAOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include "JSONRtti.h"
#include "Paginator.h"
#include "Result.h"
#include "Categorias.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFSubcategoriasDAO : public TDataModule
{
__published:	// IDE-managed Components
	TRESTRequest *RESTRequest;
	TRESTResponse *RESTResponse;
	TRESTClient *RESTClient;
private:
    UnicodeString resource;
public:
	Paginator *paginate;
    Result *result;
	TList* index(UnicodeString, int);
    TList *show(UnicodeString, int, int);
	TList* store(Categorias*, Subcategorias*);
	TList* update(Categorias*, Subcategorias*);
	void destroy(Categorias*, Subcategorias*);
	__fastcall TFSubcategoriasDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFSubcategoriasDAO *FSubcategoriasDAO;
//---------------------------------------------------------------------------
#endif
