#include <iostream>
#include <map>
#include <vector>

using namespace std;

int repeatedNTimes(vector<int>& A)
{
    map<int, int> _map;
    for(int val : A)
    {
        if (++_map[val] == 2)
        {
            return val;
        }
    }
    return 0;
}

int main()
{
    vector<int> input = {1, 2, 3, 3};
    cout << repeatedNTimes(input);
}
