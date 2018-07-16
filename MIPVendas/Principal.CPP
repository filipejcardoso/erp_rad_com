//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Principal.h"
#include "LoginBox.h"
#include "GerenciarUsuarios.h"
#include "ListaClientesView.h"
#include "ClientesView.h"
#include "ProdutosView.h"
#include "ListaProdutosView.h"
#include "PedidosView.h"
#include "PapeisView.h"
#include "Vendas.h"
#include "Caixa.h"
#include "ContasReceber.h"
#include "LinkarAplicativos.h"
#include "GraficoVendas.h"
#include "ContasFinalizadas.h"
#include "ProdutosController.h"
#include "ClientesController.h"
#include "FornecedoresController.h"
#include "EmpresasController.h"
#include "ConfiguracoesController.h"
#include "PedidosController.h"
#include "UsuariosController.h"
#include "MarcasController.h"
#include "UnidadesMedidasController.h"
#include "LojasController.h"
#include "GruposAssociadosController.h"
#include "TiposContatosController.h"
#include "TiposEnderecosController.h"
#include "CategoriasController.h"
#include "Sistema.h"

#include "Importar.h"

#define VERSAO "1.0.3.1"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TFPrincipal *FPrincipal;

//-----------------------VARIAVEIS GLOBAIS----------------------------------------------------------------
TSQLConnection *SQLCONNECT;
TFormatSettings *FormatoATUAL;
int USUARIO;
int PERMISSAO;
int CODIGO_CAIXA;
//-----------------------PROTOTIPO FUNCÕES GLOBAIS----------------------------------------------------------------
void WcharToChar(wchar_t *origem,char *dest);
char *StrToChar(UnicodeString origem);
UnicodeString RevertOrd(UnicodeString data);
void ConfigurarForm(TForm *Form);
UnicodeString CharToStr(char *c);
float FStrToFloat(UnicodeString str);
int FStrToInt(UnicodeString str);
UnicodeString ApenasNumeros(UnicodeString str);
void CharLimite(char *str,int size);
//-----------------------IMPLEMENTAÇÃO FUNCÕES GLOBAIS----------------------------------------------------------------
void WcharToChar(wchar_t *origem,char *dest)
{
	char *c;
	wchar_t *w;

	c = dest;
	w = origem;

	while(*w)
		*c++ = *w++;
	*c = 0;
}
//--------------------------------------------------
char *StrToChar(UnicodeString origem)
{
	far char *c;
	int size;

	size = origem.Length();
	c = (char*) malloc((size+1)*sizeof(char));
	WcharToChar(origem.c_str(),c);

	return c;
}
//--------------------------------------------------
UnicodeString CharToStr(char *c)
{
	UnicodeString str;

	str = c;

	return str;
}
//---------------------------------------------
float FStrToFloat(UnicodeString str)
{
	UnicodeString str_r;
	int fa,n,decimal,sinal;
	char *normal,*_normal;
	char *cortado,*_cortado;
	char fs;
	float r;

	fa = FormatoATUAL->DecimalSeparator;
	normal = StrToChar(str);
	_normal = normal;
	fs = '-';

	n = 0;
	decimal = 0;
	sinal = 0;
	while(*normal)
	{
		if((*normal>=0x30 && *normal<=0x39) || (*normal == fa && decimal == 0) || (*normal == fs && sinal == 0))
			n++;
		if(*normal == fa)
			decimal++;
		if(sinal == 0)
			sinal++;
		normal++;
	}


	cortado = (char*) malloc((n+1)*sizeof(char));
	_cortado = cortado;
	normal = _normal;

	decimal = 0;
	sinal = 0;
	while(*normal)
	{
		if((*normal>=0x30 && *normal<=0x39) || (*normal == fa && decimal == 0) || (*normal == fs && sinal == 0))
			*cortado++ = *normal;
		if(*normal == fa)
			decimal++;
		if(sinal == 0)
			sinal++;
		normal++;
	}
	*cortado = 0;

	cortado = _cortado;
	normal = _normal;

	str_r = cortado;
	if(str_r != "")
		r = StrToFloat(str_r);
	else
		r = 0;

	free(cortado);
	free(normal);

	return r;
}
//---------------------------------------------
int FStrToInt(UnicodeString str)
{
	UnicodeString str_r;
	int fa,n,sinal;
	char *normal,*_normal;
	char *cortado,*_cortado;
	char fs;
	int r;

	fa = FormatoATUAL->DecimalSeparator;
	normal = StrToChar(str);
	_normal = normal;
	fs = '-';

	n = 0;
	sinal = 0;
	while(*normal)
	{
		if((*normal>=0x30 && *normal<=0x39) || (*normal == fs && sinal == 0))
			n++;
		if(sinal == 0)
			sinal++;
		if(*normal == fa)
			break;
		normal++;
	}


	cortado = (char*) malloc((n+1)*sizeof(char));
	_cortado = cortado;
	normal = _normal;

	sinal = 0;
	while(*normal)
	{
		if((*normal>=0x30 && *normal<=0x39) || (*normal == fs && sinal == 0))
			*cortado++ = *normal;
		if(sinal == 0)
			sinal++;
		if(*normal == fa)
			break;
		normal++;
	}
	*cortado = 0;

	cortado = _cortado;
	normal = _normal;

	str_r = cortado;
	if(str_r != "")
		r = StrToInt(str_r);
	else
		r = 0;

	free(cortado);
	free(normal);

	return r;
}
//---------------------------------------------
UnicodeString ApenasNumeros(UnicodeString str)
{
	UnicodeString str_r;
	int fa,n,decimal;
	char *normal,*_normal;
	char *cortado,*_cortado;

	fa = FormatoATUAL->DecimalSeparator;
	normal = StrToChar(str);
	_normal = normal;

	n = 0;
	decimal = 0;
	while(*normal)
	{
		if((*normal>=0x30 && *normal<=0x39) || *normal == fa && decimal == 0)
			n++;
		if(*normal == fa)
			decimal++;
		normal++;
	}


	cortado = (char*) malloc((n+1)*sizeof(char));
	_cortado = cortado;
	normal = _normal;

 	decimal = 0;
	while(*normal)
	{
		if((*normal>=0x30 && *normal<=0x39) || *normal == fa && decimal == 0)
			*cortado++ = *normal;
		if(*normal == fa)
			decimal++;
		normal++;
	}
	*cortado = 0;

	cortado = _cortado;
	normal = _normal;

	str_r = cortado;

	free(cortado);
	free(normal);

	return str_r;
}
//---------------------------------------------
UnicodeString RevertOrd(UnicodeString data)
{
UnicodeString r;
char strS[11],strE[11];
WcharToChar(data.c_str(),strE);

	//ANO
	strS[0] = strE[6];
	strS[1] = strE[7];
	strS[2] = strE[8];
	strS[3] = strE[9];
	strS[4] = '-';

	//MES
	strS[5] = strE[3];
	strS[6] = strE[4];
	strS[7] = '-';

	//DIA
	strS[8] = strE[0];
	strS[9] = strE[1];

	//FECHA STRING
	strS[10]=0;

r=strS;
return r;
}
//-----------------------------------------------------
void CharLimite(char *str,int size)
{
	char *modif;
	int i;

	modif = str;
	for(i=0;*modif;i++)
	{
		if(i == size)
		{
			*modif = 0;
			break;
		}
		*modif++;
	}
}
//-----------------------------------------------------
void ConfigurarForm(TForm *Form)
{
	//FONTE
	Form->Font->Name = "Calibri";
	Form->Font->Height = 18;

	//POSIÇÃO DE EXIBIÇÃO
	Form->Position = poMainFormCenter;
}
//----------------------METODO CONSTRUTOR-----------------------------------------------
__fastcall TFPrincipal::TFPrincipal(TComponent *AOwner)
	: TForm(AOwner)
{
	SISTEMA = new Sistema();
	this->ThreadSistema->Enabled = TRUE;

	image = new (TPicture);

	SQLCONNECT = SQLConnection1;
	SQLQuery1->SQLConnection = SQLCONNECT;
}
//---------------------------------------------------------------------

