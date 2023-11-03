#include<iostream>
#include <math.h>
using namespace std;

int main()
{
	double a,b,c;
	system("cls");
	cout<<"Calculadora de ecuaciones de segundo grado"<<endl;
	cout<<"Resuelve ecuaciones de la forma ax^2+bx+c=0 "<<endl;
	cout<<"Digite valor de a ";cin>>a;	
	cout<<"Digite valor de b ";cin>>b;
	cout<<"Digite valor de c ";cin>>c;
	cout<<endl;
	if(a==0)
	{
	cout<<"La ecuación no es cuadratica "<<endl;
	}
	else
	{
	
		if((b*b)-(4*a*c)==0)
		{
			cout<<"La respuesta es x="<<-b/(2*a)<<endl;
		}
		else
		{
			if((b*b)-(4*a*c)>0)
			{
				cout<<"Las respuestas de la ecuacion son"<<endl;
				cout<<"x1= "<<(-b+sqrt((b*b)-(4*a*c)))/(2*a)<<endl;
				cout<<"x1= "<<(-b-sqrt((b*b)-(4*a*c)))/(2*a)<<endl;
			}
			else
			{
				cout<<"Las respuestas de la ecuacion son"<<endl;
				cout<<"x1= "<<-b/(2*a)<<" + "<<(sqrt(-((b*b)-(4*a*c))))/(2*a)<< "i"<<endl;
				cout<<"x2= "<<-b/(2*a)<<" - "<<(sqrt(-((b*b)-(4*a*c))))/(2*a)<< "i"<<endl;
			}
		}

	}
	cout<<endl;
	cout<<"Realizado por Jean Carlos Hernandez Benavides"<<endl;
	cout<<"Ingenieria de sistemas Grupo 1"<<endl;
	cout<<"Universidad de Nariño"<<endl;
	system("pause");
	return 0;
}
