//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CategoriasView.h"
#include "Principal.h"
#include "SubcategoriasDAO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFCategoriasView *FCategoriasView;
//---------------------------------------------------------------------------
__fastcall TFCategoriasView::TFCategoriasView(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TFCategoriasView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
	ConfigurarForm(this);
	categoria = new Categorias();
	controller = new CategoriasController();
	helperSubcategorias = new GridHelper(this->StringGridSubcategorias);
    helperSubcategorias->checkBox = TRUE;
}
//---------------------------------------------------------------------------
void TFCategoriasView::DesignerBotoes()
{
	Adicionar->Top = 10;
	Adicionar->Left = 25;

	Modificar->Top = 10;
	Modificar->Left = 25;

	Deletar->Top = 10;
	Deletar->Left = 160;

	if(editar == 0)
	{
		Adicionar->Visible = TRUE;

		Modificar->Visible = FALSE;

		Deletar->Visible = FALSE;
	}
	else if(editar == 1)
	{
		Adicionar->Visible = FALSE;

		Modificar->Visible = TRUE;

		Deletar->Visible = TRUE;
	}
	else if(editar == 2)
	{
		Adicionar->Visible = FALSE;

		Modificar->Visible = FALSE;

		Deletar->Visible = FALSE;
	}
}
//---------------------------------------------------------------------------
void TFCategoriasView::loadCategoria()
{
	categoria = (Categorias*) controller->show(categoria->id)->Items[0];

	EditNome->Text = categoria->nome;

	gridSubcategorias();

	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFCategoriasView::loadCategoriaModel()
{
	categoria->nome = EditNome->Text;
}
//---------------------------------------------------------------------------
void TFCategoriasView::loadClearFields()
{
	gridSubcategorias();

	EditNome->Clear();

	setEditarSubcategoria(false);
	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFCategoriasView::loadView()
{
	DesignerBotoes();

	if(editar)
		loadCategoria();
	else
	{
		categoria = new Categorias();
		loadClearFields();
    }
}
void __fastcall TFCategoriasView::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------

void __fastcall TFCategoriasView::SairClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFCategoriasView::AdicionarClick(TObject *Sender)
{
	this->loadCategoriaModel();
	Result *result = controller->store(categoria);

	if(result->code == 201)
		Close();
}
//---------------------------------------------------------------------------

void __fastcall TFCategoriasView::DeletarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja remover?",L"Remover Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		Result *result = controller->destroy(categoria);

		if(result->code == 200)
			Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFCategoriasView::ModificarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		this->loadCategoriaModel();
		Result *result = controller->update(categoria);

		if(result->code == 202)
			Close();
	}
}
//---------------------------------------------------------------------------
void TFCategoriasView::gridSubcategorias()
{
	int numerodalinha,i;

	for(i=1;i<StringGridSubcategorias->RowCount;i++)
		StringGridSubcategorias->Rows[i]->Clear();

	numerodalinha = 1;
	//ESTRUTURA
	StringGridSubcategorias->Options << goRowSelect;
	StringGridSubcategorias->ScrollBars = ssVertical;
	StringGridSubcategorias->Rows[1]->Clear();
	StringGridSubcategorias->RowCount = 0;
	StringGridSubcategorias->ColCount = 2;
	StringGridSubcategorias->FixedCols = 0;
    StringGridSubcategorias->ColWidths[0] = 50;
	StringGridSubcategorias->ColWidths[1] = StringGridSubcategorias->Width - 50;
	StringGridSubcategorias->Cells[1][0] = "Nome";
	//ESTRUTURA

	if(categoria)
	{
		TList *subcategorias = categoria->subcategoria;

		for(int i=0;i<subcategorias->Count;i++)
		{
			Subcategorias *subcategoria = (Subcategorias*) subcategorias->Items[i];

			StringGridSubcategorias->Cells[1][numerodalinha] = subcategoria->nome;

			StringGridSubcategorias->RowCount++;

			numerodalinha++;

			if (numerodalinha == 2)
				StringGridSubcategorias->FixedRows = 1;
		}
		if (numerodalinha <= 1)
			StringGridSubcategorias->RowCount++;
	}
}

