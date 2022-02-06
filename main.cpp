#include "mainHead.h"



int main(int argc, char *argv[])
{
    std::cout << "hello world!" << std::endl;
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> nums2 = { 2, 5, 6 };
    Solution solution;
    solution.merge(nums1, 3, nums2, 3);
    system("pause");
    return 0;
}