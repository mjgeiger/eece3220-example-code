/*
* EECE.3220: Data Structures
* Instructor: M. Geiger
* Introduction to C++ strings
*/

#include <iostream>
#include <string>		// Necessary string library
using namespace std;

int main() {
	string s1;					// s1 = ""
	string s2 = "EECE.3220: Data Structures";
	
	// Simple string output
	cout << "Initially, s1 = " << s1 << ", and s2 = " << s2 << endl;

	// String input with cin
	cout << "Testing basic input: enter string without spaces: ";
	cin >> s1;
	cout << "Now, s1 = " << s1 << endl;

	// String input with getline
	// Initially, program isn't quite right--what's the problem?
	char c1;
	
	cout << "Testing getline(): enter string with spaces: ";
	cin.ignore(1);
	getline(cin, s1);
	cout << "Finally, s1 = " << s1 << endl;

	return 0;
}