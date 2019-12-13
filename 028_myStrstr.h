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
    if(haystack.empty())
    {
        return -1;
    }

    if(needle.empty())
    {
        return 0;
    }

    const char *srcString = haystack.c_str();
    const char *needString = needle.c_str();

    while(srcString != nullptr)
    {
        if(*srcString == *needString)
        {
            while(needString != nullptr)
            {
            }
        }
    }
}