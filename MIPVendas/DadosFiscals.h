//---------------------------------------------------------------------------

#ifndef DadosFiscalsH
#define DadosFiscalsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class __declspec(delphiclass) DadosFiscals : public TPersistent
{
private:

public:
	int id;
	UnicodeString ncm;
	UnicodeString cfop;
};
#endif
