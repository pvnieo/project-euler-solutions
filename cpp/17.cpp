#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<int, string> dic_num {};

string less_than_100_converter(int num){
    int d = num / 10;
    int u = num - d * 10;
    if (d <= 1)
        return dic_num[num];
    else if (u == 0)
        return dic_num[num];
    else
        return dic_num[d*10] + dic_num[u];
}

string between_100_999_converter(int num){
    int c = num / 100;
    int d = (num - 100 * c) / 10;
    int u = num - 100 * c - 10 * d;
    if (d*10 + u == 0)
        return dic_num[c] + dic_num[100];
    else
        return dic_num[c] + dic_num[100] + dic_num[-1] + less_than_100_converter(d*10 + u);
}

string num_to_letter_converter(int num){
    int m = num / 1000;
    int c = (num - 1000*m) / 100;
    int d = (num - 1000*m - 100 * c) / 10;
    int u = num - 1000*m - 100 * c - 10 * d;
    string num_letter {""};
    if (m != 0)
        return "onethousand";
    else if (c == 0)
        num_letter += less_than_100_converter(num);
    else
        num_letter += between_100_999_converter(num);
    
    return num_letter;
}


int main() {
    vector<string> num_to_word {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
                                "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                                "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

    for (int i = 0; i < 21; i++)
        dic_num[i] = num_to_word[i];
    
    dic_num[30] = "thirty";
    dic_num[40] = "forty";
    dic_num[50] = "fifty";
    dic_num[60] = "sixty";
    dic_num[70] = "seventy";
    dic_num[80] = "eighty";
    dic_num[90] = "ninety";
    dic_num[100] = "hundred";
    dic_num[1000] = "thousand";
    dic_num[-1] = "and";

    string s {""};
    for (int i = 1; i < 1001; i++)
        s += num_to_letter_converter(i) + " ";

    cout << s.size() << endl;
    return 0;
}