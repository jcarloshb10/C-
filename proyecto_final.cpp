#include <iostream>
#include <cstring>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fstream>
#include <ctype.h>
#include <math.h>
using namespace std;
////////// variable generles
int filas = 0;
int cols = 0;
char opc;
int numero_vector, vector[100], i,j,tamano_vector;
int matriz[100][100],nf,nc,fil,col;
fstream  archivo_vector;
fstream archivo_MATRIZ;
///////// prototipos
void menu1();
void menu_vectores();
void vector_teclado();
void modificarvector();
void mostrar_vector();
void adicionarvector();
void eliminarvector ();
void grabar_vector();
void ordenar_vector();
void moda_promedio_vector();
void menu_matriz();
void matriz_teclado();
void modificarmatriz();
void adicionarmatriz();
void adcol();
void adfil();
void eliminarmatriz();
void mostrar_matriz();
void matriz_grabar();
void matriz_suma();
void matriz_multiplicacion();
void consulta_valor();
void consulta_posicion();
void vector_archivo();
void matriz_det();
void consulta_posicion_matriz();
void consulta_valor_matriz();
void matriz_archive();
int main()

{

cout<<"CALCULADORA DE MATRICES Y VECTORES\n\n";
cout<<"Menu de Opciones\n\n";
cout<<"Presione X para vectores\n";
cout<<"Presione Y para matrices\n";
cout<<"precione Z para salir del sistema\n";
do
{
cin>> opc;
opc=tolower(opc);

switch(opc)// comprobacion de la opcion dijitada
{
case 'x':// en caso de que la opcion seleccionada sea para  matrices
 system("cls");
    cout<<" Manejo de vectores";//manejo de matrices
    menu_vectores();
    break;
case 'y':// en caso de que la opcion seleccionada sea para matrices
 system("cls");
    cout<<"Manejo de manejo de matrices";//manejo de matrices
    menu_matriz();
    break;
case 'z':
    exit(0);

default :

    system("cls");
    cout<<"opcion no valida, seleccione una opcion correcta\n\n";
    main();
    break;
}

}while(opc == 'x' or opc=='y' or opc=='z');

	return 0;
	system ("pause");
}

