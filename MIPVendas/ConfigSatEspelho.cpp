#include "ConfigSatEspelho.h"

//====================SETTERS==============================
void ConfigSatEspelho::setId(int value){
    id = value;
}
//---------------------------------------------------------
void ConfigSatEspelho::setCnpjSoftwareHouse(UnicodeString value){
	cnpj_software_house = value;
}
//---------------------------------------------------------
void ConfigSatEspelho::setSignAc(UnicodeString value){
	sign_ac = value;
}
//---------------------------------------------------------

//====================GETTERS==============================
int ConfigSatEspelho::getId(){
	return id;
}
//---------------------------------------------------------
UnicodeString ConfigSatEspelho::getCnpjSoftwareHouse(){
	return cnpj_software_house;
}
//---------------------------------------------------------
UnicodeString ConfigSatEspelho::getSignAc(){
	return sign_ac;
}

