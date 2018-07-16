//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnidadesMedidasView.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFUnidadesMedidasView *FUnidadesMedidasView;
//---------------------------------------------------------------------------
__fastcall TFUnidadesMedidasView::TFUnidadesMedidasView(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TFUnidadesMedidasView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
	ConfigurarForm(this);
	unidades_medida = new UnidadesMedidas();
	controller = new UnidadesMedidasController();
}
//---------------------------------------------------------------------------
void TFUnidadesMedidasView::DesignerBotoes()
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
void TFUnidadesMedidasView::loadUnidadesMedida()
{
	EditNome->Text = unidades_medida->descricao;
	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFUnidadesMedidasView::loadUnidadesMedidaModel()
{
	unidades_medida->descricao = EditNome->Text;
}
//---------------------------------------------------------------------------
void TFUnidadesMedidasView::loadClearFields()
{
	EditNome->Clear();

	EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFUnidadesMedidasView::loadView()
{
	DesignerBotoes();

	if(editar)
		loadUnidadesMedida();
	else
	{
		unidades_medida = new UnidadesMedidas();
		loadClearFields();
    }
}
void __fastcall TFUnidadesMedidasView::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------

void __fastcall TFUnidadesMedidasView::SairClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFUnidadesMedidasView::AdicionarClick(TObject *Sender)
{
	this->loadUnidadesMedidaModel();
	Result *result = controller->store(unidades_medida);

	if(result->code == 201)
		Close();
}
//---------------------------------------------------------------------------

void __fastcall TFUnidadesMedidasView::DeletarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja remover?",L"Remover Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		Result *result = controller->destroy(unidades_medida);

		if(result->code == 200)
			Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFUnidadesMedidasView::ModificarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		this->loadUnidadesMedidaModel();
		Result *result = controller->update(unidades_medida);

		if(result->code == 202)
			Close();
	}
}
//---------------------------------------------------------------------------