// menu de vectores-------
void menu_vectores()
{

    char opc_ve;
    char opc_vg;// variable de opciones submenu vector grabar
    cout<<"\n\nMenu de opciones\n\n";
    cout<<"presione la letra C para crear vectores\n";
    cout<<"presione la letra M para Mostrar\n";
    cout<<"presione la letra F para Consultar\n";
    cout<<"precione la letra H para modificar\n";
    cout<<"presione la letra I para adicionar \n";
    cout<<"precione la letra j para eliminar\n";
    cout<<"presione la letra K para grabar en archivo\n";
    cout<<"precione la letra L para ordenar el vector\n";
    cout<<"presione la letra N para promedio, numero mayor, numero menor,moda y deviacion estandar\n";
    cout<<"precione la letra O para volver al menu principal\n";
    cout<<"precione la letra P para salir\n";
    cin>>opc_ve;
    opc_ve= tolower(opc_ve);
do
{
  switch(opc_ve)//  submenu de opciones para vectores
     {
case 'c' :
        cout<<"Presione la letra K para crear desde el teclado\n";
        cout<<"Presione la letra L para crear desde un archivo\n";
        cin>>opc_vg;

        do
        {
        opc_ve=tolower(opc_ve);
        switch(opc_vg)//segundo sub menu de opiones para actividasdes especificas
        {
          case 'k':
        //system("color 4D");
        system("cls");
        cout<<"Vector desde el teclado\n";
        vector_teclado();
        menu_vectores();
        break;

          case 'l':
         //system("color 5F");
         system("cls");
        cout<<"Vector desde archivo \n"<<" cargado con exito\n";
        vector_archivo();
        break;

        default :
        system("cls");
         cout<<"Error, selccione una opcion valida\n";
        break;
        }

        }while(opc_ve == 'k' or opc_ve=='l');// fin ciclo do
        break;// fin caso C

        //////////

case 'm':
       system("cls");
	   mostrar_vector(); //  sub rutina mostrar vector
       menu_vectores();
        break;// fin caso mostrar
case 'f':
        char opc_vc;// nueva variable de opciones

        cout<<"presione Q para consultar por posicion\n";
        cout<<"presione R para consultar por valor\n";
        cin>>opc_vc;
        opc_vc=tolower(opc_vc);
        do
        {
          switch(opc_vc)//switch para 3 sub menu de opciones consulatr vectores
        {
        case 'q':
        	 system("cls");
        consulta_posicion();
        menu_vectores();
            break;
        case 'r':
     	system("cls");
        consulta_valor();
        menu_vectores();
        break;

        default :
             cout<<"Error, seleccione una opcion valida\n";

            break;
        }
        }while(opc_vc=='q' or opc_vc=='r');

        break;// fin caso consultar

case 'h':
         //system("color 5F");
         system("cls");
        modificarvector();
        menu_vectores();

        break;
case 'i':
         //system("color 5F");
         system("cls");
        cout<<"adicionar al vector\n";
        adicionarvector();
        menu_vectores();

        break;

case 'j':
         //system("color 5F");
         system("cls");
        cout<<"eliminar vector\n";
        eliminarvector();
        menu_vectores();
        break;

case 'k':
         //system("color 5F");
         system("cls");
        cout<<"vector grabado con exito\n";
        grabar_vector();
        menu_vectores();
        break;

case 'l':
         //system("color 5F");
         system("cls");
        cout<<"ordenar el vector\n";
        ordenar_vector();
        menu_vectores();

        break;

case 'n':
         //system("color 5F");
         system("cls");
        cout<<"calculos del vector\n";
        moda_promedio_vector();
        menu_vectores();
        break;
case 'o':
         system("cls");
         main();
         break;
case 'p':
         // salir del sistema
        system("cls");
         exit(0);
        break;

        default :
        system("cls");
        cout<<"Error, selccione una opcion valida\n";
        menu_vectores();
        break;// fin caso error


     }//fin switch menu vectores

}while(opc_ve == 'c' or opc_ve == 'm' or opc_ve == 'f' or opc_ve == 'h' or opc_ve == 'i'  or opc_ve == 'j' or opc_ve == 'k' or opc_ve == 'l' or opc_ve == 'n' or opc_ve == 'o' or opc_ve == 'p');//fin do while para sub menu crear mostrar consultar
system("pause");
}

//subrutina crear vector desde teclado
void vector_teclado()
{
	cout<<" dgite tamaño del vector: ";
	cin>> tamano_vector;

	for(i=0;i<tamano_vector;i++)
	{
		cout<<"digite numero: " <<endl;
		cin>>vector[i];
	}

}

void vector_archivo()
{
     archivo_vector.open("vector.txt",ios :: in);

	if (archivo_vector.fail())
    {
	 cout<<"el archivo no esxiste";
	 menu_vectores();
	}

	else {
	while(!archivo_vector.eof())
	{
		 for (i=0;i<100;i++)
      	 {
		archivo_vector>>vector[i];
        }
	}
         }
	archivo_vector.close();

}
// subrutina para modificar vector
void modificarvector ()
{
	system("cls");
	cout<<"modificar vector"<<endl;
	int i;

	cout << "Cual posicion desea modificar?" << endl;
	cin >> i; cout << endl << endl;
	i=i-1;
	if (i < tamano_vector)
	{
		cout << "Digite el nuevo valor: " << endl;
		cin >> vector[i];
		cout << endl << endl;

	}
	else
	{
		cout << "Esa posicion no existe" << endl << endl;
		modificarvector();
	}

}

void consulta_valor()
{
system("cls");
 cout<<"Manejo de vectores\n\n";
cout<<"Consulta por valor\n";

int i,dato;
char band= 'F';
cout<<"ingresa valor a buscar: ";
cin>>dato;

i=0;
while (band=='F'&& i<tamano_vector)
{
if(vector[i]==dato)
    {
            band='V';
    }
  i++;
}

if(band=='F')
{
	cout<<"el numero buscado no existe en el arreglo";
}
else if(band=='V')
{cout<<"el numero ha sido encontrado en la posicion: "<<i; }
}

