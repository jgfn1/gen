#include "stdio.h"
#include "stdlib.h"

//#define /*order_relation*/ <= /*Depends on the application.*/ <= /*In this case, a Min_heap.*/

typedef struct heap
{
    int* array;
    int array_size;
    int size;	//Number of elements in the heap.
} heap;

heap* heap_insert(heap* Heap, int value);
heap* bubble_up(heap* Heap);
void build_heap(heap* Heap);
void heapify(heap* Heap, int sub_tree_index);
int heap_extract(heap* Heap);
void heapsort(int* array, int array_size);

int* array_doubleler(int** array, int* array_size);

int main()
{
    heap Heap;
    Heap.array = (int*) malloc(sizeof(int));
    Heap.array_size = 1;
    Heap.size = 0;
    int command;
    do
    {
        printf("Type 1 to insert, 2 to extract, 3 to heapsort or 0 to leave.\n");
        scanf("%d", &command);
        switch(command)
        {
            case 1:
            {
                int value;
                printf("Type the value to be inserted:\n");
                scanf("%d", &value);
                heap_insert(&Heap, value);
                break;
            }
            case 2:
            {
                printf("Removed value: \n%d\n", heap_extract(&Heap));
                break;
            }
            case 3:
            {
                int* array;
                int array_size;
                int i;

                printf("Insert the array size:\n");
                scanf("%d", &array_size);

                array = (int*) malloc(array_size * sizeof(int));

                printf("Insert the array:\n");
                for(i = 0; i < array_size; ++i)
                {
                    scanf("%d", &array[i]);
                }

                heapsort(array, array_size);
                for(i = 0; i < array_size; ++i)
                {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            }
            default:
                break;
        }
    } while(command != 0);
    return 0;
}

heap* heap_insert(heap* Heap, int value)
{
    if(Heap->size == Heap->array_size)
        Heap->array = array_doubleler(&(Heap->array), &(Heap->array_size));

    Heap->array[Heap->size] = value;
    Heap->size++;
    Heap = bubble_up(Heap);
    return Heap;
}

heap* bubble_up(heap* Heap)
{
    int i = Heap->size - 1;
    while(i > 0 && (Heap->array[i] /*order_relation*/ <= Heap->array[(i - 1) / 2]))
    {
        int exchanger = Heap->array[i];
        Heap->array[i] = Heap->array[(i - 1) / 2];
        Heap->array[(i - 1) / 2] = exchanger;

        i = (i - 1) / 2;
    }
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
        int exchanger = Heap->array[sub_tree_index];
        Heap->array[sub_tree_index] = Heap->array[node];
        Heap->array[node] = exchanger;
        heapify(Heap, node);
    }
}

int heap_extract(heap* Heap)
{
    int removed = -1;
    if(Heap->size > 0)
    {
        removed = Heap->array[0];
        int exchanger = Heap->array[0];
        Heap->array[0] = Heap->array[Heap->size - 1];
        Heap->array[Heap->size - 1] = exchanger;
        Heap->size--;
        heapify(Heap, 0);
    }
    return removed;
}

/*Requires the order relation to be ">=".*/
void heapsort(int* array, int array_size)
{
    heap Heap;
    Heap.array_size = array_size;
    Heap.array = array;
    Heap.size = array_size;
    int i;

    build_heap(&Heap);
    for(i = (array_size - 1); i >= 0 ; --i)
        array[i] = heap_extract(&Heap);
}

int* array_doubleler(int** array, int* array_size)
{
    *array = (int*) realloc(*array, *(array_size) * 2 * sizeof(int));
    *array_size *= 2;
    return *array;
}