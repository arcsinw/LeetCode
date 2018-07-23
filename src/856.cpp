#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void printVector(vector<char> &vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

void printStack(stack<char> &myStack)
{
    vector<char> vec;
    string a;
    while (!myStack.empty())
    {
        vec.push_back(myStack.top());
        myStack.pop();
    }

    for(vector<char>::reverse_iterator iter = vec.rbegin(); iter != vec.rend(); iter++)
    {
        a += (*iter);
        myStack.push(*iter);
    }

    cout << a << endl;
}

int scoreOfParentheses(string S)
{
    cout << S << endl;
    stack<char> myStack;
    int score = 0;

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '(')
        {
            myStack.push('(');
        }
        else if (S[i] == ')') //和'('一起弹出栈
        {

        }

        printStack(myStack);
    }

    return score;
}

int main()
{
    string str = "(()(()))";
    cout << scoreOfParentheses(str) << " expected: 6" << endl;;
    cout << scoreOfParentheses("()") << " expected: 1" << endl;
    cout << scoreOfParentheses("(())") << " expected: 2" << endl;;
    cout << scoreOfParentheses("()()") << " expected: 2" << endl;
}
