#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int mid = (left + right) / 2;

    while (left <= right)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }

    return -1;
}

int main()
{
    vector<int> input1 = {-1,0,3,5,9,12};
    int target1 = 9;
    cout << search(input1, target1) << " expected: 4" << endl;

    int target2 = 2;
    cout << search(input1, target2) << " expected: -1" << endl;

    vector<int> input2 = {5};
    int target3 = 5;
    cout << search(input2, target3) << " expected: 0" << endl;

    int target4 = 1;
    cout << search(input2, target4) << " expected: -1" << endl;
}
