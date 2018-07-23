#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int uniqueMorseRepresentations(vector<string>& words)
{
    string dic[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> morse_codes;

    for(vector<string>::iterator iter = words.begin(); iter < words.end(); iter++)
    {
        string tmp = "";
        for (int i = 0; i < (*iter).length(); i++)
        {
            int index = (int)((*iter).at(i) - 'a');
            tmp.append(dic[index]);
        }
        morse_codes.insert(tmp);
    }

    return morse_codes.size();

//    sort(morse_codes.begin(), morse_codes.end());
//
//    morse_codes.erase(unique(morse_codes.begin(), morse_codes.end()), morse_codes.end());
//
//    for(vector<string>::iterator iter = morse_codes.begin(); iter < morse_codes.end(); iter++)
//    {
//        cout << (*iter) << endl;
//    }
//
//    return morse_codes.size();
}

int main()
{
    vector<string> words;
    words.push_back("gin");
    words.push_back("zen");
    words.push_back("gig");
    words.push_back("msg");

    return uniqueMorseRepresentations(words);
}
