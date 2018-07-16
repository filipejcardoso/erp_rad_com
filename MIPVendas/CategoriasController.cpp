//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaCategoriasView.h"
#include "CategoriasController.h"
#include "CategoriasDAO.h"
#include "SubcategoriasDAO.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CategoriasController::CategoriasController()
{
	instaceFields();
}
//---------------------------------------------------------------------------
void CategoriasController::instaceFields()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(Categorias)));

	fields = new Fields(cls, NULL);

	fields->GetField("id")->primaryKey = true;
	fields->GetField("id")->visible = true;
	fields->GetField("nome")->visible = true;
	fields->GetField("nome")->required = true;

	fields->GetField("id")->text = "ID";
	fields->GetField("nome")->text = "Nome";
}
//---------------------------------------------------------------------------
void CategoriasController::showCrudView(int editar)
{
	TRttiContext context;

	FListaCategoriasView->editar = editar;
	FListaCategoriasView->controller->queryParams->fields = fields;

	FListaCategoriasView->controller->cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(CategoriasController)));

	FListaCategoriasView->controller->instance = (TObject*)this;

	FCategoriasDAO->paginate = FListaCategoriasView->controller->queryParams->paginate; //remove

	FListaCategoriasView->ShowModal();
}
//---------------------------------------------------------------------------
TList* CategoriasController::index(UnicodeString queryParams)
{
	return FCategoriasDAO->index(queryParams);
}
//---------------------------------------------------------------------------
TList* CategoriasController::show(int id)
{
	QueryParams *queryParams = new QueryParams();

	TList* records;

	records = FCategoriasDAO->show(queryParams->getQuery(), id);

	return records;
}
//---------------------------------------------------------------------------
Result* CategoriasController::store(Categorias *categoria)
{
	Result *result = new Result();

	FCategoriasDAO->result = result;

	TList *subcategorias = categoria->subcategoria;
    categoria->subcategoria = NULL;

	TList *records = FCategoriasDAO->store(categoria);

	if(result->code == 201)
	{
		Categorias *newcategoria = (Categorias*) records->Items[0];

		categoria->id = newcategoria->id;

		categoria->subcategoria = subcategorias;
		insertRelation(categoria);
	}

	return result;
}
//---------------------------------------------------------------------------
Result* CategoriasController::update(Categorias *categoria)
{
	Result *result = new Result();

	FCategoriasDAO->result = result;

	TList *subcategorias = categoria->subcategoria;
	categoria->subcategoria = NULL;

	TList *records = FCategoriasDAO->update(categoria);

	categoria->subcategoria = subcategorias;

	return result;
}
//---------------------------------------------------------------------------
Result* CategoriasController::destroy(Categorias *categoria)
{
	Result *result = new Result();

	FCategoriasDAO->result = result;

	FCategoriasDAO->destroy(categoria);

	return result;
}
//---------------------------------------------------------------------------
Result* CategoriasController::destroyRelation(Categorias *categoria)
{
	Result *result = new Result();

	FSubcategoriasDAO->result = result;

	for(int i=0;i<categoria->subcategoria->Count;i++)
	{
		Subcategorias *subcategoria = (Subcategorias*)categoria->subcategoria->Items[i];
		FSubcategoriasDAO->destroy(categoria, subcategoria);
	}

    return result;
}
//---------------------------------------------------------------------------
Result* CategoriasController::updateRelation(Categorias *categoria)
{
	Result *result = new Result();

	FSubcategoriasDAO->result = result;

	for(int i=0;i<categoria->subcategoria->Count;i++)
	{
		Subcategorias *subcategoria = (Subcategorias*)categoria->subcategoria->Items[i];
		FSubcategoriasDAO->update(categoria, subcategoria);
	}

    return result;
}
//---------------------------------------------------------------------------
void CategoriasController::insertRelation(Categorias *categoria)
{
	for(int i=0;i<categoria->subcategoria->Count;i++)
	{
		Subcategorias *subcategoria = (Subcategorias*)categoria->subcategoria->Items[i];
		TList *records = FSubcategoriasDAO->store(categoria, subcategoria);
        subcategoria->id = ((Subcategorias*)records->Items[0])->id;
	}
}
//---------------------------------------------------------------------------
Result* CategoriasController::storeRelation(Categorias *categoria)
{
	Result *result = new Result();

	FSubcategoriasDAO->result = result;

	insertRelation(categoria);

    return result;
}
//---------------------------------------------------------------------------

