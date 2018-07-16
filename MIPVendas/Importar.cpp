//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Importar.h"
#include "Principal.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFImportar *FImportar;
//---------------------------------------------------------------------------
__fastcall TFImportar::TFImportar(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFImportar::FormCreate(TObject *Sender)
{
/*	//SETA PARÂMETROS SQLConnection1
	SQLConnection1->Params->Values["HostName"]="localhost";
	SQLConnection1->Params->Values["Database"]="loja";
	SQLConnection1->Params->Values["User_Name"]="root";
	SQLConnection1->Params->Values["Password"]="bidu1313";


	if(SQLConnection1->Connected==TRUE)
	{
		SQLConnection1->Close();
		SQLConnection1->Connected=FALSE;
	}

	//CONECTA NO BANCO DE DADOS
	try
	{
		SQLConnection1->Open();
	}
	catch (const Exception &)
	{
		MessageBox(NULL,L"Não foi possivel estabelecer conexão com o servidor",L"Erro de conexão",MB_OK | MB_ICONERROR);
	}

	SQLQuery2->SQLConnection = SQLCONNECT;
	SQLQuery3->SQLConnection = SQLCONNECT;    */
}
//---------------------------------------------------------------------------
void __fastcall TFImportar::Button6Click(TObject *Sender)
{
	UnicodeString QUERY;

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add("SELECT * FROM caixa ORDER BY id ASC");
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		QUERY = "INSERT INTO caixas (codigo,operador,situacao,dinheiro,cartao,cheque,data,hora)";
		QUERY += " VALUES ('";
		QUERY += SQLQuery1->Fields->FieldByName("codigo")->AsString+"','";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,nome FROM usuarios ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("nome")->AsString == SQLQuery1->Fields->FieldByName("operador")->AsString)
				break;
			SQLQuery3->Next();
		}

		QUERY += SQLQuery3->Fields->FieldByName("id")->AsString+"','";

		if(SQLQuery1->Fields->FieldByName("aberto")->AsString == "aberto")
			QUERY += "1','";
		else
			QUERY += "0','";

		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("dinheiro")->AsString))+"','";
		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("cartao")->AsString))+"','";
		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("cheque")->AsString))+"','";
		QUERY += RevertOrd(SQLQuery1->Fields->FieldByName("data")->AsString)+"','";
		QUERY += SQLQuery1->Fields->FieldByName("hora")->AsString+"')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		SQLQuery1->Next();
	}
	MessageBox(NULL,L"SUCESSO",L"SUCESSO",MB_OK | MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TFImportar::Button7Click(TObject *Sender)
{
	UnicodeString QUERY;

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add("SELECT * FROM login ORDER BY id ASC");
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		QUERY = "INSERT INTO usuarios (nome,senha,desconto,permissao)";
		QUERY += " VALUES ('";

		QUERY += SQLQuery1->Fields->FieldByName("nome")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("senha")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("desconto")->AsString+"','";
		QUERY += "255')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		SQLQuery1->Next();

	}
	MessageBox(NULL,L"SUCESSO",L"SUCESSO",MB_OK | MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TFImportar::Button5Click(TObject *Sender)
{
	UnicodeString QUERY;
	TDate data;
	unsigned short y,m,d;

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add("SELECT * FROM vendas WHERE codigo>23722 ORDER BY id ASC");
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		QUERY = "INSERT INTO vendas (codigo_caixa,codigo,vendedor,cliente,modo_pagar,fechamento,valor,data,mes,ano)";
		QUERY += " VALUES ('";
		QUERY += SQLQuery1->Fields->FieldByName("codcaixa")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("codigo")->AsString+"','";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,nome FROM usuarios ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("nome")->AsString == SQLQuery1->Fields->FieldByName("vendedor")->AsString)
				break;
			SQLQuery3->Next();
		}
		QUERY += SQLQuery3->Fields->FieldByName("id")->AsString+"','";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,nome_fantasia,cpf_cnpj FROM clientes ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("nome_fantasia")->AsString == SQLQuery1->Fields->FieldByName("cliente")->AsString || SQLQuery3->Fields->FieldByName("cpf_cnpj")->AsString == SQLQuery1->Fields->FieldByName("cpfcliente")->AsString)
				break;
			SQLQuery3->Next();
		}
		if(SQLQuery3->Fields->FieldByName("id")->AsInteger)
			QUERY += SQLQuery3->Fields->FieldByName("id")->AsString+"','";
		else
			QUERY += "0','";

		if(SQLQuery1->Fields->FieldByName("modpagar")->AsString == "Dinheiro")
			QUERY += "0','";
		else if(SQLQuery1->Fields->FieldByName("modpagar")->AsString == "Cartão")
			QUERY += "1','";
		else if(SQLQuery1->Fields->FieldByName("modpagar")->AsString == "Cheque")
			QUERY += "2','";
		else if(SQLQuery1->Fields->FieldByName("modpagar")->AsString == "Prazo")
			QUERY += "3','";

		if(SQLQuery1->Fields->FieldByName("fechamento")->AsString.Trim()!="")
			QUERY += SQLQuery1->Fields->FieldByName("fechamento")->AsString+"','";
		else
			QUERY += "0','";
		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("precoT")->AsString))+"','";
		if(SQLQuery1->Fields->FieldByName("data")->AsString.Trim()!="")
		{
			QUERY += RevertOrd(SQLQuery1->Fields->FieldByName("data")->AsString)+"','";
			data = SQLQuery1->Fields->FieldByName("data")->AsString;
		}
		else
		{
			QUERY += RevertOrd("22/09/1996")+"','";
			data = TDate("22/09/1996");
        }
		data.DecodeDate(&y,&m,&d);
		QUERY += IntToStr((int)m)+"','";
		QUERY += IntToStr((int)y)+"')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		SQLQuery1->Next();
	}
	MessageBox(NULL,L"SUCESSO",L"SUCESSO",MB_OK | MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TFImportar::Button2Click(TObject *Sender)
{
	UnicodeString QUERY;
	UnicodeString id_cliente;

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add("SELECT * FROM clientes ORDER BY id ASC");
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		QUERY = "INSERT INTO clientes (padrao,indicacao,tipo,razao_social,nome_fantasia,cpf_cnpj,ie_rg,im,contato,telefone,celular,radio,email_financeiro,email_comprador,email_nfe,regiao,bairro,rua,numero,cep,site)";
		QUERY += " VALUES ('";
		QUERY += "0','";
		QUERY += "0','";
		QUERY += "1','";
		QUERY += SQLQuery1->Fields->FieldByName("nome")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("nome")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("cpf")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("rg")->AsString+"','";
		QUERY += "','";
		QUERY += "','";
		QUERY += SQLQuery1->Fields->FieldByName("telefone")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("celular")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("fax")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("email")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("email")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("email")->AsString+"','";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,municipio FROM regioes ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("municipio")->AsString == SQLQuery1->Fields->FieldByName("cidade")->AsString)
				break;
			SQLQuery3->Next();
		}
		if(SQLQuery3->Fields->FieldByName("id")->AsInteger)
			QUERY += SQLQuery3->Fields->FieldByName("id")->AsString+"','";
		else
			QUERY += "11','";

		QUERY += SQLQuery1->Fields->FieldByName("bairro")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("endereco")->AsString+"','";
		QUERY += "','";
		QUERY += SQLQuery1->Fields->FieldByName("cep")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("site")->AsString+"')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		QUERY = "SELECT id AS last_registro FROM clientes ORDER BY id DESC LIMIT 1";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add(QUERY);
		SQLQuery3->Open();
		SQLQuery3->First();
		if(SQLQuery3->Fields->FieldByName("last_registro")->AsInteger)
			id_cliente = SQLQuery3->Fields->FieldByName("last_registro")->AsString;

		QUERY = "INSERT INTO clientes_cobranca (cliente,estado,cidade,bairro,rua,numero,cep,nome,telefone,celular,radio)";
		QUERY += " VALUES ('";
		QUERY += id_cliente+"','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		QUERY = "INSERT INTO clientes_entrega (cliente,estado,cidade,bairro,rua,numero,cep,nome,telefone,celular,radio)";
		QUERY += " VALUES ('";
		QUERY += id_cliente+"','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		QUERY = "INSERT INTO clientes_financeiro (cliente,limite,gasto,situacao,consumidor)";
		QUERY += " VALUES ('";
		QUERY += id_cliente+"','";
		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("limite")->AsString))+"','";
		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("gasto")->AsString))+"','";

		if(SQLQuery1->Fields->FieldByName("bloqueado")->AsString == "sim")
			QUERY += "0','";
		else
			QUERY += "1','";

		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("consumidor")->AsString))+"')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		SQLQuery1->Next();
	}
	MessageBox(NULL,L"SUCESSO",L"SUCESSO",MB_OK | MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TFImportar::Button3Click(TObject *Sender)
{
	UnicodeString QUERY;
	UnicodeString id_cliente;

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add("SELECT * FROM fornecedores ORDER BY id ASC");
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		QUERY = "INSERT INTO fornecedores (padrao,indicacao,tipo,razao_social,nome_fantasia,cpf_cnpj,ie_rg,im,contato,telefone,celular,radio,email_financeiro,email_comprador,email_nfe,regiao,bairro,rua,numero,cep,site)";
		QUERY += " VALUES ('";
		QUERY += "0','";
		QUERY += "0','";
		QUERY += "1','";
		QUERY += SQLQuery1->Fields->FieldByName("nome")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("nome")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("cpf")->AsString+"','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += SQLQuery1->Fields->FieldByName("telefone")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("celular")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("fax")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("email")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("email")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("email")->AsString+"','";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,municipio FROM regioes ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("municipio")->AsString == SQLQuery1->Fields->FieldByName("cidade")->AsString)
				break;
			SQLQuery3->Next();
		}
		if(SQLQuery3->Fields->FieldByName("id")->AsInteger)
			QUERY += SQLQuery3->Fields->FieldByName("id")->AsString+"','";
		else
			QUERY += "11','";

		QUERY += SQLQuery1->Fields->FieldByName("bairro")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("endereco")->AsString+"','";
		QUERY += "','";
		QUERY += SQLQuery1->Fields->FieldByName("cep")->AsString+"','";
		QUERY += "')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		QUERY = "SELECT id AS last_registro FROM fornecedores ORDER BY id DESC LIMIT 1";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add(QUERY);
		SQLQuery3->Open();
		SQLQuery3->First();
		if(SQLQuery3->Fields->FieldByName("last_registro")->AsInteger)
			id_cliente = SQLQuery3->Fields->FieldByName("last_registro")->AsString;

		QUERY = "INSERT INTO fornecedores_cobranca (fornecedor,estado,cidade,bairro,rua,numero,cep,nome,telefone,celular,radio)";
		QUERY += " VALUES ('";
		QUERY += id_cliente+"','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		QUERY = "INSERT INTO fornecedores_entrega (fornecedor,estado,cidade,bairro,rua,numero,cep,nome,telefone,celular,radio)";
		QUERY += " VALUES ('";
		QUERY += id_cliente+"','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		SQLQuery1->Next();
	}
	MessageBox(NULL,L"SUCESSO",L"SUCESSO",MB_OK | MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TFImportar::Button8Click(TObject *Sender)
{
	UnicodeString QUERY;

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add("SELECT id,marca FROM produtos GROUP BY marca ORDER BY id ASC");
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		QUERY = "INSERT INTO produtos_marcas (descricao)";
		QUERY += " VALUES ('";

		QUERY += SQLQuery1->Fields->FieldByName("marca")->AsString.UpperCase()+"')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		SQLQuery1->Next();

	}
	MessageBox(NULL,L"SUCESSO",L"SUCESSO",MB_OK | MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TFImportar::Button1Click(TObject *Sender)
{
	UnicodeString QUERY;
	UnicodeString id_img;
	UnicodeString MARCA,MEDIDA,FORNECEDOR;
	AnsiString ansiSTR;
	int lenght;
	unsigned char *prod_atual,*prod_atual_start,*pMovel,*pMovel_start,*buf,*str;
	int i,j;
	int igual = 0;

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add("SELECT * FROM produtos WHERE id>8103 ORDER BY id ASC");
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{

		igual = 0;
		ansiSTR = SQLQuery1->Fields->FieldByName("foto")->AsString;

		lenght = ansiSTR.Length();

		str = (char*) malloc(lenght*sizeof(char));
		prod_atual = (char*) malloc((2*lenght+3)*sizeof(char));

		buf = str;
		for(i=1;i<=lenght;i++)
				*str++ = ansiSTR[i];

		prod_atual_start = prod_atual;
		*prod_atual++ = '0';
		*prod_atual++ = 'x';
		for(i=0;i<lenght;i++)
		{
			sprintf(prod_atual,"%02x",buf[i]);
			prod_atual = prod_atual + 2;
		}
		*prod_atual = 0;

		if(buf)
			free(buf);

	   /*	SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,foto FROM produtos_imagens ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			ansiSTR = SQLQuery3->Fields->FieldByName("foto")->AsString;

			lenght = ansiSTR.Length();

			str = (char*) malloc(lenght*sizeof(char));
			pMovel = (char*) malloc((2*lenght+3)*sizeof(char));

			buf = str;
			for(i=1;i<=lenght;i++)
					*str++ = ansiSTR[i];

			pMovel_start = pMovel;
			*pMovel++ = '0';
			*pMovel++ = 'x';
			for(i=0;i<lenght;i++)
			{
				sprintf(pMovel,"%02x",buf[i]);
				pMovel = pMovel + 2;
			}
			*pMovel = 0;

			if(buf)
				free(buf);

			if(strcmp(pMovel_start,prod_atual_start) == 0)
			{
				igual = 1;
				id_img = SQLQuery3->Fields->FieldByName("id")->AsString;
			}

			if(pMovel_start)
				free(pMovel_start);

			SQLQuery3->Next();

			if(igual)
				break;
		} */

		if(!igual)
		{
			QUERY = "INSERT INTO produtos_imagens (padrao,foto,tipo)";
			QUERY += " VALUES ('";
			QUERY += "0',";
			QUERY += CharToStr(prod_atual_start)+",'";
			QUERY += SQLQuery1->Fields->FieldByName("tipo")->AsString+"')";

			SQLQuery2->SQL->Clear();
			SQLQuery2->SQL->Add(QUERY);
			SQLQuery2->ExecSQL();

			QUERY = "SELECT id AS last_registro FROM produtos_imagens ORDER BY id DESC LIMIT 1";

			SQLQuery3->SQL->Clear();
			SQLQuery3->SQL->Add(QUERY);
			SQLQuery3->Open();
			SQLQuery3->First();
			if(SQLQuery3->Fields->FieldByName("last_registro")->AsInteger)
				id_img = SQLQuery3->Fields->FieldByName("last_registro")->AsString;
		}


		/*---------------------------MARCA--------------------------------------*/
		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,descricao FROM produtos_marcas ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("descricao")->AsString == SQLQuery1->Fields->FieldByName("marca")->AsString.UpperCase())
				break;
			SQLQuery3->Next();
		}
		if(SQLQuery3->Fields->FieldByName("id")->AsInteger)
			MARCA = SQLQuery3->Fields->FieldByName("id")->AsString;
		else
			MARCA = "0";

		/*---------------------------MEDIDA--------------------------------------*/
		if(SQLQuery1->Fields->FieldByName("medida")->AsString.UpperCase() == "METRO")
			MEDIDA = "4";
		else
			MEDIDA = "3";

		/*---------------------------FORNECEDOR-------------------------------------*/
		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,nome_fantasia FROM fornecedores ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("nome_fantasia")->AsString.UpperCase() == SQLQuery1->Fields->FieldByName("fornecedor")->AsString.UpperCase())
				break;
			SQLQuery3->Next();
		}
		if(SQLQuery3->Fields->FieldByName("id")->AsInteger)
			FORNECEDOR = SQLQuery3->Fields->FieldByName("id")->AsString;
		else
			FORNECEDOR = "0";

		QUERY = "INSERT INTO produtos (nome,preco_compra,preco_venda,marca,medida,categoria,subcategoria,quantidade,tempo_fornecedor,codbarras,codfornecedor,fornecedor,promocao,ncm,cfop,imagem)";
		QUERY += " VALUES ('";
		QUERY += SQLQuery1->Fields->FieldByName("nome")->AsString+"','";
		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("precoC")->AsString))+"','";
		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("precoV")->AsString))+"','";
		QUERY += MARCA+"','";
		QUERY += MEDIDA+"','";
		QUERY += "3','";
		QUERY += "3','";
		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("quantidade")->AsString))+"','";
		QUERY += IntToStr(FStrToInt(SQLQuery1->Fields->FieldByName("tempofornecedor")->AsString))+"','";
		QUERY += SQLQuery1->Fields->FieldByName("codbarras")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("codfornecedor")->AsString+"','";
		QUERY += FORNECEDOR+"','";
		QUERY += "0','";
		QUERY += SQLQuery1->Fields->FieldByName("ncm")->AsString+"','";
		QUERY += SQLQuery1->Fields->FieldByName("cfop")->AsString+"','";
		QUERY += id_img+"')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		SQLQuery1->Next();

		if(prod_atual_start)
			free(prod_atual_start);
	}
	MessageBox(NULL,L"SUCESSO",L"SUCESSO",MB_OK | MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TFImportar::Button10Click(TObject *Sender)
{
	UnicodeString QUERY;
	AnsiString ansiSTR;
	int lenght;
	unsigned char *query,*query_start,*buf,*str;
	int i,j;

	SQLQuery2->SQL->Clear();
	SQLQuery2->SQL->Add("SELECT * FROM produtos_imagens WHERE id='9' ORDER BY id ASC");
	SQLQuery2->Open();
	SQLQuery2->First();
	if(SQLQuery2->Fields->FieldByName("id")->AsInteger)
	{

		ansiSTR = SQLQuery2->Fields->FieldByName("foto")->AsString;

		lenght = ansiSTR.Length();

		str = (char*) malloc(lenght*sizeof(char));
		query = (char*) malloc((2*lenght+3)*sizeof(char));

		buf = str;
		for(i=1;i<=lenght;i++)
				*str++ = ansiSTR[i];

		query_start = query;
		*query++ = '0';
		*query++ = 'x';
		for(i=0;i<lenght;i++)
		{
			sprintf(query,"%02x",buf[i]);
			query = query + 2;
		}
		*query = 0;

		QUERY = "INSERT INTO produtos_imagens (padrao,foto,tipo)";
		QUERY += " VALUES ('";
		QUERY += "2',";
		QUERY += (char*)query_start;
		QUERY += ",'";
		QUERY += "miruca')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();
		ShowMessage("QUERY");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFImportar::Button9Click(TObject *Sender)
{
	UnicodeString QUERY;
	TDate data;
	unsigned short y,m,d;

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add("SELECT * FROM fechamentos ORDER BY id ASC");
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		QUERY = "INSERT INTO fechamentos (codigo,data_fechamento,data_pagamento,modo_pagar,desconto,valor,usuario_fechamento,usuario_pagamento,cliente,situacao,valor_pago)";
		QUERY += " VALUES ('";
		QUERY += SQLQuery1->Fields->FieldByName("codigo")->AsString+"','";
		QUERY += RevertOrd(SQLQuery1->Fields->FieldByName("data")->AsString)+"','";
		if(SQLQuery1->Fields->FieldByName("data_receber")->AsString.Trim()!="")
			QUERY += RevertOrd(SQLQuery1->Fields->FieldByName("data_receber")->AsString)+"','";
		else
			QUERY += RevertOrd("22/09/1996")+"','";

		QUERY += SQLQuery1->Fields->FieldByName("modpagar")->AsString+"','";
		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("desconto")->AsString))+"','";
		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("total")->AsString))+"','";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,nome FROM usuarios ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("nome")->AsString == SQLQuery1->Fields->FieldByName("administrador")->AsString)
				break;
			SQLQuery3->Next();
		}
		QUERY += SQLQuery3->Fields->FieldByName("id")->AsString+"','";


		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,nome FROM usuarios ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("nome")->AsString == SQLQuery1->Fields->FieldByName("administrador_receber")->AsString)
				break;
			SQLQuery3->Next();
		}
		if(SQLQuery3->Fields->FieldByName("id")->AsInteger)
			QUERY += SQLQuery3->Fields->FieldByName("id")->AsString+"','";
		else
			QUERY += "0','";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,nome_fantasia,cpf_cnpj FROM clientes ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("nome_fantasia")->AsString == SQLQuery1->Fields->FieldByName("cliente")->AsString || SQLQuery3->Fields->FieldByName("cpf_cnpj")->AsString == SQLQuery1->Fields->FieldByName("cpfcliente")->AsString)
				break;
			SQLQuery3->Next();
		}
		if(SQLQuery3->Fields->FieldByName("id")->AsInteger)
			QUERY += SQLQuery3->Fields->FieldByName("id")->AsString+"','";
		else
			QUERY += "0','";

		QUERY += SQLQuery1->Fields->FieldByName("recebido")->AsString+"','";
		QUERY += FloatToStr(FStrToFloat(SQLQuery1->Fields->FieldByName("pago")->AsString))+"')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		SQLQuery1->Next();
	}
	MessageBox(NULL,L"SUCESSO",L"SUCESSO",MB_OK | MB_ICONWARNING);
}
//---------------------------------------------------------------------------

