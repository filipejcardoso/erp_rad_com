//---------------------------------------------------------------------------

#pragma hdrstop

#include "AuthController.h"
#include "AuthDAO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
bool AuthController::login(User *usuario)
{
	int response;

    Result *result = new Result();

	FAuthDAO->result = result;

	FAuthDAO->login(usuario);

	if(result->code == 200)
		response = true;
	else
		response = false;

    return response;
}
//---------------------------------------------------------------------------
bool AuthController::logout()
{
}
//---------------------------------------------------------------------------

