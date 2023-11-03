#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cctype>
#include "verifica_fecha.h"
using namespace std;
void grabarvector(char user[100000]);
struct fecha
{
	int dd;
	int mm;
	int aaaa;
};
 
struct hora
{
	int hh;
	int mm;
};

struct user
{
	char ide;
	char nombres[100];
	char apellidos[100];
	int edad;
	int peso;
	char sexo;
	char tel;
	char direccion;
	char grupo_sanguineo[2];
	int estrato;	
};

struct tratamiento
{
	char nom_medicamento[50];
	char descr_medicamento[50];
	char posologia[100];
};

struct examen
{
	char nom_examen[50];
	char desc_examen[100];
	char resultado[100];
};

struct historia
{
	fecha fechacita;
	hora horacita;
	char nombre_medico[100];
	char sintomas[1000];
	char diagnostico[1000];
	tratamiento tratamiento[3];
	examen examen[3];
};
char user[100000];
void regis_usuario(char user[100000]);

int main()
{
	char user[100000];
	//usuario user[10000];
	//system("cls");
	regis_usuario(user);
	grabarvector(user);
}





void regis_usuario(char user[100000])
{
//	fstream usuario;
	char ide[1000];
	char nombres[1000];
	char apellidos[100];
	int edad;
	int peso;
	char sexo;
	int tel;
	char direccion[200];
	char grupo_sanguineo[30];
	int estrato;
	cout << endl<< "Registro paciente "<< endl;
	cout << "Nombres paciente: "; 
	cin.getline(nombres,sizeof(nombres)-1);
	cout << "Apellidos paciente: "; 
	cin.getline(apellidos,sizeof(apellidos)-1);
	cout << "Ingresa codigo de identificacion: "; 
	cin.getline(ide,sizeof(ide)-1);
	cout<<"Edad: ";
	cin>>edad;
	cout<<"Peso: ";
	cin>>peso;
	cout<<"Telefono: ";
	cin>>tel;

//	cout<<"Direcciòn: ";
//	cin.getline(direccion,sizeof(direccion)-1);

	/*do
	{
		cout << "Cuantas areas se va a adicionar 0-" << 100-c_a << ": "; cin >> can;
	} while (can < 0 or can > 100-c_a);
	for (n=c_a; n<c_a+can; n++)
	{
		do
		{
			cout << endl;
			cout << "Registro: " << n+1 << endl;
			cout << "Ingresa codigo del area: "; cin >> codigo;
			posicion = buscar_area(v_a, c_a, codigo);
			if (posicion >= 0)
			{
				cout << "***************************  Este codigo ya existe ******  " << v_a[posicion].nombre << endl;
			}
		}while (posicion >= 0);		
		
		v_a[n].codigo = codigo;		
		cin.ignore();
		cout << "Nombre area: "; cin.getline(v_a[n].nombre, 30);
		cout << endl;
	}
	c_a  += can;
	
	a_area.open("areas.dat", ios::out);
	for (n=0; n<c_a; n++)
		a_area.write((char *) &v_a[n], sizeof(area));
	a_area.close();*/
}
void grabarvector(char nombres[1000])
{
	char v[10000];
    fstream vector;
    int i;
   // system("cls");
    
	cout<<"GRABAR EN VECTOR"<<endl<<endl;
        vector.open("vector_original.txt",ios::out);
        vector<<nombres;
        vector<<endl;
        for(i=0; i<strlen(nombres); i++)
        {
            vector<<v[i];
            vector<<" ";
        }
        cout<<"El vector se ha guardado exitosamente"<<endl;
        vector.close();
}
