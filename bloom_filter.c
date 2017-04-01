#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#define str_max_size 100

typedef struct bloom_filter
{
	int str_quant;	//N
	char** str_vec;	//str[N]
	
	int bool_vec_size;	//M
	bool* bool_vec;	//V[M]

	int hash_func_quant;	//K
	int* hash_base_vec;	//B[K]

	int queries_quant;	//Q
	char** query_str_vec;	//T[Q]

} bloom_filter;

int binary_search_string(char** vector, int str_quant, char* target);
void bloom_add(bloom_filter* bloom);
int bloom_query(bloom_filter* bloom, char* target);

int main()
{
	bloom_filter bloom;
	int i;
	scanf("%d", &(bloom.str_quant)); //Reads the number of users

	//Allocates the vector which saves the users' strings
	bloom.str_vec = (char**) malloc(bloom.str_quant * sizeof(char*));
	for (i = 0; i < bloom.str_quant; ++i)
		bloom.str_vec[i] = (char*) malloc(str_max_size * sizeof(char));

	//Reads all the users' strings
	for(i = 0; i < bloom.str_quant; ++i)
		scanf(" %s", bloom.str_vec[i]);

	//Reads the size of the boolean vector and the quantity of hash
	//functions.
	scanf("%d %d", &bloom.bool_vec_size, &bloom.hash_func_quant);

	//Allocates the boolean vector and the vector of hash bases
	bloom.bool_vec = (bool*) calloc(bloom.bool_vec_size, sizeof(bool));
	bloom.hash_base_vec = (int*) malloc(bloom.hash_func_quant * sizeof(int));
	
	//Reads all the hash bases
	for(i = 0; i < bloom.hash_func_quant; ++i)
	{
		scanf("%d", &bloom.hash_base_vec[i]);
	}

	//Executes the hash function and set the bool_vec values
	bloom_add(&bloom);

	//Reads the quantity of queries to be made
	scanf("%d", &bloom.queries_quant);

	//Allocates the vector which saves the queries' strings
	bloom.query_str_vec = (char**) malloc(bloom.queries_quant * sizeof(char*));
	for (i = 0; i < bloom.queries_quant; ++i)
		bloom.query_str_vec[i] = (char*) malloc(str_max_size * sizeof(char));	

	//Reads all the queries' strings
	for(i = 0; i < bloom.queries_quant; ++i)
	{
		scanf(" %s", bloom.query_str_vec[i]);
	 	printf("%d\n", bloom_query(&bloom, bloom.query_str_vec[i]));
	}

	return 0;
}

void bloom_add(bloom_filter* bloom)
{
	int i;
	int j;
	int k;
	int index;
	int str_size;
	//For all the users' strings
	for(i = 0; i < bloom->str_quant; ++i)
	{
		str_size = strlen(bloom->str_vec[i]);
		//For all the bases'-based hash functions
		for(j = 0; j < bloom->hash_func_quant; ++j)
		{
			index = 0;
			//Compute the indexes' value feeding the hash function with all the characters of the string
			for(k = (str_size - 1); k > -1; k--)
			{
				index = ((bloom->str_vec[i][k] + (bloom->hash_base_vec[j] * index)) % bloom->bool_vec_size);
			}
			bloom->bool_vec[index] = 1;
			// printf("Vector[%d] = 1\n", index);
		}
		// printf("\n");
	}
	
}

int bloom_query(bloom_filter* bloom, char* target)
{
	int j;
	int k;
	int index;
	int str_size;
	//For the queried string
	str_size = strlen(target);
	//For all the bases'-based hash functions
	for(j = 0; j < bloom->queries_quant; ++j)
	{
		// printf("b--lau\n");
		index = 0;
		//Checks if the queried string is in the Bloom Filter
		for(k = (str_size - 1); k > -1; --k)
		{
			index = ((target[k] + (bloom->hash_base_vec[j] * index)) % bloom->bool_vec_size);
		}	
			if(bloom->bool_vec[index] == 0)
			{
				printf("index 0: %d\n", index);
				return 0;
			}
	}
	int result = binary_search_string(bloom->str_vec, bloom->str_quant, target);
	int i;
	for(i = 0; i < bloom->bool_vec_size; ++i)
		printf("bool_vec[%d] = %d\n", i, bloom->bool_vec[i]);
	printf("String: %s\n", target);
	printf("Result: %d\n", result);
	if(result != -1)
		return 1;
	else
		return 2;
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