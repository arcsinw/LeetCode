#include <iostream>
#include "vector_helper.h"
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A)
{
    int even = 0;
    int odd = A.size()-1;

    while (even < odd)
    {
        if (A[even] % 2 != 0)
        {
            swap(A[even], A[odd]);
            --odd;
        }
        else
        {
            ++even;
        }
    }

    return A;
}

int main()
{
    vector<int> input1 {0, 1, 3, 4};
    vector<int> input2 {1};

    auto output1 = sortArrayByParity(input1);
    auto output2 = sortArrayByParity(input2);

    VectorHelper::printVector(output1);
    VectorHelper::printVector(output2);
}
