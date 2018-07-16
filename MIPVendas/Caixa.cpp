//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Caixa.h"
#include "Principal.h"
#include "Bemafi32.h"
#include "PedidosView.h"
#include "autoload.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFCaixa *FCaixa;
//---------------------------------------------------------------------------
__fastcall TFCaixa::TFCaixa(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFCaixa::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);

	SQLQuery1->SQLConnection = SQLCONNECT;
}
//---------------------------------------------------------------------------
void TFCaixa::Designer()
{
	PanelFinalizar->Left = 25;
	PanelFinalizar->Width = PanelFixo->Width - 50;
	PanelFinalizar->Top = PanelFixo->Height - PanelFinalizar->Height - 25;

	PanelProdutos->Left = 25;
	PanelProdutos->Width = PanelFixo->Width - 50;
	PanelProdutos->Top = 25;
	PanelProdutos->Height = PanelFixo->Height - PanelFinalizar->Height - 75;

	PanelDesconto->Left = 25;
	PanelDesconto->Width = PanelVariavel->Width - 50;
	PanelDesconto->Top = PanelVariavel->Height - PanelDesconto->Height - 25;

	PanelPagamento->Left = 25;
	PanelPagamento->Width = PanelVariavel->Width - 50;
	PanelPagamento->Top = 25;
	PanelPagamento->Height = PanelVariavel->Height - PanelDesconto->Height - 75;
}
//--------------------------------------------------------------------------
void TFCaixa::InicializarCampos()
{
	UnicodeString QUERY;

	/*--------------------------PEGAR O ESTADO DO CAIXA--------------------------*/
	QUERY = "SELECT CA.id AS id,CA.codigo AS codigo,CA.situacao AS situacao,CA.data AS data,CA.hora AS hora,CA.operador AS id_operador,U.id AS id_cl,U.nome AS operador FROM caixas AS CA INNER JOIN usuarios AS U ON (CA.operador = U.id) ORDER BY CA.codigo DESC LIMIT 1";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
		STATE = SQLQuery1->Fields->FieldByName("situacao")->AsInteger;

	if(!STATE)
	{
		CODIGO_CAIXA = 0;
		ButtonAbrirFechar->Caption = "ABRIR CAIXA (F1)";
		LabelState->Caption = "CAIXA FECHADO";
		LabelCodigo->Caption = "Código: ";
		LabelOperador->Caption = "Operador: ";
		LabelData->Caption = "Data: ";
		LabelHorario->Caption = "Horário: ";
	}
	else
	{
		OPERADOR = SQLQuery1->Fields->FieldByName("operador")->AsString;
		CODIGO_CAIXA = SQLQuery1->Fields->FieldByName("codigo")->AsInteger;
		ButtonAbrirFechar->Caption = "FECHAR CAIXA (F1)";
		LabelState->Caption = "CAIXA ABERTO";
		LabelCodigo->Caption = "Código: "+IntToStr(CODIGO_CAIXA);
		LabelOperador->Caption = "Operador: "+OPERADOR;
		LabelData->Caption = "Data: "+SQLQuery1->Fields->FieldByName("data")->AsString;
		LabelHorario->Caption = "Horário: "+SQLQuery1->Fields->FieldByName("hora")->AsString;
	}

	CalcularSaldo(STATE);
}
void __fastcall TFCaixa::FormShow(TObject *Sender)
{
    loadCabecalho();
	Designer();
	InicializarCampos();
	GerarGrid();
}
//---------------------------------------------------------------------------
void TFCaixa::GerarGrid()
{
	UnicodeString QUERY,MODO;
	int numerodalinha,i,j,cc,rc;

	rc = StringGrid1->RowCount;
	cc = StringGrid1->ColCount;
	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
		StringGrid1->Cells[j][i] = "";

	numerodalinha = 1;
	// ESTRUTURA StringGrid1
	StringGrid1->Options << goRowSelect;
	StringGrid1->ScrollBars = ssVertical;
	StringGrid1->Rows[1]->Clear();
	StringGrid1->RowCount = 0;
	StringGrid1->ColCount = 6;
	StringGrid1->FixedCols = 0;
	StringGrid1->ColWidths[0] = ((StringGrid1->Width)/6);
	StringGrid1->ColWidths[1] = ((StringGrid1->Width)/6);
	StringGrid1->ColWidths[2] = ((StringGrid1->Width)/6);
	StringGrid1->ColWidths[3] = ((StringGrid1->Width)/6);
	StringGrid1->ColWidths[4] = ((StringGrid1->Width)/6);
	StringGrid1->ColWidths[5] = ((StringGrid1->Width)/6);
	StringGrid1->Cols[0]->Add("CÓDIGO");
	StringGrid1->Cols[1]->Add("DATA");
	StringGrid1->Cols[2]->Add("CLIENTE");
	StringGrid1->Cols[3]->Add("VENDEDOR");
	StringGrid1->Cols[4]->Add("MODO DE PAGAR");
	StringGrid1->Cols[5]->Add("VALOR");
	// ESTRUTURA StringGrid1


	if(STATE)
	{
		QUERY = "SELECT V.id AS id,V.codigo_caixa AS codigo_caixa,V.codigo AS codigo,V.vendedor AS id_vendedor,V.cliente AS id_cliente,V.modo_pagar AS modo_pagar,V.data AS data,V.valor AS valor,C.id AS id_c,C.nome_fantasia AS cliente,U.id AS id_u,U.nome AS vendedor FROM vendas AS V INNER JOIN clientes AS C ON (V.cliente = C.id) INNER JOIN usuarios AS U ON (V.vendedor = U.id) WHERE (V.codigo_caixa = '"+IntToStr(CODIGO_CAIXA)+"') ORDER BY V.codigo ASC";

		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->Open();
		SQLQuery1->First();
		while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
		{
			switch(SQLQuery1->Fields->FieldByName("modo_pagar")->AsInteger)
			{
				case 0:
					MODO = "DINHEIRO";
				break;
				case 1:
					MODO = "CARTÃO";
				break;
				case 2:
					MODO = "CHEQUE";
				break;
				case 3:
					MODO = "CARTEIRA";
				break;
				case 4:
					MODO = "VALE";
				break;
			}

			StringGrid1->Cells[0][numerodalinha] = SQLQuery1->Fields->FieldByName("codigo")->AsString;
			StringGrid1->Cells[1][numerodalinha] = SQLQuery1->Fields->FieldByName("data")->AsString;
			StringGrid1->Cells[2][numerodalinha] = SQLQuery1->Fields->FieldByName("cliente")->AsString;
			StringGrid1->Cells[3][numerodalinha] = SQLQuery1->Fields->FieldByName("vendedor")->AsString;
			StringGrid1->Cells[4][numerodalinha] = MODO;
			StringGrid1->Cells[5][numerodalinha] = FormatFloat("#,###,###,##0.00",SQLQuery1->Fields->FieldByName("valor")->AsFloat);
			StringGrid1->RowCount++;
			SQLQuery1->Next();
			numerodalinha++;
			if (numerodalinha == 2)
				StringGrid1->FixedRows = 1;
		}
		if (numerodalinha <= 1)
			StringGrid1->RowCount++;
	}
	else
		StringGrid1->RowCount++;
}
//---------------------------------------------------------------------------
void __fastcall TFCaixa::ButtonAbrirFecharClick(TObject *Sender)
{
	if(STATE)
		FecharCaixa();
	else
		AbrirCaixa();
}
//---------------------------------------------------------------------------
void TFCaixa::AbrirCaixa()
{
	TDate DATE;
	UnicodeString QUERY;

	DATE = Now();
	/*--------------------------PEGAR ULTIMO CÓDIGO--------------------------*/
	QUERY = "SELECT id,codigo FROM caixas ORDER BY codigo DESC LIMIT 1";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
		CODIGO_CAIXA = SQLQuery1->Fields->FieldByName("codigo")->AsInteger + 1;

	/*--------------------------INSERE O CODIGO NO BD--------------------------*/
	QUERY = "INSERT INTO caixas (codigo,operador,situacao,data,hora)";
	QUERY += " VALUES ('";
	QUERY += IntToStr(CODIGO_CAIXA)+"','";
	QUERY += IntToStr(USUARIO)+"','";
	QUERY += "1','";
	QUERY += RevertOrd(DATE.DateString())+"','";
	QUERY += DATE.TimeString()+"')";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->ExecSQL();

	InicializarCampos();
	GerarGrid();
}
//---------------------------------------------------------------------------
void TFCaixa::FecharCaixa()
{
	UnicodeString QUERY;

	if(MessageBox(NULL,L"Tem certeza que deseja FECHAR o caixa?",L"Fechar Caixa",MB_YESNO | MB_ICONWARNING) == 6)
	{
		/*--------------------------MODIFICA CAIXA--------------------------------*/
		QUERY = "UPDATE caixas SET ";

		QUERY += "dinheiro='"+FloatToStr(FStrToFloat(EditSaldoDinheiro->Text))+"',";
		QUERY += "cartao='"+FloatToStr(FStrToFloat(EditSaldoCartao->Text))+"',";
		QUERY += "cheque='"+FloatToStr(FStrToFloat(EditSaldoCheque->Text))+"',";
		QUERY += "situacao='0'";

		QUERY += " WHERE codigo='"+IntToStr(CODIGO_CAIXA)+"'";

		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->ExecSQL();

		InserirMIPGestao();
		ImprimirRelatorio();
		InicializarCampos();
		GerarGrid();
	}
}
//---------------------------------------------------------------------------
void TFCaixa::ExtornarVenda()
{
	TDate data;
	UnicodeString QUERY;
	int carteira = 0;
	int situacao;
	int cliente;
    float limite,gasto;
	float valor_carteira = 0;
	unsigned short year,month,day;

	data = Now();
	data.DecodeDate(&year,&month,&day);

	if(rowselect> 0 && StringGrid1->Cells[0][rowselect].Trim()!="")
	{
		//PROUCURAR CARTEIRA
		QUERY = "SELECT id,codigo,modo_pagar,cliente,SUM(valor) AS carteira FROM vendas WHERE modo_pagar ='3' AND codigo='"+StringGrid1->Cells[0][rowselect]+"' ORDER BY id DESC";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->Open();
		SQLQuery1->First();
		if(SQLQuery1->Fields->FieldByName("id")->AsInteger != 0)
		{
			carteira = 1;
			valor_carteira = SQLQuery1->Fields->FieldByName("carteira")->AsFloat;
			cliente  = SQLQuery1->Fields->FieldByName("cliente")->AsInteger;
		}

		//VERIFICA SE O CLIENTE ESTÁ LIBERADO NO CASO DE CARTERA
		if(carteira)
		{
			QUERY = "SELECT id,cliente,limite,gasto,situacao FROM clientes_financeiro WHERE cliente='"+IntToStr(cliente)+"' ORDER BY id ASC LIMIT 1";
			SQLQuery1->SQL->Clear();
			SQLQuery1->SQL->Add(QUERY);
			SQLQuery1->Open();
			SQLQuery1->First();
			if(SQLQuery1->Fields->FieldByName("id")->AsInteger != 0)
			{
				limite = SQLQuery1->Fields->FieldByName("limite")->AsFloat;
				gasto = SQLQuery1->Fields->FieldByName("gasto")->AsFloat;

				gasto = gasto - valor_carteira;

				if(gasto < limite)
					situacao = 1;
			}
		}

		//ATUALIZA O GASTO NO CASA DE CARTEIRA
		if(carteira)
		{
			QUERY = "UPDATE clientes_financeiro SET gasto = gasto - '"+FloatToStr(valor_carteira)+"',situacao='"+IntToStr(situacao)+"' WHERE cliente='"+IntToStr(cliente)+"'";
			SQLQuery1->SQL->Clear();
			SQLQuery1->SQL->Add(QUERY);
			SQLQuery1->ExecSQL();
		}

		//ATUALIZA O ORÇAMENTO PARA NÃO VENDIDO
		QUERY = "UPDATE orcamentos SET vendido='0' WHERE codigo='"+StringGrid1->Cells[0][rowselect]+"'";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->ExecSQL();

		CarregarProdutos();
		//RETIRA DO ESTOQUE OS PRODUTOS
		if(TabelaProdutosNo)
		{
			TabelaProdutosMovel = TabelaProdutosNo;
			while(TabelaProdutosMovel)
			{
				QUERY = "UPDATE produtos SET quantidade = quantidade + "+FloatToStr(TabelaProdutosMovel->quantidade)+" WHERE codbarras='"+CharToStr(TabelaProdutosMovel->codbarras)+"'";
				SQLQuery1->SQL->Clear();
				SQLQuery1->SQL->Add(QUERY);
				SQLQuery1->ExecSQL();

				TabelaProdutosMovel = TabelaProdutosMovel->proximo;
			}
		}

		//DELETA VENDA
		QUERY = "DELETE FROM vendas WHERE codigo = '"+StringGrid1->Cells[0][rowselect]+"'";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->ExecSQL();

		MessageBox(NULL,L"Venda extornada com sucesso!",L"Extornar Venda",MB_OK | MB_ICONINFORMATION);

		GerarGrid();
	}
	else
	MessageBox(NULL,L"Selecione uma venda válida!",L"Extornar Venda",MB_OK | MB_ICONERROR);
}
//--------------------------------------------------------------------------
void TFCaixa::ReducaoZ()
{
	TDate DATE;
	char *data,*hora;
	int iR;

	DATE = Now();

	data = StrToChar(DATE.DateString());
	hora = StrToChar(DATE.TimeString());

	iR = Bematech_FI_ReducaoZ(data,hora);

	if(iR!=1)
		AnalisaRetorno(iR, L"REDUÇÃO Z ERROR", "", "");

	free(data);
	free(hora);
}
//--------------------------------------------------------------------------
void TFCaixa::LeituraX()
{
	int iR;

	iR = Bematech_FI_LeituraX();

	if(iR!=1)
		AnalisaRetorno(iR, L"LEITURA X ERROR", "", "");
}
//--------------------------------------------------------------------------
void __fastcall TFCaixa::ButtonLeituraXClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja realizar a LEITURA X?",L"Leitura X",MB_YESNO | MB_ICONWARNING) == 6)
		LeituraX();
}
//---------------------------------------------------------------------------

