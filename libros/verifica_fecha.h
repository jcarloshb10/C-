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

void subcadena(char [], int , int , char []);
void solicitar_fecha(char [], tipo_fecha &);
bool verifica_fechas(tipo_fecha );
tipo_fecha diferencia_fechas(tipo_fecha , tipo_fecha );
int compara_fechas(tipo_fecha, tipo_fecha);
void reportar_fecha(tipo_fecha);

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


tipo_fecha diferencia_fechas(tipo_fecha fecha1, tipo_fecha fecha2)
{
	
	tipo_fecha fecha_retorno;
	long total_fecha1, total_fecha2, total_auxiliar_fecha, diferencia_fechas;
	
	total_fecha1 = (fecha1.anio*365.25)+(fecha1.mes*30.33)+(fecha1.dia);
	total_fecha2 = (fecha2.anio*365.25)+(fecha2.mes*30.33)+(fecha2.dia);
	
	if (total_fecha1>total_fecha2)
	{
		total_auxiliar_fecha = total_fecha1;
		total_fecha1 = total_fecha2;
		total_fecha2 = total_auxiliar_fecha;
	}
	
	diferencia_fechas = total_fecha2 - total_fecha1;
	
	fecha_retorno.anio = diferencia_fechas / 365.25;
	fecha_retorno.mes = (diferencia_fechas-(fecha_retorno.anio*365.25))/30.33;
	fecha_retorno.dia = ((diferencia_fechas-(fecha_retorno.anio*365.25))- (fecha_retorno.mes*30.33));
	
	return(fecha_retorno);
	
}

int compara_fechas(tipo_fecha fecha1, tipo_fecha fecha2)
{
	long dias_fecha1, dias_fecha2;
	dias_fecha1=fecha1.dia + (fecha1.mes*30.41)+(fecha1.anio*365.25);
	dias_fecha2=fecha2.dia + (fecha2.mes*30.41)+(fecha2.anio*365.25);
	
	if (dias_fecha1 > dias_fecha2)	return(1);
	if (dias_fecha1 < dias_fecha2)	return(-1);
	if (dias_fecha1 == dias_fecha2)	return(0);
}

void reportar_fecha(tipo_fecha fecha)
{
	char c_fecha[20], c_aux[3];
	if (fecha.dia<10)
	{
		c_fecha[0] = '0';
		c_fecha[1] = fecha.dia + 48;
	}
	else
		
	cout <<" "<< fecha.dia << "/" << fecha.mes << "/" << fecha.anio << " ";
}
