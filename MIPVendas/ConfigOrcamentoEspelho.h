#ifndef ConfigOrcamentoEspelhoH
#define ConfigOrcamentoEspelhoH

#include <System.hpp>
class ConfigOrcamentoEspelho
{
	private:
		int id;
        int validade;
	public:
		void setId(int value);
		void setValidade(int value);

		int getId();
		int getValidade();
};
#endif
