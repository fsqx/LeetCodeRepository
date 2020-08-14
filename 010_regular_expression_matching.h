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

        // 主动遍历正则
        for(int i = 0; i < regExpLen; i++)
        {
            matchChar = s.at(srcIndex);
            regChar = p.at(i);

            // 正则是字母
            if((regChar >= 'a' && regChar <= 'z') || (regChar >= 'A' && regChar <= 'Z'))
            {
                if(i != regExpLen - 1 && p.at(i + 1) == '*')
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
                else if(i != regExpLen - 1 && p.at(i + 1) != '*')
                {
                    char tmpMatchChar = s.at(srcIndex);

                    if(tmpMatchChar == matchChar)
                    {
                        srcIndex++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            // 正则是*
            else if((regChar == '.'))
            {
                if(i != regExpLen - 1 && p.at(i + 1) == '*')
                {
                    return true;
                }
                else
                {
                    srcIndex++;
                }
            }

            char &reg = p.at(i);
        }

        return true;
    }

};