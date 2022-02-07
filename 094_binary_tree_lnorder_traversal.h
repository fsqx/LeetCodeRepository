#pragma once
#include <vector>

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

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if(root == nullptr)
        {
            return vector<int>();
        }

        vector<int> leftV = inorderTraversal(root->left);
        vector<int> mid = { root->val };
        vector<int> rightV = inorderTraversal(root->right);
        leftV.insert(end(leftV), mid.begin(), mid.end());
        leftV.insert(end(leftV), rightV.begin(), rightV.end());
        return leftV;
    }
};