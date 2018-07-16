//---------------------------------------------------------------------------
#pragma hdrstop

#include "ContatosDAO.h"
#include "Contatos.h"
#include "Result.h"
#include "Sistema.h"
#include "HttpMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TFContatosDAO *FContatosDAO;
//---------------------------------------------------------------------------
__fastcall TFContatosDAO::TFContatosDAO(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
TList* TFContatosDAO::index(UnicodeString queryParams)
{
	TList *contatos = new TList();
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

		if(jsonRecords!=NULL)
		{
			for(int i=0;i<jsonRecords->Count;i++)
			{
				json = (TJSONObject*) jsonRecords->Items[i];
				Contatos *contato = new Contatos();

				// Get class RTTI
				TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
				(context.GetType(__delphirtti(Contatos)));

				JSONRtti::serialize(contato, cls, json);

				contatos->Add((Contatos*) contato);
			}
		}

		if(paginate!=NULL)
		{
			jsonPaginate = (TJSONArray*) jsonObj->GetValue("paginate");
			paginate->setJSON(jsonPaginate);
		}

	} catch(const Exception& e)
	{
	}

	return contatos;
}
//---------------------------------------------------------------------------
TList* TFContatosDAO::show(UnicodeString queryParams, int id)
{
	TList *contatos = new TList();
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

		Contatos *contato = new Contatos();

		// Get class RTTI
		TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
		(context.GetType(__delphirtti(Contatos)));

		JSONRtti::serialize(contato, cls, json);

		contatos->Add((Contatos*) contato);
	} catch(const Exception& e)
	{
	}

	return contatos;
}
//---------------------------------------------------------------------------
TList* TFContatosDAO::store(Associados* associado, Contatos *contato)
{
	TRttiContext context;
	TList *listRecords = new TList();
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;
	TJSONArray *jsonRecordsStore;
	TJSONValue *jsonValue;
	TJSONObject *json;

	TJSONObject *jsonContato;
	TJSONArray *arrayRecords = new TJSONArray();
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonContato = TJson::ObjectToJsonObject((TObject*)contato);

		arrayRecords->Add(jsonContato);
		jsonRecords->AddPair("records", arrayRecords);

		jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource + "/" + IntToStr(associado->id) + "/contatos";
		RESTRequest->Method = TRESTRequestMethod::rmPOST;
		RESTRequest->AddBody(jsonStr, ContentTypeFromString("application/json"));
		RESTRequest->Execute();

		jsonObj = (TJSONObject*) RESTResponse->JSONValue;

		HttpMessage::check(jsonObj, RESTRequest, RESTResponse, 0);

		if(result!=NULL)
		{
			jsonResult = (TJSONArray*) jsonObj->GetValue("result");
			result->setJSON(jsonResult);
		}

		jsonRecordsStore = (TJSONArray*) jsonObj->GetValue("records");

		if(jsonRecordsStore!=NULL)
		{
			Contatos *contato = new Contatos();

			UnicodeString sstr = jsonRecordsStore->ToString();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(Contatos)));

			JSONRtti::serialize(contato, cls, (TJSONObject*) jsonRecordsStore);

			listRecords->Add((Contatos*) contato);
		}
	}
	catch(const Exception &e)
	{
	}

    return listRecords;
}
//---------------------------------------------------------------------------
TList* TFContatosDAO::update(Contatos *contato)
{
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;

	TJSONObject *jsonContato;
	TJSONArray *arrayRecords = new TJSONArray();;
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonContato = TJson::ObjectToJsonObject((TObject*)contato);

		arrayRecords->Add(jsonContato);
		jsonRecords->AddPair("records", arrayRecords);

		jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource + "/" + IntToStr(contato->id);
		RESTRequest->Method = TRESTRequestMethod::rmPATCH;
		RESTRequest->AddBody(jsonStr, ContentTypeFromString("application/json"));
		RESTRequest->Execute();

		jsonObj = (TJSONObject*) RESTResponse->JSONValue;

		HttpMessage::check(jsonObj, RESTRequest, RESTResponse, 0);

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
//---------------------------------------------------------------------------
void TFContatosDAO::destroy(Associados* associado, Contatos *contato)
{
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;

	TJSONObject *jsonContato;
	TJSONArray *arrayRecords = new TJSONArray();;
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->Resource = resource + "/" + IntToStr(associado->id) + "/contatos/" + IntToStr(contato->id);
		RESTRequest->Method = TRESTRequestMethod::rmDELETE;
		RESTRequest->Execute();

		jsonObj = (TJSONObject*) RESTResponse->JSONValue;

		HttpMessage::check(jsonObj, 0);

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


