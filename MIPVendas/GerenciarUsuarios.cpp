//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GerenciarUsuarios.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFGerenciarUsuarios *FGerenciarUsuarios;
//---------------------------------------------------------------------------
__fastcall TFGerenciarUsuarios::TFGerenciarUsuarios(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFGerenciarUsuarios::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);

	SQLQuery1->SQLConnection = SQLCONNECT;
}
//---------------------------------------------------------------------------
void TFGerenciarUsuarios::ConfigurarLayout()
{
	Panel1->Width = Width/2;
}
void __fastcall TFGerenciarUsuarios::FormShow(TObject *Sender)
{
	//incializar variaveis
	editar = 0;

	InicializarCampos();
	ConfigurarLayout();
	GerarGrid();
	DesignerBotoes();
}
//---------------------------------------------------------------------------
void __fastcall TFGerenciarUsuarios::StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
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
void __fastcall TFGerenciarUsuarios::StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	rowselect = ARow;
}
//---------------------------------------------------------------------------
void TFGerenciarUsuarios::GerarGrid()
{
UnicodeString QUERY;
int numerodalinha,i,c;

	c = StringGrid1->RowCount;
	for(i=1;i<c;i++)
		StringGrid1->Rows[i]->Clear();

	numerodalinha = 1;
	// ESTRUTURA GRID
	StringGrid1->Options << goRowSelect;
	StringGrid1->ScrollBars = ssVertical;
	StringGrid1->Rows[1]->Clear();
	StringGrid1->RowCount = 0;
	StringGrid1->ColCount = 1;
	StringGrid1->FixedCols = 0;
	StringGrid1->ColWidths[0] = (StringGrid1->Width);
	StringGrid1->Cols[0]->Add("NOME DE USUÁRIO");
	// ESTRUTURA GRID

	//GET NUMERO DE USUARIOS
	QUERY = "SELECT COUNT(id) AS numero_usuarios FROM usuarios";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("numero_usuarios")->AsInteger)
		n = SQLQuery1->Fields->FieldByName("numero_usuarios")->AsInteger;
	else
		n = 0;

    if(n>0)
		users = (Usuarios *) malloc(n*sizeof(Usuarios));

	QUERY = "SELECT id,nome,senha,desconto,permissao FROM usuarios ORDER BY nome ASC";

	i = 0;
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	while(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		users[i].id = SQLQuery1->Fields->FieldByName("id")->AsInteger;
		users[i].nome = StrToChar(SQLQuery1->Fields->FieldByName("nome")->AsString);
		users[i].senha = StrToChar(SQLQuery1->Fields->FieldByName("senha")->AsString);
		users[i].desconto = SQLQuery1->Fields->FieldByName("desconto")->AsFloat;
		users[i].permissao = SQLQuery1->Fields->FieldByName("permissao")->AsInteger;

		StringGrid1->Cells[0][numerodalinha] = users[i].nome;

		StringGrid1->RowCount++;
		SQLQuery1->Next();
		numerodalinha++;
		if (numerodalinha == 2)
			StringGrid1->FixedRows = 1;
		i++;
	}
	if (numerodalinha <= 1) {
		StringGrid1->RowCount++;
	}
}
void __fastcall TFGerenciarUsuarios::FormClose(TObject *Sender, TCloseAction &Action)

