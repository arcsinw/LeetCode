#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//int myAtoi(string str)
//{
//    int result = 0;
//    int MAX_INT = 2147483647;
//    int MIN_INT= -2147483648;
//
//    stringstream ss(str);
//
//    ss >> result;
//
//    return result;
//}

int myAtoi(string str)
{
    int result = 0;

    for (char c : str)
    {
        if (c == ' ' || '\0')
        {
            continue;
        }

        cout << c;
    }

    return result;
}

int main()
{
    cout << myAtoi("42") << " Expected: 42" << endl;
    cout << myAtoi("   -42") << " Expected: -42" << endl;
    cout << myAtoi("4193 with words") << " Expected: 4193" << endl;
    cout << myAtoi("words and 987") << " Expected: 0" << endl;
    cout << myAtoi("-91283472332") << " Expected: -2147483648" << endl;

    cout << myAtoi(" ") << " Expected: 0" << endl;
    cout << myAtoi("a") << " Expected: 0" << endl;
}
