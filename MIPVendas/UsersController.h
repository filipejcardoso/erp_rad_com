//---------------------------------------------------------------------------
#ifndef UsersControllerH
#define UsersControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "User.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) UsersController : public TPersistent
{
private:


public:
	void showCrudView(int);
	TList* index(UnicodeString);
	TList* show(int);
	Result* store(User*);
	Result* update(User*);
	Result* destroy(User*);
};

#endif
