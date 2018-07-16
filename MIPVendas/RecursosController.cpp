//---------------------------------------------------------------------------

#pragma hdrstop

#include "RecursosController.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TList* RecursosController::index(UnicodeString queryParams)
{
    TList *records;

	Result *result = new Result();

	FResourceDAO->result = result;

	records = FResourceDAO->index("");

	return records;
}
//---------------------------------------------------------------------------
TList* RecursosController::show(int id)
{
    TList *records = new TList();

	records = FResourceDAO->show("", id);

	return records;
}
//---------------------------------------------------------------------------


