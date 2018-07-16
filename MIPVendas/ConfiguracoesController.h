//---------------------------------------------------------------------------
#ifndef ConfiguracoesControllerH
#define ConfiguracoesControllerH
//---------------------------------------------------------------------------
#include "Configuracoes.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) ConfiguracoesController : public TPersistent
{
private:

public:
	ConfiguracoesController();
	void showForm();
	TList* show();
	Result* update(Configuracoes*);
};

#endif