#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void printVector(vector<int> &vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

//int removeElement(vector<int>& nums, int val)
//{
//    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
//
//    printVector(nums);
//
//    return nums.size();
//}

//int removeElement(vector<int>& nums, int val)
//{
//     j 记录最后一个val
//    int i = 0, j = nums.size()-1;
//
//    while (i <= j)
//    {
//        if (nums[j] == val)
//        {
//            --j;
//        }
//        else
//        {
//            swap (nums[i], nums[j]);
//            ++i;
//        }
//    }
//
//    printVector(nums);
//
//    return j + 1;
//}

int removeElement(vector<int>& nums, int val)
{
    int len = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[len++] = nums[i];
        }
    }

    return len;
}

int main()
{
    int a[1] = {1};
    vector<int> input(a, a+1);

    printVector(input);

    cout << removeElement(input, 1);
}
