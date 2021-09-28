/*
 * 25/09/21
 */

#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <time.h>

size_t g_contador;

int maximo( int list[], size_t elems ){
    int max;
    for (int i = 0; i < elems; i++){
        if (i == 0 or max < list[i] ){
            max = list[i];
        }
    }
    return max;
}

int minimo( int list[], size_t elems ){
    int min;
    for (int i = 0; i < elems; ++i){
        if (i == 0 or min > list[i] ){
            min = list[i];
        }
    }
    return min;
}

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
 * @param elems  El número de elementos en la lista.
 * @param low    Índice al primer elemento de la lista.
 * @param high   Índice al último elemento de la lista.
 */
void counting_sort( int list[], size_t num_elems, size_t low, size_t high ){
    size_t capacity = high - low +1;
    fprintf(stderr, "Capacity: %ld\n", capacity);
    int* aux = calloc(capacity, sizeof(int));

    for (size_t i = 0; i < num_elems; ++i){
        size_t pos = list[i];
        
        int acum = aux[pos];
        acum = acum +1;
        aux[pos] = acum;
        
        //aux[pos]++;
        ++g_contador;
    }

    size_t j = 0;
    for (size_t i = 0; i < capacity; ++i){
        for (size_t reps = aux[i]; reps > 0; --reps){
            list[j] = i;
            ++j;
            ++g_contador;
        }
    }

    free(aux);
}

#define NUM_ELEMS 50

int main(){
	
    //int list[ NUM_ELEMS ] = { 1, 4, 1, 2, 7, 5, 2 };

    srand(time(NULL));

    int list[NUM_ELEMS];

    for (int i = 0; i < NUM_ELEMS; ++i){
        list[i] = rand() % 50;
    }

	print( list, NUM_ELEMS, "  Antes: " );

    counting_sort(list, NUM_ELEMS, minimo(list, NUM_ELEMS), maximo(list, NUM_ELEMS));

	print( list, NUM_ELEMS, "Después: " );

    printf("\nContador: %ld\n", g_contador);

    printf("Maximo: %d\n", maximo(list, NUM_ELEMS));

    printf("Minimo: %d\n", minimo(list, NUM_ELEMS));
}

