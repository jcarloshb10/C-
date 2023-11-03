#include<iostream>
#include<conio.h>
#include<ctype.h>
#include <cmath>
#include <cstring>
const int MAXP=10000;

void can_parrafos(char pal[MAXP]);
void canespacios(char pal[MAXP]);
void totalcaracteres(char pal[MAXP]);
void canptcmyptcm(char pal[MAXP]);
void contarPalabras(char pal[MAXP]);

using namespace std;
main()
{
	char pal[MAXP],opcion[0];   
	cout<<"Estadisticas del texto\n\n";
	cout<<"Hecho por: Sebastian Bastidas - Jean Carlos Hernandez"<<endl;
	cout<<"Ingenier"<<(char)161<<"a de Sistemas Grupo 1"<<endl;
	cout<<"Universidad de nari"<<(char)164<<"o"<<endl<<endl;
	cout<<"- Digite las frases, palabras o parrafos. Recuerde que la tecla enter (para salto de linea) se ha reemplazado por '**' (doble asterisco)\n\n";
	cin.getline(pal,sizeof(pal)-1);
	canptcmyptcm(pal);
	totalcaracteres(pal);
	canespacios(pal);
	contarPalabras(pal);
	can_parrafos(pal);
}

void canptcmyptcm(char pal[MAXP]) 
{
	int cont_com=0,cont_punt=0,cont_puntycom=0,i;

	for(i=0;i<strlen(pal);i++)
	{
		if(pal[i]==',')
		{
			cont_com=cont_com+1;
		}
		if(pal[i]=='.')
		{
			cont_punt=cont_punt+1;
		}
		if(pal[i]==';')
		{
			cont_puntycom=cont_puntycom+1;
		}
	}
	cout<<"\n- Hay "<<cont_com<<" coma(s) (.), hay "<<cont_punt<<" punto(s) y hay "<<cont_puntycom<<" punto y coma(s)(;)."<<endl;
}

void totalcaracteres(char pal[MAXP])
{
	cout<<"\n- El total de caracteres es : "<<strlen(pal)<<" Recuerde que el salto de linea equivale a dos caracteres. (**)"<<endl;	
}

void canespacios(char pal[MAXP]) 
{
	int cont_esp=0,i;
	for(i=0;i<strlen(pal);i++)
	{
		if(pal[i]==' ')
		{
			cont_esp=cont_esp+1;
		}
	}
	cout<<"\n- Hay "<<cont_esp<<" espacio(s)."<<endl;
}


void contarPalabras(char pal[MAXP]) 
{
	int cont_pal=0,i=0; 
 	for(i=0;i<strlen(pal);i++)
    {
 		if((pal[i] == ' ' && (pal[i+1] != '.' or pal[i+1] != ',' or pal[i+1] != ';') ) or ((pal[i]=='*' && pal[i+1]=='*') && (pal[i+2] != '.' or pal[i+2] != ',' or pal[i+2] != ';')))
        {
        	if(pal[i-1]!=' ')
        	{
        		cont_pal++;
			}
           
        }
    }
 	cout<<"\n- Hay "<<cont_pal+1<<" palabra(s)."<<endl;
}

void can_parrafos(char pal[MAXP])  
{
	int cont_par=0,i=0; 
 	for(i=0;i<strlen(pal);i++)
    {
 		if((pal[i] == '*' && pal[i+1] == '*') )
    	{	
            cont_par++;
        }
    }
 	cout<<"\n- Hay "<<cont_par+1<<" parrafo(s)."<<endl<<endl;
}

