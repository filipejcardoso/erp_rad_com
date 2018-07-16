//---------------------------------------------------------------------------

#ifndef ClientesControllerH
#define ClientesControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "Associados.h"
#include "Fields.h"
#include "QueryParams.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) ClientesController : public TPersistent
{
private:
	Fields *fields;
	void instaceFields();
    void insertRelation(Associados*);

public:
	ClientesController::ClientesController();
	void showCrudView(int);
	TList* index(UnicodeString);
	TList* show(int);
	Result* store(Associados*);
	Result* update(Associados*);
	Result* destroy(Associados*);

	Result* destroyRelation(Associados*);
	Result* storeRelation(Associados*);
};

#endif
