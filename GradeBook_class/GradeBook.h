/* 
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * GradeBook class example
 * Adapted from Deitel & Deitel, C++ How to Program
 *
 * GradeBook class definition
 */

#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
using std::string;

class GradeBook {
public:
	GradeBook();							// Default constructor
	GradeBook(const string name);			// Parameterized constructor
	void setCourseName(const string name);	// function that sets the course name
	string getCourseName() const;			// function that gets the course name
	void displayMessage() const;			// function that displays a welcome message
private:
	string courseName; // course name for this GradeBook
};

#endif	// GRADEBOOK_H