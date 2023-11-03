#include <iostream>
#include <cstdlib>  // Permite manejar los comando srand() y ran()
#include <ctime>   // Permite manejar el comando time(0)
#include <fstream>

using namespace std;

const int MAX_F=100;
const int MAX_C=100;

void crear_matriz_aletoria(double [][MAX_C], long &, long & );
void reportar_matriz(double [][MAX_C], long, long, char []);
void grabar_matriz(double [][MAX_C], long, long, char [], char [] );

int main()
{
	long filas_m1, columnas_m1, filas_m2, columnas_m2;
	double m1[MAX_F][MAX_C], m2[MAX_F][MAX_C];
	srand(time(0));
	char narchivo[30];
	cout << "Ingresa nombre de archivo con .txt ";
	cin >> narchivo;
	// MATRIZ 1
	fstream datos;
	datos.open(narchivo,ios::out);
	datos.close();
	crear_matriz_aletoria(m1, filas_m1, columnas_m1);
	reportar_matriz(m1, filas_m1, columnas_m1, "MATRIZ 1");
	grabar_matriz(m1, filas_m1, columnas_m1, "MATRIZ 1", narchivo);
	// MATRIZ 2
	crear_matriz_aletoria(m2, filas_m2, columnas_m2);
	reportar_matriz(m2, filas_m2, columnas_m2, "MATRIZ 2");
	grabar_matriz(m2, filas_m2, columnas_m2, "MATRIZ 2", narchivo);
	
	
	system("pause");
	return 0;
}

void crear_matriz_aletoria(double matriz[][MAX_C], long &nfilas, long &ncolumnas )
{
	long f,c;
	do
	{
		nfilas=rand()%10;
	}while (nfilas<2 or nfilas>MAX_F);
	do
	{
		ncolumnas=rand()%10;
	}while (ncolumnas<2 or ncolumnas>MAX_C);

	for (f=0; f<nfilas; f++)	
		for (c=0; c<ncolumnas; c++)
			matriz[f][c]=double(rand())/5;
		
}

void reportar_matriz(double matriz[][MAX_C], long nfilas, long ncolumnas, char nombre[])
{
	long f,c;
	cout << endl << nombre << " : " << nfilas << " x " << ncolumnas << endl << endl;
	
		for (f=0; f<nfilas; f++)	
		{
			for (c=0; c<ncolumnas; c++)
			{
				cout << matriz[f][c] << "\t";
			}
			cout << endl;
		}
		cout << endl;
}
void grabar_matriz(double matriz[][MAX_C], long nfilas, long ncolumnas, char nombre[], char narchivo[])
{
	long f,c;
	
	fstream datos(narchivo,ios::app);
	
	datos << endl << nombre << " : " << nfilas << " x " << ncolumnas << endl << endl;
	
		for (f=0; f<nfilas; f++)	
		{
			for (c=0; c<ncolumnas; c++)
			{
				datos << matriz[f][c] << "\t";
			}
			datos << endl;
		}
		datos << endl;
	datos.close();	
}

