#include<iostream>
#include<conio.h>
//#include "d:/conio/include/conio.h"        equipo 1     equipo 2    equipo n
#include<ctype.h>                            //por        por          por
#include<math.h>							//jug2        jug2         jug2
#include<string.h>
#include<time.h>
#include<stdlib.h>
											
using namespace std;						//      equipo 1     equipo 2    equipo n
											// def   4               3         4
void menu();								//         equipo 1       equipo 2        equipo n
											// entren   zz            pekerman         juan
void ingr_nombre_credito();
void ingr_nomina_entrenador();
void alineaciones();

void mostrar_nomina_tecnico();
void cambios_transferencias();
void cambio_nom_equipo();
void cambio_nom_jugadores();
void cambio_nom_entrenadores();
void apuestas();
void apuesta_campeon_liga();
void estadistica_liga();
void apuesta_gan_partido();
void valor_a_apostar();
void reporte_apuestas();
void reporte_partidos();
void simular_partido();
void resultados_partido();
void reporte_usuario();

struct jugador
{
	char nom[50];
	int identificacion;
	int credito;
	char jugadas[50][50];
	int puntos[50][50];      /////////////////////////////////
	int gol_contra[50][50];   ////////////////////////////////
	int gol_favor[50][50];  /////////////////////////////////
	int diferencia_gol[50][50];   /////////////////////////////////
	
	jugador *psig;
	
};

jugador *pini=NULL;
jugador *pfin=NULL;
jugador *paux;



struct equipos
{
	
	char nom_team[50];
	char entrenador[50];
	char jugadores[50];
	int def,medc,del;
	
	equipos *psig;
	
};

equipos **nomina_e;


struct apuesta
{
	int val_apuesta[50];
	
};

apuesta *pini_a=NULL;
apuesta *pfin_a=NULL;
apuesta *paux_a;

struct partidos
{
	int partidas[50][50];
	
};



partidos *pini_v=NULL;
partidos *pfin_v=NULL;
partidos *paux_v;

void creditos();
void terminar_programa();
void colocar_borde(int x1, int y1, int x2, int y2);
void colocar_ventanas(int x1,int y1, int x2,int y2,int col_fondo, int col_tex);

int formacion;

int cont_registro=0,cont_equipo=0;
char busc_nom_equipo[50];
int cont7=0,cont6=0,amistoso=0,cont9=0;  ///////////////////////////////// cont9 es global
char busc_nom_entrenador[50];


int main() 
{
	system("mode con:cols=102lines=32");
	system("cls");
	colocar_ventanas(1,1,102,5,4,14);
	colocar_borde(1,1,102,5);
	gotoxy(49,3);cout<<"FUTSOFT";

	
	menu();
	getch();
}

void menu()
{
	nomina_e  = new equipos *[15];
	nomina_e[0] = new equipos[15];
	
	char opcion[2];
	do
	{
		colocar_ventanas(1,6,102,32,1,15);
		colocar_borde(1,1,102,26);
		gotoxy(49,3);cout<<"MEN"<<(char)233;	
		
		colocar_ventanas(21,11,82,27,15,0);
		colocar_borde(1,1,62,17);
		gotoxy(3,16);cout<<"HAY "<<cont_equipo<<" EQUIPO(S) CREADOS";
		gotoxy(2,2);cout<<" A) INGRESAR NOMBRE O APODO (USUARIO) Y CREDITO";
		gotoxy(2,3);cout<<" B) INGRESAR NOMINA (EQUIPO) DE  JUGADORES Y ENTRENADOR";
		gotoxy(2,4);cout<<" C) MOSTRAR EQUIPO Y ENTRENADOR";
		gotoxy(2,5);cout<<" D) REALIZAR CAMBIOS O TRANSFERENCIAS";
		gotoxy(2,6);cout<<" E) REALIZAR APUESTAS";
		gotoxy(2,7);cout<<" F) SIMULAR PATIDO";
		gotoxy(2,8);cout<<" G) RESULTADOS DEL PARTIDO";		
		gotoxy(2,9);cout<<" H) REPORTE DE RESULTADOS";
		gotoxy(2,10);cout<<" I) CR"<<(char)144<<"DITOS";
		gotoxy(2,11);cout<<" X) SALIR";
		gotoxy(2,13);cout<<" DIGITE OPCI"<<(char)224<<"N: ";
		cin>>opcion;
		opcion[0]=tolower(opcion[0]);
		cin.ignore();
		if(opcion[1]=='\0')
		{
			switch(opcion[0])
	    	{
	    		case 'a':
	        		ingr_nombre_credito(); 
	        	break;
	    		case 'b':
	        		alineaciones(); 
	        	break;
	    		case 'c':
	        		mostrar_nomina_tecnico();
	        	break;
	        	case 'd':
	        		cambios_transferencias();
	        	break;
	        	case 'e':
	        		apuestas();
	        	break;
	        	case 'f':
	        		simular_partido();
	        	break;
	        	case 'g':
	        		resultados_partido();
	        	break;
	        	case 'h':
	        		reporte_usuario();
	        	break;
	    		case 'i':
	        		creditos();
	        	break;
	        	case 'x':
					terminar_programa();
				break;
				default:
					gotoxy(18,14);cout<<"OPCI"<<(char)224<<"N NO V"<<(char)181<<"LIDA, VUELVA A DIGITAR";
				
					getch();
	    		break;
	    	}
		}
		else
		{
			gotoxy(18,14);cout<<"OPCI"<<(char)224<<"N NO V"<<(char)181<<"LIDA, VUELVA A DIGITAR";
				
			getch();
		}

	}while(opcion[0]!='x' );
}

