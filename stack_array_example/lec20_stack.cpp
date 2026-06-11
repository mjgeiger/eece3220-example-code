/* 
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Main program for in-class stack example
 */

//#include "StackTemplate.h"
#include <iostream>
#include <stack>
using namespace std;

int main() {
	int arr1[7] = { 8, 6, 7, 5, 3, 0, 9 };
	double arr2[10] = { 0, 1.1, 2.2, 3.3, 4.4,
						5.5, 6.6, 7.7, 8.8, 9.9 };
	int i, j;
	stack <double> S1;

	for (i = 0; i < 7; i++) {
		j = arr1[i];
		S1.push(arr2[j]);
	}

	while (!S1.empty()) {
		cout << S1.top() << endl;
		S1.pop();
	}
	return 0;

	// S1.~Stack() automatically called
}