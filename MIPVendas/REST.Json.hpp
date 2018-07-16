// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'REST.Json.pas' rev: 31.00 (Windows)

#ifndef Rest_JsonHPP
#define Rest_JsonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.JSON.hpp>
#include <REST.JsonReflect.hpp>

//-- user supplied -----------------------------------------------------------

namespace Rest
{
namespace Json
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TJson;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TJsonOption : unsigned char { joIgnoreEmptyStrings, joIgnoreEmptyArrays, joDateIsUTC, joDateFormatUnix, joDateFormatISO8601, joDateFormatMongo, joDateFormatParse };

typedef System::Set<TJsonOption, TJsonOption::joIgnoreEmptyStrings, TJsonOption::joDateFormatParse> TJsonOptions;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJson : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static void __fastcall ProcessOptions(System::Json::TJSONObject* AJsonObject, TJsonOptions AOptions);
	
public:
	__classmethod System::Json::TJSONObject* __fastcall ObjectToJsonObject(System::TObject* AObject, TJsonOptions AOptions = (TJsonOptions() << TJsonOption::joDateIsUTC << TJsonOption::joDateFormatISO8601 ));
	__classmethod System::UnicodeString __fastcall ObjectToJsonString(System::TObject* AObject, TJsonOptions AOptions = (TJsonOptions() << TJsonOption::joDateIsUTC << TJsonOption::joDateFormatISO8601 ));
	template<typename T> __classmethod T __fastcall JsonToObject(System::Json::TJSONObject* AJsonObject, TJsonOptions AOptions = (TJsonOptions() << TJsonOption::joDateIsUTC << TJsonOption::joDateFormatISO8601 ))/* overload */;
	template<typename T> __classmethod T __fastcall JsonToObject(System::UnicodeString AJson, TJsonOptions AOptions = (TJsonOptions() << TJsonOption::joDateIsUTC << TJsonOption::joDateFormatISO8601 ))/* overload */;
	__classmethod void __fastcall JsonToObject(System::TObject* AObject, System::Json::TJSONObject* AJsonObject, TJsonOptions AOptions = (TJsonOptions() << TJsonOption::joDateIsUTC << TJsonOption::joDateFormatISO8601 ))/* overload */;
	__classmethod System::UnicodeString __fastcall Format(System::Json::TJSONValue* AJsonValue);
	__classmethod System::UnicodeString __fastcall JsonEncode(System::Json::TJSONValue* AJsonValue)/* overload */;
	__classmethod System::UnicodeString __fastcall JsonEncode(System::UnicodeString AJsonString)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TJson(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TJson(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Json */
}	/* namespace Rest */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_REST_JSON)
using namespace Rest::Json;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_REST)
using namespace Rest;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Rest_JsonHPP
