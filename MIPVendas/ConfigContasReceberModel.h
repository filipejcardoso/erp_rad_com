#ifndef ConfigContasRecberModelH
#define ConfigContasRecberModelH

#include <System.hpp>
#include "ConfigContasReceberEspelho.h"

class ConfigContasReceberModel
{
	public:
		static ConfigContasReceberEspelho* selectAll();
        static int update(ConfigContasReceberEspelho *value);
};
#endif
