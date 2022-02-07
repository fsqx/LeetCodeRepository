#pragma once
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int rstNumber = 0;
        int subNumber = 0;
        int tmp;

        for(size_t i = 0; i < nums.size(); i++)
        {
            tmp = nums.at(i);

            if(i == 0)
            {
                rstNumber = tmp;
                subNumber = rstNumber;
            }
            else
            {
                if(subNumber < 0)
                {
                    subNumber = 0;
                }

                subNumber += tmp;

                if(rstNumber < subNumber)
                {
                    rstNumber = subNumber;
                }
            }
        }

        // 获取最终结果
        return rstNumber;
    }
};