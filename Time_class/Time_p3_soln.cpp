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

/*** OVERLOADED OPERATORS TO BE ADDED FOR PROGRAM 3 ***/
/*** PREVIOUSLY DEFINED FUNCTIONS START ON LINE 145
	   (BEFORE YOU START ADDING CODE)				***/

// Output operator
ostream& operator <<(ostream& out, const Time& rhs) {

	/*************************************************
	* Print time using form:
	*    h:mm _M  or hh:mm _M
	* where:
	*    h or hh	= # of hours (1 or 2 digits)
	*    mm			= # of minutes (always 2 digits)
	*    _M			= AM or PM
	**************************************************/
	out << rhs.hours << ':'
		<< setw(2) << setfill('0') << rhs.minutes		// setw(2) forces minutes to be printed with 2 chars
		<< ' ' << rhs.AMorPM << 'M';					// setfill('0') adds leading 0 to minutes if needed
	return out;
}

// Input operator
istream& operator >>(istream& in, Time& rhs) {

	/*************************************************
	* Read time assuming it is written in form:
	*    h:mm _M  or hh:mm _M
	* where:
	*    h or hh	= # of hours (1 or 2 digits)
	*    mm			= # of minutes (always 2 digits)
	*    _M			= AM or PM
	**************************************************/

	in >> rhs.hours;
	in.ignore(1);						// Skip ':'
	in >> rhs.minutes >> rhs.AMorPM;
	in.ignore(1);						// Skip 'M' at end of "AM" or "PM"

	// Calculate miltime based on other inputs
	rhs.miltime = 100 * rhs.hours + rhs.minutes;
	if (rhs.AMorPM == 'P')
		rhs.miltime += 1200;

	return in;
}

// Comparison operators
bool Time::operator ==(const Time& rhs) {

	/********************************************
	* Returns true if calling object matches rhs,
	*   false otherwise
	*********************************************/
	return (miltime == rhs.miltime);
}

bool Time::operator !=(const Time& rhs) {

	/**************************************************
	* Returns true if calling object doesn't match rhs,
	*   false otherwise
	***************************************************/
	return (miltime != rhs.miltime);
}

bool Time::operator <(const Time& rhs) {

	/**********************************************
	* Returns true if calling object is less 
	*   (earlier in day) than rhs, false otherwise
	***********************************************/
	return (miltime < rhs.miltime);
}

bool Time::operator >(const Time& rhs) {

	/********************************************
	* Returns true if calling object is greater
	*   (later in day) than rhs, false otherwise
	*********************************************/
	return (miltime > rhs.miltime);
}

// Arithmetic operators
Time Time::operator +(const Time& rhs) {
	Time sum;
	
	/********************************************
	* Add two Time objects and return sum
	*   See examples in spec
	*********************************************/
	sum = *this;
	sum.advance(rhs.miltime / 100, rhs.miltime % 100);
	return sum;

	/* CODE I ADDED AFTER I FIGURED OUT advance() 
	*  WAS BROKEN, WHICH I THEN BASICALLY COPIED
	*  INTO advance()  *facepalm*

	// Check if sum of minutes is >= 60 ...
	//   ... if so, adjust accordingly
	if (minutes + rhs.minutes >= 60)
		sum.miltime = (miltime + rhs.miltime + 40) % 2400;
	else
		sum.miltime = (miltime + rhs.miltime) % 2400;

	sum.hours = sum.miltime / 100;
	if (sum.hours > 12)
		sum.hours -= 12;
	else if (sum.hours == 0)
		sum.hours = 12;

	sum.minutes = sum.miltime % 100;

	sum.AMorPM = (sum.miltime < 1200 ? 'A' : 'P');
	/**/
}


