/* 
CISC 2000
Programming assignment #0+1:
This program has three parts. This is the second one one. It calculates a new inflation rate as many times as the user wants
Date: Jan 23, 2024
Author: Miguel Ángel Vargas
*/

#include <iostream>
using namespace std;

const int MAX_RATES = 20;

void getCPIValues (float& oldRate, float& newRate);
// Pre:
// Post: 
double calcInflationRate(float oldRate, float newRate);
// Pre: the two rate variables have been declared and initialized
// Post: Calculates the inflation rate given the old and new consumer price index (both must be greater than 0)

void swap_values (double rate1, double rate2);

void sort_array (int arr[], int SIZE);

double findMedianRate (double arr[], int MAX_RATES, int numberRates);


int main() {   
   int numberRates = 0;
   float oldRate, newRate;
   double finalRate, totalRate = 0.0;
   char ans;
   double arr[MAX_RATES];
   
   do {
      getCPIValues(oldRate, newRate);
      finalRate = calcInflationRate(oldRate, newRate);
      array[numberRates] = finalRate;
      cout << "Inflation rate is " << finalRate << endl;
      if (!(finalRate == 0)){
         totalRate += finalRate;
         numberRates++;
      }

      cout << "Try again? (y or Y): ";
      cin >> ans;

   } while (ans == 'y' || ans == 'Y');
   cout << "Average rate is " << totalRate/numberRates;
   findMedianRate(arr[], MAX_RATES, numberRates);


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

void getCPIValues(float& oldRate, float& newRate){
   cout << "Enter the old and new consumer price indices: ";
   do {
      cin >> oldRate >> newRate;
      if (oldRate <= 0 || newRate <= 0) {
         cout << "Error: CPI values must be greater than 0 ";
      }
   } while (oldRate <= 0 || newRate <= 0);
}

void swap_values(double& rate1, double& rate2){
   double temp;
   temp = rate1;
   rate1 = rate2;
   rate2 = temp;
}

void sort_array (int arr[], int SIZE){
   // Selection sort
   int minRateIdx;
   for (int i = 0; i < MAX_RATES-1; i++){
      minRateIdx = i;
      for (int j = i+1; j < MAX_RATES; j++){
         if (arr[j] < arr[minRateIdx]) {
            minRateIdx = j;
         }
      }
      swap_values(arr[minRateIdx], arr[i]);
   }
}

double findMedianRate (double arr[], int MAX_RATES, int numberRates){
   sort_array(arr[], MAX_RATES);
   double medianRate;
   int medianRateIDX1, medianRateIDX2;
   if (numberRates % 2 == 0){
      // if even number of rates, median is the middle value
      medianRateIDX1 = numberRates/2;
      medianRate = arr[medianRateIDX1];
   } else {
      // otherwise, it is the two middle values
      medianRateIDX1 = numberRates/2;
      medianRateIDX2 = (numberRates/2) + 1;
      medianRate = (arr[medianRateIDX1] + arr[medianRateIDX2])/2;
   }
   return medianRate;
}