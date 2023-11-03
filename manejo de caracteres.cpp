#include <iostream>
using namespace std; 
int main ()
{
	// manejo de cadenas de caracteres 
	char nombre_est [41],vocales[]="aeiouAEIOU";
	int tamano_f, tamano_l,recorrer,recorrer_vo,posicion,can_vo; 
	nombre_est[0]='s';
	nombre_est[1]='e';
	nombre_est[2]='g';
	nombre_est[3]='u'; 
	nombre_est[4]='n'; 
	nombre_est[5]='d'; 
	nombre_est[6]='o';
	nombre_est[7]='\0'; 
	
	cout<< nombre_est;
	tamano_l=0; 
	while (nombre_est[tamano_l]!='\0')
	{
		tamano_l++; 
	}
	cout<<"\nEl tamano logico de la cadena es: "<<tamano_l<<endl; 
	cin.getline(nombre_est, sizeof(nombre_est)-1); 
	tamano_f= sizeof(nombre_est)-1;
	cout<<"el tamano fisico de la cadena es:"<< tamano_f<<endl; 
	cout<< nombre_est<<"\n";
	
	//impresion vertical
	recorrer=0; 
	while (nombre_est[recorrer]!='\0')
	{
		cout<< nombre_est[recorrer]<<endl; 
		recorrer++; 
	}
	//Recorrido inverso  
	for (recorrer=tamano_l-1;recorrer<=0;recorrer--)
	{
		cout <<nombre_est[recorrer]; 
	}
	cout<<endl; 
	
	//Cambio de caracter 
	do
	{
		cout<<"ingresa posicion del caracter a cambiar: "; 
		cin>>posicion; 
		
	}while (posicion>tamano_l or posicion<=0); 
	cout << "ingresa nuevo caracter"; 
	cin>> nombre_est[posicion-1]; 
	cout<<"la nueva cadena es: "<< nombre_est<<endl; 
	
	can_vo=0;
	recorrer_vo=0;  
	while(vocales[recorrer_vo]!='\0')
	{
		recorrer=0; 
		while(nombre_est[recorrer]!='\0')
		{
			if(nombre_est[recorrer]==vocales[recorrer_vo])
			{
				can_vo++; 
			}
		  	recorrer++;
		}
		recorrer_vo++;
	}
	cout<<"el nombre tiene:  "<<can_vo<<"vocales"<<endl; 
	
	
	
	
	
	return 0;
	system ("pause");  
}
