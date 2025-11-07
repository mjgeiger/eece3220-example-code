#include <iostream>
#include "Stack.h"

using namespace std;

int f(int arg = 5) {
	return arg * 2;
}

int main() {
	Stack S1;			// Creates stack of max size 1024
	Stack S2(200);		// Creates stack of max size 200
	int n;
	/*
	cout << "Enter array size: ";
	cin >> n;

	int* arr;
	arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = i * 2;
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	delete [] arr;
	*/

	return 0;
	// ~Stack() called on S1 and S2
	// S1.~Stack();
	// S2.~Stack();
}