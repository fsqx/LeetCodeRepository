#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= target)
            {
                return i;
            }
        }

        return nums.size();
    }
};

/*
int main()
{
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(7);
    Solution solution;
    std::cout << solution.searchInsert(nums, 2) << std::endl;
    std::cout << "Hello world" << std::endl;
    system("pause");
    return 0;
}
*/
