#ifndef ConfigSatModelH
#define ConfigSatModelH

#include <System.hpp>
#include "ConfigSatEspelho.h"

class ConfigSatModel
{
	public:
		static ConfigSatEspelho* selectAll();
        static int update(ConfigSatEspelho *value);
};
#endif
