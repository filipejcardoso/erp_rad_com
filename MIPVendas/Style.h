//---------------------------------------------------------------------------

#ifndef StyleH
#define StyleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Style
{
	private:

	public:
		static void setTop(TLabel *titulo, TLabel *subtitulo);
		static void setTop(TLabel *titulo, TLabel *subtitulo, UnicodeString modulo);
		static void setTop(TLabel *titulo, TLabel *subtitulo, TLabel *moduloLabel, UnicodeString modulo);
};
#endif
