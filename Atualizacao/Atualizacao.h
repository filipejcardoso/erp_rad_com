//----------------------------------------------------------------------------
#ifndef AtualizacaoH
#define AtualizacaoH
//----------------------------------------------------------------------------
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <IniFiles.hpp>
#include <urlmon.h>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Data.DBXMySQL.hpp>
#include <iostream>

#pragma comment (lib, "urlmon.lib")
//----------------------------------------------------------------------------
class TFAtualizacao : public TForm
{
__published:
	TPanel *Panel1;
	TLabel *Label1;
	TImage *Image1;
	TProgressBar *ProgressBar1;
	TButton *ButtonCancelar;
	TLabel *statusdownload;
	TTimer *Timer1;
	TTimer *Timer2;
	TSQLConnection *SQLCONNECT;
	TSQLQuery *SQLQuery1;
	void __fastcall ButtonCancelarClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
private:
	void WcharToChar(wchar_t *pw,char *pc);
public:
	virtual __fastcall TFAtualizacao(TComponent *AOwner);
};
//----------------------------------------------------------------------------
extern TFAtualizacao *FAtualizacao;
//----------------------------------------------------------------------------
#endif


