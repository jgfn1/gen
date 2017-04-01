#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#define str_max_size 100

typedef struct bloom_filter
{
	int bool_vec_size;	//M
	bool* bool_vec;	//V[M]
	
	int str_quant;	//N
	char** str_vec;	//str[N]

	int hash_func_quant;	//K
	int* hash_func_base;	//B[K]

	int queries_quant;	//Q
	char** query_str_vec;	//T[Q]

} bloom_filter;

int binary_search_string(char** vector, int str_quant, char* target);
void bloom_add(bloom_filter* bloom);
int bloom_query(bloom_filter* bloom);

int main()
{
	bloom_filter* bloom;
	

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