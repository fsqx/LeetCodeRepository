#pragma once
class Solution
{
public:
    int mySqrt(int x)
    {
        int ans = -1;
        int left = 0;
        int right = x;
        int mid = x / 2;

        while(left <= right)
        {
            mid = (left + right) / 2;

            if(long long(mid * mid) <= x)
            {
                left = mid + 1;
                ans = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }

};