#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

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

bool is_permutation(int b, int c){
    string bs = to_string(b), cs = to_string(c);
    if (bs.length() != cs.length())
        return false;
    sort(bs.begin(), bs.end());
    sort(cs.begin(), cs.end());
    for (int i = 0; i < bs.length(); i++)
    {
        if (bs[i] != cs[i])
            return false;
    }
    return true;
}

int main()
{
    int a {1487}, b {}, c{};
    vector<int> primes = sieve(10000);

    while (true)
    {
        a += 2;
        b = a + 3330;
        c = a + 6660;
        bool are_primes = (find(primes.begin(), primes.end(), a) != primes.end());
        are_primes = are_primes &&(find(primes.begin(), primes.end(), b) != primes.end());
        are_primes = are_primes &&(find(primes.begin(), primes.end(), c) != primes.end());
        if (are_primes && is_permutation(a, b) && is_permutation(a, c)){
            cout << a << b << c << endl;
            break;
        }
    }

    return 0;
}