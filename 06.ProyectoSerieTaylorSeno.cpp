#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

double factorial(int);
double taylor(int,int);

int main()
{
    int n,x;
    cout<<"Digite una cantidad N "<<endl;
    cin>>n;
    cout<<"Digite valor de X "<<endl;
    cin>>x;
    cout<<"\n El valor de taylor para N = "<<n<<", X = "<<x<<" es "<<taylor(n,x)<<endl<<endl;
    cout<<"Hecho por: Daniel Estiven Guancha  & Jean Carlos Hernandez"<<endl;
	cout<<"Ingenier"<<(char)161<<"a de Sistemas Grupo 1"<<endl;
	cout<<"Universidad de nari"<<(char)164<<"o"<<endl;
    system("pause");
    
}
double taylor(int n,int x)
{
   double t,s=0;
   for(int i=0;i<n;i++)
   {
       t=pow(x,1)/factorial(i);
       s += t;
   }
   return s;
}

double factorial(int n)
{
    double fac =1;
    for(int i=2;i<=n;i++)
    {
        fac *=i;
    }
    return fac;
}