void __fastcall TFCaixa::ButtonReducaoZClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja realizar a REDUÇÃO Z?",L"Reduão Z",MB_YESNO | MB_ICONWARNING) == 6)
		ReducaoZ();
}
//---------------------------------------------------------------------------

void __fastcall TFCaixa::ButtonExtornarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja extornar essa venda?",L"Extornar Venda",MB_YESNO | MB_ICONWARNING) == 6)
		ExtornarVenda();
}
//---------------------------------------------------------------------------
void TFCaixa::ImprimirRelatorio()
{
//	int i,c;
//	int a,b;
//	int *_b,*_a;
//	int n,m;
//	int y,h;
//	int e;
//	int item;
//	UnicodeString NOME_EMPRESA = "";
//	UnicodeString CPF_EMPRESA = "";
//	UnicodeString ENDERECO_EMPRESA = "";
//	UnicodeString NUMERO_EMPRESA = "";
//	UnicodeString BAIRRO_EMPRESA = "";
//	UnicodeString CEP_EMPRESA = "";
//	UnicodeString CIDADE_EMPRESA = "";
//	UnicodeString ESTADO_EMPRESA = "";
//	UnicodeString EMAIL_EMPRESA = "";
//	UnicodeString IE_EMPRESA = "";
//	UnicodeString TELEFONE_EMPRESA = "";
//	UnicodeString SITE_EMPRESA = "";
//	TJPEGImage *LOGO_EMPRESA;
//
//	 PEGAR INFORMAÇÕES EMPRESA
//	EmpresaModel *empresa_model = new EmpresaModel();
//	EmpresaEspelho *empresa = empresa_model->selectAll();
//	RegioesModel *regiao_model = new RegioesModel();
//	RegioesEspelho *regiao = regiao_model->selectById(StrToInt(empresa->getRegiao()));
//	ConfigOrcamentoEspelho *config_orcamento = ConfigOrcamentoModel::selectAll();
//
//	 PEGAR INFORMAÇÕES EMPRESA
//	NOME_EMPRESA = empresa->getRazaoSocial();
//	CPF_EMPRESA = empresa->getCpfCnpj();
//	TELEFONE_EMPRESA = empresa->getTelefone();
//	ESTADO_EMPRESA = regiao->getUf();
//	CIDADE_EMPRESA = regiao->getMunicipio();
//	ESTADO_EMPRESA = regiao->getNomeUf();
//	CIDADE_EMPRESA = regiao->getMunicipio();
//	BAIRRO_EMPRESA = empresa->getBairro();
//	ENDERECO_EMPRESA = empresa->getRua();
//	NUMERO_EMPRESA = empresa->getNumero();
//	CEP_EMPRESA = empresa->getCep();
//	EMAIL_EMPRESA = empresa->getEmailFinanceiro();
//	SITE_EMPRESA = empresa->getSite();
//	IE_EMPRESA = empresa->getIeRg();
//	LOGO_EMPRESA = empresa->getLogo();

//	/*-----------------------------ESTRUTURA DA IMPRESSAO----------------------------------*/
//	c = StringGrid1->RowCount;
//	a = 50 ; //intervalo a-b
//	b = 4750 ; //intervalo a-b
//	n = StringGrid1->ColCount;//numero de colunas
//	m = b-a; // modulo do intervalo
//	y = 100; //altura inicial
//	h = 110; //largura da linha
//	e = 10; //espacamento da borda do retangulo
//
//	_a = (int *) malloc(n*sizeof(int));
//	_b = (int *) malloc(n*sizeof(int));
//
//	TAMANHO PROPORCAO COM O MODULO DO INTERVALO
//	_b[0] = a + m/n;
//	_b[1] = _b[0] + m/n;
//	_b[2] = _b[1] + m/n;
//	_b[3] = _b[2] + m/n;
//	_b[4] = _b[3] + m/n;
//	_b[5] = _b[4] + m/n;
//
//	_a[0] = a;
//	for(i=1;i<n;i++)
//		_a[i] = _b[i-1];
//
//	if (PrintDialog1->Execute())
//	{
//		Printer()->BeginDoc();
//		Printer()->Canvas->Pen->Color = clBlack;
//		Printer()->Canvas->Font->Color = clBlack;
//		Printer()->Canvas->Brush->Color = clWhite;
//		Printer()->Canvas->Font->Size = 7;
//		Printer()->Canvas->Font->Style = TFontStyles() << fsBold;
//
//		 CABEÇALHO
//		Printer()->Canvas->Rectangle(a, y - e, b, y + 5*h);
//		Printer()->Canvas->TextOutW(a + e, y,NOME_EMPRESA);
//		Printer()->Canvas->TextOutW(a + e, y + 1*h, L"CNPJ: "+CPF_EMPRESA);
//		Printer()->Canvas->TextOutW(a + e, y + 2*h, ENDERECO_EMPRESA + ", "+ NUMERO_EMPRESA + " - " + BAIRRO_EMPRESA);
//		Printer()->Canvas->TextOutW(a + e, y + 3*h, L"CEP: "+CEP_EMPRESA);
//		Printer()->Canvas->TextOutW(a + e, y + 4*h,L"EMAIL: "+EMAIL_EMPRESA);
//
//		Printer()->Canvas->TextOutW(2000, y + h,L"INSC.EST: "+IE_EMPRESA);
//		Printer()->Canvas->TextOutW(2000, y + 2*h, L"CIDADE/ESTADO: "+CIDADE_EMPRESA + "/" + ESTADO_EMPRESA);
//		Printer()->Canvas->TextOutW(2000, y + 3*h,L"FONE: "+TELEFONE_EMPRESA);
//		Printer()->Canvas->TextOutW(2000, y + 4*h,L"SITE: "+SITE_EMPRESA);
//
//		Printer()->Canvas->StretchDraw(Rect(3400, y + h, b - 2*e, y + 4*h),LOGO_EMPRESA);
//
//		y = y + 5*h;
//
//		 TITULO
//		Printer()->Canvas->Brush->Color = clBtnFace;
//		Printer()->Canvas->Rectangle(a, y, b, y + h);
//		Printer()->Canvas->TextOutW(2150, y + e, "FECHAMENTO DE CAIXA");
//		Printer()->Canvas->Brush->Color = clWhite;
//
//		y = y + h;
//
//		 INFORMAÇOES FECHAMENTO
//		Printer()->Canvas->Font->Style = TFontStyles() << fsBold;
//
//		Printer()->Canvas->TextOutW(a + e, y + e,L"CÓDIGO: " + IntToStr(CODIGO_CAIXA));
//		Printer()->Canvas->TextOutW(1500, y + e,L"OPERADOR: " + OPERADOR);
//
//		y = y + h;
//
//		 VENDAS
//		item = 0;
//		for (i=0;i<c;i++)
//		{
//			Printer()->Canvas->Font->Style = TFontStyles() >> fsBold;
//			Printer()->Canvas->Font->Color = clBlack;
//			Printer()->Canvas->Brush->Color = clWhite;
//			if(i == 0)
//				Printer()->Canvas->Font->Style = TFontStyles() << fsBold;
//			/*------------------------RETANGULOS------------------------------------------*/
//			Printer()->Canvas->Rectangle(_a[0], y, _b[0], y + h);
//			Printer()->Canvas->Rectangle(_a[1], y, _b[1], y + h);
//			Printer()->Canvas->Rectangle(_a[2], y, _b[2], y + h);
//			Printer()->Canvas->Rectangle(_a[3], y, _b[3], y + h);
//			Printer()->Canvas->Rectangle(_a[4], y, _b[4], y + h);
//			Printer()->Canvas->Rectangle(_a[5], y, _b[5], y + h);
//
//			/*------------------------TEXTOS DAS LINHAS-----------------------------------------*/
//			Printer()->Canvas->Brush->Color = clWhite;
//			Printer()->Canvas->TextOutW(_a[0] + e, y + e, StringGrid1->Cells[0][i]);
//			Printer()->Canvas->TextOutW(_a[1] + e, y + e, StringGrid1->Cells[1][i]);
//			Printer()->Canvas->TextOutW(_a[2] + e, y + e, StringGrid1->Cells[2][i].SubString(0,20));
//			Printer()->Canvas->TextOutW(_a[3] + e, y + e, StringGrid1->Cells[3][i]);
//			Printer()->Canvas->TextOutW(_a[4] + e, y + e, StringGrid1->Cells[4][i]);
//			Printer()->Canvas->TextOutW(_a[5] + e, y + e, StringGrid1->Cells[5][i]);
//
//			y = y + h;
//			item++;
//
//			if(item>39)
//			{
//				Printer()->NewPage();
//				item = 0;
//			}
//		}
//
//		 TOTAIS
//		Printer()->Canvas->Font->Style = TFontStyles() << fsBold;
//		Printer()->Canvas->Brush->Color = TColor(0xffffff);
//		/*------------------------RETANGULOS------------------------------------------*/
//		Printer()->Canvas->Rectangle(_a[4], y, _b[4], y + h);
//		Printer()->Canvas->Rectangle(_a[5], y, _b[5], y + h);
//
//		y = y + h;
//
//		/*------------------------RETANGULOS------------------------------------------*/
//		Printer()->Canvas->Brush->Color = clBtnFace;
//		Printer()->Canvas->Rectangle(_a[4], y, _b[4], y + h);
//		Printer()->Canvas->Rectangle(_a[5], y, _b[5], y + h);
//
//		Printer()->Canvas->TextOutW(_a[4] + e, y + e, "DINHEIRO");
//		Printer()->Canvas->TextOutW(_a[5] + e, y + e,EditSaldoDinheiro->Text);
//
//		y = y + h;
//
//		/*------------------------RETANGULOS------------------------------------------*/
//		Printer()->Canvas->Rectangle(_a[4], y, _b[4], y + h);
//		Printer()->Canvas->Rectangle(_a[5], y, _b[5], y + h);
//
//		Printer()->Canvas->TextOutW(_a[4] + e, y + e, "CARTAO");
//		Printer()->Canvas->TextOutW(_a[5] + e, y + e,EditSaldoCartao->Text);
//
//		y = y + h;
//
//		/*------------------------RETANGULOS------------------------------------------*/
//		Printer()->Canvas->Rectangle(_a[4], y, _b[4], y + h);
//		Printer()->Canvas->Rectangle(_a[5], y, _b[5], y + h);
//
//		Printer()->Canvas->TextOutW(_a[4] + e, y + e, "CHEQUE");
//		Printer()->Canvas->TextOutW(_a[5] + e, y + e,EditSaldoCheque->Text);
//
//		y = y + h;
//
//		/*------------------------RETANGULOS------------------------------------------*/
//		Printer()->Canvas->Rectangle(_a[4], y, _b[4], y + h);
//		Printer()->Canvas->Rectangle(_a[5], y, _b[5], y + h);
//
//		Printer()->Canvas->TextOutW(_a[4] + e, y + e, "T O T A L");
//		Printer()->Canvas->TextOutW(_a[5] + e, y + e,EditSaldoTotal->Text);
//
//		y = y + h + e;
//		Printer()->EndDoc();
//	}
//
//
//	if(_a)
//		free(_a);
//
//	if(_b)
//		free(_b);
}
//---------------------------------------------------------------------------
void TFCaixa::AnalisaRetorno(int Retorno, const wchar_t * TituloJanela, char * Mensagem, char * Informacao)
{
	int  RetornoStatus = 0;   // retorno da função que le o status da impressora
    int  ACK, ST1, ST2 = 0;   // variáveis de status da impressora
	char StringStatus[12];    // status da impressora em string (ACK, ST1, ST2)
    //char StringRetorno[450];  // descrição por extenso dos status da impressora + StatusString (450 posicoes)
    char *StringRetorno;      // descrição por extenso dos status da impressora + StatusString (450 posicoes)
    int Tamanho = 0;          // qtde de bytes que devem ser alocados para a variável StringRetorno

    ACK = 0; ST1 = 0; ST2 = 0;
    //memset( StringRetorno, 0, 450 );
    memset( StringStatus,  0,  12 );

    Tamanho = strlen( Mensagem ) + strlen( Informacao ) + 450 + 5; // tamanho da var. Mensagem + tam. da var. Informacao + 450 (descrição por extenso dos status da impressora + StatusString) + 5 ( LF + nulo )

    // tenta alocar memória pra variável StringRetorno, se der erro retorna
    if ( ( StringRetorno = new char[ Tamanho ] ) == NULL )
        return;

    memset( StringRetorno, '\0', Tamanho );

    switch( Retorno)
    {
        case 0:      // erro de comunicação
			Application->MessageBox(L"Erro de comunicação com a impressora", TituloJanela, MB_OK);
			break;

		case -1:      // erro de execução
			Application->MessageBox(L"Erro de execução da função", TituloJanela, MB_OK);
			break;

		case -2:      // parâmetro inválido
			Application->MessageBox(L"Parâmetro inválido na função", TituloJanela, MB_OK);
			break;

		case -3:      // alíquota não programada
			Application->MessageBox(L"Alíquota não programada", TituloJanela, MB_OK);
			break;

		case -4:      // Arquivo de inicialização BemaFI32.ini não foi encontrado
			Application->MessageBox(L"O arquivo de inicialização BemaFI32.ini não foi encontrado", TituloJanela, MB_OK);
			break;

		case -5:      // erro na abertura da porta serial
			Application->MessageBox(L"Erro ao tentar abrir a porta de comunicação", TituloJanela, MB_OK);
			break;

		case -6:      // impressora desligada ou cabo desconectado
			Application->MessageBox(L"impressora desligada ou cabo de comunicação desconectado", TituloJanela, MB_OK);
			break;

		case -7:      // banco não encontrado no arquivo 'BemaFI32.ini'
			Application->MessageBox(L"banco não encontrado no arquivo 'BemaFI32.ini'", TituloJanela, MB_OK);
			break;

		case -8:      // erro ao criar ou gravar no arquivo 'Status.txt'ou 'Retorno.txt'
			Application->MessageBox(L"Erro ao criar ou gravar no arquivo 'Status.txt'ou 'Retorno.txt'", TituloJanela, MB_OK);
			break;

		case 1:
			// le o status da impressora
			Retorno = Bematech_FI_RetornoImpressora( &ACK, &ST1, &ST2);

			if ( ACK == 21 )
			{
				Application->MessageBox(L"Status da impressora: 21 \n Comando não executado", TituloJanela, MB_OK);
				return;
			}

			if ( ST1 != 0 || ST2 != 0 )
			{
				sprintf( StringRetorno, "%s%d,%d,%d\n", "Status da Impressora: ", ACK, ST1, ST2 );

				if ( ST1 >= 128 )
				{
					strcat( StringRetorno, "Fim de Papel\n" );
					ST1 -= 128;
                }

                if ( ST1 >= 64 )
                {
                    strcat( StringRetorno, "Pouco Papel\n" );
                    ST1 -= 64;
                }

                if ( ST1 >= 32 )
                {
                    strcat( StringRetorno, "Erro no relógio\n" );
                    ST1 -= 32;
                }

                if ( ST1 >= 16 )
                {
                    strcat( StringRetorno, "Impressora em erro\n" );
                    ST1 -= 16;
                }

                if ( ST1 >= 8 )
                {
                    strcat( StringRetorno, "Primeiro dado do comando não foi Esc\n" );
                    ST1 -= 8;
                }

                if ( ST1 >= 4 )
                {
                    strcat( StringRetorno, "Comando inexistente\n" );
                    ST1 -= 4;
                }

                if ( ST1 >= 2 )
                {
                    strcat( StringRetorno, "Cupom fiscal aberto\n" );
                    ST1 -= - 2;
                }

                if ( ST1 >= 1 )
                {
                    strcat( StringRetorno, "Número de parâmetros inválido no comando\n" );
                    ST1 -= - 1;
                }

                if ( ST2 >= 128 )
                {
                    strcat( StringRetorno, "Tipo de Parâmetro de comando inválido\n" );
                    ST2 -= 128;
                }

                if ( ST2 >= 64 )
                {
                    strcat( StringRetorno, "Memória fiscal lotada\n" );
                    ST2 -= 64;
                }

                if ( ST2 >= 32 )
                {
                    strcat( StringRetorno, "Erro na CMOS\n" );
                    ST2 -= 32;
                }

                if ( ST2 >= 16 )
                {
                    strcat( StringRetorno, "Alíquota não programada\n" );
                    ST2 -= 16;
                }

                if ( ST2 >= 8 )
                {
                    strcat( StringRetorno, "Capacidade de alíquota programáveis lotada\n" );
                    ST2 -= 8;
                }

                if ( ST2 >= 4 )
                {
                    strcat( StringRetorno, "Cancelamento não permitido\n" );
                    ST2 -= 4;
                }

                if ( ST2 >= 2 )
                {
                    strcat( StringRetorno, "CGC/IE do proprietário não programados\n" );
                    ST2 -= 2;
                }

                if ( ST2 >= 1 )
                {
                    strcat( StringRetorno, "Comando não executado\n" );
                    ST2 -= 1;
                }

            } //fim do ST1 <> 0 and ST2 <> 0

            // se houver informação pra ser mostrada, concatena com o status
            if ( strlen( Mensagem ) > 0 || strlen( Informacao ) > 0 )
                sprintf( StringRetorno + strlen( StringRetorno ), "\n%s%s", Mensagem, Informacao );

            // se houver alguma informação mostra em tela
			UnicodeString sr;
			if ( strlen( StringRetorno ) > 0 )
			{
				sr=StringRetorno;
				Application->MessageBox(sr.c_str(), TituloJanela, MB_OK);
			}
            break;

    } // end switch
}
//-----------------------------------------------------
void TFCaixa::CalcularSaldo(int state)
{
	UnicodeString QUERY;
	float total,dinheiro,cartao,cheque,carteira;
	int i,mod;

	dinheiro = cartao = cheque = carteira = 0;
	if(state)
	{
		QUERY = "SELECT id,modo_pagar,SUM(valor) AS saldo FROM vendas WHERE codigo_caixa='"+IntToStr(CODIGO_CAIXA)+"' GROUP BY modo_pagar ORDER BY codigo ASC";

		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->Open();
		SQLQuery1->First();
		while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
		{
			mod = SQLQuery1->Fields->FieldByName("modo_pagar")->AsInteger;
			switch(mod)
			{
				case 0:
					dinheiro = dinheiro + SQLQuery1->Fields->FieldByName("saldo")->AsFloat;
				break;
				case 1:
					cartao = cartao + SQLQuery1->Fields->FieldByName("saldo")->AsFloat;
				break;
				case 2:
					cheque = cheque + SQLQuery1->Fields->FieldByName("saldo")->AsFloat;
				break;
				case 3:
					carteira = carteira + SQLQuery1->Fields->FieldByName("saldo")->AsFloat;
				break;
			}
			SQLQuery1->Next();
		}
		for(i=0;i<4;i++)
			switch(i)
			{
				case 0:
					EditSaldoDinheiro->Text = FormatFloat("#,###,###,##0.00",dinheiro);
				break;
				case 1:
					EditSaldoCartao->Text = FormatFloat("#,###,###,##0.00",cartao);
				break;
				case 2:
					EditSaldoCheque->Text = FormatFloat("#,###,###,##0.00",cheque);
				break;
				case 3:
					EditSaldoCarteira->Text = FormatFloat("#,###,###,##0.00",carteira);
				break;
			}
		total = dinheiro + cartao + cheque;
		EditSaldoTotal->Text = FormatFloat("#,###,###,##0.00",total);
	}
	else
	{
		EditSaldoTotal->Text = FormatFloat("#,###,###,##0.00",0);
		EditSaldoDinheiro->Text = FormatFloat("#,###,###,##0.00",0);
		EditSaldoCartao->Text = FormatFloat("#,###,###,##0.00",0);
		EditSaldoCheque->Text = FormatFloat("#,###,###,##0.00",0);
		EditSaldoCarteira->Text = FormatFloat("#,###,###,##0.00",0);
	}
}
//----------------------------
void TFCaixa::CarregarProdutos()
{
	UnicodeString QUERY;
	/*----------------------------CARREGAR PRODUTOS----------------------------------------------------*/
	TabelaProdutosMovel = (TabelaProdutos *) malloc(sizeof(TabelaProdutos));

	QUERY = "SELECT id,orcamento,id_produto,codbarras,descricao,preco,quantidade,unidade_medida,marca,ncm,cfop,desconto,promocao,devolucao FROM orcamentos_produtos WHERE orcamento='"+StringGrid1->Cells[0][rowselect]+"' ORDER BY id DESC";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		TabelaProdutosMovel->funcao = 0;
		TabelaProdutosMovel->id = SQLQuery1->Fields->FieldByName("id")->AsInteger;
		TabelaProdutosMovel->id_produto = SQLQuery1->Fields->FieldByName("id_produto")->AsInteger;
		TabelaProdutosMovel->codbarras = StrToChar(SQLQuery1->Fields->FieldByName("codbarras")->AsString);
		TabelaProdutosMovel->descricao = StrToChar(SQLQuery1->Fields->FieldByName("descricao")->AsString);
		TabelaProdutosMovel->preco = SQLQuery1->Fields->FieldByName("preco")->AsFloat;
		TabelaProdutosMovel->quantidade = SQLQuery1->Fields->FieldByName("quantidade")->AsFloat;
		TabelaProdutosMovel->unidade = StrToChar(SQLQuery1->Fields->FieldByName("unidade_medida")->AsString);
		TabelaProdutosMovel->marca = StrToChar(SQLQuery1->Fields->FieldByName("marca")->AsString);
		TabelaProdutosMovel->ncm = StrToChar(SQLQuery1->Fields->FieldByName("ncm")->AsString);
		TabelaProdutosMovel->cfop = StrToChar(SQLQuery1->Fields->FieldByName("cfop")->AsString);
		TabelaProdutosMovel->desconto = SQLQuery1->Fields->FieldByName("desconto")->AsFloat;
		TabelaProdutosMovel->promocao = SQLQuery1->Fields->FieldByName("promocao")->AsInteger;
		TabelaProdutosMovel->devolucao = SQLQuery1->Fields->FieldByName("devolucao")->AsInteger;

		AdicionarTabelaProdutos(TabelaProdutosMovel);
		SQLQuery1->Next();
	}

	if(TabelaProdutosMovel)
		free(TabelaProdutosMovel);
}
//------------------------------------------------
void TFCaixa::AdicionarTabelaProdutos(TabelaProdutos *Proximo)
{
	TabelaProdutos *movel;

	if(!TabelaProdutosNo)
	{
		TabelaProdutosNo = (TabelaProdutos*) malloc(sizeof(TabelaProdutos));

		TabelaProdutosNo->funcao = Proximo->funcao;
		TabelaProdutosNo->id = Proximo->id;
		TabelaProdutosNo->id_produto = Proximo->id_produto;
		TabelaProdutosNo->codbarras = Proximo->codbarras;
		TabelaProdutosNo->descricao = Proximo->descricao;
		TabelaProdutosNo->preco = Proximo->preco;
		TabelaProdutosNo->quantidade = Proximo->quantidade;
		TabelaProdutosNo->unidade = Proximo->unidade;
		TabelaProdutosNo->marca = Proximo->marca;
		TabelaProdutosNo->ncm = Proximo->ncm;
		TabelaProdutosNo->cfop = Proximo->cfop;
		TabelaProdutosNo->desconto = Proximo->desconto;
		TabelaProdutosNo->promocao = Proximo->promocao;
		TabelaProdutosNo->devolucao = Proximo->devolucao;
		TabelaProdutosNo->proximo = NULL;
	}
	else
	{
		movel = TabelaProdutosNo;
		while(movel->proximo)
		movel = movel->proximo;

		movel->proximo = (TabelaProdutos*) malloc(sizeof(TabelaProdutos));

		movel->proximo->funcao = Proximo->funcao;
		movel->proximo->id = Proximo->id;
		movel->proximo->id_produto = Proximo->id_produto;
		movel->proximo->codbarras = Proximo->codbarras;
		movel->proximo->descricao = Proximo->descricao;
		movel->proximo->preco = Proximo->preco;
		movel->proximo->quantidade = Proximo->quantidade;
		movel->proximo->unidade = Proximo->unidade;
		movel->proximo->marca = Proximo->marca;
		movel->proximo->ncm = Proximo->ncm;
		movel->proximo->cfop = Proximo->cfop;
		movel->proximo->desconto = Proximo->desconto;
		movel->proximo->promocao = Proximo->promocao;
		movel->proximo->devolucao = Proximo->devolucao;
		movel->proximo->proximo = NULL;
	}
}

