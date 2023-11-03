#include<iostream>
#include<ctype.h>
#include<stdlib.h>
using namespace std;
const int MAXF=100;
const int MAXC=100;

int j,i;  //SE DEFINE "i,j" AQUÍ PARA DEFINIRLAS EN TODO EL PROGRAMA.
void menuprincipal();

//FUNCIONES DE VECTORES
void menuvectores(double v[MAXF],int &j);
void menucrearvector(double v[MAXF],int &j);
void vectordesdeteclado(double v[MAXF],int &j);
void imprimirvector(double v[MAXF],int &j);
void menuconsultavector(double v[MAXF],int &j);
void consultaporposicionvector(double v[MAXF], int &j);
void consultaporvalorvector(double v[MAXF], int &j);
void modificarvector(double v[MAXF], int &j);

//FUNCIONES DE MATRICES
void menumatrices(double amatriz[MAXF][MAXC],int &afil,int &acol);
void menucrearmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol);
void matrizporteclado(double amatriz[MAXF][MAXC],int &afil,int &acol);
void imprimirmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol);
void menuconsulmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol);
void consultaporposicionmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol);
void consultaporvalormatriz(double amatriz[MAXF][MAXC],int &afil,int &acol);
void modificarmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol);
void menuadicionarenmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol);
void adicionarfilamatriz(double amatriz[MAXF][MAXC],int &afil,int &acol);

bool esentero(char n[20]);
bool esnumero(char n[20]);

int main()
{
    menuprincipal();
    return 0;
}

void menuprincipal()
{
    char opcion[2];
    double amatriz[MAXF][MAXC],bmatriz[MAXF][MAXC],v[j];
    int afil=0,acol=0,bfil=0,bcol=0,j;
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
        menuvectores(v,j);
        break;
    case 'b':
        menumatrices(amatriz,afil,acol);
        break;
    case 'c':
        //VAN LOS CREDITOS
        break;
    case 'x':
        system("cls");
        cout<<"Gracias por utilizar nuestro programa"<<endl;
        system("exit");
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        system("pause");
        menuprincipal();
        break;

    }

}
void menuvectores(double v[MAXF],int &j)
{
    char opcion[2];
    int i=0;
    int num;
    system("cls");
    cout
            <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
            <<"MANEJO DE VECTORES"<<endl<<endl
            <<"A) CREAR"<<endl
            <<"B) MOSTRAR"<<endl
            <<"C) CONSULTAR"<<endl
            <<"D) MODIFICAR"<<endl
            <<"E) ADICIONAR"<<endl
            <<"F) ELIMINAR"<<endl
            <<"G) GRABAR EN ARCHIVO"<<endl
            <<"H) ORDENAR EL VECTOR"<<endl
            <<"I) PROMEDIO,NUMERO MAYOR, NUMERO MENOR, MODA Y DESVIACION ESTANDAR"<<endl<<endl
            <<"M) VOLVER AL MENU PRINCIPAL"<<endl
            <<"X) SALIR"<<endl
            <<"DIGITE OPCION ";
    cin>>opcion;
    opcion[0]=tolower(opcion[0]);
    switch(opcion[0])
    {
    case 'a':
        menucrearvector(v,j);
        break;
    case 'b':
        imprimirvector(v,j);
        break;
    case 'c':
        menuconsultavector(v,j);
        break;
    case 'd':
        modificarvector(v,j);
        break;
    case 'e':
        //HACER FUNCION DE ADICIONAR.
        break;
    case 'f':
        //HACER FUNCION DE ELIMINAR.
        break;
    case 'g':
        //HACER FUNCION DE GRABAR EN ARCHIVO.
        break;
    case 'h':
        // HACER FUNCION DE ORDENAR EL VECTOR... ASCENDENTE Y DESCENDENTE
        break;
    case 'i':
        //HACER FUNCION DE PROMEDIO, NUMERO MAYOR, NUMERO MENOR, MODA Y DESVIACION ESTANDAR.
        break;
    case 'm':
        menuprincipal();
        break;
    case 'x':
        system("cls");
        cout<<"Gracias por utilizar nuestro programa"<<endl;
        system("exit");
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        system("pause");
        menuvectores(v,j);
        break;
    }
}

