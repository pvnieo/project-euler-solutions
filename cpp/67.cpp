#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> split_and_int(const string s, char delimiter = ' ')
{
    vector<int> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(stoi(token));
    }
    return tokens;
}

int main()
{
    fstream file("67.txt");
    string line{};
    vector<vector<int>> grid{};

    while (getline(file, line))
    {
        grid.push_back(split_and_int(line));
    }

    for (int i = grid.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            grid[i][j] += max(grid[i+1][j], grid[i+1][j+1]);
        }
    }

    cout << grid[0][0] << endl;

    return 0;
}