#ifndef ConfigPdvModelH
#define ConfigPdvModelH

#include <System.hpp>
#include "ConfigPdvEspelho.h"

class ConfigPdvModel
{
	public:
		static ConfigPdvEspelho* selectAll();
        static int update(ConfigPdvEspelho *value);
};
#endif
