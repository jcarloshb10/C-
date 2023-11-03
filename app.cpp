#include<iostream>
#include <stdio.h>
#include <fstream>
#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <cstdlib>  // Permite manejar los comando srand() y ran()
#include <ctime>   // Permite manejar el comando time(0)
#include <fstream>

using namespace std;
char opc;
int DIM;
const int MAX_F=100;
const int MAX_C=100;
long guar[10000];
void vector_guardado();
void consulta_posicion();
void consulta_valor();
void vector_teclado();
void mostrar_vector();
void menu_vectores();
int vector_archive();
void crear_matriz_aletoria(double [][MAX_C], long &, long & );
void reportar_matriz(double [][MAX_C], long, long, char []);
void grabar_matriz(double [][MAX_C], long, long, char [], char [] );
void matriz_guardado();
void consulta_posicion_matriz();
void consulta_valor_matriz();
void matriz_teclado();
void mostrar_matriz();
void menu_matriz();
int matriz_archive();
//struct vectores{
// long vector[1000];
// int num;

//};
int main ()
{
cout<<"CALCULADORA DE MATRICFES Y VECTORES\n\n";
cout<<"Menu de Opciones\n\n";
cout<<"Presione X para Matrices\n";
cout<<"Presione Y para vectores\n";

do
{


cin>> opc;
opc=tolower(opc);

switch(opc)// comprobacion de la opcion dijitada
{
case 'x':// en caso de que la opcion seleccionada sea para  matrices
 system("cls");
    cout<<" Manejo de Matrices";//manejo de matrices
menu_matriz();
    break;
case 'y':// en caso de que la opcion seleccionada sea para vectores
 system("cls");
    cout<<"Manejo de vectores\n";//manejo de vectores
    menu_vectores();
    break;
default :

    system("cls");
    cout<<"opcion no valida, seleccione una opcion correcta\n\n";
    main();
    break;
}

}while(opc == 'x' or opc=='y');


system("pause");
return 0;
}
void menu_vectores()
{
    char opc_ve;
    cout<<"\n\nMenu de opciones\n\n";
    cout<<"presione la letra C para crear vectores\n";
    cout<<"presione la letra M para Mostrar\n";
    cout<<"presione la letra F para Consultar\n";
    cin>>opc_ve;
    opc_ve= tolower(opc_ve);
do
{
  switch(opc_ve)//  submenu de opciones para vectores
     {
       case 'c' :
        char opc_ve_me;// variable de opciones submenu vector
        system("cls");
         cout<<"Manejo de vectores\n";
        cout<<"Presione la letra K para crear desde el teclado\n";
        cout<<"Presione la letra L para crear desde un archivo\n";
        cin>>opc_ve_me;

        do
        {
        opc_ve_me=tolower(opc_ve_me);
        switch(opc_ve_me)//segundo sub menu de opiones para actividasdes especificas
        {
    case 'k':
        //system("color 4D");
        system("cls");
      vector_teclado();
        break;
    case 'l':
         //system("color 5F");
         system("cls");
        cout<<"Vector desde archivo\n";
        vector_archive();
         char p;
        cout<<"\npresione P volver al menu principal\n";
       cin>>p;
        if(p=='p')
        {
           system("cls") ;
           main ();
        }


        break;
        default :
        system("cls");
         cout<<"Error, selccione una opcion valida\n";
        break;

        }
        }while(opc_ve_me == 'k' or opc_ve_me=='l');// fin ciclo do
        system("pause");
        break;// fin caso C

        //////////

    case 'm':
        mostrar_vector();//  sub rutina mostrar vector

        break;// fin caso mostrar
    case 'f':
        char opc_cons;// nueva variable de opciones
        cout<<"presione Q para consultar por posicion\n";
        cout<<"presione R para consultar por valor\n";
        cin>>opc_cons;
        opc_cons=tolower(opc_cons);
        do
        {
          switch(opc_cons)//switch para 3 sub menu de opciones consulatr vectores
        {
        case 'q':

        consulta_posicion();
            break;
        case 'r':

        consulta_valor();
            break;
        default :
             cout<<"Error, seleccione una opcion valida\n";

            break;
        }
        }while(opc_cons=='q' or opc_cons=='r');

        break;// fin caso consultar
    default :
        system("cls");
        cout<<"Error, selccione una opcion valida\n";
         menu_vectores();
        break;// fin caso error


     }//fin switch menu vectores

}while(opc_ve == 'c' or opc_ve == 'm' or opc_ve == 'f');//fin do while para sub menu crear mostrar consultar
system("pause");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// subrutinas vector archivo
long crear_vector_desde_archivo(double vector[],long tamano_fisico)
{
	long cantidad=0;
	fstream archivo;

	archivo.open("datos.txt",ios :: in);

	if (!archivo.fail())
	{
		while (!archivo.eof() and cantidad<tamano_fisico)
		{
			archivo>>vector[cantidad];
			if (!archivo.eof())//eof fin de archivo
			cantidad ++;



		}

	}
	else
	{

		cout<<"archivo datos.txt no existe"<< endl;
	}
	archivo.close();
	return (cantidad);

}
void reportar_vector(double v[], long cantidad)
{
	long posicion;
	if (cantidad > 0)
	{
		for (posicion=0; posicion < cantidad; posicion++)
		{
			cout << v[posicion] << " "; //para reportar verticalmente se utiliza "endl" en vez del anterior espacio.
		}
	}
	else
	{
		cout << "el vector no tiene datos ";
	}
	cout << endl;
}


int vector_archive()
{
  double vector1[ 1000];
	long tamano_logico;

	tamano_logico=crear_vector_desde_archivo(vector1, 1000);

	cout << "se leyeron " << tamano_logico << " datos " << endl;

	reportar_vector(vector1, tamano_logico);

	tamano_logico++;

	//grabar(vector1, tamano_logico);


}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrar_vector()
{

    system("cls");
    cout<<"Manejo de vectores\n\n";
    cout<<"Vector guardado en Memoria\n\n";
    //vectores();

    system("pause");
}// fin mostrar vector


void vector_teclado()
{

cout<<"Manejo de vectores\n\n";
cout<<"Vector por teclado\n";
cout<<"Digite la Longitud del vector : ";
cin>>DIM;
if(DIM != isdigit(DIM)and DIM >=0)
{
int vector[DIM];
int i=0;
    //Petición de datos al usuario
    for( i=0; i<DIM; i++)
     {
      cout<<"Introduce el numero :"<< i+1<<"  " ;
      cin>> vector[i];
      if (vector[i]!=isdigit(vector[i]) and vector[i]>=0 )
      {
          if (i == DIM-1)
          {
                  // se asigna vector por referencia
cout<<"El Vector fue creado y guardado: ";
cout<<"\nPresione P para volver al menu principal\n";
cout<<"predione v para volver al menu anterior\n";
cin>>opc;
opc=tolower(opc);
do{
    switch(opc)
    {
case 'v':
    system("cls");
    menu_vectores();
    break;
case 'p':
    system("cls");
    main();
    break;
default:
    system("cls");
    cout<<"Error, opcion no valida\n";
vector_teclado();
    break;

}  // fin switch para regresar al sub menu vectores

} while(opc!='v' or opc!='p');// para  validar y repatir opcine
          }



}else
{

    system("cls");
 cout<<"Error, debe digitar un numero, vuelva a intentarlo\n";
 vector_teclado();

      }
      }
}
else
{
    system("cls");
 cout<<"Error, debe digitar un numero, vuelva a intentarlo\n";
 vector_teclado();

      }
system("pause");
}// fin vector teclado
void vector_guardado()
{
    long vec_guar;
    cout<<" El vector guardado en memoria es : ";
   // vector_teclado(vec_guar);
   for(int v=0;v<DIM;v++)
   cout<<guar[v];
}
void consulta_posicion()
{
system("cls");
 cout<<"Manejo de vectores\n\n";
cout<<"Consulta por posicion\n";


}//fin cunsulta posicion
void consulta_valor()
{

  system("cls");
   cout<<"Manejo de vectores\n\n";
cout<<"Consulta por valor\n";


}//fin consulta valor
/////////////////////////////////////////////////////////////////////////////MATRICES//////////////////////////////////////////////////////////////////////////

void menu_matriz()
{
    char opc_ve;
    cout<<"\n\nMenu de opciones\n\n";
    cout<<"presione la letra C para crear una matriz\n";
    cout<<"presione la letra M para Mostrar\n";
    cout<<"presione la letra F para Consultar\n";
    cin>>opc_ve;
    opc_ve= tolower(opc_ve);
do
{
  switch(opc_ve)//  submenu de opciones para vectores
     {
       case 'c' :
        char opc_ve_me;// variable de opciones submenu vector
        system("cls");
         cout<<"Manejo de Matrices\n";
        cout<<"Presione la letra K para crear desde el teclado\n";
        cout<<"Presione la letra L para crear desde un archivo\n";
        cin>>opc_ve_me;

        do
        {
        opc_ve_me=tolower(opc_ve_me);
        switch(opc_ve_me)//segundo sub menu de opiones para actividasdes especificas
        {
    case 'k':
        //system("color 4D");
        system("cls");
      matriz_teclado();
        break;
    case 'l':
         //system("color 5F");
         system("cls");
        cout<<"matriz desde archivo\n";
        matriz_archive();
         char p;
        cout<<"\npresione P volver al menu principal\n";
       cin>>p;
        if(p=='p')
        {
           system("cls") ;
           main ();
        }


        break;
        default :
        system("cls");
         cout<<"Error, selccione una opcion valida\n";
        break;

        }
        }while(opc_ve_me == 'k' or opc_ve_me=='l');// fin ciclo do
        system("pause");
        break;// fin caso C

        //////////

    case 'm':
        mostrar_matriz();//  sub rutina mostrar vector

        break;// fin caso mostrar
    case 'f':
        char opc_cons;// nueva variable de opciones
        cout<<"presione Q para consultar por posicion\n";
        cout<<"presione R para consultar por valor\n";
        cin>>opc_cons;
        opc_cons=tolower(opc_cons);
        do
        {
          switch(opc_cons)//switch para 3 sub menu de opciones consulatr vectores
        {
        case 'q':

        consulta_posicion_matriz();
            break;
        case 'r':

        consulta_valor_matriz();
            break;
        default :
             cout<<"Error, seleccione una opcion valida\n";

            break;
        }
        }while(opc_cons=='q' or opc_cons=='r');

        break;// fin caso consultar
    default :
        system("cls");
        cout<<"Error, selccione una opcion valida\n";
         menu_matriz();
        break;// fin caso error


     }//fin switch menu vectores

}while(opc_ve == 'c' or opc_ve == 'm' or opc_ve == 'f');//fin do while para sub menu crear mostrar consultar
system("pause");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// subrutinas vector archivo
void crear_matriz_aletoria(double matriz[][MAX_C], long &nfilas, long &ncolumnas )
{
	long f,c;
	do
	{
		nfilas=rand()%10;
	}while (nfilas<2 or nfilas>MAX_F);
	do
	{
		ncolumnas=rand()%10;
	}while (ncolumnas<2 or ncolumnas>MAX_C);

	for (f=0; f<nfilas; f++)
		for (c=0; c<ncolumnas; c++)
			matriz[f][c]=double(rand())/5;

}

void reportar_matriz(double matriz[][MAX_C], long nfilas, long ncolumnas, char nombre[])
{
	long f,c;
	cout << endl << nombre << " : " << nfilas << " x " << ncolumnas << endl << endl;

		for (f=0; f<nfilas; f++)
		{
			for (c=0; c<ncolumnas; c++)
			{
				cout << matriz[f][c] << "\t";
			}
			cout << endl;
		}
		cout << endl;
}
void grabar_matriz(double matriz[][MAX_C], long nfilas, long ncolumnas, char nombre[], char narchivo[])
{
	long f,c;

	fstream datos(narchivo,ios::app);

	datos << endl << nombre << " : " << nfilas << " x " << ncolumnas << endl << endl;

		for (f=0; f<nfilas; f++)
		{
			for (c=0; c<ncolumnas; c++)
			{
				datos << matriz[f][c] << "\t";
			}
			datos << endl;
		}
		datos << endl;
	datos.close();
}


int matriz_archive()
{
    long filas_m1, columnas_m1, filas_m2, columnas_m2;
	double m1[MAX_F][MAX_C], m2[MAX_F][MAX_C];
	srand(time(0));
	char narchivo[30];
	cout << "Ingresa nombre de archivo con .txt ";
	cin >> narchivo;
	// MATRIZ 1
	fstream datos;
	datos.open(narchivo,ios::out);
	datos.close();
	crear_matriz_aletoria(m1, filas_m1, columnas_m1);
	cout<<"\nmatriz generada desde archivo\n";
	reportar_matriz(m1, filas_m1, columnas_m1, "MATRIZ ");
	grabar_matriz(m1, filas_m1, columnas_m1, "MATRIZ ", narchivo);
	do
    {
     cout<<"\n Presione P para regresar al menu principal\n";
	cout<<"Presione V para regresar al menu anterior\n";
	cout<<"Presione S para terminar el programa\n";
	cin>>opc;
	opc=tolower(opc);
switch(opc)
{
   case 'p':
   system("cls");
   main();
   break;
   case 'v':
    system("cls");
    menu_matriz();
    break;
   case 's':
       system("cls");

    break;
   default :
       system("cls");
       cout<<"\n Error, opcion incorrecta, digite una opcion valida\n";
       break;
}
    }while(opc=='p' or opc=='v' or opc=='s');


	return 0;


}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrar_matriz()
{

    system("cls");
    cout<<"Manejo de Matrices\n\n";
    cout<<"Matriz guardada en Memoria\n\n";
    vector_guardado();

    system("pause");
}// fin mostrar vector


void matriz_teclado()
{

    cout<<"Manejo de Matrices\n\n";
    cout<<"Matriz por teclado\n";
/////////////////////////////////////////dedsed aui
//Declaracion de las Variables
    int fila,columna;
    int matriz[100][100];

//Ingreso de la cantidad de filas y columna
    cout << "Ingrese la cantidad de Filas: " ;
    cin >> fila;

    if(fila >0 )
    {
    do
    {

    cout << "Ingrese la cantidad de Columna: " ;
cin >> columna;

if(columna >0 )
{
    //Cambio de tamaño en la matriz (esto es la parte que no termino de comprender)
matriz[1][1]=matriz[fila][columna];

//Muestra del nuevo tamaño de la matriz
cout << "\nLa nueva matriz es de " << fila << "x" << columna << "\n\n";

//Ingreso de los componentes de la matriz
for(int i=0;i<fila;i++)
{
for(int n=0;n<columna;n++)
{
cout << "Ingrese el valor de [" << i+1 << "][" << n+1 << "] : " ;
cin >> matriz[i][n];
}
}

//Muestra de la matriz ingresa
cout << "\nLa matriz guardada es \n\n";

for(int i = 0; i < fila; i++)
{
for(int n = 0; n < columna; n++)
{
cout <<" "<< matriz[i][n]<<"  " ;
}
cout << endl;
}
}else{
system("cls");
  cout<<"La matriz con columna 0 o valores negativos , No existe, digite un valor correcto \n\n";

}
  }while(columna <=0);



}else
{
  system("cls");
  cout<<"La matriz con fila 0 o valores negativos , No existe, digite un valor correcto \n\n";
  matriz_teclado();
}



system("pause<nul");
////////////////////////////////////////////

       // se asigna vector por referencia
cout<<"La matriz fue creada y guardada fue creado y guardado: ";
cout<<"\nPresione p para volver al menu principal\n";
cout<<"predione v para volver al menu anterior\n";
cin>>opc;
opc=tolower(opc);
do{
    switch(opc)
    {
case 'v':
    system("cls");
    menu_matriz();
    break;
case 'p':
    system("cls");
    main();
    break;
default:
    system("cls");
    cout<<"Error, opcion no valida\n";
matriz_teclado();
    break;

}  // fin switch para regresar al sub menu vectores

} while(opc=='v' or opc=='p');// para  validar y repatir opcines



}// fin vector teclado

void consulta_posicion_matriz()
{
system("cls");
 cout<<"Manejo de Matrices\n\n";
cout<<"Consulta por posicion\n";


}//fin cunsulta posicion
void consulta_valor_matriz()
{

  system("cls");
   cout<<"Manejo de Matrices\n\n";
cout<<"Consulta por valor\n";


}//fin consulta valor