void __fastcall TFPrincipal::Sair1Click(TObject *Sender)
{
	exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::FormCreate(TObject *Sender)
{
	//INICIALIZAR VARIAVEIS
    BID = "1";//numero do bd a conectar

	//ABRE O LOGINBOX
	LoginBox->Interval = 100;
	LoginBox->Enabled = TRUE;

	//CONFIGURAR O FORM
	ConfigurarForm(this);

	//AJUSATA SEPARADOR DE CASAS DECIMAIS
	FormatoATUAL = &System::Sysutils::FormatSettings;
	if(FormatoATUAL->DecimalSeparator==',')
		FormatoATUAL->ThousandSeparator = '.';
	else if(FormatoATUAL->DecimalSeparator=='.')
		FormatoATUAL->ThousandSeparator = ',';

}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::LoginBoxTimer(TObject *Sender)
{
	//CHAMA O LOGINBOX
	LoginBox->Enabled = FALSE;
	FLoginBox->Show();
}
//---------------------------------------------------------------------------
void TFPrincipal::ConectarBD(int bdid)
{
//DEFINIÇÃO DE VARIÁVEIS
TIniFile *config=NULL;
UnicodeString HOST,DATABASE,USER,SENHA,open;
int bi;

//INSTANCIA CONFIG TINIFILE
config=new TIniFile( GetCurrentDir()+"\\config.ini");

//NUMERO DO BANCO DE DADOS A CARREGAR;
bi = bdid; bi++; BID = IntToStr(bi);

//ATUALIZAR
open = GetCurrentDir()+"\\mipatualizacao.exe";

//CONFIGURA SQLCONNECT
SQLCONNECT->DriverName = "MySQL";

//BUSCA DADOS .INI
HOST=config->ReadString("BD"+IntToStr(bi),"HostName","");
DATABASE=config->ReadString("BD"+IntToStr(bi),"Database","");
USER=config->ReadString("BD"+IntToStr(bi),"User_Name","");
SENHA=config->ReadString("BD"+IntToStr(bi),"Password","");

//SETA PARÂMETROS SQLCONNECT
SQLCONNECT->Params->Values["HostName"]=HOST;
SQLCONNECT->Params->Values["Database"]=DATABASE;
SQLCONNECT->Params->Values["User_Name"]=USER;
SQLCONNECT->Params->Values["Password"]=SENHA;


if(SQLCONNECT->Connected==TRUE)
{
	SQLCONNECT->Close();
	SQLCONNECT->Connected=FALSE;
}

//CONECTA NO BANCO DE DADOS
	try
	{
		SQLCONNECT->Open();
	}
	catch (const Exception &)
	{
		MessageBox(NULL,L"Não foi possivel estabelecer conexão com o servidor",L"Erro de conexão",MB_OK | MB_ICONERROR);
	}

if(VerificarAtualizacao())
	if(MessageBox(NULL,L"Nova versão do programa disponível, deseja atualizar agora?",L"Atualização do Sistema",MB_YESNO | MB_ICONINFORMATION)==6)
	{
		ShellExecute(Handle,L"open",open.c_str(),GetCurrentDir().c_str(),NULL,SW_SHOW);
		exit(0);
	}
}
//-------------------------------------------------------------------
int TFPrincipal::VerificarAtualizacao()
{
UnicodeString v;
int r;
		//ANALISA CONTA CONTABIL
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add("SELECT id,versao FROM info_gerais ORDER BY id ASC LIMIT 0,1");
		SQLQuery1->Open();
		SQLQuery1->First();
		if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
			v = SQLQuery1->Fields->FieldByName("versao")->AsString;

		if(v.Trim()!=VERSAO)
			r = 1;
		else
			r = 0;
return r;
}

void __fastcall TFPrincipal::L1Click(TObject *Sender)
{
	FLoginBox->ShowModal();
}
//---------------------------------------------------------------------------
void TFPrincipal::AtualizarPlanoFundo()
{
	try
	{
		image->LoadFromFile(GetCurrentDir() + "\\images\\" + SISTEMA->api->background);
		bt = background->Picture->Bitmap;
		this->Resize();
	}
	catch(const &Excepetion){

    }
}

void __fastcall TFPrincipal::FormResize(TObject *Sender)
{
	//AJUSTA TAMNAHO BACKGROUND
	if(bt)
	{
		bt->SetSize(Width,Height);
		bt->Canvas->StretchDraw(Rect(0,0,background->Width,background->Height),image->Graphic);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::DateTime_PanelTimer(TObject *Sender)
{
	DateTime_Panel->Enabled = FALSE;
	TDateTime DataHora;
	BarraStatus->Panels->Items[2]->Text = DataHora.CurrentDateTime();
	DateTime_Panel->Enabled = TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::sairClick(TObject *Sender)
{
	exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Image1Click(TObject *Sender)
{
	FLoginBox->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::GerenciarUsuariosMenuClick(TObject *Sender)
{
	FGerenciarUsuarios->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::NovoCliente1Click(TObject *Sender)
{
	FClientesView->editar = 0;
	FClientesView->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Image3Click(TObject *Sender)
{
	FClientesView->editar = 0;
	FClientesView->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Cleintes1Click(TObject *Sender)
{
	ClientesController *clientesController = new ClientesController();
    clientesController->showCrudView(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::clientesClick(TObject *Sender)
{
	ClientesController *clientesController = new ClientesController();
    clientesController->showCrudView(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Clientes2Click(TObject *Sender)
{
	ClientesController *clientesController = new ClientesController();
	clientesController->showCrudView(0);
}
//---------------------------------------------------------------------------
void __fastcall TFPrincipal::produtosClick(TObject *Sender)
{
	ProdutosController *produtosController = new ProdutosController();
    produtosController->showCrudView(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Produtos1Click(TObject *Sender)
{
	ProdutosController *produtosController = new ProdutosController();
    produtosController->showCrudView(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Produtos2Click(TObject *Sender)
{
	ProdutosController *produtosController = new ProdutosController();
    produtosController->showCrudView(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::NovoProduto1Click(TObject *Sender)
{
	FProdutosView->editar = 0;
	FProdutosView->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::orcamentoClick(TObject *Sender)
{
	PedidosController *pedidosController = new PedidosController();
    pedidosController->showPedido(0);
}
//---------------------------------------------------------------------------


void __fastcall TFPrincipal::Oramento1Click(TObject *Sender)
{
	PedidosController *pedidosController = new PedidosController();
    pedidosController->showPedido(0);
}
//---------------------------------------------------------------------------
void __fastcall TFPrincipal::Venda1Click(TObject *Sender)
{
	ShowVenda();
}
//---------------------------------------------------------------------------


void __fastcall TFPrincipal::caixaClick(TObject *Sender)
{
	int mask,result;
	/*----------------------Vendas & Caixa PERMISSAO-----------------------*/
	mask = 0x01;
	result = PERMISSAO & mask;
	if(result)
		FCaixa->ShowModal();
	else
		MessageBox(NULL,L"Desculpe, você não tem permissão!",L"Permissão de acesso",MB_OK | MB_ICONERROR);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Caixa1Click(TObject *Sender)
{
	int mask,result;
	/*----------------------Vendas & Caixa PERMISSAO-----------------------*/
	mask = 0x01;
	result = PERMISSAO & mask;
	if(result)
		FCaixa->ShowModal();
	else
		MessageBox(NULL,L"Desculpe, você não tem permissão!",L"Permissão de acesso",MB_OK | MB_ICONERROR);
}
//---------------------------------------------------------------------------
void TFPrincipal::ShowVenda()
{
	FCaixa->ShowModal();
}
void __fastcall TFPrincipal::vendaClick(TObject *Sender)
{
	FVendas->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::ContasaReceber1Click(TObject *Sender)
{
	FContasReceber->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Button1Click(TObject *Sender)
{
	FImportar->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::LinkarAplicativos1Click(TObject *Sender)
{
	FLinkarAplicativos->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFPrincipal::GraficodeVendas1Click(TObject *Sender)
{
	FGraficoVendas->modo = 0;
	FGraficoVendas->ShowModal();
}
//---------------------------------------------------------------------------
void TFPrincipal::SetarPermissao()
{

}
void __fastcall TFPrincipal::MinhasVendas1Click(TObject *Sender)
{
	FGraficoVendas->modo = 1;
	FGraficoVendas->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::fsdfsd1Click(TObject *Sender)
{
	FContasFinalizadas->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFPrincipal::Dadosdocontribuiente1Click(TObject *Sender)
{
	EmpresasController *empresasController = new EmpresasController();
	empresasController->showForm();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Configurar2Click(TObject *Sender)
{
	ConfiguracoesController *configuracoesController = new ConfiguracoesController();
	configuracoesController->showForm();
}
//---------------------------------------------------------------------------
void __fastcall TFPrincipal::forncedoresClick(TObject *Sender)
{
	FornecedoresController *fornecedoresController = new FornecedoresController();
	fornecedoresController->showCrudView(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Usurios1Click(TObject *Sender)
{
	UsuariosController *usuarios = new UsuariosController();
	usuarios->showCrudView();
}
void __fastcall TFPrincipal::ThreadSistemaTimer(TObject *Sender)
{
	this->ThreadSistema->Enabled = FALSE;

    SISTEMA->empresa = new Empresas(true);
    SISTEMA->configuracao = new Configuracoes(true);
}
//---------------------------------------------------------------------------


void __fastcall TFPrincipal::orcamentosHClick(TObject *Sender)
{
	PedidosController *pedidosController = new PedidosController();
    pedidosController->showListPedidos();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Marcas1Click(TObject *Sender)
{
	MarcasController *marcasController = new MarcasController();
    marcasController->showCrudView(0);
}
//---------------------------------------------------------------------------


void __fastcall TFPrincipal::UnidadesdeMedida1Click(TObject *Sender)
{
	UnidadesMedidasController *unidades_medidasController = new UnidadesMedidasController();
    unidades_medidasController->showCrudView(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Lojas1Click(TObject *Sender)
{
	LojasController *lojasController = new LojasController();
	lojasController->showCrudView(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::GruposdeAssociados1Click(TObject *Sender)
{
	GruposAssociadosController *grupos_associadosController = new GruposAssociadosController();
	grupos_associadosController->showCrudView(0);
}
//---------------------------------------------------------------------------


void __fastcall TFPrincipal::ipodeContato1Click(TObject *Sender)
{
	TiposContatosController *tipos_contatosController = new TiposContatosController();
	tipos_contatosController->showCrudView(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::ipodeEndereo1Click(TObject *Sender)
{
	TiposEnderecosController *tipos_enderecosController = new TiposEnderecosController();
	tipos_enderecosController->showCrudView(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::BuscaPedido1Click(TObject *Sender)
{
	PedidosController *pedidosController = new PedidosController();
    pedidosController->showListPedidos();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Fornecedores1Click(TObject *Sender)
{
	FornecedoresController *fornecedoresController = new FornecedoresController();
	fornecedoresController->showCrudView(0);
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::Categorias1Click(TObject *Sender)
{
	CategoriasController *categoriasController = new CategoriasController();
    categoriasController->showCrudView(0);
}
//---------------------------------------------------------------------------


void __fastcall TFPrincipal::Papeis1Click(TObject *Sender)
{
    FPapeisView->ShowModal();
}
//---------------------------------------------------------------------------

