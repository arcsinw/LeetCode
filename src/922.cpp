#include <iostream>
#include "vector_helper.h"

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A)
{
    int even = 0; // first even position with a odd
    int odd = 1;  // first odd position with a even

    while ((even < A.size() - 1) && odd < A.size())
    {
        while ((A[even] % 2 == 0) && (even < A.size() - 1))
        {
            even += 2;
        }

        cout << "1 even: " << even << " odd: " << odd << endl;

        if (even >= A.size() - 1)
        {
            break;
        }

        while ((A[odd] % 2 != 0) && (odd < A.size()))
        {
            odd += 2;
        }

        cout << "2 even: " << even << " odd: " << odd << endl;

        if (odd >= A.size())
        {
            break;
        }

        int tmp = A[even];
        A[even] = A[odd];
        A[odd] = tmp;

        cout << "3 even: " << even << " odd: " << odd << endl;
    }
    return A;
}

int main()
{
    vector<int> input = {1,2,4,3};
    vector<int> output = sortArrayByParityII(input);
    VectorHelper::printVector(output);
}
