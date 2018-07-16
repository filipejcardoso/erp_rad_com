//---------------------------------------------------------------------------

#ifndef AuthControllerH
#define AuthControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "User.h"
#include "Result.h"
//---------------------------------------------------------------------------
class AuthController : public TObject
{
private:

public:
	bool login(User*);
	bool logout();
};

#endif