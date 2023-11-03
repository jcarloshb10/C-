#include<iostream>
using namespace std;
main()
{
	char (*);
	long i,ci;
	
	cout<<"impares y asteriscos\n";
	cout<<"digite cantidad de impares\n";
	cin>>ci;
	cout<<"\n";
	for(i=1;i<=ci;i++)
		{
			if(i%2==1)
				{
					cout<<"*";
				}
		}
	cout<<"\n";

	system("pause");
}
