//---------------------------------------------------------------------------

#ifndef RecursosGrupoPapelsControllerH
#define RecursosGrupoPapelsControllerH
//---------------------------------------------------------------------------
#include "RecursosGrupoPapelsDAO.h"
//---------------------------------------------------------------------------
class RecursosGrupoPapelsController : public TPersistent
{
	private:
	public:
		RecursosGrupoPapels* createAuxTable();
		TList* update();
		//void destroy();
};
#endif
