/*Copyright (C) 
 * 2019 - eda1 dot fiunam at yahoo dot com dot mx
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */


#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
// bool, true, false

#include <iso646.h>
// and, or, not

#include<math.h>

#include "Queue.h"
// va con comillas porque es nuestro


typedef int Item;

void print( int* list, size_t tam, char* msg )
{
	printf( "%s", msg );
	for( size_t i = 0; i < tam; ++i ){
		printf( "%d, ", list[ i ] );
	}
	printf( "\n" );
}

int subKey( int val, int pos, int radix ){
    int divisor = pow(10.0, pos - 1);

    int resultado = (int) ((val / divisor) % radix);
}

void collect( int list[], Queue* queues[], int radix ){
    size_t index = 0;
    for (int i = 0; i < radix; ++i)
    {
        while(Queue_IsEmpty(queues[i]) == false){
            int val;
            Queue_Dequeue(queues[i], &val);
            list[index] = val;

            fprintf(stderr, "Desencolando el valor %d de la cola %ld y escribiendola en list[%ld] \n", val, i, index);

            ++index;
        }
    }
}

void radix_sort( int list[], size_t elems, int pos, int radix ){
    Queues *queues[ radix ];
    // guarda las direcciones de 10 colas 

    for (int i = 0; i < radix; ++i){
        fprintf(stderr, "Creando la cola %ld\n", i);
        queues[i] = Queue_New();
    }

    for (int i = 1; i <= pos; ++i){
        fprintf(stderr, "Ronda %ld\n", i);

        for (int j = 0; j < elems; ++j){

            size_t whichQ = subKey( list[j], i, radix);
            fprintf(stderr, "Encolando el valor %d en la cola%ld\n", list[j], whichQ);
            Queue_Enqueue( queues[whichQ], list[j]);
        }
    }

    for (int i = 0; i < radix; ++i){
        fprintf(stderr, "Eliminando la cola %ld\n", i);
        Queue_Delete( queues[i]);
    }
}

#define NUM_ELEMS 7

int main()
{
	Item list[ NUM_ELEMS ] = { 630, 421, 527, 911, 912, 266, 85 };

	print( list, NUM_ELEMS, "  Antes: " );

    radix_sort(list, NUM_ELEMS, 3, 10);

	print( list, NUM_ELEMS, "Después: " );
}
