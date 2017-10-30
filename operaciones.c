#include <stdio.h>
#include "oper.h"

#define MASK 1

void bitSet (puerto *prt, unsigned int num)	//los bits van de 0 a 7
{
	if (num<8)
	{
		prt->dec = prt->dec | (MASK<<(num));
	}
	else
	{
		printf("parametro invalido");
	}
}

void bitClear (puerto *prt, unsigned int num)
{
	if (num<8)
	{
		if ( prt->dec & (MASK<<(num)) )	//hacemos este if para revisar que el bit que el usuario quiere poner en 0 este previamente en 1
		prt->dec = prt->dec ^ (MASK<<(num));
	}
	else
	{
		printf("parametro invalido");
	}
}

unsigned int getBit (puerto prt, unsigned int num)
{
	unsigned int rta;
	if (num<8)
	{
		if ( prt.dec & (MASK<<(num)) )	//en caso que el bit solicitado sea 1 el 'and bitwise' devolveria un valor distinto de 0
			rta = 1;
		else
			rta = 0;
	}
	else
	{
		printf("parametro invalido");
	}
	return rta;
}	

void maskOn (puerto *prt, unsigned int num)	//los bits van de 0 a 7
{
	if (num<256)
	{
	prt->dec = prt->dec|(num);
	}
	else
	{
		printf("parametro invalido");
	}
}

void maskOff (puerto *prt, unsigned int num)
{
	if (num<256)
	{
	prt->dec = prt->dec & (255^num);
	}
	else
	{
		printf("parametro invalido");
	}
}

void btoggle (puerto *prt, unsigned int num)
{
	if (prt->dec & (MASK<<(num)) == 0)
	{
		prt->dec = prt->dec | (MASK<<(num));
	}
	else
	{
		prt->dec = prt->dec ^ (MASK<<(num));
	}
}


/*	versiones de las operaciones para el puerto D		*/


void bitSet_D (puertoD *prt, unsigned int num)	//los bits van de 0 a 7
{
	if (num<16)
	{
		prt->dec = prt->dec | (MASK<<(num));
	}
	else
	{
		printf("parametro invalido");
	}
}

void bitClear_D (puertoD *prt, unsigned int num)
{
	if (num<16)
	{
		if ( prt->dec & (MASK<<(num)) )	//hacemos este if para revisar que el bit que el usuario quiere poner en 0 este previamente en 1
		prt->dec = prt->dec ^ (MASK<<(num));
	}
	else
	{
		printf("parametro invalido");
	}
}

unsigned int getBit_D (puertoD prt, unsigned int num)
{
	unsigned int rta;
	if (num<16)
	{
		if ( prt.dec & (MASK<<(num)) )	//en caso que el bit solicitado sea 1 el 'and bitwise' devolveria un valor distinto de 0
			rta = 1;
		else
			rta = 0;
	}
	else
	{
		printf("parametro invalido");
	}
	return rta;
}	

void maskOn_D (puertoD *prt, unsigned int num)	//los bits van de 0 a 7
{
	if (num<65536)				//la mascara debera tener un valor decimal inferior a 2 elevado a la 16
	{
	prt->dec = prt->dec|(num);
	}
	else
	{
		printf("parametro invalido");
	}
}

void maskOff_D (puertoD *prt, unsigned int num)
{
	if (num<65536)
	{
	prt->dec = prt->dec & (255^num);
	}
	else
	{
		printf("parametro invalido");
	}
}