void __fastcall TFImportar::Button4Click(TObject *Sender)
{
	UnicodeString QUERY;
	TDate data;
	unsigned short y,m,d;
	UnicodeString id_orcamento,NCM,CFOP,MARCA;
	float preco;
	char *codbarras;
	char *cod;
	int devolucao;
	UnicodeString CODIGO;
	UnicodeString cod_orcamento;

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add("SELECT * FROM orcamentos WHERE codigo>23699 GROUP BY codigo ORDER BY id ASC ");
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		QUERY = "INSERT INTO orcamentos (codigo,data,hora,usuario,atendente,cliente,observacao,vendido)";
		QUERY += " VALUES ('";
		QUERY += SQLQuery1->Fields->FieldByName("codigo")->AsString+"','";
		if(SQLQuery1->Fields->FieldByName("data")->AsString.Trim()!="")
			QUERY += RevertOrd(SQLQuery1->Fields->FieldByName("data")->AsString)+"','";
		else
			QUERY += RevertOrd("22/09/1996")+"','";
		QUERY += "00:00','";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,nome FROM usuarios ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("nome")->AsString == SQLQuery1->Fields->FieldByName("atendente")->AsString)
				break;
			SQLQuery3->Next();
		}
		if(SQLQuery3->Fields->FieldByName("id")->AsInteger)
			QUERY += SQLQuery3->Fields->FieldByName("id")->AsString+"','"+SQLQuery3->Fields->FieldByName("id")->AsString+"','";
		else
			QUERY += "0','0','";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add("SELECT id,nome_fantasia,cpf_cnpj FROM clientes ORDER BY id ASC");
		SQLQuery3->Open();
		SQLQuery3->First();
		while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery3->Fields->FieldByName("nome_fantasia")->AsString == SQLQuery1->Fields->FieldByName("cliente")->AsString || SQLQuery3->Fields->FieldByName("cpf_cnpj")->AsString == SQLQuery1->Fields->FieldByName("cpfcliente")->AsString)
				break;
			SQLQuery3->Next();
		}
		if(SQLQuery3->Fields->FieldByName("id")->AsInteger)
			QUERY += SQLQuery3->Fields->FieldByName("id")->AsString+"','";
		else
			QUERY += "0','";

		QUERY += SQLQuery1->Fields->FieldByName("observacao")->AsString+"','";

		if(SQLQuery1->Fields->FieldByName("vendido")->AsString.Trim() == "sim")
			QUERY += "1')";
		else
			QUERY += "0')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();

		QUERY = "SELECT id AS last_registro FROM orcamentos ORDER BY id DESC LIMIT 1";

		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add(QUERY);
		SQLQuery3->Open();
		SQLQuery3->First();
		if(SQLQuery3->Fields->FieldByName("last_registro")->AsInteger)
			id_orcamento = SQLQuery3->Fields->FieldByName("last_registro")->AsString;

		cod_orcamento = SQLQuery1->Fields->FieldByName("codigo")->AsString.Trim();

		SQLQuery4->SQL->Clear();
		SQLQuery4->SQL->Add("SELECT * FROM orcamentos WHERE codigo='"+cod_orcamento+"' ORDER BY id ASC ");
		SQLQuery4->Open();
		SQLQuery4->First();
		while(SQLQuery4->Fields->FieldByName("id")->AsInteger)
		{
			if(SQLQuery4->Fields->FieldByName("codbarras")->AsString.Trim() != "")
			{
				devolucao = 0;
			 /*	cod = StrToChar(SQLQuery4->Fields->FieldByName("codbarras")->AsString);
				devolucao = VerificarDevolucao(cod,&codbarras);
				if(devolucao)
					CODIGO = codbarras;
				else
					CODIGO = SQLQuery4->Fields->FieldByName("codbarras")->AsString;

				if(codbarras)
					free(codbarras);
				if(cod)
					free(cod);*/
				CODIGO = SQLQuery4->Fields->FieldByName("codbarras")->AsString;
				QUERY = "INSERT INTO orcamentos_produtos (orcamento,id_produto,codbarras,descricao,preco,quantidade,unidade_medida,marca,ncm,cfop,desconto,promocao,devolucao)";
				QUERY += " VALUES ('";
				QUERY += id_orcamento+"','";

				SQLQuery3->SQL->Clear();
				SQLQuery3->SQL->Add("SELECT id,codbarras,ncm,cfop,marca FROM produtos ORDER BY id ASC");
				SQLQuery3->Open();
				SQLQuery3->First();
				while(SQLQuery3->Fields->FieldByName("id")->AsInteger)
				{
					if(SQLQuery3->Fields->FieldByName("codbarras")->AsString == CODIGO)
						break;
					SQLQuery3->Next();
				}
				if(SQLQuery3->Fields->FieldByName("id")->AsInteger)
				{
					QUERY += SQLQuery3->Fields->FieldByName("id")->AsString+"','";
					NCM = SQLQuery3->Fields->FieldByName("ncm")->AsString;
					CFOP = SQLQuery3->Fields->FieldByName("cfop")->AsString;
					MARCA = SQLQuery3->Fields->FieldByName("marca")->AsString;
				}
				else
				{
					QUERY += "0','";
					NCM = "";
					CFOP = "";
					MARCA = "";
				}

				QUERY += SQLQuery4->Fields->FieldByName("codbarras")->AsString+"','";
				QUERY += SQLQuery4->Fields->FieldByName("produto")->AsString+"','";
				preco = FStrToFloat(SQLQuery4->Fields->FieldByName("unitario")->AsString);
				if(preco<0 && devolucao)
					preco*-1;
				QUERY += FloatToStr(preco)+"','";
				QUERY += FloatToStr(FStrToFloat(SQLQuery4->Fields->FieldByName("quantidade")->AsString))+"','";
				if(SQLQuery4->Fields->FieldByName("tipo")->AsString.Trim() == "METRO")
					QUERY += "MT','";
				else
					QUERY += "PÇ','";
				QUERY += MARCA+"','";
				QUERY += NCM+"','";
				QUERY += CFOP+"','";
				QUERY += "0','";
				QUERY += "0','";
				QUERY += IntToStr(devolucao)+"')";

				SQLQuery2->SQL->Clear();
				SQLQuery2->SQL->Add(QUERY);
				SQLQuery2->ExecSQL();
			}

			SQLQuery4->Next();
		}
		SQLQuery1->Next();
	}
	MessageBox(NULL,L"SUCESSO",L"SUCESSO",MB_OK | MB_ICONWARNING);
}
//---------------------------------------------------------------------------
int TFImportar::VerificarDevolucao(char *codbarras,char **codfinal)
{
	char *cod;
	char *aux;
	char str[3];
	int i,n;
	int iR = 0;

	cod = codbarras;

	i = 0;
	n = 0;
	while(*cod)
	{
		if(i < 2)
			str[i++] = *cod++;
		else
		{
			if(!n)
				aux = cod;
			n++;
			*cod++;
		}
	}

	if(n)
	{
		*codfinal = (char*) malloc(n*sizeof(char));
		strcpy(*codfinal,aux);
	}

	str[3] = 0;

	if(strcmp(str,"0x") == 0)
		iR = 1;

	return iR;
}


