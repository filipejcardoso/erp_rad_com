#ifndef RegioesModelH
#define RegioesModelH

#include <System.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Data.DBXMySQL.hpp>
#include "RegioesEspelho.h"

class RegioesModel
{
	private:
		TSQLQuery *SQLQuery1;
		DynamicArray<RegioesEspelho*> registros;
	public:
		RegioesModel();
		RegioesEspelho* selectById(int value);
		DynamicArray<RegioesEspelho*>* selectDistinctUf();
		DynamicArray<RegioesEspelho*>* selectByUf(UnicodeString uf);
        UnicodeString selectByUfMunicipio(UnicodeString uf, UnicodeString municipio);
};
#endif
