#include <iostream>
#include "LQueue.h"

using namespace std;

int main() {
	Queue <int> Q1;
	Queue <double> Q2;
	int i;

	for (i = 0; i < 10; i++) {
		Q1.enqueue(i);
		Q2.enqueue(i * 1.23);

		cout << "Now, front of Q1 = " << Q1.getFront()
			<< "; front of Q2 = " << Q2.getFront() << '\n';
	}

	while (!Q1.empty()) {
		cout << Q1.getFront() << '\n';
		Q1.dequeue();
	}

	while (!Q2.empty()) {
		cout << Q2.getFront() << '\n';
		Q2.dequeue();
	}


}