#include <stdlib.h>
#include <stdio.h>


/**
 * @brief Imprime una lista de valores enteros.
 *
 * @param list La lista de números enteros.
 * @param tam El número de elementos en la lista.
 * @param msg Un mensaje de texto explicativo.
 */
void print( int* list, size_t tam, char* msg )
{
	printf( "%s", msg );
	for( size_t i = 0; i < tam; ++i ){
		printf( "%d, ", list[ i ] );
	}
	printf( "\n" );
}

/**
 * @brief Ordena en forma ascendente una lista de valores enteros utilizando al algoritmo counting sort.
 *
 * @param list[] La lista de números enteros
 * @param num_elems El número de elementos en la lista.
 * @param low Índice al primer elemento de la lista.
 * @param high Índice al último elemento de la lista.
 */
void counting_sort( int list[], size_t num_elems, size_t low, size_t high )
{
	// terminar
}

#define NUM_ELEMS 7

int main()
{
	int list[ NUM_ELEMS ] = { 1, 4, 1, 2, 7, 5, 2 };

	print( list, NUM_ELEMS, "Antes: " );

	counting_sort( list, NUM_ELEMS, 0, 9 );

	print( list, NUM_ELEMS, "Después: " );
}

