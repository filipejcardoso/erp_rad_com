//---------------------------------------------------------------------------

#ifndef RecursosGrupoPapelsH
#define RecursosGrupoPapelsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class __declspec(delphiclass) RecursosGrupoPapels : public TPersistent
{
	private:
	public:
		int id;
		int recursos_grupo_id;
		int papels_id;
        int crud;
};
#endif
