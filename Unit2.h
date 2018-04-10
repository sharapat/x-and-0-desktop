//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Menus.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Ani.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *StartItem;
	TMenuItem *ExitItem;
	TLabel *Label1;
	TLayout *Layout1;
	TLabel *Label2;
	TLabel *Label3;
	TLayout *GameLayout;
	TLayout *MainLayout;
	TLabel *Label4;
	TLabel *Label5;
	TLayout *LoadingLayout;
	TProgressBar *ProgressBar1;
	TLabel *Label6;
	TFloatAnimation *FloatAnimation1;
	TRectangle *Rectangle1;
	TRectangle *Rectangle2;
	TBitmapListAnimation *BitmapListAnimation1;
	TRectAnimation *RectAnimation1;
	TRectangle *Rectangle3;
	TRectangle *Panel1;
	TRectangle *Panel2;
	TRectangle *Panel3;
	TRectangle *Panel4;
	TRectangle *Panel5;
	TRectangle *Panel6;
	TRectangle *Panel7;
	TRectangle *Panel8;
	TRectangle *Panel9;
	TMenuItem *MainMenu;
	TRectangle *Gamer1;
	TRectangle *Gamer2;
	TLabel *Gamer1Name;
	TLabel *Gamer2Name;
	TLabel *Label7;
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall ExitItemClick(TObject *Sender);
	void __fastcall StartItemClick(TObject *Sender);
	void __fastcall Label4MouseEnter(TObject *Sender);
	void __fastcall Label4MouseLeave(TObject *Sender);
	void __fastcall Label4Click(TObject *Sender);
	void __fastcall FloatAnimation1Finish(TObject *Sender);
	void __fastcall Label5Click(TObject *Sender);
	void __fastcall MainMenuClick(TObject *Sender);
	void __fastcall Label7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
