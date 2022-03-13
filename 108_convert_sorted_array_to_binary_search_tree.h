#pragma once

#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    void print()
    {
        if(left)
        {
            left->print();
        }

        cout << val << endl;

        if(right)
        {
            right->print();
        }
    }
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int left, int right)
    {
        if(left > right)
        {
            return nullptr;
        }

        int index = (left + right) / 2;
        TreeNode *mid = new TreeNode(nums[index]);
        mid->left = helper(nums, left, index - 1);
        mid->right = helper(nums, index + 1, right);
        return mid;
    }
};