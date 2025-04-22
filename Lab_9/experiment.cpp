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
#include <iomanip>
#include "TempList.h"

using namespace std;

// Function to perform an experiment
TempList performExperiment(int numData)
{
	TempList experiment(numData);
	for (int j = 0; j < numData; j++) {
		double temp;
		cout << "You will be prompted to take temp after after 1 second\n";
		//sleep(1);
		cout << "Enter temp data now: ";
		cin >> temp;
		experiment.add_temp(temp);
	}
	return experiment;
}

// Function to print an experiment
void printExperiment(TempList data)
{
	cout << "  Time   " ;
	for (int i = 0; i < data.size(); i++)
	{
		cout << setw(2) << setfill('0') << i*5 << setw(4) << setfill(' ') << ' ';
	}
	cout << endl << setw(6) << "Temp" ;
	for (int i = 0; i < data.size(); i++)
	{
		cout << setw(6) << data.at(i).temp ;
	}
	cout << endl;
}

// Main program
// Reads in number of experiments and number of data items per experiment.
// Collects data for the experiments.
int main() {
	TempList *experiments;
	int numExper = 0;
	int numData = 0;

	// Get the number of experiments and data elements for each.
	do {
		cout << "Enter the number of experiments: " << endl;
		cin >> numExper;
	} while (numExper < 0);

	experiments = new TempList[numExper];

	// Collect data for the Experiments
	for (int i = 0; i < numExper; i++) {

		do {
			cout << "Enter the number of data points to collect: " << endl;
			cin >> numData;
		} while (numData < 0);

		cout << "Enter data for experiment # " << (i+1) << endl;
		experiments[i] = performExperiment(numData);
	}

	// Print the data for the experiments
	for (int i = 0; i < numExper; i++) {
		cout << "Data for Experiment # " << (i+1) << endl;
		printExperiment(experiments[i]);
	} 
	delete [] experiments;
	return 0;
}

