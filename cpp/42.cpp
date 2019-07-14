#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>
#include <cmath>

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
    fstream file("42.txt");
    string words;

    getline(file, words);

    vector<string> vect_words = {};
    vect_words = split(words);

    int num_triangles {};

    int s {};
    float test {};
    for (string word: vect_words){
        s = 0;
        for (char c: word)
            s += c - 64;
        
        test = (-1 + sqrt(1 + 8 * s)) / 2;

        if (ceil(test) == test)
            num_triangles++;

    }

    cout << num_triangles << endl;

    return 0;
}