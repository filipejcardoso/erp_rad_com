//---------------------------------------------------------------------------

#ifndef LojasDAOH
#define LojasDAOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include "JSONRtti.h"
#include "Paginator.h"
#include "Result.h"
#include "Lojas.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class TFLojasDAO : public TDataModule
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
	TList* store(Lojas*);
	TList* update(Lojas*);
	void destroy(Lojas*);
	__fastcall TFLojasDAO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFLojasDAO *FLojasDAO;
//---------------------------------------------------------------------------
#endif
