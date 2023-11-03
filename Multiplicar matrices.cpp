#include<iostream>
#include<conio.h>
using namespace std;
main()
{
	float matriz1[200][200],matriz2[200][200],matriz3[200][200];
	int fila,columna,numfilasma1,numcolumnasma1,numfilasma2,numcolumnasma2,valoresma1,valoresma2,numfilascolumnasma;
	cout<<"Realizado por: Jean Carlos Hernandez Benavides\n";
	cout<<"\n\t\t\t\t\tMULTIPLICACION DE DOS MATRICES\n\n";
	cout<<"\t- Digite la cantidad de filas de la matriz #1\n";
	cout<<"\t";
	cin>>numfilasma1;
	cout<<"\t- Digite la cantidad de columnas de la matriz #1\n";
	cout<<"\t";
	cin>>numcolumnasma1;
	cout<<"\t- Digite la cantidad de filas de la matriz #2\n";
	cout<<"\t";
	cin>>numfilasma2;
	cout<<"\t- Digite la cantidad de columnas de la matriz #2\n";
	cout<<"\t";
	cin>>numcolumnasma2;

	if(numcolumnasma1==numfilasma2)
		{
			cout<<"\t- Para llenar los valores de las matrices se debe reconocer esta forma de ubicacion de las casillas\n\n";
			cout<<"\t\t   Columnas\n\t\t   0    1    2   . . . Hasta n columnas\n\t\t0 |-|  |-|  |-|\n\tfilas\t1 |-|  |-|  |-|\n\t\t2 |-|  |-|  |-|\n\t\t.\n\t\t.\n\t\t.\n\t\tHasta n Filas\n\n";
			cout<<"\t- DIGITE LOS VALORES DE CADA CASILLA DE LA MATRIZ #1\n";
  			for(fila=0;fila<=numfilasma1-1;fila++)
 	 			{
  					for (columna=0;columna<=numcolumnasma1-1;columna++)
  	 					{
							cout<<"\t";
							cout<<"- La fila # "<<fila;
							cout<<" Y columna # "<<columna;
							cout<<"\t";
							cin>>valoresma1;
							matriz1[fila][columna]=valoresma1;
				 		}
				}
			cout<<"\n\t- DIGITE LOS VALORES DE CADA CASILLA DE LA MATRIZ #2\n\n";	
			for(fila=0;fila<=numfilasma2-1;fila++)
				{
			  		for(columna=0;columna<=numcolumnasma2-1;columna++)
  	 			  		{
								cout<<"\t";
								cout<<"- La fila # "<<fila;
								cout<<" Y columna #\t "<<columna;
								cout<<"\t";
								cin>>valoresma2;
								matriz2[fila][columna]=valoresma2;
			      		}
				}
			for(fila=0;fila<numfilasma1;fila++)	
				{
			  		for (columna=0;columna<numcolumnasma2;columna++)
			     		{ 
					 		matriz3[200][200]=0;
			     			for(numfilascolumnasma=0;numfilascolumnasma<numcolumnasma1;numfilascolumnasma++)	
			     				{
									matriz3[fila][columna]= matriz3[fila][columna]+matriz1[fila][numfilascolumnasma]*matriz2[numfilascolumnasma][columna];
								}
						}
				}
			cout<<"- LA MATRIZ RESULTANTE ENTRE LA MULTIPLICACION DE LA MATRIZ #1 Y LA MATRIZ #2 ES:\n";
    		for(fila=0;fila<=numfilasma1-1;fila++)	
		 		{
		 			for(columna=0;columna<=numcolumnasma2-1;columna++)
			     		{
			       			cout<<matriz3[fila][columna];
			       			cout<<"\t";
				 		}
			cout<<"\n";
		 		}
		}
   else
   		{
   			cout<<"\t- NO ES POSIBLE MULTIPLICAR LAS DOS MATRICES\n\tPORQUE EL NUMERO DE COLUMNAS DE LA MATRIZ #1 ES DIFERENTE AL NUMERO DE FILAS DE LA MATRIZ #2\n";
   		}
getch();
}

