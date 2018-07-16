//---------------------------------------------------------------------------

#ifndef GruposAssociadosControllerH
#define GruposAssociadosControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "GruposAssociados.h"
#include "Fields.h"
#include "QueryParams.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) GruposAssociadosController : public TPersistent
{
private:
	Fields *fields;
	void instaceFields();

public:
	GruposAssociadosController::GruposAssociadosController();
	void showCrudView(int);
	TList* index(UnicodeString);
	TList* show(int);
	Result* store(GruposAssociados*);
	Result* update(GruposAssociados*);
	Result* destroy(GruposAssociados*);
};

#endif
