#include <vector>
#include <iostream>

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

    vector<int> horizontal;
    vector<int> vertical;


    for (int i = 0; i < grid.size(); i++)
    {
        int vertical_max = 0;
        int horizontal_max = 0;
        for (int j = 0; j < grid.at(i).size(); j++)
        {
            if (grid.at(i).at(j) > vertical_max)
            {
                vertical_max = grid.at(i).at(j);
            }

            if (grid.at(j).at(i) > horizontal_max)
            {
                horizontal_max = grid.at(j).at(i);
            }
        }
        vertical.push_back(vertical_max);
        horizontal.push_back(horizontal_max);
    }

    int sum = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.at(i).size(); j++)
        {
            int max_i_j = (vertical.at(i) < horizontal.at(j)) ? vertical.at(i) : horizontal.at(j);
            sum += (max_i_j - grid.at(i).at(j));
            grid.at(i).at(j) = max_i_j;
        }
    }

    return sum;
}

void assert(string input, string actual, string expected)
{
    cout << "Input: " << input << " Output: " << actual << " Expected: " << expected << endl;
}

int main()
{
    vector<vector<int>> input = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    int output = maxIncreaseKeepingSkyline(input);
    cout << "Expected: 35 " << "Actual: " << output << endl;
}
