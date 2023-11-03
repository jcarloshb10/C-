#include <iostream>
#include "conio.h"

using namespace std ; 

void marco(int x1,int y1, int x2, int y2);
void colocarventana (int x1, int y1, int x2, int y2, int colf, int colt);
void salir ();



void colocarventana (int x1, int y1, int x2, int y2, int colf, int colt)
{
	window(x1,y1,x2,y2); 
	textbackground (colf);
	textcolor(colt);
	clrscr();
}

void marco(int x1,int y1, int x2, int y2)
{
	int i; 
	for (i=x1;i<=x2;i++)
	{
		gotoxy(i,y1); cout<<(char)205;
		gotoxy(i,y2); cout<<(char)205;
	}
	
	for (i=y1;i<=y2;i++)
	{
		gotoxy(x1,i);cout<<(char)186; 
		gotoxy(x2,i);cout<<(char)186;
	}
	gotoxy(x1,y1);cout<<(char)201;
	gotoxy(x1,y2);cout<<(char)200;
	gotoxy(x2,y1);cout<<(char)187;
	gotoxy(x2,y2);cout<<(char)188;
}

void salir ()
{	
	colocarventana (1,6,102,32,11,0);
	marco(1,1,102,26);
	gotoxy(32,3);cout<<"GRACIAS POR UTILIZAR NUESTRO PROGRAMA"; 
	gotoxy(35,8);cout<<"HECHO POR: Jean Carlos Hernandez";
	gotoxy(46,9);cout<<"Brayan Sebastian Bastidas";
	gotoxy(35,11);cout<<"INGENIER"<<(char)161<<"A DE SISTEMAS GRUPO1";  
	gotoxy(40,12);cout<<"UNIVERSIDAD DE NARI"<<(char)164<<"O";
	gotoxy(49,13);cout<<"2018";
	getch();
}
