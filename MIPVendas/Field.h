//---------------------------------------------------------------------------

#ifndef FieldH
#define FieldH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Rtti.hpp>
//---------------------------------------------------------------------------
class Field
{
	private:
		bool Fchecked;
        void check(bool);

	public:
		UnicodeString name;
		UnicodeString column;
		UnicodeString relation;
		UnicodeString text;
		bool visible;
		bool primaryKey;
		bool required;
		__property bool checked={read=Fchecked,write=check};

		Field::Field();
};
#endif