//---------------------------------------------------------------------------

#ifndef EstoquesH
#define EstoquesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class __declspec(delphiclass) Estoques : public TPersistent
{
private:

public:
	int id;
	float quantidade;
	UnicodeString area;
	UnicodeString rua;
	UnicodeString modulo;
	UnicodeString nivel;
	UnicodeString vao;
};
//---------------------------------------------------------------------------
#endif
