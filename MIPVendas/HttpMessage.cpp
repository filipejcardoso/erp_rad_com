//---------------------------------------------------------------------------

#pragma hdrstop

#include "HttpMessage.h"
#include "LoginBox.h"
#include "Sistema.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
int HttpMessage::check(TJSONObject *json, TRESTRequest *RESTRequest, TRESTResponse *RESTResponse, int flag)
{
    int ret = check(json, flag);

	if(ret == 440)
	{
		RESTRequest->Params->Clear();
		RESTRequest->Params->AddHeader("Authorization", "Bearer" + SISTEMA->usuario->token);
		RESTRequest->Execute();

		json = (TJSONObject*) RESTResponse->JSONValue;
	}

    return ret;
}
//---------------------------------------------------------------------------
int HttpMessage::check(TJSONObject *json, int flag)
{
	TJSONArray *jsonResult;

	Result *result = new Result();

	UnicodeString jsonStr = json->ToString();

	jsonResult = (TJSONArray*) json->GetValue("result");

	if(jsonResult)
		result->setJSON(jsonResult);
	else
	{
		MessageBox(NULL, L"Desculpe o JSON não possui dados suficientes sobre o resultado da operação", L"JSON Inválido", MB_OK | MB_ICONINFORMATION);
		return 0;
	}

	/*
		FLAG
        -1 - nao tratar exceçoes
		0 - tratar excecoes
		1 - tratar STORE, UPDATE
		2 - tratar DELETE
	*/
	switch(result->code)
	{
		case 200:
			//Eyerything is working
			if(flag == 2)
				return HttpMessage::destroyMessage(result);
			else
				return 1;
		break;
		case 201:
			//New resource has been created
			if(flag == 1)
				return HttpMessage::storeMessage(result);
			else
				return 1;
		break;
		case 202:
			//The resource has been updated
			if(flag == 1)
				return HttpMessage::updateMessage(result);
			else
				return 1;
		break;
		case 400:
			//The request was invalid or cannot be served. The Params is not valid
            if(flag!=-1)
				return HttpMessage::invalidParams(result);
		break;
		case 401:
			//The request requires an user authentication
            if(flag!=-1)
				return HttpMessage::checkExpired(result);
		break;
		case 403:
			//The server understood the request, but is refusing it or the access is not allowed
            if(flag!=-1)
				return HttpMessage::roleDenied(result);
		break;
		case 404:
			//There is no resource behind the URI
            if(flag!=-1)
				return HttpMessage::notFound(result);
		break;
		case 440:
			//The client's session has expired and must log in again
            if(flag!=-1)
				return HttpMessage::checkExpired(result);
		break;
		case 500:
			//Internal Server Error
            if(flag!=-1)
				return HttpMessage::internalMessage(result);
		break;
	}
}
//---------------------------------------------------------------------------
int HttpMessage::storeMessage(Result *result)
{
	UnicodeString title = "Result Message";
	UnicodeString text = result->internalMessage;

	if(result->code == 201)
	{
		MessageBox(NULL, L"Registro inserido com sucesso", title.w_str(), MB_OK | MB_ICONINFORMATION);
		return result->code;
	}
	else
	{
		MessageBox(NULL, L"Dados inválidos", title.w_str(), MB_OK | MB_ICONERROR);
		return 0;
	}
}
//---------------------------------------------------------------------------
int HttpMessage::updateMessage(Result *result)
{
	UnicodeString title = "Result Message";
	UnicodeString text = result->internalMessage;

	if(result->code == 202)
	{
		MessageBox(NULL, L"Registro alterado com sucesso", title.w_str(), MB_OK | MB_ICONINFORMATION);
		return result->code;
	}
	else
	{
		MessageBox(NULL, L"Dados inválidos", title.w_str(), MB_OK | MB_ICONERROR);
		return 0;
	}
}
//---------------------------------------------------------------------------
int HttpMessage::destroyMessage(Result *result)
{
	UnicodeString title = "Result Message";
	UnicodeString text = result->internalMessage;

	if(result->code == 200)
	{
		MessageBox(NULL, L"Registro deletado com sucesso", title.w_str(), MB_OK | MB_ICONINFORMATION);
		return result->code;
	}
	else
	{
		MessageBox(NULL, L"Operação negada", title.w_str(), MB_OK | MB_ICONERROR);
		return 0;
	}
}
//---------------------------------------------------------------------------
int HttpMessage::internalMessage(Result *result)
{
	UnicodeString title = result->userMessage;
	UnicodeString text = result->internalMessage;

	MessageBox(NULL, text.w_str(), title.w_str(), MB_OK | MB_ICONERROR);
	return result->code;
}
//---------------------------------------------------------------------------
int HttpMessage::invalidParams(Result *result)
{
	UnicodeString text = result->internalMessage;

	MessageBox(NULL, text.w_str(), L"Parâmetros inválidos", MB_OK | MB_ICONERROR);
	return result->code;
}
//---------------------------------------------------------------------------
int HttpMessage::notFound(Result *result)
{
	UnicodeString text = result->internalMessage;

//	MessageBox(NULL, L"Recurso não encontrado", text.w_str(), MB_OK | MB_ICONERROR);
	return result->code;
}
//---------------------------------------------------------------------------
int HttpMessage::roleDenied(Result *result)
{
	UnicodeString text = result->internalMessage;

	MessageBox(NULL, L"Voce não possui acesso a este recurso", L"Acesso negado", MB_OK | MB_ICONERROR);

	throw Exception("Acesso negado");

	return result->code;
}
//---------------------------------------------------------------------------
int HttpMessage::checkExpired(Result *result)
{
	if(result->code == 440)
	{
		SISTEMA->usuario->token = NULL;
		FLoginBox->Show();

		while(SISTEMA->usuario->token == NULL)
			Application->ProcessMessages();

//		throw Exception("Token expirado");
        return result->code;
	}
	else
        return 1;
}

