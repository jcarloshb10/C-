/*
	MINICALCULADORA interpretada
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	char expresion[100], caracteres_validos[]="+-*/ .",
		operador,  numero1c[20], numero2c[20], resultadoc[30], otra;
	double numero1, numero2, resultado;
	long va_expresion, va_caracteres_validos, va_numero, va_auxiliar; // contadores o indices para las cadenas
	bool caracter_valido;
	
	system("color F0");
	cout << "\t      MINICALCULADORA interpretada" << endl
		 << "\t Dos valores y un operador (+, -, *, /) " << endl
	     << "\t****************************************" << endl
		 << endl;
	

	do
	{
		cout << endl << "Ingresa una expresi\242n matem\240tica: "; cin.getline(expresion, sizeof(expresion)-1);
		
		// verificación de caracteres válidos
		va_expresion = 0;

		do
		{
			caracter_valido = false;
			for(va_caracteres_validos = 0; va_caracteres_validos<strlen(caracteres_validos); va_caracteres_validos++)
			{
				if (isdigit(expresion[va_expresion]) or (expresion[va_expresion] == caracteres_validos[va_caracteres_validos]))
				{
					caracter_valido = true;
				}
			}
			va_expresion++;
		} while (caracter_valido and va_expresion < strlen(expresion));

		if (caracter_valido)
		{
			// 	Para quitar espacios en la cadena validada
	 		va_expresion=0;
			while (expresion[va_expresion] != '\0')
			{	
				if (expresion[va_expresion] == ' ')
				{
						// proceso de movimientos de caracteres de izquierda a derecha
						for (va_auxiliar = va_expresion; va_auxiliar<strlen(expresion); va_auxiliar++)
						{
							expresion[va_auxiliar] = expresion[va_auxiliar+1];
						}
						va_expresion--;
				}
				va_expresion++;
			}
	
			va_expresion = 0;
			va_numero = 0;

			// Separación del primer número
			while (isdigit(expresion[va_expresion]) or expresion[va_expresion] == '.')
			{
				numero1c[va_numero] = expresion[va_expresion];
				va_numero++;
				va_expresion++;
			}
			numero1c[va_numero] = '\0';

			// toma el operador
			operador = expresion[va_expresion];
			va_expresion++;

			// Separación del segundo número
			va_numero = 0;
			while (expresion[va_expresion] != '\0')
			{
				numero2c[va_numero] = expresion[va_expresion];
				va_numero++;
				va_expresion++;
			}
			numero2c[va_numero] = '\0';
			
			numero1 = atof(numero1c);
			numero2 = atof(numero2c);

			// segun el operador
			caracter_valido = true;
			switch (operador)
			{
				case '+':
					resultado = numero1+numero2;
					break;
				case '-':
					resultado = numero1-numero2;
					break;
				case '*':
					resultado = numero1*numero2;
					break;
				case '/':
					if (numero2 == 0)
					{
						cout << "ERROR divisi\242n por cero " << endl;
						caracter_valido = false;
					}
					else
					{
						resultado = numero1/numero2;
					}
					break;
				default:
					cout << "Operador no v\240lido o mal digitado uno de los n\243meros" << endl;
					caracter_valido = false;
					break;
			}
			if (caracter_valido)
			{
				strcpy(expresion, numero1c);
				strcat(expresion," ");
				va_expresion = strlen(expresion);
				expresion[va_expresion] = operador;
				expresion[va_expresion+1] = '\0',
				strcat(expresion," ");
				strcat(expresion,numero2c);
				gcvt(resultado, 15, resultadoc);
				strcat(expresion," = ");
				strcat(expresion,resultadoc);
				cout << "**********************************" << endl
					 << "\t" << expresion << endl
					 << "**********************************" << endl;
			}
		}
		else
		{
			cout << "Hay un caracter inv\240lido en la posici\242n " << va_expresion << endl;
		}
		
		cout <<endl<< "Calcular otra expresi\242n matem\240tica s/n "; cin>>otra;
		cin.ignore();
		otra = tolower(otra);

	}while (otra != 'n');
}
