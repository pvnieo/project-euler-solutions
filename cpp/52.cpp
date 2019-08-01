#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<int> int_to_vector(int n)
{
    vector<int> result{};
    string s = to_string(n);
    for (char c : s)
    {
        result.push_back(c - '0');
    }
    sort(result.begin(), result.end());
    return result;
}

bool is_multi_has_same_digits(int n)
{
    vector<int> base = int_to_vector(n), temp {};
    for (int i = 2; i < 7; i++)
    {
        temp = int_to_vector(n * i);
        if (base != temp)
            return false;
    }
    return true;
}

using namespace std;

int main()
{
    int x {10};

    while (not is_multi_has_same_digits(x))
        x++;

    cout << x << endl;

    return 0;
}