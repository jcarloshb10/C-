#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cctype>

#include <conio.h>
#include <iomanip>
//#include "d:/conio/include/conio.h"
using namespace std;

void menu();
void colocar_borde(int x1, int y1, int x2, int y2);
void colocar_ventanas(int x1,int y1, int x2,int y2,int col_fondo, int col_tex);
void regis_articulo();
void list_articulo();
void regis_movim();
int verif_existe(int cod,bool &existe);
void advertencia(string texto);
void list_movim();
void creditos();

struct fecha
{
	int dd;
	int mm;
	int aaaa;
};
 struct movimiento
{
	float val;
	char des[200];
	char tip;
	int cod,can;
	fecha fec;	
};
struct articulo
{
	int cod,exi,cont;
	char num[100],des[200];
	float val;
	movimiento vmov[50];
};

articulo vart[50];
int cont=0;

int main()
{
	colocar_ventanas(1,1,102,5,4,14);
	colocar_borde(1,1,102,5);
	gotoxy(41,3);
	cout<<"PROYECTO INVENTARIO";
	
	menu();
	getch();	
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

void menu()
{	

	
	int opcion;
	
	do
	{
		colocar_ventanas(1,6,102,32,1,15);
		colocar_borde(1,1,102,26);
		gotoxy(49,3);
		cout<<"MENU";	
		
		colocar_ventanas(21,11,82,27,15,0);
		colocar_borde(1,1,62,17);
		gotoxy(2,2);cout<<" 1) REGISTRAR ARTICULOS";
		gotoxy(2,3);cout<<" 2) LISTAR ARTICULOS";
		gotoxy(2,4);cout<<" 3) REGISTRAR MOVIMIENTOS";
		gotoxy(2,5);cout<<" 4) LISTAR MOVIMIENTOS";
		gotoxy(2,6);cout<<" 5) CREDITOS";
		gotoxy(2,7);cout<<" 6) SALIR";
		gotoxy(2,9);cout<<" DIGITE OPCION: ";	
		
		cin>>opcion;
		switch(opcion)
	    {
	    case 1:
	        regis_articulo(); //registrar articulo
	        break;
	    case 2:
	        list_articulo(); //listar articulos
	        break;
	    case 3:
	        regis_movim(); //registrar movimientos
	        break;
	    case 4:
	        list_movim();  //listar movimientos
	        break;
	    case 5:
	        creditos();
	        break;
	    case 6:
	    colocar_ventanas(21,11,82,27,15,0);
		colocar_borde(1,1,62,17);
		gotoxy(15,3);
		cout<<" GRACIAS POR UTILIZAR NUESTRO PROGRAMA";
		break;
	
	    default:
			gotoxy(16,9);
			cout<<" OPCION NO VALIDA, VUELVA A DIGITAR";
			getch();
	    break;
	    }
	}while(opcion !=6 );
	
}

void regis_articulo()//funcion de 1
{

	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"REGISTRAR ARTICULO";
	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
	gotoxy(70,3);cout<<"ARTICULO "<<cont+1;
	
	gotoxy(4,5);cout<<"CODIGO:";
	gotoxy(4,6);cout<<"NOMBRE:";
	gotoxy(4,7);cout<<"DESCRIPCION";
	gotoxy(4,8);cout<<"VALOR:";
	gotoxy(4,9);cout<<"EXISTENCIAS:";
	
	gotoxy(24,5);cin>>vart[cont].cod;
	cin.ignore();
	gotoxy(24,6);cin.getline(vart[cont].num,99,'\n');
	gotoxy(24,7);cin.getline(vart[cont].des,199,'\n');
	gotoxy(24,8);cin>>vart[cont].val;
	gotoxy(24,9);cin>>vart[cont].exi;
	cont++;
}

void list_articulo()//funcion de 2
{
	int i;
	colocar_ventanas(1,6,102,32,10,1);
	colocar_borde(1,1,102,26);
	gotoxy(40,3);cout<<"LISTAR ARTICULOS";

	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
	gotoxy(10,3);cout<<"CODIGO";
	gotoxy(20,3);cout<<"NOMBRE";
	gotoxy(43,3);cout<<"DESCRIPCION";
	gotoxy(70,3);cout<<"VALOR";
	gotoxy(80,3);cout<<"EXISTENCIAS";
	
	for(i=0;i<cont;i++)
	{
		gotoxy(10,i+5);cout<<setw(3)<<vart[i].cod;
		gotoxy(20,i+5);cout<<vart[i].num;
		gotoxy(43,i+5);cout<<vart[i].des;
		gotoxy(70,i+5);cout<<setw(2)<<vart[i].val;
		gotoxy(80,i+5);cout<<setw(3)<<vart[i].exi;
	}
	getch();
}

void regis_movim()//funcion de 3
{
	int pos,cod;
	bool existe=false;
	colocar_ventanas(1,6,102,32,12,0);
	colocar_borde(1,1,102,26);
	gotoxy(40,3);cout<<"REGISTRAR MOVIMIENTO";
	
	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
	gotoxy(3,3);cout<<"DATOS DEL ARTICULO";
	gotoxy(3,4);cout<<"CODIGO: ";	
	gotoxy(3,5);cout<<"NOMBRE: ";
	gotoxy(3,6);cout<<"EXISTENCIAS: ";
	gotoxy(50,6);cout<<"VALOR C/U: ";
	gotoxy(20,4);cin>>cod;
	pos=verif_existe(cod,existe);

	if(!existe)
	{
		advertencia("NO EXISTE ARTICULO CON ESE CODIGO");
	}
	else
	{
	gotoxy(20,5);cout<<vart[pos].num;
	gotoxy(20,6);cout<<vart[pos].exi;
	gotoxy(61,6);cout<<vart[pos].val;
	
	colocar_ventanas(7,19,95,26,7,0);
	int pmov=vart[pos].cont;
	vart[pos].vmov[pmov].cod=100+vart[pos].cont;
	gotoxy(3,2);cout<<"FECHA: ";
	gotoxy(20,2);cout<<"/";
	gotoxy(25,2);cout<<"/";
	gotoxy(35,2);cout<<"TIPO(c: COMPRA - v: VENTA): ";
	gotoxy(72,2);cout<<"CMOV: ";
	gotoxy(83,2);cout<<vart[pos].vmov[pmov].cod;
	gotoxy(3,3);cout<<"CANTIDAD: ";
	gotoxy(3,4);cout<<"VALOR COMPRA: ";
	
	
	gotoxy(17,2);cin>>vart[pos].vmov[pmov].fec.dd;
	gotoxy(22,2);cin>>vart[pos].vmov[pmov].fec.mm;
	gotoxy(27,2);cin>>vart[pos].vmov[pmov].fec.aaaa;
	gotoxy(65,2);cin>>vart[pos].vmov[pmov].tip;
	cin.ignore();
	gotoxy(13,3);cin>>vart[pos].vmov[pmov].can;
	gotoxy(19,4);cin>>vart[pos].vmov[pmov].val;
	vart[pos].cont++;
	}
	getch();
	
}


void advertencia(string advertencia)
{

	colocar_ventanas(1,6,102,32,8,0);
	colocar_borde(1,1,102,26);
	gotoxy(46,3);cout<<"ADVERTENCIA";
	
	colocar_ventanas(21,11,82,27,15,0);
	colocar_borde(1,1,62,17);
	gotoxy(17,6);cout<<advertencia;

	getch();
}

void list_movim()//funcion de 4
{
	int i,cod,pos;
	bool existe=false;
	colocar_ventanas(1,6,102,32,8,0);
	colocar_borde(1,1,102,26);
	gotoxy(40,3);cout<<"LISTAR MOVIMIENTOS";

	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
    gotoxy(30,4);
    cout<<"CODIGO DEL ARTICULO: ";
    cin>>cod;
    pos=verif_existe(cod,existe);
    int pmov=vart[pos].cont;
    if(!existe)
	{
		gotoxy(3,6);
     	cout<<"NO EXISTE MOVIMIENTO ASOCIADO AL CODIGO";
     	getch();
		
	}
	else
	{
	 	gotoxy(3,5);
	 	cout<<"NOMBRE: ";cout<<vart[pos].num;
	 	gotoxy(3,6);
		cout<<"DESCRIPCION: ";cout<<vart[pos].des;
		gotoxy(3,7);
		cout<<"EXISTENCIAS: ";cout<<vart[pos].exi;
		gotoxy(3,8);
	 	cout<<" VALOR TOTAL: ";cout<<vart[pos].val;
	 	gotoxy(3,9);cout<<"FECHA: ";
	 	for(i=0;i<vart[pos].cont;i++)
	 	{
	 		cout<<setw(2)<<vart[pos].vmov[i].fec.dd<<"/"
	 		<<setw(2)<<vart[pos].vmov[i].fec.mm<<"/"
	 		<<setw(4)<<vart[pos].vmov[i].fec.aaaa;
	 		cout<<setw(10)<<vart[pos].vmov[i].tip;
		}
		getch();
	 }
}


void creditos() //funcion de 5
{
    char opcion[20];

	colocar_ventanas(1,6,102,32,1,15);
	colocar_borde(1,1,102,26);
	gotoxy(40,3);
	cout<<"PROYECTO REALIZADO POR: ";

	colocar_ventanas(21,11,82,27,15,0);
	colocar_borde(1,1,62,17);
	gotoxy(7,3);
	cout<<"BRAYAN SEBASTIAN BASTIDAS ROSERO CODIGO: 217034032";
	gotoxy(7,4);
	cout<<"JEAN CARLOS HERNANDEZ BENAVIDES CODIGO: 217034199";
	gotoxy(21,5);
	cout<<"UNIVERSIDAD DE NARINO";
	gotoxy(29,6);
	cout<<"2018";
    getch();
    
}



void colocar_ventanas(int x1,int y1, int x2,int y2,int col_fondo, int col_tex)
{
	window(x1,y1,x2,y2);
	textbackground(col_fondo);
	textcolor(col_tex);
	clrscr();
}


int verif_existe(int cod,bool &existe)
{
	int j;
	for(j=0;j<cont;j++)
	{
		if(vart[j].cod==cod)
		{
			existe=true;
			break;
		}
	}
	return(j);
}
