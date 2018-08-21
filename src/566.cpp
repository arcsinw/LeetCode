#include <vector>
#include <iostream>

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


vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
{
    int row = nums.size();
    int col = nums.at(0).size();

    if (row * col != r * c)
    {
        return nums;
    }

    vector<vector<int>> result (r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int row_tmp = (i * c + j) / col;
            int col_tmp = (i * c + j) % col;
            result[i][j] = nums[row_tmp][col_tmp];
        }
    }

    return result;
}


int main()
{
    vector<vector<int>> input;

    int a[2] = {1,2};
    int b[2] = {3,4};
    int c[2] = {5,6};

    vector<int> vec1(a, a+2);
    vector<int> vec2(b, b+2);
    vector<int> vec3(c, c+2);

    input.push_back(vec1);
    input.push_back(vec2);
    input.push_back(vec3);

    vector<vector<int>> result = matrixReshape(input, 2, 3);

    printVector(result);
}
