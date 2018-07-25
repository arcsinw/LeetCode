#include <iostream>
#include <string>

using namespace std;

bool detectCapitalUse(string word)
{
    bool allUpper = true;
    bool allLower = true;
    bool firstUpper = false;

    if (word[0] >= 'A' && word[0] <= 'Z')
    {
        firstUpper = true;
    }

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            allUpper = allUpper && 1;
            allLower = allLower && 0;
            if (i != 0)
            {
                firstUpper = firstUpper && 0;
            }
        }
        else
        {
            allUpper = allUpper && 0;
            allLower = allLower && 1;
            firstUpper = firstUpper && 1;
        }
    }

    return allUpper || allLower || firstUpper;
}

int main()
{
    string str1 = "USA";
    string str2 = "FlaG";
    string str3 = "leetcode";
    string str4 = "Flag";

    cout << detectCapitalUse(str1) << endl;
    cout << detectCapitalUse(str2) << endl;
    cout << detectCapitalUse(str3) << endl;
    cout << detectCapitalUse(str4) << endl;
}
