#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
// bool, true, false

#include <iso646.h>
// and, or, not

#include <time.h>

#include<math.h>

#include "Queue.h"
// va con comillas porque es nuestro


typedef int Item;

size_t g_contador;

void print( int* list, int tam, char* msg )
{
	printf( "%s", msg );
	for( int i = 0; i < tam; ++i ){
		printf( "%d, ", list[ i ] );
	}
	printf( "\n" );
}

int subKey( int val, int pos, int radix ){
    
    int divisor = pow(10, pos - 1);

    int res = (int)+((val / divisor) % radix);

    return res;
}

void collect( int list[], Queue* queues[], int radix ){
    int index = 0;
    for (int i = 0; i < radix; ++i){
        while(Queue_IsEmpty(queues[i]) == false){
            
            int val;
            Queue_Dequeue(queues[i], &val);
            
            list[index] = val;

            //fprintf(stderr, "Desencolando el valor %d de la cola %d y escribiendola en list[%d] \n", val, i, index);

            ++index;

            ++g_contador;
            //incrementa la variable global 
        }
    }
}

void radix_sort( int list[], int elems, int pos, int radix ){
    Queue *queues[ radix ];
    // guarda las direcciones de 10 colas 

    ++g_contador;
    //incrementa la variable global

    for (int i = 0; i < radix; ++i){
        //fprintf(stderr, "Creando la cola %d\n", i);
        queues[i] = Queue_New();
    }

    for (int i = 1; i <= pos; ++i){
        //fprintf(stderr, "Ronda %d\n", i);

        for (int j = 0; j < elems; ++j){

            int whichQ = subKey( list[j], i, radix);
            //fprintf(stderr, "Encolando el valor %d en la cola%d\n", list[j], whichQ);
            Queue_Enqueue( queues[whichQ], list[j]);
        }

        collect(list, queues, radix);
    }

    for (int i = 0; i < radix; ++i){
        //fprintf(stderr, "Eliminando la cola %d\n", i);
        Queue_Delete( queues[i]);
    }
}

#define NUM_ELEMS 50

int main()
{
	//Item list[ NUM_ELEMS ] = { 630, 421, 527, 911, 912, 266, 85 };

    srand(time(NULL));

    int list[NUM_ELEMS];

    for (int i = 0; i < NUM_ELEMS; ++i){
        list[i] = rand() % 50;
    }

	print( list, NUM_ELEMS, "  Antes: " );

    radix_sort(list, NUM_ELEMS, 4, 49);

    printf("\ncontador %ld\n", g_contador );

	print( list, NUM_ELEMS, "Después: " );
}
