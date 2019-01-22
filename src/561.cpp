#include <iostream>
#include <vector>
#include <algorithm>
#include "vector_helper.h"

using namespace std;

int arrayPairSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    VectorHelper::printVector(nums);

    int sum = 0;

    for(int i = 0; i < nums.size(); i+=2)
    {
        sum += nums[i];
        cout << nums[i] << endl;
    }

    cout << "sum: " << sum << endl;
    return sum;
}

//int arrayPairSum(vector<int>& nums)
//{
//    int f[20001] = {};
//    for (int i = 0; i < nums.size(); ++i) ++f[10000 + nums[i]];
//
//    int sum = 0;
//    int c = 0;
//    for (int i = 0; c < nums.size() - 1; ++i) {
//        int k = (f[i] + 1 - (c & 0x01)) >> 1;
//        sum += (i - 10000)*k;
//        c += f[i];
//
//        if (i >= 9999)
//        {
//            cout << "i: " << i << " k: " << k << " sum: " << sum << " c: " << c << " f[i]: " << f[i] << endl;
//        }
//    }
//
//    return sum;
//}

int main()
{
    vector<int> input = {1, 2, 3, 11};
    int sum = arrayPairSum(input);
    cout << "sum: " << sum << endl;

}