void __fastcall TFCaixa::StringGrid1SelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{
	rowselect = ARow;
}
//---------------------------------------------------------------------------



void __fastcall TFCaixa::StringGrid1DrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
{
UnicodeString Texto;
	if(ARow>0)
	{
		Texto = StringGrid1->Cells[ACol][ARow];

		StringGrid1->Canvas->Font->Color=clBlack;

		if(ARow%2!=0)
			StringGrid1->Canvas->Brush->Color=TColor(0xf7f4f1);
		else
			StringGrid1->Canvas->Brush->Color=TColor(0xfafafa);

		if(State.Contains(gdSelected))
		{
			StringGrid1->Canvas->Brush->Color=TColor(0xc9a78b);
			StringGrid1->Canvas->Font->Color=clWhite;
		}

		//COLOCA O TEXTO
		StringGrid1->Canvas->FillRect(Rect);
		StringGrid1->Canvas->Rectangle(Rect.Left-5,Rect.Top,Rect.Left+Rect.Width(),Rect.Top+Rect.Height());
		StringGrid1->Canvas->TextOutW(Rect.Left,Rect.Top+2,Texto);

	}
}
//---------------------------------------------------------------------------
void TFCaixa::InserirMIPGestao()
{
	UnicodeString QUERY,MEDICAO,DESCRICAO;
	int id_nota;
	TDate data;

	if(ConectarMIPGestao())
	{
		SQLQuery2->SQLConnection = SQLConnection1;

		MEDICAO = "1";
		data = Now();

		DESCRICAO = "FECHAMENTO DE CAIXA - "+data.DateString()+"\r\n";
		DESCRICAO += "-------------------------------------------------\r\n";
		DESCRICAO += "CODIGO DO CAIXA - "+IntToStr(CODIGO_CAIXA)+"\r\n";
		DESCRICAO += "-------------------------------------------------\r\n";
		DESCRICAO += "- SALDO TOTAL = R$"+EditSaldoTotal->Text+"\r\n";
		DESCRICAO += "- SALDO DINHEIRO = R$"+EditSaldoDinheiro->Text+"\r\n";
		DESCRICAO += "- SALDO CARTÃO = R$"+EditSaldoCartao->Text+"\r\n";
		DESCRICAO += "- SALDO CHEQUE = R$"+EditSaldoCheque->Text+"\r\n";
		DESCRICAO += "- MOVIMENTAÇÃO CARTEIRA = R$"+EditSaldoCarteira->Text+"\r\n";

		QUERY = "INSERT INTO notas_saida (fornecedor,cnpj,data_pagamento,data_emissao,nnf,valor,vnf,icms,ipi,confins,pis,iss,descricao,conta_contabil,projeto,centro_custo,medicao,data_lancamento,tipo_nf,usuario_lancamento,consolidado)";

		QUERY += " VALUES ('";
		QUERY += CharToStr(MIPGestao.fornecedor)+"','";
		QUERY += CharToStr(MIPGestao.fornecedor_cnpj)+"','";
		QUERY += RevertOrd(data.DateString())+"','";
		QUERY += RevertOrd(data.DateString())+"','";
		QUERY += "','";
		QUERY += FloatToStr(FStrToFloat(EditSaldoTotal->Text))+"','";
		QUERY += FloatToStr(FStrToFloat(EditSaldoTotal->Text))+"','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += "','";
		QUERY += DESCRICAO+"','";
		QUERY += IntToStr(MIPGestao.conta)+"','";
		QUERY += IntToStr(MIPGestao.projeto)+"','";
		QUERY += IntToStr(MIPGestao.centro)+"','";
		QUERY += MEDICAO+"','";
		QUERY += RevertOrd(data.DateString())+"','";
		QUERY += "0','";
		QUERY += CharToStr(MIPGestao.usuario)+"','";
		QUERY += "0')";

		SQLQuery2->SQL->Clear();
		SQLQuery2->SQL->Add(QUERY);
		SQLQuery2->ExecSQL();
	}
}
//------------------------------------------------------------------------
void TFCaixa::CarregarMIPGestao()
{
	UnicodeString QUERY;

	QUERY = "SELECT id,host,nome_bd,usuario_bd,senha_bd,fornecedor_gestao,cnpj_gestao,usuario_gestao,centro_gestao,projeto_gestao,conta_gestao FROM link ORDER BY id ASC";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		MIPGestao.host = StrToChar(SQLQuery1->Fields->FieldByName("host")->AsString);
		MIPGestao.bd = StrToChar(SQLQuery1->Fields->FieldByName("nome_bd")->AsString);
		MIPGestao.usuario_bd = StrToChar(SQLQuery1->Fields->FieldByName("usuario_bd")->AsString);
		MIPGestao.senha = StrToChar(SQLQuery1->Fields->FieldByName("senha_bd")->AsString);
		MIPGestao.fornecedor = StrToChar(SQLQuery1->Fields->FieldByName("fornecedor_gestao")->AsString);
		MIPGestao.fornecedor_cnpj = StrToChar(SQLQuery1->Fields->FieldByName("cnpj_gestao")->AsString);
		MIPGestao.usuario = StrToChar(SQLQuery1->Fields->FieldByName("usuario_gestao")->AsString);
		MIPGestao.centro = SQLQuery1->Fields->FieldByName("centro_gestao")->AsInteger;
		MIPGestao.projeto = SQLQuery1->Fields->FieldByName("projeto_gestao")->AsInteger;
		MIPGestao.conta = SQLQuery1->Fields->FieldByName("conta_gestao")->AsInteger;
	}
}
void __fastcall TFCaixa::FormClose(TObject *Sender, TCloseAction &Action)
{
	if(SQLConnection1->Connected==TRUE)
	{
		SQLConnection1->Close();
		SQLConnection1->Connected = FALSE;
	}

	if(MIPGestao.host)
		free(MIPGestao.host);

	if(MIPGestao.bd)
		free(MIPGestao.bd);

	if(MIPGestao.usuario_bd)
		free(MIPGestao.usuario_bd);

	if(MIPGestao.senha)
		free(MIPGestao.senha);

	if(MIPGestao.fornecedor)
		free(MIPGestao.fornecedor);

	if(MIPGestao.fornecedor_cnpj)
		free(MIPGestao.fornecedor_cnpj);

	if(MIPGestao.usuario)
		free(MIPGestao.usuario);
}
//---------------------------------------------------------------------------
int TFCaixa::ConectarMIPGestao()
{
	int iR = 1;

	CarregarMIPGestao();

	//CONFIGURA SQL
	SQLConnection1->DriverName = "MySQL";

	//SETA PARÂMETROS SQL
	SQLConnection1->Params->Values["HostName"] = MIPGestao.host;
	SQLConnection1->Params->Values["Database"] = MIPGestao.bd;
	SQLConnection1->Params->Values["User_Name"] = MIPGestao.usuario_bd;
	SQLConnection1->Params->Values["Password"] = MIPGestao.senha;


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
void TFCaixa::loadCabecalho()
{
//    EmpresaModel *empresa_model = new EmpresaModel();
//	EmpresaEspelho *empresa = empresa_model->selectAll();
//
//	InfoGeraisModel *info_gerais_model = new InfoGeraisModel();
//	InfoGeraisEspelho *info_gerais = info_gerais_model->selectAll();
//
//	LabelCabecalhoTitulo->Caption =  "[CAIXA] " + empresa->getNomeFantasia();
//
//	LabelCabecalhoSubTitulo->Caption =  ToUpper(info_gerais->getSoftwareName());
}

