#ifndef RegioesEspelhoH
#define RegioesEspelhoH

#include <System.hpp>

class RegioesEspelho
{
	private:
		int id;
		UnicodeString codigo_uf;
		UnicodeString uf;
		UnicodeString nome_uf;
		UnicodeString codigo_municipio;
        UnicodeString municipio;

	public:
		//=====================SETTERS================================
		void setId(int value);
		void setCodigoUf(UnicodeString value);
		void setUf(UnicodeString value);
		void setNomeUf(UnicodeString value);
		void setCodigoMunicipio(UnicodeString value);
		void setMunicipio(UnicodeString value);

		//=====================GETTERS================================
		int getId();
		UnicodeString getCodigoUf();
		UnicodeString getUf();
		UnicodeString getNomeUf();
		UnicodeString getCodigoMunicipio();
		UnicodeString getMunicipio();
};
#endif