#include<iostream>
#include <math.h>
using namespace std;
void primo(int v[100], int pos);

int main()
{
	int n,i,v[100] ;
	system("cls");
	system("color F1");
	cout<<"numeros primos"<<endl;
	cout<<"digite cantidad de numeros a evaluar ";cin>>n;
	while(n<1)
	{	
		cout<<"valor no valido, digite cantidad de numeros a evaluar ";cin>>n;
	}
	for(i=0;i<n;i++)
	{			
		cout<<"digite valor del numero "<<i+1<<": ";cin>>v[i];
	}
	cout<<endl;
	
	for(i=0;i<n;i++)
	{			
		cout<<v[i];
		primo(v,i);
	}
	cout<<endl;
	cout<<"hecho por:"<<endl;
	cout<<"Ingenier"<<(char)161<<"a de Sistemas Grupo 1"<<endl;
	cout<<"Universidad de nari"<<(char)164<<"o"<<endl;
	system("pause");
	return 0;
}


void primo(int v[100], int pos)
{
	int i,cont=0;
	if(v[pos]<1)
	{
		cout<<" no es primo";
	}
	else
	{	
		for(i=1;i<=v[pos];i++)
		{
			if(v[pos]%i==0)
			{
				cont++;
			}
		}
		if(cont>2)
		{
			cout<<" no es primo";
		}
		else
		{
			cout<<" es primo";
		}
	}
	cout<<endl;
}
