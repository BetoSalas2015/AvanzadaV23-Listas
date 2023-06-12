#include "Listas.h"

int main()
{
	char dato;
	nodo *nombre = NULL;
	nodo *apellido = NULL;
	nombre = insert1(nombre, 'R');
	nombre = insert1(nombre,'o');
	nombre = insert1(nombre,'b');
	nombre = insert1(nombre,'e');
	nombre = insert1(nombre,'r');
	nombre = insert1(nombre,'t');
	nombre = insert1(nombre,'o');

	imprimeLista(nombre);

	apellido = insert(apellido, 'S');
	insert(apellido, 'a');
	insert(apellido, 'l');
	insert(apellido, 'a');
	insert(apellido, 'z');
	insert(apellido, 'a');
	insert(apellido, 'r');

	imprimeLista(apellido);

	insertn(apellido, '$',5);
	nombre = remueven(nombre, 5, &dato);
	printf("Salio el dato %c de la lista.\n", dato );

	imprimeLista(nombre);


	pausa;
	return 0;
}
