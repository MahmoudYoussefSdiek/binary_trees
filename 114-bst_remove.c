#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 *
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = get_min_value(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}

/**
 * get_min_value - Finds the minimum value node in a Binary Search Tree
 *
 * @node: Pointer to the root node of the tree
 *
 * Return: Pointer to the node with the minimum value
 */
bst_t *get_min_value(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
		current = current->left;

	return (current);
}
