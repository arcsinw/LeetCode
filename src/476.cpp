#include <iostream>
#include <bitset>
#include <bits/stdc++.h>

using namespace std;

//int findComplement(int num)
//{
//    cout << bitset<32>(-1) << endl;
//    cout << bitset<32>(num) << endl;
//    cout << bitset<32>(-1 ^ num) << endl;
//
//    int sum = 0;
//    int tmp = 1;
//    while (sum < num)
//    {
//        sum += tmp;
//        tmp = 2 * tmp;
//    }
//
//    cout << sum << endl;
//    return sum - num;
//}

int findComplement(int num)
{
    int toggled = num;
    cout << num << endl;
    int topBit = static_cast<int>(log2(num));
    cout << log2(num) << endl;
    cout << "topBit: " << bitset<32>(topBit) << endl;

    for (int iBit = 0; iBit <=topBit; iBit++) {
        toggled ^= (1 << iBit);
        cout << "toggled: " << bitset<32>(toggled) << endl;
        cout << "iBit: " << bitset<32> (1 << iBit) << endl;
        cout << endl;
    }

    return toggled;
}

int main()
{
    int input = 5;
    int input2 = 1;

    cout << findComplement(input) << " Expected: 2" << endl;
    cout << findComplement(input2) << " Expected: 0" << endl;
}
