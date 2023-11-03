#include<iostream>
#include<string.h>
#include<conio.h>
#include "conio.h"

using namespace std;

void ValidarTexto(char txt[200],int tam)
{
	unsigned char let=0;
	char text[200];
	int i=0;
	while(let != 13 || text[0]==0 || text[0]==8)
	{
		let = getch();
		if(i<tam)
		{
			if(let>97 && let<=122 || let>=65 && let<=90 || let==164 || let==165 || let==32)
			{
				cout<<let;
				text[i]=let;
				i++;
			}
		}		
		if(let==8)
		{
			if(i>0)
			{
				cout<<let<<" "<<let;
				i--;
				text[i]=8;
			}
		}				
	}
	text[i]='\0';
	strcpy(txt,text);
}

void ValidarEnteros(char num[20],int tam)
{
	char let=0;
	char text[50];
	int i=0;
	while(let!=13 || text[0]==0 || text[0]==8)
	{
		let=getch();	
		if(i<tam)
		{
			if(let>=48 && let<=57 && i<tam)
			{
				cout<<let;
				text[i]=let;
				i++;
			}
		}
		if(let==8)
		{
			if(i>0)
			{
				cout<<let<<" "<<let;
				i--;
				text[i]=8;
			}
		}			
		
	}
	text[i]='\0';
	strcpy(num,text);
}


void DefinirVentana(int x1,int y1,int x2,int y2,int colF,int colT)
{
	window(x1,y1,x2,y2);
	textbackground(colF);
	textcolor(colT);
	clrscr();
}

void tVentana()
{
	system("mode con: cols=103 lines=32");
}

void ColocarBorde(int x1,int y1,int x2,int y2)
{
	for(int i=x1;i<=x2;i++)
	{
		gotoxy(i,y1);cout<<(char)205;
		gotoxy(i,y2);cout<<(char)205;
	}
	for(int i=y1;i<=y2;i++)
	{
		gotoxy(x1,i);cout<<(char)186;
		gotoxy(x2,i);cout<<(char)186;
	}
	gotoxy(x1,y1);cout<<(char)201;
	gotoxy(x2,y1);cout<<(char)187;
	gotoxy(x1,y2);cout<<(char)200;
	gotoxy(x2,y2);cout<<(char)188;
		
}

void VentanaTitulo(string tit)
{
	
	DefinirVentana(1,1,103,5,4,14);
	ColocarBorde(1,1,103,5);
	gotoxy(43,3);cout<<tit;
	
	DefinirVentana(1,6,103,32,1,14);
	ColocarBorde(1,1,103,26);
	
}

void Salir(string tit)
{
	system("cls");
	
	VentanaTitulo(tit);
	DefinirVentana(1,6,103,32,1,14);
	ColocarBorde(1,1,102,27);
	gotoxy(48,1);cout<<"SALIR";
	
	DefinirVentana(25,10,75,25,8,1);
	ColocarBorde(1,1,51,16);
	gotoxy(22,2);cout<<"Hecho por ";
	gotoxy(12,4);cout<<"Victor Emmanuel Giron Solarte";
	gotoxy(14,6);cout<<"Universidad de Nari\xA4o";
	gotoxy(24,8);cout<<"2018";
	getch();
	
}

void Advertir()
{
	DefinirVentana(41,15,61,21,15,12);
	ColocarBorde(1,1,21,7);
	gotoxy(3,4);cout<<"Opcion Invalida";
	getch();
}
