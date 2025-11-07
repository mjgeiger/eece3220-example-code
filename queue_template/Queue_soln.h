// EECE.3220
// Array-based queue code

#include <iostream>
using std::cout;
using std::ostream;

template <class T>
class Queue {
public:
	Queue(unsigned maxSize = 1024);
	~Queue();
	bool empty() const;
	void enqueue(const T &val);
	void dequeue();
	T getFront();

	void enqueuePQ(const T& val);

	friend ostream& operator <<(ostream& out, const Queue<T>& q);
private:
	T* list;
	int front, back;
	unsigned cap;
};

// Add new value to Queue as if it were priority queue
template <class T>
void Queue<T>::enqueuePQ(const T& val) {
	int i, j, k;		// Loop indexes

	if ((back + 1) % cap == front)		// Queue is full
		cout << "error\n";

	else {				// At least one empty spot in queue

		// Find right spot in queue for new item, starting at front
		i = front;
		while (i != back && val < list[i])
			i = (i + 1) % cap;
		
		// Shift everything that should come after new object
		for (j = back; j != i; j = (j - 1) % cap) {
			k = (j + 1) % cap;
			list[k] = list[j];
		}

		// Insert new object and update "back" index
		list[back] = val;
		back = (back + 1) % cap;
	}
}

/********** DO NOT MODIFY FUNCTIONS BELOW THIS LINE *********/
// Constructor
template <class T>
Queue<T>::Queue(unsigned maxSize) : front(0), back(0), cap(maxSize)
{
	list = new T[maxSize];
}

// Destructor
template <class T>
Queue<T>::~Queue()
{
	delete [] list;
}

// True if list is empty
template <class T>
bool Queue<T>::empty() const {
	return (front == back);		// Returns true if front == back
								//   false otherwise
}

// Add new value to back of queue
template <class T>
void Queue<T>::enqueue(const T &val) {
	if ((back + 1) % cap == front)		// Queue is full
		cout << "error\n";

	else {				// At least one empty spot in queue
		list[back] = val;
		back = (back + 1) % cap;
	}
}

// Remove element at front of Queue
template <class T>
void Queue<T>::dequeue() {
	if (!empty())			// Can't remove from empty queue
		front = (front + 1) % cap;
}

// Retrieve value of element at top of Queue
template <class T>
T Queue<T>::getFront() {
	if (!empty())
		return list[front];
	
	// Empty queue--return garbage data
	else {
		cout << "error: empty queue\n";
		return list[cap - 1];
	}
}

template <class T>
ostream& operator <<(ostream& out, const Queue<T>& q) {
	int i;		// Loop index

	if (q.empty())
		out << "Empty queue\n";
	else {
		for (i = q.front; i != q.back; i = (i + 1) % q.cap)
			out << q.list[i] << ' ';
		out << '\n';
	}

	return out;
}
