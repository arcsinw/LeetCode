#include <iostream>

using namespace std;

int binaryGap(int N)
{
    int max = 0;
    int cur = -1, distance = 0;

    while (N != 0)
    {
        if (N & 1 == 1)
        {
            //第一次遇到1
            if (cur == -1)
            {
                cur = 1;
            }
            else
            {
                max = cur > max ? cur : max;
                cur = 1;
            }
        }
        else
        {
            if (cur != -1)
            {
                ++cur;
            }
        }

        N = N >> 1;
    }

    return max;
}

int main()
{
    cout << binaryGap(8) << " Expected: 0" << endl;
    cout << binaryGap(22) << " Expected: 2" << endl;
    cout << binaryGap(5) << " Expected: 2" << endl;
    cout << binaryGap(6) << " Expected: 1" << endl;
}
