//---------------------------------------------------------------------------

#ifndef SistemaH
#define SistemaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "APIRest.h"
#include "User.h"
#include "Empresas.h"
#include "Configuracoes.h"
//---------------------------------------------------------------------------
class Sistema : public TObject
{
	private:
		User *Fusuario;
		APIRest *Fapi;
		Empresas *Fempresa;
		Configuracoes *Fconfiguracao;

		void setUsuario(User*);
		void setAPIRest(APIRest*);
		void setEmpresa(Empresas*);
		void setConfiguracao(Configuracoes*);
	public:
		__property User *usuario = {read=Fusuario,write=setUsuario};
		__property APIRest *api = {read=Fapi,write=setAPIRest};
		__property Empresas *empresa = {read=Fempresa,write=setEmpresa};
		__property Configuracoes *configuracao = {read=Fconfiguracao,write=setConfiguracao};

        Sistema();
};
//---------------------------------------------------------------------------
extern Sistema *SISTEMA;
//---------------------------------------------------------------------------
#endif
