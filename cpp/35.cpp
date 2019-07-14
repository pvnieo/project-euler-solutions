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

vector<int> rotations(vector<int> digits){
    vector<int> l {};

    for (int i = 0; i < digits.size() - 1; i++)
    {
        digits.insert(digits.begin(), digits.back());
        digits.pop_back();
        string tmp {};
        for (int i: digits)
            tmp += to_string(i);
        l.push_back(stoi(tmp));
    }

    return l;
}

bool is_circular_prime(int p){
    if (p == 2)
        return true;

    vector<int> digits {};
    int tmp {};

    for (char c: to_string(p)){
        tmp = c - '0';
        if (tmp % 2 == 0)
            return false;
        digits.push_back(tmp);
    }
    
    vector<int> combinations = rotations(digits);

    for (int x: combinations){
        if (! is_prime(x))
            return false;
    }

    return true;
}


int main() {  
    int s {};

    for (int i = 0; i < 1000000; i++)
    {
        if (is_prime(i) && is_circular_prime(i))
            s += 1;
    }

    cout << s << endl;

    return 0;
}