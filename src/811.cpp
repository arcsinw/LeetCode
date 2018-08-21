#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void printVector(vector<string> &vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        cout << vec.at(i) << " " << endl;
    }
    cout << endl;
}

void printMap(map<string,int> _map)
{
    for (map<string,int>::iterator iter = _map.begin(); iter != _map.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
}

void subDomain(string domain, int count, map<string,int> *_map)
{
//    vector<string> result;
//    result.push_back(domain);
    (*_map)[domain] += count;
    for(int i = 0; i < domain.size(); i++)
    {
        if (domain.at(i) == '.')
        {
            //cout << domain.substr(i+1) << " " << count << endl;
            (*_map)[domain.substr(i+1)] +=count;
            //result.push_back(domain.substr(i+1));
        }
    }
}

vector<string> subdomainVisits(vector<string>& cpdomains)
{
    map<string,int> _map;
    vector<string> result;
    int count;
    string domain;
    for(string str : cpdomains)
    {
        stringstream ss(str);

        ss >> count >> domain;
        subDomain(domain, count, &_map);

//        for (int j = 0; j < keys.size(); j++)
//        {
//            _map[keys.at(j)] += count;
//        }
    }

    for (map<string,int>::iterator iter = _map.begin(); iter != _map.end(); iter++)
    {
        result.push_back(to_string(iter->second) + " " + iter->first);
        //cout << iter->first << " : " << iter->second << endl;
    }

    //printMap(_map);
    return result;
}

int main()
{
    vector<string> input;
    input.push_back("900 google.mail.com");
    input.push_back("50 yahoo.com");
    input.push_back("1 intel.mail.com");
    input.push_back("5 wiki.org");

    vector<string> result = subdomainVisits(input);
    printVector(result);
}
