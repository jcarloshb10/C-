#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "fecha.h"

using namespace std;

struct facultad
{
	long codigo;
	char nombre[201];
};

struct carrera
{
	long codigo;
	char nombre[201];
};

struct eps
{
	long codigo;
	char nombre[201];
};


struct estudiante 
{
	long codigo;
	char p_nombre[21];	
	char s_nombre[21];
	char p_apellido[21];
	char s_apellido[21];
	long identificacion;
	char sexo[21];
	double telefono;	
	tipo_fecha fecha_nacimiento;
	tipo_fecha fecha_ingreso;
	int cod_facultad;
	int cod_carrera;
	int cod_eps;
};

void menuregistro();
void menueliminar();
void menumodificar();
void menureportar();

void refacultad();
long cargar_facultad(facultad v_facultad[]);
void grabar_facultad(facultad v_facultad[], long numfacultad);
void mostrar_facultad();
void eliminar_facultad();
void modificar_facultad();

void recarrera();
long cargar_carrera(carrera v_carrera[]);
void grabar_carrera(carrera v_carrera[], long numcarrera);
void mostrar_carrera();
void eliminar_carrera();
void modificar_carrera();

void reeps();
long cargar_eps(eps v_eps[]);
void grabar_eps(eps v_eps[], long numeps);
void mostrar_eps();
void eliminar_eps();
void modificar_eps();

void reestudiante();
long cargar_estudiante(estudiante v_estudiante[]);
void grabar_estudiante(estudiante v_estudiante[], long numestudiante);
void mostrar_estudiante();
void eliminar_estudiante();
void modificar_estudiante();
int main()
{
	char opcion;
	system("cls");
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"JAIME ALEJANDRO GOMEZ - CODIGO: 217034181"<<endl
	<<"JEAN CARLOS HERNANDEZ - CODIGO: 217034199"<<endl
	<<"SEBASTIAN BASTIDAS ROSERO - CODIGO: 217034032"<<endl<<endl;
	
	cout<<"OPCIONES: "<<endl<<endl
		<<"A- Registrar informacion"<<endl
		<<"B- Eliminar registro"<<endl
		<<"C- Modificar registro"<<endl		
		<<"D- Reportes"<<endl
		<<"X- Salir"<<endl<<endl
		<<"Digite opcion: ";
	cin>>opcion;
	opcion = tolower(opcion);
	switch(opcion)
	{
    	case 'a':
    		menuregistro();
        break;
    	case 'b':
    		menueliminar();
        break;
    	case 'c':
    		menumodificar();
        break;
        case 'd':
        	menureportar();
        break;
    	case 'x':
        system("cls");
        cout<<"Gracias por utilizar nuestro programa"<<endl;
        system("pause");
        exit (0);
        break;
    	default:
        cout<<"Opcion no valida"<<endl;
        system("pause");
        main();
        break;
   	}
	return 0;
}

void menuregistro()
{
	char opcion;
	system("cls");
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"REGISTRO DE INFORMACION"<<endl<<endl;
	
	cout<<"OPCIONES: "<<endl<<endl
		<<"A- Registrar nuevo estudiante"<<endl
		<<"B- Registrar facultad"<<endl
		<<"C- Registrar carrera"<<endl		
		<<"D- Registrar eps"<<endl				
		<<"M- Volver al menu principal"<<endl
		<<"X- Salir"<<endl<<endl
		<<"Digite opcion: ";
	cin>>opcion;
	opcion = tolower(opcion);
	switch(opcion)
	{
    	case 'a':
    		reestudiante();
        break;
    	case 'b':
    		refacultad();
        break;
    	case 'c':
    		recarrera();
        break;
        case 'd':
        	reeps();
        break;        
        case 'm':
        	main();
        break;
    	case 'x':
        system("cls");
        cout<<"Gracias por utilizar nuestro programa"<<endl;
        system("pause");
        exit (0);
        break;
    	default:
        cout<<"Opcion no valida"<<endl;
        system("pause");
        menuregistro();
        break;
   	}
	system("pause");
}

