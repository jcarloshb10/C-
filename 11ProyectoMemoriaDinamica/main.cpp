#include<iostream>
#include "d:/conio/include/conio.h"

using namespace std;

void menu();
void registrar_numero();
void listar_numero();
void creditos();
void terminar_programa();
void colocar_borde(int x1, int y1, int x2, int y2);
void colocar_ventanas(int x1,int y1, int x2,int y2,int col_fondo, int col_tex);

struct numero
{
		int num;
		numero *psig;
};

numero *pini;
numero *pfin;

int main()
{
	system("mode con:cols=102lines=32");
	system("cls");
	colocar_ventanas(1,1,102,5,4,14);
	colocar_borde(1,1,102,5);
	gotoxy(41,3);cout<<"PROYECTO MEMORIA DINAMICA";
	
	menu();
	getch();	
}

void menu() 
{
	char opcion[5];
	do
	{
		colocar_ventanas(1,6,102,32,1,15);
		colocar_borde(1,1,102,26);
		gotoxy(49,3);cout<<"MEN"<<(char)233;	
		
		colocar_ventanas(21,11,82,27,15,0);
		colocar_borde(1,1,62,17);
		gotoxy(2,2);cout<<" A) REGISTRAR NUMEROS";
		gotoxy(2,3);cout<<" B) LISTAR NUMEROS";
		gotoxy(2,4);cout<<" C) CREDITOS";
		gotoxy(2,5);cout<<" X) SALIR";
		gotoxy(2,7);cout<<" DIGITE OPCION: ";	
		cin>>opcion;
		opcion[0]=tolower(opcion[0]);
		cin.ignore();
		if(opcion[1]=='\0')
		{
			switch(opcion[0])
	    	{
	    		case 'a':
	        		registrar_numero(); 
	        	break;
	    		case 'b':
	        		listar_numero(); 
	        	break;
	    		case 'c':
	        		creditos();
	        	break;
	        	case 'x':
					terminar_programa();
				break;
				default:
					gotoxy(18,8);cout<<" OPCION NO VALIDA, VUELVA A DIGITAR";
				
					getch();
	    		break;
	    }
		}
		else
		{
			gotoxy(18,8);cout<<" OPCION NO VALIDA, VUELVA A DIGITAR";
				
			getch();
		}

	}while(opcion[0]!='x' );
}

void registrar_numero()
{
	
	numero *paux;
	paux=new numero;
	
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"REGISTRAR NUMERO";
	
	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
	if(paux==NULL)
	{
	gotoxy(5,5);cout<<"MEMORIA INSUFICIENTE.";
	}
	else
	{
		gotoxy(5,5);cout<<"INGRESE UN NUMERO: ";
		cin>>paux->num;
		paux->psig=NULL;
		if(pini==NULL)
		{
			pini=paux;
			pfin=paux;
		}
		else
		{
			pfin->psig=paux;
			pfin=paux;
		}
	}
	
}

void listar_numero()
{
	numero *paux;
	int y;
	paux=pini;
	y=5;
	
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"LISTAR NUMERO";
	
	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
	while(paux!=NULL)
	{
		gotoxy(5,y);
		cout<<paux->num;
		y++;
		paux=paux->psig;
	//	paux++;
		
	}
	getch();
}

void creditos() 
{
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);gotoxy(40,3);
	cout<<"PROYECTO REALIZADO POR: ";

	colocar_ventanas(21,11,82,27,15,0);
	colocar_borde(1,1,62,17);
	gotoxy(7,4);cout<<"JEAN CARLOS HERNANDEZ BENAVIDES CODIGO: 217034199";
	gotoxy(16,5);cout<<"INGENIER"<<(char)214<<"A DE SISTEMAS Grupo 1";
	gotoxy(21,6);cout<<"UNIVERSIDAD DE NARI"<<(char)165<<"O";
	gotoxy(29,7);cout<<"2018";
    
	getch();
}

void terminar_programa() 
{
	colocar_ventanas(1,6,102,32,1,15);
	colocar_borde(1,1,102,26);
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


