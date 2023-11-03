#include <iostream>
#include<conio.h>
//#include "d:/conio/include/conio.h"
#include "lib.h"
#include <iomanip>

using namespace std;
void menu();
void menudeclarar();
void menuasignar();
void menuoperador();
void menucomparacion();
void menuvec();
void menumatrices();

int main() 
{
	
	menu();
	return 0;
}

void menu()
{
	system ("cls");
	int opcion;
	cout<<setw(50)<<"PROYECTO PUNTEROS"<<endl;
	cout<<endl;
	cout<<" 1) DECLARAR"<<endl;
	cout<<" 2) ASIGNAR"<<endl;
	cout<<" 3) OPERADORES"<<endl;
	cout<<" 4) COMPARACION"<<endl;
	cout<<" 5) VECTORES"<<endl;
	cout<<" 6) MATRICES"<<endl;
	cout<<" 7)SUBPROGRAMAS"<<endl;
	cout<<" 8) ESTRUCTURAS"<<endl;
	cout<<" 9) SALIR"<<endl;
	cout<<" DIGITE OPCION : ";cin>>opcion;
	switch (opcion)
	{
		case 1:
			menudeclarar();
			break;
		case 2:
			menuasignar();
			break;
		case 3:
			menuoperador();	
			break;
		case 4: 
		    menucomparacion();
			break; 
		case 5: 
			menuvec();
			break;
		case 6:
			menumatrices();
				break;
		default:
			
			break;
	}
}

void menudeclarar()
{
	system("cls");
	int num;
	int *pnum;
	pnum =&num;
	cout<<"DIGITE NUMERO: ";	
	cin>>*pnum;
	cout<<"LA DIRECCION DE MEMORIA ES: "<<pnum<<endl;
	cout<<"SU CONTENIDO ES: "<<*pnum<<endl;
}


void menuasignar()
{
	system("cls");
	int num;
	int *pnum1,*pnum2;
	pnum1 =&num;
	pnum2=pnum1;
	cout<<"DIGITE NUMERO: ";	
	cin>>*pnum1;
	cout<<"LA DIRECCION pnum1 "<<pnum1<<endl;
	cout<<"LA DIRECCION pnum2 "<<pnum2<<endl;
	cout<<"EL CONTENIDO ES: "<<*pnum2<<endl;
}

void menuoperador()
{
	system("cls");
	double vdec[10];
	double *pin,*pfin;
	pin=&vdec[0];
	pfin=&vdec[9];
	while(pin<=pfin)
	{
		cin>>*pin;
		pin++;
	}
	pin=&vdec[0];
	int i=1;
	while(pin<=pfin)
	{
		gotoxy(10,i);
		cout<<pin;
		i++;
		pin++;
	}
	
	pin=&vdec[0];
	i=1;
	while(pin<=pfin)
	{
		gotoxy(30,i);
		cout<<*pfin;
		gotoxy(40,i);
		cout<<pfin;
		i++;
		pfin--;
	}
	getch();
}

void menucomparacion ()
{
 system ("cls");
 
int n,i;
int vec[50];
int *paux,sum;
float prom;
cout<<"DIGITE LA CANTIDAD DE DATOS: ";
cin>>n;
paux=&vec[0];
for (i=0;i<n;i++)
	{
		cin>>*paux;
		paux++;
	}
sum=0; 
paux=&vec[0];

for (i=0;i<n;i++)
	{
		sum=sum+(*paux);
		paux++;
	}
prom=(float)sum/n;
cout<<"EL PROMEDIO ES:  "<<prom;
getch();
menu();

}

void menuvec()
{
	int n,i,j;
	int vec[50];
	int *pvec[50];
	int *paux;
	
	cout<<"DIGITE CANTIDAD DE NUMEROS: ";
	cin>>n;
	
	paux=&vec[0];
	
	for (i=0;i<n;i++)
	{
		cout<<"DIGITE NUMERO "<<i+1<<endl;
		cin>>*paux;
		paux++;
	}	
	
	
	for (i=0;i<n;i++)
	{
		pvec[i]=&vec[i];
		
	}
	
	for (i=0;i<n;i++)
	{
		cout<<pvec[i]<<endl;
		
	}
	
	cout<<endl;
	//metodo burbuja ordenamiento
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(*pvec[j]>*pvec[j+1])
			{
				paux=pvec[j];
				pvec[j]=pvec[j+1];
				pvec[j+1]=paux;
			}
		}
	}
	cout<<paux[0];
}

void menumatrices()
{
	int mat[50][50],i,fil,col;
	cout<<"DIGITE NUMERO DE FILAS: ";
	cin>>fil;
	cout<<endl<<"DIGITE NUMERO DE COLUMNAS: ";
	cin>>col;
	
	int *pmat[fil];
	for(i=0;i<fil;i++)
	{
		pmat[i]=&mat[i][0];
	}
	
}
