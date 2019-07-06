#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> add_vec(vector<int> a, vector<int> b){
    int r = 0;
    vector<int> result {};
    if (a.size() < b.size()){
        vector<int> tmp = b;
        b = a;
        a = tmp;
    }

    int s{};
    string ss {};
    for (int i = 0; i < b.size(); i++)
    {
        s = a[i] + b[i] + r;
        ss = to_string(s);
        result.push_back(ss[ss.length()-1] - '0');
        (s > 9) ? r = stoi(ss.substr(0, ss.length()-1)) : r = 0;
    }

    for (int i = b.size() ; i < a.size(); i++)
    {
        s = a[i] + r;
        ss = to_string(s);
        result.push_back(ss[ss.length()-1] - '0');
        (s > 9) ? r = stoi(ss.substr(0, ss.length()-1)) : r = 0;
    }
    
    if (r != 0){
        ss = to_string(r);
        for (char c: ss)
            result.push_back(c - '0');
    }

    return result;
}



int main() {
    vector<int> fib2 {1}, fib1{1}, fib{2};
    int n{3};

    while (fib.size() < 1000)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = add_vec(fib1, fib2);
        n++;
    }

    cout << n << endl;
    return 0;
}