//---------------------------------------------------------------------------

#ifndef RecursosControllerH
#define RecursosControllerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "RecursosDAO.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) RecursosController : public TPersistent
{
	private:
	public:
		TList* index(UnicodeString);
		TList* show(int);
};
#endif
