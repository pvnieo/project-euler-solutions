#include <iostream>
#include <set>
#include <cmath>

using namespace std;


int main() {
    set<double> all_powers {};

    for (int a = 2; a < 101; a++)
    {
        for (int b = 2; b < 101; b++)
        {
            all_powers.insert(pow(a, b));
        }
        
    }

    cout << all_powers.size() << endl;
    return 0;
}