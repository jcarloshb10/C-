#include<iostream>
#include<conio.h>
#include<ctype.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include<fstream>
using namespace std;
main()
{
	fstream archivo;
	char pal[200];   
	int i,j,cont,clet;
	long va_expresion, va_caracteres_validos, va_letra, va_auxiliar;
	cout<<"\nDETERMINAR SI UNA PALABRA O FRASE ES UN PALINDROMO\n\n";
	cout<<"\t- Digite la palabra o frase (Escribir sin espacios entre letras y palabras, de lo contrario habr\240 un error).\n\n";
	cin.getline(pal,sizeof(pal)-1); 
	cout<<"\t- Digite la cantidad de letras que tiene su palabra o frase (en numeros, de lo contrario habr\240 un error).\n\n";
	cout<<"\t";cin>>clet;cout<<"\n"; 
	i=0;
	j=clet-1;
	cont=0;
	
	archivo.open("palindromas.txt", ios::out | ios::app);

	archivo<<"Palindromas"<<endl;
	archivo<<"Andres Fernando Aguirre 217034008 "<<endl;
	archivo<<"Jean Carlos Hernandez 217034199 "<<endl;

		
	do
	{
			// 	Para quitar espacios en la cadena validada
	 		va_expresion=0;
			while (pal[va_expresion] != '\0')
			{	
				if (pal[va_expresion] == ' ')
				{
						// proceso de movimientos de caracteres de izquierda a derecha
						for (va_auxiliar = va_expresion; va_auxiliar<strlen(pal); va_auxiliar++)
						{
							pal[va_auxiliar] = pal[va_auxiliar+1];
						}
						va_expresion--;
				}
				va_expresion++;
			}
	
			pal[i]=tolower(pal[i]);
			
			
			// ES O NO PALINDROMA
			if(pal[i]==pal[j])
			{
				cont=cont+0;
	 		}
	     	else
		    {
				cont=cont+1;
	     	}
	i=i+1;
	j=j-1;
	}while(i<j);
	
	
	
	if(cont==0)
		{
			cout<<"\tR// La palabra o frase SI es un palindromo.\n\n";
		}
	if(cont>0) 
		{
			cout<<"\tR// La palabra o frase NO es un palindromo.\n\n";
		}
	cout<<"\t";system("pause");
}
