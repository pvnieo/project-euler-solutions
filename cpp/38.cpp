#include <iostream>
#include <set>

using namespace std;

set<char> decimal_set = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


bool is_pandigital_9(string n){
    if (n.length() == 9){
        set<char> tmp = {};
        for (char c: n)
            tmp.insert(c);
        
        return tmp == decimal_set;
    }
}

int find_pandigital(int n){
    string t = to_string(n) + to_string(2 * n);
    int i = 3;
    while (t.length() <= 9)
    {
        if (is_pandigital_9(t))
            return stoi(t);
        
        t += to_string(n * i);
        i++;
    }
    
    return 0;
}


int main() {
    int M {};

    for (int i = 0; i < 10000; i++)
    {
        int t = find_pandigital(i);
        if (t && t > M)
            M = t;
    }
    
    cout << M << endl;

    return 0;
}