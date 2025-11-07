/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * 
 * Simple receipt program to demonstrate 
 *    output formatting manipulators
 * Version 1: No formatting used
 */

#include <iostream>
using namespace std;

int main() {
	string items[] = { "Lettuce", "Cherry tomatoes",
						"Rotisserie chicken", "Italian dressing",
						"Bottled water--24 pack" };
	double prices[] = { 3.10, 3.99, 4.50, 2.49, 15.00 };
	
	double total = 0;		// Total paid

	// Print each item and its price and calculate total amount paid
	for (unsigned i = 0; i < 5; i++) {
		cout << items[i] << "  $" << prices[i] << endl;
		total += prices[i];
	}
	cout << "TOTAL:  $" << total << endl;

	return 0;
}