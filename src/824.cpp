#include <iostream>
#include <sstream>

using namespace std;

string toGoatLatin(string S)
{
    stringstream ss(S);
    string tmp;
    string result;
    ss >> tmp;
    if (tmp[0] == 'a' || tmp[0] == 'A' ||
        tmp[0] == 'e' || tmp[0] == 'E'    ||
        tmp[0] == 'i' || tmp[0] == 'I'    ||
        tmp[0] == 'o' || tmp[0] == 'O'    ||
        tmp[0] == 'u' || tmp[0] == 'U')
    {
        tmp.append("ma");
    }
    else
    {
        string first = tmp.substr(0, 1);
        tmp.erase(0, 1);
        tmp.append(first);
    }

    result += tmp + "a";

    int index = 2;

    while (ss >> tmp)
    {
        if (tmp[0] == 'a' || tmp[0] == 'A' ||
            tmp[0] == 'e' || tmp[0] == 'E'    ||
            tmp[0] == 'i' || tmp[0] == 'I'    ||
            tmp[0] == 'o' || tmp[0] == 'O'    ||
            tmp[0] == 'u' || tmp[0] == 'U')
        {
            tmp.append("ma");
        }
        else
        {
            string first = tmp.substr(0, 1);
            tmp.erase(0, 1);
            tmp.append(first + "ma");
        }

        result += (" " + tmp + string(index, 'a'));
        index++;
    }

    return result;
}

int main()
{
    string str = "I speak Goat Latin";
    string str2 = "a b c";
    cout << toGoatLatin(str2);
}