void ingr_nombre_credito()
{
	int creditoini,iden,cont=0;
	cont_registro++;
	

	
	if(cont_registro==1)
	{
	paux = new jugador;
	
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"REGISTRAR JUGADOR";
	
	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);	
	gotoxy(4,4);cout<<"NOMBRE:";
	gotoxy(12,4);cin.getline(paux->nom,49,'\n');
	gotoxy(4,6);cout<<"IDENTIFICACION:";
	gotoxy(21,6);cin>>paux->identificacion;
	
	
	do
	{
		gotoxy(4,8+cont);cout<<"CREDITO INICIAL EN EUROS (Minimo 10):";
		gotoxy(43,8+cont);cout<<"$ ";cin>>paux->credito;
			
		
		if(paux->credito<10)
		{
			gotoxy(60,8+cont);cout<<" NO V"<<(char)181<<"LIDO, VUELVA A DIGITAR";
			cont++;
		}
		else	
		{
			main();
		}
		
	}while(creditoini<10);
	
	paux -> psig =NULL;
	
	}
	else
	{
		colocar_ventanas(1,6,102,32,3,11);
		colocar_borde(1,1,102,26);
		gotoxy(40,3);cout<<"USUARIO REGISTRADO";
		
		colocar_ventanas(5,10,97,28,15,0);
		colocar_borde(1,1,93,19);
		gotoxy(6,3);cout<<"YA HA REGISTRADO UN USUARIO: "<<paux->nom;
		gotoxy(6,5);cout<<"YA HA INGRESADO SU CREDITO: $ "<<paux->credito;
		getch();
	}

		
}


void alineaciones()
{

	if(cont_registro!=0)
	{
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(36,3);cout<<"FORMACION O ALINEACION DEL EQUIPO";
	
	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);	
		
	gotoxy(28,2);cout<<"FORMACIONES (DEFENSA - MEDIOS - DELANTEROS)";

	gotoxy(6,3);cout<<"1) 4-4-2 A";gotoxy(29,3);cout<<"2) 4-3-3";gotoxy(52,3);cout<<"3) 3-4-3";gotoxy(75,3);cout<<"4) 4-5-1";
		

	colocar_ventanas(9,13,26,18,10,1);
	colocar_borde(1,1,18,6);
	gotoxy(2,3);cout<<(char)220;
	gotoxy(6,2);cout<<(char)254;
	gotoxy(6,3);cout<<(char)254;
	gotoxy(6,4);cout<<(char)254;
	gotoxy(6,5);cout<<(char)254;
	gotoxy(10,2);cout<<(char)254;
	gotoxy(10,3);cout<<(char)254;
	gotoxy(10,4);cout<<(char)254;
	gotoxy(10,5);cout<<(char)254;
	gotoxy(14,3);cout<<(char)254;
	gotoxy(14,4);cout<<(char)254;
	
	
	colocar_ventanas(32,13,49,18,10,2);
	
	colocar_borde(1,1,18,6);
	gotoxy(2,3);cout<<(char)220;
	gotoxy(6,2);cout<<(char)254;
	gotoxy(6,3);cout<<(char)254;
	gotoxy(6,4);cout<<(char)254;
	gotoxy(6,5);cout<<(char)254;
	gotoxy(10,2);cout<<(char)220;
	gotoxy(10,3);cout<<(char)220;
	gotoxy(10,4);cout<<(char)220;
	gotoxy(14,2);cout<<(char)220;
	gotoxy(14,3);cout<<(char)220;
	gotoxy(14,4);cout<<(char)220;
	
	
	colocar_ventanas(55,13,72,18,10,3);
	
	colocar_borde(1,1,18,6);
	gotoxy(2,3);cout<<(char)220;
	gotoxy(6,2);cout<<(char)220;
	gotoxy(6,3);cout<<(char)220;
	gotoxy(6,4);cout<<(char)220;
	gotoxy(10,2);cout<<(char)254;
	gotoxy(10,3);cout<<(char)254;
	gotoxy(10,4);cout<<(char)254;
	gotoxy(10,5);cout<<(char)254;
	gotoxy(14,2);cout<<(char)220;
	gotoxy(14,3);cout<<(char)220;
	gotoxy(14,4);cout<<(char)220;
	
	colocar_ventanas(78,13,95,18,10,4);
	
	colocar_borde(1,1,18,6);
	gotoxy(2,3);cout<<(char)220;
	gotoxy(6,2);cout<<(char)254;
	gotoxy(6,3);cout<<(char)254;
	gotoxy(6,4);cout<<(char)254;
	gotoxy(6,5);cout<<(char)254;
	gotoxy(9,3);cout<<(char)254;
	gotoxy(9,4);cout<<(char)254;
	gotoxy(12,2);cout<<(char)220;
	gotoxy(12,3);cout<<(char)220;
	gotoxy(12,4);cout<<(char)220;
	gotoxy(15,3);cout<<(char)220;
	

		
		colocar_ventanas(50,23,95,26,10,1);
		colocar_borde(1,1,32,3);
		gotoxy(3,2);cout<<"DIGITE ALINEACION DEL EQUIPO:";gotoxy(34,2);cin>>formacion;
		cin.ignore();
		
		ingr_nomina_entrenador();
	}
	else
	{
		gotoxy(6,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA INGRESADO UN USUARIO.";
		getch();	
	}
	
	
}


void ingr_nomina_entrenador()
{
	int cont=0;
	int i=0;
	
	cont_equipo++;
		
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(30,2);cout<<"REGISTRAR NOMINA DE JUGADORES Y ENTRENADOR ";
	gotoxy(26,3);cout<<"(Las Posiciones de los jug. van de izquierda a derecha)";
	
	colocar_ventanas(5,10,97,29,15,0);
	colocar_borde(1,1,93,20);	
	gotoxy(4,2);cout<<"NOMBRE DEL EQUIPO:"<<cont_equipo;
	gotoxy(24,2);cin.getline(nomina_e[0][cont_equipo-1].nom_team,49,'\n');
	gotoxy(4,3);cout<<"NOMBRE DEL ENTRENADOR:";
	gotoxy(31,3);cin.getline(nomina_e[0][cont_equipo-1].entrenador,49,'\n');
	gotoxy(4,4);cout<<"NOMBRE DEL PORTERO:";
	gotoxy(28,4);cin.getline(nomina_e[0][cont_equipo-1].jugadores,49,'\n');
	cont++;
	
	if(formacion==1)
	{
		nomina_e[0][cont_equipo-1].def=4;
		nomina_e[0][cont_equipo-1].medc=4;
		nomina_e[0][cont_equipo-1].del=2;
	}
	if(formacion==2)
	{
		nomina_e[0][cont_equipo-1].def=4;
		nomina_e[0][cont_equipo-1].medc=3;
		nomina_e[0][cont_equipo-1].del=3;
	}
	if(formacion==3)
	{
		nomina_e[0][cont_equipo-1].def=3;
		nomina_e[0][cont_equipo-1].medc=4;
		nomina_e[0][cont_equipo-1].del=3;
	}
	if(formacion==4)
	{
		nomina_e[0][cont_equipo-1].def=4;
		nomina_e[0][cont_equipo-1].medc=5;
		nomina_e[0][cont_equipo-1].del=1;
	}
	if(formacion==5)
	{
		nomina_e[0][cont_equipo-1].def=4;
		nomina_e[0][cont_equipo-1].medc=4;
		nomina_e[0][cont_equipo-1].del=2;
	}
	
	
	
	gotoxy(50,3);cout<<"->HAY "<<cont<<" JUGADOR(ES)";
	for(i=0;i<10;i++)
	{ 
		//nomina_e[cont] = new equipos[cont_equipo-1];   /////////////-1
		
		gotoxy(4,6+i);cout<<"JUGADORES#  "<<i+1;
		gotoxy(28,6+i);cin.getline(nomina_e[cont][cont_equipo-1].jugadores,49,'\n');
	
		cont++;
		gotoxy(50,3);cout<<"-> HAY "<<cont<<" JUGADOR(ES)";
		
	}
		

	getch();
}

