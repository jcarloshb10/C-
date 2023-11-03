#include <iostream>
#include <cstring>
using namespace std; 
int main ()
{
	char p_nombre[15], s_nombre[15], p_apellido[15], s_apellido[15]; 
	char nombre_completo[61], nombre_parcial[31];
	int posicion; 

	cout<<"ingresa primer nombre: "; 
	cin.getline(p_nombre,sizeof(p_nombre)-1); 
	cout<<"ingresa tu segundo nombre: "; 
	cin.getline(s_nombre,sizeof(s_nombre)-1); 
	cout<<"ingrese primer apellido: "; 
	cin.getline(p_apellido,sizeof(p_apellido)-1); 
	cout<<"ingrese segundo apellido: "; 
	cin.getline(s_apellido,sizeof(s_apellido)-1); 
	cout<< endl; 
	
	cout<< p_nombre << s_nombre << p_apellido <<  s_apellido << "\n\n";
	
	strcpy(nombre_completo, p_apellido); 
	strcat(nombre_completo, " "); 
	strcat(nombre_completo, s_apellido); 
	strcat(nombre_completo, " "); 
	strcat(nombre_completo, p_nombre); 
	strcat(nombre_completo, " "); 
	strcat(nombre_completo, s_nombre); 
	
	cout<< nombre_completo << "\n\n";
	
	if (strcmp(p_apellido, s_apellido)==0)
	{
		cout<<"los dos apellidos son iguales \n"; 
	}
	else
	{
		if(strcmp(p_apellido,s_apellido)>0)
		{
			cout<<"el primer apellido es mayor que el segundo \n"; 
		}
		else 
		{
			cout<<"el segundo es mayor que el primero \n"; 
		}
	}  
	cout<< endl; 
	
	strcpy(nombre_parcial, p_nombre); 
	strcat(nombre_parcial, " "); 
	posicion=strlen(nombre_parcial); 
	nombre_parcial[posicion]=s_nombre[0]; 
	nombre_parcial[posicion+1]='.'; 
	nombre_parcial[posicion+2]='\0'; 
	
	cout<< nombre_parcial<< endl;
	
	strcpy(nombre_parcial, p_apellido); 
	strcat(nombre_parcial, " "); 
	posicion=strlen(nombre_parcial); 
	nombre_parcial[posicion]=s_apellido[0]; 
	nombre_parcial[posicion+1]='.'; 
	nombre_parcial[posicion+2]='\0'; 
	
	cout<< nombre_parcial<< "\n";
	
	  
	
	return 0; 
	system("pause"); 
}
