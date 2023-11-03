#include"graphics.h"


struct button
{
	int left,top;
	int right,bottom;
	char text[100];
	int backcolor;
	int forecolor;
	
	void setLimits(int xleft,int xtop,int xright, int xbottom)
	{
		left=xleft;
		top=xtop;
		right=xright;
		bottom=xbottom;	
	}
};

void createButton(button *);
void mouseEvents(button *);
void opcion1();
void opcion2();

main()
{
	
	initwindow(800,600,"Proyecto Boton Mouse");
	
	setbkcolor(COLOR(190,220,255));
	cleardevice();
	
	button *btn1;
	btn1=new button;
	button *btn2;
	btn2=new button;
	
	btn1->backcolor=COLOR(246,190,255);
	btn1->forecolor=BLACK;
	
	btn2->backcolor=COLOR(246,190,255);
	btn2->forecolor=BLACK;
	
	/*btn1.left=100;
	btn1.top=50;
	btn1.right=200;
	btn1.bottom=75;*/
	strcpy(btn1->text,"Opcion 1");
	btn1->setLimits(100,50,200,75);
	
	strcpy(btn2->text,"OPCION2");
	btn2->setLimits(200,50,300,75);
	
	createButton(btn1);
	createButton(btn2);
	
	while(true)
	{
		mouseEvents(btn1);
		mouseEvents(btn2);
	}
	
	getch();
	closegraph();
}

void createButton(button *btn)
{
	setviewport(btn->left,btn->top,btn->right,btn->bottom,1);
	setbkcolor(btn->backcolor);
	setcolor(btn->forecolor);
	clearviewport();
	
	rectangle(0,0,btn->right-btn->left-1,btn->bottom-btn->top-1);
	
	settextstyle(3,0,1);
	outtextxy(5,3,btn->text);
}

void mouseEvents(button *btn)
{
	int x,y;
	if(ismouseclick(WM_MOUSEMOVE))
	{
		getmouseclick(WM_MOUSEMOVE,x,y);
		if(x >= btn->left and y >= btn->top and x <= btn->right and y <= btn->bottom)
		{
			btn->forecolor=COLOR(255,255,255);
		}
		else
		{
			btn->forecolor=COLOR(0,0,0);
		}
		
		setviewport(btn->left,btn->top,btn->right,btn->bottom,1);
		setcolor(btn->forecolor);
		rectangle(0,0,btn->right-btn->left-1,btn->bottom-btn->top-1);
		settextstyle(3,0,1);
		outtextxy(5,3,btn->text);
	}
	if(ismouseclick(WM_LBUTTONDOWN))
	{
		getmouseclick(WM_MOUSEMOVE,x,y);
		if(x >= btn->left and y >= btn->top and x <= btn->right and y <= btn->bottom)
		{
			opcion1();
		}
		else
		{
			opcion2();
		}
	}
}

void opcion1()
{
	setviewport(0,0,800,600,1);
	readimagefile("601f1615dc0e71635987041053a50581.jpg",100,100,300,400);
}
void opcion2()
{
	setviewport(0,0,800,600,1);
	outtextxy(5,3,"hola");

}





