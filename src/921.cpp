#include <iostream>
#include <string>

using namespace std;

int minAddToMakeValid(string S)
{
    int left_count = 0;
    int total = 0;

    for(char c : S)
    {
        if (c == '(')
        {
            ++left_count;
            ++total;
        }
        else
        {
            if (left_count > 0)
            {
                --left_count;
                --total;
            }
            else
            {
                ++total;
            }
        }
        cout << c << endl;
    }

    return total;
}

int main()
{
    string input1 = "())";
    string input2 = "(((";
    string input3 = "()";
    string input4 = "()))((";

    cout << minAddToMakeValid(input1) << " Expected: 1" << endl;
    cout << minAddToMakeValid(input2) << " Expected: 3" << endl;
    cout << minAddToMakeValid(input3) << " Expected: 0" << endl;
    cout << minAddToMakeValid(input4) << " Expected: 4" << endl;
}
