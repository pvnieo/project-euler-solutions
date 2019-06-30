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

long int prod_adjacent(vector<vector<int>> grid, int i, int j,  int dir[], int num_adj=4)
{
    long int p{1};
    for (int a = 0; a < num_adj; a++)
    {
        p = p * grid[i + a*dir[0]][j + a*dir[1]];
    }
    return p;
}

int main() {
    fstream file("11.txt");
    string line {};
    vector<vector<int>> grid{};
    
    while (getline(file, line))
    {
        grid.push_back(split_and_int(line));
    }


    int n{grid.size()}, m{grid[0].size()};
    long int M{0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m-4; j++)
        {  
            int dir[] = {0, 1};
            if (prod_adjacent(grid, i, j, dir) > M)
            {
                M = prod_adjacent(grid, i, j, dir);
            }
            
        }
        
    }

    for (int i = 0; i < n-4; i++)
    {
        for (int j = 0; j < m; j++)
        {  
            int dir[] = {1, 0};
            if (prod_adjacent(grid, i, j, dir) > M)
            {
                M = prod_adjacent(grid, i, j, dir);
            }
            
        }
        
    }

    for (int i = 0; i < n-4; i++)
    {
        for (int j = 0; j < m-4; j++)
        {  
            int dir[] = {1, 1};
            if (prod_adjacent(grid, i, j, dir) > M)
            {
                M = prod_adjacent(grid, i, j, dir);
            }
            
        }
        
    }

    for (int i = 0; i < m-4; i++)
    {
        for (int j = 3; j < n; j++)
        {  
            int dir[] = {1, -1};
            if (prod_adjacent(grid, i, j, dir) > M)
            {
                M = prod_adjacent(grid, i, j, dir);
            }
            
        }
        
    }
    

    cout << M << endl;
    


    return 0;
}