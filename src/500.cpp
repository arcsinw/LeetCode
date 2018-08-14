#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(string word)
{
    int dic[26] = {1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2};
    int row = word[0] >= 'a' ? dic[word[0] - 'a'] : dic[word[0] - 'A'];

    for (int j = 1; j < word.size(); j++)
    {
        int tmp = word[j] >= 'a' ? dic[word[j] - 'a'] : dic[word[j] - 'A'];
        if (tmp != row)
        {
            return false;
        }
    }

    return true;
}

vector<string> findWords(vector<string>& words)
{
    vector<string> result;

    for(int i = 0; i < words.size(); i++)
    {
        string str = words.at(i);

        if (isValid(str))
        {
            result.push_back(str);
        }
    }

    return result;
}

void printVector(vector<string> &vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    vector<string> input;
    input.push_back("adsdf");
    input.push_back("sfd");
    input.push_back("Aasdfghjkl");
    input.push_back("Qwertyuiop");
    input.push_back("zZxcvbnm");

    vector<string> output = findWords(input);
    printVector(output);
}
