#pragma once

#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int countGoodRectangles(vector<vector<int>>& rectangles)
    {
        vector<int> maxSquare;

        for(auto rect : rectangles)
        {
            maxSquare.push_back(min(rect.at(0), rect.at(1)));
        }

        vector<int>::iterator maxElement = max_element(maxSquare.begin(), maxSquare.end());
        int cnt = count(begin(maxSquare), end(maxSquare), *maxElement);
        return cnt;
    }
};