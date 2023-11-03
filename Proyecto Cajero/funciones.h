#include "graphics.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int width=600;
centerouttexty(int y,char textstring[])
{
	outtextxy((width-textwidth(textstring))/2,y,textstring);
}

int fondo=COLOR(142,247,49);
int letra=0;

struct button
{
	int left,top;
	int right,bottom;
	char text[50];
	int backcolor;
	int forecolor;
	void create()
	{		
		setviewport(left,top,right,bottom,1);
		setbkcolor(backcolor);
		setcolor(forecolor);
		clearviewport();	
		rectangle(0,0,right-left-1,bottom-top-1);
		outtextxy((right-left-textwidth(text))/2,17,text);	
		setviewport(0,0,0,0,0);
		setbkcolor(fondo); //color de fondo
		setcolor(letra);
		clearviewport();	//aplicar fondo	
	}	
	void definir(int xleft,int xtop,int xright, int xbottom, char xtext[50])
	{
		left=xleft;
		top=xtop;
		right=xright;
		bottom=xbottom;	
		backcolor=COLOR(255,228,40);
		forecolor=0;
		strcpy(text,xtext);
		create();
	}
	bool setclick(int x,int y)
	{
		bool click=false;
		if(x>=left and y>=top and x<=right and y<=bottom)
		{
			click=true;
		}
		return(click);
	}
};



void readText(int left,int top,int right, int bottom, char text[100])
{
	unsigned char car=0;
	int i=0;
	rectangle(left-1,top-1,right,bottom);
	setviewport(left,top,right,bottom,1);	
	setbkcolor(WHITE);
	setcolor(BLACK);
	clearviewport();
	while(car!=13)
	{
		car=getch();
		if(car==8)
		{
			if(i!=0)
			{
				i--;
				text[i]='\0';
				clearviewport();
				outtextxy((right-left-textwidth(text))/2,17,text);			
			}
		}
		else
		{
			text[i]=car;
			text[i+1]='\0';	
			clearviewport();
			outtextxy((right-left-textwidth(text))/2,17,text);
			i++;			
		}
	}
	setviewport(0,0,0,0,0);
	setbkcolor(fondo); //color de fondo
	setcolor(letra);
	clearviewport();	//aplicar fondo	
}
