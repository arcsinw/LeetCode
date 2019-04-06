#include <iostream>
#include <vector>
#include "vector_helper.h"

using namespace std;

bool checkPossibility(vector<int> &nums)
{
    int last = -100000;
    bool state = false;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= last)
        {
            last = nums[i];
        }
        else
        {
            if (state)
                return false;

            if (i == 1 || nums[i] >= nums[i - 2])
            {
                last = nums[i];
            }

            state = true;
        }
    }

    return true;
}

int main()
{
    vector<int> input1 = {4, 2, 3};
    vector<int> input2 = {4, 2, 1};
    vector<int> input3 = {3, 4, 2, 3};
    vector<int> input4 = {1};
    vector<int> input5 = {2, 3, 3, 2, 4};
    vector<int> input6 = {1, 3, 2};
    vector<int> input7 = {1, 2, 4, 5, 3};
    vector<int> input8 = {-100, -99, -98, -97, -96, -95, -94, -93, -92, -91, -90, -89, -88, -87, -86, -85, -84, -83, -82, -81, -80, -79, -78, -77, -76, -75, -74, -73, -72, -71, -70, -69, -68, -67, -66, -65, -64, -63, -62, -61, -60, -59, -58, -57, -56, -55, -54, -53, -52, -51, -50, -49, -48, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38, -37, -36, -35, -34, -33, -32, -31, -30, -29, -28, -27, -26, -25, -24, -23, -22, -21, -20, -19, -18, -17, -16, -15, -14, -13, -12, -11, -10, -9, -8, 11, 17, -7, 1, -2, 14, -3, -1, -5, 4, 6, 18, -4, 8, 16, 5, 12, 10, 7, 0, -6, 15, 2, 9, 19, 3, 13, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
    cout << "Ouput1: " << checkPossibility(input1) << " Expected: True" << endl;
    cout << "Ouput2: " << checkPossibility(input2) << " Expected: False" << endl;
    cout << "Ouput3: " << checkPossibility(input3) << " Expected: False" << endl;
    cout << "Ouput4: " << checkPossibility(input4) << " Expected: True" << endl;
    cout << "Ouput5: " << checkPossibility(input5) << " Expected: True" << endl;
    cout << "Ouput6: " << checkPossibility(input6) << " Expected: True" << endl;
    cout << "Ouput7: " << checkPossibility(input7) << " Expected: True" << endl;
    cout << "Ouput8: " << checkPossibility(input8) << " Expected: True" << endl;
}
