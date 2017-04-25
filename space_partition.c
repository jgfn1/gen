#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

typedef struct tree
{
	struct tree* left;
	struct tree* right;
	int value;
} tree;

tree* BST_delete(tree* root, int value);
tree* BST_delete_min(tree* root);
tree* BST_insert(tree* root, int value);
int max(int a, int b);

int BT_height(tree* root);
bool BT_pre_order(tree* root);
bool BT_in_order(tree* root);

void scene_array_builder(long long int* obj_arr, long long int obj_num, long long int seedD, long long int param_A, long long int param_C, long long int dist_sup_lim);
tree* BST_builder(long long int* obj_arr, long long int num_of_elem);

int global;

int main()
{
	tree* root = NULL;
	long long int obj_num;			//N
	long long int dist_sup_lim;		//M
	long long int seedD;			//seedD
	long long int param_A;			//A
	long long int param_C;			//C
	long long int op_quant;			//Q
	long long int insert_dist;		//D
	long long int left_del_lim;		//L
	long long int right_del_lim;	//R
	long long int i = 0;
	char command[3];


	long long int* obj_arr;

	scanf("%lld %lld %lld %lld %lld", &obj_num, &dist_sup_lim, &seedD, &param_A, &param_C);
	obj_arr = (long long int*) malloc(obj_num * sizeof(long long int));
	
	//call the scene_array_builder function
	scene_array_builder(obj_arr, obj_num, seedD, param_A, param_C, dist_sup_lim);
	
	//call the BST_builder function
	root = BST_builder(obj_arr, obj_num);

	printf("%lld: %d\n", i, BT_height(root));

	scanf("%lld", &op_quant);
	for(i = 0; i < op_quant; ++i)
	{
		scanf("%[^\n]", command);
		if( !(strcmp(command, "ADD")) )
		{
			scanf("%lld", &insert_dist);
			//call insertion function
		}
		else if( !(strcmp(command, "DEL")) )
		{
			scanf("%lld %lld", &left_del_lim, &right_del_lim);
			//call deletion function
		}
	}
	return 0;
}

/*long long int median(long long int a, long long int b, long long int c)
{
	if(a > b && a > c)
	{
		if(b > c)
			return b;
		else
			return c;
	}
	else if(a < b && a < c);
	{
		if(b > c)
			return c;
		else
			return b;
	}
	else
		return a;	
}*/

tree* BST_builder(long long int* obj_arr, long long int num_of_elem)
{
	if(num_of_elem > 0)
	{
		tree* root = NULL;
		long long int pivot;	
		long long int i = 0;
		long long int j = 0;
		long long int k = 0;

		if(num_of_elem < 3)
		{
			pivot = obj_arr[0];
			obj_arr[0] = -1;
		}
		else
		{
			long long int a;
			long long int b;
			long long int c;
			a = obj_arr[0];
			b = obj_arr[ (num_of_elem - 1)/2 ];
			c = obj_arr[num_of_elem - 1];
			
			if(a > b && a > c)
			{
				if(b > c)
				{
					pivot = b;
					obj_arr[ (num_of_elem - 1)/2 ] = -1;
				}
				else
				{
					pivot = c;
					obj_arr[num_of_elem - 1] = -1;		
				}
			}
			else if(a < b && a < c)
			{
				if(b > c)
				{
					pivot = c;
					obj_arr[num_of_elem - 1] = -1;
				}
				else
				{
					pivot = b;
					obj_arr[ (num_of_elem - 1)/2 ] = -1;	
				}	
			}
			else
			{
				pivot = a;
				obj_arr[0] = -1;
			}
			// printf("Pivot: %lld\n", pivot);
		}

		long long int* left_array = (long long int*) malloc((num_of_elem - 1) * sizeof(long long int));
		long long int* right_array = (long long int*) malloc((num_of_elem - 1) * sizeof(long long int));
		
		for(i = 0; i < num_of_elem; ++i)
		{
			if(obj_arr[i] < pivot && obj_arr[i] != -1)
			{
				left_array[j] = obj_arr[i];
				j++;
			}
			else if(obj_arr[i] != -1)
			{
				right_array[k] = obj_arr[i];
				k++;
			}
		}

		root = BST_insert(root, pivot);
		root->left = BST_builder(left_array, j);
		root->right = BST_builder(right_array, k);
		return root;
	}
	return NULL;
}

void scene_array_builder(long long int* obj_arr, long long int obj_num, long long int seedD, long long int param_A, long long int param_C, long long int dist_sup_lim)
{
	obj_arr[0] = seedD;
	// printf("seedD: %lld\n", obj_arr[0]);
	long long int i;
	for(i = 1; i < obj_num; ++i)
	{
		obj_arr[i] = (((param_A * obj_arr[i - 1]) + param_C) % dist_sup_lim);
		// printf("obj_arr[%lld]: %lld\n", i, obj_arr[i]);
	}	
}

tree* BST_delete(tree* root, int value)
{
	if(root == NULL)
		return NULL;
	else if(value < root->value)
	{
		root->left = BST_delete(root->left, value);
		return root;
	}
	else if(value > root->value)
	{
		root->right = BST_delete(root->right, value);
		return root;
	}
	else// value == root->value
	{
		if(root->left == NULL)
		{
			tree* new_root = root->right;
			free(root);
			return new_root;
		}
		else if(root->right == NULL)
		{
			tree* new_root = root->left;
			free(root);
			return new_root;
		}
		else
		{
			root->right = BST_delete_min(root->right);
			root->value = global;
			return root;
		}
	}
}

tree* BST_delete_min(tree* root)	//The root shall not be NULL
{
	tree* new_root;
	if(root->left == NULL)
	{
		new_root = root->right;	
		global = root->value;
		free(root);
		return new_root;
	}
	else
		root->left = BST_delete_min(root->left);
		return root;
}

tree* BST_insert(tree* root, int value)
{
	if(root == NULL)
	{
		tree* node = (tree*) malloc(sizeof(tree));
		node->value = value;
		node->left = NULL;
		node->right = NULL;
		root = node;
		return node;
	}
	else if(value < root->value)
	{
		root->left = BST_insert(root->left, value);
		return root;
	}
	else
	{
		root->right = BST_insert(root->right, value);
		return root;
	}
}

int max(int a, int b)
{
	return (a >= b)? a : b;
}

int BT_height(tree* root)
{
	if(root != NULL)
	{
		int left_height = BT_height(root->left);
		int right_height = BT_height(root->right);
		return (1 + max(left_height, right_height));
	}
	return 0;
}

bool BT_pre_order(tree* root)
{
	if(root != NULL)
	{
		printf("%d ", root->value);
		BT_pre_order(root->left);
		BT_pre_order(root->right);
		return true;
	}
	return false;
}

bool BT_in_order(tree* root)
{
	if(root != NULL)
	{
		BT_in_order(root->left);
		printf("%d ", root->value);
		BT_in_order(root->right);
		return true;
	}
	return false;
}