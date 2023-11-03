#include<conio.h>
#include<stdio.h>
#include<math.h>
int pox=8,poy=3;
int i,n,potencia=2;
int col=8,colu=18,fil=5,fila=5;
int cool=28,fi=5,coool=38,filaa=5;
int com=48,fim=5;
int po=58,fo=5;
float b,c,d,usuario,suma2,suma;
float res[20],a[20],arreglo[20],arreglos[20],totalx;
float total,x_testada,y_testada,aux[20],auxi[20];
void pintar_cuadro()
{
int col,fil;

for(col=1; col<80; col++)
{
gotoxy(col,1);printf("%c",223);
}
for(fil=1; fil<=60; fil++)
{
gotoxy(79,fil);printf("%c",219);
}
for(col=1; col<80; col++)
{
gotoxy(col,60);printf("%c",223);
}
for(fil=1; fil<60; fil++)
{
gotoxy(1,fil);printf("%c",219);
}
}
main()
{
    pintar_cuadro();
    gotoxy(col,fil);printf("INGRESE EL NUMERO DE DATOS DE [X,Y]: ");scanf("%d",&n);
    gotoxy(col,fil+3);printf("DATOS DE X. . .");
    for(i=1; i<=n; i++)
    {
        clrscr();
        pintar_cuadro();
        gotoxy(col,fil+3);printf("X %d: ",i);
        scanf("%f",&arreglo[i]);
        totalx+=arreglo[i];
        gotoxy(col,fil+4);printf("Y %d: ",i);
        scanf("%f",&arreglos[i]);
        total+=arreglos[i];

    }
     clrscr();
     pintar_cuadro();
     for(i=1; i<=n; i++)
    {
     gotoxy(pox,poy);printf(" X ");
     gotoxy(col,fil);printf("%.2f",arreglo[i]);fil++;
     gotoxy(pox+10,poy);printf(" Y ");
     gotoxy(colu,fila);printf("%.2f",arreglos[i]);fila++;
    }
    gotoxy(col,fil+1);printf("Total:");
    gotoxy(col,fil+2);printf("%.2f",totalx);
    gotoxy(colu,fila+1);printf("Total:");
    gotoxy(colu,fila+2);printf("%.2f",total);
    x_testada=totalx/n;
    y_testada=total/n;
    gotoxy(col,fil+5); printf("X Testada: %.2f",x_testada);
    gotoxy(col,fil+6); printf("Y Testada: %.2f",y_testada);
    //x testada resultado//
    for(i=1; i<=n; i++)
    {

     aux[i]=arreglo[i]-x_testada;
   gotoxy(pox+20,poy-1);printf("   %c ",95);
     gotoxy(pox+20,poy);printf("(x-x)");
     gotoxy(cool,fi);printf("%.2f",aux[i]);
     fi++;
    //y testada resultado//
    auxi[i]=arreglos[i]-y_testada;
   gotoxy(pox+30,poy-1);printf("   %c ",95);
     gotoxy(pox+30,poy);printf("(y-y)");
    gotoxy(coool,filaa);printf("%.2f",auxi[i]);
    filaa++;
    //x testada* y testada//
    a[i]=(aux[i])*(auxi[i]);
   gotoxy(pox+37,poy-1);printf("   %c    %c",95,95);
     gotoxy(pox+37,poy);printf("(x-x)(y-y)");
    gotoxy(com,fim);printf("%.2f",a[i]);
    fim++;
    }
    for(i=1; i<=n; i++)
    {
        //x-x' al cuadrado//
     res[i]=pow(aux[i],potencia);
   gotoxy(pox+50,poy-1);printf("   %c",95);
     gotoxy(pox+50,poy);printf("(x-x)%c2",94);
     gotoxy(po,fo);printf("%.4f",res[i]);fo++;
    }
   for(i=1; i<=n; i++)
    {
        suma+=res[i];
        gotoxy(po,fo+1);printf("Total:");
        gotoxy(po,fo+2);printf("%.3f",suma);
    }
     for(i=1; i<=n; i++)
    {
        suma2+=a[i];
        gotoxy(com,fim+1);printf("Total:");
        gotoxy(com,fim+2);printf("%.2f",suma2);
    }
    b=suma2/suma;
    c= y_testada-(b)*(x_testada);
    gotoxy(col,fil+7);printf("A: %.3f",c);
    gotoxy(col,fil+8);printf("B: %.3f",b);
    gotoxy(col,fil+10);printf("INGRESA EL DATO PARA CALCULAR Y: ");scanf("%f",&usuario);
    d= c+(b)*(usuario);
    gotoxy(col,fil+12);printf("Y: %.3f",d);
 getch();
}
