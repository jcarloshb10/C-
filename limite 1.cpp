#include<iostream>
using namespace std;
main()
{
	double n1,n2,c1,i;
	cout<<"Ingrese el valor del limite inferior\n";
	cin>>n1;
	do
	{
		cout<<"\nIngrese el valor del limite superior\n";
		cin>>n2;
	}while (n2<n1);
	
do
{
	cout<<"\nIngresa el valor de cambio\n";	
	cin>>c1;
} while (c1<=0);
for(i=n1;i<=n2;i+=c1)
{
	cout<< i<< endl;
	
}
system("pause");
}






