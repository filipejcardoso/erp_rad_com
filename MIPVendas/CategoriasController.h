//---------------------------------------------------------------------------

#ifndef CategoriasControllerH
#define CategoriasControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "Categorias.h"
#include "Fields.h"
#include "QueryParams.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) CategoriasController : public TPersistent
{
private:
	Fields *fields;
	void instaceFields();
	void insertRelation(Categorias*);

public:
	CategoriasController::CategoriasController();
	void showCrudView(int);
	TList* index(UnicodeString);
	TList* show(int);
	Result* store(Categorias*);
	Result* update(Categorias*);
	Result* destroy(Categorias*);

	Result* storeRelation(Categorias*);
	Result* updateRelation(Categorias*);
	Result* destroyRelation(Categorias*);
};

#endif
