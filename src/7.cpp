#include <iostream>
using namespace std;

bool willOverflow(int sum, int x)
{
    int MAX_P_INT = 2147483647;
    int MAX_N_INT= -2147483648;

    if ((sum > 0 && sum > (MAX_P_INT - x % 10) / 10) ||
        (sum < 0 && sum < (MAX_N_INT - x % 10) / 10))
    {
        return true;
    }

    return false;
}

int reverse(int x)
{
    int sum = 0;

    while (x)
    {
        //cout << "sum " << sum << " MAX_N_INT / 10: " << MAX_N_INT / 10 << endl;
        if (willOverflow(sum, x))
        {
            return 0;
        }
        sum = sum * 10 + x % 10;
        x /= 10;
    }

    return sum;
}

int main()
{
    cout << reverse(123) << " Expected: 321" << endl;
    cout << reverse(-123) << " Expected: -321" << endl;
    cout << reverse(-2147483412) << " Expected: -2143847412" << endl;
}