void mostrar_nomina_tecnico()
{
	int i,j,cont2=0,pos=0,cont_let=0,aux;
	
	if(cont_registro!=0 && cont_equipo!=0)
	{
		colocar_ventanas(1,6,102,32,3,11);
		colocar_borde(1,1,102,26);
		gotoxy(34,3);cout<<"NOMINA DEL EQUIPO (NOMBRE): ";cin.getline(busc_nom_equipo,49,'\n');
		
	
		for(i=0;i<cont_equipo;i++)
		{
			
			for(j=0;j<strlen(nomina_e[0][i].nom_team);j++)
			{
				if(busc_nom_equipo[j]==nomina_e[0][i].nom_team[j])
				{
					cont_let++;
				}			
				else
				{
					cont_let--;
				}
			}
			if(cont_let==strlen(busc_nom_equipo))
			{
				aux=1;
				pos=i;
				i=cont_equipo+1;
				
			}
			cont_let=0;
		}
		
		if(pos>=0 && aux==1)
		{
			colocar_ventanas(5,10,97,29,15,0);
			colocar_borde(1,1,93,20);
	
			gotoxy(4,2);cout<<"ENTRENADOR: "<<nomina_e[cont2][pos].entrenador;
			gotoxy(4,4);cout<<"POR: "<<nomina_e[cont2][pos].jugadores;
			cont2++;
			i=0;
			for(i=0;i<nomina_e[0][cont_equipo-1].def;i++)
			{
				gotoxy(4,6+i);cout<<"DEF: "<<nomina_e[cont2][pos].jugadores;
				cont2++;
			}
			for(i=0;i<nomina_e[0][cont_equipo-1].medc;i++)
			{
				gotoxy(4,11+i);cout<<"MED: "<<nomina_e[cont2][pos].jugadores;
				cont2++;
			}
			for(i=0;i<nomina_e[0][cont_equipo-1].del;i++)
			{
				gotoxy(4,17+i);cout<<"DEL: "<<nomina_e[cont2][pos].jugadores;
				cont2++;
			}
			getch();			
		}
		else
		{
			colocar_ventanas(5,10,97,29,15,0);
			colocar_borde(1,1,93,20);
			
			gotoxy(10,5);cout<<"NO HAY UN EQUIPO CON ESE NOMBRE";
			getch();
		}
		
	}
	else
	{
		if(cont_registro==0 && cont_equipo==0)
		{
			gotoxy(4,15);cout<<"NO V"<<(char)181<<"LIDO PORQUE NO HA INGRESADO UN USUARIO, NI EQUIPO.";
		}
		else
		{
			if(cont_registro==0)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA INGRESADO UN USUARIO.";
			}
			if(cont_equipo==0)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA CREADO UN EQUIPO.";
			}			
		}

			getch();
	}


}

void cambios_transferencias()
{
	int i,opc_equip,cont2=0,opc_cam_jug;
	char opcion[2];
	
	if(cont_registro!=0 && cont_equipo!=0)
	{
		colocar_ventanas(1,6,102,32,3,11);
		colocar_borde(1,1,102,26);
		gotoxy(46,3);cout<<"MODIFICAR";	

			colocar_ventanas(15,10,88,30,15,0);
			colocar_borde(1,1,74,21);
				
		gotoxy(2,2);cout<<" A) CAMBIO NOMBRE DEL EQUIPO";
		gotoxy(2,3);cout<<" B) CAMBIO NOMBRE DE JUGADOR";
		gotoxy(2,4);cout<<" C) CAMBIO NOMBRE DE ENTRENADOR";
		gotoxy(2,6);cout<<" DIGITE OPCI"<<(char)224<<"N: ";	
					
			cin>>opcion;
			opcion[0]=tolower(opcion[0]);
			cin.ignore();
			switch(opcion[0])
	    	{
	    		case 'a':
	        		cambio_nom_equipo(); 
	        	break;
	    		case 'b':
	        		cambio_nom_jugadores(); 
	        	break;
	    		case 'c':
	        		cambio_nom_entrenadores();
	        	break;
				default:
					gotoxy(18,14);cout<<"OPCI"<<(char)224<<"N NO V"<<(char)181<<"LIDA, VUELVA A DIGITAR";
					
					getch();
					cambios_transferencias();
	    		break;
	    	}
			
	}
	else
	{
		if(cont_registro==0 && cont_equipo==0)
		{
			gotoxy(4,15);cout<<"NO V"<<(char)181<<"LIDO PORQUE NO HA INGRESADO UN USUARIO, NI EQUIPO.";
		}
		else
		{
			if(cont_registro==0)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA INGRESADO UN USUARIO.";
			}
			if(cont_equipo==0)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA CREADO UN EQUIPO.";
			}			
		}

		
	}	
	getch();
}


