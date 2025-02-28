#include <iostream>
#include <vector>
using namespace std;

void swapFrontBack(vector<int> &vector);

int main() {
    vector<int> v = {1, 2, 3, 4};

    swapFrontBack(v);
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }

    return 0;
}

void swapFrontBack(vector<int> &vector){
    int temp;
    if (vector.empty()){
        cout << "The vector is empty! ";
        return;
    } else {
        temp = vector[0];
        vector[0] = vector[vector.size()-1];
        vector[vector.size()-1] = temp;

    }
}