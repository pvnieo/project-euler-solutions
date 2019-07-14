#include <iostream>
#include <math.h>

using namespace std;


int num_solution(int p){
    int s {};
    for (int a = 1; a < p / 2; a++)
    {
        float b = (p * p - 2 * a * p) / float(2 * p - 2 * a);

        if (ceil(b) == b)
            s++;
    }
    
    return s / 2;
}


int main() {
    int M {}, p {}, s{};

    for (int i = 1; i < 1001; i++)
    {
        s = num_solution(i);
        if (s > M){
            M = s;
            p = i;
        }
    }
    
    cout << p << endl;

    return 0;
}