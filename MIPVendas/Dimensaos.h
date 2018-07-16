//---------------------------------------------------------------------------

#ifndef DimensaosH
#define DimensaosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class __declspec(delphiclass) Dimensaos : public TPersistent
{
private:

public:
	int id;
	float peso;
	float altura;
	float largura;
	float comprimento;
	float diametro;
};
//---------------------------------------------------------------------------
#endif
