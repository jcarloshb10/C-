
using namespace std;

void colocar_borde(int x1, int y1, int x2, int y2);
void colocar_ventanas(int x1,int y1, int x2,int y2,int col_fondo, int col_tex);

void creditos() 
{
	colocar_ventanas(1,6,102,60,1,15);
	colocar_borde(1,1,102,54);gotoxy(40,3);cout<<"PROYECTO REALIZADO POR: ";

	colocar_ventanas(21,11,82,27,15,0);
	colocar_borde(1,1,62,17);
	gotoxy(7,3);cout<<"JEAN CARLOS HERNANDEZ BENAVIDES C"<<(char)224<<"DIGO: 217034199";
	gotoxy(7,4);cout<<"DANIEL ESTIVEN GUANCHA C"<<(char)224<<"DIGO: 217034185";
	gotoxy(10,5);cout<<"INGENIER"<<(char)214<<"A DE SISTEMAS - 3er SEMESTRE Grupo 1";
	gotoxy(21,6);cout<<"UNIVERSIDAD DE NARI"<<(char)165<<"O";
	gotoxy(29,7);cout<<"2018";
    
	getch();
}

void terminar_programa() 
{
	colocar_ventanas(1,6,102,60,1,15);
	colocar_borde(1,1,102,54);
	gotoxy(49,3);cout<<"SALIR";
	
	colocar_ventanas(21,11,82,27,15,0);
	colocar_borde(1,1,62,17);
	gotoxy(13,3);
	cout<<"GRACIAS POR UTILIZAR EL PROGRAMA";
	gotoxy(2,8);exit(0);
}

void colocar_ventanas(int x1,int y1, int x2,int y2,int col_fondo, int col_tex) 
{
	window(x1,y1,x2,y2);
	textbackground(col_fondo);
	textcolor(col_tex);
	clrscr();
}

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
