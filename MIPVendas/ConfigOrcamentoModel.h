#ifndef ConfigOrcamentoModelH
#define ConfigOrcamentoModelH

#include <System.hpp>
#include "ConfigOrcamentoEspelho.h"

class ConfigOrcamentoModel
{
	public:
		static ConfigOrcamentoEspelho* selectAll();
        static int update(ConfigOrcamentoEspelho *value);
};
#endif
