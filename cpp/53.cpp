#include <iostream>
#include <map>
#include <vector>

using namespace std;


map<vector<int>, long double> factorials{{{0, 1}, 1}};

long double combinations(int n, int r)
{
    vector<int> ind{r, n};
    if ((factorials.find(ind) != factorials.end()))
    {
        return factorials[ind];
    }
    if (r == 0)
    {
        factorials[ind] = 1;
        return 1;
    }
    if (n == r)
    {
        factorials[ind] = 1;
        return 1;
    }
    long double result = combinations(n - 1, r - 1) + combinations(n - 1, r);
    factorials[ind] = result;
    return result;
}

int main()
{
    int s{0};

    for (int n = 1; n < 101; n++)
    {
        for (int r = 0; r < n + 1; r++)
        {
            if (combinations(n, r) > 999999)
                s += 1;
        }
    }

    cout << s << endl;

    return 0;
}