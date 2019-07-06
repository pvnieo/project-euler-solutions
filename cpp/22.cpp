#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

vector<string> split(const string s, char delimiter=',')
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token.substr(1, token.length() - 2));
   }
   return tokens;
}

int main() {
    long int count = 0;

    fstream file("22.txt");
    string names;
    getline(file, names);

    vector<string> vect_names = {};
    vect_names = split(names);
    sort(vect_names.begin(), vect_names.end());

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<char, int> name_weight {};
    int i = 1;
    for (char c: alphabet){
        name_weight[c] = i;
        i++;
    }

    i = 1;
    for (string name: vect_names)
    {
        int weight = 0;
        for (char c: name)
            weight += name_weight[c];
        
        count += weight * i;
        i++;
    }
    
    cout << count << endl;
    return 0;
}