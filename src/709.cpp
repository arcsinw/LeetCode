#include <iostream>
#include <string>

using namespace std;

//A 65
//a 97
string toLowerCase(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if ( 'A' <= str[i] && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');
            //str[i] = str[i] + 32;
            //str[i] = str[i] | 32; //32的二进制是0010 0000, str[i] | 32是把str[i]代表32的那个二进制位变成1，那个位如果原来为0和32与运算相当于+32
        }
    }
    return str;
}

int main()
{
    string tmp = toLowerCase("Hello world!");
    cout << tmp << endl;
    return 0;
}
