/* 注意不要越界，处理各种异常情况即可*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        auto lengthOfStringVector = strs.size();

        if(lengthOfStringVector == 0)
        {
            return string("");
        }

        if(lengthOfStringVector == 1)
        {
            return strs.at(0);
        }

        string commonString = "";
        int min = minLengthOfStrs(strs);
        int flag = false;

        for(int strIndex = 0; strIndex < min; strIndex++)
        {
            for(int vectorIndex = 0; vectorIndex < lengthOfStringVector - 1; vectorIndex++)
            {
                if(*(strs[vectorIndex].c_str() + strIndex) == *(strs[vectorIndex + 1].c_str() + strIndex))
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                    break;
                }
            }

            if(flag == true)
            {
                commonString += *(strs[0].c_str() + strIndex);
                flag = false;
            }
            else
            {
                return commonString;
            }
        }

        return commonString;
    }

    int minLengthOfStrs(const vector<string> &strs)
    {
        int minNumber = strs.at(0).length();

        for(int i = 0; i < strs.size(); i++)
        {
            if(minNumber >= strs.at(i).length())
            {
                minNumber = strs.at(i).length();
            }
        }

        return minNumber;
    }
};