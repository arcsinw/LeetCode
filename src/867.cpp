#include <iostream>
#include <vector>

using namespace std;


void printVector(vector< vector<int> > &matrix)
{
    for (vector< vector<int> >::iterator matrix_iter = matrix.begin();
        matrix_iter != matrix.end(); matrix_iter++)
        {
            for (vector<int>::iterator row_iter = (*matrix_iter).begin();
                row_iter != (*matrix_iter).end(); row_iter++)
                {
                    cout << (*row_iter) << " ";
                }
                cout << endl;
        }
    cout << endl;
}

vector<vector<int>> transpose(vector<vector<int>>& A)
{
    int shape = A.at(0).size();

    cout << "Shape: " << shape << endl;

    for (int i = 0; i < shape; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int tmp = A.at(i).at(j);
            A.at(i).at(j) = A.at(j).at(i);
            A.at(j).at(i) = tmp;
        }
    }

    return A;
}

int main()
{
    vector<vector<int>> vec;

    int a[3] = {1, 2, 3};
    vector<int> vec1(a, a+3);

    int b[3] = {4, 5, 6};
    vector<int> vec2(b, b+3);

    int c[3] = {7, 8, 9};
    vector<int> vec3(c, c+3);

    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);

    printVector(vec);

    transpose(vec);

    printVector(vec);
}
