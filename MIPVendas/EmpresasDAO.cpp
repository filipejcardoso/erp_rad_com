//---------------------------------------------------------------------------
#pragma hdrstop

#include "EmpresasDAO.h"
#include "Empresas.h"
#include "Result.h"
#include "Sistema.h"
#include "HttpMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TFEmpresasDAO *FEmpresasDAO;
//---------------------------------------------------------------------------
__fastcall TFEmpresasDAO::TFEmpresasDAO(TComponent* Owner)
	: TDataModule(Owner)
{
    resource = "empresas";
}
//---------------------------------------------------------------------------
TList* TFEmpresasDAO::show()
{
	TList *empresas = new TList();
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

		Empresas *empresa = new Empresas();

		// Get class RTTI
		TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
		(context.GetType(__delphirtti(Empresas)));

		JSONRtti::serialize(empresa, cls, (TJSONObject*) jsonRecords->Items[0]);

		empresas->Add((Empresas*) empresa);
	} catch(const Exception& e)
	{
	}

	return empresas;
}
//---------------------------------------------------------------------------
TList* TFEmpresasDAO::update(Empresas *empresa)
{
	TRttiContext context;
	TList *listRecords = new TList();
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;
	TJSONArray *jsonRecordsStore;
	TJSONValue *jsonValue;
	TJSONObject *json;

	TJSONObject *jsonEmpresa;
	TJSONArray *arrayRecords = new TJSONArray();
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonEmpresa = TJson::ObjectToJsonObject((TObject*)empresa);

		arrayRecords->Add(jsonEmpresa);
		jsonRecords->AddPair("records", arrayRecords);

		jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource + "/" + IntToStr(empresa->id);
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
			Empresas *empresa = new Empresas();

			UnicodeString sstr = jsonRecordsStore->ToString();

			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(Empresas)));

			JSONRtti::serialize(empresa, cls, (TJSONObject*) jsonRecordsStore);

			listRecords->Add((Empresas*) empresa);
        }
	}
	catch(const Exception &e)
	{
	}

    return listRecords;
}
//---------------------------------------------------------------------------
