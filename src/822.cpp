#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "vector_helper.h"

using namespace std;

bool isExist(int value, vector<int>& vec)
{
    vector<int>::iterator it = find(vec.begin(), vec.end(), value);
    if (it != vec.end())
    {
        return true;
    }

    return false;
}


int flipgame(vector<int>& fronts, vector<int>& backs)
{
    int min = 2001;
    int tmp;

    unordered_set<int> intersect = {};

    for (int i = 0; i < fronts.size(); i++)
    {
        if (fronts[i] == backs[i])
        {
            intersect.push_back(fronts[i]);
            continue;
        }
    }

    for (int i = 0; i < fronts.size(); i++)
    {
        if (intersect.count(fronts[i]) == 0)
        {
            min = min < fronts[i] ? min : fronts[i];
        }

        if (intersect.count(backs[i]) == 0)
        {
            min = min < backs[i] ? min : backs[i];
        }
    }

    return min == 2001 ? 0 : min;
}



int main()
{
    vector<int> fronts = {1, 1};
    vector<int> backs = {1, 2};

    int min = flipgame(fronts, backs);
    cout << min << endl;
}

