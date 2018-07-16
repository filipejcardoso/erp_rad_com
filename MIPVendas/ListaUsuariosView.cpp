//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Papels.h"
#include "Principal.h"
#include "UsuariosView.h"
#include "ListaUsuariosView.h"
#include "UsuariosDAO.h"
#include "Style.h"
#include "QueryParams.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFListaUsuariosView *FListaUsuariosView;
//---------------------------------------------------------------------------
__fastcall TFListaUsuariosView::TFListaUsuariosView(TComponent* Owner)
	: TForm(Owner)
{
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(User)));

	field = new Fields(cls, "");
}
//---------------------------------------------------------------------------
void __fastcall TFListaUsuariosView::FormCreate(TObject *Sender)
{
    //CONFIGURAR O FORM
	ConfigurarForm(this);

	controller = new UsuariosController();
}
//---------------------------------------------------------------------------
void __fastcall TFListaUsuariosView::StringGridRecordsDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
    UnicodeString Texto;
	tagRECT *rc;

	rc = new tagRECT();
	rc->left = Rect.Left;
	rc->top = Rect.top;
	rc->right = Rect.Right;
	rc->bottom = Rect.Bottom;

	if (ARow>0)
	{
		Texto = StringGridRecords->Cells[ACol][ARow];

		StringGridRecords->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGridRecords->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGridRecords->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGridRecords->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGridRecords->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGridRecords->Canvas->FillRect(Rect);
		StringGridRecords->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGridRecords->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);
	}

}
//---------------------------------------------------------------------------
void __fastcall TFListaUsuariosView::StringGridRecordsDblClick(TObject *Sender)
{
	FUsuariosView->editar = 1;
	FUsuariosView->usuario->id = StrToInt(StringGridRecords->Cells[0][rowselectRecords]);
	FUsuariosView->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFListaUsuariosView::StringGridRecordsSelectCell(TObject *Sender, int ACol,
		  int ARow, bool &CanSelect)
{
	rowselectRecords = ARow;
	colselectRecords = ACol;
}
//---------------------------------------------------------------------------
void __fastcall TFListaUsuariosView::StringGridRecordsMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if(helperGridRecords)
		if(helperGridRecords->checkBox)
		{
			if(colselectRecords == 1)
				helperGridRecords->selectRow(rowselectRecords);

			StringGridRecords->Repaint();
		}
}
//---------------------------------------------------------------------------
void __fastcall TFListaUsuariosView::BtSearchClick(TObject *Sender)
{
    gridRecords();
}
//---------------------------------------------------------------------------
void TFListaUsuariosView::loadView()
{
	gridRecords();

	EditBusca->SetFocus();
}
//---------------------------------------------------------------------------
void TFListaUsuariosView::gridRecords()
{
	User *usuario;
	TRttiContext context;
	TList *usuarios;
	QueryParams *queryParams;
	int numerodalinha,i;

	for(i=1;i<StringGridRecords->RowCount;i++)
		StringGridRecords->Rows[i]->Clear();

	//ESTRUTURA
	StringGridRecords->Options << goRowSelect;
	StringGridRecords->ScrollBars = ssVertical;
	StringGridRecords->Rows[1]->Clear();
	StringGridRecords->RowCount = 0;
	StringGridRecords->ColCount = 5;
	StringGridRecords->FixedCols = 0;
	StringGridRecords->Cells[0][0] = "ID";
	StringGridRecords->Cells[1][0] = "Nome";
	StringGridRecords->Cells[2][0] = "Username";
	StringGridRecords->Cells[3][0] = "Email";
	StringGridRecords->Cells[4][0] = "Papel";
	//ESTRUTURA


	//QUERY PARAMS
	queryParams = new QueryParams();

	Fields *fields = new Fields(dynamic_cast<TRttiInstanceType*>(context.GetType(__delphirtti(User))), NULL);

	fields->GetField("id")->visible = true;
	fields->GetField("nome")->visible = true;
	fields->GetField("username")->visible = true;
	fields->GetField("email")->visible = true;
	fields->GetField("papel_nome")->visible = true;

	queryParams->fields = fields;

	queryParams->filters->addFilter(fields->GetField("nome"), "AND", "like", EditBusca->Text);
	queryParams->filters->addFilter(fields->GetField("username"), "OR", "like", EditBusca->Text);
	queryParams->filters->addFilter(fields->GetField("email"), "OR", "like", EditBusca->Text);
	queryParams->filters->addFilter(fields->GetField("papel_nome"), "OR", "like", EditBusca->Text);

	queryParams->sorts->addSort(fields->GetField("nome"), "ASC");
	//QUERY PARAMS

	usuarios = controller->index(queryParams->getQuery());

	if(usuarios->Count > 0)
	{
		for(numerodalinha=1; numerodalinha<usuarios->Count; numerodalinha++)
		{
			usuario = (User*) usuarios->Items[numerodalinha];

			StringGridRecords->Cells[0][numerodalinha] = usuario->id;
			StringGridRecords->Cells[1][numerodalinha] = usuario->nome;
			StringGridRecords->Cells[2][numerodalinha] = usuario->username;
			StringGridRecords->Cells[3][numerodalinha] = usuario->email;
			StringGridRecords->Cells[4][numerodalinha] = usuario->papel->nome;

			StringGridRecords->RowCount++;

			if (numerodalinha == 2)
				StringGridRecords->FixedRows = 1;
		}
		if (numerodalinha <= 1)
			StringGridRecords->RowCount++;
	}

	GridHelper *grid = new GridHelper();
	grid->StringGrid = StringGridRecords;
	grid->sizeGrid();
}
//---------------------------------------------------------------------------
void __fastcall TFListaUsuariosView::FormShow(TObject *Sender)
{
	//STYLE DO FORM
	Style::setTop(LabelCabecalhoTitulo, LabelCabecalhoSubTitulo, LabelCabecalhoModulo, "USUÁRIOS DO SISTEMA");

	this->loadView();
}
//---------------------------------------------------------------------------


void __fastcall TFListaUsuariosView::BtInsertClick(TObject *Sender)
{
	FUsuariosView->editar = 0;
	FUsuariosView->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFListaUsuariosView::EditBuscaKeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key == 13)
		gridRecords();
}
//---------------------------------------------------------------------------

