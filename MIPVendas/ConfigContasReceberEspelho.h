#ifndef ConfigContasReceberEspelhoH
#define ConfigContasReceberEspelhoH

#include <System.hpp>
class ConfigContasReceberEspelho
{
	private:
		int id;
        int notificacao;
	public:
		void setId(int value);
		void setNotificacao(int value);

		int getId();
		int getNotificacao();
};
#endif
