#include <iostream>
#include <vector>

using namespace std;

vector<int> high_precesion_product(vector<int> big_num, int num){
    int r {0};
    vector<int> result {};

    for (int  i = 0; i < big_num.size(); i++)
    {
        int prod = big_num[i] * num + r;
        string prod_str = to_string(prod);
        result.push_back(prod_str[prod_str.size() - 1] - '0');
        if (prod_str.size() == 2)
            r = prod_str[0] - '0';
        else if (prod_str.size() > 2)
            r = stoi(prod_str.substr(0, prod_str.size() - 1));
    }

    string r_str = to_string(r);
    for (int i = r_str.size() - 1; i >= 0; i--)
        result.push_back(r_str[i] - '0');
    
    return result;
}

int main() {
    long double r {1};
    int count {0};
    vector<int> big_num {1};

    for (int i = 1; i < 100; i++)
        big_num = high_precesion_product(big_num, i);

    for (int i: big_num)
        count += i;
    
    cout << count << endl;

    return 0;
}