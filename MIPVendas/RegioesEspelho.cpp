#include "RegioesEspelho.h"

//=====================SETTERS================================
void RegioesEspelho::setId(int value){
    id = value;
}
//-----------------------------------------------------------
void RegioesEspelho::setCodigoUf(UnicodeString value){
    codigo_uf = value;
}
//-----------------------------------------------------------
void RegioesEspelho::setUf(UnicodeString value){
    uf = value;
}
//-----------------------------------------------------------
void RegioesEspelho::setNomeUf(UnicodeString value){
    nome_uf = value;
}
//-----------------------------------------------------------
void RegioesEspelho::setCodigoMunicipio(UnicodeString value){
    codigo_municipio = value;
}
//-----------------------------------------------------------
void RegioesEspelho::setMunicipio(UnicodeString value){
    municipio = value;
}
//-----------------------------------------------------------

//=====================GETTERS================================
int RegioesEspelho::getId(){
    return id;
}
//-----------------------------------------------------------
UnicodeString RegioesEspelho::getCodigoUf(){
    return codigo_uf;
}
//-----------------------------------------------------------
UnicodeString RegioesEspelho::getUf(){
    return uf;
}
//-----------------------------------------------------------
UnicodeString RegioesEspelho::getNomeUf(){
    return nome_uf;
}
//-----------------------------------------------------------
UnicodeString RegioesEspelho::getCodigoMunicipio(){
    return codigo_municipio;
}
//-----------------------------------------------------------
UnicodeString RegioesEspelho::getMunicipio(){
    return municipio;
}
//-----------------------------------------------------------

