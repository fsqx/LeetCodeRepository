#pragma once
#include <string>
#include <cmath>

using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if(s.empty())
        {
            return string("");
        }

        if(numRows <= 0)
        {
            return string("");
        }

        if(numRows == 1)
        {
            return s;
        }

        int strLength = s.size();
        vector<string> everyRowString(min(numRows, int(s.size())));
        bool fillFlag = false;
        int left = 0;

        for(int i = 0; i < strLength; i++)
        {
            everyRowString[left] += s.at(i);

            if((left == numRows - 1) || (left == 0))
            {
                fillFlag = !fillFlag;
            }

            if(fillFlag)
            {
                left = left + 1;
            }
            else
            {
                left = left - 1;
            }
        }

        string rstString;

        for(auto &rowString : everyRowString)
        {
            rstString += rowString;
        }

        return rstString;
    }


};