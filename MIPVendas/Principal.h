//----------------------------------------------------------------------------
#ifndef PrincipalH
#define PrincipalH
//----------------------------------------------------------------------------
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <Winapi.Windows.hpp>
#include <System.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.ToolWin.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Data.DBXMySQL.hpp>
#include <Vcl.Imaging.pngimage.hpp>

#if defined(_WIN32) && !defined(_WIN64)
#pragma link "Data.Bind.ObjectScope.obj"
#endif

//----------------------------------------------------------------------------
class TFPrincipal : public TForm
{
__published:
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Caixa1;
	TMenuItem *N2;
	TMenuItem *Oramento1;
	TMenuItem *Venda1;
	TMenuItem *N3;
	TMenuItem *L1;
	TMenuItem *Sair1;
	TMenuItem *Visualizar1;
	TMenuItem *Produtos1;
	TMenuItem *Cleintes1;
	TMenuItem *Fornecedores1;
	TMenuItem *c1;
	TMenuItem *MinhasVendas1;
	TMenuItem *FinanceiroMenu;
	TMenuItem *ControledeCaixa1;
	TMenuItem *ContasaReceber1;
	TMenuItem *N5;
	TMenuItem *ComissoVendedores1;
	TMenuItem *jj2;
	TMenuItem *Sobre1;
	TTimer *LoginBox;
	TImage *background;
	TStatusBar *BarraStatus;
	TTimer *DateTime_Panel;
	TMenuItem *AdminMenu;
	TMenuItem *fsdfsd1;
	TMenuItem *Configurar2;
	TMenuItem *Dadosdocontribuiente1;
	TPanel *Panel2;
	TImage *orcamento;
	TImage *venda;
	TImage *sair;
	TImage *caixa;
	TImage *orcamentosH;
	TImage *clientes;
	TImage *forncedores;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label12;
	TImage *produtos;
	TImage *Image1;
	TLabel *Label13;
	TDateTimePicker *DateTimePicker1;
	TButton *Button1;
	TMenuItem *BuscaPedido1;
	TMenuItem *Auxiliares1;
	TMenuItem *Marcas1;
	TMenuItem *UnidadesdeMedida1;
	TMenuItem *ipodeContato1;
	TMenuItem *ipodeEndereo1;
	TMenuItem *Categorias1;
	TMenuItem *Lojas1;
	TMenuItem *N1;
	TMenuItem *N4;
	TMenuItem *Usurios1;
	TMenuItem *N6;
	TMenuItem *Estoque1;
	TMenuItem *Papeis1;
	TMenuItem *N7;
	TTimer *ThreadSistema;
	TMenuItem *GruposdeAssociados1;
	void __fastcall Sair1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall LoginBoxTimer(TObject *Sender);
	void __fastcall L1Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall DateTime_PanelTimer(TObject *Sender);
	void __fastcall sairClick(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall GerenciarUsuariosMenuClick(TObject *Sender);
	void __fastcall NovoCliente1Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Cleintes1Click(TObject *Sender);
	void __fastcall clientesClick(TObject *Sender);
	void __fastcall Clientes2Click(TObject *Sender);
	void __fastcall produtosClick(TObject *Sender);
	void __fastcall Produtos1Click(TObject *Sender);
	void __fastcall Produtos2Click(TObject *Sender);
	void __fastcall NovoProduto1Click(TObject *Sender);
	void __fastcall orcamentoClick(TObject *Sender);
	void __fastcall Oramento1Click(TObject *Sender);
	void __fastcall Venda1Click(TObject *Sender);
	void __fastcall caixaClick(TObject *Sender);
	void __fastcall Caixa1Click(TObject *Sender);
	void __fastcall vendaClick(TObject *Sender);
	void __fastcall ContasaReceber1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall LinkarAplicativos1Click(TObject *Sender);
	void __fastcall GraficodeVendas1Click(TObject *Sender);
	void __fastcall MinhasVendas1Click(TObject *Sender);
	void __fastcall fsdfsd1Click(TObject *Sender);
	void __fastcall Dadosdocontribuiente1Click(TObject *Sender);
	void __fastcall Configurar2Click(TObject *Sender);
	void __fastcall forncedoresClick(TObject *Sender);
	void __fastcall Usurios1Click(TObject *Sender);
	void __fastcall ThreadSistemaTimer(TObject *Sender);
	void __fastcall orcamentosHClick(TObject *Sender);
	void __fastcall Marcas1Click(TObject *Sender);
	void __fastcall UnidadesdeMedida1Click(TObject *Sender);
	void __fastcall Lojas1Click(TObject *Sender);
	void __fastcall GruposdeAssociados1Click(TObject *Sender);
	void __fastcall ipodeContato1Click(TObject *Sender);
	void __fastcall ipodeEndereo1Click(TObject *Sender);
	void __fastcall BuscaPedido1Click(TObject *Sender);
	void __fastcall Fornecedores1Click(TObject *Sender);
	void __fastcall Categorias1Click(TObject *Sender);
	void __fastcall Papeis1Click(TObject *Sender);
private:
	TPicture *image;
	TBitmap *bt;

	int VerificarAtualizacao();
	void ShowVenda();
public:
	UnicodeString BID;

	void ConectarBD(int bdid);
	void AtualizarPlanoFundo();
	void SetarPermissao();

	virtual __fastcall TFPrincipal(TComponent *AOwner);
};
//----------------------------------------------------------------------------
extern TFPrincipal *FPrincipal;
//----------------------------------------------------------------------------
#endif

//-----------------------VARIAVEIS GLOBAIS----------------------------------------------------------------
extern TSQLConnection *SQLCONNECT;
extern int USUARIO;
extern int PERMISSAO;
extern TFormatSettings *FormatoATUAL;
extern int CODIGO_CAIXA;
//-------------------PROTOTIPO FUNCÕES GLOBAIS----------------------------------------------------------------
extern void WcharToChar(char *dest,wchar_t *origem);
extern char *StrToChar(UnicodeString origem);
extern UnicodeString RevertOrd(UnicodeString data);
extern void ConfigurarForm(TForm *Form);
extern UnicodeString CharToStr(char *c);
extern float FStrToFloat(UnicodeString str);
extern int FStrToInt(UnicodeString str);
extern UnicodeString ApenasNumeros(UnicodeString str);
extern void CharLimite(char *str,int size);






