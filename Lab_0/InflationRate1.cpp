/* 
CISC 2000
Programming assignment #0+1:
This program has three parts. The first one, calculates a new inflation rate. 
Date: Jan 23, 2024
Author: Miguel Ángel Vargas
*/

#include <iostream>
using namespace std;

double calcInflationRate(double oldRate, double newRate);
// Pre: the two rate variables have been declared and initialized
// Post: Calculates the inflation rate given the old and new consumer price index (both must be greater than 0)

int main() { 
   
   double oldRate, newRate, finalRate;
   cout << "Enter the old and new consumer price indices: ";
   cin >> oldRate >> newRate;
   finalRate = calcInflationRate(oldRate, newRate);
   cout << "Inflation rate is " << finalRate;

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