void consulta_posicion()
{
cout<<"Manejo de vectores\n\n";
cout<<"Consulta por posicion\n";
	int pos;
	cout<<"digite posicion a buscar: ";
	cin>>pos;
	if(pos>tamano_vector or pos<1)
	cout<<"la posicion no existe en el vector";
	else {
		for(i=1;i<=tamano_vector;i++)
		{
			if(i==pos)
			cout<<" el numero que esta en la posicion buscada es: "<<vector[i-1];
		}

	}
}
void mostrar_vector()
{
	cout<<"el vector es: ";
	for (i=0;i<tamano_vector;i++)
	{
		cout<<vector[i];
	}


}
// subrutina adiciona al vector
void adicionarvector ()
{
	system("cls");

	int pos,i,valor;

	cout << "Que elemento desea añadir" << endl;
	cin >> valor;
	cout<<" en que posicion lo desea añadir";
	cin>> pos;
	pos=pos-1;
	for( i= tamano_vector; i>pos; i--)
	{
			 vector[i] = vector[i-1] ;

	}
	vector[pos]= valor;
	tamano_vector=tamano_vector+1;

}
// subrutina eliminar vector
void eliminarvector ()
{
	system("cls");
	int pos, j,eliminado;

	cout << "Cual posicion desea eliminar?" << endl;
	cin >> pos;
	cout << endl << endl;
    pos=pos-1;
	if (pos>tamano_vector)
	 {
	cout << "Esa posicion no existe";


	}
	else
	{

		for(j=0; j<tamano_vector; j++)
		{
		   if(j==pos)
			{
	        vector[j] =vector[j+1];
		    }
		}
     tamano_vector=tamano_vector-1;
	}

}
// subrutina grabar vector
void grabar_vector()
{
	archivo_vector.open("vector.txt", ios::out);

	 archivo_vector<<"vector"<<endl;
	 for (i=0;i<tamano_vector;i++)
	 {
		archivo_vector<< vector[i] <<endl;
    }



	archivo_vector.close();//cierra archivo

}
//subrutina ordenar vector
void ordenar_vector()
{
	int i,j,aux;

    for(i=0;i<tamano_vector;i++)
    {
       for(j=0;j<tamano_vector;j++)
         {
            if(vector[j]>vector[j+1])
              {
                   	aux=vector[j];
     				vector[j]=vector[j+1];
    				vector[j+1]=aux;
    	      	}
		}
	}

	cout<<"Orden Asendente:"<<endl;
	for (i=1;i<=tamano_vector;i++)
	cout<<vector[i];
	cout<<endl;


	cout<<"Orden Descendente:"<<endl;
	for (i=tamano_vector;i>=1;i--)
	cout<<vector[i];
}

