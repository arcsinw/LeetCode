#include <vector>
#include <iostream>

using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix.at(0).size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
             if (i == 0 || j == 0)
             {
                 cout << matrix.at(i).at(j) << " " ;
             }
        }
        cout << endl;
    }
}

int main()
{
    int a[4] = {1,2,3,4};
    int b[4] = {5,1,2,3};
    int c[4] = {9,5,1,2};
    vector<int> vec1(a, a+4);
    vector<int> vec2(b, b+4);
    vector<int> vec3(c, c+4);
    vector<vector<int>> matrix;
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);

    isToeplitzMatrix(matrix);
}
