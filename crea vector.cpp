#include<iostream>
#include<conio.h>
using namespace std;

main()
{
	system("cls");
	int i=0;
	int j;
	int v[j],num;

	
	cout<<"Digite largo del vector "<<endl;
	cin>>j;
	for(i=0;i<=(j-1);i++)
	{
		cout<<"Digite valor posicion # "<<i+1<<endl;
		cin>>num;
		v[i]=num;
	}
	for(i=0;i<=(j-1);i++)
	{
		cout<<v[i]<<" - ";
	}
	system("pause");
}

