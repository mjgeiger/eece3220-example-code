/* 
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * 
 * A version of the overloaded assignment operator
 *    that uses a node-by-node copy, not a temporary
 *    stack to copy data from rhs to calling object
 * 
 * This code doesn't work on its own, but you can copy
 *    it into the existing Stack.h in this folder (and
 *    overwrite the operator=() function that's given)
 *    or simply use it as a reference
 */

template <class T>
Stack& Stack::operator=(const Stack& rhs) {
	Node<T>* p;			// Traversal pointers
	Node<T>* q;
	Node<T>* newNode;	// Used to allocate nodes on LHS

	// Guard against self-assignment
	if (!(*this == rhs)) {

		// 1. Delete all nodes in calling object
		while (!empty())
			pop();

		// 2. Traverse right-hand side
		//   (p = address of current node on RHS,
		//    q = address of current node on LHS)
		p = rhs.top;
		q = nullptr;
		while (p != nullptr) {

			// For each node on RHS
			// 2a. Create new node on left-hand side
			// 2b. Copy data from corresponding node on right-hand side
			newNode = new Node(p->getVal(), nullptr);

			// 2c. Link new node into stack on LHS
			// If new node is first, top = new node address
			if (q == nullptr)
				top = newNode;

			// Otherwise, node before new node should point to it
			else
				q->setNext(newNode);

			// Move traversal pointers ahead
			p = p->getNext();
			q = newNode;
		}
	}

	// Return reference to calling object
	return *this;
}