// subrutina calculos del vector
void moda_promedio_vector()
{
    int i,j,n,mayor,menor,moda=0,repite=0;
    float promedio, desviacion_estandar=0,varianza=0,acum=0;
for (i=0;i<tamano_vector;i++)
{
	n=vector[i];
    acum=acum+n;

    if(i==0)
    {
    	mayor=vector[i];
	    menor=vector[i];
	}
	else
	{
	if(vector[i]>mayor) mayor=vector[i];

	 if(vector[i]<menor) menor=vector[i];
	}

repite=0;
     for(j=0;j<tamano_vector;j++)
     {
       if(vector[i]==vector[j])
        repite++;

      if (repite>=2)
      moda=vector[i];
     }
}
promedio=acum/tamano_vector;

  for (i=0;i<tamano_vector;i++)
{
varianza=varianza+(vector[i]-promedio)*(vector[i]-promedio);
}


  desviacion_estandar=sqrt(varianza/(tamano_vector-1));

cout<<"el promedio es: "<<promedio<<endl;
cout<<"el numero mayor es: "<<mayor<<endl;
cout<<"el numero menor es: "<<menor<<endl;
cout<<"la moda es: "<<moda<<endl;
cout<<"la desviacion estandar es: "<<desviacion_estandar;
}
// subrutina para menu matriz
void menu_matriz()
{
    char opc_ve;
    cout<<"\n\nMenu de opciones\n\n";
    cout<<"presione la letra C para crear una matriz\n";
    cout<<"presione la letra M para Mostrar\n";
    cout<<"presione la letra F para Consultar\n";
    cout<<"presione la letra G para modificar\n";
    cout<<"presione la letra H para adicionar\n";
    cout<<"presione la letra I para eliminar\n";
    cout<<"presione la letra J para  grabar en archivo\n";
    cout<<"presione la letra K para suma\n";
    cout<<"presione la letra l para multiplicacion\n";
    cout<<"presione la letra N para determinante de orden 4\n";
    cout<<"presione la letra O para volver a menu principal\n";
    cout<<"presione la letra P para salir del sistema\n";
    cin>>opc_ve;
    opc_ve= tolower(opc_ve);
do
{
  switch(opc_ve)//  submenu de opciones para vectores
     {
case 'c' :
        char opc_ve_me;// variable de opciones submenu matrices
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
      	system("cls");
	    mostrar_matriz();   //  sub rutina mostrar matriz
	    menu_matriz();
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
       menu_matriz();
            break;
        case 'r':
        consulta_valor_matriz();
        menu_matriz();
            break;
        default :
             cout<<"Error, seleccione una opcion valida\n";

            break;
        }
        }while(opc_cons=='q' or opc_cons=='r');

        break;// fin caso consultar
case 'g':
        //system("color 4D");
      system("cls");
      cout<<"modificar una matriz\n";
      modificarmatriz();
      menu_matriz();
       break;
case 'h':
    //system("color 4D");
      system("cls");
      cout<<"adicionar a una matriz\n";
       adicionarmatriz();
      menu_matriz();
       break;
case 'i':
        //system("color 4D");
      system("cls");
      cout<<"eliminar una matriz";
      eliminarmatriz();
      menu_matriz();
       break;
case 'j':
        //system("color 4D");
      system("cls");
      cout<<"matiz grabada con exito";
      matriz_grabar();
      menu_matriz();
       break;
case 'k':
      //system("color 4D");
      system("cls");
       matriz_suma();
       menu_matriz();
       break;
case 'l':
        //system("color 4D");
      system("cls");
       matriz_multiplicacion();
      menu_matriz();
       break;
case 'n':
        //system("color 4D");
      system("cls");
      cout<<"determinante de una matriz de orden 4: \n\n ";
      matriz_det();
      menu_matriz();
       break;
case 'o':
        //system("color 4D");
      system("cls");
      main();
       break;
case 'p':
        //system("color 4D");
      system("cls");
     exit(0);
       break;


    default :
        system("cls");
        cout<<"Error, selccione una opcion valida\n";
         menu_matriz();
        break;// fin caso error


     }//fin switch menu vectores

}while(opc_ve == 'c' or opc_ve == 'm' or opc_ve == 'f' or opc_ve == 'g' or  opc_ve == 'h' or opc_ve == 'i' or opc_ve == 'j' or opc_ve == 'k' or opc_ve == 'l' or opc_ve == 'n' or opc_ve == 'o' or opc_ve == 'p');//fin do while para sub menu crear mostrar consultar
system("pause");
}

void matriz_teclado()
{
 int n;

cout<<"Manejo de Matrices\n\n";
cout<<"Matriz por teclado\n";


  cout<<"digite numero de filas que desea para la matriz: ";cin>>nf;
  cout<<"digite numero de columnas que desea para la matriz: ";cin>>nc;

        cout<<"\nllene la matriz\n";
  		for(fil=0;fil<=nf-1;fil++)
 	 		{
  			for (col=0;col<=nc-1;col++)
  	 			 {
  	 			    cout<<"digite numero en fila "<< fil+1;
					cout<<" y  columna " <<col+1<<":";
  	 			    cin>>n;
					 matriz[fil][col]=n;
				 }
			}

}

void mostrar_matriz()
{
	cout<<"la matriz es: \n";
		for(fil=0;fil<nf;fil++)
		 {
		 	for (col=0;col<nc;col++)
			     {
			       cout<<matriz[fil][col];
			       cout<<"\t";
				 }
				   cout<<"\n\n";
		 }

 }


void modificarmatriz()
{
	int i,j, n;


	cout << "Digite la posicion de la fila a modificar : ";
	cin >> i;

	cout << "Digite la posicion de la columna a modificar : ";
	cin >> j;
	if (i<=nf and j<=nc)
	{

	cout << "Digite nuevo elemento: ";
	cin >> n;

	matriz[i-1][j-1] =n;
    }
 else
 {
 	cout<<"la posicion no existe";
 	menu_matriz();

 }

}

