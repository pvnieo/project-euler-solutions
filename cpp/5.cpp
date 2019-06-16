#include <iostream>

using namespace std;

bool is_div_20(int x){
    for (int i = 2; i < 21; i++)
        {
            if (x % i != 0)
            {
                return false;
            }
        }
    return true;
}

int main() {
    int i = 1;

    while (true)
    {
        int k = 19 * 17 * i;
        if (is_div_20(k))
        {
            cout << k << endl;
            break;
        }
        i++;
    }

    return 0;
}