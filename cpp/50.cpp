#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    else if (n <= 3)
    {
        return true;
    }
    else if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    int i = 5;

    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
        i += 6;
    }
    return true;
}

int get_longest_prime(int n)
{
    vector<int> primes{};
    int P {1}, M{0}, p{};
    for (int i = 0; i < n + 1; i++)
    {
        if (is_prime(i))
            primes.push_back(i);
    }
    for (int i = 0; i < primes.size(); i++)
    {
        p = primes[i];
        for (int j = i + 1; j < primes.size(); j++)
        {
            p += primes[j];
            if (p > n)
            {
                break;
            }
            else if (((j - i) > M) && find(primes.begin(), primes.end(), p) != primes.end())
            {
                M = j - i + 1;
                P = p;
            }
        }
    }
    return P;
}

int main()
{
    cout << get_longest_prime(1000000) << endl;

    return 0;
}