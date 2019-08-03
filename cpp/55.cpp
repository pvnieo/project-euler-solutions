#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool is_pal(string s)
{
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}

string _sum(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b);

    int j = a.size() - 1;
    for (int i = b.size() - 1; i >= 0; i--, j--)
        a[j] += (b[i] - '0');

    for (int i = a.size() - 1; i > 0; i--)
    {
        if (a[i] > '9')
        {
            int d = a[i] - '0';
            a[i - 1] = ((a[i - 1] - '0') + d / 10) + '0';
            a[i] = (d % 10) + '0';
        }
    }
    if (a[0] > '9')
    {
        string k;
        k += a[0];
        a[0] = ((a[0] - '0') % 10) + '0';
        k[0] = ((k[0] - '0') / 10) + '0';
        a = k + a;
    }
    return a;
}

bool is_lychrel(int n)
{
    string s = to_string(n);
    string temp{};
    int i{};
    while (i <= 50)
    {
        temp = s;
        reverse(s.begin(), s.end());
        s = _sum(temp, s);
        if (is_pal(s))
            return false;
        i++;
    }
    return true;
}

int main()
{
    int count{};

    for (int i = 1; i < 10001; i++)
    {
        if (is_lychrel(i))
            count++;
    }

    cout << count << endl;

    return 0;
}