void menueliminar()
{
	char opcion;
	system("cls");
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"ELIMINAR REGISTRO "<<endl<<endl;
	
	cout<<"OPCIONES: "<<endl<<endl
		<<"A- Eliminar estudiante"<<endl
		<<"B- Eliminar facultad"<<endl
		<<"C- Eliminar carrera"<<endl		
		<<"D- Eliminar eps"<<endl				
		<<"M- Volver al menu principal"<<endl
		<<"X- Salir"<<endl<<endl
		<<"Digite opcion: ";
	cin>>opcion;
	opcion = tolower(opcion);
	switch(opcion)
	{
    	case 'a':
    		eliminar_estudiante();
        break;
    	case 'b':
    		eliminar_facultad();
        break;
    	case 'c':
    		eliminar_carrera();
        break;
        case 'd':
        	eliminar_eps();
        break;        
        case 'm':
        	main();
        break;
    	case 'x':
        system("cls");
        cout<<"Gracias por utilizar nuestro programa"<<endl;
        system("pause");
        exit (0);
        break;
    	default:
        cout<<"Opcion no valida"<<endl;
        system("pause");
        menueliminar();
        break;
   	}
	system("pause");
}

void menumodificar()
{
	char opcion;
	system("cls");
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"MODIFICAR REGISTRO"<<endl<<endl;
	
	cout<<"OPCIONES: "<<endl<<endl
		<<"A- Modificar estudiante"<<endl
		<<"B- Modificar facultad"<<endl
		<<"C- Modificar carrera"<<endl		
		<<"D- Modificar eps"<<endl				
		<<"M- Volver al menu principal"<<endl
		<<"X- Salir"<<endl<<endl
		<<"Digite opcion: ";
	cin>>opcion;
	opcion = tolower(opcion);
	switch(opcion)
	{
    	case 'a':
    		modificar_estudiante();
        break;
    	case 'b':
    		modificar_facultad();
        break;
    	case 'c':
    		modificar_carrera();
        break;
        case 'd':
        	modificar_eps();
        break;        
        case 'm':
        	main();
        break;
    	case 'x':
        system("cls");
        cout<<"Gracias por utilizar nuestro programa"<<endl;
        system("pause");
        exit (0);
        break;
    	default:
        cout<<"Opcion no valida"<<endl;
        system("pause");
        menumodificar();
        break;
   	}
	system("pause");
}

void menureportar()
{
	char opcion;
	system("cls");
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"MODIFICAR REGISTRO"<<endl<<endl;
	
	cout<<"OPCIONES: "<<endl<<endl
		<<"A- Lista estudiantes"<<endl
		<<"B- Lista facultades"<<endl
		<<"C- Lista carreras"<<endl		
		<<"D- Lista eps"<<endl				
		<<"M- Volver al menu principal"<<endl
		<<"X- Salir"<<endl<<endl
		<<"Digite opcion: ";
	cin>>opcion;
	opcion = tolower(opcion);
	switch(opcion)
	{
    	case 'a':
    		system("cls");
        	mostrar_estudiante();
        	system("pause");
			main();
        break;
    	case 'b':    		
        	system("cls");
        	mostrar_facultad();
        	system("pause");
			main();
        break;
    	case 'c':
    		system("cls");
        	mostrar_carrera();
        	system("pause");
			main();
        break;
        case 'd':
        	system("cls");
        	mostrar_eps();
        	system("pause");
			main();
        break;        
        case 'm':
        	main();
        break;
    	case 'x':
        system("cls");
        cout<<"Gracias por utilizar nuestro programa"<<endl;
        system("pause");
        exit (0);
        break;
    	default:
        cout<<"Opcion no valida"<<endl;
        system("pause");
        menureportar();
        break;
   	}
	system("pause");
}

void refacultad()
{
	system("cls");
	facultad v_facultad[1000];
	long numfacultad;
	numfacultad=cargar_facultad(v_facultad);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"REGISTRAR FACULTAD"<<endl<<endl;
	cout<<"Digite codigo de la facultad ";cin>>v_facultad[numfacultad].codigo;	
	cout<<"Digite nombre de la facultad ";cin>>v_facultad[numfacultad].nombre;
	numfacultad++;
	grabar_facultad(v_facultad, numfacultad);
	menuregistro();
}

long cargar_facultad(facultad v_facultad[])
{
	long cantidad=0;	
	fstream facultad;
	facultad.open("Facultades.dat", ios::in);

	if ( !facultad.fail() )
	{
		while (!facultad.eof())
		{
			facultad.read((char *) &v_facultad[cantidad], sizeof(facultad));
			if (!facultad.eof())
			{
				cantidad++;
			}
		}
		facultad.close();
	}	
	else
	{
		facultad.open("Facultades.dat", ios::out);
		facultad.close();
	}	
	return (cantidad);
}

