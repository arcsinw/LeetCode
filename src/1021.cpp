#include <iostream>
#include <string>

using namespace std;

string removeOuterParentheses(string S)
{
    string result;
    int left = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '(')
        {
            if (left++ != 0)
            {
                result += '(';
            }
        }
        else if (S[i] == ')')
        {
            if (--left != 0)
            {
                result += ')';
            }
        }
    }

    return result;
}

void assert(string input, string actual, string expected)
{
    cout << "Input: " << input << " Output: " << actual << " Expected: " << expected << endl;
}

int main()
{
    string input1 = "(()())(())";
    string expected1 = "()()()";

    string input2 = "(()())(())(()(()))";
    string expected2 = "()()()()(())";

    string input3 = "()()";
    string expected3 = "";

//    string input4 = "";
//    string expected4 = "";

    assert(input1, removeOuterParentheses(input1), expected1);
    assert(input2, removeOuterParentheses(input2), expected2);
    assert(input3, removeOuterParentheses(input3), expected3);
}
