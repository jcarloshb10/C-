#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "verifica_fecha.h"

using namespace std;

struct area
{
	long codigo;
	char nombre[31];
	
};

struct libro
{
	long codigo;
	long codigo_area;
	char nombre[61];
	char autor[31];
	int n_paginas;
	double precio;
	tipo_fecha fecha_edicion;
	int cantidad;
};

void crear_areas(area [], long);
long cargar_areas(area []);
void ver_areas(area [], long);
long buscar_area(area [], long, long);
long cargar_libros(libro []);
void crear_libros(libro [], long, area [], long);
long buscar_libro(libro [], long, long);
void ver_libros(libro [], long, area [], long);

int main()
{
	char si;
	area v_areas[100];
	libro v_libros[1000];
	long can_areas, can_libros;
	
	can_areas = cargar_areas(v_areas);
	can_libros = cargar_libros(v_libros);
	
	cout << "desea crear AREAS (s/n): "; cin >> si; si = tolower(si);
	if (si=='s') 
	{
		crear_areas(v_areas, can_areas);
		can_areas = cargar_areas(v_areas);
	}
	cout << endl;
	if (can_areas>0)
	{
		cout << "desea ver AREAS (s/n): "; cin >> si; si = tolower(si);
		if (si=='s')
		{
			cout << endl;
			ver_areas(v_areas, can_areas);
			cout << "==================" << endl;
			cout << endl << can_areas << " Registros" << endl;
			cout << "==================" << endl;
		 } 
		cout << endl;
		
		cout << "desea crear LIBROS (s/n): "; cin >> si; si = tolower(si);
		if (si=='s') 
		{
			crear_libros(v_libros, can_libros, v_areas, can_areas);
			can_libros = cargar_libros(v_libros);
		}
		cout << endl;
		cout << "desea ver LIBROS (s/n): "; cin >> si; si = tolower(si);
		if (si=='s') ver_libros(v_libros, can_libros, v_areas, can_areas);
		cout << endl;
	}
	else
	{
		cout << "No se creado ningun AREA, Se debe crear areas " << endl;
	}
	system("pause");
	return 0;
}

void crear_areas(area v_a[], long c_a)
{
	fstream a_area;
	int can,n;
	long codigo, posicion;

	do
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
	a_area.close();
}

long buscar_area(area v_a[], long c_a, long codigo)
{
	long p=0, posicion=-1;
	do
	{
		if (v_a[p].codigo == codigo)
		{
			posicion = p;
			p = c_a+1;
		}
	 	else
		{
		 	p++;
		} 
		
	} while (p<=c_a);
	return (posicion);
}

long cargar_areas(area v_a[])
{
	long cantidad=0;
	
	fstream a_area;
	a_area.open("areas.dat", ios::in);

	if ( !a_area.fail() )
	{
		while (!a_area.eof())
		{
			a_area.read((char *) &v_a[cantidad], sizeof(area));
			if (!a_area.eof())
			{
				cantidad++;
			}
		}
	}
	a_area.close();
	return (cantidad);
}

void ver_areas(area v_a[], long cantidad)
{
	long posicion, pos_cadena=0, tam_cadena=0, p;
	char salida[81], auxiliar[21];
	int n=1;

	pos_cadena=0;
	salida[pos_cadena]='\0';	
	

	
	for (posicion=0; posicion<cantidad; posicion++)
	{

		if (n%4==0) 
		{
			cout << salida << endl;
			n=1;
			pos_cadena=0;
			salida[pos_cadena]='\0';	
		} 
		itoa(v_a[posicion].codigo, auxiliar, 10);
		if (n==1) strcpy(salida, auxiliar); else strcat(salida,auxiliar);
		tam_cadena=strlen(salida);
		salida[tam_cadena]='-';
		salida[tam_cadena+1]='\0';
		strcat(salida, v_a[posicion].nombre);
		pos_cadena += 25;
		if (strlen(salida)<pos_cadena)
		{
			for (p=strlen(salida); p < pos_cadena; p++)
			{
				salida[p]=' ';
			}
		}
		salida[pos_cadena]='\0';
			
		n++;
	}
	cout << salida << endl;
}

