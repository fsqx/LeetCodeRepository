#pragma once
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        char matchChar;
        char regChar;
        int srcLen = s.length();
        int srcIndex = 0;
        int regExpLen = p.length();
        int regExpIndex = 0;

        for(int i = 0; i < regExpLen; i++)
        {
            matchChar = s.at(srcIndex);
            regChar = p.at(i);

            if((regChar >= 'a' && regChar <= 'z') || (regChar >= 'A' && regChar <= 'Z'))
            {
                if(i != regExpLen - 1 && p.at(i) == '*')
                {
                    char tmpMatchChar = s.at(srcIndex);

                    while(tmpMatchChar == matchChar)
                    {
                        if(tmpMatchChar == regChar)
                        {
                            srcIndex++;
                            tmpMatchChar = s.at(srcIndex);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

            char &reg = p.at(i);
        }
    }
};