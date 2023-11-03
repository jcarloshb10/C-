#include<iostream>
using namespace std;
main()
{
	double multiplicando, inicio_md, final_md, cambio_md, multiplicador, inicio_mdr, final_mdr, cambio_mdr, resultado;
	cout<<"Tabla de multiplicacion\n";
	cout<<"Ingresa el valor de inicio del multiplicando\n";
	cin>> inicio_md;
	cout<<"Ingresa el valor final del multiplicando\n";
	cin>>final_md;
	cout<<"Ingresa el valor de cambio del multiplicando\n";
	cin>>cambio_md;
	cout<<" ";
	cout<<"Ingresa el valor de inicio del multiplicador\n";
	cin>> inicio_mdr;
	cout<<"Ingresa el valor final del multiplicador\n";
	cin>>final_mdr;
	cout<<"Ingresa el valor de cambio del multiplicador\n";
	cin>>cambio_mdr;
	cout<<" ";
	if (inicio_md<final_md and inicio_mdr<= final_mdr);
	{
		if(cambio_md>0 and cambio_mdr>0);
			{
				for(multiplicando=inicio_md; multiplicando<=final_md; multiplicando += cambio_md)
					{
						if ((multiplicando<-1 or multiplicando>1) and (multiplicando !=10) and (multiplicando !=-10));
							{
								cout<<"Tabla del ", multiplicando;
								for(multiplicador=inicio_mdr; multiplicador<=final_mdr; multiplicador += cambio_mdr)
									{
										if(multiplicador<-1 or multiplicador>1);
											{
												resultado= multiplicando*multiplicador;
												cout<<multiplicando, " * ", multiplicador, " = ", resultado;
											}
									}
								
							}
						system("pause");		
					}
			}
		else
		{
			cout<<"ERROR en el valor de cambio";
		}
		
	}

}
