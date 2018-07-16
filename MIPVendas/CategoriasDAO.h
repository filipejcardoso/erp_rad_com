//---------------------------------------------------------------------------

#ifndef CategoriasDAOH
#define CategoriasDAOH
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

//---------------------------------------------------------------------------
class TFCategoriasDAO : public TDataModule
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
	TList* index(UnicodeString);
    TList *show(UnicodeString, int);
	TList* store(Categorias*);
	TList* update(Categorias*);
	void destroy(Categorias*);
	__fastcall TFCategoriasDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFCategoriasDAO *FCategoriasDAO;
//---------------------------------------------------------------------------
#endif
