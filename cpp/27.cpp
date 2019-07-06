#include <iostream>

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


int len_consectuve_prime(int a, int b){
    int s {0};

    while (true){
        if (is_prime(s * s + a * s + b))
            s++;
        else
            break;
    }
    return s-1;
}


int main() {
    int M {0}, p{1}, length {0};

    for (int a = -999; a < 1000; a++)
    {
        for (int b = -999; b < 1000; b++)
        {
            length = len_consectuve_prime(a, b);
            if (length > M){
                M = length;
                p = a * b;
            }
        }
    }
    

    cout << p << endl;
    return 0;
}