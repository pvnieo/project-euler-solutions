#include <iostream>

using namespace std;

bool is_prime(int n){
    if (n <= 1)
    {
        return false;
    } else if (n <= 3)
    {
        return true;
    } else if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    int i =5;

    while (i * i <= n)
    {
        if (n % i == 0 || n % (i+2) == 0)
        {
            return false;
        }
        i += 6;
    }
    return true;
}

int main() {
    int M = 2000000;
    long long int sum = 0;

    for (int i = 0; i < M; i++)
    {
        if (is_prime(i))
        {
            sum += i;
        }
    }
    
    cout << sum << endl;

    return 0;
}