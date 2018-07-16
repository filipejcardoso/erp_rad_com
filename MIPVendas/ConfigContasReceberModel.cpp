#include "ConfigContasReceberModel.h"
#include "Principal.h"

ConfigContasReceberEspelho* ConfigContasReceberModel::selectAll()
{
    ConfigContasReceberEspelho *config_contas_receber = new ConfigContasReceberEspelho();
	TSQLQuery *SQLQuery1 = new TSQLQuery(NULL);
	UnicodeString QUERY;

	SQLQuery1->SQLConnection = SQLCONNECT;

	QUERY = "SELECT * FROM config_contas_receber";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		config_contas_receber->setId(SQLQuery1->Fields->FieldByName("id")->AsInteger);
		config_contas_receber->setNotificacao(SQLQuery1->Fields->FieldByName("notificacao")->AsInteger);
	}

	return config_contas_receber;
}
//-------------------------------------------------------------
int ConfigContasReceberModel::update(ConfigContasReceberEspelho *value)
{
	TSQLQuery *SQLQuery1 = new TSQLQuery(NULL);
	UnicodeString QUERY;

	SQLQuery1->SQLConnection = SQLCONNECT;

	QUERY = "UPDATE config_contas_receber SET ";

	QUERY += "notificacao='"+IntToStr(value->getNotificacao())+"'";

	QUERY += " WHERE id='"+IntToStr(value->getId())+"'";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->ExecSQL();
}

