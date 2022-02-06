#pragma once
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int maxLen = 0;
        int count = 0;
        string::iterator c = s.begin();

        while(c != s.end())
        {
            if(*c != ' ')
            {
                count++;
                maxLen = count;
            }
            else
            {
                count = 0;
            }

            c++;
        }

        return maxLen;
    }
};