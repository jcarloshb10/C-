#include <iostream>
#include <iomanip>
#include "conio.h"
#include "funciones.h"
#include <fstream>
#include <stdlib.h>
#include "d:/conio/include/conio.h"
using namespace std;

struct empleado
{
	int ide;
	char nom[100];
	float sue;
	empleado *psig;
};

empleado *pini=NULL;
empleado *pfin=NULL;

void menu();
void registrar_empleado();
void listar_empleados();
void consultar();
void insertar(empleado *paux);

int main()
{
	system("mode con:cols=102lines=32");
	system("cls");
	colocarventana (1,1,102,5,10,0);
	marco(1,1,102,5);
	gotoxy (41,3); cout <<"PROYECTO ARCHIVOS TEXTO";
	menu(); 
}

void menu()
{
	char op;
	colocarventana (1,6,102,32,11,0);
	marco(1,1,102,26);	
	gotoxy(49,3); cout<<"MENU";
	colocarventana (20,11,82,20,15,0);
	marco(1,1,62,10);
	gotoxy (2,2); cout<<"1)Registrar EMPLEADOS.";
	gotoxy (2,3); cout<<"2)Listar EMPLEADOS."; 
	gotoxy (2,4); cout<<"3)Salir"; 
	gotoxy (2,6); cout<<"digite el numero de la opcion: ";
	cin>>op;
	switch (op)
	{
		case '1': 
		registrar_empleado(); 
		break; 
		case '2':
		listar_empleados();
		break;
		case '3':
		salir(); 
		break;
		default:
		system ("cls");
		cout<<"Opcion no valida"<<endl;
		system("pause");
		menu();
		break;
	} 		 		
}


void registrar_empleado()
{
	empleado *paux;
	paux=new empleado;
	
	colocarventana (1,6,102,32,11,0);
	marco(1,1,102,26);	
	gotoxy(49,3); cout<<"REGISTRAR EMPLEADOS";
	colocarventana (20,11,82,20,15,0);
	marco(1,1,62,10);
	gotoxy (2,2); cout<<"Ingrese la identificacion del empleado:";
	gotoxy (2,3); cin>> paux->ide; 
	gotoxy (2,4); cout<<"Nombre del empleado:";
	cin.ignore();
	gotoxy (2,5); cin.getline(paux->nom,99,'\n');
	gotoxy (2,6); cout<<"Digite el sueldo del empleado:"; 
	gotoxy (2,7); cin>>paux->sue;
	paux->psig=NULL;
	insertar(paux);
	if(pini==NULL)
	{
		pini=paux;
	}
	else 
	{
		pfin->psig=paux;
	}
	pfin=paux;
	getch();
	menu();
}

void listar_empleados()
{
	empleado *paux;
	paux=pini;
	colocarventana (1,6,102,32,11,0);
	marco(1,1,102,26);	
	gotoxy(49,3); cout<<"LISTAR EMPLEADOS";
	colocarventana (20,11,82,20,15,0);
	marco(1,1,62,10);
	int i=2;
	while (paux!=NULL)
	{
		gotoxy (2,i);cout<<paux->ide;
		gotoxy (2,i+1);cout<<paux->nom;
		gotoxy (2,i+2);cout<<paux->sue<<endl;
		gotoxy (2,i+3);paux=paux->psig;
		i++;	
	}
	getch();
	menu();	
}

void insertar(empleado *paux)
{
	fstream arc;
	arc.open("empleados.txt",ios::app);
	if (arc.fail()) 
	{
		gotoxy(2,2);cout<<"ERROR AL ABRIR EL ARCHIVO";
	}
	else 
	{
		arc<<paux->ide<<'|';
		arc<<paux->nom<<'|';
		arc<<paux->sue<<'|';
		arc<<'\n';
	}
	arc.close();
}



void consultar()
{
	char cad[100]; 
	fstream arc;
	empleado *paux; pini=NULL;
	arc.open("empleados.txt",ios::in);
	if (arc.fail())
	{
		cout<<"ERROR";
	}
	else
	{
		while (!arc.eof())
		{
			paux=new empleado; 
			arc.getline(cad,99,'|');
			paux->ide=atoi(cad); // conversion
			arc.getline(paux->nom,99,'|'); 
			arc.getline(cad,99,'|');
			paux->sue=atof(cad);//conversion
			if (pini==NULL)
			{
				pini=paux;
			}
			else
			{
				pfin->psig=paux;
			}
			pfin=paux;
		}
	}
	arc.close();
}

void seleccionar()
{
char cad[100];
empleado *paux;
fstream arc;
char aux[200];
pini=NULL;
arc.open("empleado.txt",ios::in);
if(arc.fail())
{
	cout<<"ERROR"<<endl;
}
else
{
	while(!arc.eof())
	{
		paux=new empleado;
		arc.getline(cad,199,'|');paux->ide=atoi(cad);
		arc.getline(paux->nom,199,'|');
		arc.getline(cad,199,'|');paux->sue=atof(cad);
		
		if(arc.good())
		{
			if(pini==NULL)
			{
				pini=paux;
			}
			else
			{
				pfin->psig=paux;
			}
			pfin=paux;
		}
	}	
}
}







