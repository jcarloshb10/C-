#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<iomanip>
#include<time.h>
//#include<math.h>
//#include<cstring>
#include<conio.h>
//#include "d:/conio/include/conio.h"

using namespace std;


void menu();
void ingr_dat_jug();
void jugar();
void apostar_color();

void apostar_numero();
void num_ganador();
//void impr_reporte_juego();
void creditos();
void terminar_programa();
void colocar_borde(int x1, int y1, int x2, int y2);
void colocar_ventanas(int x1,int y1, int x2,int y2,int col_fondo, int col_tex);

bool esentero(char n[50]);
bool esnumero(char n[50]);

int n_gan,num_gana;
struct jugador
{
	char nom[50];
	int credito;
};

 struct apuestas
{
	int val_apuesta;
	char col[10]; 
	int numero;
	
};

jugador jug[50];
apuestas apu[50];

int main()
{
	system("mode con:cols=102lines=32");
	system("cls");
	colocar_ventanas(1,1,102,5,4,14);
	colocar_borde(1,1,102,5);
	gotoxy(37,3);
	cout<<"PROYECTO RULETA CASINO";
	
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
		gotoxy(2,2);cout<<" A) INGRESO DE JUGADOR Y SU CREDITO";
		gotoxy(2,3);cout<<" B) JUGAR RULETA";
		gotoxy(2,4);cout<<" C) MOSTRAR REPORTE DE JUGADAS Y SALDO";
		gotoxy(2,5);cout<<" D) CREDITOS";
		gotoxy(2,6);cout<<" E) SALIR";
		gotoxy(2,8);cout<<" DIGITE OPCION: ";	
		cin>>opcion;
		opcion[0]=tolower(opcion[0]);
		cin.ignore();
		if(opcion[1]=='\0')
		{
			switch(opcion[0])
	    	{
	    	case 'a':
	        	ingr_dat_jug(); 
	        break;
	    	case 'b':
	        	jugar(); 
	        break;
	    	case 'c':
	        //	impr_reporte_juego();
	        break;
	    	case 'd':
	        	creditos();
	        break;
	        case 'e':
				terminar_programa();
			break;
			default:
				gotoxy(18,10);cout<<" OPCION NO VALIDA, VUELVA A DIGITAR";
				
				getch();
	    	break;
	    }
		}
		else
		{
			gotoxy(18,10);cout<<" OPCION NO VALIDA, VUELVA A DIGITAR";
				
			getch();
		}

	}while(opcion[0]!='e' );
}

void ingr_dat_jug() //funcion de a
{
	int creditoini,cont=0;
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"REGISTRAR JUGADOR";
	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);	
	gotoxy(4,4);cout<<"NOMBRE:";
	gotoxy(12,4);cin.getline(jug[0].nom,49,'\n');
	do
	{
		gotoxy(4,6+cont);cout<<"CREDITO INICIAL (Minimo 10)";
		gotoxy(32,6+cont);cin>>creditoini;
	if(creditoini>=10)
	{
	jug[0].credito=creditoini;
	}
	else{
		gotoxy(38,6+cont);cout<<"NUMERO NO VALIDO, VUELVA A DIGITAR";
		cont++;
	//	getch();
	}	
	}while(creditoini<10);

}

void jugar()
{
	int cont2=0,val_ap,cont3=0;
	char eleg_jue[2];
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"JUGAR";
	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
	do
	{	
	gotoxy(4,3+cont2);cout<<"DIGITE VALOR APUESTA (minimo 1)";
	gotoxy(36,3+cont2);cin>>val_ap;
	if(val_ap>=1 && val_ap<=jug[0].credito)
	{
	apu[0].val_apuesta=val_ap;
	}
	else
	{
		gotoxy(38,3+cont2);cout<<"NUMERO NO VALIDO, VUELVA A DIGITAR";
		cont2++;
	//	getch();
	}	
	}while(val_ap<1);	

	jug[0].credito=jug[0].credito-apu[0].val_apuesta;
	
	do
	{
	gotoxy(4,7+cont3);cout<<"APOSTAR POR COLOR (A) O POR NUMERO (B)?";
	gotoxy(48,7+cont3);cin>>eleg_jue[0];
	eleg_jue[0]=tolower(eleg_jue[0]);
	switch(eleg_jue[0])
	{
		case 'a':
			apostar_color();
		break;
		case 'b':
			apostar_numero();
		break;
		default: gotoxy(38,7+cont3);cout<<"OPCION NO VALIDA, VUELVA A DIGITAR";
		cont3++;
		break;	
	}
	}while(eleg_jue[0]!= 'a' or eleg_jue[0]!='b');

	cout<<jug[0].nom<<endl;
	cout<<jug[0].credito;
	getch();
}

void apostar_color()
{
	int cont3=0;
	string rojo,negro;
	char eleg_col[2];
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"JUGAR POR COLORES";
	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);

	gotoxy(4,7+cont3);cout<<"APOSTAR POR ROJO (A) O NEGRO (B)?";
	gotoxy(44,7+cont3);cin>>eleg_col[0];
	eleg_col[0]=tolower(eleg_col[0]);
	srand(time(0));
	int n_gan;
	n_gan=1+rand()%(36);
	
	if(n_gan%2==0 )
	{
		if(eleg_col[0]=='a')
		{
			gotoxy(4,10);cout<<"GANASTE";
			getch();	
		}
		else
		{
			gotoxy(4,10);cout<<"PERDISTE";
			getch();
		}
	}
	else
	{
		if(eleg_col[0]=='b')
		{
			gotoxy(4,10);cout<<"GANASTE";
			getch();	
		}
		else
		{
			gotoxy(4,10);cout<<"PERDISTE";
			getch();
		}
	}
}


void apostar_numero()
{
	int cont4=0,num;
	char eleg_col[2];
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"JUGAR POR NUMEROS (DEL 1 AL 36)";
	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
	do
	{	
	gotoxy(4,3+cont4);cout<<"DIGITE NUMERO";
	gotoxy(36,3+cont4);cin>>num;
	if(num>=1 && num<=36)
	{
	apu[0].numero;
	num_ganador();
	}
	else
	{
		gotoxy(38,3+cont4);cout<<"NUMERO NO VALIDO, VUELVA A DIGITAR";
		cont4++;
	}	
	}while(num<1 or num>36);
	
}

void num_ganador()
{
	srand(time(0));
	int num_gana;
	num_gana=1+rand()%(36);
	gotoxy(38,8);cout<<"El numero ganador es: "<<num_gana;
	getch();
	if(apu[0].numero==num_gana)
	{
		gotoxy(5,10);cout<<"GANASTE ";
	}
	else
	{
		gotoxy(5,10);cout<<"PERDISTE ";
	}
}

void creditos() //funcion de d
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

void terminar_programa() //funcion de e
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



