typedef struct {
	unsigned char b0	:1;
	unsigned char b1	:1;
	unsigned char b2	:1;
	unsigned char b3	:1;
	unsigned char b4	:1;
	unsigned char b5	:1;
	unsigned char b6	:1;
	unsigned char b7	:1;
} puerto_bits;

typedef struct {
	unsigned char b0	:1;
	unsigned char b1	:1;
	unsigned char b2	:1;
	unsigned char b3	:1;
	unsigned char b4	:1;
	unsigned char b5	:1;
	unsigned char b6	:1;
	unsigned char b7	:1;
	unsigned char b8	:1;
	unsigned char b9	:1;
	unsigned char b10	:1;
	unsigned char b11	:1;
	unsigned char b12	:1;
	unsigned char b13	:1;
	unsigned char b14	:1;
	unsigned char b15	:1;
} puerto2;

typedef union {
	char dec;		//tenemos este para manejarnos con numeros decimales
	puerto_bits prt;		//y por la union tendremos aca la expresion binaria
} puerto;

typedef union {
	unsigned short int dec;
	puerto2 prt;
} puertoD;

typedef union {
	struct{
		puerto pB;	//el orden importa
		puerto pA;
	};
	puertoD pD;
	short int a;
} puerto_t;			//solo deberiamos usar esta
