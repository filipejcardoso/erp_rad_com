#include "InfoGeraisEspelho.h"

//==============SETTERS===============================
void InfoGeraisEspelho::setId(int value){
	id = value;
}
//---------------------------------------------------
void InfoGeraisEspelho::setSoftwareName(UnicodeString value){
	software_name = value;
}
//-------------------------------------------------------
void InfoGeraisEspelho::setVersao(UnicodeString value){
	versao = value;
}


//==============GETTERS===============================
int InfoGeraisEspelho::getId(){
	return id;
}
//-------------------------------------------------------
UnicodeString InfoGeraisEspelho::getSoftwareName(){
	return software_name;
}
//-------------------------------------------------------
UnicodeString InfoGeraisEspelho::getVersao(){
	return versao;
}


