//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LinkarAplicativos.h"
#include "Principal.h"
#include "autoload.h"
#define N 10000
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFLinkarAplicativos *FLinkarAplicativos;
//---------------------------------------------------------------------------
__fastcall TFLinkarAplicativos::TFLinkarAplicativos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFLinkarAplicativos::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);

	SQLQuery1->SQLConnection = SQLCONNECT;
}
//---------------------------------------------------------------------------
void TFLinkarAplicativos::CarregarCampos()
{
	UnicodeString QUERY;
	int i;

	QUERY = "SELECT id,host,nome_bd,usuario_bd,senha_bd,fornecedor_gestao,cnpj_gestao,usuario_gestao,centro_gestao,projeto_gestao,conta_gestao FROM link ORDER BY id ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		EditHost->Text = SQLQuery1->Fields->FieldByName("host")->AsString;
		EditNome->Text = SQLQuery1->Fields->FieldByName("nome_bd")->AsString;
		EditUsuarioBd->Text = SQLQuery1->Fields->FieldByName("usuario_bd")->AsString;
		EditSenhaBd->Text = SQLQuery1->Fields->FieldByName("senha_bd")->AsString;

		if(TestarConexao())
		{
			SQLQuery2->SQLConnection = SQLConnection1;
			CarregarCombos();

			/*----SETAR FORNECEDOR----*/
			for(i=0;i<ComboFornecedor->Items->Count;i++)
			{
				ComboFornecedor->ItemIndex = i;
				if(ComboFornecedor->Text == SQLQuery1->Fields->FieldByName("fornecedor_gestao")->AsString)
					break;
			}

			/*----SETAR USUARIO----*/
			for(i=0;i<ComboUsuario->Items->Count;i++)
			{
				ComboUsuario->ItemIndex = i;
				if(ComboUsuario->Text == SQLQuery1->Fields->FieldByName("usuario_gestao")->AsString)
					break;
			}

			/*----SETAR CENTRO----*/
			for(i=0;i<N;i++)
				if(CENTRO[i] == SQLQuery1->Fields->FieldByName("centro_gestao")->AsInteger)
					break;
			ComboCentro->ItemIndex = i;

			/*----SETAR PROJETO----*/
			for(i=0;i<N;i++)
				if(PROJETO[i] == SQLQuery1->Fields->FieldByName("projeto_gestao")->AsInteger)
					break;
			ComboProjeto->ItemIndex = i;

			/*----SETAR CONTA----*/
			for(i=0;i<N;i++)
				if(CONTA[i] == SQLQuery1->Fields->FieldByName("conta_gestao")->AsInteger)
					break;
			ComboContabil->ItemIndex = i;

		}
		else
		{
			ComboFornecedor->Clear();
			ComboUsuario->Clear();
			ComboCentro->Clear();
			ComboProjeto->Clear();
			ComboContabil->Clear();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFLinkarAplicativos::FormShow(TObject *Sender)
{
    loadCabecalho();
	CarregarCampos();
}
//---------------------------------------------------------------------------
int TFLinkarAplicativos::TestarConexao()
{
	int iR = 1;

	//CONFIGURA SQL
	SQLConnection1->DriverName = "MySQL";

	//SETA PARÂMETROS SQL
	SQLConnection1->Params->Values["HostName"] = EditHost->Text;
	SQLConnection1->Params->Values["Database"] = EditNome->Text;
	SQLConnection1->Params->Values["User_Name"] = EditUsuarioBd->Text;
	SQLConnection1->Params->Values["Password"] = EditSenhaBd->Text;


	if(SQLConnection1->Connected==TRUE)
	{
		SQLConnection1->Close();
		SQLConnection1->Connected = FALSE;
	}

	//CONECTA NO BANCO DE DADOS
	try
	{
		SQLConnection1->Open();
	}
	catch (const Exception &)
	{
		iR = 0;
	}

	return iR;
}
//---------------------------------------------------------------------------
void TFLinkarAplicativos::CarregarCombos()
{
	int i;

	/*---------------------------------FORNECEDOR-----------------------------------*/
	ComboFornecedor->Clear();
	SQLQuery2->SQL->Clear();
	SQLQuery2->SQL->Add("SELECT id,nome,cpf FROM clientes_fornecedores WHERE tipo = '1' ORDER BY nome ASC");
	SQLQuery2->Open();
	SQLQuery2->First();
	for(i = 0; SQLQuery2->Fields->FieldByName("id")->AsInteger != 0; i++)
	{
		ComboFornecedor->Items->Add(SQLQuery2->Fields->FieldByName("nome")->AsString);
		CNPJ[i] = SQLQuery2->Fields->FieldByName("cpf")->AsString;
		SQLQuery2->Next();
	}
	ComboFornecedor->ItemIndex = 0;

	/*---------------------------------USUARIO-----------------------------------*/
	ComboUsuario->Clear();
	SQLQuery2->SQL->Clear();
	SQLQuery2->SQL->Add("SELECT id,nome FROM usuarios ORDER BY nome ASC");
	SQLQuery2->Open();
	SQLQuery2->First();
	for(i = 0; SQLQuery2->Fields->FieldByName("id")->AsInteger != 0; i++)
	{
		ComboUsuario->Items->Add(SQLQuery2->Fields->FieldByName("nome")->AsString);
		SQLQuery2->Next();
	}
	ComboUsuario->ItemIndex = 0;

	/*---------------------------------CENTRO-----------------------------------*/
	ComboCentro->Clear();
	SQLQuery2->SQL->Clear();
	SQLQuery2->SQL->Add("SELECT id,nome FROM centros_custo ORDER BY nome ASC");
	SQLQuery2->Open();
	SQLQuery2->First();
	for(i = 0; SQLQuery2->Fields->FieldByName("id")->AsInteger != 0; i++)
	{
		ComboCentro->Items->Add(SQLQuery2->Fields->FieldByName("nome")->AsString);
		CENTRO[i] = SQLQuery2->Fields->FieldByName("id")->AsInteger;
		SQLQuery2->Next();
	}
	ComboCentro->ItemIndex = 0;

	/*---------------------------------PROJETO-----------------------------------*/
	ComboProjeto->Clear();
	SQLQuery2->SQL->Clear();
	SQLQuery2->SQL->Add("SELECT id,nome FROM projetos ORDER BY nome ASC");
	SQLQuery2->Open();
	SQLQuery2->First();
	for(i = 0; SQLQuery2->Fields->FieldByName("id")->AsInteger != 0; i++)
	{
		ComboProjeto->Items->Add(SQLQuery2->Fields->FieldByName("nome")->AsString);
		PROJETO[i] = SQLQuery2->Fields->FieldByName("id")->AsInteger;
		SQLQuery2->Next();
	}
	ComboProjeto->ItemIndex = 0;

	/*---------------------------------CONTAS-----------------------------------*/
	ComboContabil->Clear();
	SQLQuery2->SQL->Clear();
	SQLQuery2->SQL->Add("SELECT id,nome FROM plano_contas ORDER BY nome ASC");
	SQLQuery2->Open();
	SQLQuery2->First();
	for(i = 0; SQLQuery2->Fields->FieldByName("id")->AsInteger != 0; i++)
	{
		ComboContabil->Items->Add(SQLQuery2->Fields->FieldByName("nome")->AsString);
		CONTA[i] = SQLQuery2->Fields->FieldByName("id")->AsInteger;
		SQLQuery2->Next();
	}
	ComboContabil->ItemIndex = 0;
}

void __fastcall TFLinkarAplicativos::Button2Click(TObject *Sender)
{
		if(TestarConexao())
		{
			SQLQuery2->SQLConnection = SQLConnection1;
            CarregarCombos();
		}
		else
		{
			ComboFornecedor->Clear();
			ComboUsuario->Clear();
			ComboCentro->Clear();
			ComboProjeto->Clear();
			ComboContabil->Clear();
			MessageBox(NULL,L"Desculpe não foi possivel realizar a conexão!",L"Erro de Conexão",MB_OK | MB_ICONERROR);
		}
}
//---------------------------------------------------------------------------

void __fastcall TFLinkarAplicativos::Button1Click(TObject *Sender)
{
	UnicodeString QUERY;

	QUERY = "UPDATE link SET ";

	QUERY += "host='"+EditHost->Text+"',";
	QUERY += "nome_bd='"+EditNome->Text+"',";
	QUERY += "usuario_bd='"+EditUsuarioBd->Text+"',";
	QUERY += "senha_bd='"+EditSenhaBd->Text+"',";
	QUERY += "fornecedor_gestao='"+ComboFornecedor->Text+"',";
	QUERY += "cnpj_gestao='"+CNPJ[ComboFornecedor->ItemIndex]+"',";
	QUERY += "usuario_gestao='"+ComboUsuario->Text+"',";
	QUERY += "centro_gestao='"+IntToStr(CENTRO[ComboCentro->ItemIndex])+"',";
	QUERY += "projeto_gestao='"+IntToStr(PROJETO[ComboProjeto->ItemIndex])+"',";
	QUERY += "conta_gestao='"+IntToStr(CONTA[ComboContabil->ItemIndex])+"'";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->ExecSQL();

	MessageBox(NULL,L"Dados atualizados com sucesso!",L"Atualizar Dados",MB_OK | MB_ICONINFORMATION);

}
//---------------------------------------------------------------------------
void TFLinkarAplicativos::loadCabecalho()
{
//    EmpresaModel *empresa_model = new EmpresaModel();
//	EmpresaEspelho *empresa = empresa_model->selectAll();
//
//	InfoGeraisModel *info_gerais_model = new InfoGeraisModel();
//	InfoGeraisEspelho *info_gerais = info_gerais_model->selectAll();
//
//	LabelCabecalhoTitulo->Caption =  "[LINKAR] " + empresa->getNomeFantasia();
//
//	LabelCabecalhoSubTitulo->Caption =  ToUpper(info_gerais->getSoftwareName());
}


