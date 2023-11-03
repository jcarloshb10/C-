#include <iostream>
#include <conio.h>
#include <iomanip>
//#include "d:/conio/include/conio.h"
using namespace std;

void colocar_borde(int x1, int y1, int x2, int y2);
void colocar_ventanas(int x1,int y1, int x2,int y2,int col_fondo, int col_tex);

void colocar_borde(int x1, int y1, int x2, int y2)
{
	int i;
	for(i=x1+1;i<x2;i++)
	{
		gotoxy(i,y1);cout<<(char)205;
		gotoxy(i,y2);cout<<(char)205;
	}
	for(i=y1+1;i<y2;i++)
	{
		gotoxy(x1,i);cout<<(char)186;
		gotoxy(x2,i);cout<<(char)186;
	}
	gotoxy(x1,y1);cout<<(char)201;
	gotoxy(x1,y2);cout<<(char)200;
	gotoxy(x2,y1);cout<<(char)187;
	gotoxy(x2,y2);cout<<(char)188;
}

void colocar_ventanas(int x1,int y1, int x2,int y2,int col_fondo, int col_tex)
{
	window(x1,y1,x2,y2);
	textbackground(col_fondo);
	textcolor(col_tex);
	system("cls");
}

