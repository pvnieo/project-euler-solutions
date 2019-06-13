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
    int maximum = 10001;
    int counter = 0, i = 2;

    while (counter < maximum)
    {
        if (is_prime(i))
        {
            counter++;
        }
        i++;
    }
    
    
    cout << i - 1 << endl;

    return 0;
}