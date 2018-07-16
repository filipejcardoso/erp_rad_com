//---------------------------------------------------------------------------


#pragma hdrstop

#include "CategoriasDAO.h"
#include "Categorias.h"
#include "Sistema.h"
#include "HttpMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TFCategoriasDAO *FCategoriasDAO;
//---------------------------------------------------------------------------
__fastcall TFCategoriasDAO::TFCategoriasDAO(TComponent* Owner)
	: TDataModule(Owner)
{
    resource = "categorias";
}
//---------------------------------------------------------------------------
TList* TFCategoriasDAO::index(UnicodeString queryParams)
{
	TList *categorias = new TList();
   	TRttiContext context;
	TJSONObject *json;
	TJSONObject *jsonObj;
	TJSONArray *jsonRecords;
	TJSONArray *jsonPaginate;
	TJSONArray *jsonResult;

	try{
		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->Method = TRESTRequestMethod::rmGET;
		RESTRequest->Resource = resource + "?" + queryParams;
		RESTRequest->Execute();

		jsonObj = (TJSONObject*) RESTResponse->JSONValue;

		HttpMessage::check(jsonObj, RESTRequest, RESTResponse, 0);

		if(result!=NULL && jsonObj!=NULL)
		{
			jsonResult = (TJSONArray*) jsonObj->GetValue("result");
			result->setJSON(jsonResult);
		}

		jsonRecords = (TJSONArray*) jsonObj->GetValue("records");

		for(int i=0;i<jsonRecords->Count;i++)
		{
			json = (TJSONObject*) jsonRecords->Items[i];
			Categorias *categoria = new Categorias();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(Categorias)));

			JSONRtti::serialize(categoria, cls, json);

			categorias->Add((Categorias*) categoria);
		}

		jsonPaginate = (TJSONArray*) jsonObj->GetValue("paginate");

		if(paginate!=NULL)
		{
			jsonPaginate = (TJSONArray*) jsonObj->GetValue("paginate");
			paginate->setJSON(jsonPaginate);
		}

	} catch(const Exception& e)
	{
	}

	return categorias;
}
TList* TFCategoriasDAO::show(UnicodeString queryParams, int id)
{
	TList *categorias = new TList();
   	TRttiContext context;
	TJSONObject *json;
	TJSONObject *jsonObj;
	TJSONArray *jsonPaginate;
	TJSONArray *jsonResult;

	try{
		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->Method = TRESTRequestMethod::rmGET;
		RESTRequest->Resource = resource + "/" + IntToStr(id) + "?" + queryParams;
		RESTRequest->Execute();

		jsonObj = (TJSONObject*) RESTResponse->JSONValue;

		HttpMessage::check(jsonObj, RESTRequest, RESTResponse, 0);

		if(result!=NULL && jsonObj!=NULL)
		{
			jsonResult = (TJSONArray*) jsonObj->GetValue("result");
			result->setJSON(jsonResult);
		}

		json = (TJSONObject*) jsonObj->GetValue("records");

		Categorias *categoria = new Categorias();

		// Get class RTTI
		TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
		(context.GetType(__delphirtti(Categorias)));

		JSONRtti::serialize(categoria, cls, json);

		categorias->Add((Categorias*) categoria);
	} catch(const Exception& e)
	{
	}

	return categorias;
}
TList* TFCategoriasDAO::store(Categorias *categoria)
{
	TRttiContext context;
	TList *listRecords = new TList();
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;
	TJSONArray *jsonRecordsStore;
	TJSONValue *jsonValue;
	TJSONObject *json;

	TJSONObject *jsonCategoria;
	TJSONArray *arrayRecords = new TJSONArray();
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonCategoria = TJson::ObjectToJsonObject((TObject*)categoria);

		jsonCategoria->RemovePair("subcategoria");

		arrayRecords->Add(jsonCategoria);

		jsonRecords->AddPair("records", arrayRecords);

		jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource;
		RESTRequest->Method = TRESTRequestMethod::rmPOST;
		RESTRequest->AddBody(jsonStr, ContentTypeFromString("application/json"));
		RESTRequest->Execute();

		jsonObj = (TJSONObject*) RESTResponse->JSONValue;

		HttpMessage::check(jsonObj, RESTRequest, RESTResponse, 1);

		if(result!=NULL)
		{
			jsonResult = (TJSONArray*) jsonObj->GetValue("result");
			result->setJSON(jsonResult);
		}

		jsonRecordsStore = (TJSONArray*) jsonObj->GetValue("records");

		if(jsonRecordsStore!=NULL)
		{
			Categorias *categoria = new Categorias();

			UnicodeString sstr = jsonRecordsStore->ToString();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(Categorias)));

			JSONRtti::serialize(categoria, cls, (TJSONObject*) jsonRecordsStore);

			listRecords->Add((Categorias*) categoria);
		}
	}
	catch(const Exception &e)
	{
	}

    return listRecords;
}
//---------------------------------------------------------------------------
TList* TFCategoriasDAO::update(Categorias *categoria)
{
	TRttiContext context;
	TList *listRecords = new TList();
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;
	TJSONArray *jsonRecordsStore;
	TJSONValue *jsonValue;
	TJSONObject *json;

	TJSONObject *jsonCategoria;
	TJSONArray *arrayRecords = new TJSONArray();
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonCategoria = TJson::ObjectToJsonObject((TObject*)categoria);

		jsonCategoria->RemovePair("subcategoria");

		arrayRecords->Add(jsonCategoria);
		jsonRecords->AddPair("records", arrayRecords);

		jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource + "/" + IntToStr(categoria->id);
		RESTRequest->Method = TRESTRequestMethod::rmPATCH;
		RESTRequest->AddBody(jsonStr, ContentTypeFromString("application/json"));
		RESTRequest->Execute();

		jsonObj = (TJSONObject*) RESTResponse->JSONValue;

		HttpMessage::check(jsonObj, RESTRequest, RESTResponse, 1);

		if(result!=NULL)
		{
			jsonResult = (TJSONArray*) jsonObj->GetValue("result");
			result->setJSON(jsonResult);
		}

		jsonRecordsStore = (TJSONArray*) jsonObj->GetValue("records");

		if(jsonRecordsStore!=NULL)
		{
			Categorias *categoria = new Categorias();

			UnicodeString sstr = jsonRecordsStore->ToString();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(Categorias)));

			JSONRtti::serialize(categoria, cls, (TJSONObject*) jsonRecordsStore);

			listRecords->Add((Categorias*) categoria);
		}
	}
	catch(const Exception &e)
	{
	}

    return listRecords;
}
//---------------------------------------------------------------------------
void TFCategoriasDAO::destroy(Categorias *categoria)
{
	UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;

	TJSONObject *jsonCategoria;
	TJSONArray *arrayRecords = new TJSONArray();;
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->Resource = resource + "/" + IntToStr(categoria->id);
		RESTRequest->Method = TRESTRequestMethod::rmDELETE;
		RESTRequest->Execute();

		jsonObj = (TJSONObject*) RESTResponse->JSONValue;

		HttpMessage::check(jsonObj, 2);

		if(result!=NULL && jsonObj!=NULL)
		{
			jsonResult = (TJSONArray*) jsonObj->GetValue("result");
			result->setJSON(jsonResult);
		}
	}
	catch(const Exception &e)
	{
	}
}




