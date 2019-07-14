#include <iostream>
#include <algorithm>

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

int factorial(int n){
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}


int main() {
    int M {-1};

    for (int i = 9; i > 0; i--)
    {
        int range[i];
        for (int j = 1; j <= i; j++)
        {
            range[j-1] = j;
        }

        for (int j = 0; j < factorial(i); j++)
        {
            next_permutation(range, range + i);
            string tmp {};
            for (int a:range)
                tmp += a + '0';
            int p = stoi(tmp);
            if (p > M && is_prime(p))
                M = p;
        }
        
        if (M != -1)
            break;
    }
    
    cout << M << endl;

    return 0;
}