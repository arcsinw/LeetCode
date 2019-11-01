#include <iostream>
#include <vector>
#include <numeric>
#include "vector_helper.h"

using namespace std;

//int sumRange(vector<int>& nums, int left, int right)
//{
//    int sum = 0;
//    for (int i = left; i < right; i++)
//    {
//        sum += nums[i];
//    }
//    return sum;
//}
//
//int pivotIndex(vector<int>& nums)
//{
//    int sum_left = 0;
//    int sum_right = 0;
//
//    for (int i = 0; i < nums.size(); i++)
//    {
//        sum_left = sumRange(nums, 0, i);
//        sum_right = sumRange(nums, i+1, nums.size());
//
//        if (sum_left == sum_right)
//        {
//            return i;
//        }
//    }
//
//    return -1;
//}

//int pivotIndex(vector<int>& nums)
//{
//    if (nums.size() == 0) return -1;
//    int sum_left = 0;
//    int sum_right = 0;
//
//    vector<int> sum;
//    sum.push_back(0);
//    sum.push_back(nums[0]);
//
//    for (int i = 1; i < nums.size(); i++)
//    {
//        sum.push_back(sum[i] + nums[i]);
//    }
//
//    for (int i = 0; i < nums.size(); i++)
//    {
//        sum_left = sum[i];
//        sum_right = sum[nums.size()] - sum[i+1];
//        if (sum_left == sum_right)
//        {
//            return i;
//        }
//    }
//
//    return -1;
//}

int pivotIndex(vector<int>& nums)
{
    int size = nums.size();
    int left_sum = 0;

    auto sum = std::accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < size; i++)
    {
        sum -= nums[i];
        if (left_sum == sum) {
            return i;
        }

        left_sum += nums[i];
    }

    return -1;
}

int main()
{
    vector<int> input1 = {1, 7, 3, 6, 5, 6};
    int result1 = pivotIndex(input1);
    cout << "result1: " << result1 << " Expected: 3" << endl;

    vector<int> input2 = {1, 2, 3};
    int result2 = pivotIndex(input2);
    cout << "result2: " << result2 << " Expected: -1" << endl;

    vector<int> input3 = {-1, -1, -1, -1, -1, 0};
    int result3 = pivotIndex(input3);
    cout << "result3: " << result3 << " Expected: 2" << endl;

    vector<int> input4 = {-1, 1, 0, 0};
    int result4 = pivotIndex(input4);
    cout << "result4: " << result4 << " Expected: 2" << endl;

    vector<int> input5 = {-1, -1, -1, 0, 1, 1};
    int result5 = pivotIndex(input5);
    cout << "result5: " << result5 << " Expected: 0" << endl;
}
