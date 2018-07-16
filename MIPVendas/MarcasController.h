//---------------------------------------------------------------------------

#ifndef MarcasControllerH
#define MarcasControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "Marcas.h"
#include "Fields.h"
#include "QueryParams.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) MarcasController : public TPersistent
{
private:
	Fields *fields;
	void instaceFields();

public:
	MarcasController::MarcasController();
	void showCrudView(int);
	TList* index(UnicodeString);
	TList* show(int);
	Result* store(Marcas*);
	Result* update(Marcas*);
	Result* destroy(Marcas*);
};

#endif
