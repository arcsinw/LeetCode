#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
//#include "vector_helper.h"

using namespace std;

void readVector(string file_path, vector< vector<int> > &matrix)
{
    //./data.txt
    ifstream file(file_path);
    if (!file)
    {
        cout << "Unable to open file";
    }

    string line;
    int tmp;
    while (!getline(file, line).eof())
    {
        istringstream line_stream(line);
        vector<int> tmp_line;
        tmp_line.clear();
        while (!line_stream.eof())
        {
            line_stream >> tmp;
            tmp_line.push_back(tmp);
        }
        matrix.push_back(tmp_line);
    }
}

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


vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
{
    vector<vector<int>> result;
    for (vector<vector<int>>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        vector<int> line;
        for (vector<int>::reverse_iterator inner_iter = iter->rbegin(); inner_iter != iter->rend(); inner_iter++)
        {
            int a = (*inner_iter);
            line.push_back((a == 0)? 1 : 0);
        }
        result.push_back(line);
        cout << endl;
    }
    return result;
}

int main()
{
    vector<vector<int>> input;

    readVector("./data.txt", input);
    printVector(input);

    input = flipAndInvertImage(input);

    cout << endl;

    printVector(input);

}

