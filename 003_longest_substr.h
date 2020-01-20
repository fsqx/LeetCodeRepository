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
    unordered_map<char, int> slideWindow;
    int leftIndex = 0;
    int rightIndex = 0;
    int maxLength = 0;

    while(rightIndex < s.size())
    {
        if(slideWindow.find(s[rightIndex]) != slideWindow.end())
        {
            slideWindow.erase(s[leftIndex]);
            leftIndex++;
        }
        else
        {
            slideWindow.insert(pair<char, int>(s[rightIndex], rightIndex));
            rightIndex++;
        }

        if(slideWindow.size() > maxLength)
        {
            maxLength = slideWindow.size();
        }
    }

    return maxLength;
}