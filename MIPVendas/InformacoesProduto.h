//---------------------------------------------------------------------------

#ifndef InformacoesProdutoH
#define InformacoesProdutoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.Buttons.hpp>
#include <jpeg.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TFInformacoesProduto : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet4;
	TStringGrid *GridCategorias;
	TPanel *Panel3;
	TLabel *Label44;
	TEdit *EditCategoria;
	TPanel *Panel4;
	TLabel *Label49;
	TPanel *Panel1;
	TSQLQuery *SQLQuery1;
	TSpeedButton *SpeedButton1;
	TTabSheet *TabSheet1;
	TTabSheet *Marcas;
	TTabSheet *TabSheet2;
	TTabSheet *Imagem;
	TStringGrid *GridMarcas;
	TPanel *Panel6;
	TLabel *Label3;
	TEdit *EditMarca;
	TPanel *Panel7;
	TLabel *Label4;
	TStringGrid *GridSubcategorias;
	TPanel *Panel8;
	TLabel *Label5;
	TEdit *EditSubcategoria;
	TPanel *Panel9;
	TLabel *Label6;
	TStringGrid *GridUnidades;
	TPanel *Panel10;
	TLabel *Label7;
	TEdit *EditUnidade;
	TPanel *Panel11;
	TLabel *Label8;
	TLabel *Label1;
	TComboBox *ComboCategoria;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TImage *ImageProduto;
	TPanel *Panel2;
	TSpeedButton *SpeedButton6;
	TEdit *EditImagem;
	TLabel *Label9;
	TOpenDialog *OpenDialog1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall sairClick(TObject *Sender);
	void __fastcall GridCategoriasDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall GridSubcategoriasDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall GridMarcasDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall GridUnidadesDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall GridCategoriasSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall GridSubcategoriasSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall GridMarcasSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall GridUnidadesSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall GridCategoriasKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall GridSubcategoriasKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall GridMarcasKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall GridUnidadesKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
private:
	typedef struct
	{
		int id;
		char *desc;
	}IdDesc;

	typedef struct _ListaCategorias
	{
		int id;
		int funcao;//0 - nada a fazer 1 - adiconar 2 - remover
		char *descricao;
		_ListaCategorias *proximo;
	}ListaCategorias;
	ListaCategorias *ListaCategoriasNo;
	ListaCategorias *ListaCategoriasMovel;

	typedef struct _ListaSubcategorias
	{
		int id;
		int id_categoria;
		int funcao;//0 - nada a fazer 1 - adiconar 2 - remover
		char *categoria;
		char *descricao;
		_ListaSubcategorias *proximo;
	}ListaSubcategorias;
	ListaSubcategorias *ListaSubcategoriasNo;
	ListaSubcategorias *ListaSubcategoriasMovel;

	typedef struct _ListaMarcas
	{
		int id;
		int funcao;//0 - nada a fazer 1 - adiconar 2 - remover
		char *descricao;
		_ListaMarcas *proximo;
	}ListaMarcas;
	ListaMarcas *ListaMarcasNo;
	ListaMarcas *ListaMarcasMovel;

	typedef struct _ListaUnidades
	{
		int id;
		int funcao;//0 - nada a fazer 1 - adiconar 2 - remover
		char *descricao;
		_ListaUnidades *proximo;
	}ListaUnidades;
	ListaUnidades *ListaUnidadesNo;
	ListaUnidades *ListaUnidadesMovel;

	void AdicionarListaCategorias(ListaCategorias *Proximo);
	void RemoverListaCategorias(int n);

	void AdicionarListaSubcategorias(ListaSubcategorias *Proximo);
	void RemoverListaSubcategorias(int n);

	void AdicionarListaMarcas(ListaMarcas *Proximo);
	void RemoverListaMarcas(int n);

	void AdicionarListaUnidades(ListaUnidades *Proximo);
	void RemoverListaUnidades(int n);

	void AdicionarListaCategoriasBD();
	void RemoverListaCategoriassBD();

	void AdicionarListaSubcateogriassBD();
	void RemoverListaSubcateogriassBD();

	void AdicionarListaMarcassBD();
	void RemoverListaMarcassBD();

	void AdicionarListaUnidadessBD();
	void RemoverListaUnidadessBD();

	void GerarGridCategorias();
	void GerarGridSubcategorias();
	void GerarGridMarcas();
	void GerarGridUnidades();

	TJPEGImage *image;
	TBitmap *bt;
	int img_editada;
	int img_padrao;
	int rowselect;
	int NCategorias;

	void CarregarInformacoes();
	void InicializarCampos();
	void CarregarBoxCatergorias();
	void CarregarLogoPadrao();
	void Salvar();

	IdDesc *categorias;

public:		// User declarations
	__fastcall TFInformacoesProduto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFInformacoesProduto *FInformacoesProduto;
//---------------------------------------------------------------------------
#endif
