#include <iostream>

//int maxDepth(TreeNode* root) {
//    if (!root) return 0;
//
//    queue<TreeNode*> que;
//    que.push(root);
//
//    int depth = 0;
//    while (!que.empty())
//    {
//        int layer_count = que.size();
//        for (int i = 0; i < layer_count; ++i)
//        {
//            TreeNode* tmp = que.front();
//            que.pop();
//
//            if (tmp->left) { que.push(tmp->left); }
//            if (tmp->right) { que.push(tmp->right); }
//        }
//
//        ++depth;
//    }
//
//    return depth;
//}

int maxDepth(TreeNode* root)
{
    if(root==NULL){return 0;}
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{

}
