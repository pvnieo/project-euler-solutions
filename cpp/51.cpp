#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <boost/algorithm/string/replace.hpp>

using namespace std;
using namespace boost;

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

vector<int> sieve(int n)
{
    vector<int> is_prime(n, 1), primes{2};
    int index{};
    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 3; i < sqrt(n) + 1; i++)
    {
        index = i * 2;
        while (index < n)
        {
            is_prime[index] = 0;
            index = index + i;
        }
    }
    for (int i = 3; i < n; i += 2)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

bool is_eight_family(string s, char c)
{
    int count{}, n{};
    string cc (1, c), temp = s;
    for (int i = 0; i < 10; i++)
    {
        s = temp;
        replace_all(s, cc, to_string(i));
        n = stoi(s);
        if (is_prime(n) and n > 100000)
            count++;
    }
    return (count == 8);
}

int main()
{
    vector<int> primes = sieve(1000000);
    string s{};

    for (int prime : primes)
    {
        if (prime > 100000)
        {
            s = to_string(prime);
            int c0 = count(s.begin(), s.end(), '0');
            int c1 = count(s.begin(), s.end(), '1');
            int c2 = count(s.begin(), s.end(), '2');
            if ((c0 == 3 and is_eight_family(s, '0')) or (c1 == 3 and is_eight_family(s, '1')) or (c2 == 3 and is_eight_family(s, '2')))
            {
                cout << prime << endl;
                break;
            }
        }
    }

    return 0;
}