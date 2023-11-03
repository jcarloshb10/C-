#include<iostream>
#include<ctype.h>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
//#include "d:/conio/include/conio.h"
#include<math.h>
using namespace std;
const int MAXF=100;
const int MAXC=100;
main()
{
	
	
	int i,j;
	for(i=0;i<16;i++)
	{
	system("color 0F");
	system("cls");
		for(j=0;j<16;j++)
		{
			window(1+(i*6),1+(i*2),6+(i*6),2+(i*2));
			textbackground(i);
					textcolor(j);
		clrscr();
		gotoxy(1,1);
		cout<<"UDENAR";
		}	
		getch();
	}
	/*window (1,1,6,2);
	textbackground(0);
	clrscr();
	window (7,3,12,4);
	textbackground(1);           
	clrscr();
	window (13,5,18,6);
	textbackground(2);           
	clrscr();
	window (19,7,24,8);
	textbackground(3);           
	clrscr();
	window (25,9,30,10);
	textbackground(4);           
	clrscr();
	window (31,11,36,12);
	textbackground(5);           
	clrscr();
	window (37,13,42,14);
	textbackground(6);           
	clrscr();
	window (43,15,48,16);
	textbackground(7);           
	clrscr();
	window (49,17,54,18);
	textbackground(8);           
	clrscr();
	window (55,19,60,20);
	textbackground(9);           
	clrscr();
	window (61,21,66,22);
	textbackground(10);           
	clrscr();
	window (67,23,72,24);
	textbackground(11);           
	clrscr();
	window (73,25,78,26);
	textbackground(12);           
	clrscr();
	window (79,27,84,28);
	textbackground(13);           
	clrscr();
	window (85,29,90,30);
	textbackground(14);           
	clrscr();
	window (91,31,96,32);
	textbackground(15);           
	clrscr();*/
	
}
