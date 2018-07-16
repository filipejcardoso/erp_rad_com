//---------------------------------------------------------------------------

#ifndef UserH
#define UserH
//---------------------------------------------------------------------------
#include "Papels.h"
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, private, public) properties (__published, private, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class __declspec(delphiclass) User : public TPersistent
{
	private:

	public:
        User::User();
		int id;
		int papel_id;
		UnicodeString nome;
		UnicodeString username;
		UnicodeString email;
		UnicodeString password;
        Papels *papel;
		UnicodeString token;
};
#endif