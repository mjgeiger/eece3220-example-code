/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Function example to illustrate 
 *  different styles of argument passing
 */

#include <iostream>
#include <string>
using namespace std;

double f1(int v1, int v2);
void f2(int *ptr1, int *ptr2);
void f3(int& ref1, int &ref2);

int main() {
	int foo = 10;
	int bar = 57;
	double baz;

	baz = f1(foo, bar);
	cout << "After f1(), foo = " << foo << ", bar = "
		<< bar << ", baz = " << baz << '\n';

	f2(&foo, &bar);
	cout << "After f2(), foo = " << foo << ", bar = " << bar << '\n';

	f3(foo, bar);
	cout << "After f3(), foo = " << foo << ", bar = " << bar << '\n';

	return 0;
}

double f1(int v1, int v2) {
	return (v1 + v2) / 2.0;
}

void f2(int *ptr1, int * ptr2) {
	while (*ptr1 > 5) {			// *ptr1 = "value ptr1 points to"
		*ptr2 -= 3;
		(*ptr1)--;
	}
}

void f3(int &ref1, int &ref2) {
	if (ref1 == 5 && ref2 >= 45) {
		ref1++;
		ref2--;
	}
	else if (ref1 == 5) {
		ref1--;
		ref2++;
	}
	else {
		ref1 = ref2 - 10;
		ref2 = ref1 + 10;
	}
}