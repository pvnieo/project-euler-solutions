#include <iostream>
#include <cmath>

using namespace std;


bool is_penta(int n){
    long double t = (1 + sqrt(1 + 24. * n)) / 6;
    if (ceilf(t) == t)
        return true;
    return false;
}


bool is_hexa(int n){
    long double t = (1 + sqrt(1 + 8. * n)) / 4;
    if (ceilf(t) == t)
        return true;
    return false;
}


int main() {
    long long int i = 286;
    unsigned long long int t {};

    while (true)
    {
        t = (i * (i+1)) / 2;
        if (is_penta(t) && is_hexa(t))
            break;
        i++;
    }

    cout <<  t << endl;

    return 0;
}