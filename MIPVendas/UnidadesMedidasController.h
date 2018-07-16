//---------------------------------------------------------------------------

#ifndef UnidadesMedidasControllerH
#define UnidadesMedidasControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "UnidadesMedidas.h"
#include "Fields.h"
#include "QueryParams.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) UnidadesMedidasController : public TPersistent
{
private:
	Fields *fields;
	void instaceFields();

public:
	UnidadesMedidasController::UnidadesMedidasController();
	void showCrudView(int);
	TList* index(UnicodeString);
	TList* show(int);
	Result* store(UnidadesMedidas*);
	Result* update(UnidadesMedidas*);
	Result* destroy(UnidadesMedidas*);
};

#endif
