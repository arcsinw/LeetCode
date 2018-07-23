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
            str[i] = (char)(str[i] + ('a' - 'A'));
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
