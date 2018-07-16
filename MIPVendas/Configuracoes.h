//---------------------------------------------------------------------------

#ifndef ConfiguracoesH
#define ConfiguracoesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#include "ConfigPedidos.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, private, public) properties (__published, private, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class Configuracoes : public TObject
{
	private:
        void instance();

	public:
        int id;
		ConfigPedidos *config_pedido;

		Configuracoes();
        Configuracoes(bool);
};
#endif