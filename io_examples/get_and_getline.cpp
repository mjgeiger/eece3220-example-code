/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 *
 * Program to demonstrate get, getline,
 *    and ignore functions
 */

#include <iostream>
using namespace std;

int main() {
	char ch1, ch2, ch3;
	char arr1[10], arr2[10], arr3[10];

	cout << "Enter some lines of input:\n";
	cin.get(ch1);
	cin.get(ch2);
	cin.get(ch3);
	cin.getline(arr1, 10);
	cin.getline(arr2, 10);
	cin.getline(arr3, 10);

	cout << "ch1 = " << ch1 << ", ch2 = " << ch2
		<< ", ch3 = " << ch3 << endl;
	cout << "arr1 = " << arr1 << endl;
	cout << "arr2 = " << arr2 << endl;
	cout << "arr3 = " << arr3 << endl;

	return 0;
}