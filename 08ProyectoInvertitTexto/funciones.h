#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;
void definir_ventana(int x1,int y1, int x2, int y2, int colf, int colt);
void colocar_borde(int x1, int y1, int x2, int y2);
//--------------------------------------------------------------------------------------------------------------
void validar_entero_positivo(char num[20], int tam, bool obl)
{
	int i = 0;
	char let = 0;
	char tex[50];
	
	while(let!=13)
	{
		let = getch();
		if(i < tam)
		{
			if(let >= 48 && let <= 57)
			{
				cout << let;
				tex[i] = let;
				i++;
			}
		}
		if(let == 8)
		{
			if(i > 0)
			{
				cout << let << " " << let;
				i--;
			}
		}
		if(let == 13 && obl == true && i ==0)
		{
			let = 0;
		}
	}
	tex[i] = '\0';
	strcpy(num,tex);
}
//--------------------------------------------------------------------------------------------------------------
void validar_texto(char text[200], int tam, bool obl)
{
	int i = 0;
	unsigned char let = 0;
	char tex[200];
	
	while(let!=13)
	{
		let = getch();
		if(i < tam)
		{
			
			if((let >= 65 && let <= 90) || (let >= 97 && let <= 122) || let == 164 || let == 165 || let == 32)
			{
				cout << let;
				tex[i] = let;
				i++;
			}
		}
		if(let == 8)
		{
			if(i > 0)
			{
				cout << let << " " << let;
				i--;
			}
		}
		if(let == 13 && obl == true && i ==0)
		{
			let = 0;	
		}
	}
	tex[i] = '\0';
	strcpy(text,tex);
}
//--------------------------------------------------------------------------------------------------------------
void definir_ventana(int x1,int y1, int x2, int y2, int colf, int colt)
{
	window(x1,y1,x2,y2);
	textbackground(colf);
	textcolor(colt);
	clrscr();
}
//--------------------------------------------------------------------------------------------------------------
void colocar_borde(int x1, int y1, int x2, int y2)
{
	for(int i=x1; i<x2; i++)
	{
		gotoxy(i,y1); cout << (char)177;
		gotoxy(i,y2); cout << (char)177;
	}
	
	for(int i=y1; i<y2; i++)
	{
		gotoxy(x1,i); cout << (char)177;
		gotoxy(x2,i); cout << (char)177;
	}
	
	gotoxy(x1,y1); cout << (char)177;
	gotoxy(x2,y1); cout << (char)177;
	gotoxy(x1,y2); cout << (char)177;
	gotoxy(x2,y2); cout << (char)177;
}
//--------------------------------------------------------------------------------------------------------------
void advertir()
{
	definir_ventana(1,6,102,32,15,0);
	colocar_borde(1,1,102,27);
	gotoxy(49,3); cout << "ERROR";
		
	definir_ventana(21,10,81,28,0,15);
	colocar_borde(1,1,61,19);
	gotoxy(24,6); cout << "OPCION NO VALIDA";
	gotoxy(22,7); cout << "Vuelva a intentarlo.";
	
	getch();
}
//--------------------------------------------------------------------------------------------------------------
void salir()
{
	definir_ventana(1,6,102,32,15,0);
	colocar_borde(1,1,102,27);
	gotoxy(48.5,3); cout << "SALIR";
		
	definir_ventana(21,10,81,28,0,15);
	colocar_borde(1,1,61,19);

	gotoxy(23.5,6);  cout << "DERECHOS DE AUTOR                 ";
	gotoxy(17,8);    cout << "Vanessa Riobamba (215034413)      ";
	gotoxy(17,9);    cout << "Kevin Guerrero   (217034188)      ";
	gotoxy(19,11);   cout << "Facultad de Ingenieria            ";
	gotoxy(13.5,12); cout << "Programa de Ingenieria de Sistemas";
	gotoxy(14,13);   cout << "Asignatura Taller Programacion II";
	gotoxy(19.5,14); cout << "Universidad de Nariño             ";
	gotoxy(28,15);   cout << "2018";
	
	getch();
}	
