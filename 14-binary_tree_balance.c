#include "binary_trees.h"
/**
* binary_tree_balance - measures the balance factor of a binary tree
* @tree: pointer to the root node of the tree to measure the balance
* Return: balance factor of the tree, or 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left != NULL)
	{
		left_height = binary_tree_height(tree->left) + 1;
	}
	if (tree->right != NULL)
	{
		right_height = binary_tree_height(tree->right) + 1;
	}
	return (left_height - right_height);
}
