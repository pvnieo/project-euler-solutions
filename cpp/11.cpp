#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream file("11.txt");
    string line;
    
    while (getline(file, line))
    {
        lines += line;
    }
    
    cout << 0 << endl;

    return 0;
}