#include "mainHead.h"



int main(int argc, char *argv[])
{
    std::cout << "hello world!" << std::endl;
    vector<int> nums1 = { -10, -3, 0, 5, 9 };
    vector<int> nums2 = { 2, 5, 6 };
    Solution solution;
    TreeNode *rst = solution.sortedArrayToBST(nums1);
    rst->print();
    //cout << solution.maxDepth() << endl;
    system("pause");
    return 0;
}