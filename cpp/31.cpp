#include <iostream>
#include <vector>

using namespace std;

int nway(int total, vector<int> coins){
    if (coins.size() == 0)
        return 0;
    int c = coins[0];
    coins.erase(coins.begin());
    int count {};
    
    if (total % c == 0)
        count++;
    
    for (int amount = 0; amount < total; amount += c)
        count += nway(total - amount, coins);
    
    return count;
}


int main() {
    vector<int> coins {1, 2, 5, 10, 20, 50, 100, 200};

    cout << nway(200, coins) << endl;
    return 0;
}