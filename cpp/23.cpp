#include <iostream>
#include <vector>

using namespace std;


bool is_abundant(int n){
    int s = 0;
    for (int i = 1; i < n/2 + 1; i++)
    {
        if (n % i == 0)
            s += i;
    }
    if (s > n)
        return true;
    else
        return false;
}

bool is_sum_abundant(int n, vector<int> list_abundant){
    int x{};
    for (int i = list_abundant.size() - 1; i >= 0; i--)
    {
        x = list_abundant[i];
        if (x < n)
            return false;
        else if (n == x)
            return true;
    }
    return false;
}

int main() {
    int sum {0}, th_max {28123};
    vector<int> abundants{};

    bool dr {false};
    for (int i = 1; i < th_max; i++)
    {
        cout << i << "\r";

        if (is_abundant(i))
            abundants.push_back(i);

        dr = false;
        for (int x: abundants){
            if (is_sum_abundant(i - x, abundants)){
                dr = true;
                break;
            }
        }

        if (dr == false)
            sum += i;
    }
    cout << endl;
    
    
    
    cout << sum << endl;
    return 0;
}