void cambio_nom_equipo()
{
	int i,j,cont_let2=0,aux2=0,pos2=0;
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"MODIFICAR NOMBRE DE EQUIPOS";	
	
	
	
	colocar_ventanas(15,10,88,30,15,0);
	colocar_borde(1,1,74,21);
	
	gotoxy(4,3);cout<<"NOMBRE DEL EQUIPO A MODIFICAR: ";cin.getline(busc_nom_equipo,49,'\n');
	
		for(i=0;i<cont_equipo;i++)
		{
			
			for(j=0;j<strlen(nomina_e[0][i].nom_team);j++)
			{
				if(busc_nom_equipo[j]==nomina_e[0][i].nom_team[j])
				{
					cont_let2++;
				}			
				else
				{
					cont_let2--;
				}
			}
			if(cont_let2==strlen(busc_nom_equipo))
			{
				aux2=1;
				pos2=i;
				i=cont_equipo+1;
				
			}
			cont_let2=0;
		}
		
		if(pos2>=0 && aux2==1)
		{
			gotoxy(4,5);cout<<"EQUIPO: "<<nomina_e[0][pos2].nom_team;
			
			gotoxy(4,7);cout<<"NOMBRE SUSTITUTO: ";cin.getline(nomina_e[0][pos2].nom_team,49,'\n');
			
			gotoxy(4,9);cout<<"CAMBIO EXITOSO";
		}
		else
		{
		
			gotoxy(4,5);cout<<"NO HAY UN EQUIPO CON ESE NOMBRE";
			gotoxy(4,6);cout<<"DEBE VOLVER A INTENTAR";
			getch();
			cambio_nom_equipo();
		}
	
}

void cambio_nom_jugadores()
{
	int i,j,k,aux3=0,pos3=0,cont_let3=0,aux5=0;
	char busc_nom_jugadores[50];
	

	
	
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"MODIFICAR NOMBRE DE JUGADORES";	

	colocar_ventanas(15,10,88,30,15,0);
	colocar_borde(1,1,74,21);
	
	gotoxy(4,3);cout<<"NOMBRE DEL JUGADOR A MODIFICAR: ";cin.getline(busc_nom_jugadores,49,'\n');
	
	
		for(i=0;i<cont_equipo;i++)
		{

			for(k=0;k<11;k++)
			{
				
				for(j=0;j<strlen(nomina_e[k][i].jugadores);j++)
				{
					
					if(busc_nom_jugadores[j]==nomina_e[k][i].jugadores[j])
					{
						cont_let3++;
					}			
					else
					{
						cont_let3--;
					}
				}			
				if(cont_let3==strlen(busc_nom_jugadores))
				{
					aux5=k;
					aux3=1;
					pos3=i;
					k=12;
					i=cont_equipo+1;
				}
			cont_let3=0;	
			}			
			
		}
		
		if(pos3>=0 && aux3==1)
		{
			gotoxy(4,5);cout<<"JUGADOR: "<<nomina_e[aux5][pos3].jugadores;
			
			gotoxy(4,7);cout<<"NOMBRE SUSTITUTO: ";cin.getline(nomina_e[aux5][pos3].jugadores,49,'\n');
			
			gotoxy(4,9);cout<<"CAMBIO EXITOSO";
		}
		else
		{
		
			gotoxy(4,5);cout<<"NO HAY UN JUGADOR CON ESE NOMBRE";
			gotoxy(4,6);cout<<"DEBE VOLVER A INTENTAR";
			getch();
			cambio_nom_jugadores();
		}
	
}



void cambio_nom_entrenadores()
{
	int i,j,aux4=0,pos4=0,cont_let4=0;
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"MODIFICAR NOMBRE DE TECNICOS";	
	
	
	colocar_ventanas(15,10,88,30,15,0);
	colocar_borde(1,1,74,21);
	
	gotoxy(4,3);cout<<"NOMBRE DEL TECNICO A MODIFICAR: ";cin.getline(busc_nom_entrenador,49,'\n');
	
		for(i=0;i<cont_equipo;i++)
		{
		
			
			for(j=0;j<strlen(nomina_e[0][i].entrenador);j++)
			{
				if(busc_nom_entrenador[j]==nomina_e[0][i].entrenador[j])
				{
					cont_let4++;
				}			
				else
				{
					cont_let4--;
				}
			}
			if(cont_let4==strlen(busc_nom_entrenador))
			{
				aux4=1;
				pos4=i;
				i=cont_equipo+1;
			}
			cont_let4=0;
		}
		
		if(pos4>=0 && aux4==1)
		{
			gotoxy(4,5);cout<<"ENTRENADOR: "<<nomina_e[0][pos4].entrenador;
			
			gotoxy(4,7);cout<<"NOMBRE SUSTITUTO: ";cin.getline(nomina_e[0][pos4].entrenador,49,'\n');
			
			gotoxy(4,9);cout<<"CAMBIO EXITOSO";
		}
		else
		{
		
			gotoxy(4,5);cout<<"NO HAY UN ENTENADOR CON ESE NOMBRE";
			gotoxy(4,6);cout<<"DEBE VOLVER A INTENTAR";
			getch();
			cambio_nom_entrenadores();
		}
	
}



void apuestas()
{
	char opcion[2];
	colocar_ventanas(1,6,102,32,1,15);
	colocar_borde(1,1,102,26);
	gotoxy(47,3);cout<<"APUESTAS";	
		
	colocar_ventanas(21,11,82,27,15,0);
	colocar_borde(1,1,62,17);
	
	if(cont_registro>0 && cont_equipo>=2)  ////////////////////////// 2 equipos minimo para ya apostar
	{
	gotoxy(2,2);cout<<" A) APOSTAR POR CAMPEON DE LIGA";
	gotoxy(2,3);cout<<" B) APOSTAR POR GANADOR DE PARTIDO";
	gotoxy(2,5);cout<<" DIGITE OPCI"<<(char)224<<"N: ";	
					
			cin>>opcion;
			opcion[0]=tolower(opcion[0]);
			cin.ignore();
			switch(opcion[0])
	    	{
	    		case 'a':
	        		apuesta_campeon_liga(); 
	        	break;
	    		case 'b':
	        		apuesta_gan_partido(); 
	        	break;
				default:
					gotoxy(18,14);cout<<"OPCI"<<(char)224<<"N NO V"<<(char)181<<"LIDA, VUELVA A DIGITAR";
					getch();
					apuestas();
	    		break;
	    	}
	}
	else
	{
		if(cont_registro==0 && cont_equipo==0)
		{
			gotoxy(4,15);cout<<"NO V"<<(char)181<<"LIDO PORQUE NO HA INGRESADO UN USUARIO, NI EQUIPO.";
		}
		else
		{
			if(cont_registro==0)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA INGRESADO UN USUARIO.";
			}
			if(cont_equipo==0)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA CREADO UN EQUIPO.";
			}	
			if(cont_equipo==1)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA SOLO HAY " <<cont_equipo<<" EQUIPO";
			}		
		}

		
	}
	
	
	
	getch();
}



