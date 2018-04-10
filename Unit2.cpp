//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
bool f,  won, bot, botWin;
int winX, win0, cntImg;
char c[3][3];
TImage *newImg[10];
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	//bot = true;
	for(int i = 1; i <= 9; i++){
		newImg[i] = new TImage(NULL);
		newImg[i]->Parent = (TPanel*)FindComponent("Panel" + IntToStr(i));
		newImg[i]->Position->X = 24;
		newImg[i]->Position->Y = 22;
		newImg[i]->Height = 80;
		newImg[i]->Width = 80;
		newImg[i]->Name = "Img" + IntToStr(i);
		newImg[i]->OnClick = Image1Click;
	}
	cntImg = 9;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			c[i][j] = '*';
		}
	}
	f = true;
	Label1->Text = "Ходит x";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image1Click(TObject *Sender)
{

//-------------Один Игрок------------------------------------
	if(bot){
		if(won){
			return ;
		}
		TImage *I = (TImage*)Sender;
		String s = I->Name;
		s.Delete(1, 3);
		if(!I->Bitmap->IsEmpty()){
			return ;
		}
//**************** Ход Игрока************************
		int cnt = 0, n = StrToInt(s);
		n --;
		while(n >= 3){
			n -= 3;
			cnt++;
		}
		c[cnt][n] = 'x';
		I->Bitmap->LoadFromFile("images\\krestiki.png");

		for(int i = 0; i < 3; i++){
			if((c[i][0] == 'x' && c[i][1] == 'x' && c[i][2] == 'x')||
				c[0][i] == 'x' && c[1][i] == 'x' && c[2][i] == 'x'){
                won = true;
				Label1->Text = "Игра закончена";
				ShowMessage("X выиграл!!!");

				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						c[i][j] = '*';
					}
				}
				winX++;
				Label2->Text = IntToStr(winX);
				return ;
			}
		}
		if((c[0][0] == 'x' && c[1][1] == 'x' && c[2][2] == 'x')
		||(c[0][2] == 'x' && c[2][0] == 'x' && c[1][1] == 'x')){
			ShowMessage("X выиграл!!!");
			won = true;
			Label1->Text = "Игра закончена";
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					c[i][j] == '*';
				}
			}
			winX++;

			Label2->Text = IntToStr(winX);
			return ;
		}
		Label1->Text = "Ходит 0";
//******************************************************************************

//***************** Ход компютера***********************************************

		//Sleep(1000);
