#include <iostream>
#include <fstream>

using namespace std;

long long int reduce(string x);

int main() {
    long long int max = 0;

    fstream file("8.txt");
    string line, lines;
    while (getline(file, line))
    {
        lines += line;
    }

    for (int i = 0; i < lines.length() - 12; i++)
    {
        string s = lines.substr(i, 13);
        long long int p = reduce(s);
        if (p > max)
            max = p;
    }
    
    cout << max << endl;
    return 0;
}

long long int reduce(string x){
    long long int p = 1;
    for (int i = 0; i < x.length(); i++)
    {
        int ch = x[i] - '0';
        p *= ch;
    }
    return p;
}