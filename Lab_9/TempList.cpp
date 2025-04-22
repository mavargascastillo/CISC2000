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
#include "TempList.h"

using namespace std;


// ToDo: Implement the Constructor that takes a capacity. Use the capacity to create
// the datalist and the size to keep track of TempData in the list.
TempList::TempList(int capacity) {
	t_capacity = capacity;
	t_size = 0;
	datalist = new TempData[t_capacity];
}

// ToDo: Implement the Copy Constructor, remember to set all data members to be an
// independent copy of the given TempList.
TempList::TempList(const TempList& other){
	t_capacity = other.t_capacity;
	t_size = other.t_size;
	datalist = new TempData[t_capacity];
	for (int i = 0 ; i < t_size ; ++i){ //Important to add one to i before every iteration
		datalist[i] = other.datalist[i];
	}
}
	
// ToDo: Implement the Copy Assignment Operator, remember to make sure there is room
// for the given tl.datalist in the invoking object. If not, create a bigger array.
TempList& TempList::operator=(const TempList& other){
	if (this == &other){
		return *this; // it handles self-assignment
	}

	// Reallocate if current capacity is less than the other's
	if (t_capacity < other.t_size){
		delete[] datalist;
		t_capacity = other.t_capacity;
		datalist = new TempData[t_capacity];
	}

	t_size = other.t_size;
	for (int i = 0 ; i < t_size ; ++i){
		datalist[i] = other.datalist[i];
	}
	return *this; // this allows chaining i.e a=b=c

}

// ToDo: Implement the Destructor
TempList::~TempList() {
	delete[] datalist;
}


// overload operator<< for struct TempData
// NOTE: Doesn't need to be a friend since it is public by default.
ostream& operator<<(ostream& out, const TempData& tempDat) {
	out << "temp: " << tempDat.temp << " time: " << tempDat.time;
	return out;
}

// overload operator<< for class TempList
// NOTE: Uses index[] and size() to iterator over datalist.
// Depends on overloaded operator above.
ostream& operator<<(ostream& out, TempList& tempList) {
	for (int i = 0; i < tempList.size(); i++)
		out << tempList[i] << endl;
	return out;
}

// Adds a temp to the end of datalist if it is not full.
// Assumes time is now and calls the other version.
void TempList::add_temp(double temp) {
	add_temp(temp, time(NULL));
}

// Adds a temp to the end of datalist if it is not full.
void TempList::add_temp(double temp, long time)
{
	if (!isFull()) {
		TempData tempData = { temp, time };
		datalist[t_size++] = tempData;
	}
}

// Returns the object at the given index as long as it is in bounds.
// index >= 0 && index < size()
TempData& TempList::at(int index)
{
	assert(index >= 0 && index < t_size);
	return datalist[index];
}
