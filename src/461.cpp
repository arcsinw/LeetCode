#include <iostream>
#include <bitset>

using namespace std;

int indexOfOne(int x)
{
    auto r = x & (-x);
    cout << bitset<32>(r) << endl;

    const uint64_t deBruijn = 0x022fdd63cc95386d;
    const unsigned int convert[64] =
        { 0, 1, 2, 53, 3, 7, 54, 27,
        4, 38, 41, 8, 34, 55, 48, 28,
        62, 5, 39, 46, 44, 42, 22, 9,
        24, 35, 59, 56, 49, 18, 29, 11,
        63, 52, 6, 26, 37, 40, 33, 47,
        61, 45, 43, 21, 23, 58, 17, 10,
        51, 25, 36, 32, 60, 20, 57, 16,
        50, 31, 19, 15, 30, 14, 13, 12};

    r = convert[(r * deBruijn) >> 58];
    return r;
}

//int hammingDistance(int x, int y)
//{
//    cout << "x: " << bitset<32>(x) << endl;
//    cout << "y: " << bitset<32>(y) << endl;
//    int r = x ^ y;
//    cout << "r = x ^ y: " << bitset<32>(r) << endl;
//    int index_1 = indexOfOne(r);
//    cout << index_1 << endl;
//    r = r >> (index_1 + 1);
//    int index_2 = indexOfOne(r);
//    cout << index_2 << endl;
//
//    return index_2 + 1;
//}

int hammingDistance(int x, int y)
{
    int r = x ^ y;
    int count = 0;
    cout << "r: " << bitset<32>(r) << endl;
    while (r != 0)
    {
        if (r & 1 == 1)
        {
            ++count;
        }
        r = r >> 1;
    }

    return count;
}

int main()
{
    //cout << hammingDistance(1, 4);
    cout << hammingDistance(4, 2) << "expected: 2" << endl;;
}
