//---------------------------------------------------------------------------
#pragma hdrstop

#include "TiposContatosDAO.h"
#include "TiposContatos.h"
#include "Sistema.h"
#include "HttpMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TFTiposContatosDAO *FTiposContatosDAO;
//---------------------------------------------------------------------------
__fastcall TFTiposContatosDAO::TFTiposContatosDAO(TComponent* Owner)
	: TDataModule(Owner)
{
    paginate = NULL;
    resource = "tipos_contatos";
}
//---------------------------------------------------------------------------
TList* TFTiposContatosDAO::index(UnicodeString queryParams)
{
	TList *tipos_contatos = new TList();
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
			TiposContatos *tipos_contato = new TiposContatos();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(TiposContatos)));

			JSONRtti::serialize(tipos_contato, cls, json);

			tipos_contatos->Add((TiposContatos*) tipos_contato);
		}

		if(paginate!=NULL)
		{
			jsonPaginate = (TJSONArray*) jsonObj->GetValue("paginate");
			paginate->setJSON(jsonPaginate);
		}

	} catch(const Exception& e)
	{
	}

	return tipos_contatos;
}
TList* TFTiposContatosDAO::show(UnicodeString queryParams, int id)
{
	TList *tipos_contatos = new TList();
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

		TiposContatos *tipos_contato = new TiposContatos();

		// Get class RTTI
		TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
		(context.GetType(__delphirtti(TiposContatos)));

		JSONRtti::serialize(tipos_contato, cls, json);

		tipos_contatos->Add((TiposContatos*) tipos_contato);
	} catch(const Exception& e)
	{
	}

	return tipos_contatos;
}
//---------------------------------------------------------------------------
TList* TFTiposContatosDAO::store(TiposContatos *tipos_contato)
{
	TRttiContext context;
	TList *listRecords = new TList();
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;
	TJSONArray *jsonRecordsStore;
	TJSONValue *jsonValue;
	TJSONObject *json;

	TJSONObject *jsonTiposContato;
	TJSONArray *arrayRecords = new TJSONArray();
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonTiposContato = TJson::ObjectToJsonObject((TObject*)tipos_contato);

		arrayRecords->Add(jsonTiposContato);
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
			TiposContatos *tipos_contato = new TiposContatos();

			UnicodeString sstr = jsonRecordsStore->ToString();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(TiposContatos)));

			JSONRtti::serialize(tipos_contato, cls, (TJSONObject*) jsonRecordsStore);

			listRecords->Add((TiposContatos*) tipos_contato);
		}
	}
	catch(const Exception &e)
	{
	}

    return listRecords;
}
//---------------------------------------------------------------------------
TList* TFTiposContatosDAO::update(TiposContatos *tipos_contato)
{
	TRttiContext context;
	TList *listRecords = new TList();
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;
	TJSONArray *jsonRecordsStore;
	TJSONValue *jsonValue;
	TJSONObject *json;

	TJSONObject *jsonTiposContato;
	TJSONArray *arrayRecords = new TJSONArray();
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonTiposContato = TJson::ObjectToJsonObject((TObject*)tipos_contato);

		arrayRecords->Add(jsonTiposContato);
		jsonRecords->AddPair("records", arrayRecords);

		jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource + "/" + IntToStr(tipos_contato->id);
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
			TiposContatos *tipos_contato = new TiposContatos();

			UnicodeString sstr = jsonRecordsStore->ToString();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(TiposContatos)));

			JSONRtti::serialize(tipos_contato, cls, (TJSONObject*) jsonRecordsStore);

			listRecords->Add((TiposContatos*) tipos_contato);
		}
	}
	catch(const Exception &e)
	{
	}

    return listRecords;
}
//---------------------------------------------------------------------------
void TFTiposContatosDAO::destroy(TiposContatos *tipos_contato)
{
	UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;

	TJSONObject *jsonTiposContato;
	TJSONArray *arrayRecords = new TJSONArray();;
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->Resource = resource + "/" + IntToStr(tipos_contato->id);
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




