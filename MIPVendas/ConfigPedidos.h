//---------------------------------------------------------------------------

#ifndef ConfigPedidosH
#define ConfigPedidosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#include "Associados.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, private, public) properties (__published, private, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class ConfigPedidos : public TObject
{
	private:

	public:
		int id;
		int validade;
		Associados *associado;

		ConfigPedidos();
};
#endif