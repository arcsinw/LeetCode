#include <iostream>
#include <string>
#include "vector_helper.h"

using namespace std;

vector<string> letterCombinations(string digits)
{
    vector<string> dic = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for(char c : digits)
    {
        cout << dic[c - '1'] << endl;
    }
}

int main()
{
    string input = "23";
    vector<string> output = letterCombinations(input);
    VectorHelper::printVector(output);
}
