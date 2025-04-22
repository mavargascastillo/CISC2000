/* 
CISC 2000
Programming assignment #12:
This program is a Mini lab where we practice implementing the Big Three operators of classes: constructor, copy 
constructor, copy assignment operator (and destructor as well).
Date: Apr 22, 2025
Author: Miguel Ángel Vargas
 */

#include <iostream>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

#pragma once

// Contains the Temperature data at a given time
// for an experiment.
struct TempData {
	double temp;
	time_t time;

};

// Contains a list of TempData for an experiment.
class TempList {
	public:
		// ToDo: Implement the Constructor that takes a capacity, but will default it to 5.
		// ToDo: Use the capacity to create the datalist and the size to keep track of TempData
		// in the list.
		TempList(int capacity = 5);

		// ToDo: Implement the Copy Constructor, remember to set all data members to be an
		// independent copy of the given TempList.
		TempList(const TempList& other);

		// ToDo: Implement the Copy Assignment Operator, remember to make sure there is room
		// for the given tl.datalist in the invoking object. If not, create a bigger array.
		TempList& operator=(const TempList& other);

		// ToDo: Implement the Destructor
		~TempList(); 

		void add_temp(double temp);
		// add_temp adds a temp for time now
	
		void add_temp(double temp, time_t time);
		// add_temp adds a temp and a time.

		int size() const { return t_size; };
		// Returns number of elements in data_list.

		bool isFull() const { return (t_size >= t_capacity); };
		// Tests if list is full, return true else false

		friend ostream& operator<<(ostream& out, const TempList& list);
		// Prints the data_list

		TempData& at(int index);
		// Returns the TempData at the given index.
		// Assures that the index >= 0 && index < size()

		// Overload index[] opertor uses at(int index) above
		TempData& operator[](int index) {
			return at(index);
		};

	private:
		TempData *datalist;				// TempData Array in class
		int t_size = 0;        		   	// Number of elements
		int t_capacity;					// Number of TempData that fits
};

