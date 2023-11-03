#include "graphics.h"

void readText(int x, int y,int, char text[100]);

main()
{
	
	//width,height,tittle,x,y
	initwindow(1000,600,"Proyecto Entrada Salida Texto",10,10);//Iniciar Ventana	
	
	//Background color RGB
	setbkcolor(COLOR(185,241,245));
	//clear window
	cleardevice();
	
	//color RGB
	setcolor(BLACK);
	//set type font, orientation, size text
	settextstyle(COMPLEX_FONT,0,5);
	//out text in x,y position
	outtextxy(100,10,"Universidad de Nariño");
	
	char text[100];
	readText(50, 50 , 20 , text);
	
	
	
	setviewport(0,0,800,600,0);
	outtextxy(50,100,text);
	
	//read character
	
	text[0]=getch();
	text[1]='\0';
	
	
	outtextxy(50,50,text);
	
	
	
	getch();
	//Cerrar modo grafico
	closegraph();
}

//x,y position
//text string
void readText(int x, int y,int max,char text[100])
{
	unsigned char car;
	char let[2]="";
	int i;
		
	//crear area
	setviewport(x,y,x+(max*textwidth("A"))+20,y+25,1);
	setbkcolor(WHITE);
	setcolor(BLACK);
	clearviewport();
	
	rectangle(0,0,(max*textwidth("A")+20),25);
	
	settextstyle(SANS_SERIF_FONT,0,1);
	
	x=5;
	y=5;
	car=0;
	i=0;
	
	while(car!=13)
	{
		car=getch();
		
		if(car==8) //backspace
		{
			if(i>0)
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
			outtextxy(x, y, let);
			
			i++;
			x+=textwidth(let); //width caracter in pixels
		}
		
	}
	text[i]='\0';
}
