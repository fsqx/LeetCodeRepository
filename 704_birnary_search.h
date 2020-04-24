#ifndef _BIRNARY_SEARCH_HPP_
#define _BIRNARY_SEARCH_HPP_
#include <iostream>
#include <vector>

using namespace std;

/**
 * 对于左右边界的二分法查找，重点在于明确查找区间，
 * 当查找到元素时不是直接返回元素的索引，而是将该位置作为查找边界，直至查找区间为空
 * 二分法查找应考虑是否越界，尤其是特殊二分法查找时
 */

class BirnarySearch
{
public:
    // 普通二分法查找
    int search(vector<int>& nums, int target)
    {
        int length = nums.size();
        int left = 0;
        int right = length - 1;

        while(left <= right)
        {
            int mid = (right - left) / 2 + left;

            if(nums.at(mid) > target)
            {
                right = mid - 1;
            }
            else if(nums.at(mid) < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }

    // 查找左边界的二分法查找 TODO
    int searchLeft(vector<int>& nums, int target)
    {
        int length = nums.size();
        int left = 0;
        int right = length - 1;

        while(left <= right)
        {
            int mid = (right - left) / 2 + left;

            if(nums.at(mid) > target)
            {
                right = mid - 1;
            }
            else if(nums.at(mid) < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return -1;
    }
};
#endif // !_BIRNARY_SEARCH_HPP_