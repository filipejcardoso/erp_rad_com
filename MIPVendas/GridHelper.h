//---------------------------------------------------------------------------

#ifndef GridHelperH
#define GridHelperH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Grids.hpp>
#include <Rtti.hpp>
#include "Fields.h"
#include "Field.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, public) properties (__published, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class __declspec(delphiclass) GridHelper : public TPersistent
{
	private:
        void instance();
		int getIndex();
		TList *listChecked;
		/*------SELECT LINES----------*/
		void checkRow(int ARow);
		void uncheckRow(int ARow);

		class Row
		{
			public:
				int row;
				Row(int);
        };

	public:
		TStringGrid *StringGrid;

		/*------PROPERTYS----------*/
		TList *list;
		Fields *fields;
		bool primaryKey;
		bool checkBox;
        bool checkOnlyOne;

		/*------MONTAR GRID-----------*/
		void gerarGrid();
		void estruturarGrid();
		void sizeGrid();
		void insertCol(int col);

		/*------SELECT LINES----------*/
		bool isChecked(int ARow);
		void selectRow(int ARow);
		void clearCheck();
        int countChecked();

		/*------CONSTRUTORES----------*/
		GridHelper();
        GridHelper(TStringGrid*);
};
#endif

