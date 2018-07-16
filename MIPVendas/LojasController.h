//---------------------------------------------------------------------------

#ifndef LojasControllerH
#define LojasControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "Lojas.h"
#include "Fields.h"
#include "QueryParams.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) LojasController : public TPersistent
{
private:
	Fields *fields;
	void instaceFields();

public:
	LojasController::LojasController();
	void showCrudView(int);
	TList* index(UnicodeString);
	TList* show(int);
	Result* store(Lojas*);
	Result* update(Lojas*);
	Result* destroy(Lojas*);
};

#endif
