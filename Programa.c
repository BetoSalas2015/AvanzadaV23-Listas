#include <stdio.h>			//  Para la I/O del programa
#include <stdlib.h>			//  Para las rutinas de utilería 
#include <malloc.h>			//  PAra la memoria dinámica

#define pausa system("pause")	//  Pausa en la ejecucuin del programa
#define cls sysstem("cls")		//  PAra borrar pantalla

struct Nodo 
{
	char info;
	struct Nodo *sig;
};

typedef struct Nodo nodo;

int main()
{
	nodo variable;
	pausa;
	return 0;
}
