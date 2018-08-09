#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
{
    for (vector<vector<int>>::iterator iter = graph.begin(); iter != graph.end(); iter++)
    {
        for (vector<int>::iterator inner_iter = (*iter).begin(); inner_iter != (*iter).end(); inner_iter++)
        {
            cout << *inner_iter;
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> vec;
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);

    vector<int> vec2;
    vec2.push_back(3);

    vector<int> vec3;
    vec3.push_back(3);

    vector<int> vec4;

    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);

    allPathsSourceTarget(vec);
}
