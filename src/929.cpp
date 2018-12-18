#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include "vector_helper.h"


using namespace std;

int numUniqueEmails(vector<string>& emails)
{
    unordered_set<string> ss;

    for(auto &email : emails)
    {
        string address = "";
        size_t at_pos = email.find('@');
        string domain = email.substr(at_pos + 1, email.size());
        string localName = email.substr(0, at_pos);

        for(int j = 0; j < localName.size(); j++)
        {
            if (localName[j] == '+')
            {
                break;
            }

            if (localName[j] == '.')
            {
                continue;
            }

            address += localName[j];
        }

        cout << address + domain << endl;
        ss.insert(address + domain);
    }

    return ss.size();
}

int main()
{
    vector<string> inputs =
        {
            "test.email+alex@leetcode.com",
            "test.e.mail+bob.cathy@leetcode.com",
            "testemail+david@lee.tcode.com"
        };

    cout << numUniqueEmails(inputs) << " expected: 2" << endl;
}

