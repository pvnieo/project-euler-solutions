#include <iostream>

using namespace std;


int main() {
    string d {};
    int i {1}, p {1};
    int needed[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

    while (d.length() < 1000000)
    {
        d += to_string(i);
        i++;
    }
    
    for (int x: needed)
        p *= d[x - 1] - '0';
    

    cout << p << endl;

    return 0;
}