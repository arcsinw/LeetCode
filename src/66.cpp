#include <iostream>
#include <vector>
#include "vector_helper.h"

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    for(int i = digits.size() - 1; i >= 0; i --)
    {
        digits[i] ++;
        if(digits[i] < 10)
            break;
        digits[i] = 0;
    }
    if(digits[0] == 0){
        digits[0] = 1;
        digits.push_back(0);
    }
    return digits;
}

int main()
{
    int a[3] = {1,2,3};
    vector<int> input(a, a+3);

    auto result = plusOne(input);
    VectorHelper::printVector(result);
}
