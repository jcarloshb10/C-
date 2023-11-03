#include <conio.h>
#include "funciones.h"
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
//-----------------------------------------------------------------------------------------------------
void menu();
string ingresar_texto();
void mostrar_texto(string texto); 
void registrar_palabra(string texto);
void mostrar_texto_invertido();
void advertir();
void salir();

struct palabra
{
	string palabras;
	palabra *psig;
};

palabra *pini = NULL;
palabra *pfin = NULL;
//-----------------------------------------------------------------------------------------------------
int main()
{
	system("cls");
	system("color 0F");
	
	definir_ventana(1,1,102,5,3,15);
	colocar_borde(1,1,102,5);
	gotoxy(39.5,3); cout << "PROYECTO INVERTIR TEXTO";
	
	menu();
	getch();
	ShowWindow (GetForegroundWindow(), SW_HIDE);
	return 0;	
}
//-----------------------------------------------------------------------------------------------------
void menu()
{
	int opc;
	string texto;
	
	do
	{
		char aux[20];
		
		definir_ventana(1,6,102,32,15,0);
		colocar_borde(1,1,102,27);
		gotoxy(49,3); cout << "MENU";
		
		definir_ventana(21,10,81,28,0,15);
		colocar_borde(1,1,61,19);
		
		textcolor(CYAN); gotoxy(20,5);  cout << "[1]"; textcolor(WHITE); gotoxy (25,5);  cout << "INGRESAR TEXTO.         ";
		textcolor(CYAN); gotoxy(20,7);  cout << "[2]"; textcolor(WHITE); gotoxy (25,7);  cout << "MOSTRAR TEXTO.          ";
		textcolor(CYAN); gotoxy(20,9);  cout << "[3]"; textcolor(WHITE); gotoxy (25,9);  cout << "MOSTRAR TEXTO INVERTIDO.";
		textcolor(CYAN); gotoxy(20,11); cout << "[4]"; textcolor(WHITE); gotoxy (25,11); cout << "SALIR.                  ";
		
		textcolor(WHITE); gotoxy(20,13); cout << "OPCION: "; validar_entero_positivo(aux,20,true); opc = atoi(aux);
		cin.ignore(); 
		switch(opc)
		{
			case 1: texto = ingresar_texto(); break;
			case 2: mostrar_texto(texto); break;
			case 3: mostrar_texto_invertido(); break;
			case 4: salir(); break;
			default: advertir(); break;		 
		}
				 
	}while(opc!=4);	
	getch();	
}
//-----------------------------------------------------------------------------------------------------
string ingresar_texto()
{
	string texto;
	
	definir_ventana(1,6,102,32,0,15);
	gotoxy(44,2); cout << "INGRESAR TEXTO";
	definir_ventana(1,9,102,32,15,0);
	colocar_borde(1,1,102,24);
	
	gotoxy(3,6); cout << "Digite texto a invertir: ";
	
	
	getline(cin,texto);
	registrar_palabra(texto);	
	cout<<texto;
	getch();
	return texto;
}
//-----------------------------------------------------------------------------------------------------
void mostrar_texto(string texto)
{
	definir_ventana(1,6,102,32,0,15);
	gotoxy(44.5,2); cout << "MOSTRAR TEXTO";
	
	definir_ventana(1,9,102,32,15,0);
	colocar_borde(1,1,102,24);
	gotoxy(4,7); cout << "El texto es: " << texto << endl;
	
	getch();
}
//-----------------------------------------------------------------------------------------------------
void registrar_palabra(string texto)
{
	string saux;
	
	for (int i=0; i<texto.length(); i++)
	{
		palabra *paux = new palabra;
		saux.clear();
		
		while(texto[i]!=' ' && i<texto.length())
		{
			saux.push_back(texto[i]);
			i++;
		}
		
		if(pini == NULL)
		{			
			paux->palabras = saux;
			paux->psig = NULL;    
			pini = paux;			
		}
		else
		{			
			paux->palabras = saux;
			paux->psig = pfin;
		}
		pfin = paux;
	}
}
//-----------------------------------------------------------------------------------------------------
void mostrar_texto_invertido()
{
	string auxstring;
	
	definir_ventana(1,6,102,32,0,15);
	gotoxy(46,2); cout << "INVERTIR TEXTO";
	definir_ventana(1,9,102,32,15,0);
	colocar_borde(1,1,102,24);
	
	palabra *paux;
	
	paux = pfin;
	
	if(paux != NULL)
	{
		gotoxy(5,6); cout << "El texto invertido es: ";
		while(paux != NULL)
		{
			auxstring = paux->palabras;								
			cout << " " << paux->palabras;
			paux = paux->psig;
		}	
	}
	else
	{
		gotoxy(5,7); cout << endl << "Error.No hay texto.";
	}
	getch();
}
