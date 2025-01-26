/* 
CISC 2000
Programming assignment #0+1:
This program has three parts. This is the third one. It calculates a new inflation rate as many times as the user wants, and calculates
the median rate. 
Date: Jan 26, 2024
Author: Miguel Ángel Vargas
*/


#include <iostream>
using namespace std;

const int MAX_RATES = 20;

void getCPIValues (double& oldRate, double& newRate);
// Pre: oldRate and newRate have been declared
// Post: assigns values given by user to variables, given that they are greater than 0

double calcInflationRate(double oldRate, double newRate);
// Pre: the two rate variables have been declared and initialized
// Post: Calculates the inflation rate given the old and new consumer price index (both must be greater than 0)

void swap_values (double& rate1, double& rate2);
// Pre: two variables have been initialized
// Post: swaps values 

void sort_array (double arr[], int SIZE);
// Pre: array has been initialized and filled with SIZE elements
// Post: the array is ordered in ascending order

double findMedianRate (double arr[], int numberRates);
// Pre: array has been initialized and filled with numberRates elements
// Post: returns the median rate of the array


int main() {   
   int numberRates = 0;
   double oldRate, newRate;
   double finalRate,medianRate, totalRate = 0.0;
   char ans;
   double arr[MAX_RATES];
   
   do {
      getCPIValues(oldRate, newRate);
      finalRate = calcInflationRate(oldRate, newRate);
      arr[numberRates] = finalRate;
      cout << "Inflation rate is " << finalRate << endl;
      if (!(finalRate == 0)){
         totalRate += finalRate;
         numberRates++;
      }

      cout << "Try again? (y or Y): ";
      cin >> ans;

   } while (ans == 'y' || ans == 'Y');
   cout << "Average rate is " << totalRate/numberRates << endl;
   medianRate = findMedianRate(arr, numberRates);
   cout << "Median rate is " << medianRate << endl;


   return 0;
}

double calcInflationRate(double oldRate, double newRate){

   double finalRate;
   if (oldRate <= 0 || newRate <= 0) {
      finalRate = 0;
   } else {
      finalRate = ((newRate - oldRate) / oldRate) * 100;
   }
   return finalRate;
}

void getCPIValues(double& oldRate, double& newRate){
   do {
      cout << "Enter the old and new consumer price indices: ";
      cin >> oldRate >> newRate;
      if (oldRate <= 0 || newRate <= 0) {
         cout << "Error: CPI values must be greater than 0 " << endl;
      }
   } while (oldRate <= 0 || newRate <= 0);
}

void swap_values(double& rate1, double& rate2){
   double temp;
   temp = rate1;
   rate1 = rate2;
   rate2 = temp;
}

void sort_array (double arr[], int SIZE){
   // Selection sort
   int minRateIdx;
   for (int i = 0; i < SIZE-1; i++){
      minRateIdx = i;
      for (int j = i+1; j < SIZE; j++){
         if (arr[j] < arr[minRateIdx]) {
            minRateIdx = j;
         }
      }
      swap_values(arr[minRateIdx], arr[i]);
   }
}

double findMedianRate (double arr[], int numberRates){
   sort_array(arr, numberRates); // use numberRates as that is the number of elements in the array
   double medianRate;
   int medianRateIDX1, medianRateIDX2;
   if (numberRates % 2 == 0){
      // if even number of rates, median is the average of two middle values
      medianRateIDX1 = numberRates/2;
      medianRateIDX2 = (numberRates/2) - 1;
      medianRate = (arr[medianRateIDX1] + arr[medianRateIDX2])/2;
   } else {
      // otherwise, it is the middle values
      medianRateIDX1 = numberRates/2;
      medianRate = arr[medianRateIDX1];
   }
   return medianRate;
}