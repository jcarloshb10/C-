#include <iostream>
using namespace std;
main()
{
	system("color 0A");
	float p1,p2,propar,nef,ntd,acumpg=0,acumemd=0;
	int n,i,contnpe=0,contemd=0,contapro=0,contrepro=0;
	cout<<"NOTAS\n";
	cout<<"Digite numero de estudiantes\n";
	cin>>n;
	for(i=1;i<=n;i=i+1)
	{
	cout<<"digite nota del parcial 1\n";
	cin>>p1;
	cout<<"digite nota del parcial 2\n";
	cin>>p2;
	propar=((p1+p2)/2);
	if(propar<2.5)
		{
		cout<<"No puede presentar examen final, su nota definitiva es "<<propar<<"\n";
		ntd=propar;
		contnpe=contnpe+1;
		}
	else
		{
		cout<<"digite nota de examen final\n";
		cin>>nef;
			if(nef<2)
				{
				ntd=nef;
				contemd=contemd+1;
				acumemd=acumemd+nef;
				cout<<"su nota definitiva es "<<nef<<"\n";
				}
			else
				{
				ntd=p1*0.3+p2*0.3+nef*0.4;
				cout<<"su nota definitiva es "<<ntd<<"\n";
				}
		}
	acumpg=acumpg+ntd;
	if(ntd>=3)
		{
			contapro=contapro+1;
		}	
	else
		{
			contrepro=contrepro+1;
		}	
	}
cout<<"\n\nel promedio del grupo es "<<acumpg/n<<"\n\n";
cout<<"el numero de estudiantes que no presentan examen final es "<<contnpe<<"\n\n";
cout<<"el numero de estudiantes con examen final con nota menor a 2 es "<<contemd<<"\n\n";
cout<<"el promedio de los estudiantes con examen final con nota menor a 2 es "<<acumemd/contemd<<"\n\n";
cout<<"el numero de aprobados es "<<contapro<<"\n\n";
cout<<"el numero de estudiantes reprobados es "<<contrepro<<"\n\n";	
system("pause");	
}
