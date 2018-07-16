//---------------------------------------------------------------------------
#pragma hdrstop

#include "ConfiguracoesDAO.h"
#include "Configuracoes.h"
#include "Result.h"
#include "Sistema.h"
#include "HttpMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TFConfiguracoesDAO *FConfiguracoesDAO;
//---------------------------------------------------------------------------
__fastcall TFConfiguracoesDAO::TFConfiguracoesDAO(TComponent* Owner)
	: TDataModule(Owner)
{
    resource = "configuracoes";
}
//---------------------------------------------------------------------------
TList* TFConfiguracoesDAO::show()
{
	TList *configuracoes = new TList();
   	TRttiContext context;
	TJSONArray *jsonRecords;
	TJSONObject *jsonObj;
	TJSONArray *jsonResult;

	try{
		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Method = TRESTRequestMethod::rmGET;
		RESTRequest->Resource = resource;
		RESTRequest->Execute();
		jsonObj = (TJSONObject*) RESTResponse->JSONValue;

		HttpMessage::check(jsonObj, RESTRequest, RESTResponse, 0);

		if(result!=NULL && jsonObj!=NULL)
		{
			jsonResult = (TJSONArray*) jsonObj->GetValue("result");
			result->setJSON(jsonResult);
		}

		jsonRecords = (TJSONArray*) jsonObj->GetValue("records");

		Configuracoes *configuracao = new Configuracoes();

		// Get class RTTI
		TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
		(context.GetType(__delphirtti(Configuracoes)));

		JSONRtti::serialize(configuracao, cls, (TJSONObject*) jsonRecords->Items[0]);

		configuracoes->Add((Configuracoes*) configuracao);
	} catch(const Exception& e)
	{
	}

	return configuracoes;
}
//---------------------------------------------------------------------------
TList* TFConfiguracoesDAO::update(Configuracoes *configuracao)
{
	TRttiContext context;
	TList *listRecords = new TList();
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;
	TJSONArray *jsonRecordsStore;
	TJSONValue *jsonValue;
	TJSONObject *json;

	TJSONObject *jsonConfiguracoes;
	TJSONArray *arrayRecords = new TJSONArray();
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonConfiguracoes = TJson::ObjectToJsonObject((TObject*)configuracao);

		arrayRecords->Add(jsonConfiguracoes);
		jsonRecords->AddPair("records", arrayRecords);

		jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource + "/" + IntToStr(configuracao->id);
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
			Configuracoes *configuracao = new Configuracoes();

			UnicodeString sstr = jsonRecordsStore->ToString();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(Configuracoes)));

			JSONRtti::serialize(configuracao, cls, (TJSONObject*) jsonRecordsStore);

			listRecords->Add((Configuracoes*) configuracao);
        }
	}
	catch(const Exception &e)
	{
	}

    return listRecords;
}
//---------------------------------------------------------------------------
