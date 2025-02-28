#include <iostream>
#include <vector>
using namespace std;

bool starts(vector<int> vector);

int main() {
    vector<int> v;
    int elements, a;
    cout << "How many elements in the vector: ";
    cin >> elements;

    for (int i = 0; i < elements; i++){
        cout << "Enter number: ";
        cin >> a;
        v.push_back(a); 
    }

    if (starts(v)){
        cout << " Hurray!" << endl;
    } else {
        cout << "Oh oh" << endl;
    }

    return 0;
}

bool starts(vector<int> vector){
    if (vector[0] == 2 || vector[vector.size()-1] == 2){ // access like this the last element because v[-1] is not valid
        return true;
    } else {
        return false;
    }
}