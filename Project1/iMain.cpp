/*
Original Author: S. M. Shahriar Nirjon
Last Modified by: Mohammad Saifur Rahman
last modified: October 13, 2015
Version: 2.0
*/


#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include<string.h>
#include<cstdlib>
# include "iGraphics.h"
using namespace std;

struct coin
{
	int  x;
	int y;
	coin(int it, int nm)
	{
		x = it;
		y = nm;
	}
};
struct bird
{
	int   x;
	int y;

	bird(int it, int nm)
	{
		x = it;
		y = nm;
	}
};
struct bomb
{
	int   x;
	int y;

	bomb(int it, int nm)
	{
		x = it;
		y = nm;
	}
};
struct firstaid
{
	int   x;
	int y;
	firstaid(int it, int nm)
	{
		x = it;
		y = nm;
	}
};

struct coin coin1(1100,0);
struct coin coin2(1100, 0);
struct coin coin3(1100, 0);

struct bird bird1(100, 30);

struct bomb bomb1(1100, 0);
struct bomb bomb2(1100, 0);
struct bomb bomb3(1100, 0);

struct firstaid firstaid1(1100, 0);

int mposx, mposy, dcy = 0;
int x1, x2, x3, x4,x5,x6,x7,x8;
int bx1 = 10,bx2=10,bx3=10;
int egg = 0;
int gamestate = 5;
int lifecounter = 0, score = 0;
bool flag = false, bird_up = true, bird_down = false, music_on = true, show = true, m = false,  bluster = false;

bool f_bomb1 = true, f_bomb2 = true, f_bomb3 = true;
bool f_coin1 = true, f_coin2 = true, f_coin3 = true;
bool f_firstAid = true;

bool f_b1 = true, f_b2 = true, f_b3 = true ;
bool f_c1 = true, f_c2 = true, f_c3 = true;

bool f_f1 = true;

bool eggcounter = false, bombsound = false;

int i = 0, j = 0, k = 6, blust = 0;
bool play_b = true, play_b2 = false, HighScore_b = true, HighScore_b2 = false, AboutUs_b = true, AboutUs_b2 = false, exit_b = true, exit_b2 = false, restart_b = true, restart_b2 = false,resume_b = true, resume_b2 = false;
int num,digit1,digit2,digit3,digitcounter=1;


char bc[18][600] = { "2.bmp", "3.bmp", "4.bmp", "5.bmp", "6.bmp", "7.bmp", "8.bmp", "9.bmp", "10.bmp", "11.bmp", "12.bmp", "13.bmp", "14.bmp", "15.bmp" };
char cc[4][20] = { "Coin_000.bmp", "Coin_001.bmp", "Coin_002.bmp", "Coin_003.bmp" };
char bk[4][20] = { "bc1.bmp", "bc2.bmp", "bc3.bmp", "bc4.bmp" };
char lifes[15][500] = { "health_bar000.bmp", "health_bar001.bmp", "health_bar002.bmp", "health_bar003.bmp", "health_bar004.bmp", "health_bar005.bmp", "health_bar006.bmp", "health_bar007.bmp", "health_bar008.bmp", "health_bar009.bmp", "health_bar010.bmp" };
char blusts[30][700] = { "fire_001_01.bmp", "fire_001_02.bmp", "fire_001_03.bmp", "fire_001_04.bmp", "fire_001_05.bmp", "fire_001_06.bmp", "fire_001_07.bmp", "fire_001_08.bmp", "fire_001_09.bmp", "fire_001_10.bmp", "fire_001_11.bmp", "fire_001_12.bmp", "fire_001_13.bmp", "fire_001_14.bmp", "fire_001_15.bmp", "fire_001_16.bmp", "fire_001_17.bmp", "fire_001_18.bmp", "fire_001_19.bmp", "fire_001_20.bmp" };
//char points[10][300] = { "front_0.bmp", "front_1.bmp", "front_2.bmp", "front_3.bmp", "front_4.bmp", "front_5.bmp", "front_6.bmp", "front_7.bmp", "front_8.bmp", "front_9.bmp" };

