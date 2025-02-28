/* Top Comment Block Here: Put your name and explain the program!
 */
 
#include <iostream>
using namespace std;

typedef int* intPtr;

// Declare your functions!

int main()
{
    const int SECTIONS = 3;
    int students;
    
    cout << "Enter the number of students in each section: ";
    cin >> students;
    
    // Declare the pointer, then set up the multidimensional array
    
    enterGrades(grades, SECTIONS, students);
    double average = averageOfGrades(grades, SECTIONS, students);
    cout << "Average grade is: " << average << endl;
    
    // Delete the Multidimensional Dynamic Array
}

// Implement the function to enter the grades!


// Implement the function to calculate and print out the averages!
