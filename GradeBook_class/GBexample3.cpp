/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * GradeBook class example
 * Adapted from Deitel & Deitel, C++ How to Program
 *
 * 3rd example program to test GradeBook--understanding valid class syntax
 */

#include "GradeBook.h"

#include <iostream>
using namespace std;

int main() {
	GradeBook g1("3220");			
	GradeBook g2;				
	g2.setCourseName("EECE.2100");	 
	g2.setCourseName("EECE.3220");	
	string s = g2.getCourseName();	
	g2.displayMessage();

	return 0;
}
















/*
GradeBook g1("3220");			// Originally read: GradeBook g1(3220);
								//   Since 3220 isn't a string, argument type
								//   didn't match the parameterized constructor

GradeBook g2;					// This line is fine as-is--invokes
								//   default constructor to initialize g2

g1.setCourseName("EECE.2160");	// Originally read: setCourseName(g2);
								//   That's invalid syntax for calling a member
								//   function, and setCourseName() takes a 
								//   string, not a GradeBook, as an argument
								//   (Switched the calling object to g1 to 
								//    differentiate this line from the next one.)

g2.setCourseName("EECE.3220");	// Originally read: g2.name = "EECE.3220";
								//   Two issues: the GradeBook class data member is
								//   courseName, not name, and you can't directly
								//   access private data by name--need to use a
								//   "set" function to modify

string s = g2.getCourseName();	// This line is fine as-is--calls getCourseName()
								//   member function and stores return value in
								//   appropriate variable

g2.displayMessage();			// Originally read: g2.displayMessage;
								//   displayMessage() is a valid member function
								//   for the GradeBook class, but a function call
								//   needs parentheses at the end, even if the 
								//   function takes no arguments
*/