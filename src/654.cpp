#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "vector_helper.h"

using namespace std;

void printVector(vector<int> &vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

void maxOfVector(vector<int> vec)
{
    if (vec.empty())
    {
        return;
    }

    auto max_iter = max_element(vec.begin(), vec.end());
    cout << *max_iter << endl;

    vector<int> left_vec(vec.begin(), max_iter);
    vector<int> right_vec(max_iter + 1, vec.end());

    printVector(left_vec);
    printVector(right_vec);

    maxOfVector(left_vec);
    maxOfVector(right_vec);
}

int main()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(0);
    vec.push_back(5);

    maxOfVector(vec);
}