//***************** Победный ход ***********************************************
		TImage *BotImg;
   //	ShowMessage("pobedniy");
		for(int i = 0; i < 3; i++){
			if(c[i][0] == '0' && c[i][1] == '0' && c[i][2] == '*'){
				newImg[i*3+3]->Bitmap->LoadFromFile("images\\nolik.png");
				c[i][2] = '0';
				botWin = true;
				goto check;
			}
			if(c[i][0] == '0' && c[i][1] == '*' && c[i][2] == '0'){
				newImg[i*3+2]->Bitmap->LoadFromFile("images\\nolik.png");
				c[i][1] = '0';
				botWin = true;
				goto check;
			}
			if(c[i][0] == '*' && c[i][1] == '0' && c[i][2] == '0'){
				newImg[i*3+1]->Bitmap->LoadFromFile("images\\nolik.png");
				c[i][0] = '0';
				botWin = true;
				goto check;
			}
			if(c[0][i] == '*' && c[1][i] == '0' && c[2][i] == '0'){
				newImg[i+1]->Bitmap->LoadFromFile("images\\nolik.png");
				c[0][i] = '0';
				botWin = true;
				goto check;
			}
			if(c[0][i] == '0' && c[1][i] == '*' && c[2][i] == '0'){
				newImg[i+4]->Bitmap->LoadFromFile("images\\nolik.png");
				c[1][i] = '0';
				botWin = true;
				goto check;
			}
			if(c[0][i] == '0' && c[1][i] == '0' && c[2][i] == '*'){
				newImg[i+7]->Bitmap->LoadFromFile("images\\nolik.png");
				c[2][i] = '0';
				botWin = true;
				goto check;
			}
		}
		if(c[0][0] == '0' && c[1][1] == '0' && c[2][2] == '*'){
			newImg[9]->Bitmap->LoadFromFile("images\\nolik.png");
			c[2][2] = '0';
			botWin = true;
			goto check;
		}
		if(c[0][0] == '0' && c[1][1] == '*' && c[2][2] == '0'){
			newImg[5]->Bitmap->LoadFromFile("images\\nolik.png");
			c[1][1] = '0';
			botWin = true;
			goto check;
		}
		if(c[0][0] == '*' && c[1][1] == '0' && c[2][2] == '0'){
			newImg[1]->Bitmap->LoadFromFile("images\\nolik.png");
			c[0][0] = '0';
			botWin = true;
			goto check;
		}
		if(c[0][2] == '0' && c[1][1] == '0' && c[2][0] == '*'){
			newImg[7]->Bitmap->LoadFromFile("images\\nolik.png");
			c[2][0] = '0';
			botWin = true;
			goto check;
		}
		if(c[0][2] == '0' && c[1][1] == '*' && c[2][0] == '0'){
			newImg[5]->Bitmap->LoadFromFile("images\\nolik.png");
			c[1][1] = '0';
			botWin = true;
			goto check;
		}
		if(c[0][2] == '*' && c[1][1] == '0' && c[2][0] == '0'){
			newImg[3]->Bitmap->LoadFromFile("images\\nolik.png");
			c[0][2] = '0';
			botWin = true;
			goto check;
		}
//**************************** Мешающий ход ************************************
	   //	ShowMessage("meshayushiy");
		for(int i = 0; i < 3; i++){
			if(c[i][0] == 'x' && c[i][1] == 'x' && c[i][2] != '0'){
				newImg[i*3+3]->Bitmap->LoadFromFile("images\\nolik.png");
				c[i][2] = '0';
				goto check;
			}
			if(c[i][0] == 'x' && c[i][1] != '0' && c[i][2] == 'x'){
				newImg[i*3+2]->Bitmap->LoadFromFile("images\\nolik.png");
				c[i][1] = '0';
				goto check;
			}
			if(c[i][0] != '0' && c[i][1] == 'x' && c[i][2] == 'x'){
				newImg[i*3+1]->Bitmap->LoadFromFile("images\\nolik.png");
				c[i][0] = '0';
				goto check;
			}
			if(c[0][i] != '0' && c[1][i] == 'x' && c[2][i] == 'x'){
				newImg[i+1]->Bitmap->LoadFromFile("images\\nolik.png");
				c[0][i] = '0';
				goto check;
			}
			if(c[0][i] == 'x' && c[1][i] != '0' && c[2][i] == 'x'){
				newImg[i+4]->Bitmap->LoadFromFile("images\\nolik.png");
				c[1][i] = '0';
				goto check;
			}
			if(c[0][i] == 'x' && c[1][i] == 'x' && c[2][i] != '0'){
				newImg[i+7]->Bitmap->LoadFromFile("images\\nolik.png");
				c[2][i] = '0';
				goto check;
			}
		}
		if(c[0][0] == 'x' && c[1][1] == 'x' && c[2][2] != '0'){
			newImg[9]->Bitmap->LoadFromFile("images\\nolik.png");
			c[2][2] = '0';
			goto check;
		}
		if(c[0][0] == 'x' && c[1][1] != '0'&& c[2][2] == 'x'){
			newImg[5]->Bitmap->LoadFromFile("images\\nolik.png");
			c[1][1] = '0';
			goto check;
		}
		if(c[0][0] != '0' && c[1][1] == 'x' && c[2][2] == 'x'){
			newImg[1]->Bitmap->LoadFromFile("images\\nolik.png");
			c[0][0] = '0';
			goto check;
		}
		if(c[0][2] == 'x' && c[1][1] == 'x' && c[2][0] != '0'){
			newImg[7]->Bitmap->LoadFromFile("images\\nolik.png");
			c[2][0] = '0';
			goto check;
		}
		if(c[0][2] == 'x' && c[1][1] != '0' && c[2][0] == 'x'){
			newImg[5]->Bitmap->LoadFromFile("images\\nolik.png");
			c[1][1] = '0';
			goto check;
		}
		if(c[0][2] != '0' && c[1][1] == 'x' && c[2][0] == 'x'){
			newImg[3]->Bitmap->LoadFromFile("images\\nolik.png");
			c[0][2] = '0';
			goto check;
		}
	   //	ShowMessage("prosto");
		if(c[1][1] == '*'){
			newImg[5]->Bitmap->LoadFromFile("images\\nolik.png");
			c[1][1] = '0';
			goto check;
		}
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(c[i][j] != '0' && c[i][j] != 'x'){
				//ShowMessage(IntToStr(i) + " " + IntToStr(j));
					newImg[i*3+j+1]->Bitmap->LoadFromFile("images\\nolik.png");
					c[i][j] = '0';
					goto check;
				}
			}
		}
