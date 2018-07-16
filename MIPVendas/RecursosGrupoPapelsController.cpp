//---------------------------------------------------------------------------

#pragma hdrstop

#include "RecursosGrupoPapelsController.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
RecursosGrupoPapels* RecursosGrupoPapelsController::createAuxTable()
{
	RecursosGrupoPapels *auxiliar;

	Result *result = new Result();

	FRecursosGrupoPapelsDAO->result = result;

	TList *listRecursosGrupoPapels = FRecursosGrupoPapelsDAO->store();

	auxiliar = (RecursosGrupoPapels*) listRecursosGrupoPapels->Items[0];

	return auxiliar;
}
//---------------------------------------------------------------------------
TList* RecursosGrupoPapelsController::update()
{
	int b;
}
//---------------------------------------------------------------------------
/*void RecursosGrupoPapelsController::destroy()
{
    int c;
}     */
