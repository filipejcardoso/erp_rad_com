#include "ConfigPdvModel.h"
#include "Principal.h"

ConfigPdvEspelho* ConfigPdvModel::selectAll()
{
    ConfigPdvEspelho *config_pdv = new ConfigPdvEspelho();
	TSQLQuery *SQLQuery1 = new TSQLQuery(NULL);
	UnicodeString QUERY;

	SQLQuery1->SQLConnection = SQLCONNECT;

	QUERY = "SELECT * FROM config_pdv";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		config_pdv->setId(SQLQuery1->Fields->FieldByName("id")->AsInteger);
		config_pdv->setCupom(SQLQuery1->Fields->FieldByName("cupom")->AsInteger);
	}

	return config_pdv;
}
//-------------------------------------------------------------
int ConfigPdvModel::update(ConfigPdvEspelho *value)
{
	TSQLQuery *SQLQuery1 = new TSQLQuery(NULL);
	UnicodeString QUERY;

	SQLQuery1->SQLConnection = SQLCONNECT;

	QUERY = "UPDATE config_pdv SET ";

	QUERY += "cupom='"+IntToStr(value->getCupom())+"'";

	QUERY += " WHERE id='"+IntToStr(value->getId())+"'";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->ExecSQL();
}

