#include <iostream>

using namespace std;


bool is_pal(string s){
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    
    return true;
}

// use the std defined function for speed
string bin_string(int a){
    string s {};
    while (a > 0)
    {
        s += to_string(a % 2);
        a = (a / 2);
    }
    return s;
}

int main() {
    int sum_ {0};
    string s {}, s_bin {};

    for (int i = 0; i < 1000000; i++)
    {
        s = to_string(i);
        s_bin = bin_string(i);

        if (is_pal(s) && is_pal(s_bin))
            sum_ += i;
    }

    cout << sum_ << endl;

    return 0;
}