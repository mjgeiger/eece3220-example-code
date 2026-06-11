// EECE.3220
// Array-based queue code
// FUNCTIONS ARE EMPTY--TO BE COMPLETED DURING LECTURE

#include <iostream>
using std::cout;

template <class T>
class Queue {
public:
	Queue(unsigned maxSize = 1024);
	~Queue();
	bool empty() const;
	void enqueue(const T &val);
	void dequeue();
	T getFront();		// DON'T CALL THIS IF QUEUE EMPTY
private:
	T* list;			// Actual array storage for queue
	int front, back;	// Front and back indexes
	unsigned cap;		// Maximum array size (capacity)
	unsigned nvals;		// Number of values currently in queue
};

// Constructor
template <class T>
Queue<T>::Queue(unsigned maxSize) :
	front(0), back(0), cap(maxSize), nvals(0)
{
	list = new T[maxSize];
}

// Destructor
template <class T>
Queue<T>::~Queue() {
	delete[] list;
}

// True if list is empty
template <class T>
bool Queue<T>::empty() const {
	return (nvals == 0);
}

// Add new value to back of queue
template <class T>
void Queue<T>::enqueue(const T &val) {
	
	// Can't add when queue is full
	if (nvals == cap) {
		cout << "Queue full!\n";
	}

	else {
		list[back] = val;
		back = (back + 1) % cap;
		nvals++;
	}
}

// Remove element at front of Queue
template <class T>
void Queue<T>::dequeue() {

	// Can't remove when queue is empty
	if (nvals == 0)
		cout << "Queue empty!\n";
	
	else {
		front = (front + 1) % cap;
		nvals--;
	}
}

// Retrieve value of element at front of Queue
// DON'T CALL THIS IF QUEUE EMPTY
template <class T>
T Queue<T>::getFront() {
	return list[front];
}