#include "iostream"
#include "math.h"
#include <stdlib.h>
#include <time.h>
#include "locale.h"
#include <fstream>

//#define pi 3.1416
using namespace std;

fstream LeerArchivo;
int max(int num);
int randd(int num);
double raizc(double num1);
void Saldo(double euros);
struct complex
	{
		double real, imag;
	};
	
struct cuadrado{
	double lado;
};

struct triangulo{
	double base, altura;
};

double acuadrado(cuadrado p);	
double atriangulo(triangulo p);

int main()
{
	/*#define pi 3.1416
	system("color 70");
	setlocale(LC_ALL, ""); //establecer, cambiar o consultar, en parte o en su totalidad, la información de configuración regional del programa actual especificada por locale y category
	int rad; 
	cout<<"Área circulo:";
	cin>>rad;
	system("cls");
	cout<<"El área del círculo es: "<<pi * pow(rad, 2); //pow =  exponencial
	*/
	
	///////////////////////////////////
	
	/*float ra;
	cout <<"Digite el radio: \n";
	cin >> ra;
	cout << "\t" << &ra;	Imprime la direccion de memoria y el \t es imprimir tabulación
	*/
	
	//////////////////////////////////
	
	/*char sex;
	char* pchar;
	pchar = &sex;
	cout<<"Digite género: \n";
	cin >> sex;
	cout <<"\n Contenido: "<< sex;
	cout <<"\n Dirección: "<< &pchar;*/
	
	/////////////////////////////////////
	
	/*float ang, anr, fusen, fucon, futan;
	cout<<"Digite angulo: \n";
	cin>>ang;
	anr = ang * 3.1416 / 180;
	fusen = sin(anr);
	fusen = cos(anr);
	fusen = tan(anr);
	cout<<fusen<<"\t"<<fucon<<"\t"<<futan;*/
	
	//////////////////////////////////////
	
	/*for (int i=0;i<=4;i++){
		cout<<"Num: "<<i;
		cout<<"\n";		
	}
	*/
	
	////////////////////////////////////////
	
	/*int opción;
	cout<<"Ingrese opt:\n";
	cin>>opción;
	switch(opción) //donde opción es la variable a comparar
	{
	    case 1: //Bloque de instrucciones 1;
	    cout<<"Option 1";
	    break;
	    case 2: //Bloque de instrucciones 2;
	    cout<<"Option 2";
	    break;
	    case 3: //Bloque de instrucciones 3;
	    cout<<"Option 3";
	    break;
	    //Nótese que valor 1 2 y 3 son los valores que puede tomar la opción
	    //la instrucción break es necesaria, para no ejecutar todos los casos.
	    default: //Bloque de instrucciones por defecto;
	    cout<<"Ninguna.";
	    //default, es el bloque que se ejecuta en caso de que no se de ningún caso
	}*/
	
	/*cout << "Ingrese la Opción a ejecutar: ";
	char opcion;
	cin >> opcion;
	
	switch(opcion)
	{
	    case 'a': cout << "Usted ha seleccionado la opción a";
	    break;
	    case 'b': cout << "Usted ha seleccionado la opción b";
	    break;
	    case 'c': cout << "Usted ha seleccionado la opción c";
	    break;
	    default: cout << "Usted ha ingresado una opción incorrecta";
	}*/
	
	/////////////////////////////////////////////////
	
	
	/*srand(time(NULL));
	cout<<"Número random:\n";
	cout<<1+rand()%(16-1);*/
	
	/////////////////////////////////////////////
	
	
	/*#include <iomanip>
	#include <iostream>
	#include <vector>
	using namespace std:
	using std::cout;
	using std::endl;
	using std::fixed;
	using std::setprecision;
	using std::vector;
	
	int main() {
	  vector<double> d_vec = {123.231,       2.2343, 0.324,     0.012,
	                          26.9491092019, 11013,  92.001112, 0.000000234};
	
	  for (auto &i : d_vec) {
	    cout << setprecision(3) << i << " | ";
	  }
	  cout << endl;
	
	  return EXIT_SUCCESS;
	}*/
	
	////////////////////////////////////////////
	
	//cout<<"Hola"<<endl<<"como estas?";
	
	///////////////////////////////////////////////
	
	/*#include <iostream>
	#include <string>
	
	string cad1, cad2;
	cout<<"Digitar primer cadena: ";
	cin>>cad1;
	cout<<"Digitar segundacadena: ";
	cin>>cad2;
	string cad3 = cad1+" "+cad2;
	cout<<"Es: "<<cad3;*/
	
	////////////////////////////////////////////////
	
	/*cout<<"Hola";
	sleep(5);
	cout<<"Jean";*/
	
	///////////////////////////////////////////////
	
	// return_statement2.cpp
	

//    string one = "juan";
//    string two = "carlos";
//    //printf_s("\n %s is bigger\n", max(one, two));
//	cout<<max(one,two);
//	//return EXIT_SUCCESS; 



////////////////////////////////////////////

//	int num;
//	num =4;
//	cout<<"Es: "<<max(num);


///////////////////////////////////////////////

//	int numr1;
//	cout<<"Qué número cree salió (1-6): \t";
//	cin>>numr1;
//	int gana=randd(numr1);
//	cout<<"El número random fue: "<<gana<<"\n";
//	if(numr1==gana){
//		cout<<"Ganaste";
//	}else{
//		cout<<"Perdiste";
//	}

//////////////////////////////////////////////

//	int raiz, resul, resul2;
//	cout<<"Ingrese número: \n";
//	cin>>raiz;
//	resul=sqrt(raiz);
//	resul2=float(sqrt(raiz));
//	cout<<"Es: "<<resul<<" Y es: "<<resul2;

/////////////////////////////////////////////

//	string seguir = "S";
//	while (seguir=="S" or seguir=="s"){
//		int raiz, resul, resul2;
//		cout<<"Ingrese número: \n";
//		cin>>raiz;
//		resul=sqrt(raiz);
//		resul2=float(sqrt(raiz));
//		cout<<"\nEs: "<<resul;
//		
//		cout<<"\n Desea seguir?: \t";
//		cin>>seguir;
//	
//		while(seguir!="S" and seguir!="s" and seguir !="N" and seguir != "n"){
//			cout<<"\nOpción incorrecta!";
//			cout<<"\n Desea seguir?: \t";
//			cin>>seguir;
//		}
//		
//		cout<<"Adiós!";	
//	}


/////////////////////////////////////////////////

	#define pi 3.1416
	
//	int global = 5;
//	int a = 1;
//	double x = 3.99;
//	a = global + (int) x;
//	cout<<a;

/////////////////////////////////////////////////
	
	//	#include <fstream.h>
	
//	string cont, sivacio, contenido;
//	string nombre = "ejemplo.txt";
//	ofstream EscribirArchivo;
//	//ifstream LeerArchivo("ejemplo.txt");
//	LeerArchivo.open(nombre, ios_base::in);
//	if(LeerArchivo.is_open()){
//		LeerArchivo>>contenido;
//		cout<<"\n Contenido es: "<<contenido+"\n";
//		LeerArchivo.close();
//		
//		EscribirArchivo.open(nombre.c_str(), ios_base::app);
//		cout<<"Ingrese nuevo contenido¨:\n";
//		cin>>sivacio;
//		EscribirArchivo<<sivacio+"\n";
//		EscribirArchivo.close();
//			
//	}else{
//		
//	}
	
//	string nombre;
//	ifstream archivo;
//	ofstream archivo2;
//	nombre = "ejemplo.txt";
//	archivo.open(nombre, ios_base::in);
//	string contenido;
//	archivo>>contenido;
//	cout<<contenido<<endl;
//	archivo.close();
//	
//	archivo2.open(nombre.c_str(), ios_base::app);
//	string nuevo;
//	cin>>nuevo;
//	archivo2<<nuevo+"\n";
//	cout<<"Agregado!\n";
//	archivo2.close();
//	
//	FILE * archivo3;
//  	long medida;
//  	char * texto;
//	archivo3 = fopen("ejemplo.txt", "r");
//	
//	//archivo3.fopen(nombre, ios_base::in);
////	string contenidon;
////	archivo>>contenidon;
////	cout<<contenidon<<endl;
////	archivo.close();
//	
//	fseek (archivo3 , 0 , SEEK_END);
//	medida = ftell (archivo3);
//	rewind (archivo3);
//	
//	// La siguiente linea asigna de forma automatica la memoria del archivo completo
//	texto = (char*) malloc (sizeof(char)*medida);
//	
//	// Ahora por fin almacenamos el texto del archivo en la variable texto
//	fread(texto, medida+1, 1, archivo3);
//	
//	// vemos su contenido por pantalla
//	cout << texto;


	///////////////////////////////////////////////////////////
	
	#define MAX_SIZE 100
	
	//////////////////////////////////////////////////////////
	
//	int valor;
//	cout<<"Digite valor: ";
//	cin>>valor;
//	for(int i=1;i<=10;i++){
//		cout<<valor*i<<endl;
//	}
	
	///////////////////////////////////////////////////////7
	
//	int par, impar;
//	for(int i=20;i>0;i=i-2){
//		cout<<i<<endl;
//	}
//	for(int i=19;i>0;i=i-2){
//		cout<<i<<endl;
//	}
	
	///////////////////////////////////////////////////////7
	
//	int num1;
//	
//	do{
//		if(num1%2==0 and num1>0){
//			cout<<"Número par.\n";	
//		}
//		num1++;
//		
//	}
//	while(num1<=20);
//	do-while: se ejecuta al menos una vez

//////////////////////////////////////////////////////////////

	//GOTO //Va en contra de la programación de objetos
	//Se usa para pruebas
	//facilita la depuración del código
	
//	goto jumping;
//	cout<<"Aquí no llego"<<endl;
//	jumping:
//	cout<<"Aquí si llegó"<<endl;
//	return 0;	
	
	////////////////////////////////////////////////////////
	
//	int num1, num2;
//	cout<<"raiz cuadrada";
//	cout<<"Ingrese número:\n";
//	cin>>num1;
//	if(!raizc(num1)){
//		cout<<"El número no es válido.\n";
//	}


///////////////////////////////////////////////////////////////

	//static variables en void Saldo
	//static double mi_dinero;
	
//	Saldo(1000);
//	Saldo(-1500);
//	return -1;

//////////////////////////////////////////////////////////////

	//estructuras _ abstracción
//	struct complex a; //se puede omitir el complex
//	a.real=1;
//	a.imag=1.2;
//	cout<<a.real<<"+"<<a.imag<<"i"<<endl;
//	return 0;

//////////////////////////////////////////////////////////////

//	int opt;
//	cout<<"Área de cuadrado o triangulo?: 1 o 2\n";
//	cin>>opt;
//	switch(opt){
//
//		case 1:
//			cuadrado c;
//			cout<<"Ingrese lado del cuadrado:\t";
//			cin>>c.lado;
//			cout<<"\nEl área del cuadrado es: "<<acuadrado(c)<<endl;
//			break;
//		case 2:
//			triangulo t;
//			cout<<"Ingrese base del triangulo:\t";
//			cin>>t.base;
//			cout<<"\nIngrese altura del triangulo\t";
//			cin>>t.altura;
//			cout<<"\nEl área del triangulo es: "<<atriangulo(t)<<endl;
//			break;
//		}

//////////////////////////////////////////////////////////////

	

}

double acuadrado(cuadrado p){
	return (p.lado*p.lado);
}

double atriangulo(triangulo p){
	return ((p.base*p.altura)/2);
}

void Saldo(double euros){
	static double mi_dinero;
	mi_dinero += euros;
	cout<<"Tengo en mi cuenta "<<mi_dinero<<" euros"<<endl;
}

double raizc(double num1){
	//double num1;
	if(sqrt(num1)>=0){
		cout<<"La raiz de "<<num1<<" es: "<<sqrt(num1)<<endl;
		return 1;
	}
	else{
		return 0;
	}
}

int randd(int num){
	
	srand(time(NULL));
	int numr = 1+rand()%(6);
	return numr;
}


int max(int a){
	int num = a+5;
	return num;
}

 

//#include <algorithm>
//#include <iostream>
//#include <iterator>
//using namespace std;
//
//string max(string a, string b)
//{
//	string mayor;
//    string nom1 = a;
//    string nom2 = b;
//    
//    if(a.length() < b.length()){
//	    mayor=nom2; 
//	}
//	if(a.length()==b.length())
//	{	
//		mayor="Tamaños iguales.";
//	}
//    else{
//    	mayor=nom1;  
//	}
//	
//	return mayor;
//}