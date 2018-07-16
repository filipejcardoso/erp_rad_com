//---------------------------------------------------------------------------

#ifndef UsuariosControllerH
#define UsuariosControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "QueryParams.h"
#include "Fields.h"
#include "Result.h"
#include "User.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) UsuariosController : public TPersistent
{
	private:
	public:
		UsuariosController::UsuariosController();
		TList* index(UnicodeString);
		TList* show(int);
		Result* store(User*);
		Result* update(User*);
		Result* destroy(User*);
		void showCrudView();
};
#endif
