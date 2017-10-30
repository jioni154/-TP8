#include <stdio.h>
#include "def.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int kbhit (void);

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