#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete or 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t tree_size;

	if (tree == NULL)
		return (0);

	tree_size = binary_tree_size(tree);
	if (is_complete(tree, 0, tree_size))
		return (1);

	return (0);
}

/**
 * is_complete - Recursive function to check if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index of the node being checked
 * @nodes_count: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete or 0 if not
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t nodes_count)
{
	int check_right, check_left;

	if (tree == NULL)
		return (1);

	if (index >= nodes_count)
		return (0);

	check_left = is_complete(tree->left, 2 * index + 1, nodes_count);
	check_right = is_complete(tree->right, 2 * index + 2, nodes_count);

	return (check_right && check_left);
}

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
