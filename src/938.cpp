#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include "vector_helper.h"


using namespace std;

int rangeSumBST(TreeNode* root, int L, int R) {
    if (root == NULL) return 0;
    int sum = 0;

    inOrder(root, L, R, sum);
    return sum;
}

void inOrder(TreeNode* root, int L, int R, int& sum)
{
    if (root == NULL) {return;}

    inOrder(root->left, L, R, sum);

    if (root-> val >= L && root->val <= R)
    {
        sum += root->val;
    }

    inOrder(root->right, L, R, sum);
}

