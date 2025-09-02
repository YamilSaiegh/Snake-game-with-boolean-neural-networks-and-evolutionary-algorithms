#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <windows.h>

int NAND (int x, int y)
{
 if(x==0&&y==0) return (1); else return (0);
}

struct BIT
{
 unsigned char b0:1;
 unsigned char b1:1;
 unsigned char b2:1;
 unsigned char b3:1;
 unsigned char b4:1;
 unsigned char b5:1;
 unsigned char b6:1;
 unsigned char b7:1;
};

union CONVERSION
{
 struct BIT binario;
 int numerodecimal;
};

void dec_bin (int var,int *vec)
{
 union CONVERSION decimal;
 decimal.numerodecimal=var;
 vec[7]=decimal.binario.b7;
 vec[6]=decimal.binario.b6; 
 vec[5]=decimal.binario.b5;
 vec[4]=decimal.binario.b4;
 vec[3]=decimal.binario.b3;
 vec[2]=decimal.binario.b2; 
 vec[1]=decimal.binario.b1;
 vec[0]=decimal.binario.b0;
}

void gotoxy (int x, int y)
{
 COORD posi;
 HANDLE hcmd;
 hcmd = GetStdHandle( STD_OUTPUT_HANDLE );
 posi.X = x;
 posi.Y = y+1;
 SetConsoleCursorPosition(hcmd,posi);
}

