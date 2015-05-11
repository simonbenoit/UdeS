#include "stdafx.h"
#include "btree.h"


//public methods declaration
btree::btree()
{
	root = NULL;
}

btree::~btree()
{
	destroyBtree();
}

node* btree::buildtree(string key[], int& ptr, int size)
{
	if (ptr >= size)
	{		
		return NULL;
	}

	node *n = new node;
	n->key_value = key[ptr];
	
	if (n->key_value.at(0) == '-')
	{
		return n;
	}
	else
	{
		n->left = buildtree(key, ++ptr, 18);
		n->right = buildtree(key, ++ptr, 18);
	}
	return n;
}

node* btree::buildtree(string key, int& ptr)
{
	if (ptr >= key.length())
	{
		return NULL;
	}

	node* n = new node;
	n->key_value = key[ptr];

	if (n->key_value == "-") 
	{
		return n;
	}
	else 
	{
		n->left = buildtree(key, ++ptr);
		n->right = buildtree(key, ++ptr);
	}
	return n;
}

void btree::destroyBtree()
{
	destroyBtree(root);
}

node* btree::search(string key, node *leaf)
{
	if (leaf == nullptr)
	{
		return NULL;
	}	
	else if (leaf->key_value == key)
	{
		n = leaf;
		return n;
	}
	else
	{
		if (leaf->left != nullptr)
		{
			if (leaf->left->key_value.at(0) != '-')
			{
				search(key, leaf->left);
			}
		}
		if (leaf->right != nullptr)
		{
			if (leaf->right->key_value.at(0) != '-')
			{
				search(key, leaf->right);
			}
		}
	}
	return n;
}

void btree::preorder(node *leaf)
{
	if (leaf != nullptr)
	{
		if (leaf->key_value.at(0) != '-')
		{
			cout << leaf->key_value << endl;
			preorder(leaf->left);
			preorder(leaf->right);
		}
	}
}

void btree::inoder(node *leaf)
{
	if (leaf != nullptr)
	{
		if (leaf->key_value.at(0) != '-')
		{			
			inoder(leaf->left);
			cout << leaf->key_value << endl;
			inoder(leaf->right);
		}
	}
}

void btree::postorder(node *leaf)
{
	if (leaf != nullptr)
	{
		if (leaf->key_value.at(0) != '-')
		{			
			postorder(leaf->left);
			postorder(leaf->right);
			cout << leaf->key_value << endl;
		}
	}
}

void btree::destroyBtree(node *leaf)
{
	if (leaf != NULL)
	{
		destroyBtree(leaf->left);
		destroyBtree(leaf->right);
		delete leaf;

	}
}
