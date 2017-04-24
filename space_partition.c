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
tree* BST_builder(long long int* obj_arr, long long int obj_num);

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
	long long int i;
	char command[3];


	long long int* obj_arr;

	scanf("%lld %lld %lld %lld %lld", &obj_num, &dist_sup_lim, &seedD, &param_A, &param_C);
	obj_arr = (long long int*) malloc(obj_num * sizeof(long long int));
	
	//call the scene_array_builder function
	scene_array_builder(obj_arr, obj_num, seedD, param_A, param_C, dist_sup_lim);
	
	//call the BST_builder function
	root = BST_builder(obj_arr, obj_num);

	/*scanf("%lld", &op_quant);
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
	}*/
	return 0;
}

tree* BST_builder(long long int* obj_arr, long long int obj_num)
{
	
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