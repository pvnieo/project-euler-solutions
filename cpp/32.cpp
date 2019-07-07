#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {
    set<int> pandigitals {};
    string p {};
    int sum {};

    for (int i = 1; i < 9999; i++)
    {
        for (int j = 0; j < 9999; j++)
        {
            p = to_string(i * j) + to_string(i) + to_string(j);
            if (p.length() > 9)
                break;

            sort(p.begin(), p.end());
            if (p == "123456789")
                pandigitals.insert(i * j);
        }
    }
    
    for (int i: pandigitals)
        sum += i;

    cout << sum << endl;
    return 0;
}