#include<iostream>
#include <conio.h>
using namespace std;
main()
{
	float nota[200][5],acumnd=0,contta=0;
	int fil,col,nest,cod,sw=0;
	cout<<"Matriz\n";
	cout<<"digite cantidad de estudiantes\n";
	cin>>nest;
	for(fil=0;fil<=nest-1;fil=fil+1)
	{
		cout<<"\nEstudiante N° "<<fil+1<<"\n";
		cout<<"Digite codigo\n";
		cin>>nota[fil][0];
		cout<<"\nDigite nota de parciales\n";
		cin>>nota[fil][1];
		cout<<"\nDigite nota de talleres\n";
		cin>>nota[fil][2];
		cout<<"\nDigite nota de laboratorios\n";
		cin>>nota[fil][3];
		nota[fil][4]=nota[fil][1]*0.5+nota[fil][2]*0.3+nota[fil][3]*0.2;
		cout<<"\nLa nota definitiva es "<<nota[fil][4];
		acumnd=acumnd+nota[fil][4];
	}
	cout<<"\nCodigo\tParciales\tTalleres\tLaboratorios\tNota definitiva\n";
	for(fil=0;fil<=nest-1;fil=fil+1)
	{
	cout<<nota[fil][0]<<"\t"<<nota[fil][1]<<"\t\t"<<nota[fil][2]<<"\t\t"<<nota[fil][3]<<"\t\t"<<nota[fil][4]<<"\n";
	}
	cout<<"\nDigite un codigo a buscar ";
	cin>>cod;
	for(fil=0;fil<=nest-1;fil=fil+1)
	{
		if(cod==nota[fil][0])
		{
			cout<<"\nCodigo\tParciales\tTalleres\tLaboratorios\tNota definitiva\n";
			cout<<nota[fil][0]<<"\t"<<nota[fil][1]<<"\t\t"<<nota[fil][2]<<"\t\t"<<nota[fil][3]<<"\t\t"<<nota[fil][4]<<"\n";
			fil=nest;//opcion de desbordamiento.
			sw=1;
		}
	}
	if(sw==0)
	{
		cout<<"No existe estudiante con ese codigo\n ";
	}
	cout<<"\nListado de estudiantes que reprueban el parcial ";
	cout<<"\nCodigo\tParcial\n";
	for(fil=0;fil<=nest-1;fil=fil+1)
	{
		if(nota[fil][1]<3.0)
		{
			cout<<nota[fil][0]<<"\t"<<nota[fil][1]<<"\n";
		}	
	}
	cout<<"\nEl promedio de las notas definitivas es "<<acumnd/nest;
	for(fil=0;fil<=nest-1;fil=fil+1)
	{
		if(nota[fil][2]>3.0)
		{
			contta=contta+1;
		}	
	}
	cout<<"\nEl numero de estudiantes que aprueban los talleres es "<<contta;
	getch();
}
