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
int bloom_query(bloom_filter* bloom);

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
	for(i = 0; i < bloom.bool_vec_size; ++i)
		scanf("%d", &bloom.hash_base_vec[i]);

	

}

void bloom_add(bloom_filter* bloom)
{

}

int bloom_query(bloom_filter* bloom)
{

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