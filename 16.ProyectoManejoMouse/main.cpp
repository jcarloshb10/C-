#include<iostream>
#include"graphics.h"

using namespace std;

main()
{
	int x,y;
	int poly[6];
	
	poly[0]=100;
	poly[1]=100;
	poly[2]=150;
	poly[3]=70;
	poly[4]=200;
	poly[5]=200;
	
	bool ban=true;
	
	initwindow(800,600,"Proyecto Mouse",50,50);
	setcolor(COLOR(48,212,54));
	setfillstyle(SOLID_FILL,COLOR(48,212,54));
	
	fillpoly(3,&poly[0]);
	
	//bar(100,100,200,200); 
	
	while(ban) //infinite cicle
	{
		/*if(ismouseclick(WM_MOUSEMOVE))
		{
			getmouseclick(WM_MOUSEMOVE,x,y); 
			cout<<"Move:("<<x<<","<<y<<")"<<endl;
				
		}
		
		if(ismouseclick(WM_LBUTTONDOWN)) //click left button mouse event
		{
			getmouseclick(WM_LBUTTONDOWN,x,y); 
			setcolor(COLOR(x,y,250));
			setfillstyle(SOLID_FILL,COLOR(x,y,250));
			bar(x,y,20+x,20+y); 
			
			cout<<"Left:("<<x<<","<<y<<")"<<endl;
			
		}*/
		
		if(ismouseclick(WM_RBUTTONDOWN))  //click right button mouse event
		{
			getmouseclick(WM_RBUTTONDOWN,x,y);
			
			/*setcolor(COLOR(x,y,250));
			setfillstyle(SOLID_FILL,COLOR(x,y,250)); 
			
			fillellipse(x,y,10,10);
			cout<<"Right:("<<x<<","<<y<<")"<<endl;	*/
			readimagefile("gatito.jpg",x,y,200+x,300+y);
		}
		
		if(ismouseclick(WM_MBUTTONDOWN)) //click middle button mouse event
		{
			getmouseclick(WM_MBUTTONDOWN,x,y);
			
			/*setcolor(COLOR(x,y,250));
			setfillstyle(SOLID_FILL,COLOR(x,y,250));
			
			poly[0]=x;
			poly[1]=y;
			poly[2]=x+50;
			poly[3]=y-50;
			poly[4]=x+100;
			poly[5]=y+100;
					 
			fillpoly(3,&poly[0]);
			cout<<"Middle:("<<x<<","<<y<<")"<<endl;	*/
			//getmouseclick(WM_LBUTTONDBLCLK,x,y);
			
			readimagefile("21.jpg",x,y,200+x,300+y);
		}
		
		if(ismouseclick(WM_LBUTTONDBLCLK))
		{
			getmouseclick(WM_LBUTTONDBLCLK,x,y);
			
			readimagefile("601f1615dc0e71635987041053a50581.jpg",x,y,200+x,300+y);
		}
	}
	
	getch();
	closegraph();
}
