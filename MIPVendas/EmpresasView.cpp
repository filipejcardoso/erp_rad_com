//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EmpresasView.h"
#include "Principal.h"
#include "GridHelper.h"
#include "MaskBits.h"
#include "InfoFinanceirasDAO.h"
#include "RegioesDAO.h"
#include "TiposEnderecosDAO.h"
#include "Helper.h"
#include "Sistema.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFEmpresasView *FEmpresasView;
//---------------------------------------------------------------------------
__fastcall TFEmpresasView::TFEmpresasView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFEmpresasView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
	ConfigurarForm(this);
	controller = new EmpresasController();
	empresa = new Empresas();
}
//---------------------------------------------------------------------------
void TFEmpresasView::loadView()
{
	loadComboEnderecosRegiao();
	loadComboEnderecosTipo();
	loadEmpresa();

    this->EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFEmpresasView::loadEmpresaModel()
{
	empresa->nome = this->EditNome->Text;
	empresa->razao_social = this->EditRazaoSocial->Text;
	empresa->cpf_cnpj = this->EditCnpj->Text;
	empresa->im = this->EditInscricaoMunicipal->Text;
	empresa->ie = this->EditInscricaoEstadual->Text;
	empresa->telefone = this->EditTelefone->Text;
	empresa->email = this->EditEmail->Text;
	empresa->site = this->EditSite->Text;

	empresa->endereco->cep = this->EditEnderecosCep->Text;
	empresa->endereco->complemento = this->EditEnderecosComplemento->Text;
	empresa->endereco->logradouro = this->EditEnderecosLogradouro->Text;
	empresa->endereco->numero = this->EditEnderecosNumero->Text;
	empresa->endereco->bairro = this->EditEnderecosBairro->Text;

	empresa->endereco->regioes = (Regioes*) ComboEnderecosRegiao->Items[0].Objects[ComboEnderecosRegiao->ItemIndex];
	empresa->endereco->tipos_endereco = (TiposEnderecos*) ComboEnderecosTipo->Items[0].Objects[ComboEnderecosTipo->ItemIndex];

}
//---------------------------------------------------------------------------
void TFEmpresasView::loadEmpresa()
{
   	empresa = (Empresas*) controller->show()->Items[0];

    //LIMPA OS CAMPOS
	loadClearFields();

    //DADOS PRINCIPAIS DA EMPRESA
	this->EditNome->Text = empresa->nome;
	this->EditRazaoSocial->Text = empresa->razao_social;
	this->EditCnpj->Text = empresa->cpf_cnpj;
	this->EditInscricaoMunicipal->Text = empresa->im;
	this->EditInscricaoEstadual->Text = empresa->ie;
	this->EditTelefone->Text = empresa->telefone;
	this->EditEmail->Text = empresa->email;
	this->EditSite->Text = empresa->site;

	this->EditEnderecosCep->Text = empresa->endereco->cep;
	this->EditEnderecosComplemento->Text = empresa->endereco->complemento;
	this->EditEnderecosLogradouro->Text = empresa->endereco->logradouro;
	this->EditEnderecosNumero->Text = empresa->endereco->numero;
	this->EditEnderecosBairro->Text = empresa->endereco->bairro;

	for(int i=0;i<ComboEnderecosRegiao->Items->Count;i++)
		if(((Regioes*) ComboEnderecosRegiao->Items[0].Objects[i])->id == empresa->endereco->regioes->id)
		{
			ComboEnderecosRegiao->ItemIndex = i;
            break;
        }

	for(int i=0;i<ComboEnderecosTipo->Items->Count;i++)
		if(((TiposEnderecos*) ComboEnderecosTipo->Items[0].Objects[i])->id == empresa->endereco->tipos_endereco->id)
		{
			ComboEnderecosTipo->ItemIndex = i;
			break;
		}
}
//---------------------------------------------------------------------------
void TFEmpresasView::loadClearFields()
{
	this->EditNome->Clear();
	this->EditRazaoSocial->Clear();
	this->EditCnpj->Clear();
	this->EditInscricaoMunicipal->Clear();
	this->EditInscricaoEstadual->Clear();
	this->EditTelefone->Clear();
	this->EditEmail->Clear();
	this->EditSite->Clear();

	this->EditEnderecosCep->Clear();
	this->EditEnderecosComplemento->Clear();
	this->EditEnderecosLogradouro->Clear();
	this->EditEnderecosNumero->Clear();
	this->EditEnderecosBairro->Clear();

	this->ComboEnderecosTipo->ItemIndex = 0;
    this->ComboEnderecosRegiao->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFEmpresasView::FormShow(TObject *Sender)
{
	loadView();
}
//---------------------------------------------------------------------------//---------------------------------------------------------------------------
void __fastcall TFEmpresasView::SairClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void TFEmpresasView::loadComboEnderecosRegiao()
{
    int index = 0;
	TList *recursos;

	recursos = FRegioesDAO->index("sort=Auf,Amunicipio");

	this->ComboEnderecosRegiao->Clear();

	for(int i=0;i<recursos->Count;i++)
	{
		Regioes *recurso = (Regioes*) recursos->Items[i];

		this->ComboEnderecosRegiao->AddItem(recurso->getMunicipioUf(), recurso);
		if(recurso->id != empresa->id)
			index = i;
	}

	this->ComboEnderecosRegiao->ItemIndex = index;
}
//---------------------------------------------------------------------------
void TFEmpresasView::loadComboEnderecosTipo()
{
    int index = 0;
	TList *recursos;

	recursos = FTiposEnderecosDAO->index("");

	this->ComboEnderecosTipo->Clear();

	for(int i=0;i<recursos->Count;i++)
	{
		TiposEnderecos *recurso = (TiposEnderecos*) recursos->Items[i];

		this->ComboEnderecosTipo->AddItem(recurso->nome, recurso);
        if(recurso->id != empresa->id)
            index = i;
	}

	this->ComboEnderecosTipo->ItemIndex = index;
}
//---------------------------------------------------------------------------
void __fastcall TFEmpresasView::ModificarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		this->loadEmpresaModel();
		Result *result = controller->update(empresa);

		if(result->code == 202)
		{
            SISTEMA->empresa = empresa;
			Close();
        }
	}
}
//---------------------------------------------------------------------------

