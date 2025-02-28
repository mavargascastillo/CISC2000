// I did not finish this one

#include <iostream>
#include <cstring>
using namespace std;

char* getString(data[], info[]);

int main() {
    char info[40] = "Bob 45 Programmer";
    char name[6] = "";
    char age[3] = "";
    char job[15] = "";

    name = getString(name, info);
    age = getString(age, info);
    job = getSting(job,info)

    cout << name << endl << age << endl << job;

    return 0;
}

char* getString(data[], info[]) {
    char a;
    char string[15] = "";
    int i = 0;
    do {
        a = info[i];
        string = strcat(data, &a);
        i++;
    } while (a != ' ');
    cout << name;
}