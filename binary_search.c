#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int binary_search(int* vector, int vec_size, int target);
int main()
{
	int vec_size;
	int* vector;
	int target;
	int i;

	printf("Insert the vector size: \n");
	scanf("%d", &vec_size);

	vector = (int*) calloc(vec_size, sizeof(int));

	printf("Insert the vector: \n");
	for(i = 0; i < vec_size; ++i)
		scanf("%d", &vector[i]);

	printf("Insert the target value: \n");
	scanf("%d", &target);

	int position = binary_search(vector, vec_size, target);
	if(position == -1)
		printf("The target is not in the vector.\n");
	else
		printf("The target is in the vector[%d] position.\n", position);

	free(vector);
	return 0;
}

int binary_search(int* vector, int vec_size, int target)
{
	int left = 0;
	int right = vec_size - 1;
	int index;
	do
	{
		index = /*floor*/((left + right)/2);
		if(target == vector[index])
			return index;

		else if(target < vector[index])
			right = index - 1;
		
		else
			left = index + 1;
	}while(left <= right); 
	return -1;
}