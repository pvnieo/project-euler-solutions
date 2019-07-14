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

bool is_truncatable_prime(int p){
    if (p == 2)
        return true;

    string digits = to_string(p);
    for (int i = 0; i < digits.length(); i++)
    {
        if ((digits[i] - '0') % 2 == 0 && i > 0)
            return false;
    }
    
    if ((digits[0] - '0') % 2 == 0 && (digits[0] - '0') != 2)
        return false;
    
    for (int i = 0; i < digits.length() - 1; i++)
    {
        int a {}, b {};
        a = stoi(digits.substr(0, digits.length() - 1 - i));
        b = stoi(digits.substr(i + 1, digits.length() - 1 - i));

        if ((! is_prime(a)) || (! is_prime(b)))
            return false;
    }
    
    return true;
}


int main() {
    int sum {0}, count {0}, i {11};

    while (count < 11)
    {
        if (is_prime(i) && is_truncatable_prime(i)){
            count++;
            sum += i;
        }
        i += 2;
    }
    
    cout << sum << endl;

    return 0;
}