#include <iostream>
#include <cmath>
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

vector<int> primes{2};

vector<vector<int>> prime_factorisation(int n)
{
    vector<vector<int>> factorisation{};
    vector<int> temp{};
    int p {};
    if (find(primes.begin(), primes.end(), n) != primes.end())
    {
        factorisation = {{n, 1}};
        return factorisation;
    }
    else if (is_prime(n))
    {
        primes.push_back(n);
        factorisation = {{n, 1}};
        return factorisation;
    }
    else
    {
        int i = 0;
        while (n != 1)
        {
            p = primes[i];
            temp = {p, 0};
            while (n % p == 0)
            {
                temp = {p, temp[1] + 1};
                n = n / p;
            }
            if (temp[1] != 0)
                factorisation.push_back(temp);
            temp[1] = 0;
            i++;
        }
        return factorisation;
    }
}

int main()
{
    vector<vector<int>> factorisation {};
    int i{2}, distinct{};
    bool dr{};

    while (true)
    {
        distinct = 4;
        dr = true;
        for (int j = 0; j < distinct; j++)
        {
            factorisation = prime_factorisation(i + j);
            if (factorisation.size() < distinct)
            {
                i++;
                dr = false;
                break;
            }
        }
        if (dr)
            break;
    }

    cout << i << endl;

    return 0;
}