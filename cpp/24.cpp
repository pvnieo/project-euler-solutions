#include <iostream>
#include <algorithm>

using namespace std;



int main() {
    int range[] {0,1,2,3,4,5,6,7,8,9};
    sort(range, range + 10);

    for (int i = 0; i < 999999; i++)
    {
        next_permutation(range, range + 10);
    }

    for (int j: range)
        cout << j;
    cout << endl;
    
    return 0;
}