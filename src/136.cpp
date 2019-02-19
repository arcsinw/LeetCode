#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        result = result ^ nums[i];
    }
    return result;
}

int main()
{
    vector<int> input = {2, 2, 1};
    int output = singleNumber(input);
    cout << "output : " << output << " expected: 1" << endl;

    vector<int> input2 = {4, 1, 2, 1, 2};
    int output2 = singleNumber(input2);
    cout << "output : " << output2 << " expected: 4" << endl;
}
