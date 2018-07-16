//---------------------------------------------------------------------------

#ifndef PaginatorH
#define PaginatorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <REST.Json.hpp>
#include <System.JSON.hpp>
#include <Rtti.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti fields(public)
//---------------------------------------------------------------------------
class __declspec(delphiclass) Paginator : public TPersistent
{
	private:

	public:
        int per_page;
		int current_page;
		int last_page;
		int count;

        Paginator();
		Paginator(TJSONArray*);
		void setJSON(TJSONArray*);
};
#endif

