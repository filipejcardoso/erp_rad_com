//---------------------------------------------------------------------------

#ifndef APIRestH
#define APIRestH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, private, public) properties (__published, private, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class APIRest : public TObject
{
	private:

	public:
		UnicodeString nome;
		UnicodeString host;
		UnicodeString version;
		UnicodeString background;

		UnicodeString getBaseURL();
};
#endif