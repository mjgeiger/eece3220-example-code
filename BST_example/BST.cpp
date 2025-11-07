/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Source file for BST class example
 *
 * In definitions below, nullptr == NULL
 */

#include "BST.h"

// Returns true if tree empty; false otherwise
bool BST::empty() {
	return (root == nullptr);
}

// Adds new node with value v
void BST::insert(int v) {
	BSTNode* n = new BSTNode(v);
	if (root == nullptr)
		root = n;
	else
		insertNode(root, n);
}

// Removes node with value v
//   Returns true if node found & removed; false otherwise
bool BST::remove(int v) {
	return removeNode(root, nullptr, v);
}

// Returns true if v in tree; false otherwise
bool BST::search(int v) {
	return (searchNode(root, v) != nullptr);
}

// Prints tree contents in order
void BST::printInOrder(ostream& out) {
	if (root == nullptr)
		out << "Tree is empty\n";

	else {
		out << "Tree contents:\n";
		printNode(root, out);
		out << "\n";
	}
}


// Recursive helper functions
void BST::insertNode(BST::BSTNode* tree, BST::BSTNode* n) {
	if (n->val < tree->val) {
		if (tree->left == nullptr)
			tree->left = n;
			// Set height of left subtree == 1
		else
			insertNode(tree->left, n);
			// Add 1 to height of left subtree
			//  Recompute balance factor
			// If BF == 2
	}
	else {
		if (tree->right == nullptr)
			tree->right = n;
			// Set height of right subtree == 1
		else
			insertNode(tree->right, n);
	}
}

// Recursively remove node with value v
//   Takes parent pointer so we don't need another search function to find it
//   tree == current node to search (and possibly delete)
//   parent == parent node of "tree" (will need to modify this node if you delete "tree")
//   v == value you want to delete
bool BST::removeNode(BSTNode* tree, BSTNode* parent, int v) {
	if (tree == nullptr)		// Base case 1
		return false;

	if (tree->val == v) {		// Found node--base case 2

		// Node to remove is leaf
		if (tree->left == nullptr && tree->right == nullptr) {
			if (parent->right == tree)
				parent->right = nullptr;
			else
				parent->left = nullptr;
			delete tree;
		}

		// Node has one child on right
		else if (tree->left == nullptr) {
			if (parent->right == tree)
				parent->right = tree->right;
			else
				parent->left = tree->right;
			delete tree;
		}

		// Node has one child on left
		else if (tree->right == nullptr) {
			if (parent->right == tree)
				parent->right = tree->left;
			else
				parent->left = tree->left;
			delete tree;
		}

		// Node has two children
		else {

			// Find in-order successor, copy data from that node to "tree", then delete successor
			BSTNode* s = tree->right;
			BSTNode* sp = tree;			// Parent node to pass to delete function
			while (s->left != nullptr) {
				sp = s;
				s = s->left;
			}

			tree->val = s->val;
			removeNode(s, sp, s->val);
		}

		return true;
	}

	else if (v < tree->val)		// Go left
		return removeNode(tree->left, tree, v);

	else						// Go right
		return removeNode(tree->right, tree, v);
}

// Returns node where v is found or nullptr otherwise
BST::BSTNode* BST::searchNode(BSTNode* tree, int v) {
	if (tree == nullptr || v == tree->val)
		return tree;

	else if (v < tree->val)
		return searchNode(tree->left, v);

	else
		return searchNode(tree->right, v);
}

// Recursively visit all nodes in order and print their values
void BST::printNode(BSTNode* tree, ostream& out) {
	if (tree != nullptr) {
		printNode(tree->left, out);
		out << " " << tree->val;
		printNode(tree->right, out);
	}
}