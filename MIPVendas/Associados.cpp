//---------------------------------------------------------------------------

#pragma hdrstop

#include "Associados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Associados::Associados()
{
	grupos_associado = new GruposAssociados();
	info_financeira = new InfoFinanceiras();

	contato = new TList();
	referencias_bancaria = new TList();
	endereco = new TList();
}
//---------------------------------------------------------------------------
Contatos* Associados::instance_contato()
{
    return new Contatos();
}
//---------------------------------------------------------------------------
ReferenciasBancarias* Associados::instance_referencias_bancaria()
{
    return new ReferenciasBancarias();
}
//---------------------------------------------------------------------------
Enderecos* Associados::instance_endereco()
{
    return new Enderecos();
}
//---------------------------------------------------------------------------
TRttiInstanceType* Associados::cls_contato()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(Contatos)));

    return cls;
}
//---------------------------------------------------------------------------
TRttiInstanceType* Associados::cls_referencias_bancaria()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(ReferenciasBancarias)));

    return cls;
}
//---------------------------------------------------------------------------
TRttiInstanceType* Associados::cls_endereco()
{
	TRttiContext context;

	// Get class RTTI
	TRttiInstanceType *cls = dynamic_cast<TRttiInstanceType*>
	(context.GetType(__delphirtti(Enderecos)));

    return cls;
}
//---------------------------------------------------------------------------

