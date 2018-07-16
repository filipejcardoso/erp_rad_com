//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ContasReceberFechamento.h"
#include "Principal.h"
#include "ContasReceber.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFContasReceberFechamento *FContasReceberFechamento;
//---------------------------------------------------------------------------
__fastcall TFContasReceberFechamento::TFContasReceberFechamento(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFContasReceberFechamento::FormCreate(TObject *Sender)
{
	//CONFIGURAR O FORM
   	ConfigurarForm(this);

	SQLQuery1->SQLConnection = SQLCONNECT;
}
//---------------------------------------------------------------------------
void __fastcall TFContasReceberFechamento::ButtonCancelarClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void TFContasReceberFechamento::InicializarCampos()
{
	LabelCliente->Caption = "CLIENTE: " + FContasReceber->CLIENTE_SELECIONADO;
	EditDescontoP->Text = "0.00";
	EditDescontoD->Text = "0.00";
	EditValorTotal->Text = FContasReceber->EditPendentesSelecionado->Text;
	EditValorRestante->Text = EditValorTotal->Text;
	data_vencimento->Date = Now();

	EditValorFechamento->Clear();
	EditValorFechamento->SetFocus();

}
void __fastcall TFContasReceberFechamento::FormShow(TObject *Sender)
{
	InicializarCampos();
	GerarGrid();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::ButtonDinheiroClick(TObject *Sender)
{
	AdicionarFechamento(0);
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::ButtonCartaoClick(TObject *Sender)
{
	AdicionarFechamento(1);
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::ButtonChequeClick(TObject *Sender)
{
	AdicionarFechamento(2);
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::ButtonBoletoClick(TObject *Sender)
{
	AdicionarFechamento(3);
}
//---------------------------------------------------------------------------
void TFContasReceberFechamento::GerarGrid()
{
	UnicodeString QUERY,MODO;
	int i,j,rc,cc;
	int numerodalinha;

	rc = StringGrid1->RowCount;
	cc = StringGrid1->ColCount;

	for(i=0;i<rc;i++)
		for(j=0;j<cc;j++)
			StringGrid1->Cells[j][i] = "";

	// ESTRUTURA GRID
	StringGrid1->Options << goRowSelect;
	StringGrid1->ScrollBars = ssVertical;
	StringGrid1->Rows[1]->Clear();
	StringGrid1->RowCount = 0;
	StringGrid1->ColCount = 3;
	StringGrid1->FixedCols = 0;
	StringGrid1->ColWidths[0] = 0;
	StringGrid1->ColWidths[1] = 100;
	StringGrid1->ColWidths[2] = StringGrid1->Width-100;
	StringGrid1->Cols[0]->Add("LINHA");
	StringGrid1->Cols[1]->Add("VALOR(R$)");
	StringGrid1->Cols[2]->Add("MODO DE PAGAR");
	// ESTRUTURA GRID

	numerodalinha = 1;

	if(FContasReceber->FechamentosNo)
	{
		FContasReceber->FechamentosMovel = FContasReceber->FechamentosNo;
		while(FContasReceber->FechamentosMovel)
		{
			switch(FContasReceber->FechamentosMovel->modpagar)
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
					MODO = "BOLETO";
				break;
			}
			StringGrid1->Cells[0][numerodalinha] = IntToStr(FContasReceber->FechamentosMovel->linha);
			StringGrid1->Cells[1][numerodalinha] = FormatFloat("#,###,###,##0.00",FContasReceber->FechamentosMovel->valor);
			StringGrid1->Cells[2][numerodalinha] = MODO;

			StringGrid1->RowCount++;
			numerodalinha++;
			if (numerodalinha == 2)
				StringGrid1->FixedRows = 1;
			FContasReceber->FechamentosMovel = FContasReceber->FechamentosMovel->proximo;
		}
	}
	Total();
}
//---------------------------------------------------------------------------
void TFContasReceberFechamento::Total()
{
	float valor_fechado = 0;
	float total;
	float restante;

	total = FStrToFloat(EditValorTotal->Text);

	/*----------GET VALOR-----------*/
	if(FContasReceber->FechamentosNo)
	{
		FContasReceber->FechamentosMovel = FContasReceber->FechamentosNo;
		while(FContasReceber->FechamentosMovel)
		{
			valor_fechado = valor_fechado + FContasReceber->FechamentosMovel->valor;
			FContasReceber->FechamentosMovel = FContasReceber->FechamentosMovel->proximo;
		}
	}
	restante = total - valor_fechado;
	EditValorRestante->Text = FormatFloat("#,###,###,##0.00",restante);

}
//---------------------------------------------------------------------------
void TFContasReceberFechamento::DescontoD()
{
	float desconto;
	float valor_total;
	float porcentagem;

	if(!FContasReceber->FechamentosNo)
	{
		valor_total = FStrToFloat(FContasReceber->EditPendentesSelecionado->Text);
		desconto = FStrToFloat(EditDescontoD->Text);
		porcentagem = desconto/valor_total*100;
		EditDescontoP->Text = FormatFloat("#,###,###,##0.00",porcentagem);
		DescontoP();
	}
	else
		MessageBox(NULL,L"Desculpe, você ja possui fechamentos na lista!",L"Desconto total",MB_OK | MB_ICONERROR);

}
void TFContasReceberFechamento::DescontoP()
{
	float valor_final;
	float valor_total;
	float porcentagem;
	float dinheiro;

	if(!FContasReceber->FechamentosNo)
	{
		valor_total = FStrToFloat(FContasReceber->EditPendentesSelecionado->Text);
		porcentagem = FStrToFloat(EditDescontoP->Text);
		valor_final = valor_total * (1-porcentagem/100);
		dinheiro = valor_total - valor_final;

		EditDescontoD->Text = FormatFloat("#,###,###,##0.00",dinheiro);
		EditValorTotal->Text = FormatFloat("#,###,###,##0.00",valor_final);
		EditValorRestante->Text = EditValorTotal->Text;
	}
	else
		MessageBox(NULL,L"Desculpe, você ja possui fechamentos na lista!",L"Desconto total",MB_OK | MB_ICONERROR);
}
//---------------------------------------------------------------------------
void __fastcall TFContasReceberFechamento::DelExecute(TObject *Sender)
{
	if(rowselect>0)
	{
		FContasReceber->RemoverFechamento(FStrToInt(StringGrid1->Cells[0][rowselect]));
		GerarGrid();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::EditDescontoPKeyPress(TObject *Sender,
          System::WideChar &Key)
{
	if(Key == 13)
		DescontoP();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::StringGrid1SelectCell(TObject *Sender,
          int ACol, int ARow, bool &CanSelect)
{
	rowselect = ARow;
}
//---------------------------------------------------------------------------
void TFContasReceberFechamento::AdicionarFechamento(int modpagar)
{
	int linha;
	float recebendo,restante;

	restante = FStrToFloat(EditValorRestante->Text);
	recebendo = FStrToFloat(EditValorFechamento->Text);

	if(recebendo>0 && recebendo<=restante)
	{
		/*----------GET LINHA-----------*/
		if(FContasReceber->FechamentosNo)
		{
			FContasReceber->FechamentosMovel = FContasReceber->FechamentosNo;
			while(FContasReceber->FechamentosMovel)
			{
				linha = FContasReceber->FechamentosMovel->linha;
				FContasReceber->FechamentosMovel = FContasReceber->FechamentosMovel->proximo;
			}
		}

		linha++;

		FContasReceber->AdicionarFechamento(linha,FStrToFloat(EditValorFechamento->Text),FStrToFloat(EditDescontoP->Text),modpagar,data_vencimento->Date);


		if(recebendo < restante)
			GerarGrid();
		else
		{
			FContasReceber->RealizarFechamento();
			Close();
		}
		EditValorFechamento->Clear();
		EditValorFechamento->SetFocus();
	}
	else
		MessageBox(NULL,L"Valor incorreto aplicado ao fechamento!",L"Fechamento",MB_OK | MB_ICONERROR);

}
void __fastcall TFContasReceberFechamento::EditDescontoDExit(TObject *Sender)
{
	DescontoD();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::EditDescontoDKeyPress(TObject *Sender,
          System::WideChar &Key)
{
	if(Key == 13)
		DescontoD();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::EditDescontoPExit(TObject *Sender)
{
	DescontoP();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::F4Execute(TObject *Sender)
{
	ButtonBoleto->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::F3Execute(TObject *Sender)
{
	ButtonCheque->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::F2Execute(TObject *Sender)
{
	ButtonCartao->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFContasReceberFechamento::F1Execute(TObject *Sender)
{
	ButtonDinheiro->Click();
}
//---------------------------------------------------------------------------