void apuesta_campeon_liga()
{
	int i,cont3=0,equipo_apostado=0,gol_local,gol_visitante;  //////////gol_local y gol_visitante son variables locales
	
	jugador *paux; //separar espacio
	paux = new jugador;
	
	
	colocar_ventanas(1,6,102,32,1,15);
	colocar_borde(1,1,102,26);
	gotoxy(47,3);cout<<"APUESTAS POR CAMPEON DE LIGA";	
		
	colocar_ventanas(21,11,82,27,15,0);
	colocar_borde(1,1,62,17);
	
	if(cont_equipo>=4)       ////////////////////// 4 equipos minimo para liga
	{
		
		for(i=0;i<cont_equipo;i++)
		{
			gotoxy(4+(12*i),2);cout<<i+1<<") "<<nomina_e[0][i].nom_team;
		}
		gotoxy(4,3);cout<<"DIGITE EL NUMERO DEL EQUIPO AL QUE APUESTA: ";
		cin>>equipo_apostado;
		
		cin.ignore();
		paux->jugadas[cont7][2]=equipo_apostado;  ///// en la posicion tercera 2+1 se guarda el numero de mi equipo
		
		valor_a_apostar();
		
		gotoxy(4,5);cout<<"juego de  la liga predeterminada";
		
		int y=0;
		srand(time(0));
		for (int i =0; i< cont_equipo;i++)
		{
		
			
			for (int j=i; j<cont_equipo-1 ;j++)
			{
					gol_local=0+rand()%(10);
							
					gol_visitante=0+rand()%(10);	
					
				gotoxy(4,7+y);cout<<nomina_e[0][i].nom_team<<" ("<<gol_local<<")"<<" VERSUS "<<"("<<gol_visitante<<") "<<nomina_e[0][j+1].nom_team;
	
				
		
				if(gol_local>gol_visitante)
				{
					
					gotoxy(40,7+y);cout<<"Ganador "<<nomina_e[0][i].nom_team<<" + 3 pts";
					
					paux->puntos[cont9][i] =paux->puntos[cont9][i]+3;      ///////////////////////////////
					paux->gol_favor[cont9][i] += gol_local;      /////////////////////////////////
					paux->gol_contra[cont9][i] += gol_visitante;     /////////////////////////////////
					paux->gol_favor[cont9][j+1] += gol_visitante; /////////////////////////////////
					paux->gol_contra[cont9][j+1] +=gol_local ;   /////////////////////////////////
					
				}
				if(gol_visitante>gol_local)
				{
					
					gotoxy(40,7+y);cout<<"Ganador "<<nomina_e[0][j+1].nom_team<<" + 3 pts";
					paux->puntos[cont9][j+1] =paux->puntos[cont9][j+1]+3;     /////////////////////////////////
					paux->gol_favor[cont9][j+1] += gol_visitante;  /////////////////////////////////
					paux->gol_contra[cont9][j+1] += gol_local;  /////////////////////////////////
					paux->gol_favor[cont9][i] += gol_local;     /////////////////////////////////
					paux->gol_contra[cont9][i] += gol_visitante;   /////////////////////////////////
				}
				if(gol_visitante==gol_local)
				{
					
					gotoxy(40,7+y);cout<<"Empate "<<" + 1 pts c/u";
					paux->puntos[cont9][i] =paux->puntos[cont9][i]+1;   /////////////////////////////////
					paux->puntos[cont9][j+1] =paux->puntos[cont9][j+1]+1;   /////////////////////////////////
					paux->gol_favor[cont9][i] += gol_local;    /////////////////////////////////
					paux->gol_contra[cont9][i] += gol_visitante;    /////////////////////////////////
					paux->gol_favor[cont9][j+1] += gol_visitante;    /////////////////////////////////
					paux->gol_contra[cont9][j+1] += gol_local;   /////////////////////////////////				
				}
				
				
				
				y++;
				
				
				
			}
			
			
			
			y++;
			
		}
		
		getch();
		
		estadistica_liga();	
	
	}
	else
	{
		gotoxy(5,5);cout<<"NO PUEDE APOSTAR POR LIGA PORQUE SOLO HAY "<<cont_equipo<<" EQUIPO(S) CREADO(S), MINIMO 4 EQUIPOS";
	}

	
	
	
	getch();
}

void estadistica_liga()
{
	
	paux = new jugador;
	paux_a = new apuesta;
	

	
	int y=0;
	colocar_ventanas(1,6,102,60,1,15);
	colocar_borde(1,1,102,54);
	gotoxy(47,3);cout<<"ESTADISTICAS  DE LIGA";	
	colocar_ventanas(21,10,82,49,15,0);
	colocar_borde(1,1,62,40);
	
	
	
	int mayor = paux->puntos[0][0];  /////////////////////////////////
		
		int ganador;
		
		gotoxy(5,3);cout<<"Equipo";	
		gotoxy(20,3);cout<<"goles a favor";
		gotoxy(44,3);cout<<"goles en contra";
		
		while(paux!=NULL)
		{
			gotoxy(5,5+y);cout<<nomina_e[0][y].nom_team;
			gotoxy(28,5+y);cout<<paux->gol_favor[cont9][y];  /////////////////////////////////
			gotoxy(52,5+y);cout<<paux->gol_contra[cont9][y];   /////////////////////////////////
			paux->diferencia_gol[cont9][y]=paux->gol_favor[cont9][y]-paux->gol_contra[cont9][y];  /////////////////////////
			y++;
		}
		
		int x=0;
		paux = new jugador;
		while(paux!=NULL)
		{
			gotoxy(10,11+y);cout<<nomina_e[0][x].nom_team<<"  Obtubo  "<<paux->puntos[cont9][x]<<" Puntos ";   /////////////////////////////////
			y++;
			if (paux->puntos[cont9][x+1] > mayor)   
			{
				mayor = paux->puntos[cont9][x+1];   /////////////////////////////////
				ganador = x+1;
			} 
			if(paux->puntos[cont9][x+1] == mayor)
			{
				if(paux->diferencia_gol[cont9][x+1]>paux->diferencia_gol[cont9][0])
				{
					mayor = paux->puntos[cont9][x+1];
					ganador = x+1;	
				}
				else
				{
					mayor = paux->puntos[cont9][0];
					ganador = 0;			
				}
			}
			
			paux=paux->psig; 
			x++;
				
		}
		paux->jugadas[cont7][3]=ganador+1;   /////////////////////////////////
		
		if(paux->jugadas[cont7][2]==paux->jugadas[cont7][3])   
		{
			gotoxy(4,12);cout<<" GANADOR:  "<<nomina_e[0][ganador].nom_team<<" ...  HAS GANADO";
			gotoxy(4,13);cout<<"SE TE PAGARA "<<paux_a-> val_apuesta[cont7]<<" X #EQUIPOS = "<<paux_a->val_apuesta[cont7]*cont_equipo<<" EUROS";
			paux->credito=paux->credito+(paux_a->val_apuesta[cont7]*cont_equipo);						
		}
		else
		{
			gotoxy(4,12);cout<<" GANADOR:  "<<nomina_e[0][ganador].nom_team<<" ...  HAS PERDIDO";
		}
		
			
		cont7++;   /////////////////////////////////  contador de entradas a "apuestas"
		cont9++;/////////////////////////////////    contador a solo apuesta de liga
		
}


