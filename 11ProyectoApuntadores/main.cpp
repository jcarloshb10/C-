#include <iostream>
#include <stdlib.h>
#include"funciones.h"
#include"conio.h"
#include<iomanip>

using namespace std;

void menu();


void declararPunteros();
void asignarPunteros();
void compararPunteros();
void vectoresPunteros();
void matricesPunteros();
void subprogramasPunteros();
void estructurasPunteros();
void VectoresApuntadores();

//algo que iso el profe 
void algo()
{
	int mat[50][50];
	int m,n,i,x,y;
	inr *vpini[50],*vpfin[50],*pi;
	cout<<"Ingrese filas : ";cin>>m;
	cout<<"Ingrese columnas : ";cin>>n;
	for(i=0;i<m;i++)
	{
		vpini=&mat[i][0];
		vpfin=&mat[i][n-1];
	}
	
	for(i=0;i<m;i++)
	{
		for(pi=vpini[i];pi<=vpfin[i];pi++)
		{
			gotoxy(x,y);cin>>*pi;
			x+=5;
		}
		y++;
	}
	
	clrscr();
	
	y=5;
	for(i=0,i<m;i++)
	{
		x=5;
		for(pi=vpini[i];pi<vpfin[i];pi++)
		{
			gotoxy(x,y);cout<<*pi<<"("<<pi<<")";
			x+=20;
		}
		y++;
	}
	
}
int main() 
{
	
	system ("cls");
	system ("color 0F");
	system("mode con:cols=103 lines=32");
	menu();
	return 0;
	
}

void menu()
{
	
	char opc;
	
	
	VentanaTitulo("Menu Principal");
	
	DefinirVentana(20,10,80,25,9,11);
	ColocarBorde(1,1,61,16);
	
	gotoxy(3,3);cout<<"1.Declarar";
	
	gotoxy(3,5);cout<<"2.Asignar";
	
	gotoxy(3,7);cout<<"3.comparar";
	
	gotoxy(3,9);cout<<"4.vectores";
	
	gotoxy(21,3);cout<<"5.matrices";
	
	gotoxy(21,5);cout<<"6.subprogramas";
	
	gotoxy(21,7);cout<<"7.estructuras";
	
	gotoxy(21,9);cout<<"8.Vectores apuntadores";
	
	gotoxy(21,11);cout<<"0.salir:";
	
	gotoxy(24,15);cout<<"opcion:";
	
	cin>>opc;
	
	
	
	switch(opc)
	{
		case '1' : 
			declararPunteros();
			break;
		case '2' : 
			asignarPunteros();
			break;
		case '3' : 
			compararPunteros(); 
			break;
		case '4' : 
			vectoresPunteros();
			break;
		case '5' : 
			matricesPunteros(); 
			break;
		case '6' : 
			subprogramasPunteros();
			break;
		case '7' : 
			estructurasPunteros(); 
			break;
		case '8' :
			VectoresApuntadores();
			break;
		case '0' : 
			Salir("SALIR");
			break;
		default : 
			Advertir();
			menu();
			break;
	}	

}


void declararPunteros()
{
	
	system("cls");
	VentanaTitulo("Declarar apuntadores");
	
	DefinirVentana(20,10,80,25,9,11);
	ColocarBorde(1,1,61,16);


	int num;
	int *pnum1,*pnum2;
	pnum1=&num;//obtener direccion
	pnum2=pnum1; //asignando direcciones 
				//apintadores
	gotoxy(10,5);
	cout<<"Ingrese un numero : ";
	cin>>*pnum1;
	
	gotoxy(10,7);
	cout<<"la direccion es : "<<pnum2<<endl;
	gotoxy(10,9);
	cout<<"el contenido es : "<<*pnum2<<endl;
	getch();
	menu();
}


void asignarPunteros(){
	
}

void VectoresApuntadores()
{

	
	system("cls");
	VentanaTitulo("VectoresApuntadores");
	
	DefinirVentana(20,10,80,25,9,11);
	ColocarBorde(1,1,61,16);
	
	int vec[50],n,y=2;
	int *pini,*pfin,*pi;
	
	gotoxy(5,2);cout<<"Digite cuantas veces : ";
	cin>>n;
	pini=&vec[0];
	pfin=&vec[n-1];
	pi=pini;
	while(pi<=pfin)
	{
		gotoxy(5,3+y);cout<<"Digite numeros creo : ";
		cin>>*pi;
		pi++;//puntero que va cambiando de direccion
		y++;
	}
	
	clrscr();
	
	ColocarBorde(1,1,61,16);
	

	y=1;
	pi=pini;
	
	gotoxy(5,2);cout<<"Izquierda a derecha ";
	
	while(pi<=pfin)
	{
		gotoxy(5,3+y);cout<<setw(20)<<pi;
		gotoxy(26,3+y);cout<<setw(20)<<*pi;
		pi++;
		y++;
	}
	
	pi=pfin;
	
	gotoxy(5,y+4);cout<<"Derecha a iquierda ";
	
	while(pi>=pini)
	{
		gotoxy(5,6+y);cout<<setw(20)<<pi;
		gotoxy(26,6+y);cout<<setw(20)<<*pi;
		pi--;
		y++;
	}
	
	getch();
	menu();
	
}

void compararPunteros()
{
	system("cls");
	VentanaTitulo("Comparar punteros");
	
	DefinirVentana(20,10,80,25,9,11);
	ColocarBorde(1,1,61,16);
	
	int vec[50],n;
	int *pvec;
	pvec=&vec[0];
	gotoxy(5,2);cout<<"Ingrese un numero de comparaciones : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		gotoxy(5,4+i);cout<<"Digite un numero : ";cin>>*pvec;
		pvec++;
	}
	
	clrscr();
	ColocarBorde(1,1,61,16);
	pvec=&vec[0];

	for(int i=0,y=6;i<n;i++,y++)
	{
		gotoxy(5,y);
		cout<<setw(20)<<pvec;
		gotoxy(26,y);
		cout<<setw(20)<<*pvec<<endl;
		pvec++;
	}
	getch();
	menu();
}


void vectoresPunteros()
{
	
}


void matricesPunteros()
{
	
}


void subprogramasPunteros()
{
	
}


void estructurasPunteros()
{
	
}

void advertir()
{
	
}