void grabar_facultad(facultad v_facultad[], long numfacultad)
{
	fstream facultad;
	long posicion;
	facultad.open("Facultades.dat", ios::out);	
	for (posicion=0; posicion < numfacultad; posicion++)
	{
		facultad.write( (char *) &v_facultad[posicion], sizeof(facultad));	
	}	
	facultad.close();
}

void mostrar_facultad()
{	
	facultad v_facultad[1000];
	long numfacultad,i;
	numfacultad=cargar_facultad(v_facultad);
	cout<<numfacultad;
	if(numfacultad>0)
	{
		cout<<"Codigo\tFacultad"<<endl;
		for(i=0;i<numfacultad;i++)
		{
			cout<<v_facultad[i].codigo<<"\t"<<v_facultad[i].nombre<<endl;
		}
	}
	else
	{
		cout<<"No se hay registros de facultades"<<endl;
	}
	
}

void eliminar_facultad()
{
	system("cls");
	bool existe=false;
	long posicion;
	long cod;
	facultad v_facultad[1000];
	long numfacultad,i=0;
	numfacultad=cargar_facultad(v_facultad);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"ELIMINAR FACULTAD"<<endl<<endl;
	mostrar_facultad();
	if(numfacultad>0)
	{
	
	cout<<"digite codigo de la facultad a eliminar ";	
	cin>>cod;
	while(v_facultad[i].codigo==cod or i<numfacultad)
	{
		if(v_facultad[i].codigo==cod)
		{
			existe=true;
			posicion=i;
		}
		i++;
	}
	if(existe)
	{
		for(i=posicion;i<numfacultad;i++)
		{
			v_facultad[i].codigo=v_facultad[i+1].codigo;
			strcpy(v_facultad[i].nombre,v_facultad[i+1].nombre);
		}
		numfacultad--;
		grabar_facultad(v_facultad, numfacultad);
		cout<<"el registro se ha eliminado correctamente"<<endl;
		mostrar_facultad();
		system("pause");
		menueliminar();
	}
	else
	{
		cout<<"El codigo de facultad no se encuentra en la base de datos, vuelva a intentar"<<endl;
		system("pause");
		eliminar_facultad();
	}
	}
	system("pause");
	menueliminar();
}

void modificar_facultad()
{
	system("cls");
	bool existe=false;
	long posicion;
	long cod;
	facultad v_facultad[1000];
	long numfacultad,i=0;
	numfacultad=cargar_facultad(v_facultad);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"MODIFICAR FACULTAD"<<endl<<endl;
	mostrar_facultad();
	if(numfacultad>0)
	{
	
	cout<<"digite codigo de la facultad a modificar ";	
	cin>>cod;
	while(v_facultad[i].codigo==cod or i<numfacultad)
	{
		if(v_facultad[i].codigo==cod)
		{
			existe=true;
			posicion=i;
		}
		i++;
	}
	if(existe)
	{
		cout<<"Digite nuevo nombre de facultad ";
		cin>>v_facultad[posicion].nombre;		
		grabar_facultad(v_facultad, numfacultad);
		cout<<"el registro se ha Modificado correctamente"<<endl;
		mostrar_facultad();
		system("pause");
		menueliminar();
	}
	else
	{
		cout<<"El codigo de facultad no se encuentra en la base de datos, vuelva a intentar"<<endl;
		system("pause");
		modificar_facultad();
	}
	}
	system("pause");
	menumodificar();
}

void recarrera()
{
	system("cls");
	carrera v_carrera[1000];
	long numcarrera;
	numcarrera=cargar_carrera(v_carrera);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"REGISTRAR CARRERA"<<endl<<endl;
	cout<<"Digite codigo de la carrera ";cin>>v_carrera[numcarrera].codigo;	
	cout<<"Digite nombre de la carrera ";cin>>v_carrera[numcarrera].nombre;
	numcarrera++;
	grabar_carrera(v_carrera, numcarrera);
	menuregistro();
}

