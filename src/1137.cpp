#include <iostream>
#include <vector>

using namespace std;

int tribonacci(int n)
{
    vector<int> list(38);
    list[0] = 0;
    list[1] = 1;
    list[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        list[i] = list[i-3] + list[i-2] + list[i-1];
    }

    return list[n];
}

int main()
{
    cout << tribonacci(4) << " expected: " << 4 << endl;
    cout << tribonacci(25) << " expected: " << 1389537 << endl;
}
