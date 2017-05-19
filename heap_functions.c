#include "stdio.h"
#include "stdlib.h"

#define order_relation /*Depends on the application.*/ <= /*In this case, a Min_heap.*/

typedef struct heap
{
	int* array;
	int array_size;
	int size;	//Number of elements in the heap.
} heap;

heap* heap_insert(heap* Heap, int value);
heap* bubble_up(heap* Heap);
heap* build_heap(heap* Heap);
void heapify(heap* Heap, int sub_tree_index);
int heap_extract(heap* Heap)

int* array_doubleler(int** array, int* array_size);

int main()
{

}

heap* heap_insert(heap* Heap, int value)
{
	if(Heap->size == Heap->array_size);
		Heap->array = array_doubleler(&(Heap->array), &(Heap->array_size));

	Heap->array[Heap->size] = value;
	Heap = bubble_up(Heap);
	Heap->size++;
	return Heap;
}

heap* bubble_up(heap* Heap)
{
	int i = Heap->size - 1;
	while(i > 0 && (Heap->array[i] order_relation Heap->array[(i - 1) / 2]))
	{
		int exchanger = Heap->array[i];
		Heap->array[i] = Heap->array[(i - 1) / 2];
		Heap->array[(i - 1) / 2] = exchanger;

		i = (i - 1) / 2;
	}
	return Heap;
}

heap* build_heap(heap* Heap)
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

	if(left_node < Heap->size && (Heap->array[left_node] order_relation Heap->array[node]))
		node = left_node;
	if(right_node < Heap->size && (Heap->array[right_node] order_relation Heap->array[node]))
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
	int removed = Heap->array[0];
	int exchanger = Heap->array[0];
	Heap->array[0] = Heap->array[Heap->size - 1];
	Heap->array[Heap->size - 1] = exchanger;
	heapify(Heap, 0);
	return removed;
}

/*Requires the order relation to be ">=".*/
void heapsort(int* array, int array_size)
{
	heap* Heap;
	Heap->array = array;
	Heap->array_size = array_size;
	int i;

	build_heap(Heap);
	for(i = array_size - 1; i >= 0 ; --1)
		array[i] = heap_extract(Heap);
}

int* array_doubleler(int** array, int* array_size)
{
	*array = (int*) realloc(*array, *array_size * 2 * sizeof(int));
	*array_size *= 2;
	return *array;
}