void apuesta_gan_partido()
{
	int i,cont3=0,equipo_apostado=0,equipo_1=0,equipo_2=1,ganador;
	int gol_local;
	int gol_visitante;
	

	paux = new jugador;
	paux_a = new apuesta;
	
	colocar_ventanas(1,6,102,32,1,15);
	colocar_borde(1,1,102,26);
	gotoxy(37,3);cout<<"APUESTAS POR GANADOR DE PARTIDO";	
		
	colocar_ventanas(21,10,82,29,15,0);
	colocar_borde(1,1,62,20);
	
	if(cont_equipo>1)
	{
		for(i=0;i<cont_equipo;i++)
		{
			
			gotoxy(4+(15*i),2);cout<<i+1<<") "<<nomina_e[0][i].nom_team;
		}
		
		do
		{
			gotoxy(4,3);cout<<"DIGITE EL NUMERO DEL EQUIPO LOCAL: ";cin>>equipo_1;
			if(equipo_1<=0 or equipo_1>cont_equipo)
			{
				gotoxy(10,5);cout<<"NUMERO DE EQUIPO NO VALIDO";
				getch();
			}
			else
			{
				gotoxy(4,4);cout<<" 1) LOCAL: ";cout<<nomina_e[0][equipo_1 - 1].nom_team;
				paux->jugadas[cont7][0]=equipo_1;
				
				gotoxy(4,5);cout<<"DIGITE EL NUMERO DEL EQUIPO VISITANTE: ";cin>>equipo_2;
				if(equipo_2!=equipo_1 && equipo_2>0 && equipo_2<=cont_equipo)
				{	
					
					gotoxy(4,6);cout<<" 2) VISITANTE: ";cout<<nomina_e[0][equipo_2 - 1].nom_team;
					paux->jugadas[cont7][1]=equipo_2;
					
					gotoxy(4,7);cout<<"DIGITE EL NUMERO DEL EQUIPO AL QUE APUESTA (1 O 2)";
					gotoxy(4,8);cout<<"LOCAL (1) O VISITANTE (2): ";cin>>equipo_apostado;
					cin.ignore();
					
					
					if(equipo_apostado!=1 && equipo_apostado!=2 )
					{
						gotoxy(4,9);cout<<"NUMERO DE EQUIPO NO VALIDO";
						getch();
					}
					else
					{	
						paux->jugadas[cont7][2]=equipo_apostado;
						
						
						gotoxy(4,10);cout<<nomina_e[0][equipo_1 - 1].nom_team<<" VERSUS "<<nomina_e[0][equipo_2 - 1].nom_team;
						valor_a_apostar();
						
						srand(time(0));
						gol_local=0+rand()%(10);
					
						gol_visitante=0+rand()%(10);
					
						gotoxy(4,10);cout<<nomina_e[0][equipo_1 - 1].nom_team<<" ("<<gol_local<<")"<<" VERSUS "<<"("<<gol_visitante<<") "<<nomina_e[0][equipo_2 - 1].nom_team;
		
						if(gol_local>gol_visitante)
						{
							ganador=1;
							paux->jugadas[cont7][3]=ganador;
						}
						if(gol_visitante>gol_local)
						{
							ganador=2;
							paux->jugadas[cont7][3]=ganador;
						}
						if(ganador==equipo_apostado)
						{
							gotoxy(4,12);cout<<gol_local<<" VS "<<gol_visitante<<" ...  HAS GANADO";
							gotoxy(4,13);cout<<"SE TE PAGARA "<<paux_a->val_apuesta[cont7]<<" X 5 = "<<paux_a->val_apuesta[cont7]*5<<" EUROS";
							paux->credito=paux->credito+(paux_a->val_apuesta[cont7]*5);
							equipo_1=equipo_2;
							
						}
						else
						{
							gotoxy(4,12);cout<<gol_local<<" VS "<<gol_visitante<<" ...  HAS PERDIDO";
							equipo_1=equipo_2;
						}
						
						cont7++;					
					}

				}
				else
				{
					if(equipo_2==equipo_1)
					{
						gotoxy(4,5);cout<<"NUMERO DE EQUIPO NO VALIDO";
						getch();
					}
					
				}
				
			}
				
		}while(equipo_1!=equipo_2);	
		
	}
	else
	{
		gotoxy(3,5);cout<<"NO VALIDO PORQUE SOLO HAY "<<cont_equipo<<" EQUIPO CREADO";
	}
	
}


void valor_a_apostar()
{

	paux = new jugador;
	paux_a = new apuesta;
	
	colocar_ventanas(1,6,102,32,1,15);
	colocar_borde(1,1,102,26);
	gotoxy(40,3);cout<<"VALOR DE APUESTA";	
		
	colocar_ventanas(21,10,82,29,15,0);
	colocar_borde(1,1,62,20);
	
	int cont3=0,credito_apostado;
	do
	{	
	gotoxy(4,3+(2*cont3));cout<<"DIGITE VALOR APUESTA (minimo $ 10): ";cin>>credito_apostado;
	if(credito_apostado>=10 && credito_apostado<=paux->credito)
	{
		paux_a->val_apuesta[cont7]=credito_apostado;
	}
	else
	{
		gotoxy(38,3+cont3);cout<<"NUMERO NO V"<<(char)181<<"LIDO, VUELVA A DIGITAR";
		cont3++;
	}	
	}while(credito_apostado<10 );	

	paux->credito=paux->credito-paux_a->val_apuesta[cont7];
	
}


