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
    long long int N = 600851475143;
    int i = 2;

    while (i < N / 2)
    {
        if (N % i == 0 && is_prime(N / i))
        {
            cout << N / i << endl;
            break;
        }
        
        i++;
    }

    return 0;
}