long cargar_carrera(carrera v_carrera[])
{
	long cantidad=0;	
	fstream carrera;
	carrera.open("Carreras.dat", ios::in);

	if ( !carrera.fail() )
	{
		while (!carrera.eof())
		{
			carrera.read((char *) &v_carrera[cantidad], sizeof(carrera));
			if (!carrera.eof())
			{
				cantidad++;
			}
		}
		carrera.close();
	}	
	else
	{
		carrera.open("Carreras.dat", ios::out);
		carrera.close();
	}	
	return (cantidad);
}

void grabar_carrera(carrera v_carrera[], long numcarrera)
{
	fstream carrera;
	long posicion;
	carrera.open("Carreras.dat", ios::out);	
	for (posicion=0; posicion < numcarrera; posicion++)
	{
		carrera.write( (char *) &v_carrera[posicion], sizeof(carrera));	
	}	
	carrera.close();
}

void mostrar_carrera()
{	
	carrera v_carrera[1000];
	long numcarrera,i;
	numcarrera=cargar_carrera(v_carrera);
	if(numcarrera>0)
	{
		cout<<"Codigo\tCarrera"<<endl;
		for(i=0;i<numcarrera;i++)
		{
			cout<<v_carrera[i].codigo<<"\t"<<v_carrera[i].nombre<<endl;
		}
	}
	else
	{
		cout<<"No se hay registros de carreras"<<endl;
	}
	
}

void eliminar_carrera()
{
	system("cls");
	bool existe=false;
	long posicion;
	long cod;
	carrera v_carrera[1000];
	long numcarrera,i=0;
	numcarrera=cargar_carrera(v_carrera);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"ELIMINAR CARRERA"<<endl<<endl;
	mostrar_carrera();
	if(numcarrera>0)
	{
	
	cout<<"digite codigo de la carrera a eliminar ";	
	cin>>cod;
	while(v_carrera[i].codigo==cod or i<numcarrera)
	{
		if(v_carrera[i].codigo==cod)
		{
			existe=true;
			posicion=i;
		}
		i++;
	}
	if(existe)
	{
		for(i=posicion;i<numcarrera;i++)
		{
			v_carrera[i].codigo=v_carrera[i+1].codigo;
			strcpy(v_carrera[i].nombre,v_carrera[i+1].nombre);
		}
		numcarrera--;
		grabar_carrera(v_carrera, numcarrera);
		cout<<"el registro se ha eliminado correctamente"<<endl;
		mostrar_carrera();
		system("pause");
		menueliminar();
	}
	else
	{
		cout<<"El codigo de carrera no se encuentra en la base de datos, vuelva a intentar"<<endl;
		system("pause");
		eliminar_carrera();
	}
	}
	system("pause");
	menueliminar();
}

void modificar_carrera()
{
	system("cls");
	bool existe=false;
	long posicion;
	long cod;
	carrera v_carrera[1000];
	long numcarrera,i=0;
	numcarrera=cargar_carrera(v_carrera);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"MODIFICAR CARRERA"<<endl<<endl;
	mostrar_carrera();
	if(numcarrera>0)
	{
	
	cout<<"digite codigo de la carrera a modificar ";	
	cin>>cod;
	while(v_carrera[i].codigo==cod or i<numcarrera)
	{
		if(v_carrera[i].codigo==cod)
		{
			existe=true;
			posicion=i;
		}
		i++;
	}
	if(existe)
	{
		cout<<"Digite nuevo nombre de carrera ";
		cin>>v_carrera[posicion].nombre;		
		grabar_carrera(v_carrera, numcarrera);
		cout<<"el registro se ha Modificado correctamente"<<endl;
		mostrar_carrera();
		system("pause");
		menueliminar();
	}
	else
	{
		cout<<"El codigo de carrera no se encuentra en la base de datos, vuelva a intentar"<<endl;
		system("pause");
		modificar_carrera();
	}
	}
	system("pause");
	menumodificar();
}

void reeps()
{
	system("cls");
	eps v_eps[1000];
	long numeps;
	numeps=cargar_eps(v_eps);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"REGISTRAR EPS"<<endl<<endl;
	cout<<"Digite codigo de la eps ";cin>>v_eps[numeps].codigo;	
	cout<<"Digite nombre de la eps ";cin>>v_eps[numeps].nombre;
	numeps++;
	grabar_eps(v_eps, numeps);
	menuregistro();
}

