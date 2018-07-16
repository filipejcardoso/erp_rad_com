//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InformacoesProduto.h"
#include "Principal.h"
#include "ProdutosView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFInformacoesProduto *FInformacoesProduto;
//---------------------------------------------------------------------------
__fastcall TFInformacoesProduto::TFInformacoesProduto(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFInformacoesProduto::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
	ConfigurarForm(this);

	//PONTEIRO PARA IMAGEM
	image = new(TJPEGImage);
	bt = ImageProduto->Picture->Bitmap;

	SQLQuery1->SQLConnection = SQLCONNECT;
}
//---------------------------------------------------------------------------
void __fastcall TFInformacoesProduto::sairClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TFInformacoesProduto::GridCategoriasDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
UnicodeString Texto;
	if(ARow>0)
	{
		Texto = GridCategorias->Cells[ACol][ARow];

		GridCategorias->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			GridCategorias->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridCategorias->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridCategorias->Canvas->Brush->Color=TColor(0xc9a78b);
			GridCategorias->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridCategorias->Canvas->FillRect(Rect);
		GridCategorias->Canvas->Rectangle(Rect.Left-5,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridCategorias->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

	}
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::GridSubcategoriasDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
UnicodeString Texto;
	if(ARow>0)
	{
		Texto = GridSubcategorias->Cells[ACol][ARow];

		GridSubcategorias->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			GridSubcategorias->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridSubcategorias->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridSubcategorias->Canvas->Brush->Color=TColor(0xc9a78b);
			GridSubcategorias->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridSubcategorias->Canvas->FillRect(Rect);
		GridSubcategorias->Canvas->Rectangle(Rect.Left-5,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridSubcategorias->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

	}
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::GridMarcasDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
UnicodeString Texto;
	if(ARow>0)
	{
		Texto = GridMarcas->Cells[ACol][ARow];

		GridMarcas->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			GridMarcas->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridMarcas->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridMarcas->Canvas->Brush->Color=TColor(0xc9a78b);
			GridMarcas->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridMarcas->Canvas->FillRect(Rect);
		GridMarcas->Canvas->Rectangle(Rect.Left-5,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridMarcas->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

	}
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::GridUnidadesDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
UnicodeString Texto;
	if(ARow>0)
	{
		Texto = GridUnidades->Cells[ACol][ARow];

		GridUnidades->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			GridUnidades->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			GridUnidades->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			GridUnidades->Canvas->Brush->Color=TColor(0xc9a78b);
			GridUnidades->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		GridUnidades->Canvas->FillRect(Rect);
		GridUnidades->Canvas->Rectangle(Rect.Left-5,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		GridUnidades->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

	}
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::GridCategoriasSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselect = ARow;
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::GridSubcategoriasSelectCell(TObject *Sender,
          int ACol, int ARow, bool &CanSelect)
{
	rowselect = ARow;
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::GridMarcasSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselect = ARow;
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::GridUnidadesSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselect = ARow;
}
//---------------------------------------------------------------------------

void TFInformacoesProduto::AdicionarListaCategorias(ListaCategorias *Proximo)
{
	ListaCategorias *movel;

	if(!ListaCategoriasNo)
	{
		ListaCategoriasNo = (ListaCategorias*) malloc(sizeof(ListaCategorias));

		ListaCategoriasNo->id = Proximo->id;
		ListaCategoriasNo->funcao = Proximo->funcao;
		ListaCategoriasNo->descricao = Proximo->descricao;
		ListaCategoriasNo->proximo = NULL;
	}
	else
	{
		movel = ListaCategoriasNo;
		while(movel->proximo)
			movel = movel->proximo;

		movel->proximo = (ListaCategorias*) malloc(sizeof(ListaCategorias));

		movel->proximo->id = Proximo->id;
		movel->proximo->funcao = Proximo->funcao;
		movel->proximo->descricao = Proximo->descricao;
		movel->proximo->proximo = NULL;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::RemoverListaCategorias(int n)
{
	int i,c;
	if(ListaCategoriasNo)
		ListaCategoriasMovel = ListaCategoriasNo;
	c = GridCategorias->RowCount;

	i = 0;
	if(n>=0 && (n+2)<=c)
	{
		while(ListaCategoriasMovel)
		{
			while(ListaCategoriasMovel->funcao == 2)
				ListaCategoriasMovel = ListaCategoriasMovel->proximo;

			if(i>=n)
				break;

			i++;
			ListaCategoriasMovel = ListaCategoriasMovel->proximo;
		}

		if(ListaCategoriasMovel)
			ListaCategoriasMovel->funcao = 2;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::AdicionarListaSubcategorias(ListaSubcategorias *Proximo)
{
	ListaSubcategorias *movel;

	if(!ListaSubcategoriasNo)
	{
		ListaSubcategoriasNo = (ListaSubcategorias*) malloc(sizeof(ListaSubcategorias));

		ListaSubcategoriasNo->id = Proximo->id;
		ListaSubcategoriasNo->id_categoria = Proximo->id_categoria ;
		ListaSubcategoriasNo->funcao = Proximo->funcao;
		ListaSubcategoriasNo->categoria = Proximo->categoria;
		ListaSubcategoriasNo->descricao = Proximo->descricao;
		ListaSubcategoriasNo->proximo = NULL;
	}
	else
	{
		movel = ListaSubcategoriasNo;
		while(movel->proximo)
			movel = movel->proximo;

		movel->proximo = (ListaSubcategorias*) malloc(sizeof(ListaSubcategorias));

		movel->proximo->id = Proximo->id;
		movel->proximo->id_categoria = Proximo->id_categoria;
		movel->proximo->funcao = Proximo->funcao;
		movel->proximo->categoria = Proximo->categoria;
		movel->proximo->descricao = Proximo->descricao;
		movel->proximo->proximo = NULL;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::RemoverListaSubcategorias(int n)
{
	int i,c;
	if(ListaSubcategoriasNo)
		ListaSubcategoriasMovel = ListaSubcategoriasNo;
	c = GridSubcategorias->RowCount;

	i = 0;
	if(n>=0 && (n+2)<=c)
	{
		while(ListaSubcategoriasMovel)
		{
			while(ListaSubcategoriasMovel->funcao == 2)
				ListaSubcategoriasMovel = ListaSubcategoriasMovel->proximo;

			if(i>=n)
				break;

			i++;
			ListaSubcategoriasMovel = ListaSubcategoriasMovel->proximo;
		}

		if(ListaSubcategoriasMovel)
			ListaSubcategoriasMovel->funcao = 2;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::AdicionarListaMarcas(ListaMarcas *Proximo)
{
	ListaMarcas *movel;

	if(!ListaMarcasNo)
	{
		ListaMarcasNo = (ListaMarcas*) malloc(sizeof(ListaMarcas));

		ListaMarcasNo->id = Proximo->id;
		ListaMarcasNo->funcao = Proximo->funcao;
		ListaMarcasNo->descricao = Proximo->descricao;
		ListaMarcasNo->proximo = NULL;
	}
	else
	{
		movel = ListaMarcasNo;
		while(movel->proximo)
			movel = movel->proximo;

		movel->proximo = (ListaMarcas*) malloc(sizeof(ListaMarcas));

		movel->proximo->id = Proximo->id;
		movel->proximo->funcao = Proximo->funcao;
		movel->proximo->descricao = Proximo->descricao;
		movel->proximo->proximo = NULL;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::RemoverListaMarcas(int n)
{
	int i,c;
	if(ListaMarcasNo)
		ListaMarcasMovel = ListaMarcasNo;
	c = GridMarcas->RowCount;

	i = 0;
	if(n>=0 && (n+2)<=c)
	{
		while(ListaMarcasMovel)
		{
			while(ListaMarcasMovel->funcao == 2)
				ListaMarcasMovel = ListaMarcasMovel->proximo;

			if(i>=n)
				break;

			i++;
			ListaMarcasMovel = ListaMarcasMovel->proximo;
		}

		if(ListaMarcasMovel)
			ListaMarcasMovel->funcao = 2;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::AdicionarListaUnidades(ListaUnidades *Proximo)
{
	ListaUnidades *movel;

	if(!ListaUnidadesNo)
	{
		ListaUnidadesNo = (ListaUnidades*) malloc(sizeof(ListaUnidades));

		ListaUnidadesNo->id = Proximo->id;
		ListaUnidadesNo->funcao = Proximo->funcao;
		ListaUnidadesNo->descricao = Proximo->descricao;
		ListaUnidadesNo->proximo = NULL;
	}
	else
	{
		movel = ListaUnidadesNo;
		while(movel->proximo)
			movel = movel->proximo;

		movel->proximo = (ListaUnidades*) malloc(sizeof(ListaUnidades));

		movel->proximo->id = Proximo->id;
		movel->proximo->funcao = Proximo->funcao;
		movel->proximo->descricao = Proximo->descricao;
		movel->proximo->proximo = NULL;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::RemoverListaUnidades(int n)
{
	int i,c;
	if(ListaUnidadesNo)
		ListaUnidadesMovel = ListaUnidadesNo;
	c = GridUnidades->RowCount;

	i = 0;
	if(n>=0 && (n+2)<=c)
	{
		while(ListaUnidadesMovel)
		{
			while(ListaUnidadesMovel->funcao == 2)
				ListaUnidadesMovel = ListaUnidadesMovel->proximo;

			if(i>=n)
				break;

			i++;
			ListaUnidadesMovel = ListaUnidadesMovel->proximo;
		}

		if(ListaUnidadesMovel)
			ListaUnidadesMovel->funcao = 2;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::AdicionarListaCategoriasBD()
{
	UnicodeString QUERY;

	if(ListaCategoriasNo)
	{
		ListaCategoriasMovel = ListaCategoriasNo;

		while(ListaCategoriasMovel)
		{
			if(ListaCategoriasMovel->funcao == 1)
			{
				QUERY = "INSERT INTO produtos_categorias (descricao)";
				QUERY += " VALUES ('";
				QUERY += CharToStr(ListaCategoriasMovel->descricao)+"')";

				SQLQuery1->SQL->Clear();
				SQLQuery1->SQL->Add(QUERY);
				SQLQuery1->ExecSQL();
			}
			ListaCategoriasMovel = ListaCategoriasMovel->proximo;
		}
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::RemoverListaCategoriassBD()
{
	if(ListaCategoriasNo)
	{
		ListaCategoriasMovel = ListaCategoriasNo;

		while(ListaCategoriasMovel)
		{
			if(ListaCategoriasMovel->funcao == 2)
			{
				SQLQuery1->SQL->Clear();
				SQLQuery1->SQL->Add("DELETE FROM produtos_categorias WHERE id='" + IntToStr(ListaCategoriasMovel->id) + "'");
				SQLQuery1->ExecSQL();
			}
			ListaCategoriasMovel = ListaCategoriasMovel->proximo;
		}
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::AdicionarListaSubcateogriassBD()
{
	UnicodeString QUERY;

	if(ListaSubcategoriasNo)
	{
		ListaSubcategoriasMovel = ListaSubcategoriasNo;

		while(ListaSubcategoriasMovel)
		{
			if(ListaSubcategoriasMovel->funcao == 1)
			{
				QUERY = "INSERT INTO produtos_subcategorias (categoria,descricao)";
				QUERY += " VALUES ('";
				QUERY += IntToStr(ListaSubcategoriasMovel->id_categoria)+"','";
				QUERY += CharToStr(ListaSubcategoriasMovel->descricao)+"')";

				SQLQuery1->SQL->Clear();
				SQLQuery1->SQL->Add(QUERY);
				SQLQuery1->ExecSQL();
			}
			ListaSubcategoriasMovel = ListaSubcategoriasMovel->proximo;
		}
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::RemoverListaSubcateogriassBD()
{
	if(ListaSubcategoriasNo)
	{
		ListaSubcategoriasMovel = ListaSubcategoriasNo;

		while(ListaSubcategoriasMovel)
		{
			if(ListaSubcategoriasMovel->funcao == 2)
			{
				SQLQuery1->SQL->Clear();
				SQLQuery1->SQL->Add("DELETE FROM produtos_subcategorias WHERE id='" + IntToStr(ListaSubcategoriasMovel->id) + "'");
				SQLQuery1->ExecSQL();
			}
			ListaSubcategoriasMovel = ListaSubcategoriasMovel->proximo;
		}
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::AdicionarListaMarcassBD()
{
	UnicodeString QUERY;

	if(ListaMarcasNo)
	{
		ListaMarcasMovel = ListaMarcasNo;

		while(ListaMarcasMovel)
		{
			if(ListaMarcasMovel->funcao == 1)
			{
				QUERY = "INSERT INTO produtos_marcas (descricao)";
				QUERY += " VALUES ('";
				QUERY += CharToStr(ListaMarcasMovel->descricao)+"')";

				SQLQuery1->SQL->Clear();
				SQLQuery1->SQL->Add(QUERY);
				SQLQuery1->ExecSQL();
			}
			ListaMarcasMovel = ListaMarcasMovel->proximo;
		}
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::RemoverListaMarcassBD()
{
	if(ListaMarcasNo)
	{
		ListaMarcasMovel = ListaMarcasNo;

		while(ListaMarcasMovel)
		{
			if(ListaMarcasMovel->funcao == 2)
			{
				SQLQuery1->SQL->Clear();
				SQLQuery1->SQL->Add("DELETE FROM produtos_marcas WHERE id='" + IntToStr(ListaMarcasMovel->id) + "'");
				SQLQuery1->ExecSQL();
			}
			ListaMarcasMovel = ListaMarcasMovel->proximo;
		}
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::AdicionarListaUnidadessBD()
{
	UnicodeString QUERY;

	if(ListaUnidadesNo)
	{
		ListaUnidadesMovel = ListaUnidadesNo;

		while(ListaUnidadesMovel)
		{
			if(ListaUnidadesMovel->funcao == 1)
			{
				QUERY = "INSERT INTO produtos_unidades_medida (descricao)";
				QUERY += " VALUES ('";
				QUERY += CharToStr(ListaUnidadesMovel->descricao)+"')";

				SQLQuery1->SQL->Clear();
				SQLQuery1->SQL->Add(QUERY);
				SQLQuery1->ExecSQL();
			}
			ListaUnidadesMovel = ListaUnidadesMovel->proximo;
		}
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::RemoverListaUnidadessBD()
{
	if(ListaUnidadesNo)
	{
		ListaUnidadesMovel = ListaUnidadesNo;

		while(ListaUnidadesMovel)
		{
			if(ListaUnidadesMovel->funcao == 2)
			{
				SQLQuery1->SQL->Clear();
				SQLQuery1->SQL->Add("DELETE FROM produtos_unidades_medida WHERE id='" + IntToStr(ListaUnidadesMovel->id) + "'");
				SQLQuery1->ExecSQL();
			}
			ListaUnidadesMovel = ListaUnidadesMovel->proximo;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFInformacoesProduto::FormShow(TObject *Sender)
{
	InicializarCampos();
	CarregarInformacoes();
	PageControl1->TabIndex = 0;
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::CarregarInformacoes()
{
	UnicodeString QUERY;

	/*----------------------CATEGORIAS----------------------------*/
	ListaCategoriasMovel = (ListaCategorias *) malloc(sizeof(ListaCategorias));
	QUERY = "SELECT id,descricao FROM produtos_categorias ORDER BY descricao ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		ListaCategoriasMovel->id = SQLQuery1->Fields->FieldByName("id")->AsInteger;
		ListaCategoriasMovel->funcao = 0;//nada a fazer
		ListaCategoriasMovel->descricao = StrToChar(SQLQuery1->Fields->FieldByName("descricao")->AsString);
		AdicionarListaCategorias(ListaCategoriasMovel);
		SQLQuery1->Next();
	}
	free(ListaCategoriasMovel);

	/*----------------------SUBCATEGORIAS----------------------------*/
	ListaSubcategoriasMovel = (ListaSubcategorias *) malloc(sizeof(ListaSubcategorias));
	QUERY = "SELECT SC.id AS id,SC.categoria AS _categoria,SC.descricao AS descricao,C.id AS id_c,C.descricao AS categoria FROM produtos_subcategorias AS SC INNER JOIN produtos_categorias AS C ON (C.id = SC.categoria) ORDER BY C.descricao ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		ListaSubcategoriasMovel->id = SQLQuery1->Fields->FieldByName("id")->AsInteger;
		ListaSubcategoriasMovel->id_categoria = SQLQuery1->Fields->FieldByName("_categoria")->AsInteger;
		ListaSubcategoriasMovel->funcao = 0;//nada a fazer
		ListaSubcategoriasMovel->categoria = StrToChar(SQLQuery1->Fields->FieldByName("categoria")->AsString);
		ListaSubcategoriasMovel->descricao = StrToChar(SQLQuery1->Fields->FieldByName("descricao")->AsString);
		AdicionarListaSubcategorias(ListaSubcategoriasMovel);
		SQLQuery1->Next();
	}
	free(ListaSubcategoriasMovel);

	/*----------------------MARCAS----------------------------*/
	ListaMarcasMovel = (ListaMarcas *) malloc(sizeof(ListaMarcas));
	QUERY = "SELECT id,descricao FROM produtos_marcas ORDER BY descricao ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		ListaMarcasMovel->id = SQLQuery1->Fields->FieldByName("id")->AsInteger;
		ListaMarcasMovel->funcao = 0;//nada a fazer
		ListaMarcasMovel->descricao = StrToChar(SQLQuery1->Fields->FieldByName("descricao")->AsString);
		AdicionarListaMarcas(ListaMarcasMovel);
		SQLQuery1->Next();
	}
	free(ListaMarcasMovel);

	/*----------------------UNIDADES DE MEDIDA----------------------------*/
	ListaUnidadesMovel = (ListaUnidades *) malloc(sizeof(ListaUnidades));
	QUERY = "SELECT id,descricao FROM produtos_unidades_medida ORDER BY descricao ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		ListaUnidadesMovel->id = SQLQuery1->Fields->FieldByName("id")->AsInteger;
		ListaUnidadesMovel->funcao = 0;//nada a fazer
		ListaUnidadesMovel->descricao = StrToChar(SQLQuery1->Fields->FieldByName("descricao")->AsString);
		AdicionarListaUnidades(ListaUnidadesMovel);
		SQLQuery1->Next();
	}
	free(ListaUnidadesMovel);
	CarregarBoxCatergorias();
	CarregarLogoPadrao();

	GerarGridCategorias();
	GerarGridSubcategorias();
	GerarGridMarcas();
	GerarGridUnidades();
}
void __fastcall TFInformacoesProduto::SpeedButton1Click(TObject *Sender)
{
	Salvar();
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::GerarGridCategorias()
{
	UnicodeString QUERY;
	int numerodalinha,i,c;

	c = GridCategorias->RowCount;
	for(i=1;i<c;i++)
		GridCategorias->Rows[i]->Clear();

	numerodalinha = 1;
	// ESTRUTURA GRID
	GridCategorias->Options << goRowSelect;
	GridCategorias->ScrollBars = ssVertical;
	GridCategorias->Rows[1]->Clear();
	GridCategorias->RowCount = 0;
	GridCategorias->ColCount = 1;
	GridCategorias->FixedCols = 0;
	GridCategorias->ColWidths[0] = (GridCategorias->Width);
	GridCategorias->Cols[0]->Add("CATEGORIA");
	// ESTRUTURA GRID

	if(ListaCategoriasNo)
	{
		ListaCategoriasMovel = ListaCategoriasNo;
		while(ListaCategoriasMovel)
		{
			if(ListaCategoriasMovel->funcao!=2)
			{
				GridCategorias->Cells[0][numerodalinha] = ListaCategoriasMovel->descricao;

				GridCategorias->RowCount++;
				numerodalinha++;
				if (numerodalinha == 2)
					GridCategorias->FixedRows = 1;
			}
			ListaCategoriasMovel = ListaCategoriasMovel->proximo;
		}
		if (numerodalinha <= 1)
			GridCategorias->RowCount++;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::GerarGridSubcategorias()
{
	UnicodeString QUERY;
	int numerodalinha,i,c;

	c = GridSubcategorias->RowCount;
	for(i=1;i<c;i++)
		GridSubcategorias->Rows[i]->Clear();

	numerodalinha = 1;
	// ESTRUTURA GRID
	GridSubcategorias->Options << goRowSelect;
	GridSubcategorias->ScrollBars = ssVertical;
	GridSubcategorias->Rows[1]->Clear();
	GridSubcategorias->RowCount = 0;
	GridSubcategorias->ColCount = 2;
	GridSubcategorias->FixedCols = 0;
	GridSubcategorias->ColWidths[0] = (GridSubcategorias->Width/2);
	GridSubcategorias->ColWidths[1] = (GridSubcategorias->Width/2);
	GridSubcategorias->Cols[0]->Add("CATEGORIA");
	GridSubcategorias->Cols[1]->Add("SUBCATEGORIA");
	// ESTRUTURA GRID

	if(ListaSubcategoriasNo)
	{
		ListaSubcategoriasMovel = ListaSubcategoriasNo;
		while(ListaSubcategoriasMovel)
		{
			if(ListaSubcategoriasMovel->funcao!=2)
			{
				GridSubcategorias->Cells[0][numerodalinha] = ListaSubcategoriasMovel->categoria;
				GridSubcategorias->Cells[1][numerodalinha] = ListaSubcategoriasMovel->descricao;

				GridSubcategorias->RowCount++;
				numerodalinha++;
				if (numerodalinha == 2)
					GridSubcategorias->FixedRows = 1;
			}
			ListaSubcategoriasMovel = ListaSubcategoriasMovel->proximo;
		}
		if (numerodalinha <= 1)
			GridSubcategorias->RowCount++;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::GerarGridMarcas()
{
	UnicodeString QUERY;
	int numerodalinha,i,c;

	c = GridMarcas->RowCount;
	for(i=1;i<c;i++)
		GridMarcas->Rows[i]->Clear();

	numerodalinha = 1;
	// ESTRUTURA GRID
	GridMarcas->Options << goRowSelect;
	GridMarcas->ScrollBars = ssVertical;
	GridMarcas->Rows[1]->Clear();
	GridMarcas->RowCount = 0;
	GridMarcas->ColCount = 1;
	GridMarcas->FixedCols = 0;
	GridMarcas->ColWidths[0] = (GridMarcas->Width);
	GridMarcas->Cols[0]->Add("MARCA");
	// ESTRUTURA GRID

	if(ListaMarcasNo)
	{
		ListaMarcasMovel = ListaMarcasNo;
		while(ListaMarcasMovel)
		{
			if(ListaMarcasMovel->funcao!=2)
			{
				GridMarcas->Cells[0][numerodalinha] = ListaMarcasMovel->descricao;

				GridMarcas->RowCount++;
				numerodalinha++;
				if (numerodalinha == 2)
					GridMarcas->FixedRows = 1;
			}
			ListaMarcasMovel = ListaMarcasMovel->proximo;
		}
		if (numerodalinha <= 1)
			GridMarcas->RowCount++;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::GerarGridUnidades()
{
	UnicodeString QUERY;
	int numerodalinha,i,c;

	c = GridUnidades->RowCount;
	for(i=1;i<c;i++)
		GridUnidades->Rows[i]->Clear();

	numerodalinha = 1;
	// ESTRUTURA GRID
	GridUnidades->Options << goRowSelect;
	GridUnidades->ScrollBars = ssVertical;
	GridUnidades->Rows[1]->Clear();
	GridUnidades->RowCount = 0;
	GridUnidades->ColCount = 1;
	GridUnidades->FixedCols = 0;
	GridUnidades->ColWidths[0] = (GridUnidades->Width);
	GridUnidades->Cols[0]->Add("UNIDADE DE MEDIDA");
	// ESTRUTURA GRID

	if(ListaUnidadesNo)
	{
		ListaUnidadesMovel = ListaUnidadesNo;
		while(ListaUnidadesMovel)
		{
			if(ListaUnidadesMovel->funcao!=2)
			{
				GridUnidades->Cells[0][numerodalinha] = ListaUnidadesMovel->descricao;

				GridUnidades->RowCount++;
				numerodalinha++;
				if (numerodalinha == 2)
					GridUnidades->FixedRows = 1;
			}
			ListaUnidadesMovel = ListaUnidadesMovel->proximo;
		}
		if (numerodalinha <= 1)
			GridUnidades->RowCount++;
	}
}






void __fastcall TFInformacoesProduto::FormClose(TObject *Sender, TCloseAction &Action)
{
	int i;
	ListaCategorias *movel_categorias;
	ListaSubcategorias *movel_subcategorias;
	ListaMarcas *movel_marcas;
	ListaUnidades *movel_unidades;

	//LIBERAR MEMORIA
	if(ListaCategoriasNo)
	{
		ListaCategoriasMovel = ListaCategoriasNo;
		while(ListaCategoriasMovel->proximo)
		{
			movel_categorias = ListaCategoriasMovel;
			ListaCategoriasMovel = ListaCategoriasMovel->proximo;
			free(movel_categorias);
			movel_categorias = NULL;
		}

		if(ListaCategoriasNo)
		{
			free(ListaCategoriasNo);
			ListaCategoriasNo = NULL;
		}
	}

	if(ListaSubcategoriasNo)
	{
		ListaSubcategoriasMovel = ListaSubcategoriasNo;
		while(ListaSubcategoriasMovel->proximo)
		{
			movel_subcategorias = ListaSubcategoriasMovel;
			ListaSubcategoriasMovel = ListaSubcategoriasMovel->proximo;
			free(movel_subcategorias);
			movel_subcategorias = NULL;
		}

		if(ListaSubcategoriasNo)
		{
			free(ListaSubcategoriasNo);
			ListaSubcategoriasNo = NULL;
		}
	}

	if(ListaMarcasNo)
	{
		ListaMarcasMovel = ListaMarcasNo;
		while(ListaMarcasMovel->proximo)
		{
			movel_marcas = ListaMarcasMovel;
			ListaMarcasMovel = ListaMarcasMovel->proximo;
			free(movel_marcas);
			movel_marcas = NULL;
		}

		if(ListaMarcasNo)
		{
			free(ListaMarcasNo);
			ListaMarcasNo = NULL;
		}
	}

	if(ListaUnidadesNo)
	{
		ListaUnidadesMovel = ListaUnidadesNo;
		while(ListaUnidadesMovel->proximo)
		{
			movel_unidades = ListaUnidadesMovel;
			ListaUnidadesMovel = ListaUnidadesMovel->proximo;
			free(movel_unidades);
			movel_unidades = NULL;
		}

		if(ListaUnidadesNo)
		{
			free(ListaUnidadesNo);
			ListaUnidadesNo = NULL;
		}
	}
	if(NCategorias)
	{
		for(i=0;i<NCategorias;i++)
			free(categorias[i].desc);
		free(categorias);
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::InicializarCampos()
{
	EditCategoria->Clear();
	EditSubcategoria->Clear();
	EditMarca->Clear();
	EditUnidade->Clear();
	EditImagem->Clear();
}

void __fastcall TFInformacoesProduto::GridCategoriasKeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key=='d' || Key == 'D')
		if(MessageBox(NULL,L"Tem certeza que deseja deletar?",L"Deletar Categorias",MB_YESNO | MB_ICONEXCLAMATION) == 6)
			RemoverListaCategorias(rowselect-1);

	GerarGridCategorias();
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::GridSubcategoriasKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key=='d' || Key == 'D')
		if(MessageBox(NULL,L"Tem certeza que deseja deletar?",L"Deletar Subcategorias",MB_YESNO | MB_ICONEXCLAMATION) == 6)
			RemoverListaSubcategorias(rowselect-1);

	GerarGridSubcategorias();
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::GridMarcasKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key=='d' || Key == 'D')
		if(MessageBox(NULL,L"Tem certeza que deseja deletar?",L"Deletar Marcas",MB_YESNO | MB_ICONEXCLAMATION) == 6)
			RemoverListaMarcas(rowselect-1);

	GerarGridMarcas();
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::GridUnidadesKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key=='d' || Key == 'D')
		if(MessageBox(NULL,L"Tem certeza que deseja deletar?",L"Deletar Unidades",MB_YESNO | MB_ICONEXCLAMATION) == 6)
			RemoverListaUnidades(rowselect-1);

	GerarGridUnidades();
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::CarregarBoxCatergorias()
{
	UnicodeString QUERY;
	int i;

	/*---------------------Get Numero de Fornecedores------------------------*/
	QUERY = "SELECT COUNT(id) AS numero_registros FROM produtos_categorias ORDER BY id ASC";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	NCategorias = SQLQuery1->Fields->FieldByName("numero_registros")->AsInteger;

	if(NCategorias)
	{
		categorias = (IdDesc *) malloc(NCategorias*sizeof(IdDesc));

		QUERY = "SELECT id,descricao FROM produtos_categorias ORDER BY descricao ASC";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->Open();
		SQLQuery1->First();

		i = 0;
		while(SQLQuery1->Fields->FieldByName("id")->AsInteger && i<NCategorias)
		{
			categorias[i].id = SQLQuery1->Fields->FieldByName("id")->AsInteger;
			categorias[i].desc = StrToChar(SQLQuery1->Fields->FieldByName("descricao")->AsString);
			ComboCategoria->Items->Add(categorias[i].desc);
			i++;
			SQLQuery1->Next();
		}
		ComboCategoria->ItemIndex = 0;
	}
}

void __fastcall TFInformacoesProduto::SpeedButton2Click(TObject *Sender)
{
	ListaSubcategoriasMovel = (ListaSubcategorias *) malloc(sizeof(ListaSubcategorias));

    ListaSubcategoriasMovel->id = 0;
    ListaSubcategoriasMovel->id_categoria = categorias[ComboCategoria->ItemIndex].id;
    ListaSubcategoriasMovel->funcao = 1;
	ListaSubcategoriasMovel->descricao = StrToChar(EditSubcategoria->Text);
	ListaSubcategoriasMovel->categoria = StrToChar(ComboCategoria->Text);

	AdicionarListaSubcategorias(ListaSubcategoriasMovel);

	free(ListaSubcategoriasMovel);
	GerarGridSubcategorias();
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::SpeedButton3Click(TObject *Sender)
{
	ListaCategoriasMovel = (ListaCategorias *) malloc(sizeof(ListaCategorias));

    ListaCategoriasMovel->id = 0;
    ListaCategoriasMovel->funcao = 1;
	ListaCategoriasMovel->descricao = StrToChar(EditCategoria->Text);

	AdicionarListaCategorias(ListaCategoriasMovel);

	free(ListaCategoriasMovel);
	GerarGridCategorias();
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::SpeedButton4Click(TObject *Sender)
{
	ListaMarcasMovel = (ListaMarcas *) malloc(sizeof(ListaMarcas));

    ListaMarcasMovel->id = 0;
    ListaMarcasMovel->funcao = 1;
	ListaMarcasMovel->descricao = StrToChar(EditMarca->Text);

	AdicionarListaMarcas(ListaMarcasMovel);

	free(ListaMarcasMovel);
	GerarGridMarcas();
}
//---------------------------------------------------------------------------

void __fastcall TFInformacoesProduto::SpeedButton5Click(TObject *Sender)
{
	ListaUnidadesMovel = (ListaUnidades *) malloc(sizeof(ListaUnidades));

    ListaUnidadesMovel->id = 0;
    ListaUnidadesMovel->funcao = 1;
	ListaUnidadesMovel->descricao = StrToChar(EditUnidade->Text);

	AdicionarListaUnidades(ListaUnidadesMovel);

	free(ListaUnidadesMovel);
	GerarGridUnidades();
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::Salvar()
{
	TIniFile *config=NULL;
	UnicodeString QUERY;
	UnicodeString ImgServer,ImgLoad;

	config=new TIniFile(GetCurrentDir()+"\\config.ini");


	ImgServer = config->ReadString("BD"+FPrincipal->BID,"ImageLoad","");
	ImgServer = ImgServer +"\\padrao.jpg";

	ImgLoad = StringReplace(ImgServer,"\\","/",TReplaceFlags() << rfReplaceAll);

	if(img_editada)
	{
		CopyFile(EditImagem->Text.c_str(),ImgServer.c_str(),FALSE);   //COPIA NO CAMINHO DE IMAGENS DO SERVIDOR

		QUERY = "UPDATE produtos_imagens SET foto=LOAD_FILE('"+ImgLoad+"') WHERE padrao='1' ORDER BY id ASC";

		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->ExecSQL();
	}

	AdicionarListaCategoriasBD();
	RemoverListaCategoriassBD();

	AdicionarListaSubcateogriassBD();
	RemoverListaSubcateogriassBD();

	AdicionarListaMarcassBD();
	RemoverListaMarcassBD();

	AdicionarListaUnidadessBD();
	RemoverListaUnidadessBD();

	MessageBox(NULL,L"Informações salvas com sucesso!",L"Salvar Informações",MB_OK | MB_ICONINFORMATION);
	Close();
}
void __fastcall TFInformacoesProduto::SpeedButton6Click(TObject *Sender)
{
	if(OpenDialog1->Execute() && OpenDialog1->FileName.Trim()!="")
	{
		img_editada = 1;

		image->LoadFromFile(OpenDialog1->FileName);
		bt = ImageProduto->Picture->Bitmap;

		bt->SetSize(ImageProduto->Width,ImageProduto->Height);
		bt->Canvas->StretchDraw(Rect(0,0,ImageProduto->Width,ImageProduto->Height),image);

		EditImagem->Text=OpenDialog1->FileName;
	}
}
//---------------------------------------------------------------------------
void TFInformacoesProduto::CarregarLogoPadrao()
{
	UnicodeString QUERY;
	TStream *Stream;

	QUERY = "SELECT id,padrao,foto FROM produtos_imagens WHERE padrao = '1' ORDER BY id ASC LIMIT 0,1";

	img_editada = 0;
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		img_padrao = SQLQuery1->Fields->FieldByName("id")->AsInteger;
		Stream = SQLQuery1->CreateBlobStream(SQLQuery1->FieldByName("foto"),bmRead);
		image->LoadFromStream(Stream);
		bt = ImageProduto->Picture->Bitmap;

		bt->SetSize(ImageProduto->Width,ImageProduto->Height);
		bt->Canvas->StretchDraw(Rect(0,0,ImageProduto->Width,ImageProduto->Height),image);
	}
}

