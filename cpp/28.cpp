#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> create_odd_spiral(vector<vector<int>> spiral){

    int spiral_dim = spiral[0].size();
    int last_number = spiral[0].back();
    vector<int> tmp {};
    last_number ++;

    for (int i = 0; i < spiral_dim; i++)
    {
        tmp = spiral[i];
        tmp.push_back(last_number);
        spiral[i] = tmp;
        last_number++;
    }

    tmp = {};
    spiral.push_back(tmp);
    for (int i = 0; i < spiral_dim + 2; i++)
    {
        tmp = {last_number};
        tmp.insert(tmp.end(),spiral.back().begin(),spiral.back().end());
        spiral.pop_back();
        spiral.push_back(tmp);
        last_number++;
    }

    int ind {};
    for (int i = 0; i < spiral_dim; i++)
    {
        ind = spiral.size() - 2 - i;
        tmp = {last_number};
        tmp.insert(tmp.end(),spiral[ind].begin(),spiral[ind].end());
        spiral[ind] = tmp;
        last_number++;
    }
    spiral.insert(spiral.begin(), {{}});

    for (int i = 0; i < spiral_dim + 2; i++)
    {
        tmp = spiral[0];
        tmp.push_back(last_number);
        spiral[0] = tmp;
        last_number++;
    }
    
    return spiral;
}


int main() {
    int sum {0};
    vector<vector<int>> spiral{{1}};

    for (int i = 0; i < 500; i++){
        spiral = create_odd_spiral(spiral);
    }

    for (int i = 0; i < spiral.size(); i++)
        sum += spiral[i][i];
    for (int i = 0; i < spiral.size(); i++)
        sum += spiral[i][spiral.size() -1 -i];

    
    cout << sum -1 << endl;
    return 0;
}