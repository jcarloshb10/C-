#include<iostream>
#include <conio.h>
using namespace std;
main()
{
	float ma[200][200];
	int fil,col,nfil,ncol;
	cout<<"Matriz\n";
	cout<<"digite cantidad de filas\n";
	cin>>nfil;
	cout<<"digite cantidad de columnas\n";
	cin>>ncol;
	for(fil=0;fil<=nfil-1;fil=fil+1)
	{
		for(col=0;col<=ncol-1;col=col+1)
		{
			ma[nfil][ncol]=0;
			cout<<ma[nfil][ncol]<<"\t";
		}
		cout<<"\n";
	}
	getch();
}
