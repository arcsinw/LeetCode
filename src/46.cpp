#include <iostream>
#include <vector>
#include "vector_helper.h"

using namespace std;

vector<vector<int>> permute(vector<int>& nums)
{
    VectorHelper::printVector(nums);
    vector<vector<int>> result;



    return result;
}

int main()
{
    vector<int> input {1, 2, 3};
    auto output = permute(input);
    VectorHelper::printVector(output);
}