long cargar_eps(eps v_eps[])
{
	long cantidad=0;	
	fstream eps;
	eps.open("Eps.dat", ios::in);

	if ( !eps.fail() )
	{
		while (!eps.eof())
		{
			eps.read((char *) &v_eps[cantidad], sizeof(eps));
			if (!eps.eof())
			{
				cantidad++;
			}
		}
		eps.close();
	}	
	else
	{
		eps.open("Eps.dat", ios::out);
		eps.close();
	}	
	return (cantidad);
}

void grabar_eps(eps v_eps[], long numeps)
{
	fstream eps;
	long posicion;
	eps.open("Eps.dat", ios::out);	
	for (posicion=0; posicion < numeps; posicion++)
	{
		eps.write( (char *) &v_eps[posicion], sizeof(eps));	
	}	
	eps.close();
}

void mostrar_eps()
{	
	eps v_eps[1000];
	long numeps,i;
	numeps=cargar_eps(v_eps);
	if(numeps>0)
	{
		cout<<"Codigo\tEps"<<endl;
		for(i=0;i<numeps;i++)
		{
			cout<<v_eps[i].codigo<<"\t"<<v_eps[i].nombre<<endl;
		}
	}
	else
	{
		cout<<"No se hay registros de Eps"<<endl;
	}
	
}

void eliminar_eps()
{
	system("cls");
	bool existe=false;
	long posicion;
	long cod;
	eps v_eps[1000];
	long numeps,i=0;
	numeps=cargar_eps(v_eps);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"ELIMINAR EPS"<<endl<<endl;
	mostrar_eps();
	if(numeps>0)
	{
	
	cout<<"digite codigo de la eps a eliminar ";	
	cin>>cod;
	while(v_eps[i].codigo==cod or i<numeps)
	{
		if(v_eps[i].codigo==cod)
		{
			existe=true;
			posicion=i;
		}
		i++;
	}
	if(existe)
	{
		for(i=posicion;i<numeps;i++)
		{
			v_eps[i].codigo=v_eps[i+1].codigo;
			strcpy(v_eps[i].nombre,v_eps[i+1].nombre);
		}
		numeps--;
		grabar_eps(v_eps, numeps);
		cout<<"el registro se ha eliminado correctamente"<<endl;
		mostrar_eps();
		system("pause");
		menueliminar();
	}
	else
	{
		cout<<"El codigo de eps no se encuentra en la base de datos, vuelva a intentar"<<endl;
		system("pause");
		eliminar_eps();
	}
	}
	system("pause");
	menueliminar();
}

void modificar_eps()
{
	system("cls");
	bool existe=false;
	long posicion;
	long cod;
	eps v_eps[1000];
	long numeps,i=0;
	numeps=cargar_eps(v_eps);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"MODIFICAR EPS"<<endl<<endl;
	mostrar_eps();
	if(numeps>0)
	{
	
	cout<<"digite codigo de la eps a modificar ";	
	cin>>cod;
	while(v_eps[i].codigo==cod or i<numeps)
	{
		if(v_eps[i].codigo==cod)
		{
			existe=true;
			posicion=i;
		}
		i++;
	}
	if(existe)
	{
		cout<<"Digite nuevo nombre de eps ";
		cin>>v_eps[posicion].nombre;		
		grabar_eps(v_eps, numeps);
		cout<<"el registro se ha Modificado correctamente"<<endl;
		mostrar_eps();
		system("pause");
		menueliminar();
	}
	else
	{
		cout<<"El codigo de eps no se encuentra en la base de datos, vuelva a intentar"<<endl;
		system("pause");
		modificar_eps();
	}
	}
	system("pause");
	menumodificar();
}

