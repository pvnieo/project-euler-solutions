#include <iostream>
#include <vector>

using namespace std;


vector<int> factorial_cache {};

int factorial(int n){
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

bool is_digit_factorial(int n){
    if (n <= 2)
        return false;

    int s {};
    for (char c: to_string(n))
        s += factorial_cache[c - '0'];
    
    if (s == n)
        return true;
    else
        return false;
}


int main() {

    for (int i = 0; i < 10; i++)
    {
        factorial_cache.push_back(factorial(i));
    }
    
    int s {};

    for (int i = 2; i < 8 * factorial_cache[9] + 1; i++)
    {
        if (is_digit_factorial(i))
            s += i;
    }
    


    cout << s << endl;
    return 0;
}