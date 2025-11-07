/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * In-class example code to demonstrate use
 *   of new & delete for dynamic allocation
 */

#include <iostream>
using namespace std;

int main() {
	int arr1[10];		// Statically allocating 40 B for ints
	unsigned n;			// Second array size
	int* arr2;			// Pointer to dynamically allocated array
	int* p1, * p2;		// Other pointers to show other forms of allocation

	cout << "Enter array size: ";
	cin >> n;

	arr1[0] = 10;		// arr1[0] = "Start at address 'arr1' and go 0 int-sized spots past that
	arr1[5] = 20;		// arr1[5] = "Start at address 'arr1' and go 5 int-sized spots past that

	arr2 = new int[n];	// Allocates integer array of size n
	p1 = new int;		// Allocates a single, uninitialized int
	p2 = new int(n);	// Allocates a single int and sets it = n

	for (int i = 0; i < n; i++) {
		arr2[i] = i * 2;
		cout << "arr2[" << i << "] = " << arr2[i] << '\n';
	}

	delete p1;			// Delete single int
	delete p2;			// Delete single int
	delete[] arr2;		// Delete array of ints

	return 0;
}