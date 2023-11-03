#include <iostream>
#include <conio.h>
using namespace std;
int turnos=0,i,j,k,info=0,info2=0,x,y,gana=0,a,b,z;
string triqui[3][3]={"-","-","-","-","-","-","-","-","-"};
void tablerovacio()
    {
		for (i=0;i<3;i++)
    		{
    			triqui[i][0]="-";
    		}
		for (j=0;j<3;j++)
    		{
    			triqui[j][1]="-";
    		}
    	for(k=0;k<3;k++)
    		{
     			triqui[k][2]="-";
    		}
    }
void ganador()
    {
    	if((gana==0)or(gana==3))
        	{
         		for(b=0;b<3;b++)
            	if ((triqui[0][b]=="X")&&(triqui[1][b]=="X")&&(triqui[2][b]=="X"))
               		{
                		gana=1;
            		}
				for(b=0;b<3;b++)
            	if((triqui[b][0]=="X")&&(triqui[b][1]=="X")&&(triqui[b][2]=="X"))
              		{
               			gana=1;
              		}
				if((triqui[0][0]=="X")&&(triqui[1][1]=="X")&&(triqui[2][2]=="X"))
                	{
                 		gana=1;
               	 	}
				if((triqui[0][2]=="X")&&(triqui[1][1]=="X")&&(triqui[2][0]=="X"))
                	{
            				gana=1;
            		}
				for(z=0;z<3;z++)
                if ((triqui[0][z]=="O")&&(triqui[1][z]=="O")&&(triqui[2][z]=="O"))
                    {
                        gana=2;
                    }
				for(z=0;z<3;z++)
            	if((triqui[z][0]=="O")&&(triqui[z][1]=="O")&&(triqui[z][2]=="O"))
                	{
                    	gana=2;
                	}
				if((triqui[0][0]=="O")&&(triqui[1][1]=="O")&&(triqui[2][2]=="O"))
                	{
                   	 	gana=2;
                	}
				if((triqui[0][2]=="O")&&(triqui[1][1]=="O")&&(triqui[2][0]=="O"))
                	{
                    gana=2;
                	}
            }
    }
void tablero()
    {
        
		cout<<"Realizado por: Jean Carlos Hernandez Benavides\n";
		cout <<"\n\t\tEL JUEGO DEL TRIQUI O TRES EN RAYA\n";
        cout <<"\t- Para jugar debes de ingresar un numero\n ";
        cout <<"\t- Los numeros van de orden descendente y hacia la derecha asi\n";
        cout<<"\t";cout<<"|1|\t\t|2|\t\t|3|\n\t|4|\t\t|5|\t\t|6|\n\t|7|\t\t|8|\t\t|9|\n\n\n";
		for (i=0;i<3;i++)
            {
                cout<<"\t";
				cout<<"|"<<triqui[i][0]<<"|"<<"\t";
            }
        cout<<"\n";
		for (j=0;j<3;j++)
            {
                cout<<"\t";
				cout<<"|"<<triqui[j][1]<<"|"<<"\t";
            }
      	cout<<"\n";
		for(k=0;k<3;k++)
            {
                cout<<"\t";
				cout<<"|"<<triqui[k][2]<<"|"<<"\t";
            }
    	cout<<"\n";   
    }
