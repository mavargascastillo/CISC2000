/* 
CISC 2000
Midterm C:
Program asks user to enter grades for n students in 3 classes, and then calculates average grade for 
each class and total average grade.
Date: Feb 28, 2025
Author: Miguel Ángel Vargas
 */
 
#include <iostream>
using namespace std;

typedef int* intPtr;

void enterGrades(intPtr* grades, int sections, int students);
// Pre: the array has been initialized, as well as sections and students
// Post: the user is prompted to enter the grades for 3 sections for n students

double averageOfGrades(intPtr* grades, int sections, int students);
// Pre: the array has been initialized, as well as sections and students
// Post: the average of each section is calculated, as well as the total average of grades

int main()
{
    const int SECTIONS = 3;
    int students;
    
    cout << "Enter the number of students in each section: ";
    cin >> students;
    
    // Declare the pointer, then set up the multidimensional array
    intPtr* grades = new intPtr[SECTIONS]; // The array of pointers
    for (int i = 0; i < SECTIONS; i++) {
        grades[i] = new int[students]; // Allocate array for each section
    }
    
    enterGrades(grades, SECTIONS, students);
    double average = averageOfGrades(grades, SECTIONS, students);
    cout << "Average grade is: " << average << endl;
    
    // Delete the Multidimensional Dynamic Array
    for (int i = 0; i < SECTIONS; i++) {
        delete[] grades[i]; // Delete each row
    }
    delete[] grades; // Delete array of pointers
    return 0;
}

void enterGrades(intPtr* grades, int sections, int students) {
    for (int i = 0; i < sections; i++) {
        // first loop to access the section
        cout << "Section #" << i + 1 << ":" << endl;
        for (int j = 0; j < students; j++) {
            // second loop to access each individual student
            cout << "Student " << j + 1 << ": ";
            cin >> grades[i][j];
        }
    }
}

double averageOfGrades(intPtr* grades, int sections, int students) {
    double totalSum = 0.0;

    for (int i = 0; i < sections; i++) {
        // same double loop here to access each individual student
        double sectionSum = 0.0;
        for (int j = 0; j < students; j++) {
            sectionSum += grades[i][j];
        }
        double sectAvg = sectionSum / students;
        cout << "Section #" << i + 1 << " average is: " << sectAvg << endl;
        totalSum += sectAvg;
    }
    return totalSum / sections;
}
