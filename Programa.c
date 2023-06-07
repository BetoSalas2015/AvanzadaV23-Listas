#include <stdio.h>			//  Para la I/O del programa
#include <stdlib.h>			//  Para las rutinas de utiler�a 
#include <malloc.h>			//  PAra la memoria din�mica

#define pausa system("pause")	//  Pausa en la ejecucuin del programa
#define cls sysstem("cls")		//  PAra borrar pantalla

struct Nodo 
{
	char info;
	struct Nodo *sig;
};								// Creando un nuevo tipo de dato

typedef struct Nodo nodo;		//  Se define formalemnte como tipo de dato

nodo *raiz = NULL;				// Se define una lista vac�a

//  Prototipos de Funci�n 
void insert(char dato);
void imprimeLista();

void insert(char dato)
{
	nodo *nuevo = NULL;			//  Apuntador para el nuevo nodo
	nuevo = (nodo *) malloc(sizeof (nodo) );		// reservo un nuevo nodo
	if( nuevo == NULL)			//  Hay memoria disponible?
	{
		printf("ERROR: No hay memoria disponible");		// No hay memoria
		pausa;
		exit(1);		//  Termina el programa con condici�n de error 1 (no hay memoria)
	}
	nuevo -> info = dato;	// Preservamos el dato recibido en el nodo
	nuevo -> sig = NULL;	// El apuntador sigueinte se apunta NULL	
	if( raiz == NULL)		// La lista est� vac�a?
	{						//  Si esta vac�a
		raiz = nuevo;
	}
	else					//  No est� vac�a
	{				
		nodo *recorre = raiz;	//  Me posiciono en el primer nodo de la lista
		while( recorre -> sig != NULL)		// Es el ultimo nodo
		{									// No.
			recorre = recorre-> sig;		// Me muevo al siguente nodo
		}
		recorre ->sig = nuevo;				// Inserto al final el nuevo nodo
	}
}

void imprimeLista()
{
	nodo *recorre = raiz;	//  Me posiciono en el primer nodo de la lista
	while( recorre != NULL)		// Se acab� la lista?
	{									// No.
		printf("%c, ", recorre->info);
		recorre = recorre-> sig;		// Me muevo al siguente nodo
	}
	putchar('\n');
}


int main()
{
	insert('R');
	insert('o');
	insert('b');
	insert('e');
	insert('r');
	insert('t');
	insert('o');

	imprimeLista();
	pausa;
	return 0;
}
