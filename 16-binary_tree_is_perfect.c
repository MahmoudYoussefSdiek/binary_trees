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
	size_t left_height = 1, right_height = 1;

	if (tree == NULL)
		return (0);

	if (tree->right)
		right_height += binary_tree_height(tree->right);
	if (tree->left)
		left_height += binary_tree_height(tree->left);

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full or 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->right)
		right = binary_tree_is_full(tree->right);
	if (tree->left)
		left = binary_tree_is_full(tree->left);

	return (left && right);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_perfect, right_perfect, full_tree;
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height != right_height)
		return (0);

	if (tree->right)
		left_perfect = binary_tree_is_perfect(tree->left);
	if (tree->left)
		right_perfect = binary_tree_is_perfect(tree->right);

	full_tree = binary_tree_is_full(tree);

	return (left_perfect && right_perfect && full_tree);
}
