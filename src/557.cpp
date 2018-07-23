#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string reverseWords(string str)
{
    string str_reverse;

    stringstream ss(str);
    string tmp;
    ss >> tmp;

    reverse(tmp.begin(), tmp.end());
    str_reverse.append(tmp);

    while (ss >> tmp)
    {
        reverse(tmp.begin(), tmp.end());
        str_reverse.append(" " + tmp);
    }

    return str_reverse;
}

int main()
{
    string str = "Let's take LeetCode contest";
    cout << reverseWords(str) << endl;
}
