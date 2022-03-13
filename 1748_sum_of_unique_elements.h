#pragma once

#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int sumOfUnique(vector<int>& nums)
    {
        int times[101] = { 0 };
        int cnt = 0;

        for(auto num : nums)
        {
            times[num]++;
        }

        for(int i = 0; i < 101; i++)
        {
            if(times[i] == 1)
            {
                cnt += i;
            }
        }

        return cnt;
    }
};