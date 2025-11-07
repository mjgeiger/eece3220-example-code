/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Example to illustrate substr()
 *   and find() functions
 */

#include <iostream>
#include <string>
using namespace std; 

int main() {

	string mystring("Hello there");
	cout << mystring << '\n';
	cout << "2nd char: " << mystring.at(1) << '\n';

	if (mystring == "Hello there")
		cout << "Match\n";

	// This block of code shows the two different types 
	//   of substring function--one that allows you to
	//   specify a maximum number of characters, and 
	//   one that just uses a starting position and 
	//   returns everything from that point to the
	//   end of the string
	string s2 = "EECE.3220";
	cout << s2 << '\n';
	cout << "Substring at posn 1 with 3 chars: "
		<< s2.substr(1, 3) << '\n';
	cout << "Substring at posn 4: " << s2.substr(4) << '\n';

	string s3 = "Data structures";
	int pos = 0;
	int count = 0;

	// This block of code demonstrates the find() function
	// The while loop repeatedly searches the string
	//   "Data structures" for occurrences of the character
	//   't', returning the position at which the letter's 
	//   found and incrementing the count of occurrences.
	// Incrementing the variable pos is key to this code
	//   working correctly--if you don't change the starting
	//   position for each new find() call, the function
	//   will "find" the same instance of the character
	//   repeatedly!
	while ((pos = s3.find('t', pos)) != string::npos) {
		cout << "Found t at position " << pos << '\n';
		count++;
		pos++;
	}
	cout << "Here's string::npos: " << string::npos << '\n';
	cout << "Found " << count << " occurrences of t in " << s3 << '\n';

	cout << "Found \" structures\" at position " << s3.find(" structures") << '\n';

	return 0;
}