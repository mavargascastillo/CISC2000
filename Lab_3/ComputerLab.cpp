/* 
CISC 2000
Programming assignment #5:
This program allows to keep track of the status of each computer station in a total of 4 computer labs.
Date: Feb 20, 2025
Author: Miguel Ángel Vargas
 */

#include <iostream>

using namespace std;

// Type definition
typedef int* IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes

/*
 Creates the dynamic arrays for the labs.
 @param labs: the array of labs,
 @param labsizes: contains the size (or number of computers) of each lab
  This dictates the size of the dynamic array.
 @precondition: labsize[0] is the # of computers in lab1,
                labsize[1] is the # of computers in lab2, ...
 @postcondition: labs[0] points to lab1's array (of size given by labsize[0])
      labs[1] points to lab2's array (of size given by labsize[1])
        ...
*/
void createArrays(IntPtr labs[], int labsizes[]);
// Pre: labs and labsizes have been declared
// Post: the function creates the arrays that represent the labs and its respective stations
// dynamically allocating memory based on user input

void freeArrays(IntPtr labs[]);
// Pre: the labs array has been declared and initialized
// Post: frees memory

void showLabs(IntPtr labs[], int labsizes[]);
// Pre: the arrays have been declared and initialized and they contain values
// Post: displays the status of all labs (who is logged into which computer).

void login(IntPtr labs[], int labsizes[]);
// Pre: the arrays have been initialized and declared
// Post: based on a userID, the user is allocated a station in one of the labs

void logout(IntPtr labs[], int labsizes[]);
// Pre: the arrays have been initialized and declared
// Post: based on a userID given by the user, the function searches through the arrays and, if found, logs
// the user out

void search(IntPtr labs[], int labsizes[]);
// Pre: the arrays have been initialized and declared
// Post: based on a userID given by the user, the function searches through the arrays and, if found, outputs
// the station number


// ======================
//     main function
// ======================
int main()
{
	IntPtr labs[NUMLABS]; 	// store the pointers to the dynamic array for each lab
	int labsizes[NUMLABS];	// Number of computers in each lab
	int choice = -1;
	
	cout <<"Welcome to the LabMonitorProgram!\n";

	// Prompt the user to enter labsizes 
	cout <<"Please enter the number of computer stations in each lab:\n"; 
	for (int i=0; i< NUMLABS; i++)
	{
		do
		{
			cout <<"How many computers in Lab "<< i+1<<"?";
			cin >> labsizes[i]; 
		} while (labsizes[i]<0); 
	}

	// Create ragged array structure
	createArrays(labs, labsizes);

	// Main Menu
	while (choice != 0)
	{
		cout << endl;
		cout << "MAIN MENU" << endl;
		cout << "0) Quit" << endl;
		cout << "1) Simulate login" << endl;
		cout << "2) Simulate logout" << endl;
		cout << "3) Search" << endl;
		cin >> choice;
		if (choice == 1)
		{
			login(labs, labsizes);
			showLabs(labs, labsizes);
		}
		else if (choice == 2)
		{
			logout(labs, labsizes);
			showLabs(labs, labsizes);
		}
		else if (choice == 3)
		{
			search(labs, labsizes);
		}
	}
	freeArrays(labs);		// Free memory before exiting
	cout << "Bye!\n";
	return 0;
}

void createArrays(IntPtr labs[], int labsizes[])
{
  for (int i = 0; i < NUMLABS; i++){
	labs[i] = new int[labsizes[i]]; // This dynamically allocats memory for lab[i]
	for (int j = 0; j < labsizes[i]; j++){
		labs[i][j] = -1; // Initializes each station of each lab as empty
	}
  } 
}

void freeArrays(IntPtr labs[])
{
	for (int i = 0; i < NUMLABS; i++){
		delete[] labs[i]; // Free dynamically allocated memory
	}
}

/* showLabs:
   Displays the status of all labs (who is logged into which computer).
   Precondition: labs[] is a multidimension array of labs with computers
                 labsizes[i] contains the size of the array in labs[i]
 
 */
void showLabs(IntPtr labs[], int labsizes[])
{

	int i;
	int j;

	cout << "LAB STATUS" << endl;
	cout << "Lab #     Computer Stations" << endl;
	for (i=0; i < NUMLABS; i++)
	{
		cout << i+1 << "         ";
		for (j=0; j < labsizes[i]; j++)
		{
			cout << (j+1) << ": ";
			if (labs[i][j] == -1)
			{
				cout << "empty ";
			}
			else
			{
				cout << labs[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}

void login(IntPtr labs[], int labsizes[])
{
	int userID, labNum, stationNum;

	cout << "Enter the 5 digit ID number of the user logging in:" << endl;
	cin >> userID;
	if (userID < 10000 || userID > 99999){
		cout << "Invalid user ID." << endl;
		return;
	}

	cout << "Enter the lab number the user is logging in from (1-4):" << endl;
	cin >> labNum;
	if (labNum < 1 || labNum > NUMLABS){
		cout << "Invalid lab number." << endl;
		return;
	}

	cout << "Enter computer station number the user is logging in to (1-" << labsizes[labNum -1] << "):" << endl; // -1 to adjust for 0-indexing
	cin >> stationNum;
	if (stationNum < 1 || stationNum > labsizes[labNum - 1]){
		cout << "Invalid station number." << endl;
		return;
	}

	// Convert labNum and stationNum to 0-indexing for ease of use
	int labIndex = labNum -1;
	int stationIndex = stationNum - 1;

	if (labs[labIndex][stationIndex] == -1){ //meaning the station is empty
		labs[labIndex][stationIndex] = userID;
	} else {
		cout << "Station is already in use." << endl;
	}
}

void logout(IntPtr labs[], int labsizes[])
{
	int userID;
	cout << "Enter the 5 digit ID number of the user logging in:" << endl;
	cin >> userID;

	for (int i = 0; i < NUMLABS; i++){ // loop through each lab
		for (int j = 0; j < labsizes[i]; j++){ // loop through each computer station
			if (labs[i][j] == userID){
				labs[i][j] = -1; // logs out the user
				cout << "Logout user " << userID << " in Lab " << (i+1) << " at computer " << (j+1) << endl;
				return;
			}
		}
	}
	cout << "User not logged in." << endl;

}

// wouldn't it be better to have the search function be a boolean type, and that way the logout function can call it?
// that way there is not as much code repetition
void search(IntPtr labs[], int labsizes[])
{
	int userID;
	cout << "Enter the 5 digit ID number of the user logging in:" << endl;
	cin >> userID;

	for (int i = 0; i < NUMLABS; i++){ // loop through each lab
		for (int j = 0; j < labsizes[i]; j++){ // loop through each computer station
			if (labs[i][j] == userID){
				cout << "User " << userID << " logged in Lab " << (i+1) << " at computer " << (j+1) << endl;
				return;
			}
		}
	}
	cout << "User not logged in." << endl;
}