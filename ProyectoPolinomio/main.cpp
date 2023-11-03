#include<iostream>
#include<cstdlib>
#include<ctype.h>
#include<conio.h>
//#include "d:/conio/include/conio.h" 

using namespace std;

struct polinomios
{
	
	char puntero_vec_pol1[100];
	char puntero_vec_pol2[100];
	polinomios *psig;
};

int grado_pol1,grado_pol2;

polinomios *pini=NULL;
polinomios *pfin=NULL;

void menu();
void ingr_polinomios();
void visualizar_polinomios();
void producto_pol1xpol2();
void terminar_programa();
void creditos();
void colocar_ventanas(int x1,int y1, int x2,int y2,int col_fondo, int col_tex); 
void colocar_borde(int x1, int y1, int x2, int y2);

int main()
{
	system("mode con:cols=102lines=32");
	system("cls");
	colocar_ventanas(1,1,102,5,4,14);
	colocar_borde(1,1,102,5);
	gotoxy(40,3);cout<<"PROYECTO POLINOMIOS";
	
	menu();
	getch();
	
	
}

void menu()
{
	char opcion[2];
	do
	{
		colocar_ventanas(1,6,102,32,1,15);
		colocar_borde(1,1,102,26);
		gotoxy(49,3);cout<<"MEN"<<(char)233;	
		
		colocar_ventanas(21,11,82,27,15,0);
		colocar_borde(1,1,62,17);
		gotoxy(2,2);cout<<" A) INGRESO DE POLINOMIOS";
		gotoxy(2,3);cout<<" B) VISUALIZAR LOS POLINOMIOS INGRESADOS";
		gotoxy(2,4);cout<<" C) OBTENER EL PRODUCTO DE LOS POLINOMIOS";
		gotoxy(2,6);cout<<" D) CR"<<(char)144<<"DITOS";
		gotoxy(2,7);cout<<" X) SALIR";
		gotoxy(2,9);cout<<" DIGITE OPCI"<<(char)224<<"N: ";	
		cin>>opcion;
		opcion[0]=tolower(opcion[0]);
		cin.ignore();
		if(opcion[1]=='\0')
		{
			switch(opcion[0])
	    	{
	    		case 'a':
	        		ingr_polinomios(); 
	        	break;
	    		case 'b':
	        		visualizar_polinomios(); 
	        	break;
	    		case 'c':
	        		producto_pol1xpol2();
	        	break;
	        	break;
	    		case 'd':
	        		creditos();
	        	break;
	        	case 'x':
					terminar_programa();
				break;
				default:
					gotoxy(18,10);cout<<"OPCI"<<(char)224<<"N NO V"<<(char)181<<"LIDA, VUELVA A DIGITAR";
				
					getch();
	    		break;
	    	}
		}
		else
		{
			gotoxy(18,10);cout<<"OPCI"<<(char)224<<"N NO V"<<(char)181<<"LIDA, VUELVA A DIGITAR";
				
			getch();
		}

	}while(opcion[0]!='x' );
}

void ingr_polinomios()
{
	polinomios *paux;

	paux=new polinomios;

	int i,y;
	
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(38,3);cout<<"INGRESO DE POLINOMIOS";
	
	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);			
   	gotoxy(4,5);cout<<"INGRESE EL GRADO DEL PRIMER POLINOMIO: ";
	cin>>grado_pol1;
	cin.ignore();
	for(i=0;i<=grado_pol1;i++)
	{
			paux=new polinomios;
			gotoxy(4,6+i);cout<<"INGRESE EL COEFICIENTE DEL GRADO "<<i<<" : ";cin>>paux->puntero_vec_pol1;
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

	gotoxy(4,10);cout<<"INGRESE EL GRADO DEL SEGUNDO POLINOMIO: ";	
    cin>>grado_pol2;
    cin.ignore();

		for(i=0;i<=grado_pol2;i++)
		{
			paux=new polinomios;
			gotoxy(4,11+i);cout<<"INGRESE EL COEFICIENTE DEL GRADO "<<i<<" : ";cin>>paux->puntero_vec_pol2;
			paux->psig==NULL;
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
	 
    
    getch();
}

void visualizar_polinomios()
{
	
	polinomios *paux;
	paux=pini;
	int y=0,i;
	
	colocar_ventanas(1,6,102,32,10,1);
	colocar_borde(1,1,102,26);
	gotoxy(40,3);cout<<"LISTAR POLINOMIOS";

	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
		
		for(i=0;i<=grado_pol1;i++)
		{
		y++;
		gotoxy(3+6*y,4);cout<<paux->puntero_vec_pol1<<"X^"<<i;
		
		paux=paux->psig;
		}
		y=0;			
		for(i=0;i<=grado_pol2;i++)
		{
		
		gotoxy(3+6*y,5);cout<<paux->puntero_vec_pol2<<"X^"<<i;
		y++;
		paux=paux->psig;
		}	
	
	getch();
}

void producto_pol1xpol2()
{
	
	polinomios *paux;
	paux=pini;
	
	
		
}




void creditos() 
{
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);gotoxy(40,3);
	cout<<"PROYECTO REALIZADO POR: ";

	colocar_ventanas(21,11,82,27,15,0);
	colocar_borde(1,1,62,17);
	gotoxy(7,3);cout<<"JEAN CARLOS HERNANDEZ BENAVIDES C"<<(char)224<<"DIGO: 217034199";
	gotoxy(10,5);cout<<"INGENIER"<<(char)214<<"A DE SISTEMAS - 3er SEMESTRE Grupo 1";
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







