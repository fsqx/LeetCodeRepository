#pragma once
#include <string>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        str.erase(0, str.find_first_not_of(" "));
        int symbol = 1;

        if(str.empty())
        {
            return 0;
        }

        if(str[0] == '-')
        {
            symbol = -1;
            str.erase(0, 1);
        }
        else if(str[0] == '+')
        {
            str.erase(0, 1);
        }

        int rstVal = 0;
        int index = 0;

        while(str[index] <= '9' && str[index] >= '0')
        {
            if(symbol > 0)
            {
                if(rstVal > INT_MAX / 10 || (rstVal == INT_MAX / 10 && str[index] > '7'))
                {
                    return INT_MAX;
                }
            }
            else
            {
                if(rstVal > INT_MAX / 10 || (rstVal == INT_MAX / 10 && str[index] > '8'))
                {
                    return INT_MIN;
                }
            }

            rstVal = rstVal * 10 + (str[index] - '0') * symbol;
            index++;
        }

        return rstVal;
    }
};