void reestudiante()
{
	system("cls");
	estudiante v_estudiante[1000];
	long numestudiante;
	numestudiante=cargar_estudiante(v_estudiante);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"REGISTRAR ESTUDIANTE"<<endl<<endl;
	if(numestudiante<1)
	{
		v_estudiante[numestudiante].codigo=100;
	}
	else
	{
		v_estudiante[numestudiante].codigo=v_estudiante[numestudiante-1].codigo+1;;
	}
	cout<<"Digite primer nombre ";cin>>v_estudiante[numestudiante].p_nombre;	
	cout<<"Digite segundo nombre ";cin>>v_estudiante[numestudiante].s_nombre;	
	cout<<"Digite primer apellido ";cin>>v_estudiante[numestudiante].p_apellido;	
	cout<<"Digite segundo apellido ";cin>>v_estudiante[numestudiante].s_apellido;	
	cout<<"Digite identificacion ";cin>>v_estudiante[numestudiante].identificacion;	
	cout<<"Digite sexo ";cin>>v_estudiante[numestudiante].sexo;	
	cout<<"Digite telefono ";cin>>v_estudiante[numestudiante].telefono;	
	solicitar_fecha("Digite fecha de nacimiento ",v_estudiante[numestudiante].fecha_nacimiento)	;
	solicitar_fecha("Digite fecha de ingreso ",v_estudiante[numestudiante].fecha_ingreso)	;
	cout<<"Digite codigo de EPS del estudiante ";cin>>v_estudiante[numestudiante].cod_eps;	
	cout<<"Digite codigo facultad ";cin>>v_estudiante[numestudiante].cod_facultad;	
	cout<<"Digite codigo de carrera ";cin>>v_estudiante[numestudiante].cod_carrera;
	
	numestudiante++;
	grabar_estudiante(v_estudiante, numestudiante);
	menuregistro();
}

long cargar_estudiante(estudiante v_estudiante[])
{
	long cantidad=0;	
	fstream estudiante;
	estudiante.open("Estudiantes.dat", ios::in);

	if ( !estudiante.fail() )
	{
		while (!estudiante.eof())
		{
			estudiante.read((char *) &v_estudiante[cantidad], sizeof(estudiante));
			if (!estudiante.eof())
			{
				cantidad++;
			}
		}
		estudiante.close();
	}	
	else
	{
		estudiante.open("Estudiantes.dat", ios::out);
		estudiante.close();
	}	
	return (cantidad);
}

void grabar_estudiante(estudiante v_estudiante[], long numestudiante)
{
	fstream estudiante;
	long posicion;
	estudiante.open("Estudiantes.dat", ios::out);	
	for (posicion=0; posicion < numestudiante; posicion++)
	{
		estudiante.write( (char *) &v_estudiante[posicion], sizeof(estudiante));	
	}	
	estudiante.close();
}

void mostrar_estudiante()
{	
	estudiante v_estudiante[1000];
	long numestudiante,i;
	numestudiante=cargar_estudiante(v_estudiante);
	carrera v_carrera[1000];
	long numcarrera;
	numcarrera=cargar_carrera(v_carrera);
	long pos=0,aux=0;
	if(numestudiante>0)
	{
		cout<<"Codigo\tNombre\tApellido\tIdentificacion\tCarrera"<<endl;
		for(i=0;i<numestudiante;i++)
		{
			cout<<v_estudiante[i].codigo<<"\t"<<v_estudiante[i].p_nombre<<"\t"<<v_estudiante[i].p_apellido
			<<"\t\t"<<v_estudiante[i].identificacion<<"\t\t";
			for(pos=0;pos<numcarrera;pos++)
			{
				if(v_carrera[pos].codigo==v_estudiante[i].cod_carrera)
				{
					aux=pos;
				}
			}
			cout<<v_carrera[aux].nombre<<endl;
			
		}
	}
	else
	{
		cout<<"No se hay registros de estudiante"<<endl;
	}
	
}