//***************** Проверка ***************************************************
		check:;
		for(int i = 0; i < 3; i++){
		if((c[i][0] == c[i][1] && c[i][1] == c[i][2] && c[i][2] != '*')
		||(c[0][i] == c[1][i] && c[0][i] != '*' && c[1][i] == c[2][i])){
				won = true;
				Label1->Text = "Игра закончена";
				ShowMessage("0 выиграл!!!");
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						c[i][j] = '*';
					}
				}
				if(botWin) win0++;
				Label2->Text = IntToStr(winX);
				Label3->Text = IntToStr(win0);

				return ;
		}
	}
		if((c[0][0] == c[1][1] && c[1][1] == c[2][2] && c[2][2] != '*')
		||(c[0][2] == c[1][1] && c[0][2] != '*' && c[1][1] == c[2][0])){
			ShowMessage((String)c[1][1] + " выиграл!!!");
			won = true;
			Label1->Text = "Игра закончена";
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					c[i][j] == '*';
				}
			}
			win0++;

			Label2->Text = IntToStr(winX);
			Label3->Text = IntToStr(win0);
			return ;
		}
		bool t = true;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(c[i][j] == '*') t = false;
			}
		}
		if(t){
			won = true;
			ShowMessage("Ничья!!!");
		}
		return ;
	}
//***************************************************

//****************Два Игрока*************************

	if(won){
		return ;
	}
	TImage *I = (TImage*)Sender;
	String s = I->Name;
	s.Delete(1, 3);
	if(!I->Bitmap->IsEmpty()){
		return ;
	}
	int cnt = 0, n = StrToInt(s);
	n --;
	while(n >= 3){
		n -= 3;
		cnt++;
	}
	if(f) c[cnt][n] = 'x';
	else c[cnt][n] = '0';
	if(f){
		I->Bitmap->LoadFromFile("images\\krestiki.png");
		Label1->Text = "Ходит 0";
	}
	else {
		I->Bitmap->LoadFromFile("images\\nolik.png");
		Label1->Text = "Ходит x";
	}