long cargar_libros(libro v_l[])
{
	long cantidad=0;
	
	fstream a_libro;
	a_libro.open("libros.dat", ios::in);

	if ( !a_libro.fail() )
	{
		while (!a_libro.eof())
		{
			a_libro.read((char *) &v_l[cantidad], sizeof(libro));
			if (!a_libro.eof())
			{
				cantidad++;
			}
		}
	}
	a_libro.close();
	return (cantidad);
}
void crear_libros(libro v_l[], long c_l, area v_a [], long c_a)
{
	fstream a_libros;
	int can,n;
	long codigo, posicion_l, posicion_a;

	do
	{
		cout << "Cuantos libros se va a adicionar 0-" << 1000-c_l << ": "; cin >> can;
	} while (can < 0 or can > 1000-c_l);
	for (n=c_l; n<c_l+can; n++)
	{
		do
		{
			cout << endl;
			cout << "Registro: " << n+1 << endl;
			cout << "Ingresa codigo del libro: "; cin >> codigo;
			posicion_l = buscar_libro(v_l, c_l, codigo);
			if (posicion_l >= 0)
			{
				cout << "***************************  Este codigo ya existe ******  " << v_l[posicion_l].nombre << endl;
			}
		}while (posicion_l >= 0);		
		
		v_l[n].codigo = codigo;		
		cin.ignore();
		cout << "Nombre libro: "; cin.getline(v_l[n].nombre, 60);
		posicion_a=-1;
		do
		{
			cout << "Codigo del area: "; cin >> v_l[n].codigo_area;
			posicion_a = buscar_area(v_a, c_a, v_l[n].codigo_area);
			if (posicion_a < 0)
			{
				cout << "***************************  Este codigo no existe ******  "  << endl;
			}
		} while (posicion_a < 0);
		cout << "                   " << v_a[posicion_a].nombre << endl;
		cin.ignore();
		cout << "Autor: "; cin.getline(v_l[n].autor, 30);
		cout << "Numero de paginas: "; cin >> v_l[n].n_paginas; 
		cout << "Precio: "; cin >> v_l[n].precio;
		solicitar_fecha("Fecha de edicion: ", v_l[n].fecha_edicion);
		cout << "Cantidad: "; cin >> v_l[n].cantidad;
		cout << endl;
	}
	c_l  += can;
	
	a_libros.open("libros.dat", ios::out);
	for (n=0; n<c_l; n++)
		a_libros.write((char *) &v_l[n], sizeof(libro));
	a_libros.close();
}
long buscar_libro(libro v_l[], long c_l, long codigo)
{
	long p=0, posicion=-1;
	do
	{
		if (v_l[p].codigo == codigo)
		{
			posicion = p;
			p = c_l+1;
		}
	 	else
		{
		 	p++;
		} 
		
	} while (p<=c_l);
	return (posicion);
}
void ver_libros(libro v_l[], long c_l, area v_a[], long c_a)
{
	long posicion, p_a;
	int n=1, lineas=2;
	
	system("cls");
	
	cout << "========= LISTADO DE LIBROS ==========" << endl;
	cout << "======================================" << endl;
	for (posicion=0; posicion<c_l; posicion++)
	{
		cout << "Registro: " << posicion+1 << endl;
		cout << "    Codigo:           " << v_l[posicion].codigo << endl;
		cout << "    Nombre:           " << v_l[posicion].nombre << endl;
		p_a = buscar_area(v_a, c_a, v_l[posicion].codigo_area);
		cout << "    Area:             " << v_l[posicion].codigo_area << "-" << v_a[p_a].nombre << endl;
		cout << "    Autor:            " << v_l[posicion].autor << endl;
		cout << "    # paginas:        " << v_l[posicion].n_paginas << endl;
		cout << "    Precio:           " << v_l[posicion].precio << endl;
		cout << "    Fecha de edicion: " << v_l[posicion].fecha_edicion.dia<<"/"<< v_l[posicion].fecha_edicion.mes<<"/" << v_l[posicion].fecha_edicion.anio <<endl;
		cout << "    Cantidad:         " << v_l[posicion].cantidad << endl;
		cout << "======================================" << endl;
		
		lineas += 10;
		if (lineas >= 40 )
		{
			system("pause");
			cout << endl;
			lineas=1;
		}
	}
	cout << endl;
}
