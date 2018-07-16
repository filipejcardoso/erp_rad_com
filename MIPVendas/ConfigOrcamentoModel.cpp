#include "ConfigOrcamentoModel.h"
#include "Principal.h"

ConfigOrcamentoEspelho* ConfigOrcamentoModel::selectAll()
{
    ConfigOrcamentoEspelho *config_orcamento = new ConfigOrcamentoEspelho();
	TSQLQuery *SQLQuery1 = new TSQLQuery(NULL);
	UnicodeString QUERY;

	SQLQuery1->SQLConnection = SQLCONNECT;

	QUERY = "SELECT * FROM config_orcamento";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		config_orcamento->setId(SQLQuery1->Fields->FieldByName("id")->AsInteger);
		config_orcamento->setValidade(SQLQuery1->Fields->FieldByName("validade")->AsInteger);
	}

	return config_orcamento;
}
//-------------------------------------------------------------
int ConfigOrcamentoModel::update(ConfigOrcamentoEspelho *value)
{
	TSQLQuery *SQLQuery1 = new TSQLQuery(NULL);
	UnicodeString QUERY;

	SQLQuery1->SQLConnection = SQLCONNECT;

	QUERY = "UPDATE config_orcamento SET ";

	QUERY += "validade='"+IntToStr(value->getValidade())+"'";

	QUERY += " WHERE id='"+IntToStr(value->getId())+"'";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->ExecSQL();
}

