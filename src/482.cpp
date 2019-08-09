#include <string>
#include <iostream>
#include "assert_helper.h"

using namespace std;

char toupper(char c) {
    return ('a' <= c && c <= 'z') ? c^0x20 : c;
}

string licenseKeyFormatting(string S, int K) {
    int len = 0;
    int s_len = S.size();
    int *tag = new int[s_len]{0};

    for (int i = 0; i < s_len; i++)
    {
        if (S[i] == '-')
            continue;

        S[i] = toupper(S[i]);
        len++;
        tag[i] = 1;
    }

    len += (len - 1) / K;
    string result(len, '-');
    int pivot = len - 1;
    int tmp = 0;

    for (int j = s_len - 1; j >= 0; j--)
    {
        if (tag[j] == 1)
        {
            if (tmp++ == K)
            {
                pivot--;
                tmp = 1;
            }

            result[pivot--] = S[j];
        }
    }

    return result;
}

int main()
{
    string input1 = "5F3Z-2e-9-w";
    int k1 = 4;
    string expected1 = "5F3Z-2E9W";

    string input2 = "2-5g-3-J";
    int k2 = 2;
    string expected2 = "2-5G-3J";

    AssertHelper<string>::assert(input1, licenseKeyFormatting(input1, k1), expected1);
    AssertHelper<string>::assert(input2, licenseKeyFormatting(input2, k2), expected2);
}
