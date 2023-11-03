#include "graphics.h"
#include "funciones.h"
#include "registro.h"
#include <iostream>
#include <stdlib.h>
using namespace std;



void menu();
void registrar();
void ingresar();
void transacciones();
void retiros();
void depositos();
void consultas();
void creditos();
void advertir(char mensaje[]);
int main()
{
	ini=NULL;
	fin=NULL;
	initwindow(600,600,"CAJERO");	
	setbkcolor(fondo); //color de fondo
	setcolor(letra); //cololr de texto	
	cleardevice();	//aplicar fondo	
	
	menu();	
	closegraph();
	return 0;
}

void menu()
{
	cleardevice(); //borrar pantalla como cls 	
	settextstyle(1,0,3); //fuente y tamaño
	centerouttexty(50,"CAJERO");
	
	button crearcuenta, transacion,credito, salir;
	crearcuenta.definir(100,100,500,150,"Nueva Cuenta");
	transacion.definir(100,170,500,220,"Transacion");
	credito.definir(100,240,500,290,"Creditos");
	salir.definir(100,310,500,360,"Salir");
	int opcion;
	while(true)
	{
		int x,y;
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);			
			if(crearcuenta.setclick(x,y))
			{
				opcion=1;
				break;
			}
			else if(transacion.setclick(x,y))
			{
				opcion=2;
				break;
			}
			else if(credito.setclick(x,y))
			{
				opcion=3;
				break;
			}			
			else if(salir.setclick(x,y))
			{
				opcion=4;
				break;
			}
		}
	}
	switch(opcion)
	{
		case 1:
			registrar();	
		break;		
		case 2:
			ingresar();			
		break;	
		case 3:
			creditos();
		break;
		case 4:
		
		break;
	}
}


void registrar()
{
	cleardevice(); //borrar pantalla como cls 	
	settextstyle(1,0,3); //fuente y tamaño
	centerouttexty(50,"NUEVA CUENTA");

	leerarchivo();
	limpiararchivo();
	cuenta *auxcuenta=new cuenta;
	char auxtext[100];
	
	centerouttexty(100,"Cedula");
	readText(100,130,500,180,auxtext);
	auxcuenta->cedula=atol(auxtext);
	
	centerouttexty(200,"Nombre");
	readText(100,230,500,280,auxtext);
	strcpy(auxcuenta->nombre,auxtext);
	
	centerouttexty(300,"Saldo inicial");
	readText(100,330,500,380,auxtext);
	auxcuenta->saldo=atol(auxtext);
	
	enlazarcuenta(auxcuenta, ini, fin);
	cargaralarchivo();
	menu();	
}


void ingresar()
{
	cleardevice(); //borrar pantalla como cls 	
	settextstyle(1,0,3); //fuente y tamaño
	centerouttexty(50,"INGRESAR");

	leerarchivo();
	
	char auxtext[100];
	unsigned long cedula;
	
	centerouttexty(100,"Cedula del usuario");
	readText(100,130,500,180,auxtext);
	cedula=atol(auxtext);	
	if(buscar(cedula)!=NULL)
	{
		transacciones();
	}
	else
	{
		advertir("Cedula no encontrada");
	}
}

void transacciones()
{
	cleardevice(); //borrar pantalla como cls 	
	settextstyle(1,0,3); //fuente y tamaño
	centerouttexty(50,"TRANSACCIONES");
	
	button retirar, depositar, consultar, inicio, salir;
	retirar.definir(100,100,500,150,"Retirar");
	depositar.definir(100,170,500,220,"Depositar");
	consultar.definir(100,240,500,290,"Consultar");
	inicio.definir(100,430,500,480,"Inicio");
	salir.definir(100,500,500,550,"Salir");
	
	int opcion;
	while(true)
	{
		int x,y;
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);			
			if(retirar.setclick(x,y))
			{
				opcion=1;
				break;
			}
			else if(depositar.setclick(x,y))
			{
				opcion=2;
				break;
			}
			else if(consultar.setclick(x,y))
			{
				opcion=3;
				break;
			}
			else if(inicio.setclick(x,y))
			{
				opcion=4;
				break;
			}
			else if(salir.setclick(x,y))
			{
				opcion=5;
				break;
			}
		}
	}
	switch(opcion)
	{
		case 1:
			retiros();
		break;		
		case 2:
			depositos();	
		break;
		case 3:
			consultas();		
		break;		
		case 4:
			menu();		
		break;	
		case 5:
			
		break;
	}
}

