/*
	Binary Search Algorithm altered to find a string in a vector.
	Made by jgfn1@github.com
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define str_max_size 100

int binary_search_string(char** vector, int str_quant, char* target);

int main()
{
	int str_quant;
	char** vector;
	char* target;
	int i;

	printf("Insert the string quantity: \n");
	scanf("%d", &str_quant);

	vector = (char**) malloc(str_quant * sizeof(char*));
	for(i = 0; i < str_quant; ++i)
		vector[i] = (char*) malloc(str_max_size * sizeof(char));

	printf("Insert the strings: \n");
	for(i = 0; i < str_quant; ++i)
		scanf(" %s", vector[i]);

	target = (char*) malloc(str_max_size * sizeof(char));
	printf("Insert the target string: \n");
	scanf(" %s", target);

	int position = binary_search_string(vector, str_quant, target);
	if(position == -1)
		printf("The target is not in the vector.\n");
	else
		printf("The target is in the vector[%d] position.\n", position);

	free(vector);
	return 0;
}

int binary_search_string(char** vector, int str_quant, char* target)
{
	int left = 0;
	int right = str_quant - 1;
	int index;
	do
	{
		index = /*floor*/((left + right)/2);
		if((strcmp(target, vector[index])) == 0)
			return index;

		else if(((strcmp(target, vector[index])) < 0)) 
			right = index - 1;
		
		else
			left = index + 1;
	}while(left <= right); 
	return -1;
}