/* 
CISC 2000
Programming assignment #3:
This program is a first assignment on dynamically filled arrays. The purpose is to practice the syntax, implementation
and general structure of pointers. 
Date: Feb 11, 2025
Author: Miguel Ángel Vargas
 */ 

#include <iostream>
using namespace std;

int* createAndFillArray (int size);
// Pre: the size variable has been declared
// Post: reads a sequence of integers from input to fill a dynamically allocated array.
// The array is dynamically allocated within the function

void selectionSort (int* array, int size);
// Pre: variables have been initialized and the array has been filled
// Post: uses selection sort to order the array in ascending order

void swapValues (int& a, int& b);
// Pre: a and b have been initialized
// Post: auxiliary function to selection sort. It swaps values of two variables

int main()
{
	int size;
	do {
		cout << "Enter the length of the number sequence: ";
		cin >> size;
	} while (size <= 0);


	int *arr = createAndFillArray(size);

	// Check if memory allocation was successfull
	if (arr == nullptr){
		return 1; // exit program
	}

	selectionSort(arr, size);

	for (int i = 0; i < size; i++){
		cout << arr[i] << " " ;
		cout << endl;
	}

	delete[] arr;

	return 0;
}


int* createAndFillArray (int size) {

	int *array = new int[size]; // Start dynamic array
	cout << "Enter " << size << " number of elements to store in the array: ";
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}

	return array;
}

void selectionSort (int* arr, int size) {
	for (int i = 0; i < (size-1); i++){
		int minIndex = i;

		for (int j = (i+1); j < (size); j++){
			if (arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}

		if (minIndex != i){
			swapValues(arr[i], arr[minIndex]);
		}
	}
}

void swapValues (int& a, int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}