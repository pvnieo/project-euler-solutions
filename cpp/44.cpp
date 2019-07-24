#include <iostream>
#include <cmath>

using namespace std;

bool is_penta(int k){
    float n = (1 + sqrt(1 + 24 * k)) / 6;
    if (ceilf(n) == n)
        return true;
    return false;
}

int main() {
    int D = 5482660;
    float a {}, b {}, s{}, d {};

    for (int i = 1; i < 100000; i++)
    {
        a = i * (3*i - 1) / 2;
        for (int j = i+1; j < 100000; j++)
        {
            b = j * (3*j - 1) / 2;
            s = a + b;
            d = abs(a - b);
            if (d >= D)
                break;
            if (is_penta(s) && is_penta(d))
                D = d;
        }
    }

    cout << D << endl;

    return 0;
}