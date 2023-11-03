#include <iostream>
#include "graphics.h"

using namespace std;

struct empleado
{
	long ide;
	char nom[200];
	float sue;
};


void createTextBox(int left,int top, int right, int bottom,char text[100]);

int main()
{
	int bkcolor,frcolor;
	
	empleado *paux;
	paux=new empleado[100];
	
	bkcolor=COLOR(185,241,245);
	frcolor=COLOR(255,153,0);
	
	initwindow(600,400,"Proyecto entrada y salida de texto",10,10);
	setbkcolor(COLOR(71,226,149));
	setcolor(BLACK);	
	cleardevice();
	
	settextstyle(BOLD_FONT, 0, 2);
	
	outtextxy(10,10,"Universidad de Nariño");	
	
	char text[100];
	
	setviewport(10,50,150,70,1);	
	setbkcolor(WHITE);	
	setcolor(BLACK);	
	clearviewport();
	outtextxy(10,0,"NOMBRE");
	createTextBox(200,50,400,80,text);
	
	createTextBox(200,80,400,110,text);
	
	createTextBox(200,110,400,140,text);
	
	setviewport(50,140,400,170,1);		
	setbkcolor(WHITE);
	setcolor(BLACK);
	clearviewport();
	outtextxy(50,5,text);
	
	getch();
	closegraph();
	return 0;
}

void createTextBox(int left,int top, int right, int bottom,char text[100])
{
	unsigned char car;
	char let[2]="";
	int i;
	int x,y;
	car=0;
	i=0;

	setviewport(left,top,right,bottom,1);
		
	setbkcolor(WHITE);
	setcolor(BLACK);
	clearviewport();
	rectangle(0,0,right-left-1,bottom-top-1);
	settextstyle(SOLID_FILL, 0, 2);
	x=5;
	y=5;
	while(car!=13)
	{
		car=getch();
		if(car==8)
		{
			if(i!=0)
			{
				i--;
				let[0]=text[i];
				x-=textwidth(let);
				setcolor(WHITE);
				outtextxy(x,y,let);				
			}

		}
		else
		{
			let[0]=car;
			text[i]=car;
			setcolor(BLACK);
			outtextxy(x,y,let);
			i++;
			x+=textwidth(let);			
		}

	}
	text[i]='\0';	
}

void createlabel(int left, int top, int right, int buttom)
{
	setviewport(left,top,right,buttom,0);
	

}
