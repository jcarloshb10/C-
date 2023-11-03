#include<iostream>

using namespace std;

int main()
{
	double sol,dol,mar,tdol,eur;
	system("cls");
	cout<<"Donaciones"<<endl;
	cout<<"digite cantidad de dinero en soles ";
	cin>>sol;
	cout<<"digite cantidad de dinero en marcos Alemanes ";
	cin>>mar;
	cout<<"digite cantidad de dinero en dolares ";
	cin>>dol;
	tdol=dol+(sol/3.52)+(mar/2.08);
	eur=tdol*0.98; 
	cout<<endl;
	cout<<"Para el centro medico se donarán "<<eur*0.6<< " euros "<<endl;	
	cout<<"Para el comedor de niños se donarán "<<eur*0.3<< " euros "<<endl;;
	cout<<"Para gastos administrativos "<<eur*0.1<< " euros "<<endl<<endl;
	cout<<"Trabajo realizado por: Jean Carlos Hernandez Benavides"<<endl;
	cout<<"Ingenieria de Sistemas Grupo 1"<<endl;
	cout<<"Universidad de Nariño"<<endl;
	system("pause");
	return 0;
}
