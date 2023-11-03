#include <iostream>
#include <iomanip>
#include "conio.h"
#include "funciones.h"
#include <fstream>
#include <stdlib.h>

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
empleado *buscar(int ide);
void insertar(empleado *paux);
void modificar_empleado();
void eliminar_empleado();

int main()
{
	system("mode con:lines=32 cols=102");
	colocarventana (1,1,102,5,4,14);
	marco(1,1,102,5);
	gotoxy (41,3); cout <<"PROYECTO ARCHIVOS TEXTO";
	menu(); 
}

void menu()
{
	char op;
	colocarventana (1,6,102,32,1,15);
	marco(1,1,102,26);	
	gotoxy(49,3); cout<<"MENU";
	colocarventana (20,11,82,20,15,0);
	marco(1,1,62,10);
	gotoxy (2,2); cout<<" A) REGISTRAR EMPLEADOS.";
	gotoxy (2,3); cout<<" B) LISTAR EMPLEADOS."; 
	gotoxy (2,4); cout<<" C) MODIFICAR EMPLEADO";
	gotoxy (2,5); cout<<" D) ELIMINAR"; 
	gotoxy (2,6); cout<<" X) SALIR";  
	gotoxy (2,7); cout<<" DIGITE OPCION: ";
	cin>>op;
	op=tolower(op);
	switch (op)
	{
		case 'a': 
		registrar_empleado(); 
		break; 
		case 'b':
		listar_empleados();
		break;
		case 'c':
		modificar_empleado();
		break;
		case 'd': 
		
		break; 
		case 'x': 
		salir(); 
		break; 
		default:
		
		gotoxy(20,9);cout<<"OPCION NO VALIDA"<<endl;
		getch();
		menu();
		break;
	} 		 		
}


void registrar_empleado()
{
	empleado *paux;
	paux=new empleado;
	
	colocarventana (1,6,102,32,1,15);
	marco(1,1,102,26);	
	gotoxy(49,3); cout<<"REGISTRAR EMPLEADOS";
	colocarventana (20,11,82,20,15,0);
	marco(1,1,62,10);
	gotoxy (2,2); cout<<"INGRESE LA IDENTIFICACION DEL EMPLEADO:";
	gotoxy (2,3); cin>> paux->ide; 
	gotoxy (2,4); cout<<"NOMBRE DEL EMPLEADO:";
	cin.ignore();
	gotoxy (2,5); cin.getline(paux->nom,99,'\n');
	gotoxy (2,6); cout<<"DIGITE EL SUELDO DEL EMPLEADO:"; 
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
	colocarventana (1,6,102,32,1,15);
	marco(1,1,102,26);	
	gotoxy(49,3); cout<<"LISTAR EMPLEADOS";
	colocarventana (20,11,82,20,15,0);
	marco(1,1,62,10);
	consultar();
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
	arc.open("empleados.dat",ios::app|ios::binary);
	if (arc.fail()) 
	{
		gotoxy(2,2);cout<<"ERROR AL ABRIR EL ARCHIVO";
	}
	else 
	{
		arc.write((char *)paux,sizeof(empleado));
	}
	arc.close();
	
	getch();
	menu();
}

void consultar()
{
	char cad[100]; 
	fstream arc;
	empleado *paux; pini=NULL;
	arc.open("empleados.txt",ios::in);
	if (arc.fail())
	{
		gotoxy(7,4);cout<<"ERROR";
	}
	else
	{
		while (!arc.eof())
		{
			paux=new empleado; 
			arc.getline(cad,99,'|');
			paux->ide=atoi(cad);
			arc.getline(paux->nom,99,'|'); 
			arc.getline(cad,99,'|');
			paux->sue=atof(cad);
			
			cout<<"get: "<<arc.tellg()<<"put. "<<arc.tellp()<<endl;
			cout<<"good: "<<arc.good()<<"bad. "<<arc.bad()<<"fail: "<<arc.fail()<<"eof"<<arc.eof()<<endl;
			getch();
			
			pfin=paux;
			if (arc.good())
			{
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
	}
	arc.close();
	
	getch();
	menu();
}


void modificar_empleado()
{
	empleado *paux; 
	double ide; 
	colocarventana (1,6,102,32,1,15);
	marco(1,1,102,26);	
	gotoxy(49,3); cout<<"MODIFICAR EMPLEADOS";
	colocarventana (20,11,82,20,15,0);
	marco(1,1,62,10);
	gotoxy(2,2);cout<<"IDENTIFICACION";
	gotoxy(2,3);cin>>ide;
	
	
	getch(); 
	menu();
	
}


long obtenerPosicion (int ide)
{
	fstream arc;
	empleado *paux;
	long pos = -1;
	
	arc.open("empleado.dat",ios::in|ios::binary);
	
	if(arc.fail())
	{
		gotoxy(10,4);cout<<"ERROR";
	}
	else
	{
		paux=new empleado; 
		while(!arc.eof())
		{
			arc.read((char *)paux,sizeof (empleado));
			if(arc.good())
			{
				if(paux->ide==ide)
				{
					pos= arc.tellg();
					pos=pos-sizeof(empleado);
					break;
				}
			}
		}
		
	}
	arc.close();
	return pos;
}

empleado *buscar(int ide)
{
	fstream arc;
	empleado *paux=NULL;
	long pos;
	
	paux=NULL;
	pos=obtenerPosicion(ide);
	if(pos== -1)
	{
		cout<<"ERROR";
	}
	else
	{
		arc.open("empleado.dat",ios::in|ios::binary);
		if(arc.fail())
		{
			cout<<"ERROR";
		}
		else
		{
			paux=new empleado;
			arc.seekg(pos, ios::beg);
			arc.read((char *)paux, sizeof(empleado));
		}
	}
	return paux;
}

void modificarEmpleados()
{
	empleado *paux;
	int ide;
	cout<<"IDENTIFICACION ";
	cin>>ide;
	
	paux = buscar(ide);
	if(paux==NULL)
	{
		cout<<"NO EXISTE";
	}
	else
	{
		cout<<"NOMBRE: "<<paux->nom;
		cout<<"SUELDO: "<<paux->sue;
	}
	getch();
	menu();
}

void eliminar_empleado()
{
	empleado *paux;
	int ide;
	char opc;
	if(paux->ide==paux->ide)
	{
		cout<<endl<<endl;
		cout<<"IDENTIFICACION: "<<paux->ide<<endl;
		cout<<"NOMBRE: "<<paux->nom;
		cout<<"SUELDO: "<<paux->sue;
		cout<<endl<<endl;
		cout<<"Confirme la eliminacion (S/N):";
		cin>>opc;
		opc=toupper(opc);
		if(opc=='S')
		{
			//eliminar(ide);
		}	
	
	}
	else
	{
		cout<<"ERROR"<<endl;
	}

	getch();
	menu();
}