void turno1(int x)
    {
        if ((x>9)or(x<1))
            {
                cout<<"\t- ERROR, POR FAVOR, DIGITA UN NUMERO ENTRE EL 1 Y EL 9";
                cout<<"\n";
                info2=0;
                turnos--;
                cin>>x;
                turno1(x);
            }
        else do
            {
                for(a=1;a<4;a++)
                    if (x==a)
                        {
                            if((triqui[a-1][0]=="-")&&(info2==0))
                                {
                                    triqui[a-1][0]="X";
                                }
                            else if((triqui[a-1][0]=="O")or(triqui[a-1][0]=="X"))
                                {
                                    info2=1;
                                }
                        }
				for(a=4;a<7;a++)
                    if (x==a)
                        {
                            if((triqui[a-4][1]=="-")&&(info2==0))
                                {
                                    triqui[a-4][1]="X";
                                }
                            else if((triqui[a-4][1]=="O")or(triqui[a-4][1]=="X"))
                                {
                                    info2=1;
                                }
                        }
				for(a=7;a<10;a++)
                    if (x==a)
                        {
                            if ((triqui[a-7][2]=="-")&&(info2==0))
                                {
                                    triqui[a-7][2]="X";
                                }
                            if((triqui[a-7][2]=="O")or(triqui[a-7][2]=="X"))
                                {
                                    info2=1;
                                }
                        }
			}
		while(!(x<10 && x>=1));
      	turnos++; 
		if (info2==1)
            {
                tablero(); 
				cout <<"\t- ESA POSICION YASE HA UTILIZADO, INTENTA DE NUEVO";
				cout<<"\n\t";
     			cin>>x;           
				info2=0;
                turnos--; 
                turno1(x);
            }
        else
            tablero();
}
void turno2(int y)
    {
        if ((y>9)or(y<1)) 
            {
                cout<<"\t- ERROR, POR FAVOR, DIGITA UN NUMERO ENTRE EL 1 Y EL 9";
                cout<<"\n\t";
           		cin>>y;     
		   		info=0;
                turnos--;
                turno2(y);
			}
        else do
            {
				for(a=1;a<4;a++)
                    {
                        if (y==a)
                            {
                                if((triqui[a-1][0]=="-")&&(info==0))
                                    {
                                        triqui[a-1][0]="O";
                                    }

                                else if((triqui[a-1][0]=="X")or(triqui[a-1][0]=="O"))
                                    {
                                        info=1;
                                    }
                            }
                    }

                for(a=4;a<7;a++)
                    {
                        if (y==a)
                            {
                                if((triqui[a-4][1]=="-")&&(info==0))
                                    {
                                        triqui[a-4][1]="O";
                                    }

                                if((triqui[a-4][1]=="X")or(triqui[a-4][1]=="O"))
                                    {
                                        info=1;
                                    }
                            }
                    }
                for(a=7;a<10;a++)
                    {
                        if(y==a)
                            {
                                if((triqui[a-7][2]=="-")&&(info==0))
                                    {
                                        triqui[a-7][2]="O";
                                    }

                                if((triqui[a-7][2]=="X")or(triqui[a-7][2]=="O"))
                                    {
                                        info=1;
                                    }
                            }
                    }
            }
        while(!(y<10 && y>=1));
        turnos++;
        if (info==1)
            {
                tablero();
                cout<<"\t- ESA POSICION YA SE HA UTILIZADO, INTENTA DE NUEVO";
                cout<<"\n\t";
       			cin>>y;        
				info=0;
                turnos--;
                turno2(y);
            }
        else
            tablero();
    }
void vaciar()
    {
        turnos=0;
        gana=0;
        tablerovacio();
    }
main()
    {
		while(turnos<9)
        	{
        		tablero();
            	cout<<"\n\t- Turno del jugador 1\n\tIntroduce tu ficha\n";
            	cout<<"\t";
				cin>>x;
          		turno1(x);
            	ganador();
            	if(gana==1)
                	{
                   		cout<<"\t- GANA EL JUGADOR 1\n\tEL JUEGO HA TERMINADO\n";
                    }
				if (turnos<=8) 
                	{
                    	if(gana==1)
							{
								cout<<"\tFIN JUEGO";
							}
				else
					{
						cout<<"\n\t- Turno del jugador 2\n\tIntroduce tu ficha\n";
						cout<<"\t";
                    	cin>>y;
                    	turno2(y);
                    	ganador();	
					}	
				if(gana==2)
                    {
                        cout<<"\t- GANA EL JUGADOR 2\n\tEL JUEGO HA TERMINADO\n";   		
                    }
                }
            ganador();
        }
if(gana==0)
    {
        cout<<"\t- NINGUN JUGADOR HA GANADO, EMPATE\n";
        cout<<"\t- EL JUEGO HA TERMINADO";
	}
system("pause");
} 
