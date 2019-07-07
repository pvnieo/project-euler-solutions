#include <iostream>
#include <cmath>

using namespace std;


int main() {
    int sum {}, tmp {};

    for (int i = 2; i < 400000; i++)
    {
        tmp = 0;
        for(char c: to_string(i))
            tmp += pow(c - '0', 5);
        
        if (tmp == i)
            sum += i;
    }

    cout << sum << endl;
    return 0;
}