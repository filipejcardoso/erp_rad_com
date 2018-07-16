//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClientesView.h"
#include "Principal.h"
#include "Contatos.h"
#include "GridHelper.h"
#include "TiposContatosDAO.h"
#include "TiposEnderecosDAO.h"
#include "RegioesDAO.h"
#include "GruposAssociadosDAO.h"
#include "MaskBits.h"
#include "InfoFinanceirasDAO.h"
#include "Helper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFClientesView *FClientesView;
//---------------------------------------------------------------------------
__fastcall TFClientesView::TFClientesView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFClientesView::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
	ConfigurarForm(this);
	controller = new ClientesController();
	cliente = new Associados();

	helperEnderecos = new GridHelper(this->StringGridEnderecos);
	helperBancarias = new GridHelper(this->StringGridContatos);
	helperContatos = new GridHelper(this->StringGridBancarias);

    helperEnderecos->checkBox = TRUE;
    helperBancarias->checkBox = TRUE;
	helperContatos->checkBox = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TFClientesView::StringGridContatosDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
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
		Texto = StringGridContatos->Cells[ACol][ARow];

		StringGridContatos->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGridContatos->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGridContatos->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGridContatos->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGridContatos->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGridContatos->Canvas->FillRect(Rect);
		StringGridContatos->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGridContatos->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

		/*--------------------COLOCAR CHECKBOX----------------------------*/
		if(helperContatos)
			if(helperContatos->checkBox)
			{
				if(ACol == 0)
				{
					if(helperContatos->isChecked(ARow))
						DrawFrameControl(StringGridContatos->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
					else
						DrawFrameControl(StringGridContatos->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK);
				}
			}
	}

}
//---------------------------------------------------------------------------
void __fastcall TFClientesView::StringGridBancariasDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
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
		Texto = StringGridBancarias->Cells[ACol][ARow];

		StringGridBancarias->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGridBancarias->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGridBancarias->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGridBancarias->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGridBancarias->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGridBancarias->Canvas->FillRect(Rect);
		StringGridBancarias->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGridBancarias->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

		/*--------------------COLOCAR CHECKBOX----------------------------*/
		if(helperBancarias)
			if(helperBancarias->checkBox)
			{
				if(ACol == 0)
				{
					if(helperBancarias->isChecked(ARow))
						DrawFrameControl(StringGridBancarias->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
					else
						DrawFrameControl(StringGridBancarias->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK);
				}
			}
	}
}
//---------------------------------------------------------------------------
void TFClientesView::loadView()
{
	DesignerBotoes();

	if(editar)
		loadCliente();
	else
	{
        cliente = new Associados();
		loadClearFields();
    }
}
//---------------------------------------------------------------------------
void TFClientesView::loadClienteModel()
{
	cliente->nome = this->EditNome->Text;
	cliente->email = this->EditEmail->Text;
	cliente->site = this->EditSite->Text;
	cliente->telefone_comercial = this->EditTelefoneComercial->Text;
	cliente->telefone_celular = this->EditTelefoneCelular->Text;
	cliente->fax = this->EditFax->Text;
	cliente->ie = this->EditInscricaoEstadual->Text;

	cliente->tipo = ComboTipo->ItemIndex;

	if(cliente->tipo == 0)  //FISICA
	{
		cliente->cpf_cnpj = this->EditCpf->Text;
		cliente->rg = this->EditRg->Text;
		cliente->nascimento = Helper::DateQuery(this->DateNascimento->Date.DateString());
	}
	else   //JURIDICA
	{
		cliente->cpf_cnpj = this->EditCnpj->Text;
		cliente->im = this->EditInscricaoMunicipal->Text;
		cliente->razao_social = this->EditRazaoSocial->Text;
	}

    cliente->situacao = ComboSituacao->ItemIndex;

	cliente->tipo_associado = 0;

	if(CheckCliente->Checked)
		cliente->tipo_associado = cliente->tipo_associado | 0x01;

    if(CheckFornecedor->Checked)
		cliente->tipo_associado = cliente->tipo_associado | 0x02;

	if(ComboGrupo->Enabled)
		cliente->grupos_associado = (GruposAssociados*) ComboGrupo->Items[0].Objects[ComboGrupo->ItemIndex];

	if(ComboIndicacao->Enabled)
		cliente->indicacao_id = ((Associados*) ComboIndicacao->Items[0].Objects[ComboIndicacao->ItemIndex])->id;
	else
        cliente->indicacao_id = 0;

	cliente->info_financeira->consumidor = this->CheckFinanceiroConsumidor->Checked;

	cliente->info_financeira->limite = FStrToFloat(this->EditFinanceiroLimite->Text);
}
//---------------------------------------------------------------------------
void TFClientesView::loadCliente()
{
   	cliente = (Associados*) controller->show(cliente->id)->Items[0];

    //LIMPA OS CAMPOS
	loadClearFields();

    //DADOS PRINCIPAIS DO CLIENTE
	this->EditNome->Text = cliente->nome;
	this->EditEmail->Text = cliente->email;
	this->EditSite->Text = cliente->site;
	this->EditTelefoneComercial->Text = cliente->telefone_comercial;
	this->EditTelefoneCelular->Text = cliente->telefone_celular;
	this->EditFax->Text = cliente->fax;
	this->EditInscricaoEstadual->Text = cliente->ie;
	this->EditCpf->Text = cliente->cpf_cnpj;
	this->EditRg->Text = cliente->rg;
	try{
		if(cliente->nascimento.Trim() != "")
			this->DateNascimento->Date = StrToDate(Helper::DateConvert(cliente->nascimento));
	}
	catch(Exception &e){
		this->DateNascimento->Date = Now();
	}
	this->EditCnpj->Text = cliente->cpf_cnpj;
	this->EditInscricaoMunicipal->Text = cliente->im;
	this->EditRazaoSocial->Text = cliente->razao_social;

	//SETA RELACOES E TIPO DE ASSOCIADO
	ComboSituacao->ItemIndex = cliente->situacao;
	if(cliente->indicacao_id!=0)
		CheckIndicacao->Checked = TRUE;
	if(cliente->grupos_associado->id != 0)
		CheckGrupo->Checked = TRUE;
	ComboTipo->ItemIndex = cliente->tipo;
	setTipoAssociado(false, cliente->tipo_associado);
	setTipo(false);
	setIndicacao(false);
	for(int i = 0;i<ComboIndicacao->Items->Count;i++)
		if(((Associados*)ComboIndicacao->Items[0].Objects[i])->id == cliente->indicacao_id)
			ComboIndicacao->ItemIndex = i;
	setGrupo(false);
	for(int i = 0;i<ComboGrupo->Items->Count;i++)
		if(((GruposAssociados*)ComboGrupo->Items[0].Objects[i])->id == cliente->grupos_associado->id)
			ComboGrupo->ItemIndex = i;

	//CARREGA LISTA DE RALACOES
	this->gridEnderecos();
	this->gridContatos();
	this->gridReferenciasBancarias();

    //CARREGA AS INFORMACOES FINANCEIRA DO CLIENTE
	if(cliente->info_financeira->consumidor)
		this->CheckFinanceiroConsumidor->Checked = TRUE;
	else
		this->CheckFinanceiroConsumidor->Checked = FALSE;

	this->EditFinanceiroLimite->Text =  FormatFloat("#,###,###,##0.00", cliente->info_financeira->limite);

	//SETA O FOCU E PAGE  INDEX
	PageControl1->TabIndex = 0;
    EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFClientesView::loadClearFields()
{
	gridEnderecos();
	gridContatos();
	gridReferenciasBancarias();

	this->EditNome->Clear();
	this->EditEmail->Clear();
	this->EditSite->Clear();
	this->EditTelefoneComercial->Clear();
	this->EditTelefoneCelular->Clear();
	this->EditFax->Clear();
	this->EditInscricaoEstadual->Clear();

	this->EditCpf->Clear();
	this->EditRg->Clear();
	this->DateNascimento->Date = Now();

	this->EditCnpj->Clear();
	this->EditInscricaoMunicipal->Clear();
	this->EditRazaoSocial->Clear();

	this->EditEnderecosCep->Clear();
	this->EditEnderecosComplemento->Clear();
	this->EditEnderecosLogradouro->Clear();
	this->EditEnderecosNumero->Clear();
	this->EditEnderecosBairro->Clear();

	this->EditContatosCargo->Clear();
	this->EditContatosContato->Clear();
	this->EditContatosNome->Clear();
	this->EditContatosObservacao->Clear();

	this->EditBancariasAgencia->Clear();
	this->EditBancariasBanco->Clear();
	this->EditBancariasConta->Clear();
	this->EditBancariasCpfCnpj->Clear();
	this->EditBancariasDescricao->Clear();
	this->EditBancariasNome->Clear();

	this->CheckFinanceiroConsumidor->Checked = FALSE;
	this->EditFinanceiroLimite->Clear();

	setIndicacao(true);
	setTipo(true);
	setGrupo(true);
    setTipoAssociado(true,0);

	this->ComboSituacao->ItemIndex = 1;
	this->ComboTipoContribuinte->ItemIndex = 0;

	//SETA INDEX DAS RELACOES COMBO
    ComboEnderecosRegiao->ItemIndex = 0;
    ComboEnderecosTipo->ItemIndex = 0;
    ComboContatosTipo->ItemIndex = 0;

	//SETA O FOCU E PAGE  INDEX
	PageControl1->TabIndex = 0;
    EditNome->SetFocus();
}
//---------------------------------------------------------------------------
void TFClientesView::DesignerBotoes()
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
void __fastcall TFClientesView::FormShow(TObject *Sender)
{
    loadView();
}
//---------------------------------------------------------------------------
void TFClientesView::gridEnderecos()
{
    Enderecos *endereco;
	int numerodalinha,i;

	for(i=1;i<StringGridEnderecos->RowCount;i++)
		StringGridEnderecos->Rows[i]->Clear();

	numerodalinha = 1;
	//ESTRUTURA
	StringGridEnderecos->Options << goRowSelect;
	StringGridEnderecos->ScrollBars = ssVertical;
	StringGridEnderecos->Rows[1]->Clear();
	StringGridEnderecos->RowCount = 0;
	StringGridEnderecos->ColCount = 8;
	StringGridEnderecos->FixedCols = 0;
	StringGridEnderecos->Cells[0][0] = "  ";
	StringGridEnderecos->Cells[1][0] = "Tipo";
	StringGridEnderecos->Cells[2][0] = "CEP";
	StringGridEnderecos->Cells[3][0] = "Logadouro";
	StringGridEnderecos->Cells[4][0] = "Numero";
	StringGridEnderecos->Cells[5][0] = "Bairro";
	StringGridEnderecos->Cells[6][0] = "Municipio/UF";
	StringGridEnderecos->Cells[7][0] = "Complemento";
	//ESTRUTURA

	if(cliente)
	{
		TList *enderecos = this->cliente->endereco;

		for(i=0; i<enderecos->Count; i++)
		{
			endereco = (Enderecos*) enderecos->Items[i];

			StringGridEnderecos->Cells[0][numerodalinha] = "  ";
			StringGridEnderecos->Cells[1][numerodalinha] = endereco->tipos_endereco->nome;
			StringGridEnderecos->Cells[2][numerodalinha] = endereco->cep;
			StringGridEnderecos->Cells[3][numerodalinha] = endereco->logradouro;
			StringGridEnderecos->Cells[4][numerodalinha] = endereco->numero;
			StringGridEnderecos->Cells[5][numerodalinha] = endereco->bairro;
			StringGridEnderecos->Cells[6][numerodalinha] = endereco->regioes->getMunicipioUf();
			StringGridEnderecos->Cells[7][numerodalinha] = endereco->complemento;

			StringGridEnderecos->RowCount++;

			numerodalinha++;

			if (numerodalinha == 2)
				StringGridEnderecos->FixedRows = 1;
		}
		if (numerodalinha <= 1)
			StringGridEnderecos->RowCount++;

		GridHelper *grid = new GridHelper();
		grid->StringGrid = StringGridEnderecos;
		grid->sizeGrid();
	}
}
//---------------------------------------------------------------------------
void TFClientesView::gridContatos()
{
	Contatos *contato;
	int numerodalinha,i;

	for(i=1;i<StringGridContatos->RowCount;i++)
		StringGridContatos->Rows[i]->Clear();

	numerodalinha = 1;
	//ESTRUTURA
	StringGridContatos->Options << goRowSelect;
	StringGridContatos->ScrollBars = ssVertical;
	StringGridContatos->Rows[1]->Clear();
	StringGridContatos->RowCount = 0;
	StringGridContatos->ColCount = 6;
	StringGridContatos->FixedCols = 0;
	StringGridContatos->Cells[0][0] = "  ";
	StringGridContatos->Cells[1][0] = "Nome";
	StringGridContatos->Cells[2][0] = "Cargo";
	StringGridContatos->Cells[3][0] = "Contato";
	StringGridContatos->Cells[4][0] = "Tipo";
	StringGridContatos->Cells[5][0] = "Observação";
	//ESTRUTURA

	if(cliente)
	{
		TList *contatos = this->cliente->contato;

		for(i=0; i<contatos->Count; i++)
		{
			contato = (Contatos*) contatos->Items[i];

			StringGridContatos->Cells[0][numerodalinha] = "  ";
			StringGridContatos->Cells[1][numerodalinha] = contato->nome;
			StringGridContatos->Cells[2][numerodalinha] = contato->cargo;
			StringGridContatos->Cells[3][numerodalinha] = contato->contato;
			StringGridContatos->Cells[4][numerodalinha] = contato->tipos_contato->nome;
			StringGridContatos->Cells[5][numerodalinha] = contato->observacao;

			StringGridContatos->RowCount++;

			numerodalinha++;

			if (numerodalinha == 2)
				StringGridContatos->FixedRows = 1;
		}
		if (numerodalinha <= 1)
			StringGridContatos->RowCount++;

		GridHelper *grid = new GridHelper();
		grid->StringGrid = StringGridContatos;
		grid->sizeGrid();
	}
}
//---------------------------------------------------------------------------
void TFClientesView::gridReferenciasBancarias()
{
	ReferenciasBancarias *referencias_bancaria;
	int numerodalinha,i;

	for(i=1;i<StringGridBancarias->RowCount;i++)
		StringGridBancarias->Rows[i]->Clear();

	numerodalinha = 1;
	//ESTRUTURA
	StringGridBancarias->Options << goRowSelect;
	StringGridBancarias->ScrollBars = ssVertical;
	StringGridBancarias->Rows[1]->Clear();
	StringGridBancarias->RowCount = 0;
	StringGridBancarias->ColCount = 7;
	StringGridBancarias->FixedCols = 0;
	StringGridBancarias->Cells[0][0] = "  ";
	StringGridBancarias->Cells[1][0] = "Descrição";
	StringGridBancarias->Cells[2][0] = "Banco";
	StringGridBancarias->Cells[3][0] = "Agencia";
	StringGridBancarias->Cells[4][0] = "Conta";
	StringGridBancarias->Cells[5][0] = "Nome";
	StringGridBancarias->Cells[6][0] = "CPF/CNPJ";
	//ESTRUTURA

	if(cliente)
	{
		TList *referencias_bancarias = this->cliente->referencias_bancaria;

		for(i=0; i<referencias_bancarias->Count; i++)
		{
			referencias_bancaria = (ReferenciasBancarias*) referencias_bancarias->Items[i];

			StringGridBancarias->Cells[0][numerodalinha] = "  ";
			StringGridBancarias->Cells[1][numerodalinha] = referencias_bancaria->descricao;
			StringGridBancarias->Cells[2][numerodalinha] = referencias_bancaria->banco;
			StringGridBancarias->Cells[3][numerodalinha] = referencias_bancaria->agencia;
			StringGridBancarias->Cells[4][numerodalinha] = referencias_bancaria->conta;
			StringGridBancarias->Cells[5][numerodalinha] = referencias_bancaria->nome;
			StringGridBancarias->Cells[6][numerodalinha] = referencias_bancaria->cpf_cnpj;

			StringGridBancarias->RowCount++;

			numerodalinha++;

			if (numerodalinha == 2)
				StringGridBancarias->FixedRows = 1;
		}
		if (numerodalinha <= 1)
			StringGridBancarias->RowCount++;

		GridHelper *grid = new GridHelper();
		grid->StringGrid = StringGridBancarias;
		grid->sizeGrid();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::StringGridEnderecosDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
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
		Texto = StringGridEnderecos->Cells[ACol][ARow];

		StringGridEnderecos->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGridEnderecos->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGridEnderecos->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGridEnderecos->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGridEnderecos->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGridEnderecos->Canvas->FillRect(Rect);
		StringGridEnderecos->Canvas->Rectangle(Rect.Left-5 ,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGridEnderecos->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

		/*--------------------COLOCAR CHECKBOX----------------------------*/
		if(helperEnderecos)
			if(helperEnderecos->checkBox)
			{
				if(ACol == 0)
				{
					if(helperEnderecos->isChecked(ARow))
						DrawFrameControl(StringGridEnderecos->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
					else
						DrawFrameControl(StringGridEnderecos->Canvas->Handle, rc,DFC_BUTTON, DFCS_BUTTONCHECK);
				}
			}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::RecursosThreadTimer(TObject *Sender)
{
    RecursosThread->Enabled = FALSE;

	loadComboTipoContribuinte();
	loadComboTipo();
	loadComboSituacao();

	loadComboEnderecosRegiao();
	loadComboEnderecosTipo();
	loadComboContatosTipo();
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::SairClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void TFClientesView::loadComboIndicacao()
{
	TList *recursos;

	recursos = controller->index("");

	this->ComboIndicacao->Clear();

	for(int i=0;i<recursos->Count;i++)
	{
		Associados *recurso = (Associados*) recursos->Items[i];

        if(recurso->id != cliente->id)
			this->ComboIndicacao->AddItem(recurso->nome, recurso);
	}

	this->ComboIndicacao->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void TFClientesView::loadComboGrupo()
{
	TList *recursos;

	recursos = FGruposAssociadosDAO->index("sort=Anome");

	this->ComboGrupo->Clear();

	for(int i=0;i<recursos->Count;i++)
	{
		GruposAssociados *recurso = (GruposAssociados*) recursos->Items[i];

		this->ComboGrupo->AddItem(recurso->nome, recurso);
	}

	this->ComboGrupo->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void TFClientesView::loadComboTipoContribuinte()
{
	this->ComboTipoContribuinte->Items->Clear();

	this->ComboTipoContribuinte->Items->Add("040 - Nacional Isento");
	this->ComboTipoContribuinte->Items->Add("041 - Nacional Não Tributado");
	this->ComboTipoContribuinte->Items->Add("000 - Nacional Tributado");

	this->ComboTipoContribuinte->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void TFClientesView::loadComboTipo()
{
	this->ComboTipo->Items->Clear();

	this->ComboTipo->Items->Add("Física");
	this->ComboTipo->Items->Add("Jurídica");

	this->ComboTipo->ItemIndex = 1;
}
//---------------------------------------------------------------------------
void TFClientesView::loadComboSituacao()
{
	this->ComboSituacao->Items->Clear();

	this->ComboSituacao->Items->Add("Inativo");
	this->ComboSituacao->Items->Add("Ativo");

	this->ComboSituacao->ItemIndex = 1;
}
//---------------------------------------------------------------------------
void TFClientesView::loadComboEnderecosRegiao()
{
	TList *recursos;

	recursos = FRegioesDAO->index("sort=Auf,Amunicipio");

	this->ComboEnderecosRegiao->Clear();

	for(int i=0;i<recursos->Count;i++)
	{
		Regioes *recurso = (Regioes*) recursos->Items[i];

		this->ComboEnderecosRegiao->AddItem(recurso->getMunicipioUf(), recurso);
	}

	this->ComboEnderecosRegiao->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void TFClientesView::loadComboEnderecosTipo()
{
	TList *recursos;

	recursos = FTiposEnderecosDAO->index("");

	this->ComboEnderecosTipo->Clear();

	for(int i=0;i<recursos->Count;i++)
	{
		TiposEnderecos *recurso = (TiposEnderecos*) recursos->Items[i];

		this->ComboEnderecosTipo->AddItem(recurso->nome, recurso);
	}

	this->ComboEnderecosTipo->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void TFClientesView::loadComboContatosTipo()
{
	TList *recursos;

	recursos = FTiposContatosDAO->index("");

	this->ComboContatosTipo->Clear();

	for(int i=0;i<recursos->Count;i++)
	{
		TiposContatos *recurso = (TiposContatos*) recursos->Items[i];

		this->ComboContatosTipo->AddItem(recurso->nome, recurso);
	}

	this->ComboContatosTipo->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void TFClientesView::setIndicacao(bool clear)
{
	if(clear || !CheckIndicacao->Checked)
	{
		CheckIndicacao->Checked = FALSE;
		ComboIndicacao->Clear();
		ComboIndicacao->Enabled = FALSE;
	}
	else
	{
		ComboIndicacao->Enabled = TRUE;
		loadComboIndicacao();
	}
}
//---------------------------------------------------------------------------
void TFClientesView::setGrupo(bool clear)
{
	if(clear || !CheckGrupo->Checked)
	{
		ComboGrupo->Clear();
        CheckGrupo->Checked = FALSE;
		ComboGrupo->Enabled = FALSE;
    }
	else
	{
		ComboGrupo->Enabled = TRUE;
		loadComboGrupo();
	}
}
//---------------------------------------------------------------------------
void TFClientesView::setTipo(bool clear)
{
	if(clear || ComboTipo->ItemIndex == 1)
	{
        ComboTipo->ItemIndex = 1;
		GroupJuridica->Visible = TRUE;
        GroupFisica->Visible = FALSE;
	}
	else
	{
		GroupJuridica->Visible = FALSE;
		GroupFisica->Visible = TRUE;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFClientesView::CheckIndicacaoClick(TObject *Sender)
{
	setIndicacao(false);
}
//---------------------------------------------------------------------------
void __fastcall TFClientesView::ComboTipoChange(TObject *Sender)
{
	setTipo(false);
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::CheckGrupoClick(TObject *Sender)
{
    setGrupo(false);
}
//---------------------------------------------------------------------------
void TFClientesView::setTipoAssociado(bool clear, int valor)
{
	if(clear)
	{
		this->CheckCliente->Checked = TRUE;
		this->CheckFornecedor->Checked = FALSE;
	}
	else
	{
		if(MaskBits::mask(valor, 1))
			this->CheckCliente->Checked = TRUE;

		if(MaskBits::mask(valor, 2))
			this->CheckFornecedor->Checked = TRUE;
	}

}

void __fastcall TFClientesView::ButtonAdicionarBancariasClick(TObject *Sender)
{
	ReferenciasBancarias *referencias_bancaria = new ReferenciasBancarias();

	referencias_bancaria->id = 0;
	referencias_bancaria->descricao = EditBancariasDescricao->Text;
	referencias_bancaria->agencia = EditBancariasAgencia->Text;
	referencias_bancaria->nome = EditBancariasNome->Text;
	referencias_bancaria->banco = EditBancariasBanco->Text;
	referencias_bancaria->conta = EditBancariasConta->Text;
	referencias_bancaria->cpf_cnpj = EditBancariasCpfCnpj->Text;

	cliente->referencias_bancaria->Add((ReferenciasBancarias*) referencias_bancaria);

	if(editar == 1)
	{
		Associados *auxcliente = new Associados();
		auxcliente->id = cliente->id;
		auxcliente->referencias_bancaria->Add((ReferenciasBancarias*) referencias_bancaria);

		controller->storeRelation(auxcliente);
	}

	gridReferenciasBancarias();
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::ButtonAdicionarContatoClick(TObject *Sender)
{
	Contatos *contato = new Contatos();
	int index = ComboContatosTipo->ItemIndex;

	contato->id = 0;
	contato->nome = EditContatosNome->Text;
	contato->cargo = EditContatosCargo->Text;
	contato->contato = EditContatosContato->Text;
	contato->observacao = EditContatosObservacao->Text;
	contato->tipos_contato = (TiposContatos*) ComboContatosTipo->Items[0].Objects[index];

	cliente->contato->Add((Contatos*) contato);

	if(editar == 1)
	{
		Associados *auxcliente = new Associados();
		auxcliente->id = cliente->id;
		auxcliente->contato->Add((Contatos*) contato);

		controller->storeRelation(auxcliente);
	}

	gridContatos();
}
//---------------------------------------------------------------------------



void __fastcall TFClientesView::AdicionarClick(TObject *Sender)
{
	this->loadClienteModel();
	Result *result = controller->store(cliente);

	if(result->code == 201)
		Close();
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::DeletarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja remover?",L"Remover Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		Result *result = controller->destroy(cliente);

		if(result->code == 200)
			Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::ModificarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja modificar?",L"Modificar Recurso",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		this->loadClienteModel();
		Result *result = controller->update(cliente);

		if(result->code == 202)
			Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::ButtonAdicionarEnderecoClick(TObject *Sender)
{
	Enderecos *endereco = new Enderecos();

	endereco->id = 0;
	endereco->cep = EditEnderecosCep->Text;
	endereco->logradouro = EditEnderecosLogradouro->Text;
	endereco->numero = EditEnderecosNumero->Text;
	endereco->bairro = EditEnderecosBairro->Text;
	endereco->complemento = EditEnderecosComplemento->Text;

	endereco->regioes = (Regioes*) ComboEnderecosRegiao->Items[0].Objects[ComboEnderecosRegiao->ItemIndex];
	endereco->tipos_endereco = (TiposEnderecos*) ComboEnderecosTipo->Items[0].Objects[ComboEnderecosTipo->ItemIndex];
	cliente->endereco->Add((Enderecos*) endereco);

	if(editar == 1)
	{
		Associados *auxcliente = new Associados();
		auxcliente->id = cliente->id;
		auxcliente->endereco->Add((Enderecos*) endereco);

		controller->storeRelation(auxcliente);
	}

	gridEnderecos();
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::StringGridEnderecosMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(helperEnderecos)
		if(helperEnderecos->checkBox)
		{
			if(colselectEnderecos == 0)
				helperEnderecos->selectRow(rowselectEnderecos);

			StringGridEnderecos->Repaint();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::StringGridContatosMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(helperContatos)
		if(helperContatos->checkBox)
		{
			if(colselectContatos == 0)
				helperContatos->selectRow(rowselectContatos);

			StringGridContatos->Repaint();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::StringGridBancariasMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(helperBancarias)
		if(helperBancarias->checkBox)
		{
			if(colselectBancarias == 0)
				helperBancarias->selectRow(rowselectBancarias);

			StringGridBancarias->Repaint();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::StringGridContatosSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselectContatos = ARow;
	colselectContatos = ACol;
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::StringGridBancariasSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselectBancarias = ARow;
	colselectBancarias = ACol;
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::StringGridEnderecosSelectCell(TObject *Sender, int ACol,
		  int ARow, bool &CanSelect)
{
	rowselectEnderecos = ARow;
	colselectEnderecos = ACol;
}
//---------------------------------------------------------------------------
void __fastcall TFClientesView::ButtonRemoverEnderecoClick(TObject *Sender)
{
	for(int i=StringGridEnderecos->RowCount-1;i>0;i--)
		if(helperEnderecos->isChecked(i))
		{
			if(editar == 1)
			{
				Associados *auxcliente = new Associados();
				Enderecos *endereco = (Enderecos*) cliente->endereco->Items[i-1];
				auxcliente->id = cliente->id;
				auxcliente->endereco->Add((Enderecos*) endereco);
				controller->destroyRelation(auxcliente);
            }

			cliente->endereco->Delete(i-1);
		}

	helperEnderecos->clearCheck();
	gridEnderecos();
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::ButtonRemoverContatoClick(TObject *Sender)
{
	for(int i=StringGridContatos->RowCount-1;i>0;i--)
		if(helperContatos->isChecked(i))
		{
			if(editar == 1)
			{
				Associados *auxcliente = new Associados();
				Contatos *contato = (Contatos*) cliente->contato->Items[i-1];
				auxcliente->id = cliente->id;
				auxcliente->contato->Add((Contatos*) contato);
				controller->destroyRelation(auxcliente);
            }

			cliente->contato->Delete(i-1);
        }

	helperContatos->clearCheck();
	gridContatos();
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::ButtonRemoverBancariasClick(TObject *Sender)
{
	for(int i=StringGridBancarias->RowCount-1;i>0;i--)
		if(helperBancarias->isChecked(i))
		{
			if(editar == 1)
			{
				Associados *auxcliente = new Associados();
				ReferenciasBancarias *referencias_bancaria = (ReferenciasBancarias*) cliente->referencias_bancaria->Items[i-1];
				auxcliente->id = cliente->id;
				auxcliente->referencias_bancaria->Add((ReferenciasBancarias*) referencias_bancaria);
				controller->destroyRelation(auxcliente);
            }

			cliente->referencias_bancaria->Delete(i-1);
        }

	helperBancarias->clearCheck();
	gridReferenciasBancarias();
}
//---------------------------------------------------------------------------

void __fastcall TFClientesView::PageControl1Change(TObject *Sender)
{
	PanelOptions->Visible = TRUE;

	if(editar == 1 && (PageControl1->TabIndex == 1 || PageControl1->TabIndex == 2 || PageControl1->TabIndex == 3))
		PanelOptions->Visible = FALSE;
}
//---------------------------------------------------------------------------

