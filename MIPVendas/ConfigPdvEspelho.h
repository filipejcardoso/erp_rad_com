#ifndef ConfigPdvEspelhoH
#define ConfigPdvEspelhoH

#include <System.hpp>
class ConfigPdvEspelho
{
	private:
		int id;
        int cupom;
	public:
		void setId(int value);
		void setCupom(int value);

		int getId();
		int getCupom();
};
#endif
