#include <iostream>
#include <vector>

using namespace std;

long int lattice(int n, int m){
    vector<vector<long int>> lat {n, vector<long int> (m, 1)};
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = m-2; j >= 0; j--)
        {
            lat[i][j] = lat[i+1][j] + lat[i][j+1];
        }
    }
    return lat[0][0];
}

int main() {
    
    cout << lattice(21, 21) << endl;

    return 0;
}