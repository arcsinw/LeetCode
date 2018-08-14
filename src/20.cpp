#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> stk;
    for (char c : s)
    {
        if (stk.empty() || c == '(' || c == '[' || c == '{')
        {
            stk.push(c);
            continue;
        }

        char top = stk.top();
        if ((top == '(' && c == ')') ||
            (top == '[' && c == ']') ||
            (top == '{' && c == '}'))
        {
            stk.pop();
        }
        else
        {
            return false;
        }
    }

    return stk.empty();
}

int main()
{
    string input1 = "()";
    string input2 = "()[]{}";
    string input3 = "(]";

    cout << isValid(input1) << " Expected: 1" << endl;
    cout << isValid(input2) << " Expected: 1" << endl;
    cout << isValid(input3) << " Expected: 0" << endl;
    cout << isValid("([)]") << " Expected: 0" << endl;
    cout << isValid("{[]}") << " Expected: 1" << endl;
    cout << isValid("(])") << " Expected: 0" << endl;
    cout << isValid("(]") << " Expected: 0" << endl;
}
