#include <iostream>
#include "assert_helper.h"

using namespace std;

//string defangIPaddr(string address)
//{
//    for(int i = 0; i < address.size(); i++)
//    {
//        if (address[i] == '.')
//        {
//            address.replace(i, 1, "[.]");
//            i+=2;
//        }
//    }
//
//    cout << address << endl;
//    return address;
//}

string defangIPaddr(string address)
{
    string result;
    for(int i = 0; i < address.length(); i++)
    {
        if (address[i] == '.')
        {
            result += "[.]";
        }
        else
        {
            result += address[i];
        }
    }

    return result;
}

int main()
{
    string input1 = "1.1.1.1";
    AssertHelper<string>::assert(input1, defangIPaddr(input1), "1[.]1[.]1[.]1");
}
