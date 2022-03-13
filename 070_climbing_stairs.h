#pragma once

int temp[46] = { 0 };
class Solution
{
public:
    int climbStairs(int n)
    {
        if(n == 1)
        {
            temp[1] = 1;
            return 1;
        }
        else if(n == 2)
        {
            temp[2] = 2;
            return 2;
        }
        else
        {
            int a = 0;
            int b = 0;

            if(temp[n - 1] == 0)
            {
                temp[n - 1] = climbStairs(n - 1);
            }

            if(temp[n - 2] == 0)
            {
                temp[n - 2] = climbStairs(n - 2);
            }

            a = temp[n - 1];
            b = temp[n - 2];
            return a + b;
        }
    }
};