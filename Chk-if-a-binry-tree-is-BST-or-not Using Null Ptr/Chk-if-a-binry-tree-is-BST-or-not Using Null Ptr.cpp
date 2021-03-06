// Chk-if-a-binry-tree-is-BST-or-not Using Null Ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
};

bool isBST(Node* root, Node* l = NULL, Node* r = NULL)
{
	if (root == NULL)
		return false;

	if (l != NULL and root->data < l->data)
		return false;

	if (r != NULL and root->data > r->data)
		return false;

	return isBST(root->left, l, root) and isBST(root->right, root, r);
}

struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int main()
{
	struct Node *root = newNode(3);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(4);

	if (isBST(root))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;
}
