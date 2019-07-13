#include <iostream>

using namespace std;


int main() {
    int n {1}, d {1};

    for (int a = 1; a < 10; a++)
    {
        for (int b = 1; b < a; b++)
        {
            for (int x = 1; x < b; x++)
            {
                if ((x * 10 + a) * b == (a * 10 + b) * x)
                {
                    n *= x;
                    d *= b;
                }
                
            }
            
        }
        
    }
    


    cout << d << ' ' << n << endl;
    return 0;
}