string scorestr, myText;
/*
function iDraw() is called again and again by the system.
*/
void difficulty();
void collison();
void Menu();
void highscore();
void Aboutus();
void life();
void blustert();
void gameover();
void wholegamepauser();
void showHighscore();
void customfont();
void restart();
void soundeffect();


void iDraw()
{


	//place your drawing codes here
	iClear();
	if (gamestate == 0)//menu
	{
		Menu();
	}
	if (gamestate == 1)
	{
		highscore();
	}
	if (gamestate == 2)
	{
		Aboutus();//-----------------------------------------
	}
	if (gamestate == 4)
	{
		iShowBMP(0, 0, "pause.bmp");
		if(restart_b)iShowBMP2(200, 750, "restart.bmp", 255);
		if (restart_b2)iShowBMP2(200, 750, "restart2.bmp", 255);
		if (resume_b)iShowBMP2(200, 600, "resume.bmp", 255);
		if (resume_b2)iShowBMP2(200, 600, "resume2.bmp", 255);
		if (exit_b)iShowBMP2(1450, 150, "exit.bmp", 255);
		if (exit_b2)iShowBMP2(1450, 150, "exit2.bmp", 255);
	}
	if (gamestate == 5)
	{

	

		gameover();
		if (exit_b)iShowBMP2(800, 150, "exit.bmp", 255);
		if (exit_b2)iShowBMP2(800, 150, "exit2.bmp", 255);



	}
	if (gamestate == 3)
	{
		iClear();

		iResumeTimer(x1);
		iResumeTimer(x2);
		iResumeTimer(x3);
		iResumeTimer(x4);
		iResumeTimer(x5);
		iResumeTimer(x6);
		iResumeTimer(x7);


			iShowBMP(0, 0, "bk1.bmp");
			collison();
			iShowBMP2(bird1.x, bird1.y, bc[i], 255);//

			if (f_bomb1)iShowBMP2(bomb1.x, bomb1.y, "bomb.bmp", 255);
			if (f_bomb2)iShowBMP2(bomb2.x, bomb2.y, "bomb.bmp", 255);
			if (f_bomb3)iShowBMP2(bomb3.x, bomb3.y, "bomb.bmp", 255);

			if (f_coin1)iShowBMP2(coin1.x, coin1.y, cc[j], 255);
			if (f_coin2)iShowBMP2(coin2.x, coin2.y, cc[j], 255);
			if (f_coin3)iShowBMP2(coin3.x, coin3.y, cc[j], 255);

			if (f_firstAid)iShowBMP2(firstaid1.x, firstaid1.y, "first aid.bmp", 255);

			iShowBMP2(1850, 950, "pause-button.bmp", 255);
			life();
			scorestr = to_string(score);
			char* score_char = (char*)scorestr.c_str();
			iSetColor(250,40,96);
			iText(1700, 950, " Points :", GLUT_BITMAP_HELVETICA_18);
			iText(1800, 950, score_char, GLUT_BITMAP_HELVETICA_18);
			if (k == 0)gameover();

		
	}
	
}
/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//------------------------------------------------------------------------------------------
		if (gamestate == 0)
		{
			if ((my >= 750 && my <= 750 + 96) && (mx >= 350 && mx <= 260 + 350))
			{
				gamestate = 3;
			}
			if ((my >= 600 && my <= 600 + 96) && (mx >= 350 && mx <= 260 + 350))
			{

				gamestate = 1;
			}
			if ((my >= 450 && my <= 450 + 96) && (mx >= 350 && mx <= 260 + 350))
			{

				gamestate = 2;
			}
			if ((my >= 300 && my <= 300 + 96) && (mx >= 350 && mx <= 260 + 350))
			{

				exit(0);
			}
		}
		//--------------------------------------------------------------------------

		if (gamestate == 1)
		{

			if ((my >= 100 && my <= 100 + 96) && (mx >= 1550 && mx <= 260 + 1550))
			{

				gamestate = 0;
			}

		}

		//=====================================================================================
		if (gamestate == 2)
		{

			if ((my >= 100 && my <= 100 + 96) && (mx >= 1550 && mx <= 260 + 1550))
			{

				gamestate = 0;
			}

		}
		//===================================================================================
		if (gamestate == 4)
		{

			if ((my >= 150 && my <= 150 + 96) && (mx >= 1450 && mx <= 260 + 1450))
			{

				gamestate = 0;
				restart();
			}
			if ((my >= 600 && my <= 600 + 96) && (mx >= 200 && mx <= 260 + 200))
			{

				gamestate = 3;
				iResumeTimer(x1);
				iResumeTimer(x2);
				iResumeTimer(x3);
				iResumeTimer(x4);
				iResumeTimer(x5);
				iResumeTimer(x6);
				iResumeTimer(x7);

			}
			if ((my >= 750 && my <= 750 + 96) && (mx >= 200 && mx <= 260 + 200)){

				restart();
				gamestate = 3;


			}

		}
		if (gamestate == 3){//game

			if ((my >= 950 && my <= 950 + 96) && (mx >= 1850 && mx <= 260 + 1850))
			{

				gamestate = 4;
				iPauseTimer(x1);
				iPauseTimer(x2);
				iPauseTimer(x3);
				iPauseTimer(x4);
				iPauseTimer(x5);
				iPauseTimer(x6);
				iPauseTimer(x7);
			}

		}
		if (gamestate==5){


			if ((my >= 150 && my <= 150 + 96) && (mx >= 800 && mx <= 260 + 800))
			{

				gamestate = 0;
				k = 4;
				score = 0;//last bug?''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
			}

		}

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my){
	//==============================================================================
	if (gamestate == 0){//menu
		if ((my >= 750 && my <= 750 + 96) && (mx >= 350 && mx <= 260 + 350))
		{
			play_b = false;
			play_b2 = true;
		}
		else{
			play_b = true;
			play_b2 = false;
		}

		if ((my >= 600 && my <= 600 + 96) && (mx >= 350 && mx <= 260 + 350))
		{

			HighScore_b = false;
			HighScore_b2 = true;
		}
		else{
			HighScore_b = true;
			HighScore_b2 = false;
		}


		if ((my >= 450 && my <= 450 + 96) && (mx >= 350 && mx <= 260 + 350))
		{

			AboutUs_b = false;
			AboutUs_b2 = true;
		}

		else{
			AboutUs_b = true;
			AboutUs_b2 = false;
		}
		if ((my >= 300 && my <= 300 + 96) && (mx >= 350 && mx <= 260 + 350))
		{

			exit_b = false;
			exit_b2 = true;
		}
		else{
			exit_b = true;
			exit_b2 = false;
		}
	}
	//===========================================================================
	if (gamestate == 1){
		if ((my >= 100 && my <= 100 + 96) && (mx >= 1550 && mx <= 260 + 1550))
		{

			exit_b = false;
			exit_b2 = true;
		}
		else{
			exit_b = true;
			exit_b2 = false;
		}
	}
	//===========================================================================
	if (gamestate == 2){
		if ((my >= 100 && my <= 100 + 96) && (mx >= 1550 && mx <= 260 + 1550))
		{
			exit_b = false;
			exit_b2 = true;
		}
		else{
			exit_b = true;
			exit_b2 = false;
		}
	}
	//==========================================================================

	if (gamestate == 4){


		if ((my >= 150 && my <= 150 + 96) && (mx >= 1450 && mx <= 260 + 1450))
		{

			exit_b = false;
			exit_b2 = true;
		}
		else{
			exit_b = true;
			exit_b2 = false;
		}
		if ((my >= 600 && my <= 600 + 96) && (mx >= 200 && mx <= 260 + 200))
		{

			resume_b = false;
			resume_b2 = true;
		}
		else{
			resume_b = true;
			resume_b2 = false;
		}

		if ((my >= 750 && my <= 750 + 96) && (mx >= 200 && mx <= 260 + 200))
		{

			restart_b = false;
			restart_b2 = true;
		}
		else{
			restart_b = true;
			restart_b2 = false;
		}

	}

	if (gamestate == 5){
		if ((my >= 150 && my <= 150 + 96) && (mx >= 800 && mx <= 260 + 800))
		{

			exit_b = false;
			exit_b2 = true;
		}
		else{
			exit_b = true;
			exit_b2 = false;
		}
	}
	}

	//===========================================================================