Time Time::operator -(const Time& rhs) {
	Time diff;

	/*************************************************
	* Subtract two Time objects and return difference
	*   See examples in spec
	**************************************************/

	// advance() was tricky to handle all the modulo arithmetic
	//   so I'm going to make this easier by doing math on miltime
	//   then figuring out hours and minutes later
	// There are 4 cases to worry about ...

	// Cases 1 & 2: Subtraction result would be negative
	if (miltime < rhs.miltime) {

		// Case 1: Negative result only occurs in the hours place
		//   Minutes on LHS >= minutes on RHS
		if ((miltime % 100) >= (rhs.miltime % 100))
			diff.miltime = 2400 + miltime - rhs.miltime;

		// Case 2: Negative result in both hours and minutes places
		//   Minutes on LHS < minutes on RHS
		else
			diff.miltime = 2360 + miltime - rhs.miltime;
	}

	// Cases 3 & 4: Subtraction result would be positive
	else {

		// Case 3: Positive result for both hours and minutes
		//   Minutes on LHS >= minutes on RHS
		if ((miltime % 100) >= (rhs.miltime % 100))
			diff.miltime = miltime - rhs.miltime;

		// Case 4: Positive result in hours place, but negative minutes
		//   Minutes on LHS < minutes on RHS
		else
			diff.miltime = miltime - rhs.miltime - 40;
	}
	
	// Once miltime is set, can figure out hours, minutes, and AM/PM
	diff.hours = diff.miltime / 100;
	if (diff.hours > 12)
		diff.hours -= 12;
	else if (diff.hours == 0)
		diff.hours = 12;

	diff.minutes = diff.miltime % 100;

	diff.AMorPM = (diff.miltime < 1200 ? 'A' : 'P');

	return diff;
}

Time& Time::operator +=(const Time& rhs) {

	/**************************************************
	* Same as + operator, but modifies calling object
	*   and returns reference to calling object
	***************************************************/
	*this = *this + rhs;
	return *this;
}

Time& Time::operator -=(const Time& rhs) {

	/**************************************************
	* Same as - operator, but modifies calling object
	*   and returns reference to calling object
	***************************************************/
	*this = *this - rhs;
	return *this;
}

// Increment operators--adds 1 minute to current time
Time& Time::operator++() {
	/*************************
	* Pre-increment operator
	**************************/
	*this += Time(0, 1, 'A');

	return *this;
}

Time Time::operator++(int) {
	/*************************
	* Post-increment operator
	**************************/
	Time temp = *this;

	*this += Time(0, 1, 'A');

	return temp;
}
/*** END OVERLOADED OPERATORS TO BE ADDED FOR PROGRAM 3 ***/

// Default constructor
Time::Time() : hours(0), minutes(0), miltime(0), AMorPM('A') 
{}

// Parameterized constructor
Time::Time(unsigned h, unsigned m, char AP) : hours(h), minutes(m), AMorPM(AP) {
	miltime = 100 * h + m;

	/*** FIXED 10/11: ORIGINAL VERSION DID NOT CORRECTLY HANDLE 12 AM OR 12 PM ***/
	if (AP == 'P' && h != 12)
		miltime += 1200;
	else if (AP == 'A' && h == 12)
		miltime -= 1200;
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
	unsigned tempMT = h * 100 + m;		// Temporary miltime representing amount
										//   of time to advance by, since math
										//   is much easier using miltime!

	// If sum of minutes >= 60, need to account for extra hour added
	if (minutes + m >= 60)
		miltime = (miltime + tempMT + 40) % 2400;	// % 2400 ensures time between 0 & 2359
													//   (since minutes adjustment guarantees
													//    last two digits < 60)
	else
		miltime = (miltime + tempMT) % 2400;

	// Convert back from miltime to new hours/minutes
	hours = miltime / 100;

	// Special case 1: time in PM (other than 12 PM)
	if (hours > 12)
		hours -= 12;

	// Special case 2: 12:xx AM --> miltime / 100 = 0
	else if (hours == 0)
		hours = 12;

	minutes = miltime % 100;

	// Figure out if new time is in AM or PM
	AMorPM = (miltime < 1200 ? 'A' : 'P');
}

// Returns true if calling object is less than argument
bool Time::lessThan(const Time& rhs) {
	if (miltime < rhs.miltime)
		return true;
	else 
		return false;
}