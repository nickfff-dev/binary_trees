#include "binary_trees.h"

/**
* binary_trees_ancestor - finds the lowest common ancestor of two nodes
* @first: pointer to the first node
* @second: pointer to the second node
* Return: pointer to the lowest common ancestor node
* of the two given nodes
* If no common ancestor was found, your function must return NULL
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
binary_tree_t *m, *n;
if (first == NULL || second == NULL)
{
return (NULL);
}
m = (binary_tree_t *)first;
n = (binary_tree_t *)second;
while (m != NULL)
{
while (n != NULL)
{
if (m == n)
{
return (m);
}
n = n->parent;
}
m = m->parent;
n = (binary_tree_t *)second;
}
return (NULL);
}
