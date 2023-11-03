#include<iostream>
using namespace std;
int main() 
{
	//Manejo de cadenas de caracteres
	char nombre_est[50],vocales[]="aeiouAEIOU";
	int tamano_f, tamano_l,recorrer,posicion,can_vo,recorrer_vo;
	
	//nombre_est="Segundo texto";// ES ERROR, solo se puede con numeros. Se necesita otra libreria.
	nombre_est[0]='S';
	nombre_est[1]='e';
	nombre_est[2]='g';
	nombre_est[3]='u';
	nombre_est[4]='n';
	nombre_est[5]='d';
	nombre_est[6]='o';
	nombre_est[7]='\0';
	nombre_est[20]='%';
	cout<<nombre_est<<endl;
	
	tamano_l=0;
	while(nombre_est[tamano_l]!='\0')
	{
		tamano_l++;
	}
	cout<<"El tamaño logico de la cadena es: "<<tamano_l<<endl;
	tamano_f=sizeof(nombre_est)-1;
	cout<<"El tamaño fisico de la cadena es: "<<tamano_f<<endl;
	cin.getline(nombre_est,sizeof(nombre_est)-1);
	// cout<<nombre_est<<endl; SI COLOCA ESTA ME REPITE EL NOMBRE QUE ESCRIBO.
	
	//PARA PEDIR EL TAMANO LOGICO DE UN NOMBRE
	tamano_l=0;													
	while(nombre_est[tamano_l]!='\0')																
	{														
		tamano_l++;												
	}														
	cout<<"El tamaño logico de la cadena es: "<<tamano_l<<endl; 
	
	//IMPRESIÒN VERTICAL
	recorrer=0;
	while(nombre_est[recorrer]!='\0')
	{
		cout<<nombre_est[recorrer]<<endl;
		recorrer++;
	}
	
	
	//RECORRIDO INVERSO
	for(recorrer=tamano_l-1; recorrer>=0; recorrer--)
	{
		cout<<nombre_est[recorrer];
	}
	cout<<endl;
	
	//CAMBIO DE UN CARACTER
	do
	{
		cout<<"Ingresa la posicion del caracter a cambiar: ";
		cin>>posicion;
	}while(posicion>tamano_l or posicion<=0);
	cout<<"Ingresa nuevo caracter: ";
	cin>>nombre_est[posicion-1];
	cout<<"La nueva cadena es: "<<nombre_est<<endl;
	
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
			recorrer_vo++;
		}
		recorrer_vo++;
	}
	cout<<"El nombre tiene: "<<can_vo<<"vocales"<<endl;
	

	
	
	
	return 0;
	system("pause");
}
