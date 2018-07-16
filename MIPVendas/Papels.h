//---------------------------------------------------------------------------

#ifndef PapelsH
#define PapelsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class __declspec(delphiclass) Papels: public TPersistent
{
	private:
	public:
		int id;
		UnicodeString nome;
        float desconto;
};
#endif