void retiros()
{
	cleardevice(); //borrar pantalla como cls 	
	settextstyle(1,0,3); //fuente y tamaño
	centerouttexty(50,"Retirar");
		
	char auxtext[100];
	centerouttexty(100,"Usuario");
	centerouttexty(150,usuario->nombre);
	ltoa(usuario->saldo,auxtext,10);	
	centerouttexty(200,"Su saldo es");
	centerouttexty(250,auxtext);
	
	unsigned long cantidad;	
	centerouttexty(300,"Cantidad a retirar");
	readText(100,330,500,380,auxtext);
	cantidad=atol(auxtext);	
	if(cantidad<=usuario->saldo)
	{
		usuario->saldo-=cantidad;	
		limpiararchivo();
		cargaralarchivo();	
		
		usuario=NULL;//borra el usuario buscado
		centerouttexty(400,"Retiro exitoso");
		button volver;
		volver.definir(100,500,500,550,"Volver");
		int opcion;
		while(true)
		{
			int x,y;
			if(ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN,x,y);			
				if(volver.setclick(x,y))
				{
					break;
				}
			}
		}
		menu();	
	}
	else
	{
		advertir("Saldo insuficiente");
	}	
}

void depositos()
{
	cleardevice(); //borrar pantalla como cls 	
	settextstyle(1,0,3); //fuente y tamaño
	centerouttexty(50,"Depositar");
		
	char auxtext[100];
	centerouttexty(100,"Usuario");
	centerouttexty(150,usuario->nombre);
	ltoa(usuario->saldo,auxtext,10);	
	centerouttexty(200,"Su saldo es");
	centerouttexty(250,auxtext);
	
	unsigned long cantidad;	
	centerouttexty(300,"Cantidad a depositar");
	readText(100,330,500,380,auxtext);
	cantidad=atol(auxtext);	
	
	usuario->saldo+=cantidad;
	usuario=NULL;//borra el usuario buscado
	
	limpiararchivo();
	cargaralarchivo();
	
	centerouttexty(400,"Deposito exitoso");
	button volver;
	volver.definir(100,500,500,550,"Volver");
	int opcion;
	while(true)
	{
		int x,y;
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);			
			if(volver.setclick(x,y))
			{
				break;
			}
		}
	}
	menu();		
}

void consultas()
{
	cleardevice(); //borrar pantalla como cls 	
	settextstyle(1,0,3); //fuente y tamaño
	centerouttexty(50,"CONSULTAR");
		
	char auxtext[100];
	centerouttexty(200,"Usuario");
	centerouttexty(250,usuario->nombre);
	ltoa(usuario->saldo,auxtext,10);	
	centerouttexty(300,"Su saldo es");
	centerouttexty(350,auxtext);
	
	usuario=NULL;//borra el usuario buscado
	button volver;
	volver.definir(100,500,500,550,"Volver");
	int opcion;
	while(true)
	{
		int x,y;
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);			
			if(volver.setclick(x,y))
			{
				break;
			}
		}
	}
	menu();		
}



void advertir(char mensaje[])
{
	cleardevice(); //borrar pantalla como cls 	
	settextstyle(1,0,3); //fuente y tamaño
	centerouttexty(50,"ADVERTENCIA");	
	centerouttexty(300,mensaje);
	button volver;
	volver.definir(100,500,500,550,"Volver");
	int opcion;
	while(true)
	{
		int x,y;
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);			
			if(volver.setclick(x,y))
			{
				break;
			}
		}
	}
	menu();		
}

void creditos()
{
	cleardevice(); //borrar pantalla como cls 	
	settextstyle(1,0,3); //fuente y tamaño
	centerouttexty(50,"CREDITOS");
		
	char auxtext[100];
	centerouttexty(150,"Hecho por:");
	centerouttexty(200,"Ricardo Mauricio Muñoz");
	centerouttexty(250,"Juan David Meneses");
	centerouttexty(300,"Ingeneria de Sistemas");
	centerouttexty(350,"Grupo 1");
	centerouttexty(400,"Universidad de Nariño");
	
	button volver;
	volver.definir(100,500,500,550,"Volver");
	int opcion;
	while(true)
	{
		int x,y;
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);			
			if(volver.setclick(x,y))
			{
				break;
			}
		}
	}
	menu();		
}
