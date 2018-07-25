#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

int binarySearch(vector<int> nums, int low, int high, int target)
{
    sort(nums.begin(), nums.end());

    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (target == nums.at(middle))
        {
            return middle;
        }
        else if (target > nums.at(middle))
        {
            low = middle + 1;
        }
        else if (target < nums.at(middle))
        {
            high = middle - 1;
        }
    }

    return -1;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    map<int, int> num_map;

    for (int i = 0; i < nums.size(); i++)
    {
        int rest = target - nums.at(i);
        if (num_map.find(rest) != num_map.end())
        {
            result.push_back(i);
            result.push_back(num_map.at(rest));
        }
        else
        {
            num_map[nums.at(i)] = i;
        }
    }

    printVector(result);

    return result;
}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);

    twoSum(nums, 6);
}
