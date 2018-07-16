//---------------------------------------------------------------------------

#ifndef UsuariosDAOH
#define UsuariosDAOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include <REST.Json.hpp>
#include <Rtti.hpp>
#include "JSONRtti.h"
#include "User.h"
#include "Result.h"
#include "Paginator.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class TFUsuariosDAO : public TDataModule
{
__published:	// IDE-managed Components
	TRESTClient *RESTClient;
	TRESTRequest *RESTRequest;
	TRESTResponse *RESTResponse;
private:
	UnicodeString resource;
public:
	Paginator *paginate;
	Result *result;
	TList* index(UnicodeString);
	TList *show(UnicodeString, int);
	TList *store(User*);
	TList *update(User*);
	void destroy(User*);
	__fastcall TFUsuariosDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFUsuariosDAO *FUsuariosDAO;
//---------------------------------------------------------------------------
#endif
