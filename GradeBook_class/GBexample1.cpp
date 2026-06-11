/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * GradeBook class example
 * Adapted from Deitel & Deitel, C++ How to Program
 *
 * 1st example program to test GradeBook
 */

#include <iostream>
using namespace std;

#include "GradeBook.h"		// Implicitly includes <string>

int main()
{
	string nameOfCourse;	// string of characters to store the course name
	GradeBook myGradeBook;	// create a GradeBook object named myGradeBook
	GradeBook gb2("EECE.2160");
	
	// display initial value of courseName
	cout << "Initial course name is: " << myGradeBook.getCourseName()
		<< endl;
	cout << "Second course name is: " << gb2.getCourseName() << endl;

	// prompt for, input and set course name
	cout << "\nPlease enter the course name:" << endl;
	getline(cin, nameOfCourse); // read a course name with blanks
	
	myGradeBook.setCourseName(nameOfCourse);
	
	cout << endl;
	myGradeBook.displayMessage();

	return 0;
}
