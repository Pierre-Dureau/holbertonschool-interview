#include "binary_trees.h"

/**
 * swap - Swap the value of a node with its parent
 *
 * @node: The node
 */

void swap(heap_t *node)
{
	int t;

	t = node->n;
	node->n = node->parent->n;
	node->parent->n = t;
}

/**
 * _size - measures the size of a binary tree
 *
 * @tree: Root of the tree
 * Return: The size
 */

size_t _size(const binary_tree_t *tree)
{
	size_t s = 0;

	if (!tree)
		return (0);

	s = _size(tree->left) + _size(tree->right);

	return (s + 1);
}

/**
 * get_last - get the last node of the tree
 *
 * @root: Root of the tree
 * @i: Index of the last node
 * @size: size of the array
 * Return: The last node
 */

heap_t *get_last(heap_t *root, size_t i, size_t size)
{
	heap_t *left, *right;

	if (i == size)
		return (root);
	if (i > size)
		return (NULL);

	left = get_last(root->left, 2 * i + 1, size);
	right = get_last(root->right, 2 * i + 2, size);

	if (left)
		return (left);
	else if (right)
		return (right);
	else
		return (NULL);
}

/**
 * heap_extract - Extract the root of a Heap Binary Tree
 *
 * @root: Root of the tree
 * Return: The number extract
 */

int heap_extract(heap_t **root)
{
	heap_t *last, *temp = *root;
	size_t size;
	int extract;

	if (!*root || !root)
		return (0);
	extract = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		(*root) = NULL;
		return (extract);
	}
	size = _size(*root);
	last = get_last(*root, 0, size - 1);
	while (temp->left)
	{
		if (!temp->right || temp->left->n > temp->right->n)
		{
			temp->n = temp->left->n;
			temp = temp->left;
		}
		else
		{
			temp->n = temp->right->n;
			temp = temp->right;
		}
	}
	if (last->parent->left->n == last->n)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;
	temp->n = last->n;
	for (; temp && temp->parent && temp->n > temp->parent->n; temp = temp->parent)
		swap(temp);
	free(last);
	last = NULL;
	return (extract);
}
