#include <iostream>

using namespace std;

TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if (root == NULL)
    {
        TreeNode* node = new TreeNode(val);
        return node;
    }

    if (val > root->val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    else
    {
        root->left = insertIntoBST(root->left, val);
    }
    return root;
}

int main()
{

}
