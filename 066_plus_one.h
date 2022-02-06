#pragma once

#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        vector<int> rst = digits;
        reverse(begin(rst), end(rst));
        rst[0] = rst[0] + 1;
        bool flag = false;

        for(auto iter = rst.begin(); iter < rst.end(); iter++)
        {
            if(flag)
            {
                (*iter)++;
                flag = false;
            }

            if(*iter >= 10)
            {
                *iter = *iter % 10;
                flag = true;
            }
        }

        if(flag == true)
        {
            rst.push_back(1);
        }

        reverse(begin(rst), end(rst));
        return rst;
    }
};