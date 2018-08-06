#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

bool isSelfDividing(int num)
{
    if (num < 10)
    {
        return true;
    }

    for (int i = num; i != 0; i /= 10)
    {
        if (i % 10 == 0)
        {
            return false;
        }
        if (num % (i%10) != 0)
        {
            return false;
        }
    }

    return true;
}

vector<int> selfDividingNumbers(int left, int right)
{
    vector<int> result;

    for (int i = left; i <= right; i++)
    {
        if (isSelfDividing(i))
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    vector<int> result = selfDividingNumbers(1, 22);
    printVector(result);
}
