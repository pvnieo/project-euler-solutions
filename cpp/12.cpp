#include <iostream>
#include <vector>

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

vector<vector<int>> prime_factorisation(int n, vector<int> primes){
    vector<vector<int>> factorisation{};
    int i{0};
    vector<int> temp{0, 0};
    while (n != 1)
    {
        int p = primes[i];
        while (n % p == 0)
        {
            temp[0] = p;
            temp[1] = temp[1] + 1;
            n /= p;
        }
        factorisation.push_back(temp);
        temp[1] = 0;
        i += 1;
    }
    return factorisation;
}

int num_divisors(int n, vector<int> primes){
    if (n < 2)
    {
       return 1;
    }
    vector<vector<int>> factorisation = prime_factorisation(n, primes);
    int num{1};
    for (int i = 0; i < factorisation.size(); i++)
    {
        num *= factorisation[i][1] + 1;
    }
    
    return num;
}

int main() {
    int M = 2000000;
    vector<int> primes{};

    for (int i = 2; i < M; i++)
    {
        if (is_prime(i))
        {
            primes.push_back(i);
        }
        
    }
    
    int s{0}, i{1};
    int nd = num_divisors(s, primes);

    while (nd < 500)
    {
        s += i;
        nd = num_divisors(s, primes);
        i++;
    }
    

    cout << s << endl;

    return 0;
}