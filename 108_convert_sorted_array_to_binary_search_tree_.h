#pragma once

#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    int depth;
    TreeNode() : val(0), left(nullptr), right(nullptr), depth(0) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), depth(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), depth(0) {}

};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
    }

private:
    TreeNode *LLRoute(TreeNode *root)
    {
        TreeNode *son = root->right;
        root->right = son->left;
        son->left = root;
        updateDepth(son);
        return son;
    }
    TreeNode *LRRoute(TreeNode *root)
    {
        TreeNode *newRoot = RRRoute(root->left);
        root->left = newRoot;
        return LLRoute(root);
    }
    TreeNode *RRRoute(TreeNode *root)
    {
        TreeNode *son = root->left;
        root->left = son->right;
        son->right = root;
        updateDepth(son);
        return son;
    }
    TreeNode *RLRoute(TreeNode *root)
    {
        TreeNode *newRoot = LLRoute(root->right);
        root->right = newRoot;
        return LLRoute(root);
    }

    int getDepth(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }

        return root->depth;
    }
    int isBalance(TreeNode *root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        else
        {
            return (getDepth(root->left) - getDepth(root->right));
        }
    }
    int updateDepth(TreeNode *root)
    {
        if(root == nullptr)
        {
            return 0;
        }

        int leftDepth = updateDepth(root->left);
        int rightDepth = updateDepth(root->right);
        root->depth = max(leftDepth, rightDepth) + 1;
    }

    int insertNode(TreeNode *root, int val)
    {
        TreeNode *node = new TreeNode(val);
        insertNode(root, node);
        updateDepth(root);
    }

    TreeNode* findMinUnbalanceTree(TreeNode *root)
    {
        int l = isBalance(root->left);
        int r = isBalance(root->right);

        if(-1 < l && l < 1 && -1 < r && r < 1)
        {
            return root;
        }

        // TODO
    }

    TreeNode *insertNode(TreeNode *root, TreeNode *node)
    {
        if(root->val > node->val)
        {
            if(!root->left)
            {
                insertNode(root->left, node);
            }
            else
            {
                root->left = node;
            }
        }
        else
        {
            if(!root->right)
            {
                insertNode(root->right, node);
            }
            else
            {
                root->right = node;
            }
        }
    }
};