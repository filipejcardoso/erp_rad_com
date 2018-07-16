//---------------------------------------------------------------------------
#pragma hdrstop

#include "ReferenciasBancariasDAO.h"
#include "ReferenciasBancarias.h"
#include "Result.h"
#include "Sistema.h"
#include "HttpMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TFReferenciasBancariasDAO *FReferenciasBancariasDAO;
//---------------------------------------------------------------------------
__fastcall TFReferenciasBancariasDAO::TFReferenciasBancariasDAO(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
TList* TFReferenciasBancariasDAO::index(UnicodeString queryParams)
{
	TList *referencias_bancarias = new TList();
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
				ReferenciasBancarias *referencias_bancaria = new ReferenciasBancarias();

				// Get class RTTI
				TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
				(context.GetType(__delphirtti(ReferenciasBancarias)));

				JSONRtti::serialize(referencias_bancaria, cls, json);

				referencias_bancarias->Add((ReferenciasBancarias*) referencias_bancaria);
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

	return referencias_bancarias;
}
//---------------------------------------------------------------------------
TList* TFReferenciasBancariasDAO::show(UnicodeString queryParams, int id)
{
	TList *referencias_bancarias = new TList();
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

		ReferenciasBancarias *referencias_bancaria = new ReferenciasBancarias();

		// Get class RTTI
		TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
		(context.GetType(__delphirtti(ReferenciasBancarias)));

		JSONRtti::serialize(referencias_bancaria, cls, json);

		referencias_bancarias->Add((ReferenciasBancarias*) referencias_bancaria);
	} catch(const Exception& e)
	{
	}

	return referencias_bancarias;
}
//---------------------------------------------------------------------------
TList* TFReferenciasBancariasDAO::store(Associados *associado, ReferenciasBancarias *referencias_bancaria)
{
	TRttiContext context;
	TList *listRecords = new TList();
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;
	TJSONArray *jsonRecordsStore;
	TJSONValue *jsonValue;
	TJSONObject *json;

	TJSONObject *jsonReferenciasBancaria;
	TJSONArray *arrayRecords = new TJSONArray();
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonReferenciasBancaria = TJson::ObjectToJsonObject((TObject*)referencias_bancaria);

		arrayRecords->Add(jsonReferenciasBancaria);
		jsonRecords->AddPair("records", arrayRecords);

		jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource + "/" + IntToStr(associado->id) + "/referencias_bancarias";
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
			ReferenciasBancarias *referencias_bancaria = new ReferenciasBancarias();

			UnicodeString sstr = jsonRecordsStore->ToString();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(ReferenciasBancarias)));

			JSONRtti::serialize(referencias_bancaria, cls, (TJSONObject*) jsonRecordsStore);

			listRecords->Add((ReferenciasBancarias*) referencias_bancaria);
		}
	}
	catch(const Exception &e)
	{
	}

    return listRecords;
}
//---------------------------------------------------------------------------
TList* TFReferenciasBancariasDAO::update(ReferenciasBancarias *referencias_bancaria)
{
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;

	TJSONObject *jsonReferenciasBancaria;
	TJSONArray *arrayRecords = new TJSONArray();;
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonReferenciasBancaria = TJson::ObjectToJsonObject((TObject*)referencias_bancaria);

		arrayRecords->Add(jsonReferenciasBancaria);
		jsonRecords->AddPair("records", arrayRecords);

		jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource + "/" + IntToStr(referencias_bancaria->id);
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
void TFReferenciasBancariasDAO::destroy(Associados *associado, ReferenciasBancarias *referencias_bancaria)
{
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;

	TJSONObject *jsonReferenciasBancaria;
	TJSONArray *arrayRecords = new TJSONArray();;
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->Resource = resource + "/" + IntToStr(associado->id) + "/referencias_bancarias/" + IntToStr(referencias_bancaria->id);
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


