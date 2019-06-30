#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double M = pow(2, 1000);
    string num = to_string(M);
    
    int s{0};
    for (char c : num)
    {
        if (isdigit(c))
           s += c -'0';
        
    }
    
    cout << s << endl;

    return 0;
}