void menumatrices(double amatriz[MAXF][MAXC],int &afil,int &acol)
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
        menucrearmatriz(amatriz,afil,acol);
        break;
    case 'b':
        imprimirmatriz(amatriz,afil,acol);
        break;
    case 'c':
        menuconsulmatriz(amatriz,afil,acol);
        break;
    case 'd':
        modificarmatriz(amatriz,afil,acol);
        break;
    case 'e':
        menuadicionarenmatriz(amatriz,afil,acol);
        break;
    case 'f':
        //HACER FUNCION MENU ELIMINAR EN MATRIZ
        break;
    case 'g':
        // HACER FUNCION DE GRABAR EN ARCHIVO
        break;
    case 'h':
        // HACER FUNCION DE MENU SUMA Y MULTIPLICACION
        break;
    case 'i':
        // HACER FUNCION DEL DETERMINANTE DE ODREN 4
        break;
    case 'm':
        menuprincipal();
        break;
    case 'x':
        system("cls");
        cout<<"Gracias por utilizar nuestro programa"<<endl;
        system("exit");
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        system("pause");
        menumatrices(amatriz,afil,acol);
        break;

    }

}
void menucrearmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol)
{
    char opcion[2];
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
        matrizporteclado(amatriz,afil,acol);
        break;
    case 'b':

        break;
    case 'v':
        menumatrices(amatriz,afil,acol);
        break;

    case 'm':
        menuprincipal();
        break;
    case 'x':
        system("cls");
        cout<<"Gracias por utilizar nuestro programa"<<endl;
        system("exit");
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        system("pause");
        menucrearmatriz(amatriz,afil,acol);
        break;

    }
}

void matrizporteclado(double amatriz[MAXF][MAXC],int &afil,int &acol)
{
    bool verifi=true,verico=true;
    int i,j;
    char f[20],c[20];
    afil=0;
    acol=0;
    system("cls");
    cout
            <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
            <<"MANEJO DE MATRICES"<<endl
            <<"CREACION DE MATRICES"<<endl<<endl
            <<"CREAR POR TECLADO"<<endl<<endl;
    cout<<"Digite numero de filas de las matriz"<<endl;
    do
    {
        if(!verifi)
        {
            cout<<"Numero de fila no valido, vuelva a digitar"<<endl;
        }
        //cin.getline(f,sizeof(f)-1); HECHA POR JAIME
        cin>>f;
        afil=atof(f);
        verifi=false;
    }
    while(afil<=0 or !esentero(f));
    cout<<"Digite numero de columnas de las matriz"<<endl;
    do
    {
        if(!verico)
        {
            cout<<"Numero de columna no valido, vuelva a digitar"<<endl;
        }
        //cin.getline(c,sizeof(c)-1);  HECHA POR JAIME
        cin>>c;
        acol=atof(c);
        verico=false;
    }
    while(acol<=0 or !esentero(c));
    for(i=0; i<afil; i++)
    {
        for(j=0; j<acol; j++)
        {
            cout<<"F["<<i+1<<"] C["<<j+1<<"] ";
            cin>>amatriz[i][j];
        }
    }
    menumatrices(amatriz,afil,acol);
    system("pause");
}

void imprimirmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol)
{
    system("cls");
    int i,j;
    if(afil==0 or acol==0)
    {
        cout<<"No se ha ingresado ninguna matriz"<<endl;
        system("pause");
        menucrearmatriz(amatriz,afil,acol);
    }

    for(i=0; i<afil; i++)
    {
        for(j=0; j<acol; j++)
        {
            cout<<amatriz[i][j]<<"\t";
        }
        cout<<endl;
    }

    system("pause");
    menumatrices(amatriz,afil,acol);
}

void menuconsulmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol)
{
    char opcion[2];
    system("cls");
    if(afil==0 or acol==0)
    {
        cout<<"No se ha ingresado ninguna matriz"<<endl;
        system("pause");
        menucrearmatriz(amatriz,afil,acol);
    }
    else
    {
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
            consultaporposicionmatriz(amatriz,afil,acol);
            break;
        case 'b':
            consultaporvalormatriz(amatriz,afil,acol);
            break;
        case 'v':
            menumatrices(amatriz,afil,acol);
            break;

        case 'm':
            menuprincipal();
            break;
        case 'x':
            system("cls");
            cout<<"Gracias por utilizar nuestro programa"<<endl;
            system("exit");
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            system("pause");
            menuconsulmatriz(amatriz,afil,acol);
            break;
        }
    }
}
void consultaporposicionmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol)
{
    char opcion[2];
    int fil=0, col=0;
    bool verifi=true, verico=true;
    system("cls");

    cout
            <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
            <<"MANEJO DE MATRICES"<<endl
            <<"CONSULTA"<<endl<<endl
            <<"CONSULTA POR POSICION "<<endl<<endl;
    cout<<"Digite numero de la fila"<<endl;
    do
    {
        if(verifi==false)
        {
            cout<<"Numero de fila no valido, vuelva a digitar"<<endl;
        }

        cin>>fil;
        verifi=false;
    }
    while(fil<=0 or fil>afil);
    cout<<"Digite numero de la columna"<<endl;
    do
    {
        if(verico==false)
        {
            cout<<"Numero de fila no valido, vuelva a digitar"<<endl;
        }
        cin>>col;
        verico=false;
    }
    while(col<=0 or col>acol);
    cout<<"En la posicion ("<<fil<<","<<col<<") es: "<<amatriz[fil-1][col-1]<<endl<<endl;
    cout<<"¿desea realizar otra busqueda? S o N"<<endl;
    cin>>opcion;
    opcion[0]=tolower(opcion[0]);
    switch(opcion[0])
    {
    case 's':
        consultaporposicionmatriz(amatriz,afil,acol);
        break;
    case 'n':
        menumatrices(amatriz,afil,acol);
        break;
    default:
        cout<<"Opcion no valida, vuelva a digitar"<<endl;
        consultaporposicionmatriz(amatriz,afil,acol);
        break;
    }
}

void consultaporvalormatriz(double amatriz[MAXF][MAXC],int &afil,int &acol)
{
    double a;
    int i,j;
    char opcion[2];
    bool encontrado=false;
    system("cls");
    cout
            <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
            <<"MANEJO DE MATRICES"<<endl
            <<"CONSULTA"<<endl<<endl
            <<"CONSULTA POR VALOR "<<endl<<endl;
    cout<<"Digite valor a consultar"<<endl;
    cin>>a;
    for(i=0; i<afil; i++)
    {
        for(j=0; j<acol; j++)
        {
            if(a==amatriz[i][j])
            {
                cout<<"Valor se encuentra en la posicion ("<<i+1<<","<<j+1<<")"<<endl;
                encontrado=true;
            }
        }
    }
    if(encontrado==false)
    {
        cout<<"El numero no se encuentra en la Matriz"<<endl;
    }
    cout<<"¿desea realizar otra busqueda? S o N"<<endl;
    cin>>opcion;
    opcion[0]=tolower(opcion[0]);
    switch(opcion[0])
    {
    case 's':
        consultaporvalormatriz(amatriz,afil,acol);
        break;
    case 'n':
        menumatrices(amatriz,afil,acol);
        break;
    default:
        cout<<"Opcion no valida, vuelva a digitar"<<endl;
        consultaporvalormatriz(amatriz,afil,acol);
        break;
    }
}

void modificarmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol)
{
    char opcion[2];
    int fil=0, col=0;
    bool verifi=true, verico=true;
    system("cls");
    if(afil==0 or acol==0)
    {
        cout<<"No se ha ingresado ninguna matriz"<<endl;
        system("pause");
        menucrearmatriz(amatriz,afil,acol);
    }
    else
    {
        cout
                <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
                <<"MANEJO DE MATRICES"<<endl
                <<"MODIFICAR "<<endl<<endl;
        cout<<"Digite numero de la fila"<<endl;
        do
        {
            if(verifi==false)
            {
                cout<<"Numero de fila no valido, vuelva a digitar"<<endl;
            }
            cin>>fil;
            verifi=false;
        }
        while(fil<=0 or fil>afil);
        cout<<"Digite numero de la columna"<<endl;
        do
        {
            if(verico==false)
            {
                cout<<"Numero de fila no valido, vuelva a digitar"<<endl;
            }
            cin>>col;
            verico=false;
        }
        while(col<=0 or col>acol);
        cout<<"En la posicion ("<<fil<<","<<col<<") es: "<<amatriz[fil-1][col-1]<<endl<<endl;
        cout<<"Digite nuevo valor "<<endl;
        cin>>amatriz[fil-1][col-1];
        cout<<"¿desea realizar otra modificacion? S o N"<<endl;
        cin>>opcion;
        opcion[0]=tolower(opcion[0]);
        switch(opcion[0])
        {
        case 's':
            modificarmatriz(amatriz,afil,acol);
            break;
        case 'n':
            menumatrices(amatriz,afil,acol);
            break;
        default:
            cout<<"Opcion no valida, vuelva a digitar"<<endl;
            modificarmatriz(amatriz,afil,acol);
            break;
        }
    }
}

void menuadicionarenmatriz(double amatriz[MAXF][MAXC],int &afil,int &acol)
{
    char opcion[2];
    system("cls");
    if(afil==0 or acol==0)
    {
        cout<<"No se ha ingresado ninguna matriz"<<endl;
        system("pause");
        menucrearmatriz(amatriz,afil,acol);
    }
    else
    {
        cout
                <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
                <<"MANEJO DE MATRICES"<<endl
                <<"ADICIONAR"<<endl<<endl
                <<"A) ADICIONAR FILA"<<endl
                <<"B) ADICIONAR COLUMNA"<<endl<<endl
                <<"V) VOLVER MENU ANTERIOR"<<endl
                <<"M) VOLVER AL MENU PRINCIPAL"<<endl
                <<"X) SALIR"<<endl
                <<"DIGITE OPCION ";
        cin>>opcion;
        opcion[0]=tolower(opcion[0]);
        switch(opcion[0])
        {
        case 'a':
            consultaporposicionmatriz(amatriz,afil,acol);
            break;
        case 'b':
            consultaporvalormatriz(amatriz,afil,acol);
            break;
        case 'v':
            menumatrices(amatriz,afil,acol);
            break;

        case 'm':
            menuprincipal();
            break;
        case 'x':
            system("cls");
            cout<<"Gracias por utilizar nuestro programa"<<endl;
            system("exit");
            break;
        default:
            cout<<"Opcion no valida, DIigte nuevamente"<<endl;
            system("pause");
            menuadicionarenmatriz(amatriz,afil,acol);
            break;
        }
    }
}
void adicionarfilamatriz(double amatriz[MAXF][MAXC],int &afil,int &acol)
{
    char opcion[2];
    int fil=0;
    bool verifi=true, verico=true;
    system("cls");
    cout
            <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
            <<"MANEJO DE MATRICES"<<endl
            <<"ADICIONAR"<<endl<<endl
            <<"ADICIONAR FILA"<<endl<<endl;
    cout<<"Digite posicion de la fila"<<endl;
    do
    {
        if(verifi==false)
        {
            cout<<"Numero de fila no valido, vuelva a digitar"<<endl;
        }

        cin>>fil;
        verifi=false;
    }
    while(fil<=0 or fil>afil+1);
    cout<<"¿desea realizar adicionar otra fila? S o N"<<endl;
    cin>>opcion;
    opcion[0]=tolower(opcion[0]);
    switch(opcion[0])
    {
    case 's':
        adicionarfilamatriz(amatriz,afil,acol);
        break;
    case 'n':
        menumatrices(amatriz,afil,acol);
        break;
    default:
        cout<<"Opcion no valida, vuelva a digitar"<<endl;
        adicionarfilamatriz(amatriz,afil,acol);
        break;
    }
}

