#ifndef VECTOR_HELPER_H
#define VECTOR_HELPER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class VectorHelper
{
    public:
        VectorHelper();

        static void readVector(string file_path, vector< vector<int> > &matrix);
        static void printVector(vector<int> &vec);
        static void printVector(vector< vector<int> > &matrix);
    protected:

    private:
};

#endif // VECTOR_HELPER_H
