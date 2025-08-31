#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


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
 char x[50]={2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
 char y[50]={2,2,2,2,2,2,2,2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
 char a=14, b=2, p=11, mover, i;

 srand(time(0));

system("cls");

 for(mover=77;1;mover=getch())

 for(;!kbhit();Sleep(70))
 {

  for(i=0;i<p;i++) { x[i]=x[i+1]; y[i]=y[i+1]; }
  
  gotoxy(x[0],y[0]); putchar(' ');

  switch(mover) { case 72: y[p]--; break; case 75: x[p]--; break; case 77: x[p]++; break; case 80: y[p]++; break;	}

  if(a==x[p]&&b==y[p])
  {
	p++; for(i=p;i>0;i--) { x[i]=x[i-1]; y[i]=y[i-1]; }
	a=(rand()%76+2); b=(rand()%46+3); gotoxy(a,b); putchar(219);
  }

  gotoxy(x[p],y[p]); putchar(219); gotoxy(79,49);

  for(i=0;i<p;i++) if((x[p]==x[i]&&y[p]==y[i])||(x[p]==1||y[p]==1||x[p]==80||y[p]==50)) exit(0);
  
 }
}
