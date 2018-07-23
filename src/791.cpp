#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(int arr[])
{
    cout << "ARRAY" << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << char('a' + i) << " " << arr[i] << endl;
    }
}

void printVector(vector<char> vec)
{
    cout << "Vector" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << char('a' + i) << " " << vec.at(i) <<endl;
    }
}

string customSortString(string S, string T)
{
    string result;

    int div[26] = {0};
    char chars[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < T.length(); i++)
    {
        int index = T[i] - 'a';
        div[index]++;
    }

    printArray(div);

    for (int j = 0; j < S.length(); j++)
    {
        int index = S[j] - 'a';

        for (int k = 0; k < div[index]; div[index]--)
        {
            result += chars[index];
        }
    }

    printArray(div);

    for (int m = 0; m < 26; m++)
    {
        for (int n = 0; n < div[m]; n++)
        {
            result += chars[m];
        }
    }

    return result;
}

//string customSortString(string S, string T) {
//        vector<char> c2C(26, ' '); //¥ÊÀ≥–Ú
//        vector<char> A2a(26, ' '); //¥Ê÷µ
//        char C = 'A';
//        // c2C
//        for (auto c : S) {
//            c2C[c-'a'] = C;
//            A2a[C-'A'] = c;
//            C++;
//        }
//
//        printVector(c2C);
//        printVector(A2a);
//
//        string sT = "";
//        for (auto c : T) {
//            if (c2C[c-'a'] != ' ') {
//                sT += c2C[c -'a'];
//            } else {
//                sT += c;
//            }
//        }
//
//        cout << sT << endl;
//
//        std::sort(sT.begin(), sT.end());
//        cout << sT << endl;
//        string res;
//        for (auto C : sT) {
//            if (C >= 'A' && C <= 'Z' && A2a[C-'A'] != ' ') {
//                res += A2a[C-'A'];
//            } else {
//                res += C;
//            }
//
//        }
//        return res;
//    }

int main()
{
    string S = "kqep", T = "rpekeq";
    cout << customSortString(S, T);
}
