#include <iostream>
using namespace std;

int main() {
	int* iPtr, * jPtr, i;
	iPtr = new int;
	jPtr = new int(3);

	double* dPtr;
	dPtr = new double[6];

	*iPtr = 7;
	cout << *iPtr << ',' << *jPtr << endl;
	
	for (i = 0; i < 6; i++)
		dPtr[i] = 5;
	for (i = 0; i < 6; i++)
		cout << (*dPtr)++ << ' ';
	cout << endl;

	for (i = 0; i < 6; i++)
		cout << dPtr[i] << ' ';
	cout << endl;

	delete iPtr;
	delete jPtr;
	delete[] dPtr;

	return 0;
}