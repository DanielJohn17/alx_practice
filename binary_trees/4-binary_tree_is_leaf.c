#include "binary_trees.h"

int binary_tree_is_leaf(const binary_tree_t *node)
{
	int check_leaf = 0;

	if (node)
	{
		if (!(node->left))
		{
			if (!(node->right))
				check_leaf = 1;
		}
	}

	if (check_leaf == 1)
		return (1);

	return (0);
}
