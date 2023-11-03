#include "binary_trees.h"
#include <stdlib.h>

/**
* binary_tree_size - measures the size of a binary tree
* @tree: pointer to the root node of the tree to measure the size
* Return: size of the tree, or 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
/**
* is_complete - checks if a binary tree is complete
* @tree: pointer to the root node of the tree to check
* @index: index of the node
* @number_nodes: number of nodes in the tree
* Return: 1 if the tree is complete, 0 otherwise
*/
int is_complete(const binary_tree_t *tree, size_t index, size_t number_nodes)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (index >= number_nodes)
	{
		return (0);
	}
	return (is_complete(tree->left, 2 * index + 1, number_nodes) &&
	is_complete(tree->right, 2 * index + 2, number_nodes));
}
/**
* binary_tree_is_complete - checks if a binary tree is complete
* @tree: pointer to the root node of the tree to check
* Return: 1 if the tree is complete, 0 otherwise or if tree is NULL
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t number_nodes = binary_tree_size(tree);

	return (is_complete(tree, 0, number_nodes));
}