void __fastcall TFImportar::Button11Click(TObject *Sender)
{
	UnicodeString COD,QUERY;

	SQLQuery2->SQL->Clear();
	SQLQuery2->SQL->Add("SELECT id,codbarras FROM orcamentos_produtos ORDER BY id ASC");
	SQLQuery2->Open();
	SQLQuery2->First();
	while(SQLQuery2->Fields->FieldByName("id")->AsInteger)
	{
		COD = SQLQuery2->Fields->FieldByName("codbarras")->AsString;
		if(COD.Length()>2)
		{
			if(COD[1]=='0' && (COD[2]=='x' || COD[2]=='X'))
			{
				QUERY = "UPDATE orcamentos_produtos SET devolucao='1' WHERE id='"+SQLQuery2->Fields->FieldByName("id")->AsString+"'";
				SQLQuery3->SQL->Clear();
				SQLQuery3->SQL->Add(QUERY);
				SQLQuery3->ExecSQL();
			}
		}
		SQLQuery2->Next();
	}
	ShowMessage("SUCESSO");
}
//---------------------------------------------------------------------------

void __fastcall TFImportar::Button12Click(TObject *Sender)
{
	float f;
	int i;

	f = FStrToFloat("-1fd.ff-..00");//1.00
	i = FStrToInt("-10-dasdsa.0003232423");//10

	ShowMessage("FIM");
}
//---------------------------------------------------------------------------

void __fastcall TFImportar::Button13Click(TObject *Sender)
{
	UnicodeString QUERY;
	TDate data;
	unsigned short y,m,d;

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add("SELECT id,codigo,precoT FROM vendas WHERE precoT<0 ORDER BY id ASC");
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		QUERY = "UPDATE vendas SET valor='"+FormatFloat("#########0.00",FStrToFloat(SQLQuery1->Fields->FieldByName("precoT")->AsString))+"' WHERE codigo='"+SQLQuery1->Fields->FieldByName("codigo")->AsString+"'";
		SQLQuery3->SQL->Clear();
		SQLQuery3->SQL->Add(QUERY);
		SQLQuery3->ExecSQL();

		SQLQuery1->Next();
	}
	MessageBox(NULL,L"SUCESSO",L"SUCESSO",MB_OK | MB_ICONWARNING);

}
//---------------------------------------------------------------------------

