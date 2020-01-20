#pragma once
#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    string longestPalindrome(string s);
    int judgementCharSingle(string &str, int indexLeft, int indexRight);
    int judgementCharDouble(string &str, int indexLeft, int indexRight);
};

string Solution::longestPalindrome(string str)
{
    if(str.empty())
    {
        return "";
    }

    int maxLength = 1;
    int strLength = str.length();
    int firstIndex = -1;
    int length = 0;

    for(int i = 0; i < strLength; i++)
    {
        {
            auto first = judgementCharSingle(str, i - 1, i + 1);
            length = (i - first) * 2 + 1;

            if(length > maxLength)
            {
                maxLength = length;
                firstIndex = first;
            }
        }

        if(str[i] == str[i + 1])
        {
            auto first = judgementCharDouble(str, i - 1, i + 2);
            length = (i - first) * 2 + 2;

            if(length > maxLength)
            {
                maxLength = length;
                firstIndex = first;
            }
        }
    }

    if(firstIndex < 0)
    {
        return str.substr(0, 1);
    }
    else
    {
        return str.substr(firstIndex, maxLength);
    }
}

int Solution::judgementCharSingle(string &str, int indexLeft, int indexRight)
{
    if(indexLeft < 0 || indexRight > str.length())
    {
        return indexLeft + 1;
    }

    if(str[indexLeft] != str[indexRight])
    {
        return indexLeft + 1;
    }
    else
    {
        return judgementCharSingle(str, indexLeft - 1, indexRight + 1);
    }
}

int Solution::judgementCharDouble(string &str, int indexLeft, int indexRight)
{
    if(indexLeft < 0 || indexRight + 1 > str.length())
    {
        return indexLeft + 1;
    }

    if(str[indexLeft] != str[indexRight])
    {
        return indexLeft + 1;
    }
    else
    {
        return judgementCharDouble(str, indexLeft - 1, indexRight + 1);
    }
}
