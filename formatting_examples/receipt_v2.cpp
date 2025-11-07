/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * 
 * Simple receipt program to demonstrate 
 *    output formatting manipulators
 * Version 2: Precision only
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	string items[] = { "Lettuce", "Cherry tomatoes",
						"Rotisserie chicken", "Italian dressing",
						"Bottled water--24 pack" };
	double prices[] = { 3.10, 3.99, 4.50, 2.49, 15.00 };
	
	double total = 0;		// Total paid
	
	cout << fixed << setprecision(2);	// Update precision (and, in v2.1, fixed format)

	// Print each item and its price and calculate total amount paid
	for (unsigned i = 0; i < 5; i++) {
		cout << items[i] << "  $" << prices[i] << endl;
		total += prices[i];
	}
	cout << "TOTAL:  $" << total << endl;

	return 0;
}