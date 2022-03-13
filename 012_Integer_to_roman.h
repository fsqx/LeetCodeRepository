#pragma once
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        // œﬁ∂® ‰»Î∑∂Œß1-3999
        if(num < 1 || num > 3999)
        {
            return "";
        }

        int integerArray[13] { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string strArray[13] { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        string result = "";

        for(int index = 0; index < 13; index++)
        {
            while(num >= integerArray[index])
            {
                num -= integerArray[index];
                result += strArray[index];
            }
        }

        return result;
    }
};