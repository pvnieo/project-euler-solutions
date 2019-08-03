#include <iostream>
#include <string>
#include "bigint.cpp"

using namespace std;

int digital_sum(string s)
{
    int sum_{};
    for (char c : s)
        sum_ += c - '0';
    return sum_;
}

int main()
{
    int maximum {}, M {};

    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            Dodecahedron::Bigint a = i;
            M = digital_sum(to_string(a.pow(j)));
            if (M > maximum)
                maximum = M;
        }
    }

    cout << maximum << endl;

    return 0;
}