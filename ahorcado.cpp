#include<cstdlib>
#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

main()
{ 

	char texto[50];

	cout<<endl<<endl<<" ===== JUEGO DEL AHORCADO ===== "<<endl<<endl;

	cout<<" ===== Escriba la palabra o frase que desea adivinar ====="<<endl<<endl;

	cin.getline(texto,sizeof(texto)-1);

	cout<<endl;

	int n=strlen(texto);

	char aux[n];

	for (int i=0;i < n;i++)
	{
		if(texto[i]!=' ')
		{
			aux[i]='-';	
		}
		else
		{
			aux[i]=' ';
		}
	}

	char letra[2];

	int ce=0, completa=0, encontrado;

	while(ce<7 && completa==0)
	{

		cout<<endl<<endl<<"Escriba la letra para completar la palabra"<<endl;
		cin>>letra;

		encontrado=0;

		for (int i=0;i < n;i++)
		{

			if(texto[i]==letra[0])
			{

				encontrado=1;

				aux[i]=letra[0];
				cout<<"LETRA ACERTADA "<<endl;

			}
		}

		if(encontrado==0)
		{

			ce++;
			if(ce==7)
			{
				cout<<endl<<"PERDISTE"<<endl;	
				cout<<"ERA: "<<endl;	
				for(int j=0;j<n;j++)
				{
					cout<<texto[j];	
				}
				cout<<endl;
				system("pause");
				exit(0);
			}
			else
			{
				cout<<"TIENES "<<7-ce<<" OPORTUNIDAD(ES) AUN"<<endl;
			}
		}

		completa=1;

		for (int i=0;i < n;i++)
		{

			if(aux[i]=='-')
			{ 
				completa=0;
			}

		}
	
		for(int j=0;j<n;j++)
		{
			cout<<aux[j];	
		}	
	
		}
					

			
		if(completa==1)
		{
			cout<<endl<<endl<<"GANASTE"<<endl;
		}

	system("pause");

}

