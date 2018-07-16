//---------------------------------------------------------------------------

#ifndef FieldsH
#define FieldsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Rtti.hpp>
#include "Field.h"
//---------------------------------------------------------------------------
class Fields
{
	private:
		void initList(TRttiInstanceType *cls, UnicodeString relation);

	public:
		TRttiInstanceType *RttiInstance;
		TList *fieldsList;

		Fields::Fields(TRttiInstanceType *cls, UnicodeString relation);

        int CountChecked();
        TList* getChecked();

        int CountVisible();
		TList* getVisible();

		Field* GetField(UnicodeString);

       Field* getPrimaryKey();
};
#endif

