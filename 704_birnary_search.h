#ifndef _BIRNARY_SEARCH_HPP_
#define _BIRNARY_SEARCH_HPP_
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    Solution()
    {
        m_left = 0;
        m_right = -2;
    }

    int search(vector<int>& nums, int target)
    {
        if(m_right == -2)
        {
            m_right = nums.size() - 1;
        }

        if(m_left > m_right)
        {
            return -1;
        }

        int vctLength = m_right - m_left;
        int mid = vctLength / 2 + m_left;

        if(nums.at(mid) > target)
        {
            m_right = mid - 1;
            return search(nums, target);
        }
        else if(nums.at(mid) < target)
        {
            m_left = mid + 1;
            return search(nums, target);
        }
        else if(nums.at(mid) == target)
        {
            return mid;
        }

        return 0;
    }

private:
    int m_left;
    int m_right;
};
#endif // !_BIRNARY_SEARCH_HPP_