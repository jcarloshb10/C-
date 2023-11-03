#include<iostream>
#include<conio.h>
using namespace std;
main()
{
	char palabraofrase[200];   
	int i,j,cantidadletras,contador;
	cout<<"Realizado por: Jean Carlos Hernandez Benavides\n";
	cout<<"\n\t\t\t\tDETERMINAR SI UNA PALABRA O FRASE ES UN PALINDROMO\n\n";
	cout<<"\t- Una palabra o frase es un palindromo si puede leerse tanto de izquierda a derecha como de derecha a\n\tizquierda (es decir, expresa lo mismo al ser leido de manera tradicional o al reves).\n\n";
	cout<<"\t- Digite la palabra o frase (Escribir sin espacios entre letras y palabras, de lo contrario habrá un error).\n\n";
	cout<<"\t";cin>>palabraofrase;cout<<"\n"; 
	cout<<"\t- Digite la cantidad de letras que tiene su palabra o frase (en numeros, de lo contrario habrá un error).\n\n";
	cout<<"\t";cin>>cantidadletras;cout<<"\n"; 
	i=0;
	j=cantidadletras-1;
	contador=0;
	do
		{
			if(palabraofrase[i]==palabraofrase[j])
			{
				contador=contador+0;
	 		}
	     	else
		    {
				contador=contador+1;
	     	}
	i=i+1;
	j=j-1;
		}
	while(i<j);
	if(contador==0)
		{
			cout<<"\tR// La palabra o frase SI es un palindromo.\n\n";
		}
	if(contador>0) 
		{
			cout<<"\tR// La palabra o frase NO es un palindromo.\n\n";
		}
	cout<<"\t";system("pause");
}
