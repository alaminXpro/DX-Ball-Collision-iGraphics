/*
Original Author: MD. AL AMIN [https://linkedin.com/in/alaminxpro]
Last Updated: August 2023
Version: 1.0
*/
#include "iGraphics.h"
#include "bitmap_loader.h"
#include "iostream"
#include "stdlib.h"
#define sheight 600
#define swidth 600
using namespace std;

int colli = 0;
char buffer[256] = "0";
int ax = 0, ay = 0;
void intToString(int number, char *buffer) {
	sprintf(buffer, "%d", number);
}
struct Ball {
	int r = 255, g = 255, b = 255;
	int xBall, yBall;
	int dx = 5, dy = 7;
};
Ball b[2];
void bDefault(){
	b[0].dx = 5; b[0].dy = 3;
	b[0].xBall = 0; b[0].yBall = 0;

	b[1].dx = 3; b[1].dy = 5;
	b[1].xBall = swidth - 3; b[1].yBall = 0;
}
void collision(){
	int xdif = abs(b[0].xBall - b[1].xBall);
	int ydif = abs(b[0].yBall - b[1].yBall);
	if (xdif <= 5 && ydif <= 5){
		b[0].r = b[1].r = rand() % 255;
		b[0].g = b[1].g = rand() % 255;
		b[0].b = b[1].b = rand() % 255;
		PlaySound("col.wav", NULL, SND_ASYNC);
		colli++;
		intToString(colli, buffer);
	}
}



void ballChange(){
	for (int i = 0; i < 2; ++i){
		b[i].xBall += b[i].dx; b[i].yBall += b[i].dy;
		if (b[i].xBall >= swidth || b[i].xBall <= 0)
			b[i].dx *= (-1);
		if (b[i].yBall >= sheight || b[i].yBall <= 0)
			b[i].dy *= (-1);
	}
	collision();
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();
	for (int i = 0; i < 2; ++i){
		iSetColor(b[i].r, b[i].g, b[i].b);
		iFilledCircle(b[i].xBall, b[i].yBall, 30, 1000);
	}
	iText(ax - 50, ay, "Collision: ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(ax + 50, ay, buffer, GLUT_BITMAP_TIMES_ROMAN_24);
}




/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	ax = mx; ay = my;
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{


	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{

	}


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
void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{

	}
	if (key == GLUT_KEY_LEFT)
	{

	}

	if (key == GLUT_KEY_HOME)
	{

	}

}


int main()
{
	///srand((unsigned)time(NULL));
	bDefault();
	iSetTimer(10, ballChange);
	iInitialize(swidth, sheight, "Dx Ball Collision");
	///updated see the documentations
	iStart();
	return 0;
}