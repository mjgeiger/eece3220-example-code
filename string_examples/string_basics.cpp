/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Example to illustrate string basics
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	string s3 = "Hello";
	string s4("there");		// Equivalent to string s4 = "there"
		
	int len;
	
	if (s1.empty())
		cout << "s1 is empty\n";
	cout << s3 << " contains " << s3.size() << " characters\n";

	cout << "First character in s3 is " << s3[0] << endl;
	cout << "Second character in s3 is " << s3.at(1) << endl;


	s1 = s3;		// s1 = "Hello"
	if (s1.at(3) == s3[0])
		cout << "Match\n";

	cout << s3 << " " << s4 << endl;

	s2 = s3 + ' ' + s4 + '!';	// s2 = "Hello there!"
	s3 += s4;					// s3 = s3 + s4 = "Hellothere"

	len = s3.length();

	cout << s2 << '\n';
	cout << s3 << " is " << len << " chars long\n";

	cout << "First char of s2 = " << s2[0];
	cout << "\nSecond char of s2 = " << s2.at(1) << '\n';

	cout << "s2 = " << s2 << endl;
	cout << "First 5 chars of s2 = " << s2.substr(0, 5) << endl;
	cout << "Chars starting at position 4 " << s2.substr(4) << endl;
	
	s2 = "Data structures";

	int count = 0;
	int pos = 0;
	int found;
	while ((found = s2.find('t', pos)) != string::npos) {
		count++;
		pos = found + 1;
	}
	s2 = "Nospacesfound";
	found = s2.find(' ');	// string::npos as unsigned val = max possible unsigned int
	string sub = s2.substr(0, found);
	cout << "Substring up to first space = " << sub << endl;

	char test[10];
	test[5] = 0;
	cout << "printing empty array: " << test << endl;
	return 0;
}