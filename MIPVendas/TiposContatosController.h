//---------------------------------------------------------------------------

#ifndef TiposContatosControllerH
#define TiposContatosControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "TiposContatos.h"
#include "Fields.h"
#include "QueryParams.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) TiposContatosController : public TPersistent
{
private:
	Fields *fields;
	void instaceFields();

public:
	TiposContatosController::TiposContatosController();
	void showCrudView(int);
	TList* index(UnicodeString);
	TList* show(int);
	Result* store(TiposContatos*);
	Result* update(TiposContatos*);
	Result* destroy(TiposContatos*);
};

#endif
