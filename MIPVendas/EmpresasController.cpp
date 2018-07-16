//---------------------------------------------------------------------------

#pragma hdrstop

#include "EmpresasController.h"
#include "EmpresasDAO.h"
#include "EnderecosDAO.h"
#include "EmpresasView.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
EmpresasController::EmpresasController()
{
}
//---------------------------------------------------------------------------
void EmpresasController::showForm()
{
	FEmpresasView->ShowModal();
}
//---------------------------------------------------------------------------
TList* EmpresasController::show()
{
	Result *result = new Result();

	FEmpresasDAO->result = result;

	TList* records = FEmpresasDAO->show();

	return records;
}
//---------------------------------------------------------------------------
Result* EmpresasController::update(Empresas *empresa)
{
	Result *result = new Result();

	FEmpresasDAO->result = result;

	TList *records = FEmpresasDAO->update(empresa);

	return result;
}

