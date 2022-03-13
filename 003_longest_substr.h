#pragma once
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s)
{
    string newStr = "";
    int leftIndex = 0;
    int rightIndex = 0;
    int maxSubLength = 0;

    while(rightIndex < s.length())
    {
        size_t newStringFindIndex = newStr.find(s[rightIndex]);

        if(newStringFindIndex == newStr.npos)
        {
            newStr += s[rightIndex];
            rightIndex++;

            if(maxSubLength < newStr.length())
            {
                maxSubLength = newStr.length();
            }
        }
        else
        {
            leftIndex = newStringFindIndex + 1 + leftIndex;
            rightIndex = leftIndex;
            newStr.clear();
        }
    }

    return maxSubLength;
}