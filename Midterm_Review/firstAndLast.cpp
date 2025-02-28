#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, first, last;
    cout << "Enter you first and last name: ";
    cin >> first >> last;
    name = first + ' ' + last;
    cout << first[0] << endl << last[0] << endl;
    cout << name;

    return 0;
}