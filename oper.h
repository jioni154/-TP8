#include "def.h"

void bitSet (puerto *prt, unsigned int num);
void bitClear (puerto *prt, unsigned int num);
unsigned int getBit (puerto prt, unsigned int num);
void maskOn (puerto *prt, unsigned int num);
void maskOff (puerto *prt, unsigned int num);
void btoggle (puerto *prt, unsigned int num);
void bitSet_D (puertoD *prt, unsigned int num);
void bitClear_D (puertoD *prt, unsigned int num);
unsigned int getBit_D (puertoD prt, unsigned int num);
void maskOn_D (puertoD *prt, unsigned int num);
void maskOff_D (puertoD *prt, unsigned int num);
void blink(puerto *prt);