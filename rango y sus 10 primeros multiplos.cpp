#include<iostream>
using namespace std;
main()
{
	long li,ls,i,k;
	cout<<"multiplos\n";
	cout<<"digite limite inferior\n";
	cin>>li;
	cout<<"\n";
	cout<<"digite limite superior\n";
	cin>>ls;
	cout<<"\n";
	for(i=li;i<=ls;i++)
		{
			for(k=1;k<=10;k++)
				{
					cout<<i*k<<"\n";
				}
		cout<<"\n";
		}
	system("pause");
}
