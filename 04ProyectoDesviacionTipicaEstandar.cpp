#include<iostream>
#include<ctype.h>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
using namespace std;
void desviacionest_vector();const int MAXF=100;
const int MAXC=100;
int main()
{
	system("cls");
		int i,j,can;
		double v[MAXF][MAXC],n,acum=0,prom,acum1=0;
	
{
    system("cls");
    cout<<"Digite la cantidad de registros ";
    cin>>can;
    
    
    for(j=0;j<can;j++)
    {
		cout<<"Digite valor posicion "<<j+1<<endl;
        cin>>n;
        v[j][0]=n;
        acum=acum+n;
    }
		
	
	prom=acum/can;
    
    for(j=0;j<can;j++)
    {
		v[j][1]= v[j][0]-prom;
		v[j][2]=v[j][1]*v[j][1];
        acum1=acum1+v[j][2];
        
    }
    cout<<setw(2)<<"X"<<setw(15)<<"X-Prom"<<setw(15)<<"(X-Prom)^2"<<endl<<endl;
    for(j=0;j<can;j++)
    {
    	
		cout<<setw(2)<<v[j][0]<<setw(15)<<v[j][1]<<setw(15)<<v[j][2]<<endl;
    }
    cout<<"n: "<<can<<endl;
    cout<<"Promedio: "<<prom<<endl;
    cout<<"s: "<<sqrt(acum1/can)<<endl;
    
    	cout<<"hecho por: Sebastian Bastidas - Jean Carlos Hernandez"<<endl;
	cout<<"Ingenier"<<(char)161<<"a de Sistemas Grupo 1"<<endl;
	cout<<"Universidad de nari"<<(char)164<<"o"<<endl;
getch();
    }
}
