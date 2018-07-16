#include "ConfigSatModel.h"
#include "Principal.h"

ConfigSatEspelho* ConfigSatModel::selectAll()
{
    ConfigSatEspelho *config_sat = new ConfigSatEspelho();
	TSQLQuery *SQLQuery1 = new TSQLQuery(NULL);
	UnicodeString QUERY;

	SQLQuery1->SQLConnection = SQLCONNECT;

	QUERY = "SELECT * FROM config_sat";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		config_sat->setId(SQLQuery1->Fields->FieldByName("id")->AsInteger);
		config_sat->setCnpjSoftwareHouse(SQLQuery1->Fields->FieldByName("cnpj_software_house")->AsString);
		config_sat->setSignAc(SQLQuery1->Fields->FieldByName("sign_ac")->AsString);
	}

	return config_sat;
}
//-------------------------------------------------------------
int ConfigSatModel::update(ConfigSatEspelho *value)
{
	TSQLQuery *SQLQuery1 = new TSQLQuery(NULL);
	UnicodeString QUERY;

	SQLQuery1->SQLConnection = SQLCONNECT;

	QUERY = "UPDATE config_sat SET ";

	QUERY += "cnpj_software_house='"+value->getCnpjSoftwareHouse()+"',";
	QUERY += "sign_ac='"+value->getSignAc()+"'";

	QUERY += " WHERE id='"+IntToStr(value->getId())+"'";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->ExecSQL();
}

