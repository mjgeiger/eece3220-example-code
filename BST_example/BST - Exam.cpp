/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Exam 3 code
 * Source file for BST class
 *
 * In definitions below, nullptr == NULL
 */

#include "BST.h"

/************ EXAM 3 FUNCTIONS TO BE COMPLETED ************/

// Find and return the minimum value in the BST
//   Returns 0 if tree is empty
int BST::findMin() {
	BSTNode* n;

	if (root == nullptr)
		return 0;

	else {
		n = root;
		while (n->left != nullptr)
			n = n->left;
		return n->val;
	}
}

// Count all nodes in tree
// HINT: You may want a helper function--recursive or iterative--that visits each node
unsigned BST::countNodes() {
	return countNodesRecursive(root);
}

// Visit each node and count them
unsigned BST::countNodesRecursive(BSTNode* n) {
	if (n == nullptr)
		return 0;
	else
		return 1 + countNodesRecursive(n->left) + countNodesRecursive(n->right);
}

// Finds all duplicates and prints them to out
// Hint: You may want a helper function to traverse the tree
void BST::printDuplicates(ostream& out) {

	int lp = findMin() - 1;

	out << "Duplicates:";

	// If tree is empty; no duplicates
	// If visitInOrder prints nothing, no duplicates, either
	if (root == nullptr || !visitInOrder(root, out, &lp))
		out << " None";

	out << "\n";
}

// Does in-order traversal; returns true if value printed and false otherwise
bool BST::visitInOrder(BSTNode* n, ostream& out, int* lastPrinted) {
	int lpCopy = *lastPrinted;		// Copies last printed value before traversal
	int v;							// Value to check
	BSTNode* chk;					// Used to check for duplicates

	if (n == nullptr)
		return false;

	else {
		visitInOrder(n->left, out, lastPrinted);

		// Handle current node--check for duplicate in right subtree, 
		//   since that's where they go, based on insert
		chk = n->right;
		v = n->val;
		while (chk != nullptr && v > *lastPrinted) {

			if (chk->val == v) {		// Duplicate found
				out << " " << v;
				*lastPrinted = v;
			}

			else if (v < chk->val)		// Go left
				chk = chk->left;

			else						// Go right
				chk = chk->right;
		}

		visitInOrder(n->right, out, lastPrinted);

		return (lpCopy != *lastPrinted);		// True if value printed; false otherwise
	}
}

/************ END EXAM 3 FUNCTIONS TO BE COMPLETED ************/


/**** FUNCTIONS BELOW THIS LINE ARE ALREADY DEFINED FOR YOU--DO NOT CHANGE ****/
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
void BST::insertNode(BSTNode* tree, BSTNode* n) {
	if (n->val < tree->val) {
		if (tree->left == nullptr)
			tree->left = n;
		else
			insertNode(tree->left, n);
	}
	else {
		if (tree->right == nullptr)
			tree->right = n;
		else
			insertNode(tree->right, n);
	}
}

// Recursively remove node with value v
//   Takes parent pointer so we don't need another search function to find it
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