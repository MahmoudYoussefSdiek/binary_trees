#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the binary tree or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
