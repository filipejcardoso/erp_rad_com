//---------------------------------------------------------------------------

#ifndef EmpresasControllerH
#define EmpresasControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
#include "Empresas.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) EmpresasController : public TPersistent
{
private:

public:
	EmpresasController();
	void showForm();
	TList* show();
	Result* update(Empresas*);
};

#endif
