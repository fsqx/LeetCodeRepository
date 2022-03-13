#pragma once

#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height);
};

int Solution::maxArea(vector<int>& heightArr)
{
    int head = 0;
    int taile = heightArr.size() - 1;
    int width;
    int height;
    int areaOfWater = 0;
    bool flag = true;

    while(head != taile)
    {
        int minHeight = min(heightArr[taile], heightArr[head]);
        int currWidth = taile - head;
        int area = minHeight * currWidth;
        flag = heightArr[taile] > heightArr[head];

        if(flag)
        {
            head++;
        }
        else
        {
            taile--;
        }

        if(area > areaOfWater)
        {
            areaOfWater = area;
        }
    }

    return areaOfWater;
}