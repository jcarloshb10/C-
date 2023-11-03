#include<fstream>

struct cuenta
{
	unsigned long cedula;
	char nombre[100];	
	unsigned long saldo;
	cuenta *sig;
};

cuenta *ini;
cuenta *fin;
cuenta *usuario; //aqui se guardara la busqueda
void enlazarcuenta(cuenta *&aux, cuenta *&ini, cuenta *&fin)
{
	aux->sig=NULL;
	if(ini==NULL)
	{
		ini=aux;	
		fin=aux;
	}
	else
	{
		fin->sig=aux;
		fin=aux;			
	}
}



void validararchivo()
{
	fstream cuentas;
	cuentas.open("cuentas.dat",ios::in|ios::binary);
	if (cuentas.fail()) 
	{		
		cuentas.open("cuentas.dat",ios::out|ios::binary);
	}
	cuentas.close();
}

void leerarchivo()
{
	fstream cuentas;
	validararchivo();
	ini=NULL;
	cuenta *aux; 
	cuentas.open("cuentas.dat",ios::in|ios::binary);
	while (!cuentas.eof())
	{
		aux=new cuenta; 
		cuentas.read((char*)aux,sizeof(cuenta));
		if(cuentas.good())
		{
			enlazarcuenta(aux, ini, fin);
		}		
	}
	cuentas.close();
}

cuenta *buscar(unsigned long cedula)
{
	usuario=NULL;
	leerarchivo();
	cuenta *aux=ini;
	while(aux!=NULL)
	{
		if(cedula==aux->cedula)
		{
			usuario=aux;
			break;
		}
		aux=aux->sig;
	}	
	return(usuario);
}

void limpiararchivo()
{
	fstream cuentas;	
	cuentas.open("cuentas.dat",ios::out|ios::binary);
	cuentas.close();
}

void cargaralarchivo()
{
	fstream cuentas;
	validararchivo();
	cuentas.open("cuentas.dat",ios::app|ios::binary);
	cuenta *aux=ini;
	while(aux!=NULL)
	{
		cuentas.write((char*)aux,sizeof(cuenta));
		aux=aux->sig;			
	}	
	cuentas.close();
}

void listar()
{
	system("cls");
	cout<<"listar"<<endl;
	leerarchivo();
	cuenta *aux=ini;
	while(aux!=NULL)
	{
		cout<<aux->cedula<<endl;
		cout<<aux->nombre<<endl;
		cout<<aux->saldo<<endl;
		cout<<endl;
		aux=aux->sig;
	}
}
