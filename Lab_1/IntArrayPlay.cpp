/* 
CISC 2000
Programming assignment #2:
This program asks the user to fill up an array with integers from 1-20. Then, it sorts the array and 
asks the user if he wants to add/remove any values. 
Date: Feb 1, 2025
Author: Miguel Ángel Vargas
 */ 

#include <iostream>
using namespace std;

const int CAPACITY=20;

void displayArray(int arr[], int numArrayElems);
// Pre: arr is a valid integer array with up to numArrayElems elements
//Post: the elements of arr are printed in a single line separated by spaces

void fillArray(int arr[], int& numArrayElems, int CAPACITY);
// Pre: arr is an empty or partially filled integer array
// Post: the array is filled with the values the user has inputted (up to Capacity or until -1 is entered)

bool isArraySorted(int arr[], int numArrayElems);
// Pre: arr is a valid integer array with numArrayElems elements
// Post: returns true if the array is sorted in ascending order

int findNposition(int arr[], int numArrayElems; int target);
// Pre: arr is a valid integer array with numArrayElems elements
// Post: returns the index where target should be inserted/removed to maintain sorted order

bool findElement(int arr[], int numArrayElems, int target);
// Pre: arr is a valid integer array with numArrayElems elements
// Post: returns true if target is found in arr, otherwise false

bool insertElement(int arr[], int& numArrayElems, int CAPACITY, int element);
// Pre: arr is a valid integer array & numArrayElems <= CAPACITY
// Post: Inserts element in sorted order if space is available

//ToDo: Declare a function that removes an element (given its position) from a given array
// Return whether or not the removal could be performed.
bool removeElement(int arr[], int& numArrayElems, int CAPACITY, int element);

int main() {
   int numArray[CAPACITY];	// an int array with a given CAPACITY
   int numArrayElems=0;     // the array is initially empty, i.e., contains 0 elements

   fillArray(numArray, numArrayElems, CAPACITY);
   displayArray(numArray, numArrayElems);


   // 2. ToDo: Read in a value from the user. Call your findPosition function
   // to get the position to insert, then call insertElement to insert the value
   // into the position of the array. 
   // If the insert fails, report that the array is filled.
   // Display the contents of the array afterwards
   int element;
   cout << "Enter a value to insert: ";
   cin >> element;
   insertElement(numArray, numArrayElems, CAPACITY, element); 
   // FOR WHEN I COME BACK: FIX HOW TO CORRECTLY CALL THIS BOOLEAN FUNCTION
   displayArray(numArray, numArrayElems);



   // 3. ToDo: Use your isArraySorted function to tell whether the array is sorted.
   if (isArraySorted(numArray, numArrayElems)){
      continue;
   } else {
      cout << "The array is not sorted";
      return 0;
   }


   // 4. ToDo: Read in a value from the user. Call your searchElement function
   // to get the position to remove, then call removeElement to delete it.
   // a value to the end of the array 
   // If the removal fails, report that the position could not be found in the array.
   // Display the content of the array afterwards 
   int element2;
   cout << "Enter a value to remove: ";
   removeElement(numArray, numArrayElems, CAPACITY, element2);


   return 0;
}

void displayArray(int arr[], int numArrayElems){
   for (int i = 0; i < numArrayElems; i++){
      cout << arr[i] << " ";
   }
   cout << endl; // Move to next line after printing all elements
}

void fillArray(int arr[], int& numArrayElems, int CAPACITY){
   cout << "Enter a list of up to 20 integers or -1 to end the list ";
   
   int value;
   while (numArrayElems < CAPACITY){
      cin >> value;
      if (value == -1){
         break;
      }
      arr[numArrayElems++] = value // Post increment to store the value in the array and then increment numArrayElems
   }
}

bool isArraySorted(int arr[], int numArrayElems) {
   for (int i=0; i < numArrayElems - 1; i++) {
      if (arr[i] > arr[i+1]) {
         return false;
      }
   }
   return true; // if loop completes, the array is sorted
}

int findNposition(int arr[], int numArrayElems; int target){
   int i = 0;
   while (i < numArrayElems && arr[i] < target){
      i++; // the loop moves forward until it finds an element in the array >= target
   }
   return i;
}

bool findElement(int arr[], int numArrayElems, int target){
   for (int i = 0; i < numArrayElems; i++) {
      if (arr[i] == target){
         return true;
      }
   }
   return false; // if loop completes, the target value has not been found
}

bool insertElement(int arr[], int& numArrayElems, int CAPACITY, int element) {
   if (numArray >= CAPACITY){
      return false; // no more values can be added
   }

   int pos = findNposition(arr, numArrayElems, element);

   // Shift elements to the right to make space for the new element
   for (int i = numArrayElems; i > pos; i--) {
      arr[i] = arr[i-1]; // numArrayElems is one more than the indexed-number of elements
   }
   arr[pos] = element;
   numArrayElems++;

   return true; // Successfully inserted
}

bool removeElement(int arr[], int& numArrayElems, int CAPACITY, int element) {
   for (int k = 0; k < numArrayElems, k++){
      if (!arr[k] == element){
         return false; 
      }
   }
   int pos = findNposition(arr, numArrayElems, element);
   // Shift elements to the left to fill the gap created by removed element
   for (int i = pos; i < numArrayElems - 1; i++){
      arr[i] = arr[i+1]; // Automatically overwrites the value we want to get rid of
   }
   numArrayElems--;
   return true; // Removal was successfull
}