void blustert()
{
	iShowBMP2(bird1.x, bird1.y, "fire_001_07.bmp", 255);
}
void changepic()
{
	i++;
	if (i>12)i = 0;
	j++;
	if (j>3)j = 0;
	blust++;
	if (blust > 17)blust = 0;
	/*egg++;
	if (egg>8)egg = 0;*/
}
void Menu()
{

	iShowBMP(0, 0, "menu.bmp");
	iPauseTimer(x1);
	iPauseTimer(x2);
	iPauseTimer(x3);
	iPauseTimer(x4);
	iPauseTimer(x5);
	iPauseTimer(x6);
	iPauseTimer(x7);

	if (play_b)iShowBMP2(350, 750, "play.bmp", 255);
	if (play_b2)iShowBMP2(350, 750, "play2.bmp", 255);
	if (HighScore_b)iShowBMP2(350, 600, "score.bmp", 255);
	if (HighScore_b2)iShowBMP2(350, 600, "score2.bmp", 255);
	if (AboutUs_b)iShowBMP2(350, 450, "credits.bmp", 255);
	if (AboutUs_b2)iShowBMP2(350, 450, "credits2.bmp", 255);
	if (exit_b)iShowBMP2(350, 300, "exit.bmp", 255);
	if (exit_b2)iShowBMP2(350, 300, "exit2.bmp", 255);


}
void highscore()
{
	iShowBMP(0, 0, "tengo.bmp");
	if (exit_b)iShowBMP2(1550, 100, "exit.bmp", 255);
	if (exit_b2)iShowBMP2(1550, 100, "exit2.bmp", 255);

	ifstream MyReadFile("filename.txt");

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		char* score_char1 = (char*)myText.c_str();
		customfont();
	}

	


}
void Aboutus(){
	iShowBMP(0, 0, "aboutus.bmp");
	if(exit_b)iShowBMP2(1550, 100, "exit.bmp", 255);
	if (exit_b2)iShowBMP2(1550, 100, "exit2.bmp", 255);

}
void collison(){

	if (((bird1.y <= bomb1.y && bird1.y + 90 >= bomb1.y) && (bomb1.x >= bird1.x && bomb1.x <= bird1.x + 120)) || ((bird1.y <= bomb1.y + 70 && bird1.y + 90 >= bomb1.y + 70) && (bomb1.x >= bird1.x && bomb1.x <= bird1.x + 120))){
		f_bomb1 = false;
		blustert();
		//soundeffect();
	}
	if (((bird1.y <= bomb2.y && bird1.y + 90 >= bomb2.y) && (bomb2.x >= bird1.x && bomb2.x <= bird1.x + 120)) || ((bird1.y <= bomb2.y + 70 && bird1.y + 90 >= bomb2.y + 70) && (bomb2.x >= bird1.x && bomb2.x <= bird1.x + 120))){
		f_bomb2 = false;
		blustert(); 
			//soundeffect();
	}
	if (((bird1.y <= bomb3.y && bird1.y + 90 >= bomb3.y) && (bomb3.x >= bird1.x && bomb3.x <= bird1.x + 120)) || ((bird1.y <= bomb3.y + 70 && bird1.y + 90 >= bomb3.y + 70) && (bomb3.x >= bird1.x && bomb3.x <= bird1.x + 120))){
		f_bomb3 = false;
		//blustert();
	}



	if (((bird1.y <= coin1.y && bird1.y + 90 >= coin1.y) && (coin1.x >= bird1.x && coin1.x <= bird1.x + 120)) || ((bird1.y <= coin1.y + 70 && bird1.y + 90 >= coin1.y + 70) && (coin1.x >= bird1.x && coin1.x <= bird1.x + 120))){
		f_coin1 = false;
	}
	if (((bird1.y <= coin2.y && bird1.y + 90 >= coin2.y) && (coin2.x >= bird1.x && coin2.x <= bird1.x + 120)) || ((bird1.y <= coin2.y + 70 && bird1.y + 90 >= coin2.y + 70) && (coin2.x >= bird1.x && coin2.x <= bird1.x + 120))){
		f_coin2 = false;
		
	}
	if (((bird1.y <= coin3.y && bird1.y + 90 >= coin3.y) && (coin3.x >= bird1.x && coin3.x <= bird1.x + 120)) || ((bird1.y <= coin3.y + 70 && bird1.y + 90 >= coin3.y + 70) && (coin3.x >= bird1.x && coin3.x <= bird1.x + 120))){
		f_coin3 = false;
	}


	if (((bird1.y <= firstaid1.y && bird1.y + 90 >= firstaid1.y) && (firstaid1.x >= bird1.x && firstaid1.x <= bird1.x + 120)) || ((bird1.y <= firstaid1.y + 70 && bird1.y + 90 >= firstaid1.y + 70) && (firstaid1.x >= bird1.x && firstaid1.x <= bird1.x + 120))){
		f_firstAid = false;

	}

}
void gameover(){

	iShowBMP(0, 0, "gameover.bmp");
	gamestate = 5;

	if (score>num)
	{
		ofstream MyFile("filename.txt");

		// Write to the file
		MyFile << score;

		// Close the file
		MyFile.close();
	}
	
}
/*void bendicion(){

	eggy=bird1.y;
	if(egger){
	if (k >= 10){
		iShowBMP2(bird1.x, eggy, egg23[egg], 255);
	}
	eggy-=10;
	if(eggy<=61)egger=false;
	}
	egger=true;//////////////////////////////////////////////////
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'm')
	{
		if (music_on){
			music_on = false;
			PlaySound(0, 0, 0);
		}
		else{
			music_on = true;
			PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
	if (key == 'p'){
		iPauseTimer(x1);
		iPauseTimer(x2);
		iPauseTimer(x3);
		iPauseTimer(x4);
		iPauseTimer(x5);
		iPauseTimer(x6);
		iPauseTimer(x7);
	}
	if (key == 'r'){
		iResumeTimer(x1);
		iResumeTimer(x2);
		iResumeTimer(x3);
		iResumeTimer(x4);
		iResumeTimer(x5);
		iResumeTimer(x6);
		iResumeTimer(x7);
	}
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void bird(){


	if (bird1.y >= 980) bird1.y = 950;
	if (bird_up){

		dcy += 5;
		dcy += 5;


		bird1.y += 5;
		bird1.y += 5;


	}

	if (dcy == 200){
		bird_up = false;
		bird_down = true;
		dcy = 0;

	}
	if (bird1.y - 30 <= 0) {
		bird_down = false;



	}


	if (bird_down){


		bird1.y -= 10;

	}


}
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_UP)
	{

		bird_up = true, bird_down = false;


		iSetTimer(80, bird);

	}


}
void bomb_1(){
	if (f_b1){
		bomb1.y = rand() % 900;
		f_b1 = false;
	}
	if (bomb1.x <= 80) {
		f_b1 = true;
		bomb1.x = 1900;
		if (f_bomb1==false)
		{
			k--; k--;
			if (k<0)k = 0;
		}
		f_bomb1 = true;
	}
	bomb1.x -= bx1;

}
void bomb_2(){
	if (f_b2){
		bomb2.y = rand() % 900;
		//if (bomb2.y - bomb1.y <= 300 || bomb1.y - bomb2.y <= 300) bomb2.y += 300;
		f_b2 = false;
	}
	if (bomb2.x <= 80) {
		f_b2 = true;
		bomb2.x = 1900;
		if (f_bomb2 == false){
			k--;
			k--;
			if (k<0)k = 0;
		}
		f_bomb2 = true;
	}
	bomb2.x -= bx2;
}
void bomb_3(){
	if (f_b3){
		bomb3.y = rand() % 900;
		f_b3 = false;
	}
	if (bomb3.x <= 80) {
		f_b3 = true;
		bomb3.x = 1900;
		if (f_bomb3 == false){
			k--; k--;
			if (k<0)k = 0;
		}
		f_bomb3 = true;
	}
	bomb3.x -= bx3;
}


void coin_1(){
	if (f_c1){
		coin1.y = rand() % 900;
		f_c1 = false;
	}
	if (coin1.x <= 80) {
		f_c1 = true;
		coin1.x = 1900;
		if (f_coin1 == false){
			score++;
			difficulty();
			if (k>10)k = 10;
		}
		f_coin1 = true;
	}
	coin1.x -= 10;

}
void coin_2(){
	if (f_c2){
		coin2.y = rand() % 900;
		f_c2 = false;
	}
	if (coin2.x <= 80) {
		f_c2 = true;
		coin2.x = 1900;
		if (f_coin2 == false){
			score++;
			difficulty();
			if (k>10)k = 10;
		}
		f_coin2 = true;
	}
	coin2.x -= 10;

}
void coin_3(){
	if (f_c3){
		coin3.y = rand() % 900;
		f_c3 = false;
	}
	if (coin3.x <= 80) {
		f_c3 = true;
		coin3.x = 1900;
		if (f_coin3 == false){
			score++;
			difficulty();
			if (k>10)k = 10;
		}
		f_coin3 = true;
	}
	coin3.x -= 10;

}
void firstAid(){
	if (f_f1){
		firstaid1.y = rand() % 900;
		f_f1 = false;
	}
	if (firstaid1.x <= 150) {
		f_f1 = true;
		firstaid1.x = 1900;
		if (f_firstAid == false){
			k++;
			if (k>10)k = 10;
		}
		f_firstAid = true;
	}
	firstaid1.x -= 10;

}

void life(){

	iShowBMP2(50, 950, lifes[k], 255);

}
void difficulty()
{
	if (score % 5 == 0)
	{
		bx1 += 5;
		bx2 += 5;
		bx3 += 5;
	}
}
void showHighscore()
{

	ifstream MyReadFile("filename.txt");

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		cout << myText;
	}

	num = std::stoi(myText);


}
void customfont(){


	int replacenum = num;
		digit1=replacenum % 10;
		digit2 = (replacenum/10) % 10;
		digit3 = (replacenum/100) % 10;
		cout << " digit1 = " << digit1 << endl;
		cout << " digit2 = " << digit2 << endl;
		cout << " digit3 = " << digit3 << endl;
		///////////////////////////////////////////////////
		switch (digit1) {
		case 0:
			iShowBMP2(450 + 1100, 500, "front_0.bmp", 255);
			break;
		case 1:
			iShowBMP2(450 + 1100, 500, "front_1.bmp", 255);
			break;
		case 2:
			iShowBMP2(450 + 1100, 500, "front_2.bmp", 255);
			break;
		case 3:
			iShowBMP2(450 + 1100, 500, "front_3.bmp", 255);
			break;
		case 4:
			iShowBMP2(450 + 1100, 500, "front_4.bmp", 255);
			break;
		case 5:
			iShowBMP2(450 + 1100, 500, "front_5.bmp", 255);
			break;
		case 6:
			iShowBMP2(450 + 1100, 500, "front_6.bmp", 255);
			break;
		case 7:
			iShowBMP2(450 + 1100, 500, "front_7.bmp", 255);
			break;
		case 8:
			iShowBMP2(450 + 1100, 500, "front_8.bmp", 255);
			break;
		case 9:
			iShowBMP2(450 + 1100, 500, "front_9.bmp", 255);
			break;

		default:
			cout << "Invalid  digit 1" << digit1<< endl;
		}
	/////////////////////////////////////////////////////////////////////////
		switch (digit2) {
		case 0:
			iShowBMP2(350 + 1100, 500, "front_0.bmp", 255);
			break;
		case 1:
			iShowBMP2(350 + 1100, 500, "front_1.bmp", 255);
			break;
		case 2:
			iShowBMP2(350 + 1100, 500, "front_2.bmp", 255);
			break;
		case 3:
			iShowBMP2(350 + 1100, 500, "front_3.bmp", 255);
			break;
		case 4:
			iShowBMP2(350 + 1100, 500, "front_4.bmp", 255);
			break;
		case 5:
			iShowBMP2(350 + 1100, 500, "front_5.bmp", 255);
			break;
		case 6:
			iShowBMP2(350 + 1100, 500, "front_6.bmp", 255);
			break;
		case 7:
			iShowBMP2(350 + 1100, 500, "front_7.bmp", 255);
			break;
		case 8:
			iShowBMP2(350 + 1100, 500, "front_8.bmp", 255);
			break;
		case 9:
			iShowBMP2(350 + 1100, 500, "front_9.bmp", 255);
			break;

		default:
			cout << "Invalid " << endl;
		}
		//////////////////////////////////////////////
		switch (digit3) {
		case 0:
			iShowBMP2(250 + 1100, 500, "front_0.bmp", 255);
			break;
		case 1:
			iShowBMP2(250 + 1100, 500, "front_1.bmp", 255);
			break;
		case 2:
			iShowBMP2(250 + 1100, 500, "front_2.bmp", 255);
			break;
		case 3:
			iShowBMP2(250 + 1100, 500, "front_3.bmp", 255);
			break;
		case 4:
			iShowBMP2(250 + 1100, 500, "front_4.bmp", 255);
			break;
		case 5:
			iShowBMP2(250 + 1100, 500, "front_5.bmp", 255);
			break;
		case 6:
			iShowBMP2(250 + 1100, 500, "front_6.bmp", 255);
			break;
		case 7:
			iShowBMP2(450 + 1100, 500, "front_7.bmp", 255);
			break;
		case 8:
			iShowBMP2(450 + 1100, 500, "front_8.bmp", 255);
			break;
		case 9:
			iShowBMP2(450 + 1100, 500, "front_9.bmp", 255);
			break;

		default:
			cout << "Invalid " << endl;
		}



}
void restart()
{

	 coin coin1(1100, 0);
	 coin coin2(1100, 0);
	 coin coin3(1100, 0);
	 
	 struct bird bird1(100, 30);

	 bomb bomb1(1100, 0);
	 bomb bomb2(1100, 0);
	 bomb bomb3(1100, 0);

	firstaid firstaid1(1100, 0);
	f_bomb1 = true; f_bomb2 = true; f_bomb3 = true;
	f_coin1 = true; f_coin2 = true; f_coin3 = true;
    f_firstAid = true;

	bx1 = 10; bx2 = 10; bx3 = 10;
	dcy = 0;
	score = 0;
	k = 4;
}
void soundeffect(){

	music_on = false;
	bombsound = true;

	if (bombsound)
	{
			PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
	}

}
int main()
{

	//place your own initialization codes here.

	 x3 =iSetTimer(50, bomb_1);
	 x4 = iSetTimer(20, bomb_2);
	 x6 = iSetTimer(100, bomb_3);

	 x2 = iSetTimer(100, coin_1);
	 x1 = iSetTimer(200, coin_2);
	 x7 = iSetTimer(100, coin_3);

	 x8 = iSetTimer(10, firstAid);
	
	 x5=iSetTimer(50, changepic);
	 //iSetTimer(10, difficulty);
	if (music_on)PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
	if (bombsound)PlaySound("Explosion+4.wav", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(1900, 1000, "Flying Bird");
	showHighscore();
	//customfont();
	iStart();
	return 0;
}
