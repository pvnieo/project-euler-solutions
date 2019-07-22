#include <iostream>
#include <algorithm>

using namespace std;


bool check_property(int n[10]){
    if((n[3] % 2 != 0) || (n[5] != 0 && n[5] != 5) || (n[0] == 0)){
        // cout << "first condition" << endl;
        return false;
    }

    int tests[7] = {2, 3, 5, 7, 11, 13, 17};

    for (int i = 0; i < 7; i++)
    {
        string tmp {};
        for (int j = 1; j < 4; j++)
        {
            tmp += n[i+j] + '0';
        }
        // cout << "tmp  " << tmp << endl;
        int a = stoi(tmp);
        // cout << a << "   " << tests[i] << endl;
        if (a % tests[i] != 0)
            return false;
    }

    return true;
}

int factorial(int n){
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}


int main() {
    int range[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int s {0};

    for (int i = 0; i < factorial(10); i++)
    {
        next_permutation(range, range + 10);

        if (check_property(range)){
            string tmp {};

            for (int j = 0; j < 10; j++)
            {
                tmp += range[j] + '0';
            }

            long long int a = stoll(tmp);
            s += a;
        }
    }

    cout << s << endl;

    return 0;
}