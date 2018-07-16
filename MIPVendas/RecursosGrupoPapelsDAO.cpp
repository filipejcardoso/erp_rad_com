//---------------------------------------------------------------------------


#pragma hdrstop

#include "RecursosGrupoPapelsDAO.h"
#include "HttpMessage.h"
#include "Sistema.h"
#include "JSONRtti.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TFRecursosGrupoPapelsDAO *FRecursosGrupoPapelsDAO;
//---------------------------------------------------------------------------
__fastcall TFRecursosGrupoPapelsDAO::TFRecursosGrupoPapelsDAO(TComponent* Owner)
	: TDataModule(Owner)
{
	paginate = NULL;
	resource = "recursos_grupo_papels";
}
//---------------------------------------------------------------------------
TList* TFRecursosGrupoPapelsDAO::store()
{
	TList *recursosGrupoPapels = new TList();
	TRttiContext context;
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;
	TJSONObject *json;

	try{
		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = resource;
		RESTRequest->Method = TRESTRequestMethod::rmPOST;
		RESTRequest->Execute();

		jsonObj = (TJSONObject*) RESTResponse->JSONValue;

		HttpMessage::check(jsonObj, RESTRequest, RESTResponse, 0);

		if(result!=NULL && jsonObj!=NULL)
		{
			jsonResult = (TJSONArray*) jsonObj->GetValue("result");
			result->setJSON(jsonResult);
		}

		json = (TJSONObject*) jsonObj->GetValue("records");

		RecursosGrupoPapels *auxiliar = new RecursosGrupoPapels();

		// Get class RTTI
		TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
		(context.GetType(__delphirtti(RecursosGrupoPapels)));

		JSONRtti::serialize(auxiliar, cls, json);

		recursosGrupoPapels->Add((RecursosGrupoPapels*) auxiliar);
	}
	catch(const Exception &e)
	{
	}

	return recursosGrupoPapels;
}
//---------------------------------------------------------------------------