void simular_partido()
{
	
	int i,cont3=0,equipo_apostado=0,equipo_1=0,equipo_2=1,ganador;
	int gol_local;
	int gol_visitante;
	
	paux_v = new partidos;
	
	colocar_ventanas(1,6,102,32,1,15);
	colocar_borde(1,1,102,26);
	gotoxy(42,3);cout<<"JUEGOS AMISTOSOS";	
		
	colocar_ventanas(21,10,82,27,15,0);
	colocar_borde(1,1,62,18);
	
	if(cont_equipo>1)
	{
		amistoso++;
		for(i=0;i<cont_equipo;i++)
		{
			gotoxy(4+(15*i),2);cout<<i+1<<") "<<nomina_e[0][i].nom_team;
		}
		
		do
		{
			gotoxy(4,3);cout<<"DIGITE EL NUMERO DEL EQUIPO LOCAL: ";cin>>equipo_1;
					
			
			if(equipo_1<=0 or equipo_1>cont_equipo)
			{
				gotoxy(10,4);cout<<"NUMERO DE EQUIPO NO VALIDO";
				getch();
			}
			else
			{
				gotoxy(4,4);cout<<" 1) LOCAL: ";cout<<nomina_e[0][equipo_1 - 1].nom_team;
				paux_v->partidas[cont6][0]=equipo_1;
				
				gotoxy(4,5);cout<<"DIGITE EL NUMERO DEL EQUIPO VISITANTE: ";cin>>equipo_2;
				cin.ignore();
				
				if(equipo_2!=equipo_1 && equipo_2>0 && equipo_2<=cont_equipo)
				{	
					
					gotoxy(4,6);cout<<" 2) VISITANTE: ";cout<<nomina_e[0][equipo_2 - 1].nom_team;
					paux_v->partidas[cont6][1]=equipo_2;
						
					
						
						
						gotoxy(4,8);cout<<nomina_e[0][equipo_1 - 1].nom_team<<" VERSUS "<<nomina_e[0][equipo_2 - 1].nom_team;
						
						srand(time(0));
						gol_local=0+rand()%(10);
						paux_v->partidas[cont6][2]=gol_local;
						gol_visitante=0+rand()%(10);
						paux_v->partidas[cont6][3]=gol_visitante;
						
						gotoxy(4,9);cout<<nomina_e[0][equipo_1 - 1].nom_team<<" ("<<gol_local<<")"<<" VERSUS "<<"("<<gol_visitante<<") "<<nomina_e[0][equipo_2 - 1].nom_team;
						
						cont6++;
						equipo_1=equipo_2;
											
				}
				else
				{
					if(equipo_2==equipo_1)
					{
						gotoxy(4,7);cout<<"NUMERO DE EQUIPO NO VALIDO";
						getch();
					}
					
				}
				

			}
			
		}while(equipo_1!=equipo_2);	
		
	}
	else
	{
		gotoxy(5,5);cout<<"NO PUEDE APOSTAR POR PARTIDO PORQUE SOLO HAY "<<cont_equipo<<" EQUIPO CREADO";
	}
	
	getch();
	
}

void resultados_partido()
{
	int i;
	
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"RESULTADO DEL PARTIDO";

	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
			
	int cont8=0,con_equip_1=0,con_equip_2=0,equipo_1=0,equipo_2=1,aux7=0;
	
	if(cont_registro!=0 && cont_equipo!=0 && amistoso>=1)
	{
		for(i=0;i<cont_equipo;i++)
		{
			gotoxy(4+(15*i),2);cout<<i+1<<") "<<nomina_e[0][i].nom_team;
		}
		do
		{
			gotoxy(4,3);cout<<"DIGITE EL NUMERO DEL EQUIPO LOCAL: ";cin>>equipo_1;
			
			if(equipo_1<=0 or equipo_1>cont_equipo)
			{
				gotoxy(10,4);cout<<"NUMERO DE EQUIPO NO VALIDO";
				getch();
			}
			else
			{
				gotoxy(4,4);cout<<" 1) LOCAL: ";cout<<nomina_e[0][equipo_1 - 1].nom_team;
				
				
				gotoxy(4,5);cout<<"DIGITE EL NUMERO DEL EQUIPO VISITANTE: ";cin>>equipo_2;
				cin.ignore();
				
				if(equipo_2!=equipo_1 && equipo_2>0 && equipo_2<=cont_equipo)
				{	
					
					gotoxy(4,6);cout<<"2) VISITANTE: ";cout<<nomina_e[0][equipo_2 - 1].nom_team;
					
					
					
					gotoxy(4,8);cout<<nomina_e[0][equipo_1 - 1].nom_team<<" VERSUS "<<nomina_e[0][equipo_2 - 1].nom_team;
						
						for(i=0;i<amistoso;i++)
						{
							if(equipo_1==paux_v->partidas[i][0] && equipo_2==paux_v->partidas[i][1])
							{
								con_equip_1++;
								con_equip_2++;
								aux7=i;
							}					
						}
						
						if(con_equip_1==1 && con_equip_2==1)
						{
							gotoxy(4,9);cout<<nomina_e[0][equipo_1 - 1].nom_team<<" ("<<paux_v->partidas[0][2]<<")"<<" VERSUS "<<"("<<paux_v->partidas[0][3]<<") "<<nomina_e[0][equipo_2 - 1].nom_team;
						}
						else
						{
							gotoxy(4,9);cout<<"PARTIDO NO ENCONTRADO";
						}
						
						equipo_1=equipo_2;
				}
				else
				{
					if(equipo_2==equipo_1)
					{
						gotoxy(4,6);cout<<"NUMERO DE EQUIPO NO VALIDO";
						getch();
					}
					
				}
				
			}
				
	}while(equipo_1!=equipo_2);
		
	}
	else
	{
		if(cont_registro==0 && cont_equipo==0 && amistoso==0)
		{
			gotoxy(4,15);cout<<"NO V"<<(char)181<<"LIDO PORQUE NO HA INGRESADO UN USUARIO, NI EQUIPO, NI UN PARTIDO JUGADO";
		}
		else
		{
			if(cont_registro==0)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA INGRESADO UN USUARIO.";
			}
			if(cont_equipo==0)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA CREADO UN EQUIPO.";
			}		
			if(amistoso==0)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA JUGADO UN PARTIDO AMISTOSO.";
			}		
		}

		
	}
	
	getch();	
}

