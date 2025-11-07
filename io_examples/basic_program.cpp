/*
	EECE.3220: Data Structures
	Instructor: M. Geiger
	Basic C++ program examples
*/

#include <iostream>

using namespace std;

int main() {
	int x, y, z;
	double d1, d2;
	char c1, c2;

	cout << "Enter x, y, and z: ";
	cin >> x >> y >> z;
	cout << "Enter d1 and d2: ";
	cin >> d1 >> d2;
	cout << "Enter c1 and c2: ";
	cin >> c1 >> c2;

	cout << "x = " << x << ", y = " << y << ", z = " << z << '\n';
	cout << "d1 = " << d1 << ", d2 = " << d2 << "\n";
	cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
	return 0;
}