bool esentero(char n[20])
{
    int i=0,cont=0,ver=0;
    bool entero=false;
    while(n[i]!='\0')
    {
        if(isdigit(n[i]) or n[i]=='-')
        {
            cont++;
            if(n[i]=='-')
            {
                ver++;
            }
        }
        i++;
    }
    if(i>=1 and i==cont and ver<2)
    {
        entero=true;
    }
    return(entero);
}
bool esnumero(char n[20])
{
    int i=0,cont=0,ver=0,verb=0;
    bool numero=false;
    while(n[i]!='\0')
    {
        if(isdigit(n[i]) or n[i]=='-' or n[i]=='.')
        {
            cont++;
            if(n[i]=='-')
            {
                ver++;
            }
            if(n[i]=='.')
            {
                verb++;
            }
        }
        i++;
    }
    if(i>=1 and i==cont and ver<2 and verb<2)
    {
        numero=true;
    }
    return(numero);
}


// HICE LOS VECTORES
void menucrearvector(double v[MAXF],int &j)
{
    char opcion[2];
    system("cls");
    cout
            <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
            <<"MANEJO DE VECTORES"<<endl
            <<"CREACION DE VECTORES"<<endl<<endl
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
        vectordesdeteclado(v,j);
        break;
    case 'b':
        //HACER VECTOR DESDE ARCHIVO
        break;
    case 'v':
        menuvectores(v,j);
        break;

    case 'm':
        menuprincipal();
        break;
    case 'x':
        system("cls");
        cout<<"Gracias por utilizar nuestro programa"<<endl;
        system("exit");
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        system("pause");
        menucrearvector(v,j);
        break;
    }
}

void vectordesdeteclado(double v[MAXF],int &j)
{
    system("cls");
    int i,num;  //NUM ES LA VARIABLE PARA CADA VALOR EN EL VECTOR.
    bool verilargo=true;
    do
    {
        if(verilargo==false)
        {
            cout<<"Largo del Vector no valido, vuelva a digitar"<<endl;
        }
        cout<<"Digite largo del vector "<<endl;
        cin>>j;
        verilargo=false;
    }
    while(j<=0 and isdigit(j)==false);
    for(i=0; i<=(j-1); i++)
    {
        cout<<"Digite valor posicion # "<<i+1<<endl;
        cin>>num;
        v[i]=num;
    }
    for(i=0; i<=(j-1); i++)
    {
        cout<<v[i]<<" - ";
    }
    system("pause");
    menuvectores(v,j);
}

void imprimirvector(double v[MAXF],int &j)
{
    system("cls");
    int i;
    if(j==0)
    {
        cout<<"No se ha ingresado ningun vector"<<endl;
        system("pause");
        menucrearvector(v,j);
    }
    else
    {
        for(i=0; i<=(j-1); i++)
        {
            cout<<v[i]<<" - ";
        }
    }
    system("pause");
    menuvectores(v,j);
}

void menuconsultavector(double v[MAXF], int &j)
{
    char opcion[2];
    system("cls");
    if(j==0)
    {
        cout<<"No se ha ingresado ningun vector"<<endl;
        system("pause");
        menucrearvector(v,j);
    }
    else
    {
        cout
                <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
                <<"MANEJO DE VECTORES"<<endl
                <<"CONSULTA DE VECTORES"<<endl<<endl
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
            consultaporposicionvector(v,j);
            break;
        case 'b':
            consultaporvalorvector(v,j);
            break;
        case 'v':
            menuvectores(v,j);
            break;

        case 'm':
            menuprincipal();
            break;
        case 'x':
            system("cls");
            cout<<"Gracias por utilizar nuestro programa"<<endl;
            exit(0); // LE PUSE "exit(0)" PORQUE NO CERRABA COMPLETAMENTE Y ME REDIRIGIA AL MENU PRINCIPAL. //CON ESE "exit(0)" YA CIERRA BIEN.
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            system("pause");
            menuconsultavector(v,j);
            break;
        }
    }
}