void adicionarmatriz()
{
	system("cls");
	char opc;

	cout << "Menu" << endl;
	cout << "f) Para adicionar al final de una fila." << endl;
	cout << "c) Para adicionar al final de una columna." << endl;
	cin >> opc;

	opc = tolower(opc);

	switch(opc)
	{
		case 'f' :
			adfil();
		break;

		case 'c' :
			adcol();
		break;

		default :
			cout << "Digite una opcion valida";

			adicionarmatriz();
		break;
	}


}

void adfil()
{
	system("cls");

	int fil,i,j;
	char ne;

	cout << "Digite el numero de la fila." << endl;
	cin >> fil;

	cout << "Digite nuevo elemento";
	cin >> ne;

	for(i=fil; i<nf; i++)
	{
		for(j=0; j<nc;j++)
		{
			if (matriz[i][j] == '\0')
			{
				matriz[i][j] = ne;
			}
		}
	}

}

void adcol()
{
	system("cls");

	int col,j;
	char ne;

	cout << "Digite el numero de la columna." << endl;
	cin >> col;

	cout << "Digite nuevo elemento";
	cin >> ne;

	for(j=col; j<nf; j++)
	{
		for(i=0; i<nc;i++)
		{
			if (matriz[i][j] == '\0')
			{
				matriz[i][j] = ne;
			}
		}
	}
}

void eliminarmatriz()
{
	system("cls");

	int i,j;
	char ne;

	cout << "Digite la posicion de la fila a eliminar : ";
	cin >> i;

	cout << "Digite la posicion de la columna a eliminar : ";
	cin >> j;

	cout << "Digite nuevo elemento";
	cin >> ne;

	matriz[i][j] = ne;
}

void matriz_grabar()
{

	archivo_MATRIZ.open("MATRIZ.txt", ios::out);

	 archivo_MATRIZ<<"MATRIZ"<<endl;


	for(fil=0;fil<=nf-1;fil++)
 	{
  			for (col=0;col<=nc-1;col++)
  	    {

		  archivo_MATRIZ<< matriz[fil][col]<<"\t" ;

	    }
     archivo_MATRIZ<<endl;
    }

	archivo_MATRIZ.close();//cierra archivo

}

void matriz_suma()
{
  float ma2[100][100],ma3[100][100];
  int n,fil,col,nc1,nf1,nc2,nf2,nufil,nucol,nucol2,i,cont=0,c,k,filcol,swich=0;
  cout<<"\t\t\t\t\SUMA DE MATRISES\n\n";
  cout<<"NOTA:PARA ESTA OPCION DEBE HABER INGRESADO YA UNA MATRIZ \n\n";

  cout<<"\ndigite numero de filas que desea para la segunda matriz: ";cin>>nf2;
  cout<<"digite numero de columnas que desea para la segunda matriz: ";cin>>nc2;

       if(nf==nf2 and nc2==nc)
	   {

		cout<<"\nllene la segunda matriz \n";
		for(fil=0;fil<=nf2-1;fil++)
			{
			  for (col=0;col<=nc2-1;col++)
  	 			  {
  	 			    cout<<"digite numero en fila "<< fil;
					cout<<" y  columna " <<col<<" ";
  	 			    cin>>nucol2;
					ma2[fil][col]=nucol2;
				  }
            }

     	for(fil=0;fil<nf;fil++)
			{
			  for (col=0;col<nc2;col++)
			     { ma3[100][100]=0;
			     	for(filcol=0;filcol<nc;filcol++)
			     	{
			     	ma3[fil][col]= matriz[fil][col]+ma2[fil][col];
					}

				 }

		   	}
  		cout<<"\nla suma de esta matriz \n";
		for(fil=0;fil<=nf-1;fil++)
		 {
		 	for (col=0;col<=nc-1;col++)
			     {
			       cout<<matriz[fil][col];
			       cout<<"\t";
				 }
				   cout<<"\n\n";
		 }
		 cout<<"mas esta matiz\n";
    	for(fil=0;fil<=nf2-1;fil++)
		 {
		 	for (col=0;col<=nc2-1;col++)
			     {
			       cout<<ma2[fil][col];
			       cout<<"\t";
				 }
				   cout<<"\n\n";
		 }
		 cout<<"es igual a esta matriz\n";
    	for(fil=0;fil<=nf-1;fil++)
		 {
		 	for (col=0;col<=nc2-1;col++)
			     {
			       cout<<ma3[fil][col];
			       cout<<"\t";
				 }
				   cout<<"\n";
		 }

		for(fil=0;fil<=nf-1;fil++)
		 {
		 for (col=0;col<=nc2-1;col++)
			     {
			       matriz[fil][col]=ma3[fil][col];

				 }

		 }
}




else{
	cout<<"\nlas matrices no se pueden sumar";
	}
}

