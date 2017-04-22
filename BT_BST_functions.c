#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct tree
{
	struct tree* left;
	struct tree* right;
	int value;
} tree;

tree* BST_delete(tree* root, int value);
tree* BST_delete_min(tree* root);
tree* BST_search(tree* root, int value);
tree* BST_insert(tree* root, int value);
int max(int a, int b);

int BT_height(tree* root);
bool BT_pre_order(tree* root);
bool BT_in_order(tree* root);
bool BT_post_order(tree* root);

int global;

int main()
{
	tree* root = NULL;

	int value;
	int command;
	do 
	{
		printf("Type 1 to insert a node, 2 to delete or 0 to exit: ");
		scanf("%d", &command);

		if(command == 1)
		{
			printf("Type the value to be inserted: ");
			scanf("%d", &value);
			root = BST_insert(root, value);
			printf("Height of the Tree: %d\n", BT_height(root));
			
			printf("Pre-order Traversal:\n");
			BT_pre_order(root);
			printf("\n");

			printf("In-order Traversal:\n");
			BT_in_order(root);
			printf("\n");

			printf("Post-order Traversal:\n");
			BT_post_order(root);
			printf("\n");
		}
		else if(command == 2)
		{
			printf("Type the value to be deleted: ");
			scanf("%d", &value);
			root = BST_delete(root, value);
			printf("Height of the Tree: %d\n", BT_height(root));
			
			printf("Pre-order Traversal:\n");
			BT_pre_order(root);
			printf("\n");

			printf("In-order Traversal:\n");
			BT_in_order(root);
			printf("\n");

			printf("Post-order Traversal:\n");
			BT_post_order(root);
			printf("\n");
		}

	} while(command != 0);

	return 0;
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

bool BT_post_order(tree* root)
{
	if(root != NULL)
	{
		BT_post_order(root->left);
		BT_post_order(root->right);
		printf("%d ", root->value);
		return true;
	}
	return false;
}