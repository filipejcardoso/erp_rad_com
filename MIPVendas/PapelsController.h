//---------------------------------------------------------------------------

#ifndef PapelsControllerH
#define PapelsControllerH
//---------------------------------------------------------------------------
#include "Papels.h"
#include "Result.h"
//---------------------------------------------------------------------------
class __declspec(delphiclass) PapelsController: public TPersistent
{
	private:
	public:
		PapelsController::PapelsController();
		TList* index(UnicodeString);
		TList* show(int);
		Papels* createPapel();
		//Result* store(Papels*);
		//Result* update(Papels*);
		//Result* destroy(Papels*);
};

#endif
