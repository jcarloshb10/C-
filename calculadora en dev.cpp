#include<iostream>
using namespace std;
main()
{
	double n1,n2,total; //total=0 es para inicializar el acumulador. Se puede en la asignacion de variables o despues.
	char opc;
	total=0;

	cout<<"CALCULADORA BASICA\n";
	cout<<"Ingresa el primer valor\n";
	cin>>n1;
	
	do
		{
			cout<<"\n\n+:suma"<<endl
				<<"\n-:resta"<<endl
				<<"\n*:multiplicaion"<<endl          
				<<"\n/:division"<<endl
				<<"\ns:salir"<<endl
				<<endl
				<<"\nTu opcion: \n";
				cin>>opc;
			
			if(opc !='s')
			{
				cout<<"\nIngresa el segundo valor\n";
				cin>>n2;
				switch(opc)// switch para variable de decision multiple o la estructura 'segun'
					{
						case '+':
							total=n1+n2;
							break;
						case '-':
							total=n1-n2;
							break;
						case '*':
							total=n1*n2;
							break;
						case '/':
							if(n2!=0)
								{
								total=n1/n2;
								break;	
								}
							else
								{
								cout<<"\nError matematico\n";
								}
							
						default:
							cout<<"\nOpcion no valida\n";
							break;
					} //Fin de switch o estructura de decision multiple.
			cout<<"\nEl acumulado es: "<<total;
			n1=total;
			} //Cierre del verdadero
			else
			{
				cout<<"\nFin de ejecucion del programa";
				cout<<"\nEl ultimo acumulado es: "<<total;
			} //Cierrre del falso
		} // Fin del do
	while(opc!='s');
}
