/* Top Comment Block Here: Put your name and explain the program!
CISC 2000
Midterm B:
Program asks user to fill a vector with prices, and then finds the largest price
Date: Feb 28, 2025
Author: Miguel Ángel Vargas
 */

#include <iostream>
#include <vector>
using namespace std;

void fillVector(vector<double> &prices, int numPrices);
// Pre: the vector has been declared and numPrices has been inputted by user
// Post: fills a vector with numPrices given by the user

double findLargestPrice(const vector<double> &prices);

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    vector<double> prices;
    int numPrices;
    
    cout << "How many prices? ";
    cin >> numPrices;
    
    fillVector(prices, numPrices);
    
    cout << "The most expensive price is: $" << findLargestPrice(prices) << endl;
    return 0;
}

void fillVector(vector<double> &prices, int numPrices){
    // We pass the vector by reference because we want to modify its contents directly, 
    // not make a copy
    double price;
    for (int i = 0; i < numPrices; i++)
    {
        cout << "Enter price " << i + 1 << ": ";
        cin >> price;
        prices.push_back(price);
    }
}

double findLargestPrice(const vector<double> &prices){
    // Now, we pass the vector as a constant to ensure that we do not modify its contents

    // Do we need to verify if the vector is empty?

    double maxPrice = prices[0];
    for (double price : prices)
    // compare every element of the vector with prices[0]. If the price is greater,
    // assign that value to prices[0]. Similar to a bubble sort
    {
        if (price > maxPrice)
            maxPrice = price;
    }
    return maxPrice;
}