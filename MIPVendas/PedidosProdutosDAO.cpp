//---------------------------------------------------------------------------
#pragma hdrstop

#include "PedidosProdutosDAO.h"
#include "PedidosProdutos.h"
#include "Result.h"
#include "Sistema.h"
#include "HttpMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TFPedidosProdutosDAO *FPedidosProdutosDAO;
//---------------------------------------------------------------------------
__fastcall TFPedidosProdutosDAO::TFPedidosProdutosDAO(TComponent* Owner)
	: TDataModule(Owner)
{
	resource = "pedidos_produtos";

    pedidos = new Pedidos();
}
//---------------------------------------------------------------------------
TList* TFPedidosProdutosDAO::index(UnicodeString queryParams)
{
	TList *pedidos_produtos = new TList();
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
				PedidosProdutos *pedidos_produto = new PedidosProdutos();

				// Get class RTTI
				TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
				(context.GetType(__delphirtti(PedidosProdutos)));

				JSONRtti::serialize(pedidos_produto, cls, json);

				pedidos_produtos->Add((PedidosProdutos*) pedidos_produto);
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

	return pedidos_produtos;
}
//---------------------------------------------------------------------------
TList* TFPedidosProdutosDAO::show(UnicodeString queryParams, int id)
{
	TList *pedidos_produtos = new TList();
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

		PedidosProdutos *pedidos_produto = new PedidosProdutos();

		// Get class RTTI
		TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
		(context.GetType(__delphirtti(PedidosProdutos)));

		JSONRtti::serialize(pedidos_produto, cls, json);

		pedidos_produtos->Add((PedidosProdutos*) pedidos_produto);
	} catch(const Exception& e)
	{
	}

	return pedidos_produtos;
}
//---------------------------------------------------------------------------
TList* TFPedidosProdutosDAO::store(Pedidos *pedido, TList *listProdutos)
{
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;

	TJSONArray *arrayRecords = new TJSONArray();
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		for(int i=0;i<listProdutos->Count;i++)
		{
			PedidosProdutos *pedidos_produtos = (PedidosProdutos*) listProdutos->Items[i];

			TJSONObject *jsonProdutoId = new TJSONObject();
			jsonProdutoId->AddPair("codbarras", pedidos_produtos->codbarras);

			if(pedidos_produtos->quantidade != NULL || pedidos_produtos->quantidade!=0)
				jsonProdutoId->AddPair("quantidade", pedidos_produtos->quantidade);

			arrayRecords->Add(jsonProdutoId);
		}
		jsonRecords->AddPair("records", arrayRecords);

		UnicodeString jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = "pedidos/" + IntToStr(pedido->id) + "/" + resource;
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
	}
	catch(const Exception &e)
	{
	}

}
//---------------------------------------------------------------------------
TList* TFPedidosProdutosDAO::update(UnicodeString idPedido, UnicodeString idProduto, UnicodeString key, UnicodeString value)
{
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;

	TJSONObject *jsonProduto = new TJSONObject();

	try{
		jsonProduto->AddPair(key, value);

		jsonStr = jsonProduto->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->ClearBody();
		RESTRequest->Resource = "pedidos/" + idPedido + "/" + resource + "/" + idProduto;
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
void TFPedidosProdutosDAO::destroy(PedidosProdutos *pedidos_produto)
{
    UnicodeString jsonStr;
	TJSONArray *jsonResult;
	TJSONObject *jsonObj;

	TJSONObject *jsonPedidosProduto;
	TJSONArray *arrayRecords = new TJSONArray();;
	TJSONObject *jsonRecords = new TJSONObject();

	try{
		jsonPedidosProduto = TJson::ObjectToJsonObject((TObject*)pedidos_produto);

		arrayRecords->Add(jsonPedidosProduto);
		jsonRecords->AddPair("records", arrayRecords);

		jsonStr = jsonRecords->ToString();

		RESTClient->ContentType = "application/json";
		RESTClient->BaseURL = SISTEMA->api->getBaseURL();
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->Resource = resource + "/" + IntToStr(pedidos_produto->id);
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