void __fastcall TFCategoriasView::StringGridSubcategoriasDrawCell(TObject *Sender,
          int ACol, int ARow, TRect &Rect, TGridDrawState State)
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
		Texto = StringGridSubcategorias->Cells[ACol][ARow];

		StringGridSubcategorias->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGridSubcategorias->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGridSubcategorias->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGridSubcategorias->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGridSubcategorias->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGridSubcategorias->Canvas->FillRect(Rect);
		StringGridSubcategorias->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGridSubcategorias->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

		/*--------------------COLOCAR CHECKBOX----------------------------*/
		if(helperSubcategorias)
			if(helperSubcategorias->checkBox)
			{
				if(ACol == 0)
				{
					if(helperSubcategorias->isChecked(ARow))
						DrawFrameControl(StringGridSubcategorias->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
					else
						DrawFrameControl(StringGridSubcategorias->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK);
				}
			}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCategoriasView::StringGridSubcategoriasMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if(helperSubcategorias)
		if(helperSubcategorias->checkBox)
		{
			if(colselectSubcategorias == 0)
				helperSubcategorias->selectRow(rowselectSubcategorias);

			if(helperSubcategorias->countChecked()>0)
			{
				setEditarSubcategoria(true);

				if(helperSubcategorias->countChecked()>1)
				{
                    this->EditSubcategoria->Text = "";
					ButtonEditarSubcategoria->Enabled = FALSE;
                }
			}
			else
				setEditarSubcategoria(false);

			StringGridSubcategorias->Repaint();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFCategoriasView::StringGridSubcategoriasSelectCell(TObject *Sender,
          int ACol, int ARow, bool &CanSelect)
{
	rowselectSubcategorias = ARow;
	colselectSubcategorias = ACol;
}
//---------------------------------------------------------------------------
void __fastcall TFCategoriasView::BtInsertClick(TObject *Sender)
{
	Subcategorias *subcategoria = new Subcategorias();

	subcategoria->id = 0;
	subcategoria->nome = EditSubcategoria->Text;
	categoria->subcategoria->Add((Subcategorias*) subcategoria);

	if(editar == 1)
	{
		Categorias *auxcategoria = new Categorias();
		auxcategoria->id = categoria->id;
		auxcategoria->subcategoria->Add((Subcategorias*) subcategoria);
		controller->storeRelation(auxcategoria);
        categoria->id = auxcategoria->id;
	}

	setEditarSubcategoria(false);
	gridSubcategorias();
}
void TFCategoriasView::setEditarSubcategoria(bool editar)
{
	editar_subcategoria = editar;

	if(editar)
	{
        ButtonEditarSubcategoria->Enabled = TRUE;
		ButtonDeletarSubcategoria->Enabled = TRUE;
		EditSubcategoria->Text = ((Subcategorias*)categoria->subcategoria->Items[rowselectSubcategorias - 1])->nome;

	}
	else
	{
		ButtonEditarSubcategoria->Enabled = FALSE;
		ButtonDeletarSubcategoria->Enabled = FALSE;
		EditSubcategoria->Clear();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCategoriasView::ButtonDeletarSubcategoriaClick(TObject *Sender)
{
	for(int i=StringGridSubcategorias->RowCount-1;i>0;i--)
		if(helperSubcategorias->isChecked(i))
		{
			if(editar == 1)
			{
				Categorias *auxcategoria = new Categorias();
				Subcategorias *subcategoria = (Subcategorias*) categoria->subcategoria->Items[i-1];
				auxcategoria->id = categoria->id;

				auxcategoria->subcategoria->Add((Subcategorias*) subcategoria);

				controller->destroyRelation(auxcategoria);
			}

			categoria->subcategoria->Delete(i-1);
		}

	helperSubcategorias->clearCheck();
	setEditarSubcategoria(false);
	gridSubcategorias();
}
//---------------------------------------------------------------------------





void __fastcall TFCategoriasView::ButtonEditarSubcategoriaClick(TObject *Sender)
{
	for(int i=StringGridSubcategorias->RowCount-1;i>0;i--)
		if(helperSubcategorias->isChecked(i))
		{
			Subcategorias *subcategoria = (Subcategorias*) categoria->subcategoria->Items[i-1];
            subcategoria->nome = this->EditSubcategoria->Text;

			if(editar == 1)
			{
				Categorias *auxcategoria = new Categorias();
				auxcategoria->id = categoria->id;

				auxcategoria->subcategoria->Add((Subcategorias*) subcategoria);

				controller->updateRelation(auxcategoria);
			}

		}

	helperSubcategorias->clearCheck();
	setEditarSubcategoria(false);
	gridSubcategorias();
}
//---------------------------------------------------------------------------

