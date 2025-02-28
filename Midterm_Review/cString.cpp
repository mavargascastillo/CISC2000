#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char our_string[15] = "Hello there!";
    cout << our_string;
    
    int index = 0;
    while ((our_string[index] != '\0') && (index < 15)){
        our_string[index] = 'X';
        index++;
    }
    cout << our_string;
    return 0;
} 