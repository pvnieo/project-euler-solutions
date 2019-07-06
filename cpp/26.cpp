#include <iostream>
#include <vector>
#include <string>

using namespace std;


int find(vector<int> vec, int i){
    for (int j = 0; j < vec.size(); j++){
        if (i == vec[j])
            return j;
    }
    return -1;
}


string get_cycle(int a, int b){
    string decimal = "";

    if (a >= b)
        a = a % b;

    vector<int> restes {};
    while (a != 0 and find(restes, a) == -1){
        restes.push_back(a);
        a *= 10;
        decimal += to_string(a / b);
        a = a % b;
    }

    if (a == 0)
        return "";
    else
        return decimal.substr(find(restes, a), decimal.length() - find(restes, a));
}


int main() {
    int max_len {0}, k {0}, length {0};
    string cycle{};

    for (int i = 1; i < 1000; i++)
    {
        cycle = get_cycle(1, i);
        length = cycle.length();
        if (max_len < length){
            max_len = length;
            k = i;
        }
    }
    
    cout << k << endl;
    return 0;
}