#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
* binary_tree_height - measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height
* Return: height of the tree, or 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left != NULL)
	{
		left_height = 1 + binary_tree_height(tree->left);
	}
	if (tree->right != NULL)
	{
		right_height = 1 + binary_tree_height(tree->right);
	}
	return (left_height > right_height ? left_height : right_height);
}
/**
* print_given_level - Prints the nodes at a given level
* @tree: Pointer to the root node of the tree to traverse
* @level: The level at which to print nodes
* @func: Pointer to a function to call for each node
*/
void print_given_level(const binary_tree_t *tree, size_t level,
void (*func)(int))
{
	if (!tree)
	{
		return;
	}
	if (level == 1)
	{
		func(tree->n);
	}
	else if (level > 1)
	{
		print_given_level(tree->left, level - 1, func);
		print_given_level(tree->right, level - 1, func);
	}
}
/**
* binary_tree_levelorder - Goes through a binary tree using
* level - order traversal
* @tree: Pointer to the root node of the tree to traverse
* @func: Pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h;
	size_t i;

	if (!tree || !func)
	{
		return;
	}
	h = binary_tree_height(tree) + 1;
	for (i = 1; i <= h; i++)
	{
		print_given_level(tree, i, func);
	}
}
