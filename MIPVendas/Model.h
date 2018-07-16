//---------------------------------------------------------------------------

#ifndef ModelH
#define ModelH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (__published, private, public) properties (__published, private, public) fields(__published, public, protected, private)
//---------------------------------------------------------------------------
class __declspec(delphiclass) Model : public TPersistent
{
	private:
        int Fid;
	public:
		__property int id = {read=Fid,write=Fid};
};
#endif