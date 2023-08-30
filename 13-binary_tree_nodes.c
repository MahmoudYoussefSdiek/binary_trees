#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 *
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: Number of nodes with at least 1 child or 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		node += 1;
		return (node);
	}

	if (tree->right)
		node += binary_tree_leaves(tree->right);
	if (tree->left)
		node += binary_tree_leaves(tree->left);

	return (node);
}
