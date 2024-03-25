#include "binary_trees.h"

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Root of the tree
 * Return: The height
 */

int _height(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (0);

	l = _height(tree->left) + 1;
	r = _height(tree->right) + 1;

	return (l > r ? l : r);
}

/**
 * recursion - Do the recursion
 *
 * @tree: Root of the tree
 * @min: Minimum of the previous node
 * @max: Maximum of the previous node
 * Return: 1 if yes, 0 otherwise
 */

int recursion(const binary_tree_t *tree, int min, int max)
{
	int h_left, h_right;

	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);

	h_left = _height(tree->left);
	h_right = _height(tree->right);

	if (abs(h_left - h_right) > 1)
		return (0);

	return (recursion(tree->left, min, tree->n) &&
			recursion(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *
 * @tree: Root of the tree
 *Return: 1 if yes, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recursion(tree, -1000, 1000));
}
