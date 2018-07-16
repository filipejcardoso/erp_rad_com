//---------------------------------------------------------------------------

#pragma hdrstop

#include "GridHelper.h"
#include "Produtos.h"
#include "ValueHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
GridHelper::GridHelper(TStringGrid *grid)
{
    StringGrid = grid;
    this->instance();
}
//---------------------------------------------------------------------------
GridHelper::GridHelper()
{
    this->instance();
}
//---------------------------------------------------------------------------
void GridHelper::instance()
{
    this->checkOnlyOne = false;
	this->checkBox = false;
	this->primaryKey = false;

	listChecked = new TList();
}
//---------------------------------------------------------------------------
void GridHelper::gerarGrid()
{
	TRttiInstanceType *cls = fields->RttiInstance;
	TList *listFields = fields->getChecked();
    int index = this->getIndex();
	int numerodalinha = 1;
	Field *fieldObj;
	TValue valor;
	TRttiField *field;

	estruturarGrid();

	for(int i=0; i<list->Count; i++)
	{
		for(int j=0;j<listFields->Count;j++)
        {
			fieldObj = (Field*) listFields->Items[j];

			if(fieldObj->relation == NULL)
			{
				field = cls->GetField(fieldObj->column);

				valor = field->GetValue(list->Items[i]);

				StringGrid->Cells[j + index][numerodalinha] = ValueHelper::ValueToStr(valor);
			}
			else
			{
				field = cls->GetField(fieldObj->relation);

                TRttiInstanceType *c = field->FieldType->AsInstance;

				TValue value_relation = field->GetValue(list->Items[i]);

				TRttiField *field_relation = c->GetField(fieldObj->column);

				valor = field_relation->GetValue(value_relation.AsObject());

				StringGrid->Cells[j + index][numerodalinha] = ValueHelper::ValueToStr(valor);
			}
		}

		if(this->primaryKey)
		{
			fieldObj = fields->getPrimaryKey();

			field = cls->GetField(fieldObj->column);

			valor = field->GetValue(list->Items[i]);

			StringGrid->Cells[0][numerodalinha] = ValueHelper::ValueToStr(valor);
		}

		StringGrid->RowCount++;

		numerodalinha++;

		if (numerodalinha == 2)
			StringGrid->FixedRows = 1;
	}
	if (numerodalinha <= 1)
	{
		StringGrid->RowCount++;
		StringGrid->FixedRows = 1;
	}

	sizeGrid();
}
//---------------------------------------------------------------------------
void GridHelper::sizeGrid()
{
    TList *sizeMed = new TList();
	UnicodeString texto;
	int size,total, index;
	float frac;

	index = this->getIndex();

	for(int i=index;i<StringGrid->ColCount;i++)
		sizeMed->Add((int)0);

	for(int i=index;i<StringGrid->ColCount;i++)
		for(int j=0;j<StringGrid->RowCount;j++)
		{
			texto = StringGrid->Cells[i][j];
			size = texto.Length();

			sizeMed->Items[i - index] = (void*)(size + (int)sizeMed->Items[i - index]);
		}

	for(int i=index;i<StringGrid->ColCount;i++)
		sizeMed->Items[i - index] = (void*)((int)sizeMed->Items[i - index]/StringGrid->RowCount);

	total = 0;
	for(int i=index;i<StringGrid->ColCount;i++)
		total = total + (int)sizeMed->Items[i - index];

	if(total>0)
	{
		frac = (float)StringGrid->Width/total;
		for(int i=index;i<StringGrid->ColCount;i++)
		{
			size = (int)sizeMed->Items[i - index];
			StringGrid->ColWidths[i] = (float)(size * frac);
		}

		if(index)
			StringGrid->ColWidths[0] = 0;
	}
}
//---------------------------------------------------------------------------
void GridHelper::estruturarGrid()
{
	Field *field;
	TList *listFields;

	listFields = fields->getChecked();

	int index = this->getIndex();

	for(int i=1;i<StringGrid->RowCount;i++)
		StringGrid->Rows[i]->Clear();

	StringGrid->Options << goRowSelect;
	StringGrid->ScrollBars = ssVertical;
	StringGrid->Rows[1]->Clear();
	StringGrid->RowCount = 0;
	StringGrid->ColCount = listFields->Count + index;
	StringGrid->FixedCols = 0;

	for(int i=index; i<StringGrid->ColCount; i++)
	{
		field = (Field*) listFields->Items[i-index];

		StringGrid->Cells[i][0] = field->text;
	}
}
//---------------------------------------------------------------------------
int GridHelper::getIndex()
{
	if(this->primaryKey)
		return 1;
	else
		return 0;
}
//---------------------------------------------------------------------------
bool GridHelper::isChecked(int ARow)
{
	for(int i=0;i<listChecked->Count;i++)
	{
		int row = ((Row*) listChecked->Items[i])->row;

		if(row == ARow)
			return true;
	}

	return false;
}
//---------------------------------------------------------------------------
int GridHelper::countChecked()
{
	return  listChecked->Count;
}

//---------------------------------------------------------------------------
void GridHelper::checkRow(int ARow)
{
	if(ARow == 0)
	{
		listChecked->Clear();
		for(int i=0;i<StringGrid->RowCount;i++)
			listChecked->Add((Row*) new Row(i));
	}
	else
	{
		if(!isChecked(ARow))
			listChecked->Add((Row*) new Row(ARow));
	}
}
//---------------------------------------------------------------------------
void GridHelper::uncheckRow(int ARow)
{
	if(ARow == 0)
		listChecked->Clear();
	else
	{
		for(int i=0;i<listChecked->Count;i++)
		{
			int row = ((Row*) listChecked->Items[i])->row;

			if(row == ARow)
			{
				listChecked->Delete(i);
				break;
			}
		}
	}
}
//---------------------------------------------------------------------------
void GridHelper::clearCheck()
{
	listChecked->Clear();
}
//---------------------------------------------------------------------------
void GridHelper::selectRow(int ARow)
{
	if(isChecked(ARow))
		uncheckRow(ARow);
	else
	{
		if(this->checkOnlyOne)
			this->clearCheck();

		checkRow(ARow);
    }
}
//---------------------------------------------------------------------------
GridHelper::Row::Row(int r)
{
    this->row = r;
}
//---------------------------------------------------------------------------
void GridHelper::insertCol(int col)
{
    UnicodeString title;
	StringGrid->ColCount++;

	for(int i=0;i<StringGrid->RowCount;i++)
		for(int j=StringGrid->ColCount-1;j>col;j--)
		{
			StringGrid->Cells[j][i] = StringGrid->Cells[j - 1][i];

			if(j==(col+1))
			{
				if(i==0)
				{
                    title = "";
					for(int k=0;k<StringGrid->RowCount;k++)
                        title = title + " ";

					StringGrid->Cells[j-1][i] = title;
				}
				else
					StringGrid->Cells[j-1][i] = "";
			}
		}

    this->sizeGrid();
}

