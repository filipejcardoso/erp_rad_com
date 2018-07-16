//---------------------------------------------------------------------------

#pragma hdrstop

#include "Style.h"
#include "Sistema.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void Style::setTop(TLabel *titulo, TLabel *subtitulo)
{
	titulo->Caption = "MIPVendas ERP";
	subtitulo->Caption = SISTEMA->empresa->nome;
}
//---------------------------------------------------------------------------
void Style::setTop(TLabel *titulo, TLabel *subtitulo, UnicodeString modulo)
{
	Style::setTop(titulo, subtitulo);
	titulo->Caption = "[" + modulo.UpperCase() + "] " + titulo->Caption;
}
//---------------------------------------------------------------------------
void Style::setTop(TLabel *titulo, TLabel *subtitulo, TLabel *moduloLabel, UnicodeString modulo)
{
    Style::setTop(titulo, subtitulo);
	moduloLabel->Caption = "[" + modulo.UpperCase() + "]";
}

