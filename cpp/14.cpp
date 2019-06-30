#include <iostream>

using namespace std;

long int next_collatz(long int n){
    if (n % 2 == 0)
    {
        return n / 2;
    } else {
        return 3*n + 1;
    }
    
}

int collatz_length(long int n){
    int s{0};
    while (n != 1)
    {
        n = next_collatz(n);
        s += 1;
    }
    return s;
}

int main() {
    int M = 1000000;
    int arg{1}, max_length{1}, length{};

    for (int i = 1; i <= M; i++)
    {
        length = collatz_length(i);
        if (length > max_length)
        {
            max_length = length;
            arg = i;
        }
    }
    
    cout << arg << endl;

    return 0;
}