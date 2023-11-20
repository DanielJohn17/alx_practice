#include "binary_trees.h"

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = parent->right;

	if (parent->right != NULL)
		parent->right->parent = new;

	parent->right = new;

	return (new);
}
