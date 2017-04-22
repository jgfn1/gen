#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct tree
{
	struct tree* left;
	struct tree* right;
	int value;
} tree;

int main()
{
	tree* root;
	return 0;
}

tree* BST_delete(tree* root, int value)
{
	if(root == NULL)
		return NULL;
	else if(value < root->value)
		root->left = BST_delete(root->left, value);
		return root;
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
			root->value = BST_delete_min(root->right);
			return root;
		}
	}
}

int BST_delete_min(tree* root)	//The root shall not be NULL
{
	if(root->left == NULL)
	{
		tree* new_root = root->right;	
		tree* old_root = root;
		root = new_root;
		int removed_value = root->value;
		free(old_root);
		return removed_value;
	}
	else
		return BST_delete_min(root->left);
}

tree* BST_search(tree* root, int value)
{
	if(root != NULL)
	{
		if(root->value == value)
			return root;
		
		else if(value < root->value)
			return BST_search(root->left, value);
		
		else 
			return BST_search(root->right, value);
	}
	return NULL;
}

tree* BST_insert(tree* root, int value)
{
	if(root == NULL)
	{
		tree* node = (tree*) malloc(sizeof(tree));
		node->value = v;
		node->left = NULL;
		node->right = NULL;
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
	(a >= b)? return a : return b;
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
		printf("%d\n", root->value);
		pre_order(root->left);
		pre_order(root->right);
		return true;
	}
	return false;
}

bool BT_in_order(tree* root)
{
	if(root != NULL)
	{
		pre_order(root->left);
		printf("%d\n", root->value);
		pre_order(root->right);
		return true;
	}
	return false;
}

bool BT_post_order(tree* root)
{
	if(root != NULL)
	{
		pre_order(root->left);
		pre_order(root->right);
		printf("%d\n", root->value);
		return true;
	}
	return false;
}