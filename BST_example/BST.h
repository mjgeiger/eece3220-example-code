/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Header file for BST class example
 *
 * In definitions below, nullptr == NULL
 */

#include <iostream>
using namespace std;

class BST {
public:
	
	BST() : root(nullptr) {}			// Constructs empty tree
	bool empty();						// Returns true if tree empty; false otherwise
	void insert(int v);					// Adds new node with value v
	bool remove(int v);					// Removes node with value v
										//   Returns true if node found & removed; false otherwise
	bool search(int v);					// Returns true if v in tree; false otherwise
	void printInOrder(ostream& out);	// Prints tree contents in order

private:
	
	// BST node to be used in implementation
	class BSTNode {
	public:
		BSTNode(int v) : val(v), left(nullptr), right(nullptr) {}
		int val;					// Value stored in node
		BSTNode* left, * right;		// Pointers to left and right subtrees
	};

	BSTNode* root;			// Root of tree

	// Recursive helper functions--called only in other BST functions
	void insertNode(BSTNode* tree, BSTNode *n);
	bool removeNode(BSTNode* tree, BSTNode *parent, int v);
	BSTNode* searchNode(BSTNode* tree, int v);
	void printNode(BSTNode* tree, ostream& out);
};