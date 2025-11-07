/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 *
 * Time.cpp: Time function definitions
 * Includes blank definitions for overloaded operators to be written for Program 3
 */

#include "Time.h"	// Necessary for Time class definition
					// Implicitly includes <iostream>
#include <iomanip>	// Necessary for setw(), setfill()
using std::setw;
using std::setfill;

// Default constructor
Time::Time() : hours(0), minutes(0), miltime(0), AMorPM('A') 
{}

// Parameterized constructor
Time::Time(unsigned h, unsigned m, char AP) : hours(h), minutes(m), AMorPM(AP) {
	miltime = 100 * h + m;
	if (AP == 'P')
		miltime += 1200;
}

// Set time data members
void Time::set(unsigned h, unsigned m, char AP) {
	hours = h;
	minutes = m;
	AMorPM = AP;
	miltime = 100 * h + m;
	if (AP == 'P')
		miltime += 1200;
}

// Print time to desired output stream
void Time::display(ostream& out) {
	out << hours << ':'
		<< setw(2) << setfill('0') << minutes		// setw(2) forces minutes to be printed with 2 chars
		<< ' ' << AMorPM << 'M';					// setfill('0') adds leading 0 to minutes if needed
}

// Advance time by h hours, m minutes
// Use modulo arithmetic to ensure 
//   1 <= hours <= 12, 0 <= minutes <= 59
void Time::advance(unsigned h, unsigned m) {

	// If minutes you're adding account for >1 hour, add that number to h
	// For example, if m = 183, that's 3 hours and 3 minutes--add 183 / 60 = 3 to h
	//   and set m = 180 % 60 = 3
	if (m >= 60) {
		h = h + m / 60;
		m = m % 60;
	}

	// If adding m to minutes takes you over an hour, add that hour
	if (minutes + m >= 60)
		h++;

	// Get h to a value between 0 and 23--adding 24 or more hours would basically cause
	//   time to "wrap around" (adding 24 hours keeps hours the same, adding 25 is the 
	//   same as adding 1, etc.)
	h = h % 24;

	// Account for time changes from AM to PM or vice versa
	if (AMorPM == 'A' && ((hours + h) % 12) >= 12)
		AMorPM = 'P';
	else if (AMorPM == 'P' && ((hours + h) % 12) < 12)
		AMorPM = 'A';

	// Change hours
	hours = (hours + h) % 12;

	// hours shouldn't be 0
	if (hours == 0)
		hours = 12;

	// Finally, change minutes
	minutes = (minutes + m) % 60;
}

// Returns true if calling object is less than argument
bool Time::lessThan(const Time& rhs) {
	if (miltime < rhs.miltime)
		return true;
	else 
		return false;
}