//*******************Проверка***********************************

	for(int i = 0; i < 3; i++){
		if((c[i][0] == c[i][1] && c[i][1] == c[i][2] && c[i][2] != '*')
		||(c[0][i] == c[1][i] && c[0][i] != '*' && c[1][i] == c[2][i])){
				won = true;
				Label1->Text = "Игра закончена";
				if(f){
					ShowMessage("X Выиграл!!!");
				}
				else {
					ShowMessage("0 Выиграл!!!");
				}
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						c[i][j] = '*';
					}
				}
				if(f){
					winX++;
				}
				else win0++;
				Label2->Text = IntToStr(winX);
				Label3->Text = IntToStr(win0);
				return ;
		}
	}
	if((c[0][0] == c[1][1] && c[1][1] == c[2][2] && c[2][2] != '*')
	||(c[0][2] == c[1][1] && c[0][2] != '*' && c[1][1] == c[2][0])){
		ShowMessage((String)c[1][1] + " выиграл!!!");
		won = true;
		Label1->Text = "Игра закончена";
		for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			c[i][j] == '*';
		}
	}
		if(f){
			winX++;
		}
		else win0++;

		Label2->Text = IntToStr(winX);
		Label3->Text = IntToStr(win0);
		return ;
	}
	bool t = true;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(c[i][j] == '*') t = false;
		}
	}
	if(t){
		won = true;
		ShowMessage("Ничья!!!");
	}

	f = !f;
}

//---------------------------------------------------------------------------

void __fastcall TForm2::ExitItemClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::StartItemClick(TObject *Sender)
{
	if(MainLayout->Visible){
		return ;
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			c[i][j] = '*';
		}
	}
	for(int i = 1; i<= cntImg; i++){
		delete(newImg[i]);
	}
	for(int i = 1; i <= 9; i++){
		newImg[i] = new TImage(NULL);
		newImg[i]->Parent = (TPanel*)FindComponent("Panel" + IntToStr(i));
		newImg[i]->Position->X = 20;
		newImg[i]->Position->Y = 20;
		newImg[i]->Height = 80;
		newImg[i]->Width = 80;
		newImg[i]->Name = "Img" + IntToStr(i);
		newImg[i]->OnClick = Image1Click;
	}
	Label1->Text = "Ходит х";
	cntImg = 9;
	botWin = false;
	won = false;
	f = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label4MouseEnter(TObject *Sender)
{
	TLabel *L = (TLabel*)Sender;
	L->Font->Size = 23;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Label4MouseLeave(TObject *Sender)
{
	TLabel *L = (TLabel*)Sender;
	L->Font->Size = 20;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Label4Click(TObject *Sender)
{
	TLabel *L = (TLabel*)Sender;
	if(L->Text == "Один игрок"){
    	bot = true;
		Gamer1Name->Text = "Игрок";
		Gamer2Name->Text = "Компьютер";
	}
	if(L->Text == "Два игрока") {
		bot = false;
		Gamer1Name->Text = "Игрок1";
		Gamer2Name->Text = "Игрок2";
    }
		bot = true;
	MainLayout->Visible = false;
	LoadingLayout->Visible = true;

	FloatAnimation1->Start();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FloatAnimation1Finish(TObject *Sender)
{
	LoadingLayout->Visible = false;
	GameLayout->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Label5Click(TObject *Sender)
{
   	bot = false;
	MainLayout->Visible = false;
	GameLayout->Visible = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm2::MainMenuClick(TObject *Sender)
{
	if(LoadingLayout->Visible){
		return ;
	}
	win0 = 0;
	winX = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			c[i][j] = '*';
		}
	}
	for(int i = 1; i<= cntImg; i++){
		delete(newImg[i]);
	}
	for(int i = 1; i <= 9; i++){
		newImg[i] = new TImage(NULL);
		newImg[i]->Parent = (TPanel*)FindComponent("Panel" + IntToStr(i));
		newImg[i]->Position->X = 20;
		newImg[i]->Position->Y = 20;
		newImg[i]->Height = 80;
		newImg[i]->Width = 80;
		newImg[i]->Name = "Img" + IntToStr(i);
		newImg[i]->OnClick = Image1Click;
	}
	Label1->Text = "Ходит х";
	cntImg = 9;
	won = false;
	f = true;
	bot = false;
	Label2->Text = "0";
    Label3->Text = "0";
	GameLayout->Visible = false;
	MainLayout->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Label7Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
