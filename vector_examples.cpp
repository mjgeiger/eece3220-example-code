/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * In-class example code to demonstrate use
 *   of vectors
 */

#include <vector>
#include <iostream>
using namespace std;

int main() {
	int i;							// Loop index
	vector <int>	vec1;			// Uninitialized integer vector
	vector <double>	vec2(6);		// Vector of 6 doubles
	vector <int>	vec3(10, -1);	// Vector of 10 ints, all set to -1
	vector <char>	vec4 =			// Vector of 5 characters (NOT a string)
		{ 'H', 'e', 'l', 'l', 'o' };

	if (vec1.empty())
		cout << "Vector 1 empty\n";
	if (vec2.empty())
		cout << "Vector 2 empty\n";

	// Using size() function to determine vector size
	cout << "Vector sizes:\n";
	cout << "vec1: " << vec1.size()
		<< "\nvec2: " << vec2.size()
		<< "\nvec3: " << vec3.size()
		<< "\nvec4: " << vec4.size() << '\n';

	// Accessing vector elements using simple for loop
	cout << "Vector contents:\nvec2: ";
	for (i = 0; i < vec2.size(); i++)
		cout << vec2.at(i) << ' ';	// vec2.at(i) equivalent to vec2[i]

	// Using range-based for loop
	cout << "\nvec3: ";
	for (int& val : vec3) {		// "val" == vec3[i]
		cout << val << ' ';
		val = 5;
	}

	cout << "\nvec3 again: ";
	for (int val : vec3)
		cout << val << ' ';

	// Using range-based for loop with auto type specifier
	cout << "\nvec4: ";
	for (auto ch : vec4)
		cout << ch;
	cout << "\n";

	// Resizing integer vectors
	cout << "Effects of resizing vec1 & vec3\n";
	vec1.resize(5);
	vec3.resize(5);
	for (i = 0; i < 5; i++) {
		cout << "vec1: " << vec1.at(i)
			<< ", vec3: " << vec3.at(i) << '\n';
	}

	// Vector push_back demonstration
	cout << "Effects of push_back:\n";
	for (i = 10; i > 5; i--)
		vec1.push_back(i);
	for (int val : vec1)
		cout << val << ' ';
	cout << '\n';

	// Vector pop_back demonstation
	cout << "\nEffects of pop_back:\n";
	while (!vec1.empty()) {
		cout << "Last value: " << vec1.at(vec1.size() - 1) << '\n';
		vec1.pop_back();
	}
	cout << "Vector 1 size is now " << vec1.size() << '\n';

	return 0;
}