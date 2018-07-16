//---------------------------------------------------------------------------

#ifndef MaskBitsH
#define MaskBitsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <REST.Json.hpp>
#include <System.JSON.hpp>
#include <Rtti.hpp>
//---------------------------------------------------------------------------
class MaskBits
{
	private:

	public:
		static bool mask(int value, int mask);
};
#endif
