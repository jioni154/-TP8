#include <stdio.h>
#include "oper.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "termlib.h"


int kbhit (void);

int main (void)
{
	
	puerto_t p;
	int loop=0;
while(loop==0)
{
	printf("Con numeros prendes los leds, con s apagas todos, con c prendes todos, y con b la haces prenderse y apagarse\n presiona esc para terminar el programa\n");	
	int tempnum,caso;	
	char c;
	c=getch();
	if(!(c<'0'||c>'7'))
	{
	tempnum=((c)-'0');
	caso=1;
	}
	else if(c=='b')
	caso=2;
	else if(c=='s')
	caso=3;
	else if(c=='c')
	caso=5;
	else if(c==27)
	caso=6;
	else 
	caso=4;
	


switch(caso)
{
case 1: bitSet(&(p.pA),tempnum);
break;
case 2: blink(&(p.pA));
break;
case 3: maskOff(&(p.pA),255);
break;
case 4:
break;
case 5: maskOn(&(p.pA),255);
break;
case 6:
return 0;
break;
}

printf("%d %d %d %d %d %d %d %d \n", p.pA.prt.b7, p.pA.prt.b6, p.pA.prt.b5, p.pA.prt.b4, p.pA.prt.b3, p.pA.prt.b2, p.pA.prt.b1, p.pA.prt.b0);

getchar();
}



return 0;
}	