{
int i;
	if(users)
	{
		for(i=0;i<n;i++)
		{
			free(users[i].nome);
			free(users[i].senha);
		}
		free(users);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFGerenciarUsuarios::StringGrid1Click(TObject *Sender)
{
	editar = 1;
	CarregarCampos();
	DesignerBotoes();
}
//---------------------------------------------------------------------------
void TFGerenciarUsuarios::CarregarCampos()
{
	unsigned int mascara;
	unsigned int result;

	EditUsuario->Text = users[rowselect-1].nome;
	EditSenha->Text = users[rowselect-1].senha;
	EditDesconto->Text = FormatFloat("#,###,###,##0.00",users[rowselect-1].desconto);
	EditRepitirSenha->Text = users[rowselect-1].senha;

	mascara = 0x01;
	result = mascara&users[rowselect-1].permissao;
	if(result == mascara)
		Check0->Checked = TRUE;
	else
		Check0->Checked = FALSE;

	mascara = 0x02;
	result = mascara&users[rowselect-1].permissao;
	if(result == mascara)
		Check1->Checked = TRUE;
	else
		Check1->Checked = FALSE;

	mascara = 0x04;
	result = mascara&users[rowselect-1].permissao;
	if(result == mascara)
		Check2->Checked = TRUE;
	else
		Check2->Checked = FALSE;

	mascara = 0x08;
	result = mascara&users[rowselect-1].permissao;
	if(result == mascara)
		Check3->Checked = TRUE;
	else
		Check3->Checked = FALSE;

	mascara = 0x10;
	result = mascara&users[rowselect-1].permissao;
	if(result == mascara)
		Check4->Checked = TRUE;
	else
		Check4->Checked = FALSE;

	mascara = 0x20;
	result = mascara&users[rowselect-1].permissao;
	if(result == mascara)
		Check5->Checked = TRUE;
	else
		Check5->Checked = FALSE;

	mascara = 0x40;
	result = mascara&users[rowselect-1].permissao;
	if(result == mascara)
		Check6->Checked = TRUE;
	else
		Check6->Checked = FALSE;

	mascara = 0x80;
	result = mascara&users[rowselect-1].permissao;
	if(result == mascara)
		Check7->Checked = TRUE;
	else
		Check7->Checked = FALSE;


}
void __fastcall TFGerenciarUsuarios::ButtonAtualizarClick(TObject *Sender)
{
	GerarGrid();
}
//---------------------------------------------------------------------------
void __fastcall TFGerenciarUsuarios::ButtonNovoUsuarioClick(TObject *Sender)
{
	editar = 0;
	InicializarCampos();
	DesignerBotoes();
}
//---------------------------------------------------------------------------
void TFGerenciarUsuarios::InicializarCampos()
{
	EditUsuario->Clear();
	EditSenha->Clear();
	EditRepitirSenha->Clear();
	EditDesconto->Clear();
	Check0->Checked = FALSE;
	Check1->Checked = FALSE;
	Check2->Checked = FALSE;
	Check3->Checked = FALSE;
	Check4->Checked = FALSE;
	Check5->Checked = FALSE;
	Check6->Checked = FALSE;
	Check7->Checked = FALSE;
}
//-----------------------------------
void TFGerenciarUsuarios::DesignerBotoes()
{
	if(editar == 0)
	{
		ButtonDeletar->Visible = FALSE;
		ButtonInserirModificar->Caption = "ADICIONAR";
	}
	else
	{
		ButtonDeletar->Visible = TRUE;
		ButtonInserirModificar->Caption = "MODIFICAR";
	}
}
void __fastcall TFGerenciarUsuarios::ButtonDeletarClick(TObject *Sender)
{
	if(MessageBox(NULL,L"Tem certeza que deseja deletar?",L"Deletar Usuário",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add("DELETE FROM usuarios WHERE id='" + IntToStr(users[rowselect-1].id) + "'");
		SQLQuery1->ExecSQL();
		MessageBox(NULL,L"Usuário deletado com sucesso!",L"Remover Usuário",MB_OK | MB_ICONINFORMATION);

		editar = 0;
		InicializarCampos();
		DesignerBotoes();
		GerarGrid();
	}
}
//---------------------------------------------------------------------------
void TFGerenciarUsuarios::InserirUsuario()
{
	UnicodeString QUERY;
	unsigned int permissao;
	unsigned int mask[8];
	int i;

	for(i=0;i<8;i++)
		mask[i] = 0x00;

	if(Check0->Checked == TRUE)
		mask[0] = 0x01;
	if(Check1->Checked == TRUE)
		mask[1] = 0x02;
	if(Check2->Checked == TRUE)
		mask[2] = 0x04;
	if(Check3->Checked == TRUE)
		mask[3] = 0x08;
	if(Check4->Checked == TRUE)
		mask[4] = 0x10;
	if(Check5->Checked == TRUE)
		mask[5] = 0x20;
	if(Check6->Checked == TRUE)
		mask[6] = 0x40;
	if(Check7->Checked == TRUE)
		mask[7] = 0x80;

	permissao = 0;
	for(i=0;i<8;i++)
		permissao = permissao | mask[i];

	QUERY = "INSERT INTO usuarios (nome,senha,desconto,permissao)";
	QUERY += " VALUES ('";
	QUERY += EditUsuario->Text+"','";
	QUERY += EditSenha->Text+"','";
	QUERY += FloatToStr(FStrToFloat(EditDesconto->Text))+"','";
	QUERY += IntToStr((int)permissao)+"')";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->ExecSQL();

	MessageBox(NULL,L"Usuário cadastrado com sucesso!",L"Cadastro de usuários",MB_OK | MB_ICONINFORMATION);

	editar = 0;
	InicializarCampos();
	DesignerBotoes();
	GerarGrid();
}
//---------------------------------------------------------------------------
void TFGerenciarUsuarios::ModificarUsuario()
{
	UnicodeString QUERY;
	unsigned int permissao;
	unsigned int mask[8];
	int i;

	for(i=0;i<8;i++)
		mask[i] = 0x00;

	if(Check0->Checked == TRUE)
		mask[0] = 0x01;
	if(Check1->Checked == TRUE)
		mask[1] = 0x02;
	if(Check2->Checked == TRUE)
		mask[2] = 0x04;
	if(Check3->Checked == TRUE)
		mask[3] = 0x08;
	if(Check4->Checked == TRUE)
		mask[4] = 0x10;
	if(Check5->Checked == TRUE)
		mask[5] = 0x20;
	if(Check6->Checked == TRUE)
		mask[6] = 0x40;
	if(Check7->Checked == TRUE)
		mask[7] = 0x80;

	permissao = 0;
	for(i=0;i<8;i++)
		permissao = permissao | mask[i];

	if(MessageBox(NULL,L"Tem certeza que deseja modificar este usuário?",L"Modificar Usuário",MB_YESNO | MB_ICONEXCLAMATION) == 6)
	{
		QUERY = "UPDATE usuarios SET ";

		QUERY += "nome='"+EditUsuario->Text+"',";
		QUERY += "senha='"+EditSenha->Text+"',";
		QUERY += "desconto='"+FloatToStr(FStrToFloat(EditDesconto->Text))+"',";
		QUERY += "permissao='"+IntToStr((int)permissao)+"'";

		QUERY += " WHERE id='"+IntToStr(users[rowselect-1].id)+"' ORDER BY id ASC";

		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(QUERY);
		SQLQuery1->ExecSQL();

		MessageBox(NULL,L"Usuário modificado com sucesso",L"Usuário Modificado",MB_OK | MB_ICONINFORMATION);

		editar = 0;
		InicializarCampos();
		DesignerBotoes();
		GerarGrid();
	}
}

void __fastcall TFGerenciarUsuarios::ButtonInserirModificarClick(TObject *Sender)
{
	if(editar)
		ModificarUsuario();
	else
		InserirUsuario();

}
//---------------------------------------------------------------------------

