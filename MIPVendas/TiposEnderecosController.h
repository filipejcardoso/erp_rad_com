//---------------------------------------------------------------------------

#ifndef TiposEnderecosControllerH
#define TiposEnderecosControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "TiposEnderecos.h"
#include "Fields.h"
#include "QueryParams.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) TiposEnderecosController : public TPersistent
{
private:
	Fields *fields;
	void instaceFields();

public:
	TiposEnderecosController::TiposEnderecosController();
	void showCrudView(int);
	TList* index(UnicodeString);
	TList* show(int);
	Result* store(TiposEnderecos*);
	Result* update(TiposEnderecos*);
	Result* destroy(TiposEnderecos*);
};

#endif
