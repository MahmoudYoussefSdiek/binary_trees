#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_child;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	new_root = tree->left;

	new_root_child = new_root->right;

	new_root->right = tree;
	tree->parent = new_root;

	tree->left = new_root_child;
	if (new_root_child != NULL)
		new_root_child->parent = tree;

	new_root->parent = NULL;

	return (new_root);
}
