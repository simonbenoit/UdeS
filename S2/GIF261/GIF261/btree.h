#pragma once
using namespace std;

struct node {
	string key_value;
	node* left;
	node* right;
};

class btree
{
public:
	btree();
	~btree();
	node *search(string key, node *leaf);
	void destroyBtree();
	node *buildtree(string key[], int& ptr, int size);
	node *buildtree(string key, int& ptr);
	void preorder(node *leaf);
	void inoder(node *leaf);
	void postorder(node *leaf);

private:	
	void destroyBtree(node *leaf);
	node *root;
	node *n;
};

