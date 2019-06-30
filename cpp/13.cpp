#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main() {
    int max = 0;
    vector<string> lines{};


    fstream file("13.txt");
    string line;
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    string sum{};
    int temp{0}, r{0};
    
    for (int j = lines[0].size()-1; j >= 0 ; j--)
    {
        for (int i = 0; i < lines.size(); i++)
        {
            temp += lines[i][j] - '0';
        }
        temp += r;
        string temp_str = to_string(temp);
        r = stoi(temp_str.substr(0, temp_str.size()-1));
        sum = temp_str[temp_str.size()-1] + sum;
        temp = 0;
    }
    sum = to_string(r) + sum;

    cout << sum.substr(0, 10) << endl;

    return 0;
}