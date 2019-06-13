#include <iostream>

using namespace std;


int main() {
    int s1 = 0, s2 = 0;

    for (int i = 0; i < 101; i++)
    {
        s1 += i * i;
        s2 += i;
    }
    
    cout << s2 * s2 - s1 << endl;

    return 0;
}