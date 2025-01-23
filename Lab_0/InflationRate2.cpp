/* 
CISC 2000
Programming assignment #0+1:
This program has three parts. The second one, calculates a new inflation rate as many times as the user wants. 
Date: Jan 23, 2024
Author: Miguel Ángel Vargas
*/

#include <iostream>
using namespace std;

double calcInflationRate(double oldRate, double newRate);
// Pre: the two rate variables have been declared and initialized
// Post: Calculates the inflation rate given the old and new consumer price index (both must be greater than 0)

int main() {   
   int numberRates = 0;
   double oldRate, newRate, finalRate, totalRate = 0.0;
   char ans;
   
   do {

      cout << "Enter the old and new consumer price indices: ";
      cin >> oldRate >> newRate;
      finalRate = calcInflationRate(oldRate, newRate);
      cout << "Inflation rate is " << finalRate << endl;
      if (!(finalRate == 0)){
         totalRate += finalRate;
         numberRates++;
      }

      cout << "Try again? (y or Y): ";
      cin >> ans;

   } while (ans == 'y' || ans == 'Y');
   cout << "Average rate is " << totalRate/numberRates;

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