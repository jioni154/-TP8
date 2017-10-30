#include <stdio.h>
#include "oper.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

void blink(puerto *prt);
int kbhit(void);

int main (void)
{
	
	puerto_t p;
	int loop=0;
while(loop==0)
{
	int tempnum,caso;	
	char c;
	c=getchar();
	if(!(c<0||c>9))
	{
	tempnum=(c-'0');
	caso=1;
	}
	else if(c=='b')
	caso=2;
	else if(c=='s')
	caso=3;
	else if(c=='c')
	caso=5;
	else if(c==28)
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
case 6: loop=1;
break;
}
}

//debug
printf("%c \n",p.pA.dec);


return 0;
}	


void blink(puerto *prt)
{	
	int blinknum;
	blinknum=(prt->dec);
	while(!kbhit())
	{	
		prt->dec=0;
		sleep(1);
		prt->dec=blinknum;
		sleep(1);
	}
	sleep(2);
}

int kbhit(void)

{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}