void consultaporposicionvector(double v[MAXF], int &j)
{
    char opcion[2];
    int pos=0;   // "pos" ES UNA VARIABLE ENTERA QUE SE USA PARA CONSULTAR POR POSICION
    bool veripos=true;
    system("cls");
    cout
            <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
            <<"MANEJO DE VECTORES"<<endl
            <<"CONSULTA:"<<endl<<endl
            <<"CONSULTA POR POSICION "<<endl<<endl;
    cout<<"Digite Posicion del vector a buscar"<<endl;
    do
    {
        if(veripos==false)
        {
            cout<<"Posicion no valida, vuelva a digitar"<<endl;
        }
        cin>>pos;
        veripos=false;
    }
    while(pos<=0 or pos>j);
    cout<<"En la posicion ("<<pos<<") se encuentra: "<<v[pos-1]<<endl<<endl;
    cout<<"¿desea realizar otra busqueda? S o N"<<endl;
    cin>>opcion;
    opcion[0]=tolower(opcion[0]);
    switch(opcion[0])
    {
    case 's':
        consultaporposicionvector(v,j);
        break;
    case 'n':
        menuvectores(v,j);
        break;
    default:
        cout<<"Opcion no valida, vuelva a digitar"<<endl;
        consultaporposicionvector(v,j);
        break;
    }
}

void consultaporvalorvector(double v[MAXF], int &j)
{
    double a;
    int i;
    char opcion[2];
    bool encontrada=false;
    system("cls");

    cout
            <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
            <<"MANEJO DE MATRICES"<<endl
            <<"CONSULTA"<<endl<<endl
            <<"CONSULTA POR VALOR "<<endl<<endl;
    cout<<"Digite valor a consultar"<<endl;
    cin>>a;
    for(i=0; i<j; i++)
    {
        if(a==v[i])
        {
            cout<<"Valor se encuentra en la posicion ("<<i+1<<")"<<endl;
            encontrada=true;
        }
    }
    if(encontrada==false)
    {
        cout<<"El numero no se encuentra en el vector"<<endl;
    }
    cout<<"¿desea realizar otra busqueda? S o N"<<endl;
    cin>>opcion;
    opcion[0]=tolower(opcion[0]);
    switch(opcion[0])
    {
    case 's':
        consultaporvalorvector(v,j);
        break;
    case 'n':
        menuvectores(v,j);
        break;
    default:
        cout<<"Opcion no valida, vuelva a digitar"<<endl;
        consultaporvalorvector(v,j);
        break;
    }
}

void modificarvector(double v[MAXF], int &j)
{
    char opcion[2];
    int posi=0;	// "posi" SIRVE COMO VARIABLE DE POSICION PARA CAMBIAR LO QUE ALLÍ SE ENCUENTRE.
    bool veriposi=true;
    system("cls");
    if(j==0)
    {
        cout<<"No se ha ingresado ningun vector"<<endl;
        system("pause");
        menucrearvector(v,j);
    }
    else
    {
        cout
                <<"CALCULADORA DE VECTORES Y MATRICES"<<endl<<endl
                <<"MANEJO DE VECTORES"<<endl
                <<"MODIFICAR "<<endl<<endl;
        cout<<"Digite posicion del numero a modificar"<<endl;
        do
        {
            if(veriposi==false)
            {
                cout<<"Posicion del vector no valida, vuelva a digitar"<<endl;
            }
            cin>>posi;
            veriposi=false;
        }
        while(posi<=0 or posi>j);
        cout<<"En la posicion ("<<posi<<") se encuentra: "<<v[posi-1]<<endl<<endl;
        cout<<"Digite nuevo valor "<<endl;
        cin>>v[posi-1];
        cout<<"¿desea realizar otra modificación? S o N"<<endl;
        cin>>opcion;
        opcion[0]=tolower(opcion[0]);
        switch(opcion[0])
        {
        case 's':
            modificarvector(v,j);
            break;
        case 'n':
            menuvectores(v,j);
            break;
        default:
            cout<<"Opcion no valida, vuelva a digitar"<<endl;
            modificarvector(v,j);
            break;
        }
    }
}

