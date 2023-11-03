#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<iomanip>
//#include<conio.h>
#include "d:/conio/include/conio.h"
using namespace std;

int main()
{
	
}

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
int cont;

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

bool esentero(char n[20])
{
    int i=0,cont=0;
    bool entero=false;
    
    while(n[i]!='\0')
    {
        if(isdigit(n[i]))
        {
            cont++;
        }
        i++;
    }
    if(i>=1 and i==cont)
    {
        entero=true;
    }
    return(entero);
}

bool esnumero(char n[20])
{
    int i=0,cont=0,ver=0,verb=0;
    bool numero=false;
    
    while(n[i]!='\0')
    {
        if(isdigit(n[i]) or n[0]=='-' or n[i]=='.')
        {
            cont++;
            if(n[i]=='-')
            {
                ver++;
            }
            if(n[i]=='-' && n[i+1]!=isdigit(n[i+1]))
            {
                ver++;
            }            
            if(n[i]=='.')
            {
                verb++;
            }
        }
        i++;
    }
    if(i>=1 && i==cont && ver<2 && verb<2)
    {
        numero=true;
    }
    if(n[0]=='.' or (n[0]=='-' && cont==1))
    {
    	numero=false;
	}
    return(numero);   
}
