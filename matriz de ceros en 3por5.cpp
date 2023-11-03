#include<iostream>
#include <conio.h>
using namespace std;
main()
{
	int ma[3][5],fil,col;
	cout<<"Matriz\n";
	cout<<"digite cantidad de filas\n "
	for(fil=0;fil<=2;fil=fil+1)
	{
		for(col=0;col<=4;col=col+1)
		{
			ma[fil][col]=fil*col;
			cout<<ma[fil][col]<<"\t";
		}
		cout<<"\n";
	}
	getch();
}
