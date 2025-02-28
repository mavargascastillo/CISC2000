/*
Write a program that asks the user to input an integer named numDoubles. 
Create a dynamic array that can store numDoubles doubles and make a loop that
allows the user to enter a double into each array entry. loop through the array, 
calculate the average, and output it. Delete the memory allocated to your dynamic 
array before exiting.
*/

#include <iostream>
using namespace std;

int main(){
    int numDoubles;
    cout << "Enter number of doubles in the array: ";
    cin >> numDoubles;
    
    double *arr;
    arr = new double[numDoubles];

    for (int i = 0; i < numDoubles; i++){
        cout << "Enter a number to be stored: ";
        cin >> arr[i];
    }
    double total = 0.0; // Do not forget to initialize the variable!!
    for (int i = 0; i< numDoubles; i++){
        // Use traditional loop when dealing with pointers. Do not use range-based loops
        total += arr[i];
    }
    cout << (total/numDoubles);
    delete [] arr;
}