#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<int> &vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

vector<int> numberOfLines(vector<int>& widths, string S)
{
    int line_count = 1, width = 0;
    for (char c : S)
    {
        int tmp = widths.at(c - 'a');
        if (width + tmp <= 100)
        {
            width += tmp;
        }
        else
        {
            ++line_count;
            width = tmp;
        }
    }

    return {line_count, width};
}

int main()
{
    string str = "abcdefghijklmnopqrstuvwxyz";
    vector<int> widths(26, 10);
    vector<int> result = numberOfLines(widths, str);
    printVector(result);

    string str2 = "bbbcccdddaaa";
    widths.at(0) = 4;
    result = numberOfLines(widths, str2);
    printVector(result);
}
