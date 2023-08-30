#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);
	size = 1;

	if (tree->right)
		size += binary_tree_size(tree->right);
	if (tree->left)
		size += binary_tree_size(tree->left);

	return (size);
}
