//---------------------------------------------------------------------------

#pragma hdrstop

#include "PapelsDAO.h"
#include "PapelsController.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
PapelsController::PapelsController()
{

}
//---------------------------------------------------------------------------
TList* PapelsController::index(UnicodeString queryParams)
{
	TList *records;

	Result *result = new Result();

	FPapelsDAO->result = result;

	records = FPapelsDAO->index(queryParams);

	return records;
}
//---------------------------------------------------------------------------
TList* PapelsController::show(int id)
{
	TList *records;

	Result *result = new Result();

    FPapelsDAO->result = result;

	records = FPapelsDAO->show("", id);

	return records;
}
//---------------------------------------------------------------------------
Papels* PapelsController::createPapel()
{
	Papels *papel;

	Result *result = new Result();

	FPapelsDAO->result = result;

	TList *listPapels = FPapelsDAO->store();

	papel = (Papels*) listPapels->Items[0];

	return papel;
}
//---------------------------------------------------------------------------
/*Result* PapelsController::update(Papels *papel)
{

}
//---------------------------------------------------------------------------
Result* PapelsController::destroy(Papels *papel)
{

} */
//---------------------------------------------------------------------------

