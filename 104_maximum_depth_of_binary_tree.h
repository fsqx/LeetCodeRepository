#pragma once
#include <algorithm>
#include <numeric>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;
class Solution {
public:

    int maxDepth(TreeNode *root)
    {
        int m = 1;

        if(root == nullptr)
        {
            return 0;
        }

        int l = max(maxDepth(root->left, m + 1), m);
        int r = max(maxDepth(root->right, m + 1), m);
        return max(l, r);
    }

    int maxDepth(TreeNode *root, int m)
    {
        if(root == nullptr)
        {
            return m - 1;
        }

        int l = max(maxDepth(root->left, m + 1), m);
        int r = max(maxDepth(root->right, m + 1), m);
        return max(l, r);
    }

};