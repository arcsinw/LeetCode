#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//int peakIndexInMountainArray(vector<int>& A)
//{
//    int i = 1;
//    while (i <= A.size())
//    {
//        if (A.at(i-1) > A.at(i))
//        {
//            return i-1;
//        }
//        ++i;
//    }
//}

//int peakIndexInMountainArray(vector<int>& A)
//{
//    for (int i = 1; i <= A.size(); i++)
//    {
//        if (A.at(i-1) > A.at(i))
//        {
//            return i-1;
//        }
//    }
//}

int peakIndexInMountainArray(vector<int>& A)
{
    vector<int>::iterator max_iter = max_element(A.begin(), A.end());
    return distance(A.begin(), max_iter);
}

int main()
{
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(0);

    cout << peakIndexInMountainArray(vec) << endl;

    vector<int> vec2;
    vec2.push_back(0);
    vec2.push_back(2);
    vec2.push_back(3);
    vec2.push_back(1);
    vec2.push_back(0);

    cout << peakIndexInMountainArray(vec2) << endl;
}
