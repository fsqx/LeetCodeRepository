#pragma once
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:

    int strStr(string haystack, string needle);
};

int Solution::strStr(string haystack, string needle)
{
    if(needle.empty())
    {
        return 0;
    }

    if(haystack.empty())
    {
        return -1;
    }

    const char *srcString = haystack.c_str();
    const char *needString = needle.c_str();
    bool flag = false;
    int index = 0;

    while(*srcString != '\0')
    {
        if(*srcString == *needString)
        {
            while(*needString != '\0')
            {
                if(*srcString == '\0' || *srcString != *needString)
                {
                    flag = false;
                    break;
                }

                flag = true;
                srcString++;
                needString++;
            }

            if(flag)
            {
                return index;
            }
            else
            {
                srcString = haystack.c_str() + index;
                needString = needle.c_str();
            }
        }

        srcString++;
        index++;
    }

    return -1;
}