#include "binary_trees.h"

int binary_tree_is_root(const binary_tree_t *node)
{
	int check_root = 0;

	if (node)
	{
		if (!(node->parent))
			check_root = 1;
	}

	if (check_root == 1)
		return (1);

	return (0);
}
