//---------------------------------------------------------------------------

#pragma hdrstop

#include "UsuariosController.h"
#include "UsuariosDAO.h"
#include "ListaUsuariosView.h"
#include "User.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
UsuariosController::UsuariosController()
{
}
//---------------------------------------------------------------------------
void UsuariosController::showCrudView()
{
	FListaUsuariosView->ShowModal();
}
//---------------------------------------------------------------------------
TList* UsuariosController::index(UnicodeString queryParams)
{
	TList *records;

	Result *result = new Result();

	FUsuariosDAO->result = result;

	records = FUsuariosDAO->index(queryParams);

	return records;
}
//---------------------------------------------------------------------------
TList* UsuariosController::show(int id)
{
	TList *records = new TList();

	records = FUsuariosDAO->show("", id);

	return records;
}
//---------------------------------------------------------------------------
Result* UsuariosController::store(User *usuario)
{
	TList *records = new TList();

	Result *result = new Result();

	result = FUsuariosDAO->result;

	records = FUsuariosDAO->store(usuario);

	return result;
}
//---------------------------------------------------------------------------
Result* UsuariosController::update(User *usuario)
{
	TList *records = new TList();

	Result *result = new Result();

	result = FUsuariosDAO->result;

	records = FUsuariosDAO->update(usuario);

    return result;
}
//---------------------------------------------------------------------------
Result* UsuariosController::destroy(User *usuario)
{
	Result *result = new Result();

	FUsuariosDAO->result = result;

	FUsuariosDAO->destroy(usuario);

	return result;
}
//---------------------------------------------------------------------------
