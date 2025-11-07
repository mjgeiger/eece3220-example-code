/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * GradeBook class example
 * Adapted from Deitel & Deitel, C++ How to Program
 *
 * GradeBook function definitions
 */

#include "GradeBook.h"

#include <iostream>
using std::cout;
using std::endl;

// Default constructor
GradeBook::GradeBook() : courseName("") 
{}

// Parameterized constructor
GradeBook::GradeBook(const string name) :
	courseName(name)
{}

// function that sets the course name
void GradeBook::setCourseName(const string name) {
	courseName = name;
}

// function that gets the course name
string GradeBook::getCourseName() const {
	return courseName;
}

// function that displays a welcome message
void GradeBook::displayMessage() const {
	cout << "Welcome to the grade book for\n" << courseName << "!"
		<< endl;
}
