#include "InfoGeraisModel.h"
#include "Principal.h"

InfoGeraisEspelho* InfoGeraisModel::selectAll()
{
    InfoGeraisEspelho *info_gerais = new InfoGeraisEspelho();
	TSQLQuery *SQLQuery1 = new TSQLQuery(NULL);
	UnicodeString QUERY;

	SQLQuery1->SQLConnection = SQLCONNECT;

	QUERY = "SELECT * FROM info_gerais LIMIT 1";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger != 0)
	{
		info_gerais->setId(SQLQuery1->Fields->FieldByName("id")->AsInteger);
		info_gerais->setSoftwareName(SQLQuery1->Fields->FieldByName("software_name")->AsString);
		info_gerais->setVersao(SQLQuery1->Fields->FieldByName("versao")->AsString);
    }

	return info_gerais;
}