void reporte_usuario()
{

	char opcion[2];
	colocar_ventanas(1,6,102,32,1,15);
	colocar_borde(1,1,102,26);
	gotoxy(43,3);cout<<"REPORTE DE USUARIO";	
		
	colocar_ventanas(21,11,82,27,15,0);
	colocar_borde(1,1,62,17);
	
	if(cont_registro!=0 && cont_equipo>1)
	{
		gotoxy(2,2);cout<<" A) REPORTE DE APUESTAS";
		gotoxy(2,3);cout<<" B) REPORTE DE PARTIDOS AMISTOSOS";
		gotoxy(2,5);cout<<" DIGITE OPCI"<<(char)224<<"N: ";	
					
			cin>>opcion;
			opcion[0]=tolower(opcion[0]);
			cin.ignore();
			switch(opcion[0])
	    	{
	    		case 'a':
	        		reporte_apuestas(); 
	        	break;
	    		case 'b':
	        		reporte_partidos(); 
	        	break;
				default:
					gotoxy(18,14);cout<<"OPCI"<<(char)224<<"N NO V"<<(char)181<<"LIDA, VUELVA A DIGITAR";
					getch();
					apuestas();
	    		break;
	    	}
	}
	else
	{
		if(cont_registro==0 && cont_equipo==0)
		{
			gotoxy(4,15);cout<<"NO V"<<(char)181<<"LIDO PORQUE NO HA INGRESADO UN USUARIO, NI EQUIPO.";
		}
		else
		{
			if(cont_registro==0)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA INGRESADO UN USUARIO.";
			}
			if(cont_equipo==0)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE NO HA CREADO UN EQUIPO.";
			}	
			if(cont_equipo==1)
			{
				gotoxy(9,15);cout<<"ENTRADA NO V"<<(char)181<<"LIDA PORQUE SOLAO HAY UN EQUIPO.";
			}		
		}

		
	}
	
	
	getch();
}

void reporte_apuestas()
{
	int i;
	
	paux_a = new apuesta;
	
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"REPORTE DE APUESTAS";

	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
			
		gotoxy(4,3);cout<<"NOMBRE JUGADOR: "<<paux->nom;
		gotoxy(4,4);cout<<"CREDITO ACTUAL: "<<paux->credito;
	
		int cont8=0;
	
		for(i=0;i<cont7;i++)
		{
			gotoxy(4,6+(3*cont8));cout<<"APUESTA POR EL EQUIPO: "<<nomina_e[0][paux->jugadas[cont8][2]-1].nom_team;
			gotoxy(4,7+(3*cont8));cout<<"VALOR APUESTA: "<<paux_a->val_apuesta[cont8];
			if(paux->jugadas[cont8][2]==paux->jugadas[cont8][3])
			{
				gotoxy(4,8+(3*cont8));cout<<"GANASTE";	
			}
			else
			{
				gotoxy(4,8+(3*cont8));cout<<"PERDISTE";
			}
			
		cont8++;
		}

	
	//getch();
}

void reporte_partidos()
{
	int i;
	paux_v = new partidos;
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);
	gotoxy(41,3);cout<<"REPORTE DE PARTIDOS AMISTOSOS";

	colocar_ventanas(5,10,97,28,15,0);
	colocar_borde(1,1,93,19);
			
		gotoxy(4,3);cout<<"NOMBRE JUGADOR: "<<paux->nom;
	
		int cont8=0;
	
		for(i=0;i<cont6;i++)
		{
			gotoxy(4,6+(3*cont8));cout<<nomina_e[0][paux_v->partidas[cont8][0]].nom_team<<" VERSUS "<<nomina_e[0][paux_v->partidas[cont8][1]].nom_team;
			gotoxy(4,7+(3*cont8));cout<<"RESULTADO: ("<<paux_v->partidas[cont8][2]<<") VS ("<< paux_v->partidas[cont8][3]<<") ";
			
		cont8++;
		}

	//getch();
}

void creditos() 
{
	colocar_ventanas(1,6,102,32,3,11);
	colocar_borde(1,1,102,26);gotoxy(40,3);
	cout<<"PROYECTO REALIZADO POR: ";

	colocar_ventanas(21,11,82,27,15,0);
	colocar_borde(1,1,62,17);
	gotoxy(7,3);cout<<"JEAN CARLOS HERNANDEZ BENAVIDES C"<<(char)224<<"DIGO: 217034199";
	gotoxy(7,4);cout<<"DANIEL ESTIVEN GUANCHA C"<<(char)224<<"DIGO: 217034";
	gotoxy(10,5);cout<<"INGENIER"<<(char)214<<"A DE SISTEMAS - 3er SEMESTRE Grupo 1";
	gotoxy(21,6);cout<<"UNIVERSIDAD DE NARI"<<(char)165<<"O";
	gotoxy(29,7);cout<<"2018";
    
	getch();
}

void terminar_programa() 
{
	colocar_ventanas(1,6,102,32,1,15);
	colocar_borde(1,1,102,26);
	gotoxy(49,3);cout<<"SALIR";
	
	colocar_ventanas(21,11,82,27,15,0);
	colocar_borde(1,1,62,17);
	gotoxy(13,3);
	cout<<"GRACIAS POR UTILIZAR EL PROGRAMA";
	gotoxy(2,8);exit(0);
}

void colocar_ventanas(int x1,int y1, int x2,int y2,int col_fondo, int col_tex) 
{
	window(x1,y1,x2,y2);
	textbackground(col_fondo);
	textcolor(col_tex);
	clrscr();
}

void colocar_borde(int x1, int y1, int x2, int y2)  
{
	int i;
	for(i=x1+1;i<x2;i++)
	{
		gotoxy(i,y1);cout<<(char)205;
		gotoxy(i,y2);cout<<(char)205;
	}
	for(i=y1+1;i<y2;i++)
	{
		gotoxy(x1,i);cout<<(char)186;
		gotoxy(x2,i);cout<<(char)186;
	}
	gotoxy(x1,y1);cout<<(char)201;
	gotoxy(x1,y2);cout<<(char)200;
	gotoxy(x2,y1);cout<<(char)187;
	gotoxy(x2,y2);cout<<(char)188;
}