void matriz_multiplicacion()
{
  float ma2[100][100],ma3[100][100];
  int n,fil,col,nc1,nf1,nc2,nf2,nufil,nucol,nucol2,i,cont=0,c,k,filcol,swich=0;
  cout<<"\t\t\t\t\tMULTIPLICACION DE MATRISES\n\n";
  cout<<"NOTA:PARA ESTA OPCION DEBE HABER INGRESADO YA UNA MATRIZ \n\n";

  cout<<"ingrese otra matriz para multiplicar: \n";
  cout<<"\ndigite numero de filas que desea para la segunda matriz: ";cin>>nf2;
  cout<<"digite numero de columnas que desea para la segunda matriz: ";cin>>nc2;


  if(nc==nf2)
	{


		cout<<"\nllene la segunda matriz \n";
		for(fil=0;fil<=nf2-1;fil++)
			{
			  for (col=0;col<=nc2-1;col++)
  	 			  {
  	 			    cout<<"digite numero en fila "<< fil;
					cout<<" y  columna " <<col<<" ";
  	 			    cin>>nucol2;
					ma2[fil][col]=nucol2;
			      }
			}
		for(fil=0;fil<nf;fil++)
			{
			  for (col=0;col<nc2;col++)
			     { ma3[100][100]=0;
			     	for(filcol=0;filcol<nc;filcol++)
			     	{



					  ma3[fil][col]= ma3[fil][col]+matriz[fil][filcol]*ma2[filcol][col];



				    }

				 }

		   	}

		cout<<"\nla multiplicacion de esta matriz \n";
		for(fil=0;fil<nf;fil++)
		 {
		 	for (col=0;col<nc;col++)
			     {
			       cout<<matriz[fil][col];
			       cout<<"\t";
				 }
				   cout<<"\n\n";
		 }
		 cout<<"por esta matiz\n";
    	for(fil=0;fil<=nf2-1;fil++)
		 {
		 	for (col=0;col<=nc2-1;col++)
			     {
			       cout<<ma2[fil][col];
			       cout<<"\t";
				 }
				   cout<<"\n\n";
		 }
		 cout<<"es igual a esta matriz\n";
    	for(fil=0;fil<=nf-1;fil++)
		 {
		 	for (col=0;col<=nc2-1;col++)
			     {
			       cout<<ma3[fil][col];
			       cout<<"\t";
				 }
				   cout<<"\n";
		 }
	for(fil=0;fil<=nf-1;fil++)
		 {
		 for (col=0;col<=nc2-1;col++)
			     {
			       matriz[fil][col]=ma3[fil][col];

				 }

		 }


   }
   else
   {
   	cout<<"esta matriz no se puede multiplicar \n";
   }
}


void matriz_det()
{
    int i,j,k,l,m,o=1,signo=1;
    double aux[20],a,b,c,det=1;

    if(nc==nf and nc==4)
    {
    for(i=0; i<nf; i++)
    {
        if(matriz[i][i]!=0)
        {
            o=1;
            a=matriz[i][i];
            b=1/a;

            for(j=0; j<nc; j++)
            {
                matriz[i][j]=b*matriz[i][j];
            }
            for(k=i+1; k<nf; k++)
            {
                c=matriz[k][i];
                for(l=0; l<nf; l++)
                {
                    matriz[k][l]=matriz[k][l]-(c*matriz[i][l]);
                }
            }
            det=det*a;
        }
        else
        {
            if(i+o<nc)
            {
                for(m=0; m<nc; m++)
                {
                    aux[m]=matriz[i][m];
                    matriz[i][m]=matriz[i+o][m];
                    matriz[i+o][m]=aux[m];
                }
                i--;
                o++;
                signo=signo*(-1);
            }
            else
            {
                det=0;
                signo=1;
                i=nc;
            }
        }
    }
    det=signo*det*matriz[nc-1][nc-1];
    cout<< "el determinante de la matriz es: "<< det;
}
else
cout<<"solo se puede calcular determinante de matriz de  orden 4";
}

