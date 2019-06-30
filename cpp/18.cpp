#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> split_and_int(const string s, char delimiter=' ')
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


int main() {
    fstream file("18.txt");
    string line;
    vector<vector<int>> pyramide;
    while (getline(file, line))
    {
        pyramide.push_back(split_and_int(line));
    }

    for (int i = pyramide.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < pyramide[i].size(); j++)
        {
            pyramide[i][j] += max(pyramide[i+1][j], pyramide[i+1][j+1]);
        }
        
    }
    

    cout << pyramide[0][0] << endl;

    return 0;
}