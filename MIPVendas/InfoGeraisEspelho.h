#ifndef InfoGeraisEspelhoH
#define InfoGeraisEspelhoH

#include <System.hpp>

class InfoGeraisEspelho
{
	private:
		int id;
		UnicodeString software_name;
		UnicodeString versao;

	public:
		void setId(int value);
		void setSoftwareName(UnicodeString value);
		void setVersao(UnicodeString value);

		int getId();
		UnicodeString getSoftwareName();
		UnicodeString getVersao();
};
#endif
