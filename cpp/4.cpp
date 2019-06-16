#include <iostream>

using namespace std;

bool is_pal(string x){
    for (int i = 0; i < x.length() / 2; i++)
    {
        if (x[i] != x[x.length() - 1 - i])
        {
            return false;
        }
        
    }
    return true;
}


int main() {
    int M = 0;

    for (int i = 999; i > 900; --i)
    {
        for (int j = 999; j > 900; --j)
        {
            int N = i * j;
            if (is_pal(to_string(N)))
            {
                if (N > M)
                {
                    M = N;
                }
            }
            
        }
        
    }
    
    cout << M << endl;

    return 0;
}