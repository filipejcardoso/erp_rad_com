//---------------------------------------------------------------------------

#ifndef InfoFinanceirasH
#define InfoFinanceirasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) InfoFinanceiras : public TPersistent
{
private:

public:
	int id;
	int consumidor;
    float limite;
};
//---------------------------------------------------------------------------
#endif


