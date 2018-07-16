//---------------------------------------------------------------------------

#pragma hdrstop

#include "Enderecos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Enderecos::Enderecos()
{
    tipos_endereco = new TiposEnderecos();
    regioes = new Regioes();
}

