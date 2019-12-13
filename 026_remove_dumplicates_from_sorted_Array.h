#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums);

};

int Solution::removeDuplicates(vector<int>& nums)
{
    // 空数组
    if(nums.size() == 0)
    {
        return 0;
    }

    auto iter = nums.begin();
    int frontNum = nums.front();
    bool hasIntMax = false;
    iter++;

    while(iter != nums.end())
    {
        if(*iter == INT_MAX)
        {
            hasIntMax = true;
        }

        if(*iter != frontNum)
        {
            frontNum = *iter;
        }
        else
        {
            *iter = INT_MAX;
        }

        iter++;
    }

    nums.erase(remove(nums.begin(), nums.end(), INT_MAX), nums.end());

    if(hasIntMax)
    {
        nums.push_back(INT_MAX);
    }

    return nums.size();
}