#include <vector>
#include <iostream>
#include <algorithm>
#include "vector_helper.h"

using namespace std;

// sort and return the middle element
//int majorityElement(vector<int>& nums)
//{
//    sort(nums.begin(), nums.end());
//    VectorHelper::printVector(nums);
//    cout << nums.size() / 2 << endl;
//    return nums[nums.size() / 2];
//}

// count and return element appear more than nums.size() / 2
//int majorityElement(vector<int>& nums)
//{
//    unordered_map<int, int> map;
//
//    for(int a : nums)
//    {
//        if (++map[a] > (nums.size() / 2))
//        {
//            return a;
//        }
//    }
//
//    return -1;
//}

// remove two elements if they are not equal
int majorityElement(vector<int>& nums)
{
    stack<int> tony;

    for(int a : nums)
    {
        if (tony.empty() || a == tony.top())
        {
            tony.push(a);
        }
        else
        {
            tony.pop();
        }
    }

    return tony.top();
}

int main()
{
    vector<int> input1 = {3, 2, 3};
    vector<int> input2 = {2, 2, 1, 1, 1, 2, 2, 3};

    cout << "output1: " <<  majorityElement(input1) << " expected: 3" << endl;
    cout << "output2: " <<  majorityElement(input2) << " expected: 2" << endl;
}
