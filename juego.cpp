#include <iostream>
#include <cstdlib> // permite manejar los comandos srand() y ran()
#include <ctime> // permite manejar el comando time (0) 
#include <cstring>
using namespace std; 

int main ()
{
	char entrada [11], secuencia [11], digito_c; 
	long digito_n, posicion_va, posicion_re, fijas, picas, n_oportunidad; 
	bool existe, logrado, correcto; 
	
	//generacion de umeros aleatorios 
	
	srand(time(0)); 
	
	posicion_va=0; 
	while (posicion_va < 5)
	{
		existe=true; 
		while (existe)
		{
			existe=false;  
			digito_n = rand()%10; //generacion de un numero aleatorio 
			
			digito_c = digito_n +48; //conversion de un valor numerico 
			
			//verificacion de no repeticion de digitos 
			for (posicion_re=0; posicion_re<6; posicion_re++)
			{
				if (secuencia[posicion_re]==digito_c)
				{
					existe=true; 
				}
			} 
		}
		secuencia [posicion_va]=digito_c; 
		posicion_va++; 
	}
	secuencia[5]='\0'; 
	cout<<secuencia<<endl;
	
	//control de la secuencia ingresada por el jugador 
	
	n_oportunidad=0; 
	logrado=false; 
	while (!logrado)
	{
		picas=0; 
		fijas=0; 
		correcto=false; 
		while(!correcto)
		{
			correcto=true; 
			cout<< endl << "ingrese tu secuencia, maximo 5 digitos "; 
			cin.getline(entrada,sizeof(entrada)-1); 
			entrada[5]='\0'; 
			
			//verificacion de que solo entran nùmeros en la secuencia 
			for(posicion_va=0; posicion_va<5; posicion_va++)
			{
				if(entrada[posicion_va]<48 or entrada [posicion_va]>57)
				{
					correcto=false; 
				}
			}
			// verificacion de que los digitos no se repiten en la secuencia 
			if(correcto)
			{
				for(posicion_va=0; posicion_va<5; posicion_va++)
				{
					for(posicion_re=posicion_va+1; posicion_re<5;posicion_re++)
					{
						if(entrada[posicion_va]==entrada[posicion_re])
						{
							correcto=false; 
						}
					}
				}
			}
			if(!correcto)
			{
				cout<<"la secuencia esta incorrecta, "<<endl; 
			    cout<<"faltan digitos, se repiten digitos o hay caracteres no validos. "; 
				cout<<endl; 
			}
		}
		//conteo de picas i fijas en la secuencia ingresada
		posicion_va=0; 
		posicion_re=0; 
		for(posicion_va=0; posicion_va<5;posicion_va++)
		{
			for(posicion_re=0; posicion_re<5;posicion_re++)
			{
				if(secuencia[posicion_va]==entrada[posicion_re])
				{
					if(posicion_va==posicion_re)
					{
						fijas++; 
					}
					else
					{
						picas++; 
					}
				}
			}
		}
		if(fijas==5)
		{
			logrado=true; 
		}
		else 
		{
			cout<<entrada<<"... tienes" << fijas << "FIJAS y" << picas << "PICAS \n"; 
		}
		n_oportunidad++; 
	}
	cout<< endl << "FELICITACIONES  lo lograstes en: "<< n_oportunidad<< "oportunidades"; 	 
	
}
