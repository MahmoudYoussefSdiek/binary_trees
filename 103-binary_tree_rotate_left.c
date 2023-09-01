#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_child;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;

	new_root_child = new_root->left;

	new_root->left = tree;
	tree->parent = new_root;

	tree->right = new_root_child;
	if (new_root_child != NULL)
		new_root_child->parent = tree;

	new_root->parent = NULL;

	return (new_root);
}
