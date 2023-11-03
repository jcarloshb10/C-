#include<iostream>
#include<ctype.h>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
using namespace std;
const int MAXF=100;
const int MAXC=100;
int main()
{
	system("cls");
		int i,j,dep,mayor,menor,aux;
		double v[MAXF][MAXC],aus,acum=0;
	
    cout<<"Asistencia al Trabajo"<<endl;
    cout<<"Digite la cantidad de departamentos"<<endl;
    cin>>dep;
    
    for(i=0;i<dep;i++)
    {
    	acum=0;
		for(j=0;j<7;j++)
		{
		cout<<"Digite ausentes en el departamento "<<i+1<<", dia "<<j+1<<endl;
        cin>>aus;
        v[i][j]=aus;
        acum=acum+aus;
        v[i][7]=acum;
        
		}
	}

	for(j=0;j<8;j++)
	{
		v[dep][j]=0;
		for(i=0;i<dep;i++)
		{
			v[dep][j]=v[dep][j]+v[i][j];
		}	
	}
	
	cout<<setw(2)<<"\tLunes"<<setw(9)<<"Martes"<<setw(10)<<"Miercol."<<setw(6)<<"Jueves"<<setw(9)<<"Viernes"<<setw(7)<<"Sabado"<<setw(9)<<"Domingo"<<setw(6)<<"Total"<<endl;
	for(i=0;i<=dep;i++)
    {
    	if(i==dep)
    	{
		cout<<"Total : ";
		}
		else
		{	
		cout<<"Dpto "<<i+1<<": ";
		}
		for(j=0;j<8;j++)
		{
        cout<<v[i][j]<<"\t";
		}
    
		cout<<endl;
    }
    
    
	mayor=v[0][7];
    for(i=0; i<dep; i++)
    {
        if(v[i][7]>=mayor)
        {
        	mayor=v[i][7];
            aux=i;
		}       
    }
    cout<<"El departamento con mayor ausentismo en la semana fue dpto "<<aux+1<<endl;
	mayor=v[0][7];
    for(i=0; i<dep; i++)
    {
         if(v[i][7]<=mayor)
        {
        	mayor=v[i][7];
            aux=i;
		}
    }
    cout<<"El departamento con menor ausentismo en la semana fue dpto "<<aux+1<<endl;
   
    cout<<"Hecho por: Sebastian Bastidas Rosero - Jean Carlos Hernandez"<<endl;
	cout<<"Ingenier"<<(char)161<<"a de Sistemas Grupo 1"<<endl;
	cout<<"Universidad de nari"<<(char)164<<"o"<<endl;
	getch();
    
}
