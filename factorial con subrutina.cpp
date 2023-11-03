#include <iostream>
#include <cctype>

using namespace std;

long factorial(long);

int main()
{
	long numero, li, lf, f;
	char opcion;
	
	do
	{
		system("cls");
		cout << "u: Factorial unico numero " << endl
			<< "s: Factorial de una serie de numeros"<< endl
			<< "x: Salir" << endl;
		cout << "Cual opcion: "; cin >> opcion;
		opcion = tolower(opcion);
		switch(opcion)
		{
			case 'u':
					cout << "Ingresa el numero "; cin >> numero;
					cout << "El factorial de " << numero << " es " 
						<< factorial(numero) << endl;
					system("pause");
					break;
			case 's':
					cout << "Ingresa el limite inicial de la serie: ";
					cin >> li;
					if (li >= 0)
					{
						cout << "Ingresa el limite final de la serie: ";
						cin >> lf;
						if (lf > li)
						{
							for (f=li; f<=lf; f++)
							{
								cout << f << "! = " << factorial(f) << endl;
							}
							system("pause");
						}
						else
						{
							cout << "El limite final debe ser mayor que el inicial" << endl;
						}
					}
					else
					{
						cout << "El limite inicial debe ser mayor o igual a cero (0)" << endl;
					}
				break;
			case 'x':
					cout << endl;
				break;
			default :
				cout << "Esa opcion no existe" << endl;
		}
	}
	system("pause");
	return 0;
	
	long factorial(long n)
{
	long f, resultado;
	resultado=1;
	for(f=1;f<=n;f++)
	{
		resultado*=f;
	}
	return(resultado);
}
}

