#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <boost/algorithm/string/replace.hpp>
#include <sstream>
#include <map>
#include <set>
#include <numeric>

using namespace std;
using namespace boost;

vector<vector<string>> preprocess_hand(string line)
{
    replace_all(line, "T", "10");
    replace_all(line, "J", "11");
    replace_all(line, "Q", "12");
    replace_all(line, "K", "13");
    replace_all(line, "A", "14");
    vector<vector<string>> cards{};
    string token;
    istringstream tokenStream(line);
    while (getline(tokenStream, token, ' '))
    {
        cards.push_back({token.substr(0, token.length() - 1), token.substr(token.length() - 1, 1)});
    }
    return cards;
}

vector<vector<int>> counter(vector<int> values)
{
    vector<vector<int>> count{};

    map<int, int> occurrences{};
    for (int i : values)
    {
        if (occurrences.find(i) != occurrences.end())
            occurrences[i] += 1;
        else
            occurrences[i] = 1;
    }
    for (auto [key, value] : occurrences)
    {
        count.push_back({key, value});
    }
    sort(count.begin(), count.end(),
         [](const std::vector<int> &a, const std::vector<int> &b) {
             return a[1] > b[1];
         });
    return count;
}

///////////////////
// Hand Rankings //
///////////////////

vector<vector<int>> get_rank(vector<vector<string>> cards)
{
    vector<vector<int>> result{};
    vector<int> sorted_values{};
    set<string> symb{};
    for (int i = 0; i < cards.size(); i++)
    {
        sorted_values.push_back(stoi(cards[i][0]));
        symb.insert(cards[i][0]);
    }
    vector<vector<int>> counter_ = counter(sorted_values);
    sort(sorted_values.begin(), sorted_values.end());

    // royal flush
    vector<int> royal{10, 11, 12, 13, 14};
    if (symb.size() == 1 && sorted_values == royal)
    {
        result = {{10}, {sorted_values.back()}, sorted_values};
        return result;
    }

    // straight flush
    vector<int> straight(5);
    iota(straight.begin(), straight.end(), sorted_values[0]);
    if (symb.size() == 1 && straight == sorted_values)
    {
        result = {{9}, {sorted_values.back()}, sorted_values};
        return result;
    }

    // four of a kind
    if (counter_[0][1] == 4)
    {
        result = {{8}, {counter_[0][0]}, sorted_values};
        return result;
    }

    // full house
    if (counter_[0][1] == 3 && counter_[1][1] == 2)
    {
        result = {{7}, {counter_[0][0]}, sorted_values};
        return result;
    }

    // flush
    if (symb.size() == 1)
    {
        result = {{6}, {sorted_values.back()}, sorted_values};
        return result;
    }

    // straight
    if (straight == sorted_values)
    {
        result = {{5}, {sorted_values.back()}, sorted_values};
        return result;
    }

    // three of a kind
    if (counter_[0][1] == 3)
    {
        result = {{4}, {counter_[0][0]}, sorted_values};
        return result;
    }

    //  two pair
    if (counter_[0][1] == 2 and counter_[1][1] == 2)
    {
        result = {{3}, {max(counter_[0][0], counter_[1][0])}, sorted_values};
        return result;
    }

    // one pair
    if (counter_[0][1] == 2)
    {
        result = {{2}, {counter_[0][0]}, sorted_values};
        return result;
    }

    // high card
    result = {{1}, {sorted_values.back()}, sorted_values};
    return result;
}

//////////////////////
// Rankings Players //
/////////////////////

bool is_player_1_winning(vector<vector<string>> game)
{
    vector<vector<string>> player1(game.begin(), game.begin() + 5);
    vector<vector<string>> player2(game.begin() + 5, game.begin() + 10);
    vector<vector<int>> result1 = get_rank(player1);
    vector<vector<int>> result2 = get_rank(player2);
    if (result1[0][0] != result2[0][0])
        return result1[0][0] > result2[0][0];
    else if (result1[1][0] != result2[1][0])
        return result1[1][0] > result2[1][0];
    for (int i = 0; i < 5; i++)
    {
        if (result1[2][4 - i] != result2[2][4 - i])
            return result1[2][4 - i] > result2[2][4 - i];
    }
    return true;
}

int main()
{
    int count{};
    fstream file("54.txt");
    string line{};
    vector<string> hands{};
    vector<vector<string>> cards{};

    while (getline(file, line))
    {
        hands.push_back(line);
    }

    for (string hand : hands)
    {
        cards = preprocess_hand(hand);
        if (is_player_1_winning(cards))
            count++;
    }

    cout << count << endl;
    return 0;
}