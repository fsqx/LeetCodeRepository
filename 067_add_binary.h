#pragma once

#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int maxlen = max(a.length(), b.length());
        int tmpA = 0;
        int tmpB = 0;
        int tmpF = 0;
        char tmpC = 0;
        string rst;

        for(size_t i = 0; i < maxlen; i++)
        {
            if(i >= a.length())
            {
                tmpA = 0;
            }
            else
            {
                tmpA = a.at(i) - '0';
            }

            if(i >= b.length())
            {
                tmpB = 0;
            }
            else
            {
                tmpB = b.at(i) - '0';
            }

            tmpC = tmpA + tmpB + tmpF;

            if(tmpC >= 2)
            {
                tmpC = tmpC % 2;
                tmpF = 1;
            }
            else
            {
                tmpF = 0;
            }

            rst.push_back(tmpC + '0');
        }

        if(tmpF == 1)
        {
            rst.push_back('1');
        }

        reverse(rst.begin(), rst.end());
        return rst;
    }
};