#include <iostream>
#include <vector>
#include "vector_helper.h"

using namespace std;

int binarySearch(vector<int>& vec, int low, int high, int target)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        cout << "low: " << low << " high: " << high << " mid: " << mid << endl;

        if (vec[mid] == target)
        {
            return mid;
        }
        else if (vec[mid] > target)
        {
            high = mid-1;
        }
        else if (vec[mid] < target)
        {
            low = mid + 1;
        }
    }

    return -1;
}

//vector<int> twoSum(vector<int>& numbers, int target)
//{
//    for (int i = 0; i < numbers.size()-1; i++)
//    {
//        int rest = target - numbers[i];
//
//        int index = binarySearch(numbers, i+1, numbers.size(), rest);
//        if (index != -1)
//        {
//            return vector<int> {i, index};
//        }
//    }
//}

vector<int> twoSum(vector<int>& numbers, int target)
{
    vector<int> result;
    int low = 0;
    int high = numbers.size() - 1;

    while (low <= high)
    {
        int sum = numbers[low] + numbers[high];
        if (sum == target)
        {
            return vector<int> {low + 1, high + 1};
        }
        else if (sum > target)
        {
            high--;
        }
        else if (sum < target)
        {
            low++;
        }
    }
}

int main()
{
    //vector<int> input{2, 7, 11, 15};

    vector<int> input{0, 0, 3, 4};

    VectorHelper::printVector(input);

    auto result = twoSum(input, 0);

    VectorHelper::printVector(result);
}
