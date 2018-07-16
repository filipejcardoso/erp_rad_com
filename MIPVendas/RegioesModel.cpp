#include "RegioesModel.h"
#include "Principal.h"

RegioesModel::RegioesModel()
{
	SQLQuery1 = new TSQLQuery(NULL);
	SQLQuery1->SQLConnection = SQLCONNECT;
}
//--------------------------------------------------------------
RegioesEspelho* RegioesModel::selectById(int value)
{
	RegioesEspelho *regiao = new RegioesEspelho();
    UnicodeString QUERY;

	QUERY = "SELECT * FROM regioes WHERE id ='"+IntToStr(value)+"'";

	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();
	if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
	{
		regiao->setId(SQLQuery1->Fields->FieldByName("id")->AsInteger);
		regiao->setCodigoUf(SQLQuery1->Fields->FieldByName("codigo_uf")->AsString);
		regiao->setUf(SQLQuery1->Fields->FieldByName("uf")->AsString);
		regiao->setNomeUf(SQLQuery1->Fields->FieldByName("nome_uf")->AsString);
		regiao->setCodigoMunicipio(SQLQuery1->Fields->FieldByName("codigo_municipio")->AsString);
		regiao->setMunicipio(SQLQuery1->Fields->FieldByName("municipio")->AsString);
	}

	return regiao;
}
//--------------------------------------------------------------
DynamicArray<RegioesEspelho*>* RegioesModel::selectDistinctUf()
{
	UnicodeString QUERY;
	registros.Length = 0;

	QUERY = "SELECT DISTINCT id,uf FROM regioes GROUP BY uf ORDER BY uf ASC";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();

	for(int i = 0;SQLQuery1->Fields->FieldByName("id")->AsInteger;i++)
	{
		registros.Length++;

		registros[i] = new RegioesEspelho();
		registros[i]->setId(SQLQuery1->Fields->FieldByName("id")->AsInteger);
		registros[i]->setCodigoUf(NULL);
		registros[i]->setUf(SQLQuery1->Fields->FieldByName("uf")->AsString);
		registros[i]->setNomeUf(NULL);
		registros[i]->setCodigoMunicipio(NULL);
		registros[i]->setMunicipio(NULL);

		SQLQuery1->Next();
	}

    return &registros;
}
//--------------------------------------------------------------
DynamicArray<RegioesEspelho*>* RegioesModel::selectByUf(UnicodeString uf)
{
	UnicodeString QUERY;
	registros.Length = 0;

	QUERY = "SELECT DISTINCT * FROM regioes WHERE uf='"+uf+"' ORDER BY municipio ASC";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();

	for(int i = 0;SQLQuery1->Fields->FieldByName("id")->AsInteger;i++)
	{
		registros.Length++;

		registros[i] = new RegioesEspelho();
		registros[i]->setId(SQLQuery1->Fields->FieldByName("id")->AsInteger);
		registros[i]->setCodigoUf(SQLQuery1->Fields->FieldByName("codigo_uf")->AsString);
		registros[i]->setUf(SQLQuery1->Fields->FieldByName("uf")->AsString);
		registros[i]->setNomeUf(SQLQuery1->Fields->FieldByName("nome_uf")->AsString);
		registros[i]->setCodigoMunicipio(SQLQuery1->Fields->FieldByName("codigo_municipio")->AsString);
		registros[i]->setMunicipio(SQLQuery1->Fields->FieldByName("municipio")->AsString);

		SQLQuery1->Next();
	}

    return &registros;
}
UnicodeString RegioesModel::selectByUfMunicipio(UnicodeString uf, UnicodeString municipio)
{
	UnicodeString QUERY;
	registros.Length = 0;

	QUERY = "SELECT id,uf,municipio FROM regioes WHERE uf='"+uf+"' AND municipio='"+municipio+"' ORDER BY id ASC";
	SQLQuery1->SQL->Clear();
	SQLQuery1->SQL->Add(QUERY);
	SQLQuery1->Open();
	SQLQuery1->First();

	if(SQLQuery1->Fields->FieldByName("id")->AsInteger)
		return SQLQuery1->Fields->FieldByName("id")->AsString;
}