void consulta_posicion_matriz()
{
system("cls");
 cout<<"Manejo de Matrices\n\n";
cout<<"Consulta por posicion\n";

	cout<<"digite posicion a buscar: \n";
	cout<<"fila: ";cin>>fil;
	cout<<"\ncolumna: ";cin>>col;


	if(fil>nf or col>nc or fil<1 or col<1)
	cout<<"la posicion no existe en la matriz";
	else {
		for(i=1;i<=nf;i++)
		{
			for(j=1;j<=nc;j++)
			{
			if(i==fil and j==col)
			cout<<" el numero que esta en la posicion buscada es: "<<matriz[i-1][j-1];
			}

		}

	}

}

void consulta_valor_matriz()
{

   system("cls");
   cout<<"Manejo de Matrices\n\n";
   cout<<"Consulta por valor\n";

int i,dato,j;
char band= 'F';
cout<<"ingresa valor a buscar: ";
cin>>dato;

i=0;
j=0;
while (band=='F'&& i<nf && j<nc)
{
if(matriz[i][j]==dato)
    {
    band='V';
    }
  j++;
  i++;
}

if(band=='F')
{
	cout<<"el numero buscado no existe en el arreglo";
}
else if(band=='V')
{cout<<"el numero ha sido encontrado en la posicion: "<<"fila: "<<i <<" y "<<"columna: "<<j; }

}
int** llenarMatriz(int f, int c) {
	filas = f;
	cols = c;
	int **matriz = new int*[f];
	for (int i = 0; i < f; i++) {
		matriz[i] = new int[c];
		for (int j = 0; j < c; j++) {
			matriz[i][j] = rand() % 100;
		}
	}
	return matriz;
}

void imprimeMatriz(int **matriz) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < cols; j++) {
			cout<<"\t"<< matriz[i][j];
		}
		cout<<"\n";
	}
}


void guardarMatriz(char *fileName, int **matriz) {
	FILE *fp = fopen(fileName, "w");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}
	char linea[80];
	sprintf(linea, "%d %d\n", filas, cols);
	fputs(linea, fp);
	for (int i = 0; i < filas; i++) {
		linea[0] = '\0';
		for (int j = 0; j < cols; j++) {
			char buffer[10];
			sprintf(buffer, "%d ", matriz[i][j]);
			strcat(linea, buffer);
		}
		int len = strlen(linea);
		linea[len - 1] = '\n';
		fputs(linea, fp);
	}
	fclose(fp);

}

int** leerMatriz(char *fileName) {
	FILE *fp = fopen(fileName, "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}
	char linea[80];
	fgets(linea, 79, fp);
	char *token = strtok(linea, " ");//10 6
	filas = atoi(token);
	token = strtok(NULL, " ");
	cols = atoi(token);
	int **matriz = new int*[filas];
	for (int i = 0; i < filas; i++) {
		matriz[i] = new int[cols];
		fgets(linea,79, fp);
		token = strtok(linea, " ");
		matriz[i][0] = atoi(token);
		for (int j = 1; j < cols; j++) {
			token = strtok(NULL, " ");
			matriz[i][j] = atoi(token);
		}
	}
	fclose(fp);
	return matriz;
}
void matriz_archive()
{

   int **M = llenarMatriz(10, 5);
	guardarMatriz("matriz.txt", M);
	int **M2 = leerMatriz("matriz.txt");
	imprimeMatriz(M2);
	cout<<endl;
	cout<<"presione V para volver al menu anterior\n";
	cout<<"Presione P para regresar al menu principal\n";
	cout<<"Presione S para salir del programa\n";
	cin>>opc;
	opc=tolower(opc);
	switch(opc)
	{
  case  'v':
    system("cls");
    menu_matriz();
    break;
  case 'p':
    system("cls");
    main();
    break;
    case 's':
    system("exit");
    break;
    default:
        cout<<"Error opcion  no valida, selccione una opcion correcta\n";
        break;
	}

	menu_vectores();



}

