#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct heap
{
    char* array;
    int array_size;
    int size;	//Number of elements in the heap.
} heap;

heap* heap_insert(heap* Heap, char value);
heap* bubble_up(heap* Heap);
void build_heap(heap* Heap);
void heapify(heap* Heap, int sub_tree_index);
char heap_extract(heap* Heap);

char* array_doubleler(char** array, int* array_size);

int main()
{
    heap Heap;
    Heap.array = (char*) malloc(sizeof(char));
    Heap.array_size = 1;
    Heap.size = 0;
    char alphabet[63];
    char instruction[5];
    char push[5] = "PUSH";
    char pop[5] = "POP";
    char message[2000000000];
    long int op_num;
    long int pop_num;
    long int i;
    int order_relation[123];
    scanf("%s", alphabet);

    for(i = 0; i < 63; ++i)
    {
    	order_relation[(int) alphabet[i]] = (int) i;
    }

	scanf("%ld", &op_num);
    for(i = 0; i < op_num; ++i)
    {
    	scanf("%s", instruction);
    	if((strcmp(instruction, push)) == 0)
    	{
    		scanf("%s", message);
    		if(Heap.size == 0)
    		{
    			Heap.array = message;
    			Heap.size = (int) strlen(message);
    			build_heap(&Heap);
    		}
    		else if(Heap.size > 0)
    		{
    			for(i = 0; message[i] != '\0'; ++i)
    			{
    				heap_insert(&Heap, message[i]);
    			}
    		}
    	}
    	else if((strcmp(instruction, pop)) == 0)
    	{
    		char temp;
    		scanf("%ld", &pop_num);
    		for (i = 0; i < pop_num; ++i)
    		{
    			temp = heap_extract(&Heap);
    			if((temp > 64 && temp < 78) || (temp > 96 && temp < 110))
    				temp += 13;
    			else if((temp > 77 && temp < 91) || (temp > 109 && temp < 123))
    				temp -= 13;
    			printf("%c", temp);
    		}
    		printf("\n");
    	}
    }
    return 0;
}

heap* bubble_up(heap* Heap)
{
    int i = Heap->size - 1;
    while(i > 0 && (Heap->array[i] /*order_relation*/ <= Heap->array[(i - 1) / 2]))
    {
        char exchanger = Heap->array[i];
        Heap->array[i] = Heap->array[(i - 1) / 2];
        Heap->array[(i - 1) / 2] = exchanger;

        i = (i - 1) / 2;
    }
    return Heap;
}

heap* heap_insert(heap* Heap, char value)
{
    if(Heap->size == Heap->array_size)
        Heap->array = array_doubleler(&(Heap->array), &(Heap->array_size));

    Heap->array[Heap->size] = value;
    Heap->size++;
    Heap = bubble_up(Heap);
    return Heap;
}

void build_heap(heap* Heap)
{
    int i;
    for(i = ((Heap->size / 2) - 1); i >= 0; --i)
        heapify(Heap, i);
}

void heapify(heap* Heap, int sub_tree_index)
{
    int left_node = (2 * sub_tree_index) + 1;
    int right_node = (2 * sub_tree_index) + 2;
    int node = sub_tree_index;

    if(left_node < Heap->size && (Heap->array[left_node] /*order_relation*/ <= Heap->array[node]))
        node = left_node;
    if(right_node < Heap->size && (Heap->array[right_node] /*order_relation*/ <= Heap->array[node]))
        node = right_node;

    if(node != sub_tree_index)
    {
        char exchanger;
        exchanger = Heap->array[sub_tree_index];
        Heap->array[sub_tree_index] = Heap->array[node];
        Heap->array[node] = exchanger;
        heapify(Heap, node);
    }
}

char heap_extract(heap* Heap)
{
    char removed = -1;
    if(Heap->size > 0)
    {
        removed = Heap->array[0];
        char exchanger = Heap->array[0];
        Heap->array[0] = Heap->array[Heap->size - 1];
        Heap->array[Heap->size - 1] = exchanger;
        Heap->size--;
        heapify(Heap, 0);
    }
    return removed;
}

char* array_doubleler(char** array, int* array_size)
{
    *array = (char*) realloc(*array, *(array_size) * 2 * sizeof(char));
    *array_size *= 2;
    return *array;
}