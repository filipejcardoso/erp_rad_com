//---------------------------------------------------------------------------

#pragma hdrstop

#include "Regioes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

UnicodeString Regioes::getMunicipioUf()
{
    return this->municipio + " - " + this->uf;
}