int main (void)
{
 int x[10000],y[10000];
 int a,b,p,mover,i,j;
 int entradas[40],n1,n2,n3,n4;
 int vec1[32][3],vec2[32][3],vec3[32][3];
 int salva1[32][3],salva2[32][3],salva3[32][3];
 int bec1[256], bec2[256], bec3[256];
 int coinci,coinci_max,dec,w=0,Aciertos=0,Aciertos_max=0,perder,z=0,h,movidas;
 char palabra[9]="color 0a";

 srand(time(0));

 //----------ENTRENADOR-------------------------------------------------------//
 
 for(i=0;i<32;i++)
 { 
  vec1[i][0]=rand()%(i+8); vec1[i][1]=rand()%(i+8); vec1[i][2]=i+8;  
  vec2[i][0]=rand()%(i+8); vec2[i][1]=rand()%(i+8); vec2[i][2]=i+8;  
  vec3[i][0]=rand()%(i+8); vec3[i][1]=rand()%(i+8); vec3[i][2]=i+8; 
  salva1[i][0]=vec1[i][0]; salva1[i][1]=vec1[i][1];
  salva2[i][0]=vec2[i][0]; salva2[i][1]=vec2[i][1];
  salva3[i][0]=vec3[i][0]; salva3[i][1]=vec3[i][1];
 }
 
 for(h=2;h<100;h++)
 {
 
 for(;Aciertos_max<100*h;w++)
 {
  vec1[rand()%32][rand()%2]=rand()%40; vec2[rand()%32][rand()%2]=rand()%40; vec3[rand()%32][rand()%2]=rand()%40; 

  for(dec=0;dec<256;dec++)
  {
   dec_bin(dec,entradas);
   for(i=0;i<32;i++) entradas[vec1[i][2]]=NAND(entradas[vec1[i][0]],entradas[vec1[i][1]]); bec1[dec]=entradas[39];
   for(i=0;i<32;i++) entradas[vec2[i][2]]=NAND(entradas[vec2[i][0]],entradas[vec2[i][1]]); bec2[dec]=entradas[39];
   for(i=0;i<32;i++) entradas[vec3[i][2]]=NAND(entradas[vec3[i][0]],entradas[vec3[i][1]]); bec3[dec]=entradas[39];
  }
  
  for(Aciertos=0,j=0;j<2000;j++)
  {
   n1=rand()%80; n2=rand()%80; entradas[2]=0; entradas[3]=0;
   n3=rand()%50; n4=rand()%50; entradas[6]=0; entradas[7]=0;
   
   for(i=0;i<130&&(!(n1==n2&&n3==n4))&&n2<80&&n2>=0&&n4<50&&n4>=0;i++)
   {
    if(n1<n2) { entradas[0]=0; entradas[1]=1; }
    else
    {
     if(n1>n2) { entradas[0]=1; entradas[1]=0; }
     else { entradas[0]=0; entradas[1]=0; }
    }
    
    if(n3<n4) { entradas[4]=0; entradas[5]=1; } 
    else
    { 
     if(n3>n4) { entradas[4]=1; entradas[5]=0; }
     else { entradas[4]=0; entradas[5]=0; } 
    }
      
    dec=entradas[0]*1+entradas[1]*2+entradas[2]*4+entradas[3]*8+entradas[4]*16+entradas[5]*32+entradas[6]*64+entradas[7]*128;
  
    if(bec1[dec]==0&&bec2[dec]==0&&bec3[dec]==1) n2--;
    if(bec1[dec]==0&&bec2[dec]==1&&bec3[dec]==1) n2++;
    if(bec1[dec]==1&&bec2[dec]==0&&bec3[dec]==1) n4--;
    if(bec1[dec]==1&&bec2[dec]==1&&bec3[dec]==1) n4++;

    if(n1==n2&&n3==n4) Aciertos++; 
   }
  }
  
  if(Aciertos<Aciertos_max)
  {
   for(i=0;i<32;i++)
   { 
    vec1[i][0]=salva1[i][0]; vec1[i][1]=salva1[i][1];
    vec2[i][0]=salva2[i][0]; vec2[i][1]=salva2[i][1];
    vec3[i][0]=salva3[i][0]; vec3[i][1]=salva3[i][1]; 
   }
  }
  
  else
  {
   Aciertos_max=Aciertos;
   for(i=0;i<32;i++)
   { 
    salva1[i][0]=vec1[i][0]; salva1[i][1]=vec1[i][1];
    salva2[i][0]=vec2[i][0]; salva2[i][1]=vec2[i][1];
    salva3[i][0]=vec3[i][0]; salva3[i][1]=vec3[i][1]; 
   }
  }
 }
  
 //----------VIBORITA---------------------------------------------------------//
 

  system("cls");
 
  for(i=0;i<20;i++) { x[i]=i+2; y[i]=2; } a=14; b=2; p=11; perder=0;

  for(mover=77,movidas=0;perder==0&&movidas<150;movidas++)
  {
   Sleep(10);
   for(i=0;i<p;i++) { x[i]=x[i+1]; y[i]=y[i+1]; }
  
   gotoxy(x[0],y[0]); putchar(' ');

   if(a<x[p]) { entradas[0]=0; entradas[1]=1; }
   else
   { 
    if(a>x[p]) { entradas[0]=1; entradas[1]=0; }
    else { entradas[0]=0; entradas[1]=0; }
   }
    
   if(b<y[p]) { entradas[4]=0; entradas[5]=1; } 
   else
   { 
    if(b>y[p]) { entradas[4]=1; entradas[5]=0; }
    else { entradas[4]=0; entradas[5]=0; }  
   }
  
   entradas[2]=0; entradas[3]=0;
   entradas[6]=0; entradas[7]=0;
  
   dec=entradas[0]*1+entradas[1]*2+entradas[2]*4+entradas[3]*8+entradas[4]*16+entradas[5]*32+entradas[6]*64+entradas[7]*128;
  
   if(bec1[dec]==0&&bec2[dec]==0&&bec3[dec]==1) x[p]--;
   if(bec1[dec]==0&&bec2[dec]==1&&bec3[dec]==1) x[p]++;
   if(bec1[dec]==1&&bec2[dec]==0&&bec3[dec]==1) y[p]--;
   if(bec1[dec]==1&&bec2[dec]==1&&bec3[dec]==1) y[p]++;

   if(a==x[p]&&b==y[p])
   {
    p++; for(i=p;i>0;i--) { x[i]=x[i-1]; y[i]=y[i-1]; }
    a=rand()%80; b=rand()%50; gotoxy(a,b); putchar(219);
    movidas=0;
   }

   gotoxy(x[p],y[p]); putchar(219); gotoxy(79,49);
   if(p>21) { palabra[6]=101; palabra[7]=51; system(palabra); }
   
   if(p==32&&z==0) for(i=0;i<10;i++) { gotoxy(rand()%80,rand()%50); printf("sensocentrismo"); Sleep(10); z=1; }

   for(i=0;i<p;i++) if(/*(x[p]==x[i]&&y[p]==y[i])||*/(x[p]<0||y[p]<0||x[p]>79||y[p]>49)) { perder=1; Sleep(50); }

   gotoxy(0,1); printf("Aptitud: %i Generaciones: %i Ingestas: %i", Aciertos_max, w, p-12);
  }
 
 


}

 
 
}
