#include "bst.h"
#include <stddef.h>  // For NULL
#include <stdlib.h>  // For malloc, free
#include <iostream>
using namespace std;

void insert_into(struct Node** root, int value) {

	struct Node *z = NULL; //node to be created and inserted
	struct Node *x = *root;
	struct Node *y = NULL; //y will be parent of z

	z = new struct Node;
	z->value = value;
	z->left = NULL;
	z->right = NULL;

	while (x != NULL)
	{
		y = x;
		if (value == x->value)
		{
			cout << "The item to be inserted is already in the tree, no duplicates allowed." << endl;
			return; //prevent duplicates
		}

		if (value < x->value)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}

	}


	if (y == NULL) //tree T was empty
	{
		*root = z;
	}
	else if (z->value < y->value)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}


	//inorder_tree_walk(*root);
	return;
}


//recursion
void free_tree(struct Node* root) {

	if (root != NULL)
	{
		free_tree(root->left);
		free_tree(root->right);
		delete root;
	}
	return;
}


//get number of nodes in the tree
size_t size_of(const struct Node* root){

	if (root == NULL)
	{
		return 0;
	}
	else
	{
		size_t value1 = size_of(root->left);
		size_t value2 = size_of(root->right);

		return 1 + value1 + value2;
	}

	return 0;

}


//uses inorder_tree_walk_build, a recursive function
//to help build the dynamic array.
int* contents_of(const struct Node* root) {

	int* sortedArr;
	size_t s = size_of(root); //count elements for array size
	//cout << endl;
	//cout << "arr size = " << s << endl;

	//do inorder walk through the tree and fill array
	sortedArr = new int[s];
	int index = 0;
	inorder_tree_walk_build(root, sortedArr, index);

	return sortedArr;
}


const struct Node* second_min_in(const struct Node* root) {

	if (size_of(root) < 2)
	{
		return NULL;
	}
	const struct Node* parent = root;
	const struct Node* firstSmallest = tree_minimum(root, parent); //parent should be passed by reference?

	if (firstSmallest->left == NULL && firstSmallest->right == NULL)
	{
		return parent;
	}
	else
	{
		return tree_minimum(firstSmallest->right, parent);
	}

	/*
	//track the parent node while
	//descending to smallest value
	while (root->left != NULL)
	{
		parent = root;
		root = root->left;
	}

	//At the smallest value, if there is a value on the right
	//it will be the second smallest value. Otherwise, its the parent of the smallest
	if (root->right != NULL)
	{
		secondSmallest = root->right;
	}
	else
	{
		secondSmallest = tree_minimum(root->right, parent);
		//secondSmallest = parent;
	}

	return secondSmallest;
*/

}


const struct Node* tree_minimum(const struct Node* t, const struct Node* p)
{
	while (t->left != NULL)
	{
		p = t;
		t = t->left;
	}
	return t;
}


//inorder walk smallest to largest value
void inorder_tree_walk(const struct Node* x)
{
	if (x != NULL)
	{
		inorder_tree_walk(x->left);
		cout << x->value << " ";
		inorder_tree_walk(x->right);
	}
}


//recursive function to walk through the tree inorder
//and fill the dynamic array
void inorder_tree_walk_build(const struct Node* root, int arr[], int& index)
{
	if (root != NULL)
	{
		inorder_tree_walk_build(root->left, arr, index);
		arr[index] = root->value;
		index++;
		inorder_tree_walk_build(root->right, arr, index);
	}

}

//Failed code/attempts below
/*
if (size_of(root) < 2)
	{
		return NULL;
	}
	const struct Node* parent = root;
	const struct Node* secondSmallest = tree_minimum(root, parent);

const struct Node* tree_minimum(const struct Node* t, const struct Node* p)
{
	const struct Node* secondSmallest = NULL;
	//p is the parent node, track it
	//descend to smallest value
	while (t->left != NULL)
	{
		p = t;
		t = t->left;
	}

	if (t->right != NULL)
	{
		secondSmallest = t->right;
	}
	else
	{
		secondSmallest = p;
	}

	return secondSmallest;

}
*/


/*
//function with slight inconsistencies
const struct Node* second_min_in(const struct Node* root) {

	if (size_of(root) < 2)
	{
		return NULL;
	}
	const struct Node* parent = root;
	const struct Node* secondSmallest = NULL;

	//track the parent node while
	//descending to smallest value
	while (root->left != NULL)
	{
		parent = root;
		root = root->left;
	}

	//At the smallest value, if there is a value on the right
	//it will be the second smallest value. Otherwise, its the parent of the smallest
	if (root->right != NULL)
	{
		secondSmallest = root->right;
	}
	else
	{
		secondSmallest = parent;
	}

	return secondSmallest;

}
*/


/*
//not working
const struct Node* second_min_in(const struct Node* root) {

	if (size_of(root) < 2)
	{
		return NULL;
	}
	const struct Node* secondSmallest = NULL;
	const struct Node* t = root; //traverse down the tree

	while (t->left != NULL)
	{
		t = t->left;
	}

	if (t->right != NULL)
	{
		return tree_min(t->right);
	}


	while (root != NULL)
	{
		if (t->value < root->value)
		{
			secondSmallest = root;
			root = root->left;
		}
		else if (t->value > root->value)
		{
			root = root->right;
		}
		else
		{
			break;
		}
	}

	return secondSmallest;

}

const struct Node* tree_min(const struct Node* t)
{
	while (t->left != NULL)
	{
		t = t->left;
	}
	return t;
}
*/
