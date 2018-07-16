//---------------------------------------------------------------------------

#ifndef RecursosH
#define RecursosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class __declspec(delphiclass) Recursos: public TPersistent
{
	private:
	public:
		int id;
		UnicodeString recurso;
		int recursos_grupo_id;
};
#endif
