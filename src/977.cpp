#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& A)
{
    for(int i = 0; i < A.size(); i++)
    {
        A[i] = abs(A[i]);
        cout << A[i] << endl;
    }
    cout << "After sort" << endl;

    sort(A.begin(), A.end());

    for(int i = 0; i < A.size(); i++)
    {
        A[i] = A[i] * A[i] ;
        cout << A[i] << endl;
    }
    return A;
}

int main()
{
    vector<int> input = {-4, -1, 0, 3, 10};
    sortedSquares(input);
}
