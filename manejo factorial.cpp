#include <iostream>
#include <ctype.h>
#include <cstring>

using namespace std; 

long double factorial(long); 
void encabezado(char texto[]);



int main ()
{
	long numero, li,lf,f; 
	char opcion; 
	
	do
	{
		system ("cls"); 
		encabezado("menu para calculo factorial");
	 	cout<< "u: factorial unico numero "<< endl; 
		cout<< "s: factorial de una seie de numeros"<< endl; 
		cout<< "x: salir"<< endl; 
		cout<< "cual opcion: "; cin>> opcion; 
		opcion = tolower (opcion); 
		switch (opcion)
		{
			case 'u': 
				cout<< "ingresa numero "; cin>> numero; 
				cout<< "el factorial de " << numero << " es: ";
				cout<< factorial(numero) << endl<< endl;
				encabezado ("termina el calculo");
				system ("pause"); 
				break; 
			
			case 's': 
				cout<< "ingresa el limite inicial de la serie: "<< endl; 
				cin>> li; 
				if (li>=0)
				{
					cout<< "ingresar limite final de la serie: "<< endl; 
					cin>> lf;
					if (lf > li)
					{
						for (f=li; f<=lf; f++)
						{
							cout<< f << "! = " << factorial (f) << endl<< endl; 
						}
						encabezado ("termina el calculo de la serie");
						system ("pause"); 
					} 
					else 
					{
						cout<< "el limite final debe ser mayor que el limite inicial" << endl; 
					}
				}
				else
				{
					cout<< "el limite inicial debe ser mayor o igual a cero (0)"<< endl; 
				}
				break;
				 
			case 'x':
				cout<<endl; 
			
			break; 
			default :
				cout<< "esa opcion no existe";  
		}
		  		
	}while (opcion != 'x'); 
	
	
	
	
	system("pause"); 
	return 0; 
}

void encabezado (char texto[])
{
	long tamano, posicion, e; 
	
	tamano=strlen(texto);
	if (tamano<80)
	    posicion= (80-tamano)/2;
	else 
		posicion=1;   
	for (e=1;e<=posicion; e++)
	
		cout<< " ";
		for (e=1; e<=tamano; e++)
			cout<< "*";  
	cout<< texto <<endl<< endl; 
	
}



long double factorial(long n)
{
	long f; 
	long double resultado; 
	resultado=1;
	for (f=1; f<=n; f++)
	{
		resultado *= f; 
	}
	
	return (resultado); 		
}














