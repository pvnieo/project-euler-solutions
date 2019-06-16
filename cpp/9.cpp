#include <iostream>

using namespace std;


int main() {
    int M = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000 - i; j++)
        {
            int k = 1000 - i - j;
            if (i * i + j * j == k * k && i * j * k > M)
            {
                M = i * j * k;
            }
        }
    }
    
    cout << M << endl;

    return 0;
}