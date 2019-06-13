#include <iostream>

using namespace std;

int main() {
    int M = 4000000;

    int fib1 = 1, fib2 = 2, fib = 3;
    int sum = 2;

    while (fib < M)
    {
        if (fib % 2 == 0)
        {
            sum += fib;
        }
        fib1 = fib2;
        fib2 = fib;
        fib = fib1 + fib2;
    }
    
    
    cout << sum << endl;
}