//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("PedidosDAO.cpp", FPedidosDAO); /* TDataModule: File Type */
USEFORM("PedidosProdutosDAO.cpp", FPedidosProdutosDAO); /* TDataModule: File Type */
USEFORM("PapeisView.cpp", FPapeisView);
USEFORM("PapelsDAO.cpp", FPapelsDAO); /* TDataModule: File Type */
USEFORM("ProdutosView.cpp", FProdutosView);
USEFORM("ProdutosDAO.cpp", FProdutosDAO); /* TDataModule: File Type */
USEFORM("Principal.CPP", FPrincipal);
USEFORM("PedidosView.cpp", FPedidosView);
USEFORM("LoginBox.cpp", FLoginBox);
USEFORM("LojasDAO.cpp", FLojasDAO); /* TDataModule: File Type */
USEFORM("ListaUsuariosView.cpp", FListaUsuariosView);
USEFORM("ListaTiposContatosView.cpp", FListaTiposContatosView);
USEFORM("ListaProdutosView.cpp", FListaProdutosView);
USEFORM("ListaUnidadesMedidasView.cpp", FListaUnidadesMedidasView);
USEFORM("ListaTiposEnderecosView.cpp", FListaTiposEnderecosView);
USEFORM("MarcasView.cpp", FMarcasView);
USEFORM("LojasView.cpp", FLojasView);
USEFORM("MarcasDAO.cpp", FMarcasDAO); /* TDataModule: File Type */
USEFORM("TiposEnderecosView.cpp", FTiposEnderecosView);
USEFORM("UnidadesMedidasDAO.cpp", FUnidadesMedidasDAO); /* TDataModule: File Type */
USEFORM("TiposEnderecosDAO.cpp", FTiposEnderecosDAO); /* TDataModule: File Type */
USEFORM("TiposContatosView.cpp", FTiposContatosView);
USEFORM("TiposContatosDAO.cpp", FTiposContatosDAO); /* TDataModule: File Type */
USEFORM("Vendas.cpp", FVendas);
USEFORM("VendasRecebimento.cpp", FVendasRecebimento);
USEFORM("VendasCpf.cpp", FVendasCpf);
USEFORM("UsuariosView.cpp", FUsuariosView);
USEFORM("UnidadesMedidasView.cpp", FUnidadesMedidasView);
USEFORM("UsuariosDAO.cpp", FUsuariosDAO); /* TDataModule: File Type */
USEFORM("RegioesDAO.cpp", FRegioesDAO); /* TDataModule: File Type */
USEFORM("ReferenciasBancariasDAO.cpp", FReferenciasBancariasDAO); /* TDataModule: File Type */
USEFORM("RecursosDAO.cpp", FResourceDAO); /* TDataModule: File Type */
USEFORM("SubcategoriasDAO.cpp", FSubcategoriasDAO); /* TDataModule: File Type */
USEFORM("ListaPedidosView.cpp", FListaPedidosView);
USEFORM("ConfiguracoesView.cpp", FConfiguracoesView);
USEFORM("ConfiguracoesDAO.cpp", FConfiguracoesDAO); /* TDataModule: File Type */
USEFORM("ContatosDAO.cpp", FContatosDAO); /* TDataModule: File Type */
USEFORM("ContasReceber.cpp", FContasReceber);
USEFORM("ContasFinalizadas.cpp", FContasFinalizadas);
USEFORM("ContasReceberFechamento.cpp", FContasReceberFechamento);
USEFORM("Caixa.cpp", FCaixa);
USEFORM("AuthDao.cpp", FAuthDAO); /* TDataModule: File Type */
USEFORM("AssociadosDAO.cpp", FAssociadosDAO); /* TDataModule: File Type */
USEFORM("ClientesView.cpp", FClientesView);
USEFORM("CategoriasDAO.cpp", FCategoriasDAO); /* TDataModule: File Type */
USEFORM("CategoriasView.cpp", FCategoriasView);
USEFORM("InfoFinanceirasDAO.cpp", FInfoFinanceirasDAO); /* TDataModule: File Type */
USEFORM("InformacoesProduto.cpp", FInformacoesProduto);
USEFORM("Importar.cpp", FImportar);
USEFORM("ListaGruposAssociadosView.cpp", FListaGruposAssociadosView);
USEFORM("ListaFornecedoresView.cpp", FListaFornecedoresView);
USEFORM("ListaMarcasView.cpp", FListaMarcasView);
USEFORM("ListaLojasView.cpp", FListaLojasView);
USEFORM("ListaClientesView.cpp", FListaClientesView);
USEFORM("LiberarAcesso.cpp", FLiberarAcesso);
USEFORM("ListaCategoriasView.cpp", FListaCategoriasView);
USEFORM("LinkarAplicativos.cpp", FLinkarAplicativos);
USEFORM("GruposAssociadosView.cpp", FGruposAssociadosView);
USEFORM("EnderecosDAO.cpp", FEnderecosDAO); /* TDataModule: File Type */
USEFORM("EmpresasDAO.cpp", FEmpresasDAO); /* TDataModule: File Type */
USEFORM("EmpresasView.cpp", FEmpresasView);
USEFORM("GrupoRecursosView.cpp", FGrupoRecursos);
USEFORM("GruposAssociadosDAO.cpp", FGruposAssociadosDAO); /* TDataModule: File Type */
USEFORM("FornecedoresView.cpp", FFornecedoresView);
USEFORM("GraficoVendas.cpp", FGraficoVendas);
USEFORM("GerenciarUsuarios.cpp", FGerenciarUsuarios);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TFPrincipal), &FPrincipal);
		Application->CreateForm(__classid(TFLoginBox), &FLoginBox);
		Application->CreateForm(__classid(TFGerenciarUsuarios), &FGerenciarUsuarios);
		Application->CreateForm(__classid(TFClientesView), &FClientesView);
		Application->CreateForm(__classid(TFListaClientesView), &FListaClientesView);
		Application->CreateForm(__classid(TFProdutosView), &FProdutosView);
		Application->CreateForm(__classid(TFInformacoesProduto), &FInformacoesProduto);
		Application->CreateForm(__classid(TFListaProdutosView), &FListaProdutosView);
		Application->CreateForm(__classid(TFPedidosView), &FPedidosView);
		Application->CreateForm(__classid(TFVendas), &FVendas);
		Application->CreateForm(__classid(TFVendasRecebimento), &FVendasRecebimento);
		Application->CreateForm(__classid(TFVendasCpf), &FVendasCpf);
		Application->CreateForm(__classid(TFCaixa), &FCaixa);
		Application->CreateForm(__classid(TFLiberarAcesso), &FLiberarAcesso);
		Application->CreateForm(__classid(TFContasReceber), &FContasReceber);
		Application->CreateForm(__classid(TFImportar), &FImportar);
		Application->CreateForm(__classid(TFLinkarAplicativos), &FLinkarAplicativos);
		Application->CreateForm(__classid(TFGraficoVendas), &FGraficoVendas);
		Application->CreateForm(__classid(TFContasReceberFechamento), &FContasReceberFechamento);
		Application->CreateForm(__classid(TFContasFinalizadas), &FContasFinalizadas);
		Application->CreateForm(__classid(TFConfiguracoesView), &FConfiguracoesView);
		Application->CreateForm(__classid(TFProdutosDAO), &FProdutosDAO);
		Application->CreateForm(__classid(TFMarcasDAO), &FMarcasDAO);
		Application->CreateForm(__classid(TFLojasDAO), &FLojasDAO);
		Application->CreateForm(__classid(TFSubcategoriasDAO), &FSubcategoriasDAO);
		Application->CreateForm(__classid(TFUnidadesMedidasDAO), &FUnidadesMedidasDAO);
		Application->CreateForm(__classid(TFCategoriasDAO), &FCategoriasDAO);
		Application->CreateForm(__classid(TFAssociadosDAO), &FAssociadosDAO);
		Application->CreateForm(__classid(TFAuthDAO), &FAuthDAO);
		Application->CreateForm(__classid(TFRegioesDAO), &FRegioesDAO);
		Application->CreateForm(__classid(TFTiposEnderecosDAO), &FTiposEnderecosDAO);
		Application->CreateForm(__classid(TFTiposContatosDAO), &FTiposContatosDAO);
		Application->CreateForm(__classid(TFGruposAssociadosDAO), &FGruposAssociadosDAO);
		Application->CreateForm(__classid(TFPedidosDAO), &FPedidosDAO);
		Application->CreateForm(__classid(TFPedidosProdutosDAO), &FPedidosProdutosDAO);
		Application->CreateForm(__classid(TFInfoFinanceirasDAO), &FInfoFinanceirasDAO);
		Application->CreateForm(__classid(TFReferenciasBancariasDAO), &FReferenciasBancariasDAO);
		Application->CreateForm(__classid(TFContatosDAO), &FContatosDAO);
		Application->CreateForm(__classid(TFEnderecosDAO), &FEnderecosDAO);
		Application->CreateForm(__classid(TFFornecedoresView), &FFornecedoresView);
		Application->CreateForm(__classid(TFListaFornecedoresView), &FListaFornecedoresView);
		Application->CreateForm(__classid(TFEmpresasView), &FEmpresasView);
		Application->CreateForm(__classid(TFEmpresasDAO), &FEmpresasDAO);
		Application->CreateForm(__classid(TFListaUsuariosView), &FListaUsuariosView);
		Application->CreateForm(__classid(TFUsuariosView), &FUsuariosView);
		Application->CreateForm(__classid(TFConfiguracoesDAO), &FConfiguracoesDAO);
		Application->CreateForm(__classid(TFUsuariosDAO), &FUsuariosDAO);
		Application->CreateForm(__classid(TFPapelsDAO), &FPapelsDAO);
		Application->CreateForm(__classid(TFListaPedidosView), &FListaPedidosView);
		Application->CreateForm(__classid(TFListaMarcasView), &FListaMarcasView);
		Application->CreateForm(__classid(TFMarcasView), &FMarcasView);
		Application->CreateForm(__classid(TFUnidadesMedidasView), &FUnidadesMedidasView);
		Application->CreateForm(__classid(TFListaUnidadesMedidasView), &FListaUnidadesMedidasView);
		Application->CreateForm(__classid(TFListaLojasView), &FListaLojasView);
		Application->CreateForm(__classid(TFLojasView), &FLojasView);
		Application->CreateForm(__classid(TFListaGruposAssociadosView), &FListaGruposAssociadosView);
		Application->CreateForm(__classid(TFGruposAssociadosView), &FGruposAssociadosView);
		Application->CreateForm(__classid(TFListaTiposEnderecosView), &FListaTiposEnderecosView);
		Application->CreateForm(__classid(TFTiposEnderecosView), &FTiposEnderecosView);
		Application->CreateForm(__classid(TFListaTiposContatosView), &FListaTiposContatosView);
		Application->CreateForm(__classid(TFTiposContatosView), &FTiposContatosView);
		Application->CreateForm(__classid(TFCategoriasView), &FCategoriasView);
		Application->CreateForm(__classid(TFListaCategoriasView), &FListaCategoriasView);
		Application->CreateForm(__classid(TFPapeisView), &FPapeisView);
		Application->CreateForm(__classid(TFResourceDAO), &FResourceDAO);
		Application->CreateForm(__classid(TFGruposAssociadosView), &FGruposAssociadosView);
		Application->Run();

	return 0;
}
//---------------------------------------------------------------------
