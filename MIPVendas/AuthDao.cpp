//---------------------------------------------------------------------------
#pragma hdrstop

#include "AuthDao.h"
#include "Sistema.h"
#include "HttpMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TFAuthDAO *FAuthDAO;
//---------------------------------------------------------------------------
__fastcall TFAuthDAO::TFAuthDAO(TComponent* Owner)
	: TDataModule(Owner)
{
    resource = "auth";
}
//---------------------------------------------------------------------------
User* TFAuthDAO::login(User *user)
{
   	TRttiContext context;
	UnicodeString jsonStr;
	TJSONArray *jsonResult,*jsonRecords;
	TJSONObject *jsonObj;

	TJSONObject *json;
	try{
		json = TJson::ObjectToJsonObject((TObject*)user);
		jsonStr = json->ToString();

        RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource + "/login";
		RESTRequest->Method = TRESTRequestMethod::rmPOST;
		RESTRequest->AddBody(jsonStr, ContentTypeFromString("application/json"));
		RESTRequest->Execute();

		jsonObj = (TJSONObject*) RESTResponse->JSONValue;

		if(result!=NULL && jsonObj!=NULL)
		{
			jsonResult = (TJSONArray*) jsonObj->GetValue("result");
			result->setJSON(jsonResult);
		}

		jsonRecords = (TJSONArray*) jsonObj->GetValue("records");

		if(jsonRecords!=NULL)
		{
			// Get class RTTI
			TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
			(context.GetType(__delphirtti(User)));

			JSONRtti::serialize(SISTEMA->usuario, cls, (TJSONObject*) jsonRecords);

			JSONRtti::serialize(SISTEMA->usuario, cls, (TJSONObject*) jsonObj);
		}
	}
	catch(const Exception &e)
	{
	}
}

void TFAuthDAO::logout()
{

}

