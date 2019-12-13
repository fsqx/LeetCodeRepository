#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        // C++ STL 常见算法(比较详细)
        // https://blog.csdn.net/xyqqwer/article/details/81263060
        // stl中的remove返回的是什么
        // https://blog.csdn.net/jfkidear/article/details/52349964
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};
