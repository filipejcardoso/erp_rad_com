//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConfiguracoesView.h"
#include "Principal.h"
#include "GridHelper.h"
#include "MaskBits.h"
#include "InfoFinanceirasDAO.h"
#include "RegioesDAO.h"
#include "TiposEnderecosDAO.h"
#include "ClientesController.h"
#include "Helper.h"
#include "Sistema.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFConfiguracoesView *FConfiguracoesView;
//---------------------------------------------------------------------------
__fastcall TFConfiguracoesView::TFConfiguracoesView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFConfiguracoesView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
	ConfigurarForm(this);
	controller = new ConfiguracoesController();
	configuracao = new Configuracoes();
}
//---------------------------------------------------------------------------
void TFConfiguracoesView::loadView()
{
	loadConfiguracoes();

	this->EditValidade->SetFocus();
}
//---------------------------------------------------------------------------
void TFConfiguracoesView::loadConfiguracoesModel()
{
	//CONFIG PEDIDOS
	configuracao->config_pedido->validade = StrToInt(this->EditValidade->Text);
    configuracao->config_pedido->associado = (Associados*) ComboClientePadrao->Items[0].Objects[ComboClientePadrao->ItemIndex];
}
//---------------------------------------------------------------------------
void TFConfiguracoesView::loadConfiguracoes()
{
	printLogo = "";

	ImageLogo->Picture->LoadFromFile(GetCurrentDir() + "/images/pedido/print_logo.jpg");

	configuracao = (Configuracoes*) controller->show()->Items[0];

	EditValidade->Text = configuracao->config_pedido->validade;

    loadComboClientePadrao();
}
//---------------------------------------------------------------------------
void __fastcall TFConfiguracoesView::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------//---------------------------------------------------------------------------
void __fastcall TFConfiguracoesView::SairClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void TFConfiguracoesView::loadComboClientePadrao()
{
	TList *recursos;
    int index = 0;
	ClientesController *clientesController = new ClientesController();

	recursos = clientesController->index("");

	this->ComboClientePadrao->Clear();

	for(int i=0;i<recursos->Count;i++)
	{
		Associados *recurso = (Associados*) recursos->Items[i];

		this->ComboClientePadrao->AddItem(recurso->nome, recurso);

		if(recurso->id == configuracao->config_pedido->associado->id)
            index = i;
	}

	this->ComboClientePadrao->ItemIndex = index;
}
//---------------------------------------------------------------------------

void __fastcall TFConfiguracoesView::ModificarClick(TObject *Sender)
{
	UnicodeString existfile,newfile;

	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		//LOGO PEDIDO
		if(printLogo.Trim() != "")
		{
			existfile = printLogo;
			newfile = GetCurrentDir() + "/images/pedido/print_logo.jpg";
			CopyFile(existfile.w_str(), newfile.w_str(), FALSE);
        }

		this->loadConfiguracoesModel();
		Result *result = controller->update(configuracao);

		if(result->code == 202)
		{
            SISTEMA->configuracao = configuracao;
			Close();
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TFConfiguracoesView::BtSearchClick(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
		printLogo = OpenDialog1->FileName;
		ImageLogo->Picture->LoadFromFile(OpenDialog1->FileName);
	}
}
//---------------------------------------------------------------------------

