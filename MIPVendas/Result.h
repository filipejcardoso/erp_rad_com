//---------------------------------------------------------------------------

#ifndef ResultH
#define ResultH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <REST.Json.hpp>
#include <System.JSON.hpp>
#include <Rtti.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) Result : public TPersistent
{
	private:

	public:
		UnicodeString userMessage;
		UnicodeString internalMessage;
		int code;

		void setJSON(TJSONArray*);
};
#endif