void eliminar_estudiante()
{
	system("cls");
	bool existe=false;
	long posicion;
	long cod;
	estudiante v_estudiante[1000];
	long numestudiante,i=0;
	numestudiante=cargar_estudiante(v_estudiante);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"ELIMINAR ESTUDIANTE"<<endl<<endl;
	mostrar_estudiante();
	if(numestudiante>0)
	{
	
	cout<<"digite codigo del estudiante a eliminar ";	
	cin>>cod;
	while(v_estudiante[i].codigo==cod or i<numestudiante)
	{
		if(v_estudiante[i].codigo==cod)
		{
			existe=true;
			posicion=i;
		}
		i++;
	}
	if(existe)
	{
		for(i=posicion;i<numestudiante;i++)
		{
			v_estudiante[i].codigo=v_estudiante[i+1].codigo;
			strcpy(v_estudiante[i].p_nombre,v_estudiante[i+1].p_nombre);
			strcpy(v_estudiante[i].s_nombre,v_estudiante[i+1].s_nombre);
			strcpy(v_estudiante[i].p_apellido,v_estudiante[i+1].p_apellido);
			strcpy(v_estudiante[i].s_apellido,v_estudiante[i+1].s_apellido);
			v_estudiante[i].identificacion=v_estudiante[i+1].identificacion;
			strcpy(v_estudiante[i].sexo,v_estudiante[i+1].sexo);
			v_estudiante[i].telefono=v_estudiante[i+1].telefono;
			v_estudiante[i].fecha_nacimiento.dia=v_estudiante[i+1].fecha_nacimiento.dia;
			v_estudiante[i].fecha_nacimiento.mes=v_estudiante[i+1].fecha_nacimiento.mes;
			v_estudiante[i].fecha_nacimiento.anio=v_estudiante[i+1].fecha_nacimiento.anio;
			v_estudiante[i].fecha_ingreso.dia=v_estudiante[i+1].fecha_ingreso.dia;
			v_estudiante[i].fecha_ingreso.mes=v_estudiante[i+1].fecha_ingreso.mes;
			v_estudiante[i].fecha_ingreso.anio=v_estudiante[i+1].fecha_ingreso.anio;			
			v_estudiante[i].cod_facultad=v_estudiante[i+1].cod_facultad;						
			v_estudiante[i].cod_carrera=v_estudiante[i+1].cod_carrera;			
			v_estudiante[i].cod_eps=v_estudiante[i+1].cod_eps;
		}
		numestudiante--;
		grabar_estudiante(v_estudiante, numestudiante);
		cout<<"el registro se ha eliminado correctamente"<<endl;
		mostrar_estudiante();
		system("pause");
		menueliminar();
	}
	else
	{
		cout<<"El codigo de estudiante no se encuentra en la base de datos, vuelva a intentar"<<endl;
		system("pause");
		eliminar_estudiante();
	}
	}
	system("pause");
	menueliminar();
}

void modificar_estudiante()
{
	system("cls");
	bool existe=false;
	long posicion;
	long cod;
	estudiante v_estudiante[1000];
	long numestudiante,i=0;
	numestudiante=cargar_estudiante(v_estudiante);
	cout<<"PROGRAMA PARA REGISTRO DE ESTUDIANTE"<<endl
	<<"MODIFICAR ESTUDIANTE"<<endl<<endl;
	mostrar_estudiante();
	if(numestudiante>0)
	{
	
	cout<<"digite codigo del estudiante a modificar ";	
	cin>>cod;
	while(v_estudiante[i].codigo==cod or i<numestudiante)
	{
		if(v_estudiante[i].codigo==cod)
		{
			existe=true;
			posicion=i;
		}
		i++;
	}
	if(existe)
	{
		cout<<"Digite primer nombre ";cin>>v_estudiante[posicion].p_nombre;	
		cout<<"Digite segundo nombre ";cin>>v_estudiante[posicion].s_nombre;	
		cout<<"Digite primer apellido ";cin>>v_estudiante[posicion].p_apellido;	
		cout<<"Digite segundo apellido ";cin>>v_estudiante[posicion].s_apellido;	
		cout<<"Digite identificacion ";cin>>v_estudiante[posicion].identificacion;	
		cout<<"Digite sexo ";cin>>v_estudiante[posicion].sexo;	
		cout<<"Digite telefono ";cin>>v_estudiante[posicion].telefono;	
		solicitar_fecha("Digite fecha de nacimiento ",v_estudiante[posicion].fecha_nacimiento)	;
		solicitar_fecha("Digite fecha de ingreso ",v_estudiante[posicion].fecha_ingreso)	;
		cout<<"Digite codigo de EPS del estudiante ";cin>>v_estudiante[posicion].cod_eps;	
		cout<<"Digite codigo facultad ";cin>>v_estudiante[posicion].cod_facultad;	
		cout<<"Digite codigo de carrera ";cin>>v_estudiante[posicion].cod_carrera;
			
		
			
		grabar_estudiante(v_estudiante, numestudiante);
		cout<<"el registro se ha Modificado correctamente"<<endl;
		mostrar_estudiante();
		system("pause");
		menueliminar();
	}
	else
	{
		cout<<"El codigo de estudiante no se encuentra en la base de datos, vuelva a intentar"<<endl;
		system("pause");
		modificar_estudiante();
	}
	}
	system("pause");
	menumodificar();
}
