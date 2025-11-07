/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * GradeBook class example
 * Adapted from Deitel & Deitel, C++ How to Program
 *
 * 2nd example program to test GradeBook--tests constructors
 */

#include "GradeBook.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// create three GradeBook objects
	GradeBook gradeBook1("CS101 Introduction to C++ Programming");	// Calls parameterized constructor
	GradeBook gradeBook2("CS102 Data Structures in C++");
	GradeBook gb3;		// Calls default constructor

	// display initial value of courseName for each GradeBook
	cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
		<< "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
		<< endl;
	gradeBook1.setCourseName("EECE.3220: Data Structures");
	gradeBook1.displayMessage();

	return 0; 
}
