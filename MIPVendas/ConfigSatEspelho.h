#ifndef ConfigSatEspelhoH
#define ConfigSatEspelhoH

#include <System.hpp>

class ConfigSatEspelho
{
	private:
		int id;
		UnicodeString cnpj_software_house;
		UnicodeString sign_ac;
		
	public:
		void setId(int value);
		void setCnpjSoftwareHouse(UnicodeString value);
		void setSignAc(UnicodeString value);

		int getId();
		UnicodeString getCnpjSoftwareHouse();
		UnicodeString getSignAc();
};
#endif
