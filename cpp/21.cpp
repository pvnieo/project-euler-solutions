#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int sum_div(int m){
    int sm {1};
    if (m % 2 == 0)
    {
        for (int i = 2; i < m/2 + 1; i++)
        {
            if (m % i == 0)
                sm += i;
        }
        
    } else {
        for (int i = 3; i < m/2 + 1; i++)
        {
            if (m % i == 0)
                sm += i;
        }
    }
    return sm;
}

int main() {
    int N {10000};
    vector<int> l {};
    for (int i = 0; i < N+1; i++)
    {
        l.push_back(sum_div(i));
    }

    int amical {0};
    for (int i = 1; i < N; i++)
    {
        int m = l[i];
        if (m >= N)
            continue;
        else if (l[m] == i and i != m)
            amical += i;
    }

    cout << amical << endl;
    return 0;
}