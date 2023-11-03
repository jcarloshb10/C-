#include<iostream>
#include<ctype.h>
using namespace std;
const int MAXF=100;
const int MAXC=100;


void menuprincipal(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol);
void menuvectores();
void menumatrices(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol);
void menucrearmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol);
void matrizporteclado(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol);
void imprimirmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol);
void menuconsulmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol);
void consultaporposicionmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol);
void consultaporvalormatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol);
void modificarmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol);



int main()
{
	double amatriz[MAXF][MAXC],bmatriz[MAXF][MAXC];
	int afil,acol,bfil,bcol;
	menuprincipal(amatriz,afil,acol,bmatriz,bfil,bcol);
	return 0;
}

void menuprincipal(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol)
{
	char opcion[2];
	
	system("cls");
	cout
	<<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
	<<"A) MANEJO DE VECTORES"<<endl
	<<"B) MANEJO DE MATRICES"<<endl
	<<"C) CREDITOS"<<endl<<endl
	<<"X) SALIR"<<endl
	<<"DIGITE OPCION ";
	cin>>opcion;
	opcion[0]=tolower(opcion[0]);
	switch(opcion[0])
	{
		case 'a':
			menuvectores();
		break;
		case 'b':
			menumatrices(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'c': /* AÑADÍ LOS CREDITOS
		system("cls");
		cout
		<<" Creado Por:"<<endl
		<<" Jaime Alejandro Gomez "<<endl
		<<" Brayan Sebastian Bastidas Rosero "<<endl	
		<<" Jean Carlos Hernandez Benavides";
		system("pause");*/
			
		break;
		case 'x':
			system("cls");
			cout<<"Gracias por utilizar nuestro programa"<<endl;
			exit(0);
		break;
		default:
		cout<<"Opcion no valida"<<endl;
		system("pause");
		menuprincipal(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		
	}

}
void menuvectores()
{
	char opcion[2];
	double vector[MAXF];
	system("cls");
	cout
	<<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
	<<"MANEJO DE VECTORES"<<endl<<endl
	<<"A) CREAR"<<endl
	<<"B) MOSTRAR"<<endl
	<<"C) COSULTAR"<<endl
	<<"D) MODIFICAR"<<endl
	<<"E) ADICIONAR"<<endl
	<<"F) ELIMINAR"<<endl
	<<"G) GRABAR EN ARCHIVO"<<endl
	<<"H) ORDENAR EL VECTOR"<<endl
	<<"I) PROMEDIO, NUMERO MAYOR, NUMERO MENOR, MODA Y DESVIACION ESTANDAR"<<endl<<endl
	<<"M) VOLVER AL MENU PRINCIPAL"<<endl
	<<"X) SALIR"<<endl
	<<"DIGITE OPCION ";
	cin>>opcion;
	opcion[0]=tolower(opcion[0]);
	switch(opcion[0])
	{
		case 'a':


		break;
		case 'b':
			
		break;
		case 'c':
			
		break;
		case 'd':
			
		break;
		case 'e':
			
		break;
		case 'f':
			
		break;
		case 'g':
			
		break;
		case 'h':
			
		break;
		case 'i':
			
		break;
		case 'm':
			
		break;
		case 'x':
			system("cls");
			cout<<"Gracias por utilizar nuestro programa"<<endl;
			exit(0);
		break;
		default:
		cout<<"Opcion no valida"<<endl;
		system("pause");
		menuvectores();
		break;
		
	}

}

void menumatrices(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol)
{
	char opcion[2];
	system("cls");
	cout
	<<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
	<<"MANEJO DE MATRICES"<<endl<<endl
	<<"A) CREAR"<<endl
	<<"B) MOSTRAR"<<endl
	<<"C) COSULTAR"<<endl
	<<"D) MODIFICAR"<<endl
	<<"E) ADICIONAR"<<endl
	<<"F) ELIMINAR"<<endl
	<<"G) GRABAR EN ARCHIVO"<<endl
	<<"H) SUMA Y MULTIPLICACION"<<endl
	<<"I) DETERMINANTE"<<endl<<endl
	<<"M) VOLVER AL MENU PRINCIPAL"<<endl
	<<"X) SALIR"<<endl
	<<"DIGITE OPCION ";
	cin>>opcion;
		opcion[0]=tolower(opcion[0]);
	switch(opcion[0])
	{
		case 'a':
			menucrearmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'b':
			imprimirmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'c':
			menuconsulmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'd':
			modificarmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'e':
			
		break;
		case 'f':
			
		break;
		case 'g':
			
		break;
		case 'h':
			
		break;
		case 'i':
			
		break;
		case 'm':
			menuprincipal(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'x':
			system("cls");
			cout<<"Gracias por utilizar nuestro programa"<<endl;
			exit(0);
		break;
		default:
		cout<<"Opcion no valida"<<endl;
		system("pause");
		menumatrices(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		
	}

}
void menucrearmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol)
{
	char opcion[2];
	bool verificar=true;
//	do{
	
	system("cls");
	cout
	<<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
	<<"MANEJO DE MATRICES"<<endl
	<<"CREACION DE MATRICES"<<endl<<endl
	<<"A) CREAR POR TECLADO"<<endl
	<<"B) CREAR DESDE ARCHIVO"<<endl<<endl
	<<"V) VOLVER MENU ANTERIOR"<<endl
	<<"M) VOLVER AL MENU PRINCIPAL"<<endl
	<<"X) SALIR"<<endl
	<<"DIGITE OPCION ";
	cin>>opcion;
		opcion[0]=tolower(opcion[0]);
	switch(opcion[0])
	{
		case 'a':
			matrizporteclado(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'b':
			
		break;
		case 'v':
			menumatrices(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		
		case 'm':
			menuprincipal(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'x':
			system("cls");
			cout<<"Gracias por utilizar nuestro programa"<<endl;
			exit(0);
		break;
		default:
		cout<<"Opcion no valida"<<endl;
		system("pause");
		menucrearmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		//verificar=false;
		break;
		
	}
	
//	}while(verificar=true);
}

void matrizporteclado(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol)
{
	bool verifi=true,verico=true;
	int i,j;
	afil=0;
	acol=0;
	system("cls");
	cout
	<<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
	<<"MANEJO DE MATRICES"<<endl
	<<"CREACION DE MATRICES"<<endl<<endl
	<<"CREAR POR TECLADO"<<endl<<endl;
	cout<<"Digite numero de filas de las matriz"<<endl;
	do{
		if(verifi==false)
		{
			cout<<"Numero de fila no valido, vuelva a digitar"<<endl;
		}
		
		cin>>afil;
		verifi=false;
	}while(afil<=0);
	cout<<"Digite numero de colomnas de las matriz"<<endl;
	do{
		if(verico==false)
		{
			cout<<"Numero de columna no valido, vuelva a digitar"<<endl;
		}
		
		cin>>acol;
		verico=false;
	}while(acol<=0);
	for(i=0;i<afil;i++)
	{
		for(j=0;j<acol;j++)
		{
			cout<<"F["<<i+1<<"] C["<<j+1<<"] ";cin>>amatriz[i][j];
		}
	}
	menumatrices(amatriz,afil,acol,bmatriz,bfil,bcol);
system("pause");
}

void imprimirmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol)
{
	system("cls");
	int i,j;
	if(afil==0 or acol==0)
	{
		cout<<"No se ha ingresado ninguna matriz"<<endl;
		system("pause");
		menucrearmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
	}
	
	for(i=0;i<afil;i++)
	{
		for(j=0;j<acol;j++)
		{
			cout<<amatriz[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	system("pause");
	menumatrices(amatriz,afil,acol,bmatriz,bfil,bcol);
}

void menuconsulmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol)
{
	char opcion[2];
	bool verificar=true;
	system("cls");
	if(afil==0 or acol==0)
	{
		cout<<"No se ha ingresado ninguna matriz"<<endl;
		system("pause");
		menucrearmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
	}
	else{
	
	//do{
	
	
	cout
	<<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
	<<"MANEJO DE MATRICES"<<endl
	<<"CONSULTA DE MATRICES"<<endl<<endl
	<<"A) CONSULTA POR POSICION"<<endl
	<<"B) CONSULTA POR VALOR"<<endl<<endl
	<<"V) VOLVER MENU ANTERIOR"<<endl
	<<"M) VOLVER AL MENU PRINCIPAL"<<endl
	<<"X) SALIR"<<endl
	<<"DIGITE OPCION ";
	cin>>opcion;
		opcion[0]=tolower(opcion[0]);
	switch(opcion[0])
	{
		case 'a':
			consultaporposicionmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'b':
			consultaporvalormatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'v':
			menumatrices(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		
		case 'm':
			menuprincipal(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'x':
			system("cls");
			cout<<"Gracias por utilizar nuestro programa"<<endl;
		exit(0);
		break;
		default:
		cout<<"Opcion no valida"<<endl;
		system("pause");
	//	verificar=false;
	 	menuconsulmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		
	}
	
//	}while(verificar=true);
	}
}
void consultaporposicionmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol)
{
	char opcion[2];
	int fil=0, col=0;
	bool verifi=true, verico=true, correcto=true;
	system("cls");
	
	cout
	<<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
	<<"MANEJO DE MATRICES"<<endl
	<<"CONSULTA"<<endl<<endl
	<<"CONSULTA POR POSICION "<<endl<<endl;
	cout<<"Digite numero de la fila"<<endl;
	do{
		if(verifi==false)
		{
			cout<<"Numero de fila no valido, vuelva a digitar"<<endl;
		}
		
		cin>>fil;
		verifi=false;
	}while(fil<=0 or fil>afil);
	cout<<"Digite numero de la columna"<<endl;
	do{
		if(verico==false)
		{
			cout<<"Numero de fila no valido, vuelva a digitar"<<endl;
		}
		
		cin>>col;
		verico=false;
	}while(col<=0 or col>acol);
	cout<<"En la posicion ("<<fil<<","<<col<<") es: "<<amatriz[fil-1][col-1]<<endl<<endl;
	cout<<"¿desea realizar otra busqueda? S o N"<<endl;
//	do{
	
	cin>>opcion;
		opcion[0]=tolower(opcion[0]);
	switch(opcion[0])
	{
		case 's':
			consultaporposicionmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'n':
			menumatrices(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		default:
		cout<<"Opcion no valida, vuelva a digitar"<<endl;
	//	correcto=false;
		consultaporposicionmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
	}
//	}while(correcto=true);
	
}

void consultaporvalormatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol)
{
	double a;
	int i,j;
	char opcion[2];
	bool correcto=true;
	system("cls");
	
	cout
	<<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
	<<"MANEJO DE MATRICES"<<endl
	<<"CONSULTA"<<endl<<endl
	<<"CONSULTA POR VALOR "<<endl<<endl;
	cout<<"Digite valor a consultar"<<endl;cin>>a;
	for(i=0;i<afil;i++)
	{
		for(j=0;j<acol;j++)
		{
			if(a==amatriz[i][j])
			{
			cout<<"Valor se encuentra en la posicion ("<<i+1<<","<<j+1<<")"<<endl;	
			}
			
		}
	}
	cout<<"¿desea realizar otra busqueda? S o N"<<endl;
//	do{
	
	cin>>opcion;
		opcion[0]=tolower(opcion[0]);
	switch(opcion[0])
	{
		case 's':
			consultaporvalormatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'n':
			menumatrices(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		default:
		cout<<"Opcion no valida, vuelva a digitar"<<endl;
//		correcto=false;
		consultaporvalormatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
	}
//	}while(correcto=true);	
}

void modificarmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol,double bmatriz[MAXF][MAXC],int &bfil,int &bcol)
{
	char opcion[2];
	int fil=0, col=0;
	bool verifi=true, verico=true, correcto=true;
	system("cls");
	if(afil==0 or acol==0)
	{
		cout<<"No se ha ingresado ninguna matriz"<<endl;
		system("pause");
		menucrearmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
	}
	else{
	cout
	<<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
	<<"MANEJO DE MATRICES"<<endl
	<<"MODIFICAR "<<endl<<endl;
	cout<<"Digite numero de la fila"<<endl;
	do{
		if(verifi==false)
		{
			cout<<"Numero de fila no valido, vuelva a digitar"<<endl;
		}
		
		cin>>fil;
		verifi=false;
	}while(fil<=0 or fil>afil);
	cout<<"Digite numero de la columna"<<endl;
	do{
		if(verico==false)
		{
			cout<<"Numero de fila no valido, vuelva a digitar"<<endl;
		}
		
		cin>>col;
		verico=false;
	}while(col<=0 or col>acol);
	cout<<"En la posicion ("<<fil<<","<<col<<") es: "<<amatriz[fil-1][col-1]<<endl<<endl;
	cout<<"Digite nuevo valor "<<endl;
	cin>>amatriz[fil-1][col-1];
	cout<<"¿desea realizar otra busqueda? S o N"<<endl;
//	do{
	
	cin>>opcion;
		opcion[0]=tolower(opcion[0]);
	switch(opcion[0])
	{
		case 's':
			modificarmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		case 'n':
			menumatrices(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
		default:
		cout<<"Opcion no valida, vuelva a digitar"<<endl;
	//	correcto=false;
		modificarmatriz(amatriz,afil,acol,bmatriz,bfil,bcol);
		break;
	}
//	}while(correcto=true);
}
}
	


