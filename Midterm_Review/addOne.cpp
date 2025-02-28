#include <iostream>
using namespace std;

void addOne(*numPtr);

int main()
{
    int n = 10;
    typedef int* IntPtr;
    IntPtr numPtr;
    numPtr = n;
    
    addOne(*numPtr);
    cout << n;
    
    return 0;
}

void addOne(*numPtr){
    numPtr++;
}