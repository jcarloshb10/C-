/*
	SUBRUTINAS PARA VERIFICAR SI UNA FECHA ES VALIDA
	Desarrollado por Delio Gómez López
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib> // Para convertir de cadena a número

using namespace  std;

struct tipo_fecha
{
	int dia, mes, anio;
};

char meses[][20]={"ENERO", "FEBRERO", "MARZO", "ABRIL", 
				   "MAYO", "JUNIO", "JULIO", "AGOSTO", 
				   "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};

void subcadena(char [], int, int, char []);

void solicitar_fecha(char [], tipo_fecha &);
bool verifica_fechas(tipo_fecha);

int main()
{
	tipo_fecha fecha1, fecha2, fecha3;
	int dia, mes, anio;

	solicitar_fecha("\n Ingresa fecha-1 (dd/mm/aaaa) ", fecha1);
	cout << "*************************************" << endl;
	cout << " FECHA 1: " << fecha1.dia << " de " <<meses[fecha1.mes-1]<< " de "<< fecha1.anio << endl ;
	cout << "*************************************" << endl;

	solicitar_fecha("\n \n=============================\n Ingresa fecha-2 (dd/mm/aaaa) ",fecha2);
	cout << "*************************************" << endl;
	cout << " FECHA 2: " << fecha2.dia << " de " <<meses[fecha2.mes-1]<< " de "<< fecha2.anio << endl ;
	cout << "*************************************" << endl;
	
	solicitar_fecha("\n fecha (dd/mm/aaaa) ",fecha3);
	cout << "*************************************" << endl;
	cout << " FECHA 3: Correcta " << endl ;
	cout << "*************************************" << endl;
	
	
	cout << endl;
	system("pause");
	return 0;
}

void subcadena(char cadena[], int pos1_cadena, int pos2_cadena, char subcadena[])
{
	int posicion_cadena, posicion_subcadena;
	posicion_subcadena=0;
	for (posicion_cadena=pos1_cadena-1; posicion_cadena< pos2_cadena; posicion_cadena++)
	{
		subcadena[posicion_subcadena] = cadena[posicion_cadena];
		posicion_subcadena++;
	}
	subcadena[posicion_subcadena] = '\0';
}

void solicitar_fecha(char texto[], tipo_fecha &fecha)
{
	char fecha_c[21], dia_c[3], mes_c[3], anio_c[5];
	int posicion;
	bool fecha_bien;
	do
	{
		do
		{
			fecha_bien = true;
			cout << texto ; cin >> fecha_c;
			if (fecha_c[2] != '/' or fecha_c[5] != '/' or strlen(fecha_c)>10)
			{
				cout << endl << "ERROR en el formato de fecha " << endl;
				fecha_bien = false;
			}
			for (posicion=0; posicion<strlen(fecha_c); posicion++)
			{
				if (posicion!=2 and posicion!=5)
				{
					if (!isdigit( fecha_c[posicion] ) )
					{
						cout<< endl << "ERROR: Carcater no valido en la fecha, posicion:[" << posicion+1 << "]" << endl;	
						fecha_bien = false;
					}
				}
			}
		} while (!fecha_bien);

		subcadena(fecha_c, 1, 2, dia_c);
		fecha.dia = atoi(dia_c);

		subcadena(fecha_c, 4, 5, mes_c);
		fecha.mes = atoi(mes_c); 

		subcadena(fecha_c, 7, 10, anio_c);
		fecha.anio = atoi(anio_c);
		
		if (fecha.dia<1 or fecha.mes>31)
		{
			cout<< endl <<"ERROR: El rango del día es incorrecto (01-31)" << endl;
			fecha_bien = false;
		}
		if (fecha.mes<1 or fecha.mes>12)
		{
			cout<< endl <<"ERROR: El rango del mes es incorrecto (01-12)" << endl;
			fecha_bien = false;
		}
		
	} while (!verifica_fechas(fecha) or !fecha_bien);
}

bool verifica_fechas(tipo_fecha fecha)
{
	bool bien=true;
	switch (fecha.mes)
	{
		case 2:
			if (fecha.dia==29)
			{
				if (fecha.anio%4 != 0)
				{
					bien=false;
					cout<< endl << "No es un año bisiesto, el mes de febrero no puede tener 29 días " << endl;
				}
			}
			else
			{
				if (fecha.dia>28)
				{
					bien=false;
					cout<< endl << "El mes de febrero no puede tener más de 28 días " << endl;
				}
			}
		break;
		
		case 4:
		case 6:
		case 9:
		case 11:
			if (fecha.dia>30)
			{
				bien=false;
				cout<< endl << "El mes de " << meses[fecha.mes-1] << " No pueden tener mas de 30 dias "<< endl;
			}
		break;
		
		default:
			if (fecha.dia>31)
			{
				bien=false;
				cout<< endl << "El mes de "<< meses[fecha.mes-1] << " No pueden tener mas de 31 dias "<< endl;
			}
		break;
	}

	return (bien);	
}
