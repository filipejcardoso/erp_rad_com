//---------------------------------------------------------------------------
#pragma hdrstop

#include "AssociadosDAO.h"
#include "Associados.h"
#include "Result.h"
#include "Sistema.h"
#include "HttpMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TFAssociadosDAO *FAssociadosDAO;
//---------------------------------------------------------------------------
__fastcall TFAssociadosDAO::TFAssociadosDAO(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
TList* TFAssociadosDAO::index(UnicodeString queryParams)
{
	TList *associados = new TList();
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
				Associados *associado = new Associados();

				// Get class RTTI
				TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
				(context.GetType(__delphirtti(Associados)));

				JSONRtti::serialize(associado, cls, json);

				associados->Add((Associados*) associado);
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

	return associados;
}
//---------------------------------------------------------------------------
TList* TFAssociadosDAO::show(UnicodeString queryParams, int id)
{
	TList *associados = new TList();
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

		Associados *associado = new Associados();

		// Get class RTTI
		TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
		(context.GetType(__delphirtti(Associados)));

		JSONRtti::serialize(associado, cls, json);

		associados->Add((Associados*) associado);
	} catch(const Exception& e)
	{
	}

	return associados;
}
//---------------------------------------------------------------------------
TList* TFAssociadosDAO::store(Associados *associado)
{
	TRttiContext context;
	TList *listRecords = new TList();
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;
	TJSONArray *jsonRecordsStore;
	TJSONValue *jsonValue;
	TJSONObject *json;

	TJSONObject *jsonAssociado;
	TJSONArray *arrayRecords = new TJSONArray();
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonAssociado = TJson::ObjectToJsonObject((TObject*)associado);

		arrayRecords->Add(jsonAssociado);
		jsonRecords->AddPair("records", arrayRecords);

		//FIX f no comeco
        jsonAssociado->RemovePair("ax");
        jsonAssociado->AddPair("fax",associado->fax);

		//REMOVE RALATION
		jsonAssociado->RemovePair("contato");
		jsonAssociado->RemovePair("endereco");
		jsonAssociado->RemovePair("referencias_bancaria");

		jsonValue = jsonAssociado->GetValue("info_financeira");
		UnicodeString sstr = jsonValue->ToString();
		if(jsonValue->GetValue<int>("id") == 0)
			jsonAssociado->RemovePair("info_financeira");

		jsonValue = jsonAssociado->GetValue("grupos_associado");
		if(jsonValue->GetValue<int>("id") == 0)
			jsonAssociado->RemovePair("grupos_associado");

		jsonValue = jsonAssociado->GetValue("indicacao_id");
		if(jsonValue->ToString() == "0")
			jsonAssociado->RemovePair("indicacao_id");

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
			Associados *associado = new Associados();

			UnicodeString sstr = jsonRecordsStore->ToString();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(Associados)));

			JSONRtti::serialize(associado, cls, (TJSONObject*) jsonRecordsStore);

			listRecords->Add((Associados*) associado);
		}
	}
	catch(const Exception &e)
	{
	}

    return listRecords;
}
//---------------------------------------------------------------------------
TList* TFAssociadosDAO::update(Associados *associado)
{
	TRttiContext context;
	TList *listRecords = new TList();
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;
	TJSONArray *jsonRecordsStore;
	TJSONValue *jsonValue;
	TJSONObject *json;

	TJSONObject *jsonAssociado;
	TJSONArray *arrayRecords = new TJSONArray();
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonAssociado = TJson::ObjectToJsonObject((TObject*)associado);

		arrayRecords->Add(jsonAssociado);
		jsonRecords->AddPair("records", arrayRecords);

		//FIX f no comeco
        jsonAssociado->RemovePair("ax");
        jsonAssociado->AddPair("fax",associado->fax);

		//REMOVE RALATION
		jsonAssociado->RemovePair("contato");
		jsonAssociado->RemovePair("endereco");
		jsonAssociado->RemovePair("referencias_bancaria");

		jsonValue = jsonAssociado->GetValue("info_financeira");
		jsonAssociado->RemovePair("info_financeira");

		jsonValue = jsonAssociado->GetValue("grupos_associado");
		if(jsonValue->GetValue<int>("id") == 0)
			jsonAssociado->RemovePair("grupos_associado");

		jsonValue = jsonAssociado->GetValue("indicacao_id");
		if(jsonValue->ToString() == "0")
			jsonAssociado->RemovePair("indicacao_id");

		jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource + "/" + IntToStr(associado->id);
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
			Associados *associado = new Associados();

			UnicodeString sstr = jsonRecordsStore->ToString();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(Associados)));

			JSONRtti::serialize(associado, cls, (TJSONObject*) jsonRecordsStore);

			listRecords->Add((Associados*) associado);
        }
	}
	catch(const Exception &e)
	{
	}

}
//---------------------------------------------------------------------------
void TFAssociadosDAO::destroy(Associados *associado)
{
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;

	TJSONObject *jsonAssociado;
	TJSONArray *arrayRecords = new TJSONArray();;
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->Resource = resource + "/" + IntToStr(associado->id);
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


