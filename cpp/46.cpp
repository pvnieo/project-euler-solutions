#include <iostream>
#include <cmath>
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


int main() {
    int i {3};
    float t{};
    bool dr {};
    vector<int> primes {2};


    while (true)
    {
        if (is_prime(i)){
            primes.push_back(i);
        } else {
            for (int x: primes)
            {
                t = sqrt((i -x) / 2);
                dr = false;
                if (ceil(t) == t){
                    dr =true;
                    break;
                }
            }

            if (not dr)
                break;
        }
        i += 2;
    }

    cout << i